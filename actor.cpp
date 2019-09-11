#include "isxao_main.h"

namespace isxao_classes
{

	DWORD actor::build_ls_ncu(LSIndex* p_index)
	{
		auto l = get_spell_template_data()->GetSpellTemplateDataData().nano_template_list;
		for (auto it = l.begin(); it != l.end(); ++it)  // NOLINT(modernize-loop-convert)
		{
			auto p_nano_template = reinterpret_cast<NanoTemplate*>(&(*it));
			p_index->AddItem(reinterpret_cast<LSOBJECTDATA&>(p_nano_template));
		}
		return p_index->GetContainerUsed();
	}

	DWORD actor::build_ls_pets(LSIndex* p_index)
	{
		std::map<identity_t, DWORD> pet_map;
		if (get_pet_ids(pet_map) == 0)
			return 0;
		for (auto it = pet_map.begin(); it != pet_map.end(); ++it)  // NOLINT(modernize-loop-convert)
		{
			auto p_dynel = dynel::get_dynel(it->first);
			p_index->AddItem(reinterpret_cast<LSOBJECTDATA&>(p_dynel));
		}
		return p_index->GetContainerUsed();
	}

	DWORD actor::casting()
	{
		return get_spell_template_data()->GetNanoBeingCast();
	}

	PCSTR actor::consider()
	{
		float consider;
		P_ENGINE_CLIENT_ANARCHY->n3_msg_consider(this->get_identity(), consider);
		if (consider >= 0.0f && consider < 0.2000000029802322)
			return "Easy";
		if (consider >= 0.2000000029802322 && consider < 0.4900000095367432)
			return "Probable";
		if (consider >= 0.4900000095367432 && consider < 0.50999999)
			return "MaybePossible";
		if (consider >= 0.50999999 && consider < 0.69999999)
			return "Hard";
		if (consider >= 0.69999999 && consider < 0.8999999761581421)
			return "AlmostImpossible";
		if (consider >= 0.8999999761581421)
			return "Impossible";
		return "VeryEasy";
	}

	PCSTR actor::con_color()
	{
		const auto argb = con_color_argb();
		if (argb.ARGB == 0xFFFFFF)
			return "White";
		if (argb.ARGB == 0xAAAAAA)
			return "Grey";
		auto f_r = float(argb.R / 255.0f);
		auto f_g = float(argb.G / 255.0f);
		auto f_b = float(argb.B / 255.0f);
		auto f_h = 0.0f;
		auto f_s = 0.0f;
		auto f_v = 0.0f;
		const auto f_c_max = max(max(f_r, f_g), f_b);
		const auto f_c_min = min(min(f_r, f_g), f_b);
		const auto f_delta = f_c_max - f_c_min;

		if (f_delta > 0) {
			if (f_c_max == f_r) {
				f_h = 60 * float(fmod(((f_g - f_b) / f_delta), 6));
			}
			else if (f_c_max == f_g) {
				f_h = 60 * (((f_b - f_r) / f_delta) + 2);
			}
			else if (f_c_max == f_b) {
				f_h = 60 * (((f_r - f_g) / f_delta) + 4);
			}

			if (f_c_max > 0) {
				f_s = f_delta / f_c_max;
			}
			else {
				f_s = 0;
			}

			f_v = f_c_max;
		}
		else {
			f_h = 0;
			f_s = 0;
			f_v = f_c_max;
		}

		if (f_h < 0) {
			f_h = 360 + f_h;
		}
		if (f_h < 0.0f)
			return "Unknown";
		if (f_h <= 15.0f)
			return "Red";
		if (f_h <= 45.0f)
			return "Orange";
		if (f_h <= 75.0f)
			return "Yellow";
		return "Green";
	}

	RGBCOLOR actor::con_color_argb()
	{
		RGBCOLOR argb;
		argb.ARGB = 0xFFFFFF;
		float consider;
		const auto con_type = P_ENGINE_CLIENT_ANARCHY->n3_msg_consider(this->get_identity(), consider);
		if (consider > 1.0f)
			consider = 1.0f;
		if(con_type == 3)
		{
			if(consider  > 0.0f)
			{
				if(consider >= 0.5f)
				{
					argb.ARGB = (int(2 * (1 - consider) * 240) | 0xFF00) << 8;
					// ReSharper disable once CppSomeObjectMembersMightNotBeInitialized
					return argb;
				}
				argb.ARGB = (int(2 * (consider * 255)) << 16) | 0xFF00;
				// ReSharper disable once CppSomeObjectMembersMightNotBeInitialized
				return argb;
			}
			argb.ARGB = 0xAAAAAA;
			// ReSharper disable once CppSomeObjectMembersMightNotBeInitialized
			return argb;				
		}
		// ReSharper disable once CppSomeObjectMembersMightNotBeInitialized
		return argb;
	}

	void actor::do_face()
	{
		vector3_t client_position;
		P_ENGINE_CLIENT_ANARCHY->n3_msg_get_global_character_position(client_position);
		auto position = this->get_position();
		const auto new_rotation = quaternion_t::get_quaternion_to_face(position, client_position);
		P_ENGINE_CLIENT_ANARCHY->get_client_char()->SetRotation(new_rotation);
	}

	void actor::do_target()
	{
		P_TARGETING_MODULE->SetTarget(this->get_identity(), false);
	}

	float actor::estimated_distance_to(vector3_t &position)
	{
		const auto dynel_position = get_position();
		const auto uncompensated_distance = get_distance_to(position);
		const auto x = position.x - (dynel_position.x + get_vehicle()->GetVelocity().x*uncompensated_distance);
		const auto z = position.z - (dynel_position.z + get_vehicle()->GetVelocity().z*uncompensated_distance);
		vector3_t estimated_position;
		estimated_position.x = x;
		estimated_position.y = 0.0f;
		estimated_position.z = z;
		return estimated_position.length();
	}

	NanoTemplate* actor::get_ncu(const DWORD index)
	{
		std::vector<NanoTemplate> nano_template_vector;
		// ReSharper disable once CppExpressionWithoutSideEffects
		if (this->get_spell_template_data()->GetNanoTemplateList(nano_template_vector))
		{
			if (index < 0 || index >= nano_template_vector.size())
				return nullptr;
			return static_cast<NanoTemplate*>(&(nano_template_vector[index]));
		}
		return nullptr;		
	}

	NanoTemplate* actor::get_ncu(const PCSTR effect_name)
	{
		const identity_t container_identity(0, 0);
		char name[MAX_STRING] = { 0 };
		char search_name[MAX_STRING];
		strcpy_s(search_name, MAX_STRING, effect_name);
		_strlwr_s(search_name);
		vector<NanoTemplate> nano_template_vector;
		if (this->get_spell_template_data()->GetNanoTemplateList(nano_template_vector))
		{  
			for (auto it = nano_template_vector.begin(); it != nano_template_vector.end(); ++it)  // NOLINT(modernize-loop-convert)
			{
				const auto entry = static_cast<NanoTemplate*>(&(*it));
				strcpy_s(name, MAX_STRING, P_ENGINE_CLIENT_ANARCHY->n3_msg_get_name(entry->GetNanoIdentity(), container_identity));
				_strlwr_s(name);
				if (strstr(name, search_name))
					return entry;
			}
		}
		return nullptr;
	}

	DWORD actor::get_ncu_count()
	{
		std::vector<NanoTemplate> nano_template_vector;
		if (this->get_spell_template_data()->GetNanoTemplateList(nano_template_vector))
		{
			return nano_template_vector.size();
		}
		return 0;
	}

	SpellTemplateData* actor::get_spell_template_data()
	{
		return reinterpret_cast<SpellTemplateData*>(this->get_simple_char_data()->p_spell_template_data);
	}

	float actor::get_scale()
	{
		return this->get_simple_char_data()->body_scale;
	}

	p_simple_char_t actor::get_simple_char_data()
	{
		return p_simple_char_t(this->get_data());
	}

	Vehicle* actor::get_vehicle()
	{
		return reinterpret_cast<Vehicle*>(this->get_simple_char_data()->p_vehicle);
	}

	bool actor::is_backing_up()
	{
		return this->get_vehicle()->GetCharMovementStatus()->is_moving_forward_back != 1 && get_vehicle()->GetCharMovementStatus()->forward_back_direction == 2;
	}

	bool actor::is_casting()
	{
		return this->get_spell_template_data()->IsCasting();
	}

	bool actor::is_fighting()
	{
		return this->get_simple_char_data()->p_weapon_holder->is_attacking != 1;

	}

	bool actor::is_fighting_me()
	{
		return IsClientId(this->get_simple_char_data()->p_weapon_holder->weapon_target_identity.id);
	}

	bool actor::is_idle()
	{
		return this->get_vehicle()->GetCharMovementStatus()->is_moving_forward_back == 1 && this->get_vehicle()->GetCharMovementStatus()->is_moving_strafe == 1;
	}

	bool actor::is_in_my_team()
	{
		return this->is_player() && this->is_in_team() && (this->get_team_raid()->GetTeamIdentity() == P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_team_raid()->GetTeamIdentity());
	}

	bool actor::is_in_team()
	{
		if(this->is_player())
			return this->get_team_raid()->GetTeamIdentity().type != 0;
		return false;
	}

	bool actor::is_in_raid()
	{
		return this->is_player() && this->is_in_team() && this->get_team_raid()->GetTeamRaidIndex() != DWORD(-1);
	}

	bool actor::is_in_my_raid_team()
	{
		if(this->is_team_member() && this->is_in_raid())
		{
			std::vector<TeamEntry*> v;
			if (P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_team_raid()->GetTeam(v))
			{
				for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
				{
					if ((*it)->GetIdentity() == this->get_identity())
						return true;
				}
			}			
		}		
		return false;
	}

	bool actor::is_invis()
	{
		return !(this->get_simple_char_data()->is_visible);
	}

	bool actor::is_kos()
	{
		return this->get_skill(ST_BREEDHOSTILITY) > 30;
	}

	bool actor::is_moving_forward()
	{
		return this->get_vehicle()->GetCharMovementStatus()->is_moving_forward_back != 1 && this->get_vehicle()->GetCharMovementStatus()->forward_back_direction == 1;
	}

	bool actor::is_npc()
	{
		return this->get_simple_char_data()->is_npc == 1;
	}

	bool actor::is_strafing_left()
	{
		return this->get_vehicle()->GetCharMovementStatus()->is_moving_strafe != 1 && this->get_vehicle()->GetCharMovementStatus()->strafe_direction == 3;
	}

	bool actor::is_strafing_right()
	{
		return this->get_vehicle()->GetCharMovementStatus()->is_moving_strafe != 1 && this->get_vehicle()->GetCharMovementStatus()->strafe_direction == 4;
	}
	
	bool actor::is_team_leader()
	{
		if(this->is_player())
		{
			auto result = false;
			if (this->is_in_team() && this->is_in_my_team())
				result = P_ENGINE_CLIENT_ANARCHY->N3Msg_IsTeamLeader(this->get_identity());
			return result;
		}
		return false;
	}
	
	DWORD actor::get_master_id()
	{
		return this->get_skill(ST_PETMASTER);
	}

	actor* actor::get_master()
	{
		if (!this->is_pet())
			return nullptr;
		identity_t master;
		DWORD id = 0;
		master.type = 50000;
		id = DWORD(this->get_skill(ST_PETMASTER));
		master.id = id;
		return dynel::get_dynel(master)->to_actor();
	}

	actor* actor::get_pet(const DWORD index)
	{
		map<identity_t, DWORD> pet_map;
		if (this->get_pet_ids(pet_map) == 0)
			return nullptr;
		if (index < 0 || index >= pet_map.size())
			return nullptr;
		for (auto it = pet_map.begin(); it != pet_map.end(); ++it)  // NOLINT(modernize-loop-convert)
		{
			if (it->second == index)
				return dynel::get_dynel(it->first)->to_actor();
		}
		return nullptr;
	}

	actor* actor::get_pet(const PCSTR pet_name)
	{
		const identity_t container_identity(0, 0);
		map<identity_t, DWORD> pet_map;
		char name[MAX_STRING];
		char search_name[MAX_STRING];
		if (get_pet_ids(pet_map) == 0)
			return nullptr;		
		strcpy_s(search_name, MAX_STRING, pet_name);
		_strlwr_s(search_name);
		for (auto it = pet_map.begin(); it != pet_map.end(); ++it)  // NOLINT(modernize-loop-convert)
		{
			strcpy_s(name, MAX_STRING, P_ENGINE_CLIENT_ANARCHY->n3_msg_get_name((*it).first, container_identity));
			_strlwr_s(name);
			if (strstr(name, search_name))
				return dynel::get_dynel((*it).first)->to_actor();
		}
		return nullptr;
	}

	DWORD actor::get_pet_count()
	{
		std::map<identity_t, DWORD> pet_map;
		return get_pet_ids(pet_map);
	}

	DWORD actor::get_pet_ids(map<identity_t, DWORD>& m)
	{
		std::map<identity_t, DWORD> pet_map;
		if (!IsClientId(this->get_identity().id))
		{
			map<identity_t, p_n3_dynel_t> dynel_map;
			get_dynel_map(dynel_map);
			DWORD pet_count = 0;
			for (auto it = dynel_map.begin(); it != dynel_map.end(); ++it)  // NOLINT(modernize-loop-convert)
			{
				if (it->first.type == 50000)
				{
					const auto is_npc = P_ENGINE_CLIENT_ANARCHY->n3_msg_is_npc(it->first);
					if (is_npc)
					{
						auto instance = reinterpret_cast<dynel*>(it->second);
						if (DWORD(instance->get_skill(ST_PETMASTER)) == get_identity().id)
						{
							pet_map.insert_or_assign(it->first, pet_count);
							pet_count++;
						}
					}
				}
			}
			return pet_map.size();
		}
		isxao_utilities::GetPetMap(m, this->to_character()->GetNPCHolder()->GetNPCHolderData().p_pet_dir);
		return m.size();
	}

	bool actor::has_pet()
	{
		if(this->is_character())
		{
			std::map <identity_t, DWORD> pet_map;
			isxao_utilities::GetPetMap(pet_map, to_character()->GetNPCHolder()->GetNPCHolderData().p_pet_dir);
			return !pet_map.empty();
		}
		std::map<identity_t, p_n3_dynel_t> dynel_map;
		isxao_utilities::get_dynel_map(dynel_map);
		for (auto it = dynel_map.begin(); it != dynel_map.end(); ++it)  // NOLINT(modernize-loop-convert)
		{
			if (it->first.type == 50000)
			{
				const auto is_npc = P_ENGINE_CLIENT_ANARCHY->n3_msg_is_npc(it->first);
				if (is_npc)
				{
					auto instance = reinterpret_cast<dynel*>(it->second);
					if (DWORD(instance->get_skill(ST_PETMASTER)) == get_identity().id)
						return true;
				}
			}
		}
		return false;
	}

	TeamRaid* actor::get_team_raid()
	{
		if(this->is_player())
			return reinterpret_cast<TeamRaid*>(this->get_simple_char_data()->p_team_raid_info);
		return nullptr;
	}

	WeaponHolder* actor::get_weapon_holder()
	{
		return reinterpret_cast<WeaponHolder*>(this->get_simple_char_data()->p_weapon_holder);
	}

	void actor::kick()
	{
		if(this->is_team_member())
			P_ENGINE_CLIENT_ANARCHY->N3Msg_KickTeamMember(get_identity());
	}

	void actor::make_leader()
	{
		if(this->is_team_member())
			P_ENGINE_CLIENT_ANARCHY->get_client_char()->MakeTeamLeader(get_identity());
	}

	bool actor::send_team_invite()
	{
		if(this->is_player())
			return P_ENGINE_CLIENT_ANARCHY->N3Msg_TeamJoinRequest(get_identity(), true);
		return false;
	}	

}
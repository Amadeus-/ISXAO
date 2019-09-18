#include "isxao_main.h"

namespace ao
{

	DWORD actor::build_ls_ncu(LSIndex* p_index)
	{
		auto l = this->get_spell_template_data()->get_spell_template_data_data().nano_template_list;
		for (auto it = l.begin(); it != l.end(); ++it)  // NOLINT(modernize-loop-convert)
		{
			auto p_nano_template = reinterpret_cast<nano_template*>(&(*it));
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
		return this->get_spell_template_data()->get_nano_being_cast();
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
		auto f_r = float(argb.R) / 255.0f;
		auto f_g = float(argb.G) / 255.0f;
		auto f_b = float(argb.B) / 255.0f;
		auto f_h = 0.0f;
		// ReSharper disable CppInitializedValueIsAlwaysRewritten
		// ReSharper disable CppEntityAssignedButNoRead
		auto f_s = 0.0f;
		auto f_v = 0.0f;
		// ReSharper restore CppInitializedValueIsAlwaysRewritten
		// ReSharper restore CppEntityAssignedButNoRead
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
				// ReSharper disable once CppAssignedValueIsNeverUsed
				f_s = f_delta / f_c_max;
			}
			else {
				// ReSharper disable once CppAssignedValueIsNeverUsed
				f_s = 0;
			}

			// ReSharper disable once CppAssignedValueIsNeverUsed
			f_v = f_c_max;
		}
		else {
			f_h = 0;
			// ReSharper disable CppAssignedValueIsNeverUsed
			f_s = 0;			
			f_v = f_c_max;
			// ReSharper restore CppAssignedValueIsNeverUsed
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
		P_ENGINE_CLIENT_ANARCHY->get_client_char()->set_rotation(new_rotation);
	}

	void actor::do_target()
	{
		P_TARGETING_MODULE->set_target(this->get_identity(), false);
	}

	float actor::estimated_distance_to(vector3_t &position)
	{
		const auto dynel_position = get_position();
		const auto uncompensated_distance = get_distance_to(position);
		const auto x = position.x - (dynel_position.x + get_vehicle()->get_velocity().x*uncompensated_distance);
		const auto z = position.z - (dynel_position.z + get_vehicle()->get_velocity().z*uncompensated_distance);
		vector3_t estimated_position;
		estimated_position.x = x;
		estimated_position.y = 0.0f;
		estimated_position.z = z;
		return estimated_position.length();
	}

	nano_template* actor::get_ncu(const DWORD index)
	{
		std::vector<nano_template> nano_template_vector;
		// ReSharper disable once CppExpressionWithoutSideEffects
		if (this->get_spell_template_data()->get_nano_template_list(nano_template_vector))
		{
			if (index < 0 || index >= nano_template_vector.size())
				return nullptr;
			return static_cast<nano_template*>(&(nano_template_vector[index]));
		}
		return nullptr;		
	}

	nano_template* actor::get_ncu(const PCSTR effect_name)
	{
		const identity_t container_identity(0, 0);
		char name[MAX_VARSTRING] = { 0 };
		char search_name[MAX_VARSTRING];
		strcpy_s(search_name, MAX_VARSTRING, effect_name);
		_strlwr_s(search_name);
		std::vector<nano_template> nano_template_vector;
		if (this->get_spell_template_data()->get_nano_template_list(nano_template_vector))
		{  
			for (auto it = nano_template_vector.begin(); it != nano_template_vector.end(); ++it)  // NOLINT(modernize-loop-convert)
			{
				const auto entry = static_cast<nano_template*>(&(*it));
				strcpy_s(name, MAX_VARSTRING, P_ENGINE_CLIENT_ANARCHY->n3_msg_get_name(entry->get_nano_identity(), container_identity));
				_strlwr_s(name);
				if (strstr(name, search_name))
					return entry;
			}
		}
		return nullptr;
	}

	DWORD actor::get_ncu_count()
	{
		std::vector<nano_template> nano_template_vector;
		if (this->get_spell_template_data()->get_nano_template_list(nano_template_vector))
		{
			return nano_template_vector.size();
		}
		return 0;
	}

	spell_template_data* actor::get_spell_template_data()
	{
		return reinterpret_cast<spell_template_data*>(this->get_simple_char_data()->p_spell_template_data);
	}

	float actor::get_scale()
	{
		return this->get_simple_char_data()->body_scale;
	}

	p_simple_char_t actor::get_simple_char_data()
	{
		return p_simple_char_t(this->get_data());
	}

	vehicle* actor::get_vehicle()
	{
		return reinterpret_cast<vehicle*>(this->get_simple_char_data()->p_vehicle);
	}

	bool actor::is_backing_up()
	{
		return this->get_vehicle()->get_char_movement_status()->is_moving_forward_back != 1 && get_vehicle()->get_char_movement_status()->forward_back_direction == 2;
	}

	bool actor::is_casting()
	{
		return this->get_spell_template_data()->is_casting();
	}

	bool actor::is_fighting()
	{
		return this->get_simple_char_data()->p_weapon_holder->is_attacking != 1;

	}

	bool actor::is_fighting_me()
	{
		return is_client_id(this->get_simple_char_data()->p_weapon_holder->weapon_target_identity.id);
	}

	bool actor::is_idle()
	{
		return this->get_vehicle()->get_char_movement_status()->is_moving_forward_back == 1 && this->get_vehicle()->get_char_movement_status()->is_moving_strafe == 1;
	}

	bool actor::is_in_my_team()
	{
		return this->is_player() && this->is_in_team() && (this->get_team_raid()->get_team_identity() == P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_team_raid()->get_team_identity());
	}

	bool actor::is_in_team()
	{
		if(this->is_player())
			return this->get_team_raid()->get_team_identity().type != 0;
		return false;
	}

	bool actor::is_in_raid()
	{
		return this->is_player() && this->is_in_team() && this->get_team_raid()->get_team_raid_index() != DWORD(-1);
	}

	bool actor::is_in_my_raid_team()
	{
		if(this->is_team_member() && this->is_in_raid())
		{
			std::vector<team_entry*> v;
			if (P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_team_raid()->get_team(v))
			{
				for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
				{
					if ((*it)->get_identity() == this->get_identity())
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
		return this->get_vehicle()->get_char_movement_status()->is_moving_forward_back != 1 && this->get_vehicle()->get_char_movement_status()->forward_back_direction == 1;
	}

	bool actor::is_npc()
	{
		return this->get_simple_char_data()->is_npc == 1;
	}

	bool actor::is_strafing_left()
	{
		return this->get_vehicle()->get_char_movement_status()->is_moving_strafe != 1 && this->get_vehicle()->get_char_movement_status()->strafe_direction == 3;
	}

	bool actor::is_strafing_right()
	{
		return this->get_vehicle()->get_char_movement_status()->is_moving_strafe != 1 && this->get_vehicle()->get_char_movement_status()->strafe_direction == 4;
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
		master.type = 50000;
		const auto id = DWORD(this->get_skill(ST_PETMASTER));
		master.id = id;
		return dynel::get_dynel(master)->to_actor();
	}

	actor* actor::get_pet(const DWORD index)
	{
		std::map<identity_t, DWORD> pet_map;
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
		std::map<identity_t, DWORD> pet_map;
		char name[MAX_VARSTRING];
		char search_name[MAX_VARSTRING];
		if (get_pet_ids(pet_map) == 0)
			return nullptr;		
		strcpy_s(search_name, MAX_VARSTRING, pet_name);
		_strlwr_s(search_name);
		for (auto it = pet_map.begin(); it != pet_map.end(); ++it)  // NOLINT(modernize-loop-convert)
		{
			strcpy_s(name, MAX_VARSTRING, P_ENGINE_CLIENT_ANARCHY->n3_msg_get_name((*it).first, container_identity));
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

	DWORD actor::get_pet_ids(std::map<identity_t, DWORD>& m)
	{
		if (!is_client_id(this->get_identity().id))
		{
			std::map<identity_t, p_n3_dynel_t> dynel_map;
			P_DYNEL_DIR->copy_map(dynel_map);
			DWORD pet_count = 0;
			for (auto it = dynel_map.begin(); it != dynel_map.end(); ++it)  // NOLINT(modernize-loop-convert)
			{
				if (it->first.type == 50000)
				{
					const auto is_npc = P_ENGINE_CLIENT_ANARCHY->n3_msg_is_npc(it->first);
					if (is_npc)
					{
						auto instance = reinterpret_cast<dynel*>(it->second);
						if (DWORD(instance->get_skill(ST_PETMASTER)) == this->get_identity().id)
						{
							m.insert_or_assign(it->first, pet_count);
							pet_count++;
						}
					}
				}
			}
			return m.size();
		}
		return P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_npc_holder()->get_npc_holder_data().p_pet_dir->copy_map(m);
	}

	bool actor::has_pet()
	{
		if(this->is_character())
		{
			map <identity_t, DWORD> pet_map;
			return P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_npc_holder()->get_npc_holder_data().p_pet_dir->copy_map(pet_map) != 0;
		}
		std::map<identity_t, p_n3_dynel_t> dynel_map;
		P_DYNEL_DIR->copy_map(dynel_map);
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

	team_raid* actor::get_team_raid()
	{
		if(this->is_player())
			return reinterpret_cast<team_raid*>(this->get_simple_char_data()->p_team_raid_info);
		return nullptr;
	}

	weapon_holder* actor::get_weapon_holder()
	{
		return reinterpret_cast<weapon_holder*>(this->get_simple_char_data()->p_weapon_holder);
	}

	void actor::kick()
	{
		if(this->is_team_member())
			P_ENGINE_CLIENT_ANARCHY->N3Msg_KickTeamMember(get_identity());
	}

	void actor::make_leader()
	{
		if(this->is_team_member())
			P_ENGINE_CLIENT_ANARCHY->get_client_char()->make_team_leader(get_identity());
	}

	bool actor::send_team_invite()
	{
		if(this->is_player())
			return P_ENGINE_CLIENT_ANARCHY->N3Msg_TeamJoinRequest(get_identity(), true);
		return false;
	}	

}
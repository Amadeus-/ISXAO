#include "isxao_main.h"

namespace isxao_classes
{

	DWORD Actor::BuildLSNCU(LSIndex* pIndex)
	{
		auto l = GetSpellTemplateData()->GetSpellTemplateDataData().nano_template_list;
		for (auto it = l.begin(); it != l.end(); ++it)
		{
			auto pNanoTemplate = reinterpret_cast<NanoTemplate*>(&(*it));
			pIndex->AddItem(reinterpret_cast<LSOBJECTDATA&>(pNanoTemplate));
		}
		return pIndex->GetContainerUsed();
	}

	DWORD Actor::BuildLSPets(LSIndex* pIndex)
	{
		std::map<identity_t, DWORD> pet_map;
		if (GetPetIDs(pet_map) == 0)
			return 0;
		for (auto it = pet_map.begin(); it != pet_map.end(); ++it)
		{
			auto p_dynel = isxao_utilities::GetDynel(it->first);
			pIndex->AddItem(reinterpret_cast<LSOBJECTDATA&>(p_dynel));
		}
		return pIndex->GetContainerUsed();
	}

	DWORD Actor::Casting()
	{
		return GetSpellTemplateData()->GetNanoBeingCast();
	}

	PCSTR Actor::Consider()
	{
		float consider;
		P_ENGINE_CLIENT_ANARCHY->n3_msg_consider(get_identity(), consider);
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

	PCSTR Actor::ConColor()
	{
		RGBCOLOR argb = ConColorARGB();
		if (argb.ARGB == 0xFFFFFF)
			return "White";
		if (argb.ARGB == 0xAAAAAA)
			return "Grey";
		float fR = float(argb.R / 255);
		float fG = float(argb.G / 255);
		float fB = float(argb.B / 255);
		float fH = 0.0f;
		float fS = 0.0f;
		float fV = 0.0f;
		float fCMax = max(max(fR, fG), fB);
		float fCMin = min(min(fR, fG), fB);
		float fDelta = fCMax - fCMin;

		if (fDelta > 0) {
			if (fCMax == fR) {
				fH = 60 * (fmod(((fG - fB) / fDelta), 6));
			}
			else if (fCMax == fG) {
				fH = 60 * (((fB - fR) / fDelta) + 2);
			}
			else if (fCMax == fB) {
				fH = 60 * (((fR - fG) / fDelta) + 4);
			}

			if (fCMax > 0) {
				fS = fDelta / fCMax;
			}
			else {
				fS = 0;
			}

			fV = fCMax;
		}
		else {
			fH = 0;
			fS = 0;
			fV = fCMax;
		}

		if (fH < 0) {
			fH = 360 + fH;
		}
		if (fH < 0.0f)
			return "Unknown";
		if (fH <= 15.0f)
			return "Red";
		if (fH <= 45.0f)
			return "Orange";
		if (fH <= 75.0f)
			return "Yellow";
		return "Green";
	}

	RGBCOLOR Actor::ConColorARGB()
	{
		RGBCOLOR argb;
		argb.ARGB = 0xFFFFFF;
		float consider;
		DWORD con_type = P_ENGINE_CLIENT_ANARCHY->n3_msg_consider(get_identity(), consider);
		if (consider > 1.0f)
			consider = 1.0f;
		if(con_type == 3)
		{
			if(consider  > 0.0f)
			{
				if(consider >= 0.5f)
				{
					argb.ARGB = (int(2 * (1 - consider) * 240) | 0xFF00) << 8;
					return argb;
				}
				argb.ARGB = (int(2 * (consider * 255)) << 16) | 0xFF00;
				return argb;
			}
			argb.ARGB = 0xAAAAAA;
			return argb;				
		}
		return argb;
	}

	void Actor::DoFace()
	{
		vector3_t client_position;
		P_ENGINE_CLIENT_ANARCHY->n3_msg_get_global_character_position(client_position);
		auto position = get_position();
		auto new_rotation = quaternion_t::get_quaternion_to_face(position, client_position);
		P_ENGINE_CLIENT_ANARCHY->get_client_char()->SetRotation(new_rotation);
	}

	void Actor::DoTarget()
	{
		pTargetingModule->SetTarget(get_identity(), false);
	}

	float Actor::EstimatedDistanceTo(vector3_t &position)
	{
		vector3_t dynel_position = get_position();
		float uncompensated_distance = get_distance_to(position);
		float x = position.x - (dynel_position.x + GetVehicle()->GetVelocity().x*uncompensated_distance);
		float z = position.z - (dynel_position.z + GetVehicle()->GetVelocity().z*uncompensated_distance);
		vector3_t estimated_position;
		estimated_position.x = x;
		estimated_position.y = 0.0f;
		estimated_position.z = z;
		return estimated_position.length();
	}

	NanoTemplate* Actor::GetNCU(DWORD index)
	{
		std::vector<NanoTemplate> nano_template_vector;
		GetSpellTemplateData()->GetNanoTemplateList(nano_template_vector);
		if (index < 0 || index >= nano_template_vector.size())
			return nullptr;
		return static_cast<NanoTemplate*>(&(nano_template_vector[index]));
	}

	NanoTemplate* Actor::GetNCU(PCSTR effect_name)
	{
		identity_t dummy_identity;
		ZeroMemory(&dummy_identity, sizeof(identity_t));
		char name[MAX_STRING] = { 0 };
		char search_name[MAX_STRING];
		strcpy_s(search_name, MAX_STRING, effect_name);
		_strlwr_s(search_name);
		std::vector<NanoTemplate> nano_template_vector;
		GetSpellTemplateData()->GetNanoTemplateList(nano_template_vector);
		for (auto it = nano_template_vector.begin(); it != nano_template_vector.end(); ++it)
		{
			auto entry = static_cast<NanoTemplate*>(&(*it));
			strcpy_s(name, MAX_STRING, P_ENGINE_CLIENT_ANARCHY->n3_msg_get_name(entry->GetNanoIdentity(), dummy_identity));
			_strlwr_s(name);
			if (strstr(name, search_name))
				return entry;
		}
		return nullptr;
	}

	DWORD Actor::GetNCUCount()
	{
		std::vector<NanoTemplate> nano_template_vector;
		GetSpellTemplateData()->GetNanoTemplateList(nano_template_vector);
		return nano_template_vector.size();
	}

	SpellTemplateData* Actor::GetSpellTemplateData()
	{
		return reinterpret_cast<SpellTemplateData*>(GetSimpleCharData()->p_spell_template_data);
	}

	float Actor::GetScale()
	{
		return GetSimpleCharData()->body_scale;
	}

	p_simple_char_t Actor::GetSimpleCharData()
	{
		return p_simple_char_t(get_data());
	}

	Vehicle* Actor::GetVehicle()
	{
		return reinterpret_cast<Vehicle*>(GetSimpleCharData()->p_vehicle);
	}

	bool Actor::IsBackingUp()
	{
		return GetVehicle()->GetCharMovementStatus()->is_moving_forward_back != 1 && GetVehicle()->GetCharMovementStatus()->forward_back_direction == 2;
	}

	bool Actor::IsCasting()
	{
		return GetSpellTemplateData()->IsCasting();
	}

	bool Actor::IsFighting()
	{
		return GetSimpleCharData()->p_weapon_holder->is_attacking != 1;

	}

	bool Actor::IsFightingMe()
	{
		return IsClientId(GetSimpleCharData()->p_weapon_holder->weapon_target_identity.id);
	}

	bool Actor::IsIdle()
	{
		return GetVehicle()->GetCharMovementStatus()->is_moving_forward_back == 1 && GetVehicle()->GetCharMovementStatus()->is_moving_strafe == 1;
	}

	bool Actor::IsInMyTeam()
	{
		return is_player() && IsInTeam() && (GetTeamRaid()->GetTeamIdentity() == P_ENGINE_CLIENT_ANARCHY->get_client_char()->GetTeamRaid()->GetTeamIdentity());
	}

	bool Actor::IsInTeam()
	{
		if(is_player())
			return GetTeamRaid()->GetTeamIdentity().type != 0;
		return false;
	}

	bool Actor::IsInRaid()
	{
		return is_player() && IsInTeam() && GetTeamRaid()->GetTeamRaidIndex() != -1;
	}

	bool Actor::IsInMyRaidTeam()
	{
		if(is_team_member() && IsInRaid())
		{
			std::vector<TeamEntry*> v;
			P_ENGINE_CLIENT_ANARCHY->get_client_char()->GetTeamRaid()->GetTeam(v);
			for (auto it = v.begin(); it != v.end(); ++it)
			{
				if ((*it)->GetIdentity() == get_identity())
					return true;
			}
		}		
		return false;
	}

	bool Actor::IsInvis()
	{
		return !(GetSimpleCharData()->is_visible);
	}

	bool Actor::IsKOS()
	{
		return get_skill(ST_BREEDHOSTILITY) > 30;
	}

	bool Actor::IsMovingForward()
	{
		return GetVehicle()->GetCharMovementStatus()->is_moving_forward_back != 1 && GetVehicle()->GetCharMovementStatus()->forward_back_direction == 1;
	}

	bool Actor::IsNPC()
	{
		return GetSimpleCharData()->is_npc == 1;
	}

	bool Actor::IsStrafingLeft()
	{
		return GetVehicle()->GetCharMovementStatus()->is_moving_strafe != 1 && GetVehicle()->GetCharMovementStatus()->strafe_direction == 3;
	}

	bool Actor::IsStrafingRight()
	{
		return GetVehicle()->GetCharMovementStatus()->is_moving_strafe != 1 && GetVehicle()->GetCharMovementStatus()->strafe_direction == 4;
	}
	
	bool Actor::IsTeamLeader()
	{
		if(is_player())
		{
			auto result = false;
			if (P_ENGINE_CLIENT_ANARCHY && IsInTeam() && IsInMyTeam())
				result = P_ENGINE_CLIENT_ANARCHY->N3Msg_IsTeamLeader(get_identity());
			return result;
		}
		return false;
	}
	
	DWORD Actor::GetMasterId()
	{
		return get_skill(ST_PETMASTER);
	}

	Actor* Actor::GetMaster()
	{
		if (!is_pet())
			return nullptr;
		identity_t master;
		DWORD id = 0;
		master.type = 50000;
		id = get_skill(ST_PETMASTER);
		master.id = id;
		return isxao_utilities::GetDynel(master)->to_actor();
	}

	Actor* Actor::GetPet(DWORD index)
	{
		std::map<identity_t, DWORD> pet_map;
		if (GetPetIDs(pet_map) == 0)
			return nullptr;
		if (index < 0 || index >= pet_map.size())
			return nullptr;
		for (auto it = pet_map.begin(); it != pet_map.end(); ++it)
		{
			if (it->second == index)
				return isxao_utilities::GetDynel(it->first)->to_actor();
		}
		return nullptr;
	}

	Actor* Actor::GetPet(PCSTR pet_name)
	{
		identity_t dummy_identity;
		std::map<identity_t, DWORD> pet_map;
		char name[MAX_STRING];
		char search_name[MAX_STRING];
		if (GetPetIDs(pet_map) == 0)
			return nullptr;		
		ZeroMemory(&dummy_identity, sizeof(identity_t));
		strcpy_s(search_name, MAX_STRING, pet_name);
		_strlwr_s(search_name);
		for (auto it = pet_map.begin(); it != pet_map.end(); ++it)
		{
			strcpy_s(name, MAX_STRING, P_ENGINE_CLIENT_ANARCHY->n3_msg_get_name((*it).first, dummy_identity));
			_strlwr_s(name);
			if (strstr(name, search_name))
				return isxao_utilities::GetDynel((*it).first)->to_actor();
		}
		return nullptr;
	}

	DWORD Actor::GetPetCount()
	{
		std::map<identity_t, DWORD> pet_map;
		return GetPetIDs(pet_map);
	}

	DWORD Actor::GetPetIDs(std::map<identity_t, DWORD>& m)
	{
		std::map<identity_t, DWORD> pet_map;
		if (!IsClientId(get_identity().id))
		{
			std::map<identity_t, p_n3_dynel_t> dynel_map;
			GetDynelMap(dynel_map);
			DWORD pet_count = 0;
			for (auto it = dynel_map.begin(); it != dynel_map.end(); ++it)
			{
				if (it->first.type == 50000)
				{
					auto is_npc = P_ENGINE_CLIENT_ANARCHY->N3Msg_IsNpc(it->first);
					if (is_npc)
					{
						auto dynel = reinterpret_cast<dynel*>(it->second);
						if (dynel->get_skill(ST_PETMASTER) == get_identity().id)
						{
							pet_map.insert_or_assign(it->first, pet_count);
							pet_count++;
						}
					}
				}
			}
			return pet_map.size();
		}
		isxao_utilities::GetPetMap(m, to_character()->GetNPCHolder()->GetNPCHolderData().p_pet_dir);
		return m.size();
	}

	bool Actor::HasPet()
	{
		if(is_character())
		{
			std::map <identity_t, DWORD> pet_map;
			isxao_utilities::GetPetMap(pet_map, to_character()->GetNPCHolder()->GetNPCHolderData().p_pet_dir);
			if (pet_map.size() == 0)
				return false;
			return true;
		}
		std::map<identity_t, p_n3_dynel_t> dynel_map;
		isxao_utilities::GetDynelMap(dynel_map);
		for (auto it = dynel_map.begin(); it != dynel_map.end(); ++it)
		{
			if (it->first.type == 50000)
			{
				auto is_npc = P_ENGINE_CLIENT_ANARCHY->N3Msg_IsNpc(it->first);
				if (is_npc)
				{
					auto dynel = reinterpret_cast<dynel*>(it->second);
					if (dynel->get_skill(ST_PETMASTER) == get_identity().id)
						return true;
				}
			}
		}
		return false;
	}

	TeamRaid* Actor::GetTeamRaid()
	{
		if(is_player())
			return reinterpret_cast<TeamRaid*>(GetSimpleCharData()->p_team_raid_info);
		return nullptr;
	}

	WeaponHolder* Actor::GetWeaponHolder()
	{
		return reinterpret_cast<WeaponHolder*>(GetSimpleCharData()->p_weapon_holder);
	}

	void Actor::Kick()
	{
		if(is_team_member())
			P_ENGINE_CLIENT_ANARCHY->N3Msg_KickTeamMember(get_identity());
	}

	void Actor::MakeLeader()
	{
		if(is_team_member())
			P_ENGINE_CLIENT_ANARCHY->get_client_char()->MakeTeamLeader(get_identity());
	}

	bool Actor::SendTeamInvite()
	{
		if(is_player())
			return P_ENGINE_CLIENT_ANARCHY->N3Msg_TeamJoinRequest(get_identity(), true);
		return false;
	}	

}
#include "isxao_main.h"

namespace isxao_classes
{

	float Dynel::GetDistanceToClient()
	{
		vector3_t client_position;
		P_ENGINE_CLIENT_ANARCHY->N3Msg_GetGlobalCharacterPosition(client_position);
		return GetDistance3DTo(client_position);
	}

	float Dynel::GetDistanceTo(vector3_t& position)
	{
		auto dynel_position = GetPosition();
		return vector3_t::distance_xz(dynel_position, position);
	}

	float Dynel::GetDistance3DTo(vector3_t& position)
	{
		auto dynel_position = GetPosition();
		return vector3_t::distance(dynel_position, position);
	}

	float Dynel::GetDistance3DToSquared(vector3_t& position)
	{
		auto dynel_position = GetPosition();
		return vector3_t::distance_squared(dynel_position, position);
	}

	float Dynel::GetDistanceToSquared(vector3_t& position)
	{
		auto dynel_position = GetPosition();
		return vector3_t::distance_xz_squared(dynel_position, position);
	}

	float Dynel::GetDistanceXTo(vector3_t& position)
	{
		auto dynel_position = GetPosition();
		return vector3_t::distance_x(dynel_position, position);
	}

	float Dynel::GetDistanceYTo(vector3_t& position)
	{
		auto dynel_position = GetPosition();
		return vector3_t::distance_y(dynel_position, position);
	}

	float Dynel::GetDistanceZTo(vector3_t& position)
	{
		auto dynel_position = GetPosition();
		return vector3_t::distance_z(dynel_position, position);
	}

	float Dynel::GetHeading()
	{
		return GetRotation().get_heading();
	}

	float Dynel::GetHeadingTo(vector3_t & position)
	{
		auto direction_vector = vector3_t::subtract(GetPosition(), position);
		direction_vector.normalize();
		return direction_vector.get_yaw();
	}

	float Dynel::GetHeadingToLoc(vector3_t &position, vector3_t &position_offset)
	{
		vector3_t new_position = vector3_t::add(GetPosition(), position_offset);
		auto direction_vector = vector3_t::subtract(position, new_position);
		direction_vector.normalize();
		return direction_vector.get_yaw();
	}

	identity_t Dynel::GetIdentity()
	{
		return GetDynelData()->identity;
	}	

	void Dynel::Interact()
	{
		P_ENGINE_CLIENT_ANARCHY->N3Msg_DefaultActionOnDynel(GetIdentity());
	}

	bool Dynel::IsInLineOfSight()
	{
		vector3_t height_offset;
		height_offset.x = 0.0f;
		height_offset.y = 1.6f;
		height_offset.z = 0.0f;
		vector3_t client_position;
		P_ENGINE_CLIENT_ANARCHY->N3Msg_GetGlobalCharacterPosition(client_position);
		vector3_t offset_client_position = vector3_t::add(client_position, height_offset);
		vector3_t dynel_position = GetPosition();
		vector3_t offset_dynel_position = vector3_t::add(dynel_position, height_offset);
		return P_PLAYFIELD_DIR->GetPlayfield()->LineOfSight(offset_client_position, offset_dynel_position, GetDynelData()->p_vehicle->zone_instance_id, false);
	}

	bool Dynel::IsInLineOfSight(vector3_t &position)
	{
		vector3_t me = GetPosition();
		return P_PLAYFIELD_DIR->GetPlayfield()->LineOfSight(position, me, GetDynelData()->p_vehicle->zone_instance_id, false);
	}
	
	PCSTR Dynel::GetName()
	{
		identity_t dummy_identity;
		ZeroMemory(&dummy_identity, sizeof(identity_t));
		return P_ENGINE_CLIENT_ANARCHY->N3Msg_GetName(GetIdentity(), dummy_identity);
	}

	vector3_t Dynel::GetPosition()
	{
		if (GetDynelData()->p_vehicle->p_parent_vehicle == nullptr)
			return GetDynelData()->p_vehicle->global_pos;
		return GetDynelData()->p_vehicle->parent_global_pos;
	}

	quaternion_t Dynel::GetRotation()
	{
		if (GetDynelData()->p_vehicle->p_parent_vehicle == nullptr)
			return GetDynelData()->p_vehicle->body_rot;
		return GetDynelData()->p_vehicle->parent_body_rot;
	}

	LONG Dynel::GetSkill(DWORD stat)
	{
		identity_t dummy_identity; 
		ZeroMemory(&dummy_identity, sizeof(identity_t));
		if (!IsClientId(GetIdentity().id))
		{
			//if (!IsInfoRequestCompleted())
			//	isxao_utilities::RequestInfo(GetIdentity());
			return P_ENGINE_CLIENT_ANARCHY->N3Msg_GetSkill(GetIdentity(), stat, 2, dummy_identity);
		}			
		return P_ENGINE_CLIENT_ANARCHY->N3Msg_GetSkill(stat, 2);
	}

	bool Dynel::IsContainer()
	{
		return GetIdentity().type == 51017;
	}

	bool Dynel::IsCorpse()
	{
		return GetIdentity().type == 51050;
	}

	bool Dynel::IsDoor()
	{
		return GetIdentity().type == 51016;
	}

	bool Dynel::IsActor()
	{
		if (GetIdentity().type == 50000)
		{
			auto is_npc = P_ENGINE_CLIENT_ANARCHY->N3Msg_IsNpc(GetIdentity());
			return is_npc;
		}
		return false;
	}

	bool Dynel::IsInfoRequestCompleted()
	{
		if(!IsClientId(GetIdentity().id))
		{
			identity_t dummy_identity;
			ZeroMemory(&dummy_identity, sizeof(identity_t));
			auto profession = P_ENGINE_CLIENT_ANARCHY->N3Msg_GetSkill(GetIdentity(), ST_PROFESSION, 2, dummy_identity);
			//printf("%d", profession);
			return profession != -1;
		}
		return true;
	}

	bool Dynel::IsPet()
	{
		if (GetIdentity().type == 50000)
		{
			auto is_npc = P_ENGINE_CLIENT_ANARCHY->N3Msg_IsNpc(GetIdentity());
			if (is_npc)
			{
				if (GetSkill(ST_PETMASTER) != 1234567890)
					return true;
			}
		}
		return false;
	}

	bool Dynel::IsPlayer()
	{
		if (GetIdentity().type == 50000)
		{
			auto is_npc = P_ENGINE_CLIENT_ANARCHY->N3Msg_IsNpc(GetIdentity());
			return is_npc == 0;
		}
		return false;
	}

	bool Dynel::IsCharacter()
	{
		if (GetIdentity().type == 50000)
		{
			return GetIdentity().id == g_character_id;
		}
		return false;
	}

	bool Dynel::IsTeamMember()
	{
		return IsPlayer() && ToPlayer()->IsInMyTeam();
	}

	bool Dynel::IsVendingMachine()
	{
		return GetIdentity().type == 51035;
	}

	bool Dynel::IsWeaponInstance()
	{
		return GetIdentity().type == 51018;
	}

	PVOID Dynel::GetData()
	{
		return &n3_dynel_;
	}

	p_n3_dynel_t Dynel::GetDynelData()
	{
		return p_n3_dynel_t(GetData());
	}

	FUNCTION_AT_ADDRESS(void Dynel::SendIIRToObservers(InfoItemRemote*), n3_dynel_t__send_iir_to_observers)


	Actor* Dynel::ToActor()
	{
		return static_cast<Actor*>(GetData());
	}

	character* Dynel::ToCharacter()
	{
		return static_cast<character*>(GetData());
	}

	Pet* Dynel::ToPet()
	{
		return static_cast<Pet*>(GetData());
	}

	Player* Dynel::ToPlayer()
	{
		return static_cast<Player*>(GetData());
	}

	TeamMember* Dynel::ToTeamMember()
	{
		return static_cast<TeamMember*>(GetData());
	}
	
	FUNCTION_AT_ADDRESS(void Dynel::UpdateLocalityListeners(), n3_dynel_t__update_locality_listeners);


	bool Dynel::pDynelCompare(Dynel *pA, Dynel *pB)
	{
		return pA->GetDistanceToClient() < pB->GetDistanceToClient();
	}
	
}
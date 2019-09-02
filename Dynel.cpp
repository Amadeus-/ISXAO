#include "isxao_main.h"

namespace isxao_classes
{

	float Dynel::GetDistanceToClient()
	{
		VECTOR3 client_position;
		pEngineClientAnarchy->N3Msg_GetGlobalCharacterPosition(client_position);
		return GetDistance3DTo(client_position);
	}

	float Dynel::GetDistanceTo(VECTOR3& position)
	{
		auto dynel_position = GetPosition();
		return VECTOR3::DistanceXZ(dynel_position, position);
	}

	float Dynel::GetDistance3DTo(VECTOR3& position)
	{
		auto dynel_position = GetPosition();
		return VECTOR3::Distance(dynel_position, position);
	}

	float Dynel::GetDistance3DToSquared(VECTOR3& position)
	{
		auto dynel_position = GetPosition();
		return VECTOR3::DistanceSquared(dynel_position, position);
	}

	float Dynel::GetDistanceToSquared(VECTOR3& position)
	{
		auto dynel_position = GetPosition();
		return VECTOR3::DistanceXZSquared(dynel_position, position);
	}

	float Dynel::GetDistanceXTo(VECTOR3& position)
	{
		auto dynel_position = GetPosition();
		return VECTOR3::DistanceX(dynel_position, position);
	}

	float Dynel::GetDistanceYTo(VECTOR3& position)
	{
		auto dynel_position = GetPosition();
		return VECTOR3::DistanceY(dynel_position, position);
	}

	float Dynel::GetDistanceZTo(VECTOR3& position)
	{
		auto dynel_position = GetPosition();
		return VECTOR3::DistanceZ(dynel_position, position);
	}

	float Dynel::GetHeading()
	{
		return GetRotation().GetHeading();
	}

	float Dynel::GetHeadingTo(VECTOR3 & position)
	{
		auto direction_vector = VECTOR3::Subtract(GetPosition(), position);
		direction_vector.Normalize();
		return direction_vector.GetYaw();
	}

	float Dynel::GetHeadingToLoc(VECTOR3 &position, VECTOR3 &position_offset)
	{
		VECTOR3 new_position = VECTOR3::Add(GetPosition(), position_offset);
		auto direction_vector = VECTOR3::Subtract(position, new_position);
		direction_vector.Normalize();
		return direction_vector.GetYaw();
	}

	IDENTITY Dynel::GetIdentity()
	{
		return GetDynelData()->Identity;
	}	

	void Dynel::Interact()
	{
		pEngineClientAnarchy->N3Msg_DefaultActionOnDynel(GetIdentity());
	}

	bool Dynel::IsInLineOfSight()
	{
		VECTOR3 height_offset;
		height_offset.X = 0.0f;
		height_offset.Y = 1.6f;
		height_offset.Z = 0.0f;
		VECTOR3 client_position;
		pEngineClientAnarchy->N3Msg_GetGlobalCharacterPosition(client_position);
		VECTOR3 offset_client_position = VECTOR3::Add(client_position, height_offset);
		VECTOR3 dynel_position = GetPosition();
		VECTOR3 offset_dynel_position = VECTOR3::Add(dynel_position, height_offset);
		return P_PLAYFIELD_DIR->GetPlayfield()->LineOfSight(offset_client_position, offset_dynel_position, GetDynelData()->pVehicle->ZoneInstanceID, false);
	}

	bool Dynel::IsInLineOfSight(VECTOR3 &position)
	{
		VECTOR3 me = GetPosition();
		return P_PLAYFIELD_DIR->GetPlayfield()->LineOfSight(position, me, GetDynelData()->pVehicle->ZoneInstanceID, false);
	}
	
	PCSTR Dynel::GetName()
	{
		IDENTITY dummy_identity;
		ZeroMemory(&dummy_identity, sizeof(IDENTITY));
		return pEngineClientAnarchy->N3Msg_GetName(GetIdentity(), dummy_identity);
	}

	VECTOR3 Dynel::GetPosition()
	{
		if (GetDynelData()->pVehicle->pParentVehicle == nullptr)
			return GetDynelData()->pVehicle->GlobalPos;
		return GetDynelData()->pVehicle->ParentGlobalPos;
	}

	QUATERNION Dynel::GetRotation()
	{
		if (GetDynelData()->pVehicle->pParentVehicle == nullptr)
			return GetDynelData()->pVehicle->BodyRot;
		return GetDynelData()->pVehicle->ParentBodyRot;
	}

	LONG Dynel::GetSkill(DWORD stat)
	{
		IDENTITY dummy_identity; 
		ZeroMemory(&dummy_identity, sizeof(IDENTITY));
		if (!IsClientId(GetIdentity().Id))
		{
			//if (!IsInfoRequestCompleted())
			//	isxao_utilities::RequestInfo(GetIdentity());
			return pEngineClientAnarchy->N3Msg_GetSkill(GetIdentity(), stat, 2, dummy_identity);
		}			
		return pEngineClientAnarchy->N3Msg_GetSkill(stat, 2);
	}

	bool Dynel::IsContainer()
	{
		return GetIdentity().Type == 51017;
	}

	bool Dynel::IsCorpse()
	{
		return GetIdentity().Type == 51050;
	}

	bool Dynel::IsDoor()
	{
		return GetIdentity().Type == 51016;
	}

	bool Dynel::IsActor()
	{
		if (GetIdentity().Type == 50000)
		{
			auto is_npc = pEngineClientAnarchy->N3Msg_IsNpc(GetIdentity());
			return is_npc;
		}
		return false;
	}

	bool Dynel::IsInfoRequestCompleted()
	{
		if(!IsClientId(GetIdentity().Id))
		{
			IDENTITY dummy_identity;
			ZeroMemory(&dummy_identity, sizeof(IDENTITY));
			auto profession = pEngineClientAnarchy->N3Msg_GetSkill(GetIdentity(), ST_PROFESSION, 2, dummy_identity);
			//printf("%d", profession);
			return profession != -1;
		}
		return true;
	}

	bool Dynel::IsPet()
	{
		if (GetIdentity().Type == 50000)
		{
			auto is_npc = pEngineClientAnarchy->N3Msg_IsNpc(GetIdentity());
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
		if (GetIdentity().Type == 50000)
		{
			auto is_npc = pEngineClientAnarchy->N3Msg_IsNpc(GetIdentity());
			return is_npc == 0;
		}
		return false;
	}

	bool Dynel::IsCharacter()
	{
		if (GetIdentity().Type == 50000)
		{
			return GetIdentity().Id == g_character_id;
		}
		return false;
	}

	bool Dynel::IsTeamMember()
	{
		return IsPlayer() && ToPlayer()->IsInMyTeam();
	}

	bool Dynel::IsVendingMachine()
	{
		return GetIdentity().Type == 51035;
	}

	bool Dynel::IsWeaponInstance()
	{
		return GetIdentity().Type == 51018;
	}

	PVOID Dynel::GetData()
	{
		return &n3_dynel_;
	}

	PN3DYNEL Dynel::GetDynelData()
	{
		return PN3DYNEL(GetData());
	}

	FUNCTION_AT_ADDRESS(void Dynel::SendIIRToObservers(InfoItemRemote*), n3_dynel_t__send_iir_to_observers)


	Actor* Dynel::ToActor()
	{
		return static_cast<Actor*>(GetData());
	}

	Character* Dynel::ToCharacter()
	{
		return static_cast<Character*>(GetData());
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
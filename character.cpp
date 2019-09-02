#include "isxao_main.h"

namespace isxao_classes
{

#pragma region Holders

	InventoryHolder* Character::GetInventoryHolder()
	{
		return reinterpret_cast<InventoryHolder*>(GetSimpleCharData()->pContainerInventory);
	}

	NpcHolder* Character::GetNPCHolder()
	{
		return reinterpret_cast<NpcHolder*>(GetSimpleCharData()->pNpcHolder);
	}

	PerkHolder* Character::GetPerkHolder()
	{
		return reinterpret_cast<PerkHolder*>(GetSimpleCharData()->pPerkHolder);
	}

	SpecialActionHolder* Character::GetSpecialActionHolder()
	{
		return reinterpret_cast<SpecialActionHolder*>(GetSimpleCharData()->pSpecialActionHolder);
	}

	StatHolder* Character::GetStatHolder()
	{
		return reinterpret_cast<StatHolder*>(GetSimpleCharData()->pMapHolder);
	}

	void Character::GetStatMap(std::map<DWORD, LONG> &m)
	{
		GetStatHolder()->GetStatMap(m);
	}

#pragma endregion

#pragma region Info

#ifdef SimpleChar_t__CheckLOS_x
	FUNCTION_AT_ADDRESS(bool Character::CheckLOS(Dynel* pDynel), SimpleChar_t__CheckLOS);
#else
	bool Character::CheckLOS(Dynel* pDynel)
	{
		if (P_ENGINE_CLIENT_ANARCHY && P_ENGINE_CLIENT_ANARCHY->GetClientChar() && P_PLAYFIELD_DIR && P_PLAYFIELD_DIR->GetPlayfield())
		{
			VECTOR3 offset;
			offset.X = 0.0f;
			offset.Y = 1.6f;
			offset.Z = 0.0f;
			VECTOR3 client;
			P_ENGINE_CLIENT_ANARCHY->N3Msg_GetGlobalCharacterPosition(client);
			VECTOR3 offsetClient = VECTOR3::Add(client, offset);
			VECTOR3 dynel = pDynel->GetPosition();
			VECTOR3 offsetMe = VECTOR3::Add(dynel, offset);
			return P_PLAYFIELD_DIR->GetPlayfield()->LineOfSight(offsetClient, offsetMe, GetDynelData()->pVehicle->ZoneInstanceID, false);
		}
		return false;
	}
#endif

	bool Character::GetWeaponTarget(IDENTITY& id)
	{
		if (HasWeaponTarget())
		{
			id = pAttackingIndicator->Identity;
			return true;
		}
		return false;
	}

	bool Character::GetTarget(IDENTITY& id)
	{
		if (HasTarget())
		{
			id = pSelectionIndicator->Identity;
			return true;
		}
		return false;
	}

	bool Character::HasTarget()
	{
		return pSelectionIndicator != nullptr;
	}

	bool Character::HasWeaponTarget()
	{
		return pAttackingIndicator != nullptr;
	}

#pragma endregion

#pragma region Actions

	void Character::CastNanoSpell(IDENTITY const& nano, IDENTITY const& target) const
	{
		P_ENGINE_CLIENT_ANARCHY->N3Msg_CastNanoSpell(nano, target);
	}

	void Character::DefaultAttack(IDENTITY const& id) const
	{
		P_ENGINE_CLIENT_ANARCHY->N3Msg_DefaultAttack(id, true);
	}

	void Character::Face(float heading)
	{
		if (heading > 180.0f)
			heading -= 360.0f;
		auto q = QUATERNION::GetQuaternion(heading);
		SetRotation(q);
	}

	void Character::Face(VECTOR3 &location)
	{
		auto client_position = GetPosition();
		auto q = QUATERNION::GetQuaternionToFace(location, client_position);
		SetRotation(q);
	}

	void Character::MakeTeamLeader(const IDENTITY& id)
	{
		if (P_ENGINE_CLIENT_ANARCHY && IsInTeam() && IsTeamLeader())
			P_ENGINE_CLIENT_ANARCHY->N3Msg_TransferTeamLeadership(id);
	}

#ifdef n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_2_x
	bool Character::PerformSpecialAction(const IDENTITY &id) const
	{
		return P_ENGINE_CLIENT_ANARCHY->N3Msg_PerformSpecialAction(id);
	}

#else
	bool Character::PerformSpecialAction(const IDENTITY &id) const
	{
		typedef bool(__thiscall * tPerformSpecialAction)(PVOID, IDENTITY const &);
		auto pPerformSpecialAction = tPerformSpecialAction(n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_2);
		return pPerformSpecialAction(P_ENGINE_CLIENT_ANARCHY, id);
	}
#endif

	void Character::SetRotation(const QUATERNION& q)
	{
		GetVehicle()->SetRotation(q);
	}

	void Character::StopAttack() const
	{
		typedef void(__thiscall * tStopAttack)(PVOID);
		auto pStopAttack = tStopAttack(n3EngineClientAnarchy_t__N3Msg_StopAttack);
		pStopAttack(P_ENGINE_CLIENT_ANARCHY);
	}

#ifdef n3EngineClientAnarchy_t__N3Msg_UseItem_x
	void Character::UseItem(const IDENTITY& id)
	{
		P_ENGINE_CLIENT_ANARCHY->N3Msg_UseItem(id, false);
	}
#else
	void Character::UseItem(IDENTITY const& id)
	{
		IDENTITY dummy;
		dummy.Type = 0;
		dummy.Id = 0;
		if (P_ENGINE_CLIENT_ANARCHY->GetItemByTemplate(id, dummy))
		{
			typedef void(__thiscall * tUseItem)(PVOID, IDENTITY const &, bool);
			auto pUseItem = tUseItem(n3EngineClientAnarchy_t__N3Msg_UseItem);
			pUseItem(this, id, false);
		}
	}
#endif

#pragma endregion

}
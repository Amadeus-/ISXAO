#include "isxao_main.h"

namespace isxao_classes
{

#pragma region Holders

	InventoryHolder* Character::GetInventoryHolder()
	{
		return reinterpret_cast<InventoryHolder*>(GetSimpleCharData()->p_container_inventory);
	}

	NpcHolder* Character::GetNPCHolder()
	{
		return reinterpret_cast<NpcHolder*>(GetSimpleCharData()->p_npc_holder);
	}

	PerkHolder* Character::GetPerkHolder()
	{
		return reinterpret_cast<PerkHolder*>(GetSimpleCharData()->p_perk_holder);
	}

	SpecialActionHolder* Character::GetSpecialActionHolder()
	{
		return reinterpret_cast<SpecialActionHolder*>(GetSimpleCharData()->p_special_action_holder);
	}

	StatHolder* Character::GetStatHolder()
	{
		return reinterpret_cast<StatHolder*>(GetSimpleCharData()->p_map_holder);
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
			vector3_t offset;
			offset.X = 0.0f;
			offset.Y = 1.6f;
			offset.Z = 0.0f;
			vector3_t client;
			P_ENGINE_CLIENT_ANARCHY->N3Msg_GetGlobalCharacterPosition(client);
			vector3_t offsetClient = vector3_t::Add(client, offset);
			vector3_t dynel = pDynel->GetPosition();
			vector3_t offsetMe = vector3_t::Add(dynel, offset);
			return P_PLAYFIELD_DIR->GetPlayfield()->LineOfSight(offsetClient, offsetMe, GetDynelData()->pVehicle->ZoneInstanceID, false);
		}
		return false;
	}
#endif

	bool Character::GetWeaponTarget(identity_t& id)
	{
		if (HasWeaponTarget())
		{
			id = pAttackingIndicator->identity;
			return true;
		}
		return false;
	}

	bool Character::GetTarget(identity_t& id)
	{
		if (HasTarget())
		{
			id = pSelectionIndicator->identity;
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

	void Character::CastNanoSpell(identity_t const& nano, identity_t const& target) const
	{
		P_ENGINE_CLIENT_ANARCHY->N3Msg_CastNanoSpell(nano, target);
	}

	void Character::DefaultAttack(identity_t const& id) const
	{
		P_ENGINE_CLIENT_ANARCHY->N3Msg_DefaultAttack(id, true);
	}

	void Character::Face(float heading)
	{
		if (heading > 180.0f)
			heading -= 360.0f;
		auto q = quaternion_t::get_quaternion(heading);
		SetRotation(q);
	}

	void Character::Face(vector3_t &location)
	{
		auto client_position = GetPosition();
		auto q = quaternion_t::get_quaternion_to_face(location, client_position);
		SetRotation(q);
	}

	void Character::MakeTeamLeader(const identity_t& id)
	{
		if (P_ENGINE_CLIENT_ANARCHY && IsInTeam() && IsTeamLeader())
			P_ENGINE_CLIENT_ANARCHY->N3Msg_TransferTeamLeadership(id);
	}

#ifdef n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_2_x
	bool Character::PerformSpecialAction(const identity_t &id) const
	{
		return P_ENGINE_CLIENT_ANARCHY->N3Msg_PerformSpecialAction(id);
	}

#else
	bool Character::PerformSpecialAction(const identity_t &id) const
	{
		typedef bool(__thiscall * tPerformSpecialAction)(PVOID, identity_t const &);
		auto pPerformSpecialAction = tPerformSpecialAction(n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_2);
		return pPerformSpecialAction(P_ENGINE_CLIENT_ANARCHY, id);
	}
#endif

	void Character::SetRotation(const quaternion_t& q)
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
	void Character::UseItem(const identity_t& id)
	{
		P_ENGINE_CLIENT_ANARCHY->N3Msg_UseItem(id, false);
	}
#else
	void Character::UseItem(identity_t const& id)
	{
		identity_t dummy;
		dummy.Type = 0;
		dummy.Id = 0;
		if (P_ENGINE_CLIENT_ANARCHY->get_item_by_template(id, dummy))
		{
			typedef void(__thiscall * tUseItem)(PVOID, identity_t const &, bool);
			auto pUseItem = tUseItem(n3EngineClientAnarchy_t__N3Msg_UseItem);
			pUseItem(this, id, false);
		}
	}
#endif

#pragma endregion

}
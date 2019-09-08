#include "isxao_main.h"

namespace isxao_classes
{

#pragma region Holders

	InventoryHolder* character::GetInventoryHolder()
	{
		return reinterpret_cast<InventoryHolder*>(GetSimpleCharData()->p_container_inventory);
	}

	NpcHolder* character::GetNPCHolder()
	{
		return reinterpret_cast<NpcHolder*>(GetSimpleCharData()->p_npc_holder);
	}

	PerkHolder* character::GetPerkHolder()
	{
		return reinterpret_cast<PerkHolder*>(GetSimpleCharData()->p_perk_holder);
	}

	SpecialActionHolder* character::GetSpecialActionHolder()
	{
		return reinterpret_cast<SpecialActionHolder*>(GetSimpleCharData()->p_special_action_holder);
	}

	StatHolder* character::GetStatHolder()
	{
		return reinterpret_cast<StatHolder*>(GetSimpleCharData()->p_map_holder);
	}

	void character::GetStatMap(std::map<DWORD, LONG> &m)
	{
		GetStatHolder()->GetStatMap(m);
	}

#pragma endregion

#pragma region Info

#ifdef SIMPLE_CHAR_T__CHECK_LOS_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool character::check_los(Dynel* p_dynel), simple_char_t__check_los);
#else
	bool character::check_los(Dynel* p_dynel)
	{
		if (GetGameState() == GAMESTATE_IN_GAME)
		{
			vector3_t offset;
			offset.x = 0.0f;
			offset.y = 1.6f;
			offset.z = 0.0f;
			vector3_t client;
			P_ENGINE_CLIENT_ANARCHY->n3_msg_get_global_character_position(client);
			const auto offset_client = vector3_t::add(client, offset);
			auto dynel = p_dynel->GetPosition();
			const vector3_t offset_me = vector3_t::add(dynel, offset);
			return P_PLAYFIELD_DIR->GetPlayfield()->LineOfSight(offset_client, offset_me, GetDynelData()->p_vehicle->zone_instance_id, false);
		}
		return false;
	}
#endif

	bool character::GetWeaponTarget(identity_t& id)
	{
		if (HasWeaponTarget())
		{
			id = pAttackingIndicator->identity;
			return true;
		}
		return false;
	}

	bool character::GetTarget(identity_t& id)
	{
		if (HasTarget())
		{
			id = pSelectionIndicator->identity;
			return true;
		}
		return false;
	}

	bool character::HasTarget()
	{
		return pSelectionIndicator != nullptr;
	}

	bool character::HasWeaponTarget()
	{
		return pAttackingIndicator != nullptr;
	}

#pragma endregion

#pragma region Actions

	void character::CastNanoSpell(identity_t const& nano, identity_t const& target) const
	{
		P_ENGINE_CLIENT_ANARCHY->N3Msg_CastNanoSpell(nano, target);
	}

	void character::DefaultAttack(identity_t const& id) const
	{
		P_ENGINE_CLIENT_ANARCHY->N3Msg_DefaultAttack(id, true);
	}

	void character::Face(float heading)
	{
		if (heading > 180.0f)
			heading -= 360.0f;
		auto q = quaternion_t::get_quaternion(heading);
		SetRotation(q);
	}

	void character::Face(vector3_t &location)
	{
		auto client_position = GetPosition();
		auto q = quaternion_t::get_quaternion_to_face(location, client_position);
		SetRotation(q);
	}

	void character::MakeTeamLeader(const identity_t& id)
	{
		if (P_ENGINE_CLIENT_ANARCHY && IsInTeam() && IsTeamLeader())
			P_ENGINE_CLIENT_ANARCHY->N3Msg_TransferTeamLeadership(id);
	}

#ifdef n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_2_x
	bool character::PerformSpecialAction(const identity_t &id) const
	{
		return P_ENGINE_CLIENT_ANARCHY->N3Msg_PerformSpecialAction(id);
	}

#else
	bool character::PerformSpecialAction(const identity_t &id) const
	{
		typedef bool(__thiscall * tPerformSpecialAction)(PVOID, identity_t const &);
		auto pPerformSpecialAction = tPerformSpecialAction(n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_2);
		return pPerformSpecialAction(P_ENGINE_CLIENT_ANARCHY, id);
	}
#endif

	void character::SetRotation(const quaternion_t& q)
	{
		GetVehicle()->SetRotation(q);
	}

	void character::StopAttack() const
	{
		typedef void(__thiscall * tStopAttack)(PVOID);
		auto pStopAttack = tStopAttack(n3EngineClientAnarchy_t__N3Msg_StopAttack);
		pStopAttack(P_ENGINE_CLIENT_ANARCHY);
	}

#ifdef n3EngineClientAnarchy_t__N3Msg_UseItem_x
	void character::UseItem(const identity_t& id)
	{
		P_ENGINE_CLIENT_ANARCHY->N3Msg_UseItem(id, false);
	}
#else
	void character::UseItem(identity_t const& id)
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
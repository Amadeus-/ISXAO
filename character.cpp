#include "isxao_main.h"

namespace ao
{

#pragma region Holders

	inventory_holder* character::get_inventory_holder()
	{
		return reinterpret_cast<inventory_holder*>(this->get_simple_char_data()->p_container_inventory);
	}

	npc_holder* character::get_npc_holder()
	{
		return reinterpret_cast<npc_holder*>(this->get_simple_char_data()->p_npc_holder);
	}

	perk_holder* character::get_perk_holder()
	{
		return reinterpret_cast<perk_holder*>(this->get_simple_char_data()->p_perk_holder);
	}

	special_action_holder* character::get_special_action_holder()
	{
		return reinterpret_cast<special_action_holder*>(this->get_simple_char_data()->p_special_action_holder);
	}

	stat_holder* character::get_stat_holder()
	{
		return reinterpret_cast<stat_holder*>(this->get_simple_char_data()->p_map_holder);
	}

	void character::get_stat_map(std::map<DWORD, LONG> &m)
	{
		get_stat_holder()->get_stat_map(m);
	}

#pragma endregion

#pragma region Info

#ifdef SIMPLE_CHAR_T__CHECK_LOS_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool character::check_los(dynel* p_dynel), simple_char_t__check_los);
#else
	bool character::check_los(dynel* p_dynel)
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
			auto dynel = p_dynel->get_position();
			const vector3_t offset_me = vector3_t::add(dynel, offset);
			return P_PLAYFIELD_DIR->GetPlayfield()->LineOfSight(offset_client, offset_me, get_dynel_data()->p_vehicle->zone_instance_id, false);
		}
		return false;
	}
#endif

	bool character::get_weapon_target(identity_t& id)
	{
		if (character::has_weapon_target())
		{
			id = P_ATTACKING_INDICATOR->identity;
			return true;
		}
		return false;
	}

	bool character::get_target(identity_t& id)
	{
		if (character::has_target())
		{
			id = P_SELECTION_INDICATOR->identity;
			return true;
		}
		return false;
	}

	bool character::has_target()
	{
		return P_SELECTION_INDICATOR != nullptr;
	}

	bool character::has_weapon_target()
	{
		return P_ATTACKING_INDICATOR != nullptr;
	}

#pragma endregion

#pragma region Actions

	void character::cast_nano_spell(identity_t const& nano, identity_t const& target)
	{
		P_ENGINE_CLIENT_ANARCHY->n3_msg_cast_nano_spell(nano, target);
	}

	void character::default_attack(identity_t const& id)
	{
		P_ENGINE_CLIENT_ANARCHY->n3_msg_default_attack(id, true);
	}

	void character::face(float heading)
	{
		if (heading > 180.0f)
			heading -= 360.0f;
		const auto q = quaternion_t::get_quaternion(heading);
		this->set_rotation(q);
	}

	void character::face(vector3_t &location)
	{
		auto client_position = get_position();
		const auto q = quaternion_t::get_quaternion_to_face(location, client_position);
		this->set_rotation(q);
	}

	void character::make_team_leader(const identity_t& id)
	{
		if (P_ENGINE_CLIENT_ANARCHY && this->is_in_team() && this->is_team_leader())
			P_ENGINE_CLIENT_ANARCHY->N3Msg_TransferTeamLeadership(id);
	}

	bool character::perform_special_action(const identity_t &id)
	{
		return P_ENGINE_CLIENT_ANARCHY->n3_msg_perform_special_action(id);
	}

	void character::set_rotation(const quaternion_t& q)
	{
		this->get_vehicle()->set_rotation(q);
	}

	void character::stop_attack()
	{
		P_ENGINE_CLIENT_ANARCHY->n3_msg_stop_attack();
	}

	void character::use_item(const identity_t& id)
	{
		P_ENGINE_CLIENT_ANARCHY->n3_msg_use_item(id, false);
	}

#pragma endregion

}
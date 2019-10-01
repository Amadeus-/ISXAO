#include "isxao_main.h"
#include "character.h"
#include "dynel.h"
#include "engine_client_anarchy.h"

namespace ao
{

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(const char* engine_client_anarchy::get_breed_str(breed_e), n3_engine_client_anarchy_t__get_breed_str)
#else
	// ReSharper disable once CppParameterMayBeConst
	const char* engine_client_anarchy::get_breed_str(breed_e breed_id)
	{
		switch (breed_id)
		{
		case ao::BT_NOTHING:
			return "Nothing";
		case ao::BT_SOLITUS:
			return "Solitus";
		case ao::BT_OPIFEX:
			return "Opifex";
		case ao::BT_NANOMAGE:
			return "Nanomage";
		case ao::BT_ATROX:
			return "Atrox";
		case ao::BT_SPECIAL:
			return "Special";
		case ao::BT_MONSTER:
			return "Monster";
		case ao::BT_HUMAN_MONSTER:
			return "human monster";
		default:
			char buffer[MAX_VARSTRING];
			sprintf_s(buffer, sizeof(buffer), "Missing breed: %d", unsigned long(breed_id));
			return const char*(pISInterface->GetTempBuffer(sizeof(buffer), buffer));
		}
	}
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(character* engine_client_anarchy::get_client_char(), n3_engine_client_anarchy_t__get_client_char)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	character* engine_client_anarchy::get_client_char(void)
	{
		return reinterpret_cast<character*>(get_data()->p_client_control_char);
	}
#endif	

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(p_identity_t engine_client_anarchy::get_client_dynel_id(identity_t &), n3_engine_client_anarchy_t__get_client_dynel_id)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	p_identity_t engine_client_anarchy::get_client_dynel_id(identity_t& id)
	{
		id.type = 50000;
		id.id = get_data()->client_inst_id;
		return &id;
	}
#endif	

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::get_current_movement_mode(), n3_engine_client_anarchy_t__get_current_movement_mode)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	unsigned long engine_client_anarchy::get_current_movement_mode()
	{
		return get_data()->p_client_control_char->p_vehicle->p_char_movement_status->movement_mode;
	}
#endif

	//n3_engine_client_anarchy_t engine_client_anarchy::get_data() const
	//{
	//	return n3_engine_client_anarchy_;
	//}

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(const char* engine_client_anarchy::get_faction_str(unsigned long, bool), n3_engine_client_anarchy_t__get_faction_str)
#else
	static_assert(false, "engine_client_anarchy::get_faction_str(unsigned long, bool) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(const char* engine_client_anarchy::get_faction_title(unsigned long), n3_engine_client_anarchy_t__get_faction_title)
#else
	static_assert(false, "engine_client_anarchy::get_faction_title(unsigned long) requires a native function.");
#endif


#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(const char* engine_client_anarchy::get_gender_string(identity_t const &), n3_engine_client_anarchy_t__get_gender_string)
#else
	static_assert(false, "engine_client_anarchy::get_gender_string(const identity_t&) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(p_dummy_item_base_t engine_client_anarchy::get_item_by_template(identity_t, identity_t const &), n3_engine_client_anarchy_t__get_item_by_template)
#else
	static_assert(false, "engine_client_anarchy::get_item_by_template(identity_t, identity_t const &) requires a native function.");
#endif

	const char* engine_client_anarchy::get_item_rarity_str(const unsigned long rarity_id)
	{
		auto result = "Unknown";
		switch (rarity_id)
		{
		case 1:
			result = "Trash";
			break;
		case 2:
			result = "Normal";
			break;
		case 3:
			result = "Exotic";
			break;
		case 4:
			result = "Quest";
			break;
		case 5:
			result = "Social";
			break;
		default:
			break;
		}
		return result;
	}

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(int engine_client_anarchy::get_last_speed_mode(), n3_engine_client_anarchy_t__get_last_speed_mode)
#else
	static_assert(false, "engine_client_anarchy::get_last_speed_mode() requires a native function.");
#endif

#if true
	FUNCTION_AT_ADDRESS(ao::p_nano_item_t engine_client_anarchy::get_nano_item(unsigned long), f_get_nano_item)
#else
	static_assert(false, "engine_client_anarchy::get_nano_item(unsigned long) requires a native function.");
#endif

	const char* engine_client_anarchy::get_nano_school_str(const unsigned long school_id)
	{
		auto result = "Unknown";
		switch (school_id)
		{
		case 1:
			result = "Combat";
			break;
		case 2:
			result = "Medical";
			break;
		case 3:
			result = "Protection";
			break;
		case 4:
			result = "Psi";
			break;
		case 5:
			result = "Space";
			break;
		default:
			break;
		}
		return result;
	}

	const char* engine_client_anarchy::get_profession_str(const ao::profession_e prof_id)
	{
		switch (prof_id)
		{
		case ao::PT_NONE:
			return "None";
		case ao::PT_SOLDIER:
			return "Soldier";
		case ao::PT_MARTIAL_ARTIST:
			return "Martial Artist";
		case ao::PT_ENGINEER:
			return "Engineer";
		case ao::PT_FIXER:
			return "Fixer";
		case ao::PT_AGENT:
			return "Agent";
		case ao::PT_ADVENTURER:
			return "Adventurer";
		case ao::PT_TRADER:
			return "Trader";
		case ao::PT_BUREAUCRAT:
			return "Bureaucrat";
		case ao::PT_ENFORCER:
			return "Enforcer";
		case ao::PT_DOCTOR:
			return "Doctor";
		case ao::PT_NANO_TECHNICIAN:
			return "Nano Technician";
		case ao::PT_META_PHYSICIST:
			return "Meta-Physicist";
		case ao::PT_MONSTER:
			return "Monster";
		case ao::PT_KEEPER:
			return "Keeper";
		case ao::PT_SHADE:
			return "Shade";
		default:
			return "Unknown";
		}
	}

#if true
	FUNCTION_AT_ADDRESS(const char* engine_client_anarchy::get_sex_str(gender_e), n3_engine_client_anarchy_t__get_sex_str)
#else
	// ReSharper disable once CppParameterMayBeConst
	const char* engine_client_anarchy::get_sex_str(gender_e gender_id)
	{
		switch (gender_id)
		{
		case ao::GT_NONE:
			return "NONE";
		case ao::GT_UNI:
			return "uni";
		case ao::GT_MALE:
			return "male";
		case ao::GT_FEMALE:
			return "female";
		default:
			char buffer[MAX_VARSTRING];
			sprintf_s(buffer, sizeof(buffer), "Missing sex: %d", unsigned long(gender_id));
			return const char*(pISInterface->GetTempBuffer(sizeof(buffer), buffer));
		}
	}
#endif

	const char* engine_client_anarchy::get_side_str(const ao::side_e side_id)
	{
		switch (side_id)
		{
		case ao::SD_NEUTRAL:
			return "Neutral";
		case ao::SD_CLAN:
			return "Clan";
		case ao::SD_OMNI:
			return "Omni";
		case ao::SD_MONSTER:
			return "Monster";
		case ao::SD_ADVISOR:
			return "Advisor";
		case ao::SD_GUARDIAN:
			return "Guardian";
		case ao::SD_GM:
			return "GM";
		case ao::SD_MIXED:
			return "Mixed";
		default:
			return "Unknown";
		}
	}

	unsigned long engine_client_anarchy::get_static_item_map(std::map<ao::identity_t, ao::p_dummy_item_base_t>& m)
	{
		const auto count = P_STATIC_ITEM_VECTOR->size();
		for (unsigned long i = 0; i < count; i++)
		{
			if (P_STATIC_ITEM_VECTOR->at(i).p_dummy_item)
				m.insert_or_assign(P_STATIC_ITEM_VECTOR->at(i).p_dummy_item->identity, P_STATIC_ITEM_VECTOR->at(i).p_dummy_item);
		}
		return m.size();
	}

#if true
	FUNCTION_AT_ADDRESS(const char* engine_client_anarchy::get_title_string(unsigned long, unsigned long), n3_engine_client_anarchy_t__get_title_str)
#else
	static_assert(false, "engine_client_anarchy::get_title_string(unsigned long, unsigned long) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::is_first_login(), n3_engine_client_anarchy_t__is_first_login)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	bool engine_client_anarchy::is_first_login(void)
	{
		return get_data()->is_first_login == 1;
	}
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::is_fixture(const identity_t &, const identity_t &), n3_engine_client_anarchy_t__is_fixture)
#else
	static_assert(false, "engine_client_anarchy::is_fixture(const identity_t &, const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_activate_mech(unsigned long), n3_engine_client_anarchy_t__n3_msg_activate_mech);
#else
	static_assert(false, "engine_client_anarchy::n3_msg_activate_mech(unsigned long) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_airstrike(const identity_t &), n3_engine_client_anarchy_t__n3_msg_airstrike)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_airstrike(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_artillery_attack(const identity_t &), n3_engine_client_anarchy_t__n3_msg_artillery_attack)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_artillery_attack(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_assist_fight(const identity_t &), n3_engine_client_anarchy_t__n3_msg_assist_fight)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_artillery_attack(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_can_attack(const identity_t &), n3_engine_client_anarchy_t__n3_msg_can_attack)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_can_attack(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_can_click_target_target(const identity_t &, const identity_t &), n3_engine_client_anarchy_t__n3_msg_can_click_target_target)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_can_click_target_target(const identity_t &, const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_can_use_mech(), n3_engine_client_anarchy_t__n3_msg_can_use_mech)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_can_use_mech(void) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_cast_nano_spell(const identity_t &, const identity_t &), n3_engine_client_anarchy_t__n3_msg_cast_nano_spell)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_cast_nano_spell(const identity_t &, const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::n3_msg_consider(const identity_t &, float &), n3_engine_client_anarchy_t__n3_msg_consider)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_consider(const identity_t &, float &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_container_add_item(const identity_t &, const identity_t &), n3_engine_client_anarchy_t__n3_msg_container_add_item)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_container_add_item(const identity_t &, const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_crawl_toggle(), n3_engine_client_anarchy_t__n3_msg_crawl_toggle)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_crawl_toggle(void) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_create_raid(), n3_engine_client_anarchy_t__n3_msg_create_raid)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_create_raid(void) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_default_action_on_dynel(const identity_t &), n3_engine_client_anarchy_t__n3_msg_default_action_on_dynel)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_default_action_on_dynel(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_default_attack(const identity_t &, bool), n3_engine_client_anarchy_t__n3_msg_default_attack)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_default_attack(const identity_t &, bool) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_delete_item(const identity_t&, const identity_t&), n3_engine_client_anarchy_t__n3_msg_delete_item)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_delete_item(const identity_t&, const identity_t&) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_delete_nano(const identity_t &), n3_engine_client_anarchy_t__n3_msg_delete_nano)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_delete_nano(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::n3_msg_do_social_action(social_action_e), n3_engine_client_anarchy_t__n3_msg_do_social_action)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_do_social_action(social_action_e) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_drop_item(const identity_t &, const vector3_t &), n3_engine_client_anarchy_t__n3_msg_drop_item)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_drop_item(const identity_t &, const vector3_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_duel_accept(), n3_engine_client_anarchy_t__n3_msg_duel_accept)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_duel_accept() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_duel_challenge(const identity_t &), n3_engine_client_anarchy_t__n3_msg_duel_challenge)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_duel_challenge(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_duel_draw(), n3_engine_client_anarchy_t__n3_msg_duel_draw)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_duel_draw() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_duel_refuse(), n3_engine_client_anarchy_t__n3_msg_duel_refuse);
#else
	static_assert(false, "engine_client_anarchy::n3_msg_duel_refuse() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_duel_stop(), n3_engine_client_anarchy_t__n3_msg_duel_stop)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_duel_stop() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_forage(), n3_engine_client_anarchy_t__n3_msg_forage)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_forage() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::n3_msg_get_action_by_name(const char*), n3_engine_client_anarchy_t__n3_msg_get_action_by_name)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_action_by_name(const char*) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(float engine_client_anarchy::n3_msg_get_action_progress(const identity_t &, unsigned long*, unsigned long*), n3_engine_client_anarchy_t__n3_msg_get_action_progress)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_action_progress(const identity_t &, unsigned long*, unsigned long*) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(LONG engine_client_anarchy::n3_msg_get_agg_def(), n3_engine_client_anarchy_t__n3_msg_get_agg_def)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_agg_def() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(const char* engine_client_anarchy::n3_msg_get_alien_level_string(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_alien_level_string)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_alien_level_string(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_get_area_name(const char**), n3_engine_client_anarchy_t__n3_msg_get_area_name)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_area_name(const char**) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_get_attacking_id(identity_t &), n3_engine_client_anarchy_t__n3_msg_get_attacking_id)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	bool engine_client_anarchy::n3_msg_get_attacking_id(identity_t& id)
	{
		if (g_game_state == GAMESTATE_IN_GAME && get_data()->p_client_control_char->p_weapon_holder->is_attacking == 1)
		{
			id = get_data()->p_client_control_char->p_weapon_holder->weapon_target_identity;
			return true;
		}
		return false;
	}
#endif	

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(const char* engine_client_anarchy::n3_msg_get_breed_str(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_breed_str)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_breed_str(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::n3_msg_get_buff_current_time(const identity_t &, const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_buff_current_time)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_buff_current_time(const identity_t &, const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::n3_msg_get_buff_total_time(const identity_t &, const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_buff_total_time)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_buff_total_time(const identity_t &, const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_get_character_body_shape(unsigned char &, identity_t), n3_engine_client_anarchy_t__n3_msg_get_character_body_shape)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_character_body_shape(BYTE &, identity_t) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_get_char_orientation_data(const identity_t &, vector3_t &, quaternion_t &, float &), n3_engine_client_anarchy_t__n3_msg_get_char_orientation_data)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_char_orientation_data(const identity_t &, vector3_t &, quaternion_t &, float &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(const char* engine_client_anarchy::n3_msg_get_city_name_for_clan_member(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_city_name_for_clan_member)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_city_name_for_clan_member(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(const char* engine_client_anarchy::n3_msg_get_clan_level_string(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_clan_level_string)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_clan_level_string(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(string* engine_client_anarchy::n3_msg_get_clan_string(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_clan_string)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_clan_string(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(p_identity_t engine_client_anarchy::n3_msg_get_client_pet_id(identity_t &, unsigned long), n3_engine_client_anarchy_t__n3_msg_get_client_pet_id)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_client_pet_id(identity_t &, unsigned long) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_get_close_target(identity_t &, bool, bool), n3_engine_client_anarchy_t__n3_msg_get_close_target)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_close_target(identity_t &, bool, bool) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(p_inventory_holder_t engine_client_anarchy::n3_msg_get_container_inventory_list(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_container_inventory_list)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_container_inventory_list(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_get_correct_action_id(identity_t &), n3_engine_client_anarchy_t__n3_msg_get_correct_action_id)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_correct_action_id(identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(LONG engine_client_anarchy::n3_msg_get_current_room(), n3_engine_client_anarchy_t__n3_msg_get_current_room)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_current_room() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(const char* engine_client_anarchy::n3_msg_get_current_room_name(), n3_engine_client_anarchy_t__n3_msg_get_current_room_name)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_current_room_name() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::n3_msg_get_district_fight_mode(), n3_engine_client_anarchy_t__n3_msg_get_district_fight_mode)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_district_fight_mode() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_get_dynels_in_vicinity(vector<identity_t>&, bool, bool, type_id_e), n3_engine_client_anarchy_t__n3_msg_get_dynels_in_vicinity)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_dynels_in_vicinity(vector<identity_t>&, bool, bool, type_id_e) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_get_faction_info_string(const identity_t &, string &), n3_engine_client_anarchy_t__n3_msg_get_faction_info_string)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_faction_info_string(const identity_t &, string &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_get_faction_range(unsigned long, unsigned long &, unsigned long &), n3_engine_client_anarchy_t__n3_msg_get_faction_range)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_faction_range(unsigned long, unsigned long &, unsigned long &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(const char* engine_client_anarchy::n3_msg_get_first_name(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_first_name)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_first_name(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(double engine_client_anarchy::n3_msg_get_formula_progress(const identity_t &, unsigned long &, unsigned long &), n3_engine_client_anarchy_t__n3_msg_get_formula_progress)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_formula_progress(const identity_t &, unsigned long &, unsigned long &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::n3_msg_get_formula_radius(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_formula_radius)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_formula_radius(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_get_global_character_position(vector3_t &), n3_engine_client_anarchy_t__n3_msg_get_global_character_position)
#else
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	void engine_client_anarchy::n3_msg_get_global_character_position(vector3_t& pos)
	{
		if (g_game_state == GAMESTATE_IN_GAME)
		{
			const auto client_pos = P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_position();
			pos.copy(client_pos);
		}
	}
#endif

#if true
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::n3_msg_get_full_perk_map(), n3_engine_client_anarchy_t__n3_msg_get_full_perk_map)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_full_perk_map() requires a native function.");
#endif

#if false
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_get_global_character_rotation(quaternion_t &), n3_engine_client_anarchy_t__n3_msg_get_global_character_rotation)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	// ReSharper disable once CppMemberFunctionMayBeStatic
	void engine_client_anarchy::n3_msg_get_global_character_rotation(quaternion_t& rot)
	{
		if (g_game_state == GAMESTATE_IN_GAME)
		{
			const auto client_rot = P_ENGINE_CLIENT_ANARCHY->get_client_char()->to_dynel()->get_rotation();
			rot.copy(client_rot);
		}
	}
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(PVOID engine_client_anarchy::n3_msg_get_grid_destination_list(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_1)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_grid_destination_list(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(PVOID engine_client_anarchy::n3_msg_get_grid_destination_list(), n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_2);
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	PVOID engine_client_anarchy::n3_msg_get_grid_destination_list()
	{
		if (GetGameState() == GAMESTATE_IN_GAME)
		{
			return n3_engine_client_anarchy_.p_grid_destination_list;
		}
		return nullptr;
	}
#endif	

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(std::vector<p_inventory_data_t>* engine_client_anarchy::n3_msg_get_inventory_vec(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_inventory_vec)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_inventory_vec(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_get_item(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_item)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_item(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(double engine_client_anarchy::n3_msg_get_item_progress(const identity_t &, unsigned long &, unsigned long &), n3_engine_client_anarchy_t__n3_msg_get_item_progress)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_item_progress(const identity_t &, unsigned long &, unsigned long &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::n3_msg_get_movement_mode(), n3_engine_client_anarchy_t__n3_msg_get_movement_mode)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_movement_mode() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(const char* engine_client_anarchy::n3_msg_get_name(const identity_t &, const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_name)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_name(const identity_t &, const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::n3_msg_get_nano_cost_modifier(), n3_engine_client_anarchy_t__n3_msg_get_nano_cost_modifier)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_nano_cost_modifier() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(std::list<unsigned long>* engine_client_anarchy::n3_msg_get_nano_spell_list(), n3_engine_client_anarchy_t__n3_msg_get_nano_spell_list)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	std::list<unsigned long>* engine_client_anarchy::n3_msg_get_nano_spell_list()
	{
		if (GetGameState() == GAMESTATE_IN_GAME)
		{
			return &n3_engine_client_anarchy_.p_client_control_char->p_spell_template_data->spell_list;
		}
		return nullptr;
	}
#endif	

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(std::list<nano_template_t>* engine_client_anarchy::n3_msg_get_nano_template_info_list(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_1)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_nano_template_info_list(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(std::list<nano_template_t>* engine_client_anarchy::n3_msg_get_nano_template_info_list(), n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_2);
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	std::list<nano_template>* engine_client_anarchy::n3_msg_get_nano_template_info_list()
	{
		if (GetGameState() == GAMESTATE_IN_GAME)
		{
			return &n3_engine_client_anarchy_.p_client_control_char->p_spell_template_data->nano_template_list;
		}
		return nullptr;
	}
#endif	

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(p_identity_t engine_client_anarchy::n3_msg_get_next_target(identity_t &, unsigned long), n3_engine_client_anarchy_t__n3_msg_get_next_target)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_next_target(identity_t &, unsigned long) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::n3_msg_get_number_of_available_alien_perks(), n3_engine_client_anarchy_t__n3_msg_get_number_of_available_alien_perks)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_number_of_available_alien_perks() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::n3_msg_get_number_of_available_perks(), n3_engine_client_anarchy_t__n3_msg_get_number_of_available_perks)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_number_of_available_perks() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::n3_msg_get_number_of_free_inventory_slots(), n3_engine_client_anarchy_t__n3_msg_get_number_of_free_inventory_slots)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_number_of_free_inventory_slots() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::n3_msg_get_number_of_used_alien_perks(), n3_engine_client_anarchy_t__n3_msg_get_number_of_used_alien_perks)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_number_of_used_alien_perks() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::n3_msg_get_number_of_used_perks(), n3_engine_client_anarchy_t__n3_msg_get_number_of_used_perks)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_number_of_used_perks() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::n3_msg_get_over_equip_level(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_over_equip_level)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_number_of_used_perks() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(const char* engine_client_anarchy::n3_msg_get_pf_name(unsigned long), n3_engine_client_anarchy_t__n3_msg_get_pf_name_1)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_pf_name(unsigned long) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(const char* engine_client_anarchy::n3_msg_get_pf_name(), n3_engine_client_anarchy_t__n3_msg_get_pf_name_2)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_pf_name() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_get_parent(const identity_t &, identity_t &), n3_engine_client_anarchy_t__n3_msg_get_parent)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_parent(const identity_t &, identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_get_pos(const identity_t &, vector3_t &), n3_engine_client_anarchy_t__n3_msg_get_pos)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_pos(const identity_t &, vector3_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(LONG engine_client_anarchy::n3_msg_get_skill(unsigned long, unsigned long), n3_engine_client_anarchy_t__n3_msg_get_skill_1)
#else
	static_assert(false, " engine_client_anarchy::n3_msg_get_skill(unsigned long, unsigned long) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(LONG engine_client_anarchy::n3_msg_get_skill(const identity_t &, unsigned long, unsigned long, const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_skill_2)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_skill(const identity_t &, unsigned long, unsigned long, const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(LONG engine_client_anarchy::n3_msg_get_skill_max(unsigned long), n3_engine_client_anarchy_t__n3_msg_get_skill_max)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_skill_max(unsigned long) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(std::list<special_action_t>* engine_client_anarchy::n3_msg_get_special_action_list(), n3_engine_client_anarchy_t__n3_msg_get_special_action_list)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	std::list<special_action_t>* engine_client_anarchy::n3_msg_get_special_action_list()
	{
		if (GetGameState() == GAMESTATE_IN_GAME)
		{
			return n3_engine_client_anarchy_.p_client_control_char->p_special_action_holder->p_special_actions_list;
		}
		return nullptr;
	}
#endif	

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::n3_msg_get_special_action_state(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_special_action_state)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_special_action_state(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(const char* engine_client_anarchy::n3_msg_get_special_attack_weapon_name(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_special_attack_weapon_name)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_special_attack_weapon_name(const identity_t &) requires a native function.");
#endif

#if true
	FUNCTION_AT_ADDRESS(PVOID engine_client_anarchy::n3_msg_get_stat_name_map(), n3_engine_client_anarchy_t__n3_msg_get_stat_name_map)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_stat_name_map() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(p_identity_t engine_client_anarchy::N3Msg_GetTargetTarget(identity_t &, const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_target_target)
#else
	static_assert(false, "engine_client_anarchy::N3Msg_GetTargetTarget(identity_t &, const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(PVOID engine_client_anarchy::n3_msg_get_team_member_list(long), n3_engine_client_anarchy_t__n3_msg_get_team_member_list)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_team_member_list(LONG) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_has_perk(unsigned long), n3_engine_client_anarchy_t__n3_msg_has_perk)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_has_perk(unsigned long) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_hide_against_opponent(const ao::identity_t&), n3_engine_client_anarchy_t__n3_msg_hide_against_opponent)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_hide_against_opponent(const ao::identity_t&) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_attacking(), n3_engine_client_anarchy_t__n3_msg_is_attacking)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	bool engine_client_anarchy::n3_msg_is_attacking()
	{
		return n3_engine_client_anarchy_.p_client_control_char->p_weapon_holder->is_attacking == 1;
	}
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_battle_station(), n3_engine_client_anarchy_t__n3_msg_is_battle_station)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_is_battle_station() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_character_in_mech(identity_t), n3_engine_client_anarchy_t__n3_msg_is_character_in_mech)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_is_character_in_mech(identity_t) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_character_morphed(identity_t), n3_engine_client_anarchy_t__n3_msg_is_character_morphed)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_is_character_morphed(identity_t) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_dungeon(), n3_engine_client_anarchy_t__n3_msg_is_dungeon)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_is_dungeon() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_formula_ready(const identity_t &), n3_engine_client_anarchy_t__n3_msg_is_formula_ready)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_is_formula_ready(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_general_perk(unsigned long), n3_engine_client_anarchy_t__n3_msg_is_general_perk)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_is_general_perk(unsigned long) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_group_perk(unsigned long), n3_engine_client_anarchy_t__n3_msg_is_group_perk)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_is_group_perk(unsigned long) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_in_raid_team(), n3_engine_client_anarchy_t__n3_msg_is_in_raid_team);
#else
	static_assert(false, "engine_client_anarchy::N3Msg_IsInRaidTeam() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_in_team(const identity_t &), n3_engine_client_anarchy_t__n3_msg_is_in_team)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_is_in_team(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_item_disabled(const identity_t &, const identity_t &), n3_engine_client_anarchy_t__n3_msg_is_item_disabled)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_is_item_disabled(const identity_t &, const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_item_mine(const identity_t &), n3_engine_client_anarchy_t__n3_msg_is_item_mine)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_is_item_mine(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_item_nf_crystal(const identity_t &, const identity_t &), n3_engine_client_anarchy_t__n3_msg_is_item_nf_crystal)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_is_item_nf_crystal(const identity_t &, const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_item_possible_to_un_wear(const identity_t &), n3_engine_client_anarchy_t__n3_msg_is_item_possible_to_un_wear)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_is_item_possible_to_un_wear(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_item_possible_to_wear(const identity_t &, unsigned long, unsigned long, bool, unsigned long), n3_engine_client_anarchy_t__n3_msg_is_item_possible_to_wear)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_is_item_possible_to_wear(const identity_t &, unsigned long, unsigned long, bool, unsigned long) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_moving(), n3_engine_client_anarchy_t__n3_msg_is_moving);
#else
	static_assert(false, "engine_client_anarchy::n3_msg_is_moving() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_my_pet_id(const identity_t &), n3_engine_client_anarchy_t__n3_msg_is_my_pet_id)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_is_my_pet_id(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_nano_self_only(const identity_t &), n3_engine_client_anarchy_t__n3_msg_is_nano_self_only)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_is_nano_self_only(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_npc(const identity_t &), n3_engine_client_anarchy_t__n3_msg_is_npc)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_is_npc(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_perk(unsigned long), n3_engine_client_anarchy_t__n3_msg_is_perk)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_is_perk(unsigned long) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsPetTower(const identity_t &), n3_engine_client_anarchy_t__n3_msg_is_pet_tower)
#else
	static_assert(false, "engine_client_anarchy::N3Msg_IsPetTower(const identity_t &) requires a native function.");
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsProfessionPerk_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsProfessionPerk(unsigned long), n3EngineClientAnarchy_t__N3Msg_IsProfessionPerk);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsResearch_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsResearch(unsigned long), n3EngineClientAnarchy_t__N3Msg_IsResearch);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsSecondarySpecialAttackAvailable_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsSecondarySpecialAttackAvailable(unsigned long), n3EngineClientAnarchy_t__N3Msg_IsSecondarySpecialAttackAvailable);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsShieldDisablerItem_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsShieldDisablerItem(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsShieldDisablerItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsSpecialPerk_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsSpecialPerk(unsigned long), n3EngineClientAnarchy_t__N3Msg_IsSpecialPerk);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsTeamLeader_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsTeamLeader(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsTeamLeader);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsTeamMission_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsTeamMission(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsTeamMission);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsTeamMissionCopy_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsTeamMissionCopy(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsTeamMissionCopy);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsTeamNano_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsTeamNano(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsTeamNano);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsTower_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsTower(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsTower);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsVisible_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsVisible(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsVisible);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_JoinItems_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_JoinItems(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_JoinItems);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_KickTeamMember_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_KickTeamMember(const identity_t &), n3EngineClientAnarchy_t__N3Msg_KickTeamMember);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_LeaveBattle_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_LeaveBattle(void), n3EngineClientAnarchy_t__N3Msg_LeaveBattle);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_LeaveTeam_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_LeaveTeam(void), n3EngineClientAnarchy_t__N3Msg_LeaveTeam);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_MeetsPerkCriteria_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_MeetsPerkCriteria(unsigned long), n3EngineClientAnarchy_t__N3Msg_MeetsPerkCriteria);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_MoveItemToInventory_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_MoveItemToInventory(const identity_t &, unsigned long, unsigned long), n3EngineClientAnarchy_t__N3Msg_MoveItemToInventory);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_MoveRaidMember_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_MoveRaidMember(const identity_t &, unsigned long), n3EngineClientAnarchy_t__N3Msg_MoveRaidMember);
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_movement_changed(movement_action_e, float, float, bool), n3_engine_client_anarchy_t__n3_msg_movement_changed)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_movement_changed(movement_action_e, float, float bool) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_name_to_id(const std::string &, identity_t &), n3_engine_client_anarchy_t__n3_msg_name_to_id)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_name_to_id(const std::string &, identity_t &) requires a native function.");
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatAddTradeItem_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_NPCChatAddTradeItem(const identity_t &, const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_NPCChatAddTradeItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatCloseWindow_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_NPCChatCloseWindow(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_NPCChatCloseWindow);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatEndTrade_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_NPCChatEndTrade(const identity_t &, const identity_t &, unsigned long, bool), n3EngineClientAnarchy_t__N3Msg_NPCChatEndTrade);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatRemoveTradeItem_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_NPCChatRemoveTradeItem(const identity_t &, const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_NPCChatRemoveTradeItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatRequestDescription_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_NPCChatRequestDescription(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_NPCChatRequestDescription);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatStartTrade_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_NPCChatStartTrade(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_NPCChatStartTrade);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_OrbitalAttack_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_OrbitalAttack(const identity_t &), n3EngineClientAnarchy_t__N3Msg_OrbitalAttack);
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_PERFORM_SPECIAL_ACTION_1_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_perform_special_action(unsigned long), n3_engine_client_anarchy_t__n3_msg_perform_special_action_1)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_perform_special_action(unsigned long) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_PERFORM_SPECIAL_ACTION_2_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_perform_special_action(const identity_t &), n3_engine_client_anarchy_t__n3_msg_perform_special_action_2)
#else
	static_assert(false, "n3_msg_perform_special_action(const identity_t &) requires a native function.");
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_PetDuel_Accept_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_PetDuel_Accept(void), n3EngineClientAnarchy_t__N3Msg_PetDuel_Accept);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_PetDuel_Challenge_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_PetDuel_Challenge(const identity_t &), n3EngineClientAnarchy_t__N3Msg_PetDuel_Challenge);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_PetDuel_Refuse_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_PetDuel_Refuse(void), n3EngineClientAnarchy_t__N3Msg_PetDuel_Refuse);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_PetDuel_Stop_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_PetDuel_Stop(void), n3EngineClientAnarchy_t__N3Msg_PetDuel_Stop);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_RemoveBuff_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_RemoveBuff(const identity_t &), n3EngineClientAnarchy_t__N3Msg_RemoveBuff);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_RemoveQuest_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_RemoveQuest(const identity_t &), n3EngineClientAnarchy_t__N3Msg_RemoveQuest);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_RequestCharacterInventory_x
	FUNCTION_AT_ADDRESS(std::list<inventory_entry_t>* engine_client_anarchy::N3Msg_RequestCharacterInventory(void), n3EngineClientAnarchy_t__N3Msg_RequestCharacterInventory);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_RequestClothInventory_x
	FUNCTION_AT_ADDRESS(std::list<inventory_entry_t>* engine_client_anarchy::N3Msg_RequestClothInventory(const identity_t &), n3EngineClientAnarchy_t__N3Msg_RequestClothInventory);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_RequestImplantInventory_x
	FUNCTION_AT_ADDRESS(std::list<inventory_entry_t>* engine_client_anarchy::N3Msg_RequestImplantInventory(const identity_t &), n3EngineClientAnarchy_t__N3Msg_RequestImplantInventory);
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_request_info_packet(const identity_t&), n3_engine_client_anarchy_t__n3_msg_request_info_packet)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_request_info_packet(const identity_t&) requires a native function.");
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_RequestSocialInventory_x
	FUNCTION_AT_ADDRESS(std::list<inventory_entry_t>* engine_client_anarchy::N3Msg_RequestSocialInventory(const identity_t &), n3EngineClientAnarchy_t__N3Msg_RequestSocialInventory);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_RequestWeaponInventory_x
	FUNCTION_AT_ADDRESS(std::list<inventory_entry_t>* engine_client_anarchy::N3Msg_RequestWeaponInventory(const identity_t &), n3EngineClientAnarchy_t__N3Msg_RequestWeaponInventory);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_SecondarySpecialAttack_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_SecondarySpecialAttack(const identity_t &, unsigned long), n3EngineClientAnarchy_t__N3Msg_SecondarySpecialAttack);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_SelectedTarget_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_SelectedTarget(const identity_t&), n3EngineClientAnarchy_t__N3Msg_SelectedTarget);
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_SEND_PET_COMMAND_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_send_pet_command(unsigned long, const identity_t &, unsigned long, unsigned long, const char*), n3_engine_client_anarchy_t__n3_msg_send_pet_command)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_send_pet_command(unsigned long, const identity_t &, unsigned long, unsigned long, const char*) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_sit_toggle(), n3_engine_client_anarchy_t__n3_msg_sit_toggle)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_sit_toggle() requires a native function.");
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_SplitItem_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_SplitItem(const identity_t &, unsigned long), n3EngineClientAnarchy_t__N3Msg_SplitItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_StartAltState_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_StartAltState(void), n3EngineClientAnarchy_t__N3Msg_StartAltState);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_StartCamping_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_StartCamping(void), n3EngineClientAnarchy_t__N3Msg_StartCamping);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_StartPvP_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_StartPvP(const identity_t &), n3EngineClientAnarchy_t__N3Msg_StartPvP);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_StartTreatment_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_StartTreatment(const identity_t &), n3EngineClientAnarchy_t__N3Msg_StartTreatment);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_StopAltState_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_StopAltState(void), n3EngineClientAnarchy_t__N3Msg_StopAltState);
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_STOP_ATTACK_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_stop_attack(), n3_engine_client_anarchy_t__n3_msg_stop_attack)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_stop_attack() requires a native function.");
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_StopCamping_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_StopCamping(void), n3EngineClientAnarchy_t__N3Msg_StopCamping);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_StringToStat_x
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::N3Msg_StringToStat(const char*), n3EngineClientAnarchy_t__N3Msg_StringToStat);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_SwitchTarget_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_SwitchTarget(const identity_t &), n3EngineClientAnarchy_t__N3Msg_SwitchTarget);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TeamJoinRequest_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_TeamJoinRequest(const identity_t &, bool), n3EngineClientAnarchy_t__N3Msg_TeamJoinRequest);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TemplateIDToDynelID_x
	FUNCTION_AT_ADDRESS(p_identity_t engine_client_anarchy::N3Msg_TemplateIDToDynelID(identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_TemplateIDToDynelID);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TextCommand_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_TextCommand(unsigned long, const char*, const identity_t &), n3EngineClientAnarchy_t__N3Msg_TextCommand);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_ToggleReclaim_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_ToggleReclaim(bool), n3EngineClientAnarchy_t__N3Msg_ToggleReclaim);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeAbort_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_TradeAbort(bool), n3EngineClientAnarchy_t__N3Msg_TradeAbort);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeAccept_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_TradeAccept(void), n3EngineClientAnarchy_t__N3Msg_TradeAccept);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeAddItem_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_TradeAddItem(const identity_t &, const identity_t &, unsigned long), n3EngineClientAnarchy_t__N3Msg_TradeAddItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeConfirm_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_TradeConfirm(void), n3EngineClientAnarchy_t__N3Msg_TradeConfirm);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeGetInventory_x
	FUNCTION_AT_ADDRESS(PVOID engine_client_anarchy::N3Msg_TradeGetInventory(const identity_t &), n3EngineClientAnarchy_t__N3Msg_TradeGetInventory);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeGetInventoryCost_x
	FUNCTION_AT_ADDRESS(unsigned long engine_client_anarchy::N3Msg_TradeGetInventoryCost(const identity_t &), n3EngineClientAnarchy_t__N3Msg_TradeGetInventoryCost);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeRemoveItem_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_TradeRemoveItem(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_TradeRemoveItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeSetCash_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_TradeSetCash(unsigned long), n3EngineClientAnarchy_t__N3Msg_TradeSetCash);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeStart_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_TradeStart(const identity_t &), n3EngineClientAnarchy_t__N3Msg_TradeStart);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeskillCombine_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_TradeskillCombine(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_TradeskillCombine);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TrainPerk_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_TrainPerk(unsigned long), n3EngineClientAnarchy_t__N3Msg_TrainPerk);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TransferTeamLeadership_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_TransferTeamLeadership(const identity_t &), n3EngineClientAnarchy_t__N3Msg_TransferTeamLeadership);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TryAbortNanoFormula_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_TryAbortNanoFormula(void), n3EngineClientAnarchy_t__N3Msg_TryAbortNanoFormula);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TryEnterSneakMode_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_TryEnterSneakMode(void), n3EngineClientAnarchy_t__N3Msg_TryEnterSneakMode);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_UntrainPerk_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_UntrainPerk(unsigned long), n3EngineClientAnarchy_t__N3Msg_UntrainPerk);
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_USE_ITEM_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_use_item(const identity_t&, bool), n3_engine_client_anarchy_t__n3_msg_use_item)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_use_item(const identity_t&, bool) requires a native function.");
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_UseItemOnItem_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_UseItemOnItem(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_UseItemOnItem);
#endif

#if true
	FUNCTION_AT_ADDRESS(const char* engine_client_anarchy::stat_to_string(ao::stat_e stat_id), f_stat_to_string)
#else
	// ReSharper disable once CppParameterMayBeConst
	const char* engine_client_anarchy::stat_to_string(ao::stat_e stat_id)
	{
		auto result = "NoName";
		std::map<ao::stat_e, const char*> m;
		P_STAT_NAME_MAP->copy_map(m);
		if (m.count(stat_id))
			result = m.find(stat_id)->second;
		return result;
	}
#endif

}
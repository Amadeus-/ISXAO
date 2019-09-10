#include "isxao_main.h"

namespace isxao_classes
{
#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_BREED_STR_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(PCSTR engine_client_anarchy::get_breed_str(breed_e), n3_engine_client_anarchy_t__get_breed_str)
#else
	// ReSharper disable once CppParameterMayBeConst
	PCSTR engine_client_anarchy::get_breed_str(breed_e breed_id)
	{
		return get_breed_str_local(breed_id);
	}
#endif


#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_CLIENT_CHAR_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(character* engine_client_anarchy::get_client_char(), n3_engine_client_anarchy_t__get_client_char)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	character* engine_client_anarchy::get_client_char(void)
	{
		return reinterpret_cast<character*>(n3_engine_client_anarchy_.p_client_control_char);
	}
#endif	

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_CLIENT_DYNEL_ID_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(p_identity_t engine_client_anarchy::get_client_dynel_id(identity_t &), n3_engine_client_anarchy_t__get_client_dynel_id)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	p_identity_t engine_client_anarchy::get_client_dynel_id(identity_t& id)
	{
		id.type = 50000;
		id.id = n3_engine_client_anarchy_.client_inst_id;
		return &id;
	}
#endif	

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_CURRENT_MOVEMENT_MODE_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD engine_client_anarchy::get_current_movement_mode(), n3_engine_client_anarchy_t__get_current_movement_mode)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	DWORD engine_client_anarchy::get_current_movement_mode()
	{
		return n3_engine_client_anarchy_.p_client_control_char->p_vehicle->p_char_movement_status->movement_mode;
	}
#endif

	n3_engine_client_anarchy_t engine_client_anarchy::get_engine_client_anarchy_data() const
	{
		return n3_engine_client_anarchy_;
	}

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_FACTION_STR_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(PCSTR engine_client_anarchy::get_faction_str(DWORD, bool), n3_engine_client_anarchy_t__get_faction_str)
#else
	static_assert(false, "engine_client_anarchy::get_faction_str(DWORD, bool) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_FACTION_TITLE_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(PCSTR engine_client_anarchy::get_faction_title(DWORD), n3_engine_client_anarchy_t__get_faction_title)
#else
	static_assert(false, "engine_client_anarchy::get_faction_title(DWORD) requires a native function.");
#endif


#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_GENDER_STRING_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(PCSTR engine_client_anarchy::get_gender_string(identity_t const &), n3_engine_client_anarchy_t__get_gender_string)
#else
	static_assert(false, "engine_client_anarchy::get_gender_string(const identity_t&) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_ITEM_BY_TEMPLATE_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(p_dummy_item_base_t engine_client_anarchy::get_item_by_template(identity_t, identity_t const &), n3_engine_client_anarchy_t__get_item_by_template)
#else
	static_assert(false, "engine_client_anarchy::get_item_by_template(identity_t, identity_t const &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_SEX_STR_USE_NATIVE
	FUNCTION_AT_ADDRESS(PCSTR engine_client_anarchy::get_sex_str(gender_e), n3_engine_client_anarchy_t__get_sex_str)
#else
	// ReSharper disable once CppParameterMayBeConst
	PCSTR engine_client_anarchy::get_sex_str(gender_e gender_id)
	{
		return get_sex_str_local(gender_id);
	}
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_TITLE_STR_USE_NATIVE
	FUNCTION_AT_ADDRESS(PCSTR engine_client_anarchy::get_title_string(DWORD, DWORD), n3_engine_client_anarchy_t__get_title_str)
#else
	static_assert(false, "engine_client_anarchy::get_title_string(DWORD, DWORD) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__IS_FIRST_LOGIN_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::is_first_login(), n3_engine_client_anarchy_t__is_first_login)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	bool engine_client_anarchy::is_first_login(void)
	{
		return n3_engine_client_anarchy_.is_first_login == 1;
	}
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__IS_FIXTURE_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::is_fixture(const identity_t &, const identity_t &), n3_engine_client_anarchy_t__is_fixture)
#else
	static_assert(false, "engine_client_anarchy::is_fixture(const identity_t &, const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_ACTIVATE_MECH_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_activate_mech(DWORD), n3_engine_client_anarchy_t__n3_msg_activate_mech);
#else
	static_assert(false, "engine_client_anarchy::n3_msg_activate_mech(DWORD) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_AIRSTRIKE_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_airstrike(const identity_t &), n3_engine_client_anarchy_t__n3_msg_airstrike)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_airstrike(const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_ARTILLERY_ATTACK_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_artillery_attack(const identity_t &), n3_engine_client_anarchy_t__n3_msg_artillery_attack)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_artillery_attack(const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_ASSIST_FIGHT_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_assist_fight(const identity_t &), n3_engine_client_anarchy_t__n3_msg_assist_fight)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_artillery_attack(const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CAN_ATTACK_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_can_attack(const identity_t &), n3_engine_client_anarchy_t__n3_msg_can_attack)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_can_attack(const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CAN_CLICK_TARGET_TARGET_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_can_click_target_target(const identity_t &, const identity_t &), n3_engine_client_anarchy_t__n3_msg_can_click_target_target)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_can_click_target_target(const identity_t &, const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CAN_USE_MECH_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_can_use_mech(), n3_engine_client_anarchy_t__n3_msg_can_use_mech)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_can_use_mech(void) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CAST_NANO_SPELL_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_cast_nano_spell(const identity_t &, const identity_t &), n3_engine_client_anarchy_t__n3_msg_cast_nano_spell)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_cast_nano_spell(const identity_t &, const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CONSIDER_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD engine_client_anarchy::n3_msg_consider(const identity_t &, float &), n3_engine_client_anarchy_t__n3_msg_consider)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_consider(const identity_t &, float &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CONTAINER_ADD_ITEM_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_container_add_item(const identity_t &, const identity_t &), n3_engine_client_anarchy_t__n3_msg_container_add_item)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_container_add_item(const identity_t &, const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CRAWL_TOGGLE_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_crawl_toggle(), n3_engine_client_anarchy_t__n3_msg_crawl_toggle)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_crawl_toggle(void) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CREATE_RAID_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_create_raid(), n3_engine_client_anarchy_t__n3_msg_create_raid)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_create_raid(void) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DEFAULT_ACTION_ON_DYNEL_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_default_action_on_dynel(const identity_t &), n3_engine_client_anarchy_t__n3_msg_default_action_on_dynel)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_default_action_on_dynel(const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DEFAULT_ATTACK_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_default_attack(const identity_t &, bool), n3_engine_client_anarchy_t__n3_msg_default_attack)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_default_attack(const identity_t &, bool) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DELETE_ITEM_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_delete_item(const identity_t&, const identity_t&), n3_engine_client_anarchy_t__n3_msg_delete_item)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_delete_item(const identity_t&, const identity_t&) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DELETE_NANO_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_delete_nano(const identity_t &), n3_engine_client_anarchy_t__n3_msg_delete_nano)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_delete_nano(const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DO_SOCIAL_ACTION_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD engine_client_anarchy::n3_msg_do_social_action(social_action_e), n3_engine_client_anarchy_t__n3_msg_do_social_action)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_do_social_action(social_action_e) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DROP_ITEM_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_drop_item(const identity_t &, const vector3_t &), n3_engine_client_anarchy_t__n3_msg_drop_item)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_drop_item(const identity_t &, const vector3_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_ACCEPT_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_duel_accept(), n3_engine_client_anarchy_t__n3_msg_duel_accept)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_duel_accept() requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_CHALLENGE_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_duel_challenge(const identity_t &), n3_engine_client_anarchy_t__n3_msg_duel_challenge)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_duel_challenge(const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_DRAW_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_duel_draw(), n3_engine_client_anarchy_t__n3_msg_duel_draw)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_duel_draw() requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_REFUSE_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_duel_refuse(), n3_engine_client_anarchy_t__n3_msg_duel_refuse);
#else
	static_assert(false, "engine_client_anarchy::n3_msg_duel_refuse() requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_STOP_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_duel_stop(), n3_engine_client_anarchy_t__n3_msg_duel_stop)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_duel_stop() requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_FORAGE_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_forage(), n3_engine_client_anarchy_t__n3_msg_forage)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_forage() requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ACTION_BY_NAME_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD engine_client_anarchy::n3_msg_get_action_by_name(PCSTR), n3_engine_client_anarchy_t__n3_msg_get_action_by_name)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_action_by_name(PCSTR) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ACTION_PROGRESS_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(float engine_client_anarchy::n3_msg_get_action_progress(const identity_t &, DWORD*, DWORD*), n3_engine_client_anarchy_t__n3_msg_get_action_progress)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_action_progress(const identity_t &, DWORD*, DWORD*) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_AGG_DEF_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(LONG engine_client_anarchy::n3_msg_get_agg_def(), n3_engine_client_anarchy_t__n3_msg_get_agg_def)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_agg_def() requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ALIEN_LEVEL_STRING_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(PCSTR engine_client_anarchy::n3_msg_get_alien_level_string(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_alien_level_string)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_alien_level_string(const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_AREA_NAME_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_get_area_name(PCSTR*), n3_engine_client_anarchy_t__n3_msg_get_area_name)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_area_name(PCSTR*) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ATTACKING_ID_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_get_attacking_id(identity_t &), n3_engine_client_anarchy_t__n3_msg_get_attacking_id)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	bool engine_client_anarchy::n3_msg_get_attacking_id(identity_t& id)
	{
		if (GetGameState() == GAMESTATE_IN_GAME && n3_engine_client_anarchy_.p_client_control_char->p_weapon_holder->is_attacking == 1)
		{
			id = n3_engine_client_anarchy_.p_client_control_char->p_weapon_holder->weapon_target_identity;
			return true;
		}
		return false;
	}
#endif	

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_BREED_STR_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(PCSTR engine_client_anarchy::n3_msg_get_breed_str(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_breed_str)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_breed_str(const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_BUFF_CURRENT_TIME_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD engine_client_anarchy::n3_msg_get_buff_current_time(const identity_t &, const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_buff_current_time)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_buff_current_time(const identity_t &, const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_BUFF_TOTAL_TIME_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD engine_client_anarchy::n3_msg_get_buff_total_time(const identity_t &, const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_buff_total_time)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_buff_total_time(const identity_t &, const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CHARACTER_BODY_SHAPE_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_get_character_body_shape(BYTE &, identity_t), n3_engine_client_anarchy_t__n3_msg_get_character_body_shape)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_character_body_shape(BYTE &, identity_t) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CHAR_ORIENTATION_DATA_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_get_char_orientation_data(const identity_t &, vector3_t &, quaternion_t &, float &), n3_engine_client_anarchy_t__n3_msg_get_char_orientation_data)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_char_orientation_data(const identity_t &, vector3_t &, quaternion_t &, float &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CITY_NAME_FOR_CLAN_MEMBER_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(PCSTR engine_client_anarchy::n3_msg_get_city_name_for_clan_member(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_city_name_for_clan_member)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_city_name_for_clan_member(const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CLAN_LEVEL_STRING_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(PCSTR engine_client_anarchy::n3_msg_get_clan_level_string(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_clan_level_string)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_clan_level_string(const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CLAN_STRING_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(string* engine_client_anarchy::n3_msg_get_clan_string(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_clan_string)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_clan_string(const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CLIENT_PET_ID_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(p_identity_t engine_client_anarchy::n3_msg_get_client_pet_id(identity_t &, DWORD), n3_engine_client_anarchy_t__n3_msg_get_client_pet_id)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_client_pet_id(identity_t &, DWORD) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CLOSE_TARGET_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_get_close_target(identity_t &, bool, bool), n3_engine_client_anarchy_t__n3_msg_get_close_target)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_close_target(identity_t &, bool, bool) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CONTAINER_INVENTORY_LIST_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(p_inventory_holder_t engine_client_anarchy::n3_msg_get_container_inventory_list(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_container_inventory_list)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_container_inventory_list(const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CORRECT_ACTION_ID_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_get_correct_action_id(identity_t &), n3_engine_client_anarchy_t__n3_msg_get_correct_action_id)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_correct_action_id(identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CURRENT_ROOM_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(LONG engine_client_anarchy::n3_msg_get_current_room(), n3_engine_client_anarchy_t__n3_msg_get_current_room)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_current_room() requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CURRENT_ROOM_NAME_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(PCSTR engine_client_anarchy::n3_msg_get_current_room_name(), n3_engine_client_anarchy_t__n3_msg_get_current_room_name)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_current_room_name() requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_DISTRICT_FIGHT_MODE_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD engine_client_anarchy::n3_msg_get_district_fight_mode(), n3_engine_client_anarchy_t__n3_msg_get_district_fight_mode)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_district_fight_mode() requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_DYNELS_IN_VICINITY_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_get_dynels_in_vicinity(vector<identity_t>&, bool, bool, type_id_e), n3_engine_client_anarchy_t__n3_msg_get_dynels_in_vicinity)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_dynels_in_vicinity(vector<identity_t>&, bool, bool, type_id_e) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FACTION_INFO_STRING_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_get_faction_info_string(const identity_t &, string &), n3_engine_client_anarchy_t__n3_msg_get_faction_info_string)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_faction_info_string(const identity_t &, string &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FACTION_RANGE_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_get_faction_range(DWORD, DWORD &, DWORD &), n3_engine_client_anarchy_t__n3_msg_get_faction_range)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_faction_range(DWORD, DWORD &, DWORD &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FIRST_NAME_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(PCSTR engine_client_anarchy::n3_msg_get_first_name(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_first_name)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_first_name(const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FORMULA_PROGRESS_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(double engine_client_anarchy::n3_msg_get_formula_progress(const identity_t &, DWORD &, DWORD &), n3_engine_client_anarchy_t__n3_msg_get_formula_progress)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_formula_progress(const identity_t &, DWORD &, DWORD &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FORMULA_RADIUS_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD engine_client_anarchy::n3_msg_get_formula_radius(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_formula_radius)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_formula_radius(const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_GLOBAL_CHARACTER_POSITION_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_get_global_character_position(vector3_t &), n3_engine_client_anarchy_t__n3_msg_get_global_character_position)
#else
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	void engine_client_anarchy::n3_msg_get_global_character_position(vector3_t& pos)
	{
		if (GetGameState() == GAMESTATE_IN_GAME)
		{
			const auto client_pos = P_ENGINE_CLIENT_ANARCHY->get_client_char()->GetPosition();
			pos.copy(client_pos);
		}
	}
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_GLOBAL_CHARACTER_ROTATION_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_get_global_character_rotation(quaternion_t &), n3_engine_client_anarchy_t__n3_msg_get_global_character_rotation)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	// ReSharper disable once CppMemberFunctionMayBeStatic
	void engine_client_anarchy::n3_msg_get_global_character_rotation(quaternion_t& rot)
	{
		if (GetGameState() == GAMESTATE_IN_GAME)
		{
			const auto client_rot = P_ENGINE_CLIENT_ANARCHY->get_client_char()->GetRotation();
			rot.copy(client_rot);
		}
	}

#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_GRID_DESTINATION_1_LIST_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(PVOID engine_client_anarchy::n3_msg_get_grid_destination_list(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_1)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_grid_destination_list(const identity_t &) requires a native function.");
#endif

#ifdef  N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_GRID_DESTINATION_2_LIST_USE_NATIVE
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

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_INVENTORY_VEC_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(std::vector<p_inventory_data_t>* engine_client_anarchy::n3_msg_get_inventory_vec(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_inventory_vec)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_inventory_vec(const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ITEM_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::n3_msg_get_item(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_item)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_item(const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ITEM_PROGRESS_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(double engine_client_anarchy::n3_msg_get_item_progress(const identity_t &, DWORD &, DWORD &), n3_engine_client_anarchy_t__n3_msg_get_item_progress)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_item_progress(const identity_t &, DWORD &, DWORD &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_MOVEMENT_MODE_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD engine_client_anarchy::n3_msg_get_movement_mode(), n3_engine_client_anarchy_t__n3_msg_get_movement_mode)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_movement_mode() requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NAME_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(PCSTR engine_client_anarchy::n3_msg_get_name(const identity_t &, const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_name)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_name(const identity_t &, const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NANO_COST_MODIFIER_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD engine_client_anarchy::n3_msg_get_nano_cost_modifier(), n3_engine_client_anarchy_t__n3_msg_get_nano_cost_modifier)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_nano_cost_modifier() requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NANO_SPELL_LIST_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(list<DWORD>* engine_client_anarchy::n3_msg_get_nano_spell_list(), n3_engine_client_anarchy_t__n3_msg_get_nano_spell_list)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	list<DWORD>* engine_client_anarchy::n3_msg_get_nano_spell_list()
	{
		if (GetGameState() == GAMESTATE_IN_GAME)
		{
			return &n3_engine_client_anarchy_.p_client_control_char->p_spell_template_data->spell_list;
		}
		return nullptr;
	}
#endif	

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NANO_TEMPLATE_INFO_LIST_1_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(list<nano_template>* engine_client_anarchy::n3_msg_get_nano_template_info_list(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_1)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_nano_template_info_list(const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NANO_TEMPLATE_INFO_LIST_2_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(list<nano_template>* engine_client_anarchy::n3_msg_get_nano_template_info_list(), n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_2);
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	list<nano_template>* engine_client_anarchy::n3_msg_get_nano_template_info_list()
	{
		if (GetGameState() == GAMESTATE_IN_GAME)
		{
			return &n3_engine_client_anarchy_.p_client_control_char->p_spell_template_data->nano_template_list;
		}
		return nullptr;
	}
#endif	

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NEXT_TARGET_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(p_identity_t engine_client_anarchy::n3_msg_get_next_target(identity_t &, DWORD), n3_engine_client_anarchy_t__n3_msg_get_next_target)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_next_target(identity_t &, DWORD) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_AVAILABLE_ALIEN_PERKS_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD engine_client_anarchy::n3_msg_get_number_of_available_alien_perks(), n3_engine_client_anarchy_t__n3_msg_get_number_of_available_alien_perks)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_number_of_available_alien_perks() requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_AVAILABLE_PERKS_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD engine_client_anarchy::n3_msg_get_number_of_available_perks(), n3_engine_client_anarchy_t__n3_msg_get_number_of_available_perks)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_number_of_available_perks() requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_FREE_INVENTORY_SLOTS_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD engine_client_anarchy::n3_msg_get_number_of_free_inventory_slots(), n3_engine_client_anarchy_t__n3_msg_get_number_of_free_inventory_slots)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_number_of_free_inventory_slots() requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_USED_ALIEN_PERKS_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD engine_client_anarchy::n3_msg_get_number_of_used_alien_perks(), n3_engine_client_anarchy_t__n3_msg_get_number_of_used_alien_perks)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_number_of_used_alien_perks() requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_USED_PERKS_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD engine_client_anarchy::n3_msg_get_number_of_used_perks(), n3_engine_client_anarchy_t__n3_msg_get_number_of_used_perks)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_number_of_used_perks() requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_OVER_EQUIP_LEVEL_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD engine_client_anarchy::n3_msg_get_over_equip_level(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_over_equip_level)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_number_of_used_perks() requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_PLAYFIELD_NAME_1_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(PCSTR engine_client_anarchy::n3_msg_get_pf_name(DWORD), n3_engine_client_anarchy_t__n3_msg_get_pf_name_1)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_pf_name(DWORD) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_PLAYFIELD_NAME_2_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(PCSTR engine_client_anarchy::n3_msg_get_pf_name(), n3_engine_client_anarchy_t__n3_msg_get_pf_name_2)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_pf_name() requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_PARENT_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_get_parent(const identity_t &, identity_t &), n3_engine_client_anarchy_t__n3_msg_get_parent)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_parent(const identity_t &, identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_POS_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_get_pos(const identity_t &, vector3_t &), n3_engine_client_anarchy_t__n3_msg_get_pos)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_pos(const identity_t &, vector3_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SKILL_1_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(LONG engine_client_anarchy::n3_msg_get_skill(DWORD, DWORD), n3_engine_client_anarchy_t__n3_msg_get_skill_1)
#else
	static_assert(false, " engine_client_anarchy::n3_msg_get_skill(DWORD, DWORD) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SKILL_2_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(LONG engine_client_anarchy::n3_msg_get_skill(const identity_t &, DWORD, DWORD, const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_skill_2)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_skill(const identity_t &, DWORD, DWORD, const identity_t &) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SKILL_MAX_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(LONG engine_client_anarchy::n3_msg_get_skill_max(DWORD), n3_engine_client_anarchy_t__n3_msg_get_skill_max)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_skill_max(DWORD) requires a native function.");
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SPECIAL_ACTION_LIST_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(list<special_action_t>* engine_client_anarchy::n3_msg_get_special_action_list(), n3_engine_client_anarchy_t__n3_msg_get_special_action_list)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	list<special_action_t>* engine_client_anarchy::n3_msg_get_special_action_list()
	{
		if (GetGameState() == GAMESTATE_IN_GAME)
		{
			return n3_engine_client_anarchy_.p_client_control_char->p_special_action_holder->p_special_actions_list;
		}
		return nullptr;
	}
#endif	

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SPECIAL_ACTION_STATE_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(DWORD engine_client_anarchy::n3_msg_get_special_action_state(const identity_t &), n3_engine_client_anarchy_t__n3_msg_get_special_action_state)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_get_special_action_state(const identity_t &) requires a native function.");
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetSpecialAttackWeaponName_x
	FUNCTION_AT_ADDRESS(PCSTR engine_client_anarchy::N3Msg_GetSpecialAttackWeaponName(const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetSpecialAttackWeaponName);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetTargetTarget_x
	FUNCTION_AT_ADDRESS(p_identity_t engine_client_anarchy::N3Msg_GetTargetTarget(identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetTargetTarget);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetTeamMemberList_x
	FUNCTION_AT_ADDRESS(PVOID engine_client_anarchy::N3Msg_GetTeamMemberList(LONG), n3EngineClientAnarchy_t__N3Msg_GetTeamMemberList);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_HasPerk_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_HasPerk(DWORD), n3EngineClientAnarchy_t__N3Msg_HasPerk);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsAttacking_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsAttacking(void), n3EngineClientAnarchy_t__N3Msg_IsAttacking);
#endif

	bool engine_client_anarchy::N3Msg_IsAttacking(void) const
	{
		return n3_engine_client_anarchy_.p_client_control_char->p_weapon_holder->is_attacking == 1;
	}

#ifdef n3EngineClientAnarchy_t__N3Msg_IsBattleStation_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsBattleStation(void), n3EngineClientAnarchy_t__N3Msg_IsBattleStation);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsCharacterInMech_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsCharacterInMech(identity_t), n3EngineClientAnarchy_t__N3Msg_IsCharacterInMech);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsCharacterMorphed_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsCharacterMorphed(identity_t), n3EngineClientAnarchy_t__N3Msg_IsCharacterMorphed);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsDungeon_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsDungeon(void), n3EngineClientAnarchy_t__N3Msg_IsDungeon);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsFormulaReady_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsFormulaReady(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsFormulaReady);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsGeneralPerk_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsGeneralPerk(DWORD), n3EngineClientAnarchy_t__N3Msg_IsGeneralPerk);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsGroupPerk_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsGroupPerk(DWORD), n3EngineClientAnarchy_t__N3Msg_IsGroupPerk);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsInRaidTeam_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsInRaidTeam(void), n3EngineClientAnarchy_t__N3Msg_IsInRaidTeam);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsInTeam_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsInTeam(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsInTeam);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsItemDisabled_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsItemDisabled(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsItemDisabled);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsItemMine_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsItemMine(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsItemMine);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsItemNFCrystal_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsItemNFCrystal(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsItemNFCrystal);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToUnWear_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsItemPossibleToUnWear(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToUnWear);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToWear_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsItemPossibleToWear(const identity_t &, DWORD, DWORD, bool, DWORD), n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToWear);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsMoving_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsMoving(void), n3EngineClientAnarchy_t__N3Msg_IsMoving);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsMyPetID_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsMyPetID(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsMyPetID);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsNanoSelfOnly_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsNanoSelfOnly(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsNanoSelfOnly);
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_IS_NPC_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::n3_msg_is_npc(const identity_t &), n3_engine_client_anarchy_t__n3_msg_is_npc)
#else
	static_assert(false, "engine_client_anarchy::n3_msg_is_npc(const identity_t &) requires a native function.");
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsPerk_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsPerk(DWORD), n3EngineClientAnarchy_t__N3Msg_IsPerk);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsPetTower_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsPetTower(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsPetTower);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsProfessionPerk_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsProfessionPerk(DWORD), n3EngineClientAnarchy_t__N3Msg_IsProfessionPerk);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsResearch_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsResearch(DWORD), n3EngineClientAnarchy_t__N3Msg_IsResearch);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsSecondarySpecialAttackAvailable_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsSecondarySpecialAttackAvailable(DWORD), n3EngineClientAnarchy_t__N3Msg_IsSecondarySpecialAttackAvailable);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsShieldDisablerItem_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsShieldDisablerItem(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsShieldDisablerItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsSpecialPerk_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_IsSpecialPerk(DWORD), n3EngineClientAnarchy_t__N3Msg_IsSpecialPerk);
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
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_MeetsPerkCriteria(DWORD), n3EngineClientAnarchy_t__N3Msg_MeetsPerkCriteria);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_MoveItemToInventory_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_MoveItemToInventory(const identity_t &, DWORD, DWORD), n3EngineClientAnarchy_t__N3Msg_MoveItemToInventory);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_MoveRaidMember_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_MoveRaidMember(const identity_t &, DWORD), n3EngineClientAnarchy_t__N3Msg_MoveRaidMember);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_NameToID_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_NameToID(const std::string &, identity_t &), n3EngineClientAnarchy_t__N3Msg_NameToID);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatAddTradeItem_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_NPCChatAddTradeItem(const identity_t &, const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_NPCChatAddTradeItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatCloseWindow_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_NPCChatCloseWindow(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_NPCChatCloseWindow);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatEndTrade_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_NPCChatEndTrade(const identity_t &, const identity_t &, DWORD, bool), n3EngineClientAnarchy_t__N3Msg_NPCChatEndTrade);
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

#ifdef n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_1_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_PerformSpecialAction(DWORD), n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_1);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_2_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_PerformSpecialAction(const identity_t &), n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_2);
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

#ifdef n3EngineClientAnarchy_t__N3Msg_RequestSocialInventory_x
	FUNCTION_AT_ADDRESS(std::list<inventory_entry_t>* engine_client_anarchy::N3Msg_RequestSocialInventory(const identity_t &), n3EngineClientAnarchy_t__N3Msg_RequestSocialInventory);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_RequestWeaponInventory_x
	FUNCTION_AT_ADDRESS(std::list<inventory_entry_t>* engine_client_anarchy::N3Msg_RequestWeaponInventory(const identity_t &), n3EngineClientAnarchy_t__N3Msg_RequestWeaponInventory);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_SecondarySpecialAttack_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_SecondarySpecialAttack(const identity_t &, DWORD), n3EngineClientAnarchy_t__N3Msg_SecondarySpecialAttack);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_SelectedTarget_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_SelectedTarget(const identity_t&), n3EngineClientAnarchy_t__N3Msg_SelectedTarget);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_SendPetCommand_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_SendPetCommand(DWORD, const identity_t &, DWORD, DWORD, PCSTR), n3EngineClientAnarchy_t__N3Msg_SendPetCommand);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_SitToggle_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_SitToggle(void), n3EngineClientAnarchy_t__N3Msg_SitToggle);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_SplitItem_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_SplitItem(const identity_t &, DWORD), n3EngineClientAnarchy_t__N3Msg_SplitItem);
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

#ifdef n3EngineClientAnarchy_t__N3Msg_StopAttack_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_StopAttack(void), n3EngineClientAnarchy_t__N3Msg_StopAttack);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_StopCamping_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_StopCamping(void), n3EngineClientAnarchy_t__N3Msg_StopCamping);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_StringToStat_x
	FUNCTION_AT_ADDRESS(DWORD engine_client_anarchy::N3Msg_StringToStat(PCSTR), n3EngineClientAnarchy_t__N3Msg_StringToStat);
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
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_TextCommand(DWORD, PCSTR, const identity_t &), n3EngineClientAnarchy_t__N3Msg_TextCommand);
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
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_TradeAddItem(const identity_t &, const identity_t &, DWORD), n3EngineClientAnarchy_t__N3Msg_TradeAddItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeConfirm_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_TradeConfirm(void), n3EngineClientAnarchy_t__N3Msg_TradeConfirm);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeGetInventory_x
	FUNCTION_AT_ADDRESS(PVOID engine_client_anarchy::N3Msg_TradeGetInventory(const identity_t &), n3EngineClientAnarchy_t__N3Msg_TradeGetInventory);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeGetInventoryCost_x
	FUNCTION_AT_ADDRESS(DWORD engine_client_anarchy::N3Msg_TradeGetInventoryCost(const identity_t &), n3EngineClientAnarchy_t__N3Msg_TradeGetInventoryCost);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeRemoveItem_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_TradeRemoveItem(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_TradeRemoveItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeSetCash_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_TradeSetCash(DWORD), n3EngineClientAnarchy_t__N3Msg_TradeSetCash);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeStart_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_TradeStart(const identity_t &), n3EngineClientAnarchy_t__N3Msg_TradeStart);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeskillCombine_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_TradeskillCombine(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_TradeskillCombine);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TrainPerk_x
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_TrainPerk(DWORD), n3EngineClientAnarchy_t__N3Msg_TrainPerk);
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
	FUNCTION_AT_ADDRESS(bool engine_client_anarchy::N3Msg_UntrainPerk(DWORD), n3EngineClientAnarchy_t__N3Msg_UntrainPerk);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_UseItem_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_UseItem(const identity_t&, bool), n3EngineClientAnarchy_t__N3Msg_UseItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_UseItemOnItem_x
	FUNCTION_AT_ADDRESS(void engine_client_anarchy::N3Msg_UseItemOnItem(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_UseItemOnItem);
#endif


}
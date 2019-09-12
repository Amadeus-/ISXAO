#include "isxao_main.h"

#define GET_FUNCTION_ADDRESS(module, function_address) get_function_address((module##_data), (function_address##_pattern), (module##_module_base), (function_address), #function_address); // NOLINT(cppcoreguidelines-macro-usage)
#define GET_ADDRESS_FROM_FUNCTION_OFFSET(function_base, static_address) get_static_address_from_function((function_base), (static_address), #static_address, (static_address##_offset));  // NOLINT(cppcoreguidelines-macro-usage)
#define GET_RELATIVE_ADDRESS_FROM_FUNCTION_OFFSET(function_base, relative_address) get_relative_address_from_function((function_base), (relative_address), #relative_address, (relative_address##_offset), (relative_address##_bytes_to_next));  // NOLINT(cppcoreguidelines-macro-usage)
#define GET_PROC_ADDRESS(module, function_address) get_proc_address((module##_module_handle), (function_address), #function_address, (function_address##_mangled_name));  // NOLINT(cppcoreguidelines-macro-usage)

namespace isxao_globals
{

#pragma region Modules

	
	HMODULE n3_module_handle = GetModuleHandle(n3_module_name);
	MODULEINFO n3_module_info;
	HMODULE gamecode_module_handle = GetModuleHandle(gamecode_module_name);
	MODULEINFO gamecode_module_info;
	HMODULE gui_module_handle = GetModuleHandle(gui_module_name);
	MODULEINFO gui_module_info;
	HMODULE interfaces_module_handle = GetModuleHandle(interfaces_module_name);
	MODULEINFO interfaces_module_info;
	HMODULE vehicle_module_handle = GetModuleHandle(vehicle_module_name);
	MODULEINFO vehicle_module_info;
	DWORD hDatabaseController = DWORD(GetModuleHandle("DatabaseController.dll"));
	DWORD hMessageProtocol = DWORD(GetModuleHandle("MessageProtocol.dll"));
	DWORD hPathFinder = DWORD(GetModuleHandle("PathFinder.dll"));

#pragma endregion

	bool initialize_offsets()
	{
		if (!n3_module_handle)
		{
			printf("Could not find handle to module \"N3.dll\". Aborting offset initialization.");
			return false;
		}
		if (!gamecode_module_handle)
		{
			printf("Could not find handle to module \"Gamecode.dll\". Aborting offset initialization.");
			return false;
		}		
		if (!gui_module_handle)
		{
			printf("Could not find handle to module \"GUI.dll\". Aborting offset initialization.");
			return false;
		}
		if (!interfaces_module_handle)
		{
			printf("Could not find handle to module \"Interfaces.dll\". Aborting offset initialization.");
			return false;
		}
#pragma region Process

		process_handle = GetCurrentProcess();

#pragma endregion

#pragma region N3

		// Module
		GetModuleInformation(process_handle, n3_module_handle, &n3_module_info, sizeof(n3_module_info));
		// ReSharper disable once CppLocalVariableMayBeConst
		auto n3_module_base = DWORD(n3_module_handle);
		const auto n3_data_begin = reinterpret_cast<unsigned char*>(n3_module_base);
		const auto n3_data_end = n3_data_begin + n3_module_info.SizeOfImage;
		const vector<unsigned char> n3_data(n3_data_begin, n3_data_end);

		// Functions
#ifdef N3_CAMERA_T__SET_SECONDARY_TARGET_USE_PATTERN
		GET_FUNCTION_ADDRESS(n3, n3_camera_t__set_secondary_target)
#else
		GET_PROC_ADDRESS(n3, n3_camera_t__set_secondary_target)
#endif

#ifdef N3_CAMERA_T__SET_SELECTED_TARGET_USE_PATTERN
		GET_FUNCTION_ADDRESS(n3, n3_camera_t__set_selected_target)
#else
		GET_PROC_ADDRESS(n3, n3_camera_t__set_selected_target)
#endif

		// Functions
#ifdef N3_DYNEL_T__N3_DYNEL_T_USE_PATTERN
		GET_FUNCTION_ADDRESS(n3, n3_dynel_t__n3_dynel_t)
#else
		GET_PROC_ADDRESS(n3, n3_dynel_t__n3_dynel_t)
#endif

#ifdef N3_DYNEL_T__D_N3_DYNEL_T_USE_PATTERN
		GET_FUNCTION_ADDRESS(n3, n3_dynel_t__d_n3_dynel_t)
#else
		GET_PROC_ADDRESS(n3, n3_dynel_t__d_n3_dynel_t)
#endif

#ifdef N3_DYNEL_T__GET_DYNEL_USE_PATTERN
		GET_FUNCTION_ADDRESS(n3, n3_dynel_t__get_dynel)
#else
		GET_PROC_ADDRESS(n3, n3_dynel_t__get_dynel)
#endif

#ifdef N3_DYNEL_T__SEND_IIR_TO_OBSERVERS_USE_PATTERN
		GET_FUNCTION_ADDRESS(n3, n3_dynel_t__send_iir_to_observers)
#else
		GET_PROC_ADDRESS(n3, n3_dynel_t__send_iir_to_observers)
#endif

#ifdef N3_DYNEL_T__SET_PLAYFIELD_USE_PATTERN
		GET_FUNCTION_ADDRESS(n3, n3_dynel_t__set_playfield)
#else
		GET_PROC_ADDRESS(n3, n3_dynel_t__set_playfield)
#endif

#ifdef N3_DYNEL_T__UPDATE_WHERE_USE_PATTERN
		GET_FUNCTION_ADDRESS(n3, n3_dynel_t__update_where)
#else
		GET_PROC_ADDRESS(n3, n3_dynel_t__update_where)
#endif

#ifdef N3_DYNEL_T__UPDATE_LOCALITY_LISTENERS_USE_PATTERN
		GET_RELATIVE_ADDRESS_FROM_FUNCTION_OFFSET(n3_dynel_t__update_where, n3_dynel_t__update_locality_listeners)
#else
		GET_PROC_ADDRESS(n3, n3_dynel_t__update_locality_listeners)
#endif

		// Instances
#ifdef N3_DYNEL_T__M_PC_DYNEL_DIR_INSTANCE_USE_PATTERN
		GET_ADDRESS_FROM_FUNCTION_OFFSET(n3_dynel_t__get_dynel, n3_dynel_t__m_pc_dynel_dir_instance)
#else
		GET_PROC_ADDRESS(n3, n3_dynel_t__m_pc_dynel_dir_instance)
#endif
		pp_dynel_dir = reinterpret_cast<dynel_map_t**>(n3_dynel_t__m_pc_dynel_dir_instance);

		// Functions
#ifdef N3_ENGINE_T__N3_ENGINE_T_USE_PATTERN
		GET_FUNCTION_ADDRESS(n3, n3_engine_t__n3_engine_t)
#else
		GET_PROC_ADDRESS(n3, n3_engine_t__n3_engine_t)
#endif

		// Instances
#ifdef N3_ENGINE_T__M_PC_INSTANCE_USE_PATTERN
		GET_ADDRESS_FROM_FUNCTION_OFFSET(n3_engine_t__n3_engine_t, n3_engine_t__m_pc_instance)
#else
		GET_PROC_ADDRESS(n3, n3_engine_t__m_pc_instance)
#endif

		// Functions
#ifdef N3_ENGINE_CLIENT_T__GET_CLIENT_CONTROL_DYNEL_USE_PATTERN
		GET_RELATIVE_ADDRESS_FROM_FUNCTION_OFFSET(n3_camera_t__set_selected_target, n3_engine_client_t__get_client_control_dynel)
#else
		GET_PROC_ADDRESS(n3, n3_engine_client_t__get_client_control_dynel)
#endif

		// Functions
#ifdef N3_PLAYFIELD_T__ADD_CHILD_DYNEL_USE_PATTERN
		GET_FUNCTION_ADDRESS(n3, n3_playfield_t__add_child_dynel)
#else
		GET_PROC_ADDRESS(n3, n3_playfield_t__add_child_dynel)
#endif

#ifdef N3_PLAYFIELD_T__GET_PLAYFIELD_1_USE_PATTERN
		GET_FUNCTION_ADDRESS(n3, n3_playfield_t__get_playfield_1)
#else
		GET_PROC_ADDRESS(n3, n3_playfield_t__get_playfield_1)
#endif

#ifdef N3_PLAYFIELD_T__GET_PLAYFIELD_2_USE_PATTERN
		GET_FUNCTION_ADDRESS(n3, n3_playfield_t__get_playfield_2)
#else
		GET_PROC_ADDRESS(n3, n3_playfield_t__get_playfield_2)
#endif

#ifdef N3_PLAYFIELD_T__GET_PLAYFIELD_3_USE_PATTERN
		GET_FUNCTION_ADDRESS(n3, n3_playfield_t__get_playfield_3)
#else
		GET_PROC_ADDRESS(n3, n3_playfield_t__get_playfield_3)
#endif

#ifdef N3_PLAYFIELD_T__LINE_OF_SIGHT_USE_PATTERN
		GET_FUNCTION_ADDRESS(n3, n3_playfield_t__line_of_sight)
#else
		GET_PROC_ADDRESS(n3, n3_playfield_t__line_of_sight)
#endif

#ifdef N3_PLAYFIELD_T__REMOVE_CHILD_USE_PATTERN
		GET_FUNCTION_ADDRESS(n3, n3_playfield_t__remove_child)
#else
		GET_PROC_ADDRESS(n3, n3_playfield_t__remove_child)
#endif

		// Instances
#ifdef N3_PLAYFIELD_T__M_PC_PLAYFIELD_DIR_INSTANCE_USE_PATTERN
		GET_ADDRESS_FROM_FUNCTION_OFFSET(n3_playfield_t__get_playfield_2, n3_playfield_t__m_pc_playfield_dir_instance)
#else
		GET_PROC_ADDRESS(n3, n3_playfield_t__m_pc_playfield_dir_instance)
#endif
		pp_playfield_dir = reinterpret_cast<PlayfieldDir**>(n3_playfield_t__m_pc_playfield_dir_instance);

#pragma endregion

#pragma region Gamecode

		// Module
		GetModuleInformation(process_handle, gamecode_module_handle, &gamecode_module_info, sizeof(gamecode_module_info));
		// ReSharper disable once CppLocalVariableMayBeConst
		auto gamecode_module_base = DWORD(gamecode_module_handle);
		const auto gamecode_data_begin = reinterpret_cast<unsigned char*>(gamecode_module_base);
		const auto gamecode_data_end = gamecode_data_begin + gamecode_module_info.SizeOfImage;
		const vector<unsigned char> gamecode_data(gamecode_data_begin, gamecode_data_end);

		// Functions
#ifdef F_GET_NANO_ITEM_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, f_get_nano_item)
#else
		static_assert(false, "f_get_nano_item requires a pattern for the function address to be found.")
#endif

#ifdef F_STAT_TO_STRING_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, stat_to_string)
#else
		GET_PROC_ADDRESS(gamecode, f_stat_to_string)
#endif



#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_ENGINE_CLIENT_ANARCHY_T_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_engine_client_anarchy_t)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_engine_client_anarchy_t)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__D_N3_ENGINE_CLIENT_ANARCHY_T_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__CONVERT_CRITERIA_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__convert_criteria)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__convert_criteria)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_BREED_STR_USE_PATTERN
		GET_RELATIVE_ADDRESS_FROM_FUNCTION_OFFSET(n3_engine_client_anarchy_t__convert_criteria, n3_engine_client_anarchy_t__get_breed_str)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_breed_str)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_CLIENT_CHAR_USE_PATTERN
		n3_engine_client_anarchy_t__get_client_char = n3_engine_client_t__get_client_control_dynel;
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_client_char)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_CLIENT_DYNEL_ID_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_client_dynel_id)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_client_dynel_id)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_CURRENT_MOVEMENT_MODE_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_current_movement_mode)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_current_movement_mode)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_FACTION_STR_USE_PATTERN		
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_faction_str)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_faction_str)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_FACTION_TITLE_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_faction_title)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_faction_title)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_GENDER_STRING_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_gender_string)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_gender_string)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_ITEM_BY_TEMPLATE_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_item_by_template)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_item_by_template)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_SEX_STR_USE_PATTERN
		GET_RELATIVE_ADDRESS_FROM_FUNCTION_OFFSET(n3_engine_client_anarchy_t__convert_criteria, n3_engine_client_anarchy_t__get_sex_str)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_sex_str)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_TITLE_STR_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_title_str)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_title_str)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__IS_FIRST_LOGIN_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__is_first_login)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__is_first_login)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__IS_FIXTURE_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__is_fixture)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__is_fixture)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_ACTIVATE_MECH_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_activate_mech)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_activate_mech)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_AIRSTRIKE_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_airstrike)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_airstrike)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_ARTILLERY_ATTACK_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_artillery_attack)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_artillery_attack)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_ASSIST_FIGHT_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_assist_fight)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_assist_fight)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CAN_ATTACK_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_can_attack)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_can_attack)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CAST_NANO_SPELL_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_cast_nano_spell)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_cast_nano_spell)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CONSIDER_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_consider)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_consider)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CONTAINER_ADD_ITEM_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_container_add_item)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_container_add_item)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CRAWL_TOGGLE_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_crawl_toggle)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_crawl_toggle)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CREATE_RAID_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_create_raid)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_create_raid)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DEFAULT_ACTION_ON_DYNEL_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_default_action_on_dynel)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_default_action_on_dynel)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DEFAULT_ATTACK_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_default_attack)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_default_attack)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DELETE_ITEM_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_delete_item)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_delete_item)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DELETE_NANO_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode , n3_engine_client_anarchy_t__n3_msg_delete_nano)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_delete_nano)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DO_SOCIAL_ACTION_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_do_social_action)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_do_social_action)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DROP_ITEM_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_drop_item)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_drop_item)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_ACCEPT_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_duel_accept)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_duel_accept)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_CHALLENGE_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_duel_challenge)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_duel_challenge)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_DRAW_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_duel_draw)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_duel_draw)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_REFUSE_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_duel_refuse)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_duel_refuse)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_STOP_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_duel_stop)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_duel_stop)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_FORAGE_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_forage)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_forage)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ACTION_BY_NAME_USE_PATTERN
		static_assert(false, "engine_client_anarchy::n3_msg_get_action_by_name(PCSTR) cannot be found with a pattern.");
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_action_by_name)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ACTION_PROGRESS_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_action_progress)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_action_progress)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_AGG_DEF_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_agg_def)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_agg_def)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ALIEN_LEVEL_STRING_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_alien_level_string)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_alien_level_string)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_AREA_NAME_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_area_name)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_area_name)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ATTACKING_ID_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_attacking_id)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_attacking_id)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_BREED_STR_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_breed_str)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_breed_str)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_BUFF_CURRENT_TIME_USE_PATTERN
		static_assert(false, "engine_client_anarchy::n3_msg_get_buff_current_time(const identity_t&, const identity_t&) cannot be found with a pattern.");
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_buff_current_time)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_BUFF_TOTAL_TIME_USE_PATTERN
		static_assert(false, "engine_client_anarchy::n3_msg_get_buff_total_time(const identity_t&, const identity_t&) cannot be found with a pattern.");
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_buff_total_time)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CHARACTER_BODY_SHAPE_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_character_body_shape)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_character_body_shape)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CHAR_ORIENTATION_DATA_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_char_orientation_data)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_char_orientation_data)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CITY_NAME_FOR_CLAN_MEMBER_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_city_name_for_clan_member)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_city_name_for_clan_member)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CLAN_LEVEL_STRING_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_clan_level_string)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_clan_level_string)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CLAN_STRING_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_clan_string)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_clan_string)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CLIENT_PET_ID_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_client_pet_id)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_client_pet_id)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CLOSE_TARGET_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_close_target)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_close_target)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CONTAINER_INVENTORY_LIST_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_container_inventory_list)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_container_inventory_list)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CORRECT_ACTION_ID_USE_PATTERN
		static_assert(false, "engine_client_anarchy::n3_msg_get_correct_action_id(identity_t &) cannot be found with a pattern.");
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_correct_action_id)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CURRENT_ROOM_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_current_room)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_current_room)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CURRENT_ROOM_NAME_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_current_room_name)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_current_room_name)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_DISTRICT_FIGHT_MODE_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_district_fight_mode)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_district_fight_mode)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_DYNELS_IN_VICINITY_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_dynels_in_vicinity)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_dynels_in_vicinity)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FACTION_INFO_STRING_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_faction_info_string)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_faction_info_string)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FACTION_RANGE_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_faction_range)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_faction_range)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FIRST_NAME_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_first_name)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_first_name)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FORMULA_PROGRESS_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_formula_progress)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_formula_progress)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FORMULA_RADIUS_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_formula_radius)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_formula_radius)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_GLOBAL_CHARACTER_POSITION_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_global_character_position)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_global_character_position)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_GLOBAL_CHARACTER_ROTATION_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_global_character_rotation)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_global_character_rotation)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_GRID_DESTINATION_1_LIST_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_1)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_1)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_GRID_DESTINATION_2_LIST_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_2)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_2)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_INVENTORY_VEC_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_inventory_vec)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_inventory_vec)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ITEM_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_item)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_item)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ITEM_PROGRESS_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_item_progress)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_item_progress)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_MOVEMENT_MODE_USE_PATTERN
		static_assert(false, "engine_client_anarchy::n3_msg_get_correct_action_id(identity_t &) cannot be found with a pattern.");
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_movement_mode)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NAME_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_name)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_name)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NANO_COST_MODIFIER_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_nano_cost_modifier)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_nano_cost_modifier)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NANO_SPELL_LIST_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_nano_spell_list)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_nano_spell_list)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NANO_TEMPLATE_INFO_LIST_1_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_1)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_1)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NANO_TEMPLATE_INFO_LIST_2_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_2)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_2)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NEXT_TARGET_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_next_target)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_next_target)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_AVAILABLE_ALIEN_PERKS_USE_PATTERN
		static_assert(false, "engine_client_anarchy::n3_msg_get_number_of_available_alien_perks() cannot be found with a pattern.");
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_number_of_available_alien_perks)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_AVAILABLE_PERKS_USE_PATTERN
		static_assert(false, "engine_client_anarchy::n3_msg_get_number_of_available_perks() cannot be found with a pattern.");
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_number_of_available_perks)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_FREE_INVENTORY_SLOTS_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_number_of_free_inventory_slots)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_number_of_free_inventory_slots)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_USED_ALIEN_PERKS_USE_PATTERN
		static_assert(false, "engine_client_anarchy::n3_msg_get_number_of_used_alien_perks() cannot be found with a pattern.");
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_number_of_used_alien_perks)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_USED_PERKS_USE_PATTERN
		static_assert(false, "engine_client_anarchy::n3_msg_get_number_of_used_perks() cannot be found with a pattern.");
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_number_of_used_perks)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_OVER_EQUIP_LEVEL_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_over_equip_level)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_over_equip_level)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_PLAYFIELD_NAME_1_USE_PATTERN
		static_assert(false, "engine_client_anarchy::n3_msg_get_pf_name(DWORD) cannot be found with a pattern.");
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_pf_name_1)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_PLAYFIELD_NAME_2_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_pf_name_2)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_pf_name_2)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_PARENT_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_parent)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_parent)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_POS_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_pos)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_pos)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SKILL_1_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_skill_1)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_skill_1)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SKILL_2_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_skill_2)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_skill_2)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SKILL_MAX_USE_PATTERN
		static_assert(false, "engine_client_anarchy::n3_msg_get_skill_max(DWORD) cannot be found with a pattern.");
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_skill_max)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SPECIAL_ACTION_LIST_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_special_action_list)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_special_action_list)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SPECIAL_ACTION_STATE_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_special_action_state)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_special_action_state)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SPECIAL_ATTACK_WEAPON_NAME_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_special_attack_weapon_name)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_special_attack_weapon_name)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_STAT_NAME_MAP_USE_PATTERN
		static_assert(false, "engine_client_anarchy::n3_msg_get_stat_name_map() cannot be found with a pattern.");
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_stat_name_map)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_TARGET_TARGET_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_target_target)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_target_target)
#endif







#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_IS_NPC_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_npc)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_npc)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_PERFORM_SPECIAL_ACTION_1_USE_PATTERN
		static_assert(false, "engine_client_anarchy::n3_msg_perform_special_action(DWORD) cannot be found with a pattern.");
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_perform_special_action_1)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_PERFORM_SPECIAL_ACTION_2_USE_PATTERN
		static_assert(false, "engine_client_anarchy::n3_msg_perform_special_action(const identity_t &) cannot be found with a pattern.");
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_perform_special_action_2)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_SEND_PET_COMMAND_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_send_pet_command)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_send_pet_command)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_STOP_ATTACK_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_stop_attack)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_stop_attack)
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_USE_ITEM_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_use_item)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_use_item)
#endif



#ifdef N3_ENGINE_CLIENT_ANARCHY_T__ON_CLOSED_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__on_closed)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__on_closed)
#endif





#ifdef SIMPLE_CHAR_T__CHECK_LOS_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, simple_char_t__check_los)
#else
		static_assert(false, "simple_char_t__check_los requires a pattern for the function address to be found.")
#endif

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CAN_CLICK_TARGET_TARGET_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_can_click_target_target)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_can_click_target_target)
#endif



		// Instances
		n3_engine_client_anarchy_t__m_pc_instance = n3_engine_t__m_pc_instance;
		pp_engine_client_anarchy = reinterpret_cast<isxao_classes::engine_client_anarchy**>(n3_engine_client_anarchy_t__m_pc_instance);

#ifdef M_C_NANO_ITEM_DIR_USE_PATTERN
		GET_ADDRESS_FROM_FUNCTION_OFFSET(f_get_nano_item, m_c_nano_item_dir)
#else
		static_assert(false, "m_c_nano_item_dir requires a pattern for the function address to be found.")
#endif
		p_nano_item_dir = reinterpret_cast<nano_item_map_t*>(m_c_nano_item_dir);

#ifdef M_C_STAT_NAME_DIR_USE_PATTERN
		GET_ADDRESS_FROM_FUNCTION_OFFSET(f_stat_to_string, m_c_stat_name_dir)
#else
		static_assert(false, "m_c_stat_name_dir requires a pattern for the function address to be found.")
#endif
		p_stat_name_dir = reinterpret_cast<stat_name_map_t*>(m_c_stat_name_dir);

#ifdef ITEM_MANAGER_T__ITEM_MANAGER_T_USE_PATTERN
		GET_RELATIVE_ADDRESS_FROM_FUNCTION_OFFSET(n3_engine_client_anarchy_t__get_item_by_template, item_manager_t__item_manager_t)
#else
		static_assert(false, "item_manager_t__item_manager_t requires a pattern for the function address to be found.")
#endif

#ifdef ITEM_MANAGER_T__M_PPC_INSTANCE_USE_PATTERN
		GET_ADDRESS_FROM_FUNCTION_OFFSET(item_manager_t__item_manager_t, item_manager_t__m_ppc_instance)
#else
		static_assert(false, "item_manager_t__m_ppc_instance requires a pattern for the function address to be found.")
#endif
		ppp_item_vector = reinterpret_cast<vector<acg_game_item_t> ***>(item_manager_t__m_ppc_instance);

#ifdef STATIC_ITEM_MANAGER_T__STATIC_ITEM_MANAGER_T_USE_PATTERN
		GET_RELATIVE_ADDRESS_FROM_FUNCTION_OFFSET(n3_engine_client_anarchy_t__get_item_by_template, static_item_manager_t__static_item_manager_t)
#else
		static_assert(false, "static_item_manager_t__static_item_manager_t requires a pattern for the function address to be found.")
#endif

#ifdef STATIC_ITEM_MANAGER_T__M_PPC_INSTANCE_USE_PATTERN
		GET_ADDRESS_FROM_FUNCTION_OFFSET(static_item_manager_t__static_item_manager_t, static_item_manager_t__m_ppc_instance)
#else
		static_assert(false, "static_item_manager_t__m_ppc_instance requires a pattern for the function address to be found.")
#endif
		ppp_static_item_vector = reinterpret_cast<vector<static_item_t>***>(static_item_manager_t__m_ppc_instance);
#pragma endregion

#pragma region GUI

		// Module
		GetModuleInformation(process_handle, gui_module_handle, &gui_module_info, sizeof(gui_module_info));
		// ReSharper disable once CppLocalVariableMayBeConst
		auto gui_module_base = DWORD(gui_module_handle);
		const auto gui_data_begin = reinterpret_cast<unsigned char*>(gui_module_base);
		const auto gui_data_end = gui_data_begin + gui_module_info.SizeOfImage;
		const vector<unsigned char> gui_data(gui_data_begin, gui_data_end);

		// Functions
#ifdef TARGETING_MODULE_T__INITIALISE_MESSAGE_USE_PATTERN
		GET_FUNCTION_ADDRESS(gui, targeting_module_t__initialise_message)
#else
		GET_PROC_ADDRESS(gui, targeting_module_t__initialise_message)
#endif

#ifdef TARGETING_MODULE_T__TARGETING_MODULE_T_USE_PATTERN
		GET_FUNCTION_ADDRESS(gui, targeting_module_t__targeting_module_t)
#else
		GET_PROC_ADDRESS(gui, targeting_module_t__targeting_module_t)
#endif

#ifdef TARGETING_MODULE_T__SET_TARGET_USE_PATTERN
		GET_FUNCTION_ADDRESS(gui, targeting_module_t__set_target)
#else
		GET_PROC_ADDRESS(gui, targeting_module_t__set_target)
#endif

		// Instances
#ifdef TARGETING_MODULE_T__M_PC_INSTANCE_USE_PATTERN
		GET_ADDRESS_FROM_FUNCTION_OFFSET(targeting_module_t__set_target, targeting_module_t__m_pc_instance)
#else
		GET_PROC_ADDRESS(gui, targeting_module_t__m_pc_instance)
#endif		

#ifdef TARGETING_MODULE_T__M_PC_SELECTION_INDICATOR_USE_PATTERN
		GET_ADDRESS_FROM_FUNCTION_OFFSET(targeting_module_t__initialise_message, targeting_module_t__m_pc_selection_indicator)
#else
		GET_PROC_ADDRESS(gui, targeting_module_t__m_pc_selection_indicator)
#endif

		pp_selection_indicator = reinterpret_cast<indicator_t**>(targeting_module_t__m_pc_selection_indicator);

#ifdef TARGETING_MODULE_T__M_PC_ATTACKING_INDICATOR_USE_PATTERN
		GET_ADDRESS_FROM_FUNCTION_OFFSET(targeting_module_t__initialise_message, targeting_module_t__m_pc_attacking_indicator)
#else
		GET_PROC_ADDRESS(gui, targeting_module_t__m_pc_attacking_indicator)
#endif

		pp_attacking_indicator = reinterpret_cast<indicator_t**>(targeting_module_t__m_pc_attacking_indicator);

#ifdef TARGETING_MODULE_T__M_C_LAST_TARGET_USE_PATTERN
		GET_ADDRESS_FROM_FUNCTION_OFFSET(targeting_module_t__initialise_message, targeting_module_t__m_c_last_target)
#else
		GET_PROC_ADDRESS(gui, targeting_module_t__m_c_last_target)
#endif

#pragma endregion

#pragma region Interfaces

		// Module
		GetModuleInformation(process_handle, interfaces_module_handle, &interfaces_module_info, sizeof(interfaces_module_info));
		// ReSharper disable once CppLocalVariableMayBeConst
		auto interfaces_module_base = DWORD(interfaces_module_handle);
		const auto interfaces_data_begin = reinterpret_cast<unsigned char*>(interfaces_module_base);
		const auto interfaces_data_end = interfaces_data_begin + interfaces_module_info.SizeOfImage;
		const vector<unsigned char> interfaces_data(interfaces_data_begin, interfaces_data_end);

		// Instances
#ifdef CLIENT_T__S_N_CHAR_ID_USE_PATTERN
		static_assert(false, "client_t__s_n_char_id cannot be found with a pattern.");
#else
		GET_PROC_ADDRESS(interfaces, client_t__s_n_char_id)
#endif
		gp_character_id = reinterpret_cast<DWORD*>(client_t__s_n_char_id);

#pragma endregion

#pragma region Vehicle

		// Module
		GetModuleInformation(process_handle, vehicle_module_handle, &vehicle_module_info, sizeof(vehicle_module_info));
		// ReSharper disable once CppLocalVariableMayBeConst
		auto vehicle_module_base = DWORD(vehicle_module_handle);
		const auto vehicle_data_begin = reinterpret_cast<unsigned char*>(vehicle_module_base);
		const auto vehicle_data_end = vehicle_data_begin + vehicle_module_info.SizeOfImage;
		const vector<unsigned char> vehicle_data(vehicle_data_begin, vehicle_data_end);

#ifdef VEHICLE_T__SET_REL_ROT_USE_PATTERN
		GET_FUNCTION_ADDRESS(vehicle, vehicle_t__set_rel_rot)
#else
		GET_PROC_ADDRESS(vehicle, vehicle_t__set_rel_rot)
#endif


#pragma endregion

		return true;
	}

#pragma region Process

	HANDLE process_handle = nullptr;

#pragma endregion

#pragma region Globals

	DWORD __N3Msg_GetFullPerkMap = 0;
	DWORD __SetTarget = 0;
	
	DWORD __RequestInfo = 0;

#pragma endregion

#pragma region N3

	// Functions
	DWORD n3_camera_t__set_secondary_target = 0;
	DWORD n3_camera_t__set_selected_target = 0;	

	// Functions
	DWORD n3_dynel_t__n3_dynel_t = 0;
	DWORD n3_dynel_t__d_n3_dynel_t = 0;
	DWORD n3_dynel_t__get_dynel = 0;
	DWORD n3_dynel_t__send_iir_to_observers = 0;
	DWORD n3_dynel_t__set_playfield = 0;
	DWORD n3_dynel_t__update_locality_listeners = 0;
	DWORD n3_dynel_t__update_where = 0;

	// Instances
	DWORD n3_dynel_t__m_pc_dynel_dir_instance = 0;
	dynel_map_t **pp_dynel_dir = nullptr;

	// Functions
	DWORD n3_engine_t__n3_engine_t = 0;

	// Functions
	DWORD n3_engine_client_t__get_client_control_dynel = 0;

	// Instances
	DWORD n3_engine_t__m_pc_instance = 0;

	// Functions
	DWORD n3_playfield_t__add_child_dynel = 0;
	DWORD n3_playfield_t__get_playfield_1 = 0;
	DWORD n3_playfield_t__get_playfield_2 = 0;
	DWORD n3_playfield_t__get_playfield_3 = 0;
	DWORD n3_playfield_t__line_of_sight = 0;
	DWORD n3_playfield_t__remove_child = 0;

	// Instances
	DWORD n3_playfield_t__m_pc_playfield_dir_instance = 0;
	PlayfieldDir** pp_playfield_dir = nullptr;

#pragma endregion

#pragma region Gamecode

	// Functions
	DWORD f_get_nano_item = 0;
	DWORD f_stat_to_string = 0;

	DWORD item_manager_t__item_manager_t = 0;

	DWORD n3_engine_client_anarchy_t__n3_engine_client_anarchy_t = 0;
	DWORD n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t = 0;
	DWORD n3_engine_client_anarchy_t__convert_criteria = 0;
	DWORD n3_engine_client_anarchy_t__get_breed_str = 0;
	DWORD n3_engine_client_anarchy_t__get_client_char = 0;
	DWORD n3_engine_client_anarchy_t__get_client_dynel_id = 0;
	DWORD n3_engine_client_anarchy_t__get_current_movement_mode = 0;
	DWORD n3_engine_client_anarchy_t__get_faction_str = 0;
	DWORD n3_engine_client_anarchy_t__get_faction_title = 0;
	DWORD n3_engine_client_anarchy_t__get_gender_string = 0;
	DWORD n3_engine_client_anarchy_t__get_item_by_template = 0;
	DWORD n3_engine_client_anarchy_t__get_sex_str = 0;
	DWORD n3_engine_client_anarchy_t__get_title_str = 0;
	DWORD n3_engine_client_anarchy_t__is_first_login = 0;
	DWORD n3_engine_client_anarchy_t__is_fixture = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_activate_mech = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_airstrike = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_artillery_attack = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_assist_fight = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_can_attack = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_can_click_target_target = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_can_use_mech = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_cast_nano_spell = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_consider = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_container_add_item = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_crawl_toggle = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_create_raid = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_default_action_on_dynel = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_default_attack = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_delete_item = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_delete_nano = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_do_social_action = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_drop_item = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_duel_accept = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_duel_challenge = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_duel_draw = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_duel_refuse = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_duel_stop = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_forage = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_action_by_name = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_action_progress = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_agg_def = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_alien_level_string = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_area_name = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_attacking_id = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_breed_str = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_buff_current_time = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_buff_total_time = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_character_body_shape = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_char_orientation_data = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_city_name_for_clan_member = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_clan_level_string = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_clan_string = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_client_pet_id = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_close_target = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_container_inventory_list = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_correct_action_id = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_current_room = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_current_room_name = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_district_fight_mode = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_dynels_in_vicinity = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_faction_info_string = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_faction_range = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_first_name = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_formula_progress = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_formula_radius = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_global_character_position = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_global_character_rotation = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_1 = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_2 = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_inventory_vec = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_item = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_item_progress = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_movement_mode = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_name = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_nano_cost_modifier = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_nano_spell_list = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_1 = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_2 = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_next_target = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_available_alien_perks = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_available_perks = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_free_inventory_slots = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_used_alien_perks = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_used_perks = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_over_equip_level = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_pf_name_1 = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_pf_name_2 = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_parent = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_pos = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_skill_1 = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_skill_2 = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_skill_max = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_special_action_list = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_special_action_state = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_special_attack_weapon_name = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_stat_name_map = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_get_target_target = 0;


	DWORD n3_engine_client_anarchy_t__n3_msg_is_npc = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_perform_special_action_1 = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_perform_special_action_2 = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_send_pet_command = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_stop_attack = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_use_item = 0;
	DWORD n3_engine_client_anarchy_t__on_closed = 0;
	

	DWORD simple_char_t__check_los = 0;

	DWORD static_item_manager_t__static_item_manager_t = 0;

	// Instances
	DWORD n3_engine_client_anarchy_t__m_pc_instance = 0;
	isxao_classes::engine_client_anarchy **pp_engine_client_anarchy = nullptr;
	DWORD m_c_stat_name_dir = 0;
	stat_name_map_t* p_stat_name_dir = nullptr;
	DWORD m_c_nano_item_dir = 0;
	nano_item_map_t* p_nano_item_dir = nullptr;
	DWORD item_manager_t__m_ppc_instance = 0;
	vector<acg_game_item_t> ***ppp_item_vector = nullptr;
	DWORD static_item_manager_t__m_ppc_instance = 0;
	vector<static_item_t> ***ppp_static_item_vector = nullptr;

#pragma endregion

#pragma region GUI

	DWORD targeting_module_t__m_pc_instance = 0;
	TargetingModule** pp_targeting_module = nullptr;
	DWORD targeting_module_t__m_pc_selection_indicator = 0;
	indicator_t** pp_selection_indicator = nullptr;
	DWORD targeting_module_t__m_pc_attacking_indicator = 0;
	indicator_t** pp_attacking_indicator = nullptr;
	DWORD targeting_module_t__m_c_last_target = 0;
	identity_t* p_last_target = nullptr;
	DWORD targeting_module_t__initialise_message = 0;
	DWORD targeting_module_t__targeting_module_t = 0;
	DWORD targeting_module_t__set_target = 0;

#pragma endregion



#pragma region Vehicle

	DWORD vehicle_t__set_rel_rot = 0;

#pragma endregion

#pragma region EngineClientAnarchy
	
	
	DWORD n3EngineClientAnarchy_t__N3Msg_GetTeamMemberList = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_HasPerk = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsAttacking = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsBattleStation = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsCharacterInMech = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsCharacterMorphed = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsDungeon = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsFormulaReady = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsGeneralPerk = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsGroupPerk = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsInRaidTeam = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsInTeam = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsItemDisabled = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsItemMine = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsItemNFCrystal = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToUnWear = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToWear = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsMoving = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsMyPetID = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsNanoSelfOnly = 0;
	
	DWORD n3EngineClientAnarchy_t__N3Msg_IsPerk = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsPetTower = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsProfessionPerk = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsResearch = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsSecondarySpecialAttackAvailable = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsShieldDisablerItem = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsSpecialPerk = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsTeamLeader = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsTeamMission = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsTeamMissionCopy = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsTeamNano = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsTower = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_IsVisible = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_JoinItems = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_KickTeamMember = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_LeaveBattle = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_LeaveTeam = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_MeetsPerkCriteria = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_MoveItemToInventory = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_MoveRaidMember = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_NameToID = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatAddTradeItem = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatCloseWindow = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatEndTrade = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatRemoveTradeItem = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatRequestDescription = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatStartTrade = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_OrbitalAttack = 0;
	
	DWORD n3EngineClientAnarchy_t__N3Msg_PetDuel_Accept = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_PetDuel_Challenge = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_PetDuel_Refuse = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_PetDuel_Stop = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_RemoveBuff = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_RemoveQuest = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_RequestCharacterInventory = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_RequestClothInventory = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_RequestImplantInventory = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_RequestSocialInventory = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_RequestWeaponInventory = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_SecondarySpecialAttack = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_SelectedTarget = 0;
	
	DWORD n3EngineClientAnarchy_t__N3Msg_SitToggle = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_SplitItem = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_StartAltState = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_StartCamping = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_StartPvP = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_StartTreatment;
	DWORD n3EngineClientAnarchy_t__N3Msg_StopAltState = 0;
	
	DWORD n3EngineClientAnarchy_t__N3Msg_StopCamping = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_StringToStat = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_SwitchTarget = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_TeamJoinRequest = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_TemplateIDToDynelID = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_TextCommand = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_ToggleReclaim = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_TradeAbort = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_TradeAccept = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_TradeAddItem = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_TradeConfirm = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_TradeGetInventory = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_TradeGetInventoryCost = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_TradeRemoveItem = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_TradeSetCash = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_TradeStart = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_TradeskillCombine = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_TrainPerk = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_TransferTeamLeadership = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_TryAbortNanoFormula = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_TryEnterSneakMode = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_UntrainPerk = 0;
	
	DWORD n3EngineClientAnarchy_t__N3Msg_UseItemOnItem = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_UseSkill = 0;
	DWORD n3EngineClientAnarchy_t__SetMainDynel = 0;

	DWORD n3Engine_t__SetTeleportStatus = 0;

	DWORD n3EngineClient_t__SetMainDynel = 0;


#pragma endregion
	
#pragma region ItemManagement

	
	//DWORD NanoItemManager_t__m_pcInstance = 0;
	//nano_item_dir_t **ppNanoItemDir = nullptr;
	//DWORD NanoItem_t__GetNanoItem = 0;
	
	

#pragma endregion

#pragma region Playfield	
	
	DWORD n3Playfield_t__OnChildDynelBeingRemoved = 0;
	

	DWORD PlayfieldAnarchy_t__PlayfieldAnarchy_t = 0;
	DWORD PlayfieldAnarchy_t__dPlayfieldAnarchy_t = 0;

#pragma endregion

#pragma region Gametime

	DWORD Gametime_t__m_pcInstance = 0;
	GameTime** ppGametime = nullptr;

#pragma endregion

#pragma region InputConfig

	DWORD InputConfig_t__m_pcInstance = 0;
	InputConfig** ppInputConfig = nullptr;

	DWORD InputConfig_t__SetCurrentTarget = 0;

#pragma endregion

#pragma region FlowControl

	DWORD FlowControlModule_t__m_pcInstance = 0;
	DWORD FlowControlModule_t__m_isLauncherRun = 0;
	DWORD FlowControlModule_t__m_bIsGameClosing = 0;
	DWORD FlowControlModule_t__m_nCloseFrames = 0;
	DWORD FlowControlModule_t__m_isTeleporting = 0;
	bool* gpbIsTeleporting = nullptr;
	DWORD FlowControlModule_t__m_eLoggingOutTimed = 0;
	DWORD FlowControlModule_t__m_isClientToRestartAtExit = 0;
	
#pragma endregion

#pragma region TargetingModule	
	
	DWORD TargetingModule_t__RemoveTarget = 0;
	DWORD TargetingModule_t__SelectSelf = 0;	
	DWORD TargetingModule_t__SetTargetPet = 0;

#pragma endregion

#pragma region ChatGUIModule

	DWORD ChatGUIModule_c__s_pcInstance = 0;
	ChatGUIModule** ppChatGUIModule = nullptr;
	DWORD ChatGUIModule_c__HandleGroupAction = 0;
	DWORD ChatGUIModule_c__HandleGroupMessage = 0;
	DWORD ChatGUIModule_c__HandlePrivateGroupAction = 0;
	DWORD ChatGUIModule_c__HandlePrivateMessage = 0;
	DWORD ChatGUIModule_c__HandleSystemMessage = 0;
	DWORD ChatGUIModule_c__HandleVicinityMessage = 0;

#pragma endregion



#pragma region Client

	DWORD client_t__s_n_char_id = 0;
	PDWORD gp_character_id = nullptr;
	DWORD Client_t__ProcessMessage = 0;

#pragma endregion

#pragma region Message

	DWORD Message_t__DataBlockSizeGet = 0;
	DWORD Message_t__MessageSizeGet = 0;

	DWORD N3Message_t__DuplicateBody = 0;
	DWORD N3Message_t__MessageBodyGet = 0;
	DWORD N3Message_t__MessageBodyLen = 0;

	DWORD TextMessage_t__MessageBodyGet = 0;
	DWORD TextMessage_t__MessageBodyLen = 0;

#pragma endregion

#pragma region Logger

	ISXAOLog* gp_isxao_log = nullptr;

#pragma endregion

#pragma region vTable

	DWORD AccessCard_t__vTable = 0;
	DWORD CentralController_t__vTable = 0;
	DWORD Chest_t__vTable = 0;
	DWORD CityTerminal_t__vTable = 0;
	DWORD Corpse_t__vTable = 0;
	DWORD Door_t__vTable = 0;
	DWORD LockableItem_t__vTable = 0;
	DWORD Mine_t__vTable = 0;
	DWORD PlayerShop_t__vTable = 0;
	DWORD QuestBooth_t__vTable = 0;
	DWORD ReclaimBooth_t__vTable = 0;
	DWORD SimpleChar_t__vTable = 0;
	DWORD SimpleItem_t__vTable = 0;
	DWORD TrapItem_t__vTable = 0;
	DWORD VendingMachine_t__vTable = 0;
	DWORD Weapon_t__vTable = 0;
	DWORD WearableItem_t__vTable = 0;

#pragma endregion

#pragma region SimpleChar

	DWORD SimpleChar_t__SimpleChar_t = 0;
	DWORD SimpleChar_t__dSimpleChar_t = 0;	

#pragma endregion

#pragma region Internal

	DWORD64 g_pulse_count = 0;
	DWORD g_game_state = 0;
	DOUBLE g_y_filter = 10000.0f;
	bool g_zoning = false;
	bool g_offsets_initialized = false;
	bool g_events_registered = false;
	bool g_isxao_initialized = false;
	Concurrency::concurrent_queue<PN3MESSAGEINFO> g_n3message_queue;
	Concurrency::concurrent_queue<PGROUPMESSAGEINFO> g_group_message_queue;
	Concurrency::concurrent_queue<PPRIVATEMESSAGEINFO> g_private_message_queue;
	Concurrency::concurrent_queue<PPRIVATEMESSAGEINFO> g_vicinity_message_queue;
	Concurrency::concurrent_queue<PSYSTEMCHATINFO> g_system_chat_queue;

#pragma endregion

#pragma region PlayerVehicle

	DWORD PlayerVehicle_t__UseWaypointPath;

#pragma endregion

#pragma region LoginModule

	DWORD LoginModule_c__m_pcInstance = 0;
	login_module_t** ppLoginModule = nullptr;

#pragma endregion

#pragma region ChatWindowController

	DWORD ChatWindowController_c__m_pcInstance = 0;
	ChatWindowController** ppChatWindowController = nullptr;

	DWORD ChatGroupController_c__sub_10083D9C = 0;

#pragma endregion

#pragma region FriendListController

	DWORD FriendListController_c__sub_100A68E6 = 0;

#pragma endregion

#pragma region CommandInterpreter

	DWORD CommandInterpreter_c__m_pcInstance = 0;
	CommandInterpreter** ppCommandInterpreter = nullptr;
	DWORD CommandInterpreter_c__ParseTextCommand = 0;

#pragma endregion

#pragma region ChatWindowNode

	DWORD ChatWindowNode_c__ParseTextCommand = 0;
	DWORD ChatWindowNode_c__sub_1009BB79 = 0;

#pragma endregion

#pragma region HTMLParser

	DWORD HTMLParser_c__HTMLParser_c = 0;
	DWORD HTMLParser_c__dHTMLParser_c = 0;
	DWORD HTMLParser_c__HTMLParser_c_copy = 0;
	DWORD HTMLParser_c__ExtractText = 0;

#pragma endregion

#pragma region LookAtIIR

	DWORD LookAtIIR_t__sub_10073E4D = 0;

#pragma endregion

#pragma region ResourceDatabase

	DWORD ResourceDatabase_t__GetDbObject_1 = 0;
	DWORD ResourceDatabase_t__GetIdentityVec = 0;

#pragma endregion

#pragma region n3DatabaseController

	DWORD n3DatabaseHandler_t__s_pcInstance = 0;
	DatabaseHandler** ppDatabaseHandler = nullptr;

#pragma endregion

#pragma region GraphPathFinder

	DWORD GraphPathFinder_t__GraphPathFinder_t = 0;
	DWORD GraphPathFinder_t__GraphPathFinder_t_Copy = 0;
	DWORD GraphPathFinder_t__dGraphPathFinder_t = 0;
	DWORD GraphPathFinder_t__Configure = 0;
	DWORD GraphPathFinder_t__CreateFromData = 0;
	DWORD GraphPathFinder_t__FindPath = 0;
	DWORD GraphPathFinder_t__GenerateGraph = 0;
	DWORD GraphPathFinder_t__GenerateGraphForRoom = 0;
	DWORD GraphPathFinder_t__Init = 0;
	DWORD GraphPathFinder_t__SetSpaceForGraph = 0;
	DWORD GraphPathFinder_t__SetSurface = 0;

#pragma endregion

	bool get_function_address(const std::vector<unsigned char>& data, const char* function_pattern, DWORD& module_base_address, DWORD& function_address, const char* function_offset_name)
	{
		function_address = find_pattern(data, function_pattern, module_base_address);
		if (function_address == DWORD(-1))
		{
			printf("Cannot find %s function address using pattern matching.", function_offset_name);
			return false;
		}
		return true;
	}

	bool get_static_address_from_function(const DWORD& function_base_address, DWORD& static_address, const char* static_address_name, const size_t& offset)
	{
		if (function_base_address == DWORD(-1))
		{
			return false;
		}
		try
		{
			static_address = *reinterpret_cast<DWORD*>(function_base_address + offset);
		}
		catch (exception&)
		{
			printf("Cannot read pointer to get offset for %s static address.", static_address_name);
			return false;
		}
		return true;
	}

	bool get_relative_address_from_function(const DWORD& function_base_address, DWORD& relative_address, const char* relative_address_name, const size_t& offset, const size_t& bytes_to_next_line)
	{
		if (function_base_address == uint32_t(-1))
		{
			return false;
		}
		size_t base_offset = 0;
		try
		{
			base_offset = *reinterpret_cast<DWORD*>(function_base_address + offset);
		}
		catch (exception&)
		{
			printf("Cannot read pointer to get offset for %s static address.", relative_address_name);
		}
		relative_address = function_base_address + offset + bytes_to_next_line + base_offset + sizeof(DWORD*);
		return true;
	}

	bool get_proc_address(const HMODULE& module_handle, DWORD& function_address, const char* function_name, const char* mangled_function_name)
	{
		if (module_handle == nullptr)
		{
			return false;
		}
		function_address = DWORD(GetProcAddress(module_handle, mangled_function_name));
		if (function_address == 0)
		{
			printf("Cannot find %s function address using GetProcAddress.", function_name);
			return false;
		}
		return true;
	}

}
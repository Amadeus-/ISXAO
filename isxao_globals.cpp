#include "isxao_main.h"

#define GET_FUNCTION_ADDRESS(module, function_address) get_function_address((module##_data), (function_address##_pattern), (module##_module_base), (function_address), #function_address); // NOLINT(cppcoreguidelines-macro-usage)
#define GET_ADDRESS_FROM_FUNCTION_OFFSET(function_base, static_address) get_static_address_from_function((function_base), (static_address), #static_address, (static_address##_offset));  // NOLINT(cppcoreguidelines-macro-usage)
#define GET_RELATIVE_ADDRESS_FROM_FUNCTION_OFFSET(function_base, relative_address) get_relative_address_from_function((function_base), (relative_address), #relative_address, (relative_address##_offset), (relative_address##_bytes_to_next));  // NOLINT(cppcoreguidelines-macro-usage)
#define GET_PROC_ADDRESS(module, function_address) get_proc_address((module##_module_handle), (function_address), #function_address, (function_address##_mangled_name));  // NOLINT(cppcoreguidelines-macro-usage)
#define RESOLVE_FUNCTION_ADDRESS(module, function_address, ...) resolve_function_address(module##_data, module##_module_handle, (function_address), #function_address, function_address##_mangled_name, function_address##_pattern, function_address##_offset, function_address##_bytes_to_next, __VA_ARGS__);  // NOLINT(cppcoreguidelines-macro-usage)
#define RESOLVE_STATIC_INSTANCE_ADDRESS(module, static_address, ...) resolve_static_instance_address(module##_module_handle, (static_address), #static_address, static_address##_mangled_name, static_address##_offset, __VA_ARGS__);	// NOLINT(cppcoreguidelines-macro-usage)

namespace isxao
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
	HMODULE pathfinder_module_handle = GetModuleHandle(pathfinder_module_name);
	MODULEINFO pathfinder_module_info;
	HMODULE message_protocol_module_handle = GetModuleHandle(message_protocol_module_name);
	MODULEINFO message_protocol_module_info;
	DWORD hDatabaseController = DWORD(GetModuleHandle("DatabaseController.dll"));

	

#pragma endregion
	
#pragma region Process

	HANDLE process_handle = nullptr;

#pragma endregion

#pragma region N3

	// Functions
	DWORD n3_camera_t__set_secondary_target = 0;
	DWORD n3_camera_t__set_selected_target = 0;	

	// Functions
	DWORD n3_dynel_t__n3_dynel_t = 0;
	DWORD n3_dynel_t__d_n3_dynel_t = 0;
	DWORD n3_dynel_t__get_dynel = 0;
	DWORD n3_dynel_t__is_dynel_in_engine = 0;
	DWORD n3_dynel_t__send_iir_to_observers = 0;
	DWORD n3_dynel_t__set_playfield = 0;
	DWORD n3_dynel_t__update_locality_listeners = 0;
	DWORD n3_dynel_t__update_where = 0;

	// Instances
	DWORD n3_dynel_t__m_pc_dynel_dir_instance = 0;
	ao::dynel_map_t **pp_dynel_dir = nullptr;

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
	DWORD n3_playfield_t__get_playfield_dynels_1 = 0;
	DWORD n3_playfield_t__get_playfield_dynels_2 = 0;
	DWORD n3_playfield_t__line_of_sight = 0;
	DWORD n3_playfield_t__remove_child = 0;

	// Instances
	DWORD n3_playfield_t__m_pc_playfield_dir_instance = 0;
	ao::playfield_dir** pp_playfield_dir = nullptr;

#pragma endregion

#pragma region Gamecode

	// Functions
	DWORD f_get_nano_item = 0;
	DWORD f_stat_to_string = 0;

	DWORD game_time_t__get_instance = 0;	

	DWORD item_manager_t__item_manager_t = 0;

	DWORD look_at_iir_t__look_at_iir_t = 0;

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
	DWORD n3_engine_client_anarchy_t__n3_msg_get_full_perk_map = 0;
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
	DWORD n3_engine_client_anarchy_t__n3_msg_get_team_member_list = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_has_perk = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_hide_against_opponent = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_attacking = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_battle_station = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_character_in_mech = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_character_morphed = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_dungeon = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_formula_ready = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_general_perk = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_group_perk = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_in_raid_team = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_in_team = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_item_disabled = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_item_mine = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_item_nf_crystal = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_item_possible_to_un_wear = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_item_possible_to_wear = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_moving = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_my_pet_id = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_nano_self_only = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_npc = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_perk = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_is_pet_tower = 0;
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
	DWORD n3_engine_client_anarchy_t__n3_msg_name_to_id = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatAddTradeItem = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatCloseWindow = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatEndTrade = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatRemoveTradeItem = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatRequestDescription = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatStartTrade = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_OrbitalAttack = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_perform_special_action_1 = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_perform_special_action_2 = 0;

	DWORD n3_engine_client_anarchy_t__n3_msg_request_info_packet = 0;

	DWORD n3_engine_client_anarchy_t__n3_msg_send_pet_command = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_stop_attack = 0;
	DWORD n3_engine_client_anarchy_t__n3_msg_use_item = 0;
	DWORD n3_engine_client_anarchy_t__on_closed = 0;
	
	DWORD playfield_anarchy_t__playfield_anarchy_t = 0;
	DWORD playfield_anarchy_t__d_playfield_anarchy_t = 0;

	DWORD simple_char_t__check_los = 0;

	DWORD static_item_manager_t__static_item_manager_t = 0;

	// Instances
	DWORD game_time_t__m_pc_instance = 0;
	ao::game_time** pp_game_time = nullptr;
	DWORD n3_engine_client_anarchy_t__m_pc_instance = 0;
	ao::engine_client_anarchy **pp_engine_client_anarchy = nullptr;
	DWORD m_c_stat_name_dir = 0;
	ao::stat_name_map_t* p_stat_name_dir = nullptr;
	DWORD m_c_nano_item_dir = 0;
	ao::nano_item_map_t* p_nano_item_dir = nullptr;
	DWORD item_manager_t__m_ppc_instance = 0;
	std::vector<ao::acg_game_item_t> ***ppp_item_vector = nullptr;
	DWORD static_item_manager_t__m_ppc_instance = 0;
	std::vector<ao::static_item_t> ***ppp_static_item_vector = nullptr;

#pragma endregion

#pragma region GUI
	
	DWORD chat_gui_module_c__chat_gui_module_c = 0;
	DWORD chat_gui_module_c__handle_group_action = 0;
	DWORD chat_gui_module_c__handle_group_message = 0;
	DWORD chat_gui_module_c__handle_private_group_action = 0;
	DWORD chat_gui_module_c__handle_private_message = 0;
	DWORD chat_gui_module_c__handle_system_message = 0;
	DWORD chat_gui_module_c__handle_vicinity_message = 0;
	DWORD chat_gui_module_c__s_pc_instance = 0;
	ao::chat_gui_module** pp_chat_gui_module = nullptr;

	DWORD chat_window_node_c__parse_text_command = 0;

	DWORD command_interpreter_c__command_interpreter_c = 0;

	DWORD html_parser_c__html_parser_c_1 = 0;
	DWORD html_parser_c__html_parser_c_2 = 0;
	DWORD html_parser_c__d_html_parser_c = 0;	
	DWORD html_parser_c__extract_text = 0;

	DWORD input_config_t__m_pc_instance = 0;
	ao::input_config** pp_input_config = nullptr;
	DWORD input_config_t__get_instance = 0;
	DWORD input_config_t__set_current_target = 0;

	DWORD targeting_module_t__initialise_message = 0;
	DWORD targeting_module_t__targeting_module_t = 0;
	DWORD targeting_module_t__set_target = 0;
	DWORD targeting_module_t__remove_target = 0;
	DWORD targeting_module_t__select_self = 0;
	DWORD targeting_module_t__set_target_pet = 0;
	DWORD targeting_module_t__m_pc_instance = 0;
	ao::targeting_module** pp_targeting_module = nullptr;
	DWORD targeting_module_t__m_pc_selection_indicator = 0;
	ao::indicator_t** pp_selection_indicator = nullptr;
	DWORD targeting_module_t__m_pc_attacking_indicator = 0;
	ao::indicator_t** pp_attacking_indicator = nullptr;
	DWORD targeting_module_t__m_c_last_target = 0;
	ao::identity_t* p_last_target = nullptr;	

#pragma endregion

#pragma region Interfaces

	DWORD client_t__s_n_char_id = 0;
	PDWORD gp_character_id = nullptr;
	DWORD client_t__process_message = 0;

#pragma endregion

#pragma region Vehicle

	DWORD vehicle_t__set_rel_rot = 0;

#pragma endregion

#pragma region Pathfinder

	DWORD graph_path_finder_t__graph_path_finder_t_1 = 0;
	DWORD graph_path_finder_t__graph_path_finder_t_2 = 0;
	DWORD graph_path_finder_t__d_graph_path_finder_t = 0;
	DWORD graph_path_finder_t__configure = 0;
	DWORD graph_path_finder_t__create_from_data = 0;
	DWORD graph_path_finder_t__find_path = 0;
	DWORD graph_path_finder_t__generate_graph = 0;
	DWORD graph_path_finder_t__generate_graph_for_room = 0;
	DWORD graph_path_finder_t__init = 0;
	DWORD graph_path_finder_t__set_space_for_graph = 0;
	DWORD graph_path_finder_t__set_surface = 0;

#pragma endregion

#pragma region MessageProtocol

	DWORD message_t__data_block_size_get = 0;
	DWORD message_t__dest_id_get = 0;
	DWORD message_t__header_size = 0;
	DWORD message_t__message_size_get = 0;
	DWORD message_t__message_type_get = 0;
	DWORD message_t__priority_get = 0;
	DWORD message_t__source_id_get = 0;

	DWORD n3_message_t__duplicate_body = 0;
	DWORD n3_message_t__message_body_get = 0;

	DWORD text_message_t__message_body_get = 0;
	DWORD text_message_t__message_body_len = 0;

#pragma endregion

#pragma region EngineClientAnarchy	
	
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

#pragma region Logger

	isxao_log* gp_isxao_log = nullptr;

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
	ao::login_module_t** ppLoginModule = nullptr;

#pragma endregion

#pragma region ChatWindowController

	DWORD ChatWindowController_c__m_pcInstance = 0;
	ao::chat_window_controller** ppChatWindowController = nullptr;

	DWORD ChatGroupController_c__sub_10083D9C = 0;

#pragma endregion

#pragma region FriendListController

	DWORD FriendListController_c__sub_100A68E6 = 0;

#pragma endregion

#pragma region CommandInterpreter

	DWORD command_interpreter_c__m_pc_instance = 0;
	ao::command_interpreter** pp_command_interpreter = nullptr;
	DWORD command_interpreter_c__parse_text_command = 0;

#pragma endregion

#pragma region ChatWindowNode

	
	DWORD ChatWindowNode_c__sub_1009BB79 = 0;

#pragma endregion

#pragma region HTMLParser

	

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
	ao::database_handler** ppDatabaseHandler = nullptr;

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
		if (!pathfinder_module_handle)
		{
			printf("Could not find handle to module \"Pathfinder.dll\". Aborting offset initialization.");
			return false;
		}
		if (!message_protocol_module_handle)
		{
			printf("Could not find handle to module \"MessageProtocol.dll\". Aborting offset initialization.");
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
		const std::vector<unsigned char> n3_data(n3_data_begin, n3_data_end);

		// Functions
		RESOLVE_FUNCTION_ADDRESS(n3, n3_camera_t__set_secondary_target)
		RESOLVE_FUNCTION_ADDRESS(n3, n3_camera_t__set_selected_target)
		RESOLVE_FUNCTION_ADDRESS(n3, n3_dynel_t__n3_dynel_t)
		RESOLVE_FUNCTION_ADDRESS(n3, n3_dynel_t__d_n3_dynel_t)
		RESOLVE_FUNCTION_ADDRESS(n3, n3_dynel_t__get_dynel)
		RESOLVE_FUNCTION_ADDRESS(n3, n3_dynel_t__send_iir_to_observers)
		RESOLVE_FUNCTION_ADDRESS(n3, n3_dynel_t__set_playfield)
		RESOLVE_FUNCTION_ADDRESS(n3, n3_dynel_t__update_where)
		RESOLVE_FUNCTION_ADDRESS(n3, n3_engine_t__n3_engine_t)
		RESOLVE_FUNCTION_ADDRESS(n3, n3_playfield_t__add_child_dynel)
		RESOLVE_FUNCTION_ADDRESS(n3, n3_playfield_t__get_playfield_1)
		RESOLVE_FUNCTION_ADDRESS(n3, n3_playfield_t__get_playfield_2)
		RESOLVE_FUNCTION_ADDRESS(n3, n3_playfield_t__get_playfield_3)
		RESOLVE_FUNCTION_ADDRESS(n3, n3_playfield_t__line_of_sight)
		RESOLVE_FUNCTION_ADDRESS(n3, n3_playfield_t__remove_child)

		RESOLVE_FUNCTION_ADDRESS(n3, n3_dynel_t__update_locality_listeners, n3_dynel_t__update_where)	// Depends on n3_dynel_t__update_where
		RESOLVE_FUNCTION_ADDRESS(n3, n3_engine_client_t__get_client_control_dynel, n3_camera_t__set_selected_target)	// Depends on n3_camera_t__set_selected_target

		// Instances
		RESOLVE_STATIC_INSTANCE_ADDRESS(n3, n3_dynel_t__m_pc_dynel_dir_instance, n3_dynel_t__get_dynel)
		pp_dynel_dir = reinterpret_cast<ao::dynel_map_t**>(n3_dynel_t__m_pc_dynel_dir_instance);

		RESOLVE_STATIC_INSTANCE_ADDRESS(n3, n3_engine_t__m_pc_instance, n3_engine_t__n3_engine_t)	// Used with Gamecode to get n3_engine_client_anarchy_t__m_pc_instance

		RESOLVE_STATIC_INSTANCE_ADDRESS(n3, n3_playfield_t__m_pc_playfield_dir_instance, n3_playfield_t__get_playfield_2)
		pp_playfield_dir = reinterpret_cast<ao::playfield_dir**>(n3_playfield_t__m_pc_playfield_dir_instance);

#pragma endregion

#pragma region Gamecode

		// Module
		GetModuleInformation(process_handle, gamecode_module_handle, &gamecode_module_info, sizeof(gamecode_module_info));
		// ReSharper disable once CppLocalVariableMayBeConst
		auto gamecode_module_base = DWORD(gamecode_module_handle);
		const auto gamecode_data_begin = reinterpret_cast<unsigned char*>(gamecode_module_base);
		const auto gamecode_data_end = gamecode_data_begin + gamecode_module_info.SizeOfImage;
		const std::vector<unsigned char> gamecode_data(gamecode_data_begin, gamecode_data_end);

		// Functions
		RESOLVE_FUNCTION_ADDRESS(gamecode, f_get_nano_item)
		RESOLVE_FUNCTION_ADDRESS(gamecode, f_stat_to_string)
		RESOLVE_FUNCTION_ADDRESS(gamecode, game_time_t__get_instance)		
		RESOLVE_FUNCTION_ADDRESS(gamecode, look_at_iir_t__look_at_iir_t)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_engine_client_anarchy_t)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__convert_criteria)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_client_char)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_client_dynel_id)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_current_movement_mode)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_faction_str)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_faction_title)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_gender_string)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_item_by_template)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_title_str)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__is_first_login)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__is_fixture)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_activate_mech)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_airstrike)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_artillery_attack)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_assist_fight)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_can_attack)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_can_click_target_target)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_can_use_mech)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_cast_nano_spell)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_consider)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_container_add_item)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_crawl_toggle)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_create_raid)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_default_action_on_dynel)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_default_attack)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_delete_item)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_delete_nano)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_do_social_action)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_drop_item)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_duel_accept)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_duel_challenge)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_duel_draw)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_duel_refuse)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_duel_stop)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_forage)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_action_by_name)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_action_progress)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_agg_def)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_alien_level_string)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_area_name)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_attacking_id)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_breed_str)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_buff_current_time)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_buff_total_time)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_character_body_shape)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_char_orientation_data)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_city_name_for_clan_member)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_clan_level_string)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_clan_string)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_client_pet_id)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_close_target)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_container_inventory_list)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_correct_action_id)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_current_room)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_current_room_name)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_district_fight_mode)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_dynels_in_vicinity)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_faction_info_string)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_faction_range)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_first_name)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_formula_progress)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_formula_radius)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_full_perk_map)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_global_character_position)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_global_character_rotation)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_1)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_2)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_inventory_vec)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_item)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_item_progress)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_movement_mode)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_name)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_nano_cost_modifier)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_1)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_2)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_next_target)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_number_of_available_alien_perks)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_number_of_available_perks)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_number_of_free_inventory_slots)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_number_of_used_alien_perks)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_number_of_used_perks)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_over_equip_level)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_pf_name_1)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_pf_name_2)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_parent)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_pos)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_skill_1)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_skill_2)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_skill_max)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_special_action_list)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_special_action_state)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_special_attack_weapon_name)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_stat_name_map)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_target_target)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_team_member_list)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_has_perk)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_hide_against_opponent)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_attacking)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_battle_station)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_character_in_mech)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_character_morphed)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_dungeon)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_formula_ready)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_general_perk)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_group_perk)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_in_raid_team)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_in_team)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_item_disabled)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_item_mine)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_item_nf_crystal)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_item_possible_to_un_wear)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_item_possible_to_wear)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_moving)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_my_pet_id)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_nano_self_only)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_npc)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_perk)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_is_pet_tower)

		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_name_to_id)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_perform_special_action_1)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_perform_special_action_2)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_request_info_packet)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_send_pet_command)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_stop_attack)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_use_item)
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__on_closed)
		RESOLVE_FUNCTION_ADDRESS(gamecode, playfield_anarchy_t__playfield_anarchy_t)
		RESOLVE_FUNCTION_ADDRESS(gamecode, playfield_anarchy_t__d_playfield_anarchy_t)
		RESOLVE_FUNCTION_ADDRESS(gamecode, simple_char_t__check_los)

		RESOLVE_FUNCTION_ADDRESS(gamecode, item_manager_t__item_manager_t, n3_engine_client_anarchy_t__get_item_by_template) // Depends on n3_engine_client_anarchy_t__get_item_by_template
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_breed_str, n3_engine_client_anarchy_t__convert_criteria) // Depends on n3_engine_client_anarchy_t__convert_criteria
		RESOLVE_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_sex_str, n3_engine_client_anarchy_t__convert_criteria) // Depends on n3_engine_client_anarchy_t__convert_criteria
		RESOLVE_FUNCTION_ADDRESS(gamecode, static_item_manager_t__static_item_manager_t, n3_engine_client_anarchy_t__get_item_by_template) // Depends on n3_engine_client_anarchy_t__get_item_by_template

		// Instances
		n3_engine_client_anarchy_t__m_pc_instance = n3_engine_t__m_pc_instance;	// Depends on n3_engine_t__m_pc_instance
		pp_engine_client_anarchy = reinterpret_cast<ao::engine_client_anarchy**>(n3_engine_client_anarchy_t__m_pc_instance);

		RESOLVE_STATIC_INSTANCE_ADDRESS(gamecode, game_time_t__m_pc_instance, game_time_t__get_instance) // Depends on game_time_t__get_instance
		pp_game_time = reinterpret_cast<ao::game_time**>(game_time_t__m_pc_instance);

		RESOLVE_STATIC_INSTANCE_ADDRESS(gamecode, m_c_nano_item_dir, f_get_nano_item) // Depends on f_get_nano_item
		p_nano_item_dir = reinterpret_cast<ao::nano_item_map_t*>(m_c_nano_item_dir);

		RESOLVE_STATIC_INSTANCE_ADDRESS(gamecode, m_c_stat_name_dir, f_stat_to_string) // Depends on f_stat_to_string
		p_stat_name_dir = reinterpret_cast<ao::stat_name_map_t*>(m_c_stat_name_dir);

		RESOLVE_STATIC_INSTANCE_ADDRESS(gamecode, item_manager_t__m_ppc_instance, item_manager_t__item_manager_t) // Depends on item_manager_t__item_manager_t
		ppp_item_vector = reinterpret_cast<std::vector<ao::acg_game_item_t> ***>(item_manager_t__m_ppc_instance);

		RESOLVE_STATIC_INSTANCE_ADDRESS(gamecode, static_item_manager_t__m_ppc_instance, static_item_manager_t__static_item_manager_t) // Depends on static_item_manager_t__static_item_manager_t
		ppp_static_item_vector = reinterpret_cast<std::vector<ao::static_item_t>***>(static_item_manager_t__m_ppc_instance);
		
#pragma endregion

#pragma region GUI

		// Module
		GetModuleInformation(process_handle, gui_module_handle, &gui_module_info, sizeof(gui_module_info));
		// ReSharper disable once CppLocalVariableMayBeConst
		auto gui_module_base = DWORD(gui_module_handle);
		const auto gui_data_begin = reinterpret_cast<unsigned char*>(gui_module_base);
		const auto gui_data_end = gui_data_begin + gui_module_info.SizeOfImage;
		const std::vector<unsigned char> gui_data(gui_data_begin, gui_data_end);

		// Functions
		RESOLVE_FUNCTION_ADDRESS(gui, chat_gui_module_c__chat_gui_module_c)
		RESOLVE_FUNCTION_ADDRESS(gui, chat_gui_module_c__handle_group_action)
		RESOLVE_FUNCTION_ADDRESS(gui, chat_gui_module_c__handle_group_message)
		RESOLVE_FUNCTION_ADDRESS(gui, chat_gui_module_c__handle_private_group_action)
		RESOLVE_FUNCTION_ADDRESS(gui, chat_gui_module_c__handle_private_message)
		RESOLVE_FUNCTION_ADDRESS(gui, chat_gui_module_c__handle_system_message)
		RESOLVE_FUNCTION_ADDRESS(gui, chat_gui_module_c__handle_vicinity_message)
		RESOLVE_FUNCTION_ADDRESS(gui, chat_window_node_c__parse_text_command)
		RESOLVE_FUNCTION_ADDRESS(gui, command_interpreter_c__command_interpreter_c)
		RESOLVE_FUNCTION_ADDRESS(gui, command_interpreter_c__parse_text_command)
		RESOLVE_FUNCTION_ADDRESS(gui, html_parser_c__html_parser_c_1)
		RESOLVE_FUNCTION_ADDRESS(gui, html_parser_c__html_parser_c_2)
		RESOLVE_FUNCTION_ADDRESS(gui, html_parser_c__d_html_parser_c)
		RESOLVE_FUNCTION_ADDRESS(gui, html_parser_c__extract_text)
		RESOLVE_FUNCTION_ADDRESS(gui, input_config_t__get_instance)
		RESOLVE_FUNCTION_ADDRESS(gui, input_config_t__set_current_target)
		RESOLVE_FUNCTION_ADDRESS(gui, targeting_module_t__initialise_message)
		RESOLVE_FUNCTION_ADDRESS(gui, targeting_module_t__remove_target)
		RESOLVE_FUNCTION_ADDRESS(gui, targeting_module_t__select_self)
		RESOLVE_FUNCTION_ADDRESS(gui, targeting_module_t__set_target)
		RESOLVE_FUNCTION_ADDRESS(gui, targeting_module_t__set_target_pet)
		RESOLVE_FUNCTION_ADDRESS(gui, targeting_module_t__targeting_module_t)

		// Instances
		RESOLVE_STATIC_INSTANCE_ADDRESS(gui, chat_gui_module_c__s_pc_instance, chat_gui_module_c__chat_gui_module_c)
		pp_chat_gui_module = reinterpret_cast<ao::chat_gui_module**>(chat_gui_module_c__s_pc_instance);

		RESOLVE_STATIC_INSTANCE_ADDRESS(gui, command_interpreter_c__m_pc_instance, command_interpreter_c__command_interpreter_c)
		pp_command_interpreter = reinterpret_cast<ao::command_interpreter**>(command_interpreter_c__m_pc_instance);

		RESOLVE_STATIC_INSTANCE_ADDRESS(gui, input_config_t__m_pc_instance, input_config_t__get_instance)	// Depends on input_config_t__get_instance
		pp_input_config = reinterpret_cast<ao::input_config**>(input_config_t__m_pc_instance);

		RESOLVE_STATIC_INSTANCE_ADDRESS(gui, targeting_module_t__m_pc_instance, targeting_module_t__set_target) // Depends on targeting_module_t__set_target
		pp_targeting_module = reinterpret_cast<ao::targeting_module**>(targeting_module_t__m_pc_instance);

		RESOLVE_STATIC_INSTANCE_ADDRESS(gui, targeting_module_t__m_pc_selection_indicator, targeting_module_t__initialise_message)	// Depends on targeting_module_t__initialise_message
		pp_selection_indicator = reinterpret_cast<ao::indicator_t**>(targeting_module_t__m_pc_selection_indicator);

		RESOLVE_STATIC_INSTANCE_ADDRESS(gui, targeting_module_t__m_pc_attacking_indicator, targeting_module_t__initialise_message) // Depends on targeting_module_t__initialise_message
		pp_attacking_indicator = reinterpret_cast<ao::indicator_t**>(targeting_module_t__m_pc_attacking_indicator);

		RESOLVE_STATIC_INSTANCE_ADDRESS(gui, targeting_module_t__m_c_last_target, targeting_module_t__initialise_message)	// Depends on targeting_module_t__initialise_message
		p_last_target = reinterpret_cast<ao::identity_t*>(targeting_module_t__m_c_last_target);

#pragma endregion

#pragma region Interfaces

			// Module
			GetModuleInformation(process_handle, interfaces_module_handle, &interfaces_module_info, sizeof(interfaces_module_info));
		// ReSharper disable once CppLocalVariableMayBeConst
		auto interfaces_module_base = DWORD(interfaces_module_handle);
		const auto interfaces_data_begin = reinterpret_cast<unsigned char*>(interfaces_module_base);
		const auto interfaces_data_end = interfaces_data_begin + interfaces_module_info.SizeOfImage;
		const std::vector<unsigned char> interfaces_data(interfaces_data_begin, interfaces_data_end);

		// Instances
#ifdef CLIENT_T__S_N_CHAR_ID_USE_PATTERN
		static_assert(false, "client_t__s_n_char_id cannot be found with a pattern.");
#else
		GET_PROC_ADDRESS(interfaces, client_t__s_n_char_id)
#endif
		gp_character_id = reinterpret_cast<DWORD*>(client_t__s_n_char_id);

#ifdef CLIENT_T__PROCESS_MESSAGE_USE_PATTERN
		GET_FUNCTION_ADDRESS(interfaces, client_t__process_message)
#else
		GET_PROC_ADDRESS(interfaces, client_t__process_message)
#endif

#pragma endregion

#pragma region Vehicle

		// Module
		GetModuleInformation(process_handle, vehicle_module_handle, &vehicle_module_info, sizeof(vehicle_module_info));
		// ReSharper disable once CppLocalVariableMayBeConst
		auto vehicle_module_base = DWORD(vehicle_module_handle);
		const auto vehicle_data_begin = reinterpret_cast<unsigned char*>(vehicle_module_base);
		const auto vehicle_data_end = vehicle_data_begin + vehicle_module_info.SizeOfImage;
		const std::vector<unsigned char> vehicle_data(vehicle_data_begin, vehicle_data_end);

#ifdef VEHICLE_T__SET_REL_ROT_USE_PATTERN
		GET_FUNCTION_ADDRESS(vehicle, vehicle_t__set_rel_rot)
#else
		GET_PROC_ADDRESS(vehicle, vehicle_t__set_rel_rot)
#endif


#pragma endregion

#pragma region Pathfinder

		// Module
		GetModuleInformation(process_handle, pathfinder_module_handle, &pathfinder_module_info, sizeof(pathfinder_module_info));
		// ReSharper disable once CppLocalVariableMayBeConst
		auto pathfinder_module_base = DWORD(pathfinder_module_handle);
		const auto pathfinder_data_begin = reinterpret_cast<unsigned char*>(pathfinder_module_base);
		const auto pathfinder_data_end = pathfinder_data_begin + pathfinder_module_info.SizeOfImage;
		const std::vector<unsigned char> pathfinder_data(pathfinder_data_begin, pathfinder_data_end);

		//Functions
#ifdef GRAPH_PATH_FINDER_T__GRAPH_PATH_FINDER_T_1_USE_PATTERN
		GET_FUNCTION_ADDRESS(pathfinder, graph_path_finder_t__graph_path_finder_t_1)
#else
		GET_PROC_ADDRESS(pathfinder, graph_path_finder_t__graph_path_finder_t_1)
#endif

#ifdef GRAPH_PATH_FINDER_T__GRAPH_PATH_FINDER_T_2_USE_PATTERN
		GET_FUNCTION_ADDRESS(pathfinder, graph_path_finder_t__graph_path_finder_t_2)
#else
		GET_PROC_ADDRESS(pathfinder, graph_path_finder_t__graph_path_finder_t_2)
#endif

#ifdef GRAPH_PATH_FINDER_T__D_GRAPH_PATH_FINDER_T_USE_PATTERN
		GET_FUNCTION_ADDRESS(pathfinder, graph_path_finder_t__d_graph_path_finder_t)
#else
		GET_PROC_ADDRESS(pathfinder, graph_path_finder_t__d_graph_path_finder_t)
#endif

#ifdef GRAPH_PATH_FINDER_T__CONFIGURE_USE_PATTERN
		GET_FUNCTION_ADDRESS(pathfinder, graph_path_finder_t__configure)
#else
		GET_PROC_ADDRESS(pathfinder, graph_path_finder_t__configure)
#endif

#ifdef GRAPH_PATH_FINDER_T__CREATE_FROM_DATA_USE_PATTERN
		static_assert(false, "graph_path_finder::create_from_data(PVOID) cannot be found with a pattern.");
#else
		GET_PROC_ADDRESS(pathfinder, graph_path_finder_t__create_from_data)
#endif

#ifdef GRAPH_PATH_FINDER_T__FIND_PATH_USE_PATTERN
		GET_FUNCTION_ADDRESS(pathfinder, graph_path_finder_t__find_path)
#else
		GET_PROC_ADDRESS(pathfinder, graph_path_finder_t__find_path)
#endif

#ifdef GRAPH_PATH_FINDER_T__GENERATE_GRAPH_USE_PATTERN
		GET_FUNCTION_ADDRESS(pathfinder, graph_path_finder_t__generate_graph)
#else
		GET_PROC_ADDRESS(pathfinder, graph_path_finder_t__generate_graph)
#endif

#ifdef GRAPH_PATH_FINDER_T__GENERATE_GRAPH_FOR_ROOM_USE_PATTERN
		GET_FUNCTION_ADDRESS(pathfinder, graph_path_finder_t__generate_graph_for_room)
#else
		GET_PROC_ADDRESS(pathfinder, graph_path_finder_t__generate_graph_for_room)
#endif

#ifdef GRAPH_PATH_FINDER_T__INIT_USE_PATTERN
		GET_FUNCTION_ADDRESS(pathfinder, graph_path_finder_t__init)
#else
		GET_PROC_ADDRESS(pathfinder, graph_path_finder_t__init)
#endif

#ifdef GRAPH_PATH_FINDER_T__SET_SPACE_FOR_GRAPH_USE_PATTERN
		GET_FUNCTION_ADDRESS(pathfinder, graph_path_finder_t__set_space_for_graph)
#else
		GET_PROC_ADDRESS(pathfinder, graph_path_finder_t__set_space_for_graph)
#endif

#ifdef GRAPH_PATH_FINDER_T__SET_SURFACE_USE_PATTERN
		GET_FUNCTION_ADDRESS(pathfinder, graph_path_finder_t__set_surface)
#else
		GET_PROC_ADDRESS(pathfinder, graph_path_finder_t__set_surface)
#endif

#pragma endregion

#pragma region MessageProtocol

		// Module
		GetModuleInformation(process_handle, message_protocol_module_handle, &message_protocol_module_info, sizeof(message_protocol_module_info));
		// ReSharper disable once CppLocalVariableMayBeConst
		auto message_protocol_module_base = DWORD(message_protocol_module_handle);
		const auto message_protocol_data_begin = reinterpret_cast<unsigned char*>(message_protocol_module_base);
		const auto message_protocol_data_end = message_protocol_data_begin + message_protocol_module_info.SizeOfImage;
		const std::vector<unsigned char> message_protocol_data(message_protocol_data_begin, message_protocol_data_end);

		// Functions
#ifdef MESSAGE_T__DATA_BLOCK_SIZE_GET_USE_PATTERN
		GET_FUNCTION_ADDRESS(message_protocol, message_t__data_block_size_get)
#else
		GET_PROC_ADDRESS(message_protocol, message_t__data_block_size_get)
#endif

#ifdef MESSAGE_T__DEST_ID_GET_USE_PATTERN
		GET_FUNCTION_ADDRESS(message_protocol, message_t__dest_id_get)
#else
		GET_PROC_ADDRESS(message_protocol, message_t__dest_id_get)
#endif

#ifdef MESSAGE_T__HEADER_SIZE_USE_PATTERN
		GET_FUNCTION_ADDRESS(message_protocol, message_t__header_size)
#else
		GET_PROC_ADDRESS(message_protocol, message_t__header_size)
#endif

#ifdef MESSAGE_T__MESSAGE_SIZE_GET_USE_PATTERN
		GET_FUNCTION_ADDRESS(message_protocol, message_t__message_size_get)
#else
		GET_PROC_ADDRESS(message_protocol, message_t__message_size_get)
#endif

#ifdef MESSAGE_T__MESSAGE_TYPE_GET_USE_PATTERN
		GET_FUNCTION_ADDRESS(message_protocol, message_t__message_type_get)
#else
		GET_PROC_ADDRESS(message_protocol, message_t__message_type_get)
#endif

#ifdef MESSAGE_T__PRIORITY_GET_USE_PATTERN
		GET_FUNCTION_ADDRESS(message_protocol, message_t__priority_get)
#else
		GET_PROC_ADDRESS(message_protocol, message_t__priority_get)
#endif

#ifdef MESSAGE_T__SOURCE_ID_GET_USE_PATTERN
		GET_FUNCTION_ADDRESS(message_protocol, message_t__source_id_get)
#else
		GET_PROC_ADDRESS(message_protocol, message_t__source_id_get)
#endif

#ifdef N3_MESSAGE_T__DUPLICATE_BODY_USE_PATTERN
		static_assert(false, "n3_message::duplicate_body() cannot be found with a pattern.");
#else
		GET_PROC_ADDRESS(message_protocol, n3_message_t__duplicate_body)
#endif

#ifdef N3_MESSAGE_T__MESSAGE_BODY_GET_USE_PATTERN
		GET_FUNCTION_ADDRESS(message_protocol, n3_message_t__message_body_get)
#else
		GET_PROC_ADDRESS(message_protocol, n3_message_t__message_body_get)
#endif

#ifdef TEXT_MESSAGE_T__MESSAGE_BODY_GET_USE_PATTERN
		GET_FUNCTION_ADDRESS(message_protocol, text_message_t__message_body_get)
#else
		GET_PROC_ADDRESS(message_protocol, text_message_t__message_body_get)
#endif

#ifdef TEXT_MESSAGE_T__MESSAGE_BODY_LEN_USE_PATTERN
		GET_FUNCTION_ADDRESS(message_protocol, text_message_t__message_body_len)
#else
		GET_PROC_ADDRESS(message_protocol, text_message_t__message_body_len)
#endif

#pragma endregion

			return true;
	}

	bool get_function_address(const std::vector<unsigned char>& data, const char* function_pattern, DWORD& module_base_address, DWORD& function_address, const char* function_offset_name)
	{
		function_address = find_pattern(data, function_pattern, module_base_address);
		if (function_address == DWORD(-1))
		{
			printf("[ERROR]\t%s could not be found using pattern matching.", function_offset_name);
			return false;
		}
		return true;
	}

	bool get_static_address_from_function(const DWORD& function_base_address, DWORD& static_address, const char* static_address_name, const size_t& offset)
	{
		if (function_base_address == DWORD(-1))
		{
			gp_isxao_log->add_line("[ERROR]\t%s could not be found because the base function address was invalid (0x%.8X).", static_address_name, function_base_address);
			printf("[ERROR]\t%s could not be found because the base function address was invalid (0x%.8X).", static_address_name, function_base_address);
			return false;
		}
		try
		{
			static_address = *reinterpret_cast<DWORD*>(function_base_address + offset);
		}
		catch (exception&)
		{
			gp_isxao_log->add_line("[ERROR]\t%s could not be found because we could not read the pointer to get address.", static_address_name);
			printf("[ERROR]\t%s could not be found because we could not read the pointer to get address.", static_address_name);
			return false;
		}
		return true;
	}

	bool get_relative_address_from_function(const DWORD& function_base_address, DWORD& relative_address, const char* relative_address_name, const size_t& offset, const size_t& bytes_to_next_line)
	{
		if (function_base_address == uint32_t(-1))
		{
			gp_isxao_log->add_line("[ERROR]\t%s could not be found because the base function address was invalid (0x%.8X).", relative_address_name, function_base_address);
			printf("[ERROR]\t%s could not be found because the base function address was invalid (0x%.8X).", relative_address_name, function_base_address);
			return false;
		}
		size_t base_offset = 0;
		try
		{
			base_offset = *reinterpret_cast<DWORD*>(function_base_address + offset);
		}
		catch (exception&)
		{
			gp_isxao_log->add_line("[ERROR]\t%s could not be found because we could not read the pointer to get address.", relative_address_name);
			printf("[ERROR]\t%s could not be found because we could not read the pointer to get address.", relative_address_name);
		}
		relative_address = function_base_address + offset + bytes_to_next_line + base_offset + sizeof(DWORD*);
		return true;
	}

	bool get_proc_address(const HMODULE& module_handle, DWORD& function_address, const char* function_name, const char* mangled_function_name)
	{
		if (module_handle == nullptr)
		{
			gp_isxao_log->add_line("[ERROR]\t%s could not be found because an invalid module handle was provided (0x%.8X)", function_name, module_handle);
			printf("[ERROR]\t%s could not be found because an invalid module handle was provided (0x%.8X)", function_name, module_handle);
			return false;
		}
		function_address = DWORD(GetProcAddress(module_handle, mangled_function_name));
		if (function_address == 0)
		{
			gp_isxao_log->add_line("[ERROR]\t%s could not be found using GetProcAddress", function_name);
			printf("[ERROR]\t%s could not be found using GetProcAddress", function_name);
			return false;
		}
		return true;
	}

	bool resolve_function_address(const std::vector<BYTE>& data, HMODULE& module_handle, DWORD& function_address, const char* function_address_name, const char* mangled_function_name, const char* function_pattern, DWORD offset, DWORD bytes_to_next_line, DWORD relative_function_base_address)
	{
		// If there a mangled function name was supplied, try to use get_proc_address to resolve it.
		if (mangled_function_name != nullptr && get_proc_address(module_handle, function_address, function_address_name, mangled_function_name))
		{
			gp_isxao_log->add_line("[0x%.8X]\t%s found using GetProcAddress.", function_address, function_address_name);
			return true;
		}
		// If there is not a mangled function name or GetProcAddress was unable to resolve the address and a pattern exists, use pattern matching to find the address.
		auto module_base_address = DWORD(module_handle);
		if (function_pattern != nullptr && get_function_address(data, function_pattern, module_base_address, function_address, function_address_name))
		{
			if (mangled_function_name == nullptr)
				gp_isxao_log->add_line("[0x%.8X]\t%s found using pattern matching.", function_address, function_address_name);
			else
				gp_isxao_log->add_line("[WARNING]\t[0x%.8X]\t%s found using pattern matching. Could not be found with GetProcAddress.", function_address, function_address_name);
			return true;
		}
		// If no pattern is present but a function base, offset, and bytes to next line are present, try to resolve the address as a relative offset
		if (relative_function_base_address != 0 && get_relative_address_from_function(relative_function_base_address, function_address, function_address_name, offset, bytes_to_next_line))
		{
			gp_isxao_log->add_line("[0x%.8X]\t%s found using a relative function offset.", function_address, function_address_name);
			return true;
		}
		gp_isxao_log->add_line("[ERROR]\t%s not found!", function_address_name);
		printf("[ERROR]\t%s not found!", function_address_name);
		return false;
	}

	bool resolve_static_instance_address(HMODULE& module_handle, DWORD& static_instance_address, const char* static_instance_name, const char* mangled_name, DWORD offset, DWORD relative_function_base_address)
	{
		if (mangled_name != nullptr && get_proc_address(module_handle, static_instance_address, static_instance_name, mangled_name))
		{
			gp_isxao_log->add_line("[0x%.8X]\t%s found using GetProcAddress.", static_instance_address, static_instance_name);
			return true;
		}
		if (relative_function_base_address != 0 && get_static_address_from_function(relative_function_base_address, static_instance_address, static_instance_name, offset))
		{
			if (mangled_name == nullptr)
				gp_isxao_log->add_line("[0x%.8X]\t%s found using a relative function offset.", static_instance_address, static_instance_name);
			else
				gp_isxao_log->add_line("[WARNING]\t[0x%.8X]\t%s found using a relative function offset. Could not be found with GetProcAddress", static_instance_address, static_instance_name);
			return true;
		}
		gp_isxao_log->add_line("[ERROR]\t%s not found!", static_instance_name);
		printf("[ERROR]\t%s not found!", static_instance_name);
		return false;
	}

}
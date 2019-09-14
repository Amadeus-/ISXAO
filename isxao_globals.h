
#ifndef ISXAO_GLOBALS_H
#define ISXAO_GLOBALS_H

namespace isxao_globals
{	

#pragma region Process

	AOLIB_VAR HANDLE process_handle;

#pragma endregion

#pragma region Modules

	AOLIB_VAR HMODULE gamecode_module_handle;
	AOLIB_VAR MODULEINFO gamecode_module_info;
	AOLIB_VAR HMODULE n3_module_handle;
	AOLIB_VAR MODULEINFO n3_module_info;
	AOLIB_VAR HMODULE gui_module_handle;
	AOLIB_VAR MODULEINFO gui_module_info;
	AOLIB_VAR HMODULE vehicle_module_handle;
	AOLIB_VAR MODULEINFO vehicle_module_info;	
	AOLIB_VAR HMODULE interfaces_module_handle;
	AOLIB_VAR MODULEINFO interfaces_module_info;
	AOLIB_VAR HMODULE pathfinder_module_handle;
	AOLIB_VAR MODULEINFO pathfinder_module_info;

#pragma endregion

#pragma region N3

	// Functions
	AOLIB_VAR DWORD n3_camera_t__set_secondary_target;
	AOLIB_VAR DWORD n3_camera_t__set_selected_target;	

	// Functions
	AOLIB_VAR DWORD n3_dynel_t__n3_dynel_t;
	AOLIB_VAR DWORD n3_dynel_t__d_n3_dynel_t;
	AOLIB_VAR DWORD n3_dynel_t__get_dynel;
	AOLIB_VAR DWORD n3_dynel_t__send_iir_to_observers;
	AOLIB_VAR DWORD n3_dynel_t__set_playfield;
	AOLIB_VAR DWORD n3_dynel_t__update_locality_listeners;
	AOLIB_VAR DWORD n3_dynel_t__update_where;

	// Instances
	AOLIB_VAR DWORD n3_dynel_t__m_pc_dynel_dir_instance;
	AOLIB_VAR dynel_map_t **pp_dynel_dir;
#define P_DYNEL_DIR (*pp_dynel_dir)  // NOLINT(cppcoreguidelines-macro-usage)

	// Functions
	AOLIB_VAR DWORD n3_engine_t__n3_engine_t;

	// Instances
	AOLIB_VAR DWORD n3_engine_t__m_pc_instance;

	// Functions
	AOLIB_VAR DWORD n3_engine_client_t__get_client_control_dynel;

	// Functions
	AOLIB_VAR DWORD n3_playfield_t__add_child_dynel;
	AOLIB_VAR DWORD n3_playfield_t__get_playfield_1;
	AOLIB_VAR DWORD n3_playfield_t__get_playfield_2;
	AOLIB_VAR DWORD n3_playfield_t__get_playfield_3;
	AOLIB_VAR DWORD n3_playfield_t__line_of_sight;
	AOLIB_VAR DWORD n3_playfield_t__remove_child;

	// Instances
	AOLIB_VAR DWORD n3_playfield_t__m_pc_playfield_dir_instance;
	AOLIB_VAR PlayfieldDir** pp_playfield_dir;
#define P_PLAYFIELD_DIR (*pp_playfield_dir)  // NOLINT(cppcoreguidelines-macro-usage)

#pragma endregion

#pragma region Gamecode

	// Functions
	AOLIB_VAR DWORD f_get_nano_item;
	AOLIB_VAR DWORD f_stat_to_string;

	AOLIB_VAR DWORD game_time_t__get_instance;

	AOLIB_VAR DWORD item_manager_t__item_manager_t;

	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_engine_client_anarchy_t;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__convert_criteria;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__get_breed_str;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__get_client_char;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__get_client_dynel_id;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__get_current_movement_mode;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__get_faction_str;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__get_faction_title;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__get_gender_string;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__get_item_by_template;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__get_sex_str;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__get_title_str;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__is_first_login;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__is_fixture;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_activate_mech;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_airstrike;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_artillery_attack;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_assist_fight;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_can_attack;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_can_click_target_target;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_can_use_mech;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_cast_nano_spell;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_consider;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_container_add_item;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_crawl_toggle;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_create_raid;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_default_action_on_dynel;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_default_attack;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_delete_item;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_delete_nano;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_do_social_action;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_drop_item;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_duel_accept;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_duel_challenge;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_duel_draw;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_duel_refuse;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_duel_stop;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_forage;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_action_by_name;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_action_progress;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_agg_def;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_alien_level_string;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_area_name;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_attacking_id;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_breed_str;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_buff_current_time;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_buff_total_time;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_character_body_shape;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_char_orientation_data;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_city_name_for_clan_member;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_clan_level_string;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_clan_string;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_client_pet_id;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_close_target;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_container_inventory_list;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_correct_action_id;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_current_room;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_current_room_name;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_district_fight_mode;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_dynels_in_vicinity;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_faction_info_string;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_faction_range;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_first_name;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_formula_progress;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_formula_radius;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_global_character_position;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_global_character_rotation;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_1;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_2;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_inventory_vec;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_item;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_item_progress;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_movement_mode;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_name;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_nano_cost_modifier;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_nano_spell_list;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_1;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_2;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_next_target;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_available_alien_perks;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_available_perks;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_free_inventory_slots;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_used_alien_perks;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_used_perks;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_over_equip_level;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_pf_name_1;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_pf_name_2;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_parent;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_pos;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_skill_1;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_skill_2;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_skill_max;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_special_action_list;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_special_action_state;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_special_attack_weapon_name;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_stat_name_map;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_target_target;


	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_npc;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_perform_special_action_1;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_perform_special_action_2;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_send_pet_command;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_stop_attack;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_use_item;

	AOLIB_VAR DWORD n3_engine_client_anarchy_t__on_closed;

	

	AOLIB_VAR DWORD simple_char_t__check_los;

	AOLIB_VAR DWORD static_item_manager_t__static_item_manager_t;

	// Instances
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__m_pc_instance;
	AOLIB_VAR isxao_classes::engine_client_anarchy **pp_engine_client_anarchy;
#define P_ENGINE_CLIENT_ANARCHY (*pp_engine_client_anarchy)  // NOLINT(cppcoreguidelines-macro-usage)
	AOLIB_VAR DWORD m_c_stat_name_dir;
	AOLIB_VAR p_stat_name_map_t p_stat_name_dir;
#define P_STAT_NAME_MAP p_stat_name_dir  // NOLINT(cppcoreguidelines-macro-usage)
	AOLIB_VAR DWORD m_c_nano_item_dir;
	AOLIB_VAR p_nano_item_map_t p_nano_item_dir;
#define P_NANO_ITEM_MAP p_nano_item_dir  // NOLINT(cppcoreguidelines-macro-usage)
	AOLIB_VAR DWORD item_manager_t__m_ppc_instance;
	AOLIB_VAR vector<acg_game_item_t> ***ppp_item_vector;
#define P_ITEM_VECTOR (**ppp_item_vector)  // NOLINT(cppcoreguidelines-macro-usage)
	AOLIB_VAR DWORD static_item_manager_t__m_ppc_instance;
	AOLIB_VAR vector<static_item_t> ***ppp_static_item_vector;
#define P_STATIC_ITEM_VECTOR (**ppp_static_item_vector)  // NOLINT(cppcoreguidelines-macro-usage)
	AOLIB_VAR DWORD game_time_t__m_pc_instance;
	AOLIB_VAR game_time** pp_game_time;
#define P_GAME_TIME (*pp_game_time)

#pragma endregion

#pragma region GUI

	AOLIB_VAR DWORD chat_window_node_c__parse_text_command;

	AOLIB_VAR DWORD html_parser_c__html_parser_c_1;
	AOLIB_VAR DWORD html_parser_c__html_parser_c_2;
	AOLIB_VAR DWORD html_parser_c__d_html_parser_c;	
	AOLIB_VAR DWORD html_parser_c__extract_text;

	AOLIB_VAR DWORD targeting_module_t__m_pc_instance;
	AOLIB_VAR TargetingModule** pp_targeting_module;
#define P_TARGETING_MODULE (*pp_targeting_module)  // NOLINT(cppcoreguidelines-macro-usage)
	AOLIB_VAR DWORD targeting_module_t__m_pc_selection_indicator;
	AOLIB_VAR indicator_t** pp_selection_indicator;
#define P_SELECTION_INDICATOR (*pp_selection_indicator)  // NOLINT(cppcoreguidelines-macro-usage)
	AOLIB_VAR DWORD targeting_module_t__m_pc_attacking_indicator;
	AOLIB_VAR indicator_t** pp_attacking_indicator;
#define P_ATTACKING_INDICATOR (*pp_attacking_indicator)  // NOLINT(cppcoreguidelines-macro-usage)
	AOLIB_VAR DWORD targeting_module_t__m_c_last_target;
	AOLIB_VAR identity_t* p_last_target;
#define P_LAST_TARGET (p_last_target)  // NOLINT(cppcoreguidelines-macro-usage)
	AOLIB_VAR DWORD targeting_module_t__targeting_module_t;
	AOLIB_VAR DWORD targeting_module_t__initialise_message;
	AOLIB_VAR DWORD TargetingModule_t__RemoveTarget;
	AOLIB_VAR DWORD TargetingModule_t__SelectSelf;
	AOLIB_VAR DWORD targeting_module_t__set_target;
	AOLIB_VAR DWORD TargetingModule_t__SetTargetPet;

	

#pragma endregion

#pragma region Interfaces

	AOLIB_VAR DWORD client_t__s_n_char_id;
	AOLIB_VAR DWORD* gp_character_id;
#define G_CHARACTER_ID (*gp_character_id)  // NOLINT(cppcoreguidelines-macro-usage)
	AOLIB_VAR DWORD client_t__process_message;

#pragma endregion

#pragma region Vehicle

	AOLIB_VAR DWORD vehicle_t__set_rel_rot;

#pragma endregion

#pragma region Pathfinder

	AOLIB_VAR DWORD graph_path_finder_t__graph_path_finder_t_1;
	AOLIB_VAR DWORD graph_path_finder_t__graph_path_finder_t_2;
	AOLIB_VAR DWORD graph_path_finder_t__d_graph_path_finder_t;
	AOLIB_VAR DWORD graph_path_finder_t__configure;
	AOLIB_VAR DWORD graph_path_finder_t__create_from_data;
	AOLIB_VAR DWORD graph_path_finder_t__find_path;
	AOLIB_VAR DWORD graph_path_finder_t__generate_graph;
	AOLIB_VAR DWORD graph_path_finder_t__generate_graph_for_room;
	AOLIB_VAR DWORD graph_path_finder_t__init;
	AOLIB_VAR DWORD graph_path_finder_t__set_space_for_graph;
	AOLIB_VAR DWORD graph_path_finder_t__set_surface;

#pragma endregion

#pragma region Globals

	AOLIB_VAR DWORD __N3Msg_GetFullPerkMap;
	AOLIB_VAR DWORD __SetTarget;	
	AOLIB_VAR DWORD __RequestInfo;

#pragma endregion

#pragma region EngineClientAnarchy			
	
	
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetTeamMemberList;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_HasPerk;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsAttacking;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsBattleStation;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsCharacterInMech;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsCharacterMorphed;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsDungeon;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsFormulaReady;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsGeneralPerk;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsGroupPerk;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsInRaidTeam;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsInTeam;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsItemDisabled;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsItemMine;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsItemNFCrystal;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToUnWear;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToWear;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsMoving;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsMyPetID;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsNanoSelfOnly;
	
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsPerk;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsPetTower;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsProfessionPerk;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsResearch;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsSecondarySpecialAttackAvailable;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsShieldDisablerItem;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsSpecialPerk;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsTeamLeader;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsTeamMission;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsTeamMissionCopy;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsTeamNano;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsTower;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsVisible;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_JoinItems;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_KickTeamMember;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_LeaveBattle;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_LeaveTeam;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_MeetsPerkCriteria;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_MoveItemToInventory;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_MoveRaidMember;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_NameToID;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatAddTradeItem;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatCloseWindow;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatEndTrade;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatRemoveTradeItem;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatRequestDescription;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatStartTrade;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_OrbitalAttack;
	
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_PetDuel_Accept;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_PetDuel_Challenge;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_PetDuel_Refuse;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_PetDuel_Stop;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_RemoveBuff;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_RemoveQuest;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_RequestCharacterInventory;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_RequestClothInventory;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_RequestImplantInventory;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_RequestSocialInventory;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_RequestWeaponInventory;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_SecondarySpecialAttack;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_SelectedTarget;
	
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_SitToggle;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_SplitItem;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_StartAltState;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_StartCamping;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_StartPvP;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_StartTreatment;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_StopAltState;
	
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_StopCamping;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_StringToStat;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_SwitchTarget;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_TeamJoinRequest;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_TemplateIDToDynelID;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_TextCommand;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_ToggleReclaim;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_TradeAbort;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_TradeAccept;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_TradeAddItem;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_TradeConfirm;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_TradeGetInventory;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_TradeGetInventoryCost;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_TradeRemoveItem;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_TradeSetCash;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_TradeStart;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_TradeskillCombine;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_TrainPerk;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_TransferTeamLeadership;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_TryAbortNanoFormula;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_TryEnterSneakMode;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_UntrainPerk;
	
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_UseItemOnItem;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_UseSkill;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__SetMainDynel;

	AOLIB_VAR DWORD n3Engine_t__SetTeleportStatus;

	AOLIB_VAR DWORD n3EngineClient_t__SetMainDynel;

#pragma endregion

#pragma region Playfield
	
	AOLIB_VAR DWORD n3Playfield_t__OnChildDynelBeingRemoved;
	AOLIB_VAR DWORD PlayfieldAnarchy_t__PlayfieldAnarchy_t;
	AOLIB_VAR DWORD PlayfieldAnarchy_t__dPlayfieldAnarchy_t;

#pragma endregion

#pragma region Gametime
	
#pragma endregion
	
#pragma region InputConfig
	
	AOLIB_VAR DWORD InputConfig_t__m_pcInstance;
	AOLIB_VAR InputConfig** ppInputConfig;
#define pInputConfig (*ppInputConfig)
	AOLIB_VAR DWORD InputConfig_t__SetCurrentTarget;

#pragma endregion

#pragma region FlowControl

	AOLIB_VAR DWORD FlowControlModule_t__m_pcInstance;
	AOLIB_VAR DWORD  FlowControlModule_t__m_isLauncherRun;
	AOLIB_VAR DWORD FlowControlModule_t__m_bIsGameClosing;
	AOLIB_VAR DWORD FlowControlModule_t__m_nCloseFrames;
	AOLIB_VAR DWORD FlowControlModule_t__m_isTeleporting;
	AOLIB_VAR bool* gpbIsTeleporting;
#define gbIsTeleporting (*gpbIsTeleporting)
	AOLIB_VAR DWORD FlowControlModule_t__m_eLoggingOutTimed;
	AOLIB_VAR DWORD FlowControlModule_t__m_isClientToRestartAtExit;

#pragma endregion

#pragma region ChatGUIModule

	AOLIB_VAR DWORD  ChatGUIModule_c__s_pcInstance;
	AOLIB_VAR chat_gui_module** ppChatGUIModule;
#define pChatGUIModule (*ppChatGUIModule)

	AOLIB_VAR DWORD ChatGUIModule_c__HandleGroupAction;
	AOLIB_VAR DWORD ChatGUIModule_c__HandleGroupMessage;
	AOLIB_VAR DWORD ChatGUIModule_c__HandlePrivateGroupAction;
	AOLIB_VAR DWORD ChatGUIModule_c__HandlePrivateMessage;
	AOLIB_VAR DWORD ChatGUIModule_c__HandleSystemMessage;
	AOLIB_VAR DWORD ChatGUIModule_c__HandleVicinityMessage;

#pragma endregion



#pragma region Messaging

	AOLIB_VAR DWORD Message_t__DataBlockSizeGet;
	AOLIB_VAR DWORD Message_t__MessageSizeGet;
	AOLIB_VAR DWORD N3Message_t__DuplicateBody;
	AOLIB_VAR DWORD N3Message_t__MessageBodyGet;
	AOLIB_VAR DWORD N3Message_t__MessageBodyLen;
	AOLIB_VAR DWORD TextMessage_t__MessageBodyGet;
	AOLIB_VAR DWORD TextMessage_t__MessageBodyLen;

#pragma endregion

#pragma region Logger

	AOLIB_VAR ISXAOLog* gp_isxao_log;

#pragma endregion
	
#pragma region vTables

	AOLIB_VAR DWORD AccessCard_t__vTable;
	AOLIB_VAR DWORD CentralController_t__vTable;
	AOLIB_VAR DWORD Chest_t__vTable;
	AOLIB_VAR DWORD CityTerminal_t__vTable;
	AOLIB_VAR DWORD Corpse_t__vTable;
	AOLIB_VAR DWORD Door_t__vTable;
	AOLIB_VAR DWORD LockableItem_t__vTable;
	AOLIB_VAR DWORD Mine_t__vTable;
	AOLIB_VAR DWORD PlayerShop_t__vTable;
	AOLIB_VAR DWORD QuestBooth_t__vTable;
	AOLIB_VAR DWORD ReclaimBooth_t__vTable;
	AOLIB_VAR DWORD SimpleChar_t__vTable;
	AOLIB_VAR DWORD SimpleItem_t__vTable;
	AOLIB_VAR DWORD TrapItem_t__vTable;
	AOLIB_VAR DWORD VendingMachine_t__vTable;
	AOLIB_VAR DWORD Weapon_t__vTable;
	AOLIB_VAR DWORD WearableItem_t__vTable;

#pragma endregion

#pragma region SimpleChar

	AOLIB_VAR DWORD SimpleChar_t__SimpleChar_t;
	AOLIB_VAR DWORD SimpleChar_t__dSimpleChar_t;	

#pragma endregion

#pragma region Internal

	AOLIB_VAR DWORD64 g_pulse_count;
	AOLIB_VAR DWORD g_game_state;
	AOLIB_VAR DOUBLE g_y_filter;
	AOLIB_VAR bool g_zoning;
	AOLIB_VAR bool g_offsets_initialized;
	AOLIB_VAR bool g_events_registered;
	AOLIB_VAR bool g_isxao_initialized;
	AOLIB_VAR Concurrency::concurrent_queue<PN3MESSAGEINFO> g_n3message_queue;
	AOLIB_VAR Concurrency::concurrent_queue<PGROUPMESSAGEINFO> g_group_message_queue;
	AOLIB_VAR Concurrency::concurrent_queue<PPRIVATEMESSAGEINFO> g_private_message_queue;
	AOLIB_VAR Concurrency::concurrent_queue<PPRIVATEMESSAGEINFO> g_vicinity_message_queue;
	AOLIB_VAR Concurrency::concurrent_queue<PSYSTEMCHATINFO> g_system_chat_queue;

#pragma endregion

#pragma region PlayerVehicle

	AOLIB_VAR DWORD PlayerVehicle_t__UseWaypointPath;

#pragma endregion

#pragma region LoginModule

	AOLIB_VAR DWORD LoginModule_c__m_pcInstance;
	AOLIB_VAR login_module_t** ppLoginModule;
#define pLoginModule (*ppLoginModule)

#pragma endregion

#pragma region ChatWindowController

	AOLIB_VAR DWORD ChatWindowController_c__m_pcInstance;
	AOLIB_VAR chat_window_controller** ppChatWindowController;
#define pChatWindowController (*ppChatWindowController)

	AOLIB_VAR DWORD ChatGroupController_c__sub_10083D9C;

#pragma endregion

#pragma region FriendListController

	AOLIB_VAR DWORD FriendListController_c__sub_100A68E6;

#pragma endregion

#pragma region CommandInterpreter

	AOLIB_VAR DWORD CommandInterpreter_c__m_pcInstance;
	AOLIB_VAR CommandInterpreter** ppCommandInterpreter;
#define pCommandInterpreter (*ppCommandInterpreter)
	AOLIB_VAR DWORD CommandInterpreter_c__ParseTextCommand;

#pragma endregion

#pragma region ChatWindowNode	

	AOLIB_VAR DWORD ChatWindowNode_c__sub_1009BB79;

#pragma endregion

#pragma region LookAtIIR

	AOLIB_VAR DWORD LookAtIIR_t__sub_10073E4D;

#pragma endregion

#pragma region ResourceDatabase

	AOLIB_VAR DWORD ResourceDatabase_t__GetDbObject_1;
	AOLIB_VAR DWORD ResourceDatabase_t__GetIdentityVec;

#pragma endregion

#pragma region n3DatabaseHandler

	AOLIB_VAR DWORD n3DatabaseHandler_t__s_pcInstance;
	AOLIB_VAR database_handler** ppDatabaseHandler;
#define pDatabaseHandler (*ppDatabaseHandler)

#pragma endregion

	bool initialize_offsets();
	bool get_function_address(const std::vector<unsigned char>& data, const char* function_pattern, DWORD& module_base_address, DWORD& function_address, const char* function_offset_name);
	bool get_static_address_from_function(const DWORD& function_base_address, DWORD& static_address, const char* static_address_name, const size_t& offset);
	bool get_relative_address_from_function(const DWORD& function_base_address, DWORD& relative_address, const char* relative_address_name, const size_t& offset, const size_t& bytes_to_next_line);
	bool get_proc_address(const HMODULE& module_handle, DWORD& function_address, const char* function_name, const char* mangled_function_name);

}
using namespace isxao_globals;
#endif // ISXAO_GLOBALS_H

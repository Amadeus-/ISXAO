
#ifndef ISXAO_GLOBALS_H
#define ISXAO_GLOBALS_H

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
	AOLIB_VAR HMODULE message_protocol_module_handle;
	AOLIB_VAR MODULEINFO message_protocol_module_info;
	AOLIB_VAR HMODULE database_controller_module_handle;
	AOLIB_VAR MODULEINFO database_controller_module_info;

#pragma endregion

#pragma region N3

	// Functions
	AOLIB_VAR DWORD n3_camera_t__set_secondary_target;
	AOLIB_VAR DWORD n3_camera_t__set_selected_target;	

	//Functions	
	AOLIB_VAR DWORD n3_database_handler_t__initialize;

	// Instances
	AOLIB_VAR DWORD n3_database_handler_t__s_pc_instance;
	AOLIB_VAR ao::database_handler** pp_database_handler;
#define P_DATABASE_HANDLER (*pp_database_handler)  // NOLINT(cppcoreguidelines-macro-usage)

	// Functions
	AOLIB_VAR DWORD n3_dynel_t__n3_dynel_t;
	AOLIB_VAR DWORD n3_dynel_t__d_n3_dynel_t;
	AOLIB_VAR DWORD n3_dynel_t__get_dynel;
	AOLIB_VAR DWORD n3_dynel_t__is_dynel_in_engine;
	AOLIB_VAR DWORD n3_dynel_t__send_iir_to_observers;
	AOLIB_VAR DWORD n3_dynel_t__set_playfield;
	AOLIB_VAR DWORD n3_dynel_t__update_locality_listeners;
	AOLIB_VAR DWORD n3_dynel_t__update_where;

	// Instances
	AOLIB_VAR DWORD n3_dynel_t__m_pc_dynel_dir_instance;
	AOLIB_VAR ao::dynel_map_t **pp_dynel_dir;
#define P_DYNEL_DIR (*pp_dynel_dir)  // NOLINT(cppcoreguidelines-macro-usage)

	// Functions
	AOLIB_VAR DWORD n3_engine_t__n3_engine_t;
	AOLIB_VAR DWORD n3Engine_t__SetTeleportStatus;

	// Instances
	AOLIB_VAR DWORD n3_engine_t__m_pc_instance;

	// Functions
	AOLIB_VAR DWORD n3_engine_client_t__get_client_control_dynel;
	AOLIB_VAR DWORD n3_engine_client_t__set_main_dynel;

	// Functions
	AOLIB_VAR DWORD n3_playfield_t__add_child_dynel;
	AOLIB_VAR DWORD n3_playfield_t__debug_draw_pathfinder;
	AOLIB_VAR DWORD n3_playfield_t__get_playfield_1;
	AOLIB_VAR DWORD n3_playfield_t__get_playfield_2;
	AOLIB_VAR DWORD n3_playfield_t__get_playfield_3;
	AOLIB_VAR DWORD n3_playfield_t__line_of_sight;
	AOLIB_VAR DWORD n3_playfield_t__remove_child;

	// Instances
	AOLIB_VAR DWORD n3_playfield_t__m_pc_playfield_dir_instance;
	AOLIB_VAR ao::playfield_dir** pp_playfield_dir;
#define P_PLAYFIELD_DIR (*pp_playfield_dir)  // NOLINT(cppcoreguidelines-macro-usage)
	

#pragma endregion

#pragma region Gamecode

	// Functions
	AOLIB_VAR DWORD f_get_nano_item;
	AOLIB_VAR DWORD f_stat_to_string;

	AOLIB_VAR DWORD game_time_t__get_instance;

	AOLIB_VAR DWORD item_manager_t__item_manager_t;

	AOLIB_VAR DWORD look_at_iir_t__look_at_iir_t;

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
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__get_last_speed_mode;
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
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_full_perk_map;
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
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_get_team_member_list;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_has_perk;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_hide_against_opponent;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_attacking;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_battle_station;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_character_in_mech;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_character_morphed;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_dungeon;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_formula_ready;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_general_perk;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_group_perk;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_in_raid_team;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_in_team;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_item_disabled;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_item_mine;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_item_nf_crystal;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_item_possible_to_un_wear;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_item_possible_to_wear;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_moving;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_my_pet_id;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_nano_self_only;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_npc;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_perk;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_is_pet_tower;
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
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_mouse_movement;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_MoveItemToInventory;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_MoveRaidMember;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_movement_changed;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_name_to_id;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatAddTradeItem;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatCloseWindow;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatEndTrade;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatRemoveTradeItem;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatRequestDescription;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_NPCChatStartTrade;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_OrbitalAttack;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_perform_special_action_1;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_perform_special_action_2;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_PetDuel_Accept;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_PetDuel_Challenge;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_PetDuel_Refuse;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_PetDuel_Stop;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_RemoveBuff;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_RemoveQuest;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_RequestCharacterInventory;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_RequestClothInventory;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_RequestImplantInventory;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_request_info_packet;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_RequestSocialInventory;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_RequestWeaponInventory;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_SecondarySpecialAttack;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_SelectedTarget;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_send_pet_command;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_sit_toggle;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_SplitItem;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_StartAltState;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_StartCamping;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_StartPvP;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_StartTreatment;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_StopAltState;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_stop_attack;
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
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__n3_msg_use_item;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_UseItemOnItem;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_UseSkill;
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__on_closed;

	
	

	AOLIB_VAR DWORD playfield_anarchy_t__playfield_anarchy_t;
	AOLIB_VAR DWORD playfield_anarchy_t__d_playfield_anarchy_t;

	AOLIB_VAR DWORD simple_char_t__check_los;

	AOLIB_VAR DWORD static_item_manager_t__static_item_manager_t;

	// Instances
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__m_pc_instance;
	AOLIB_VAR ao::engine_client_anarchy **pp_engine_client_anarchy;
#define P_ENGINE_CLIENT_ANARCHY (*pp_engine_client_anarchy)  // NOLINT(cppcoreguidelines-macro-usage)

	AOLIB_VAR DWORD m_c_stat_name_dir;
	AOLIB_VAR ao::p_stat_name_map_t p_stat_name_dir;
#define P_STAT_NAME_MAP p_stat_name_dir  // NOLINT(cppcoreguidelines-macro-usage)

	AOLIB_VAR DWORD m_c_nano_item_dir;
	AOLIB_VAR ao::p_nano_item_map_t p_nano_item_dir;
#define P_NANO_ITEM_MAP p_nano_item_dir  // NOLINT(cppcoreguidelines-macro-usage)

	AOLIB_VAR DWORD item_manager_t__m_ppc_instance;
	AOLIB_VAR std::vector<ao::acg_game_item_t> ***ppp_item_vector;
#define P_ITEM_VECTOR (**ppp_item_vector)  // NOLINT(cppcoreguidelines-macro-usage)

	AOLIB_VAR DWORD static_item_manager_t__m_ppc_instance;
	AOLIB_VAR std::vector<ao::static_item_t> ***ppp_static_item_vector;
#define P_STATIC_ITEM_VECTOR (**ppp_static_item_vector)  // NOLINT(cppcoreguidelines-macro-usage)

	AOLIB_VAR DWORD game_time_t__m_pc_instance;
	AOLIB_VAR ao::game_time** pp_game_time;
#define P_GAME_TIME (*pp_game_time)  // NOLINT(cppcoreguidelines-macro-usage)

	AOLIB_VAR DWORD mouse_look_active;
	AOLIB_VAR byte* p_mouse_look_active;
#define MOUSE_LOOK_ACTIVE (*p_mouse_look_active == 1)  // NOLINT(cppcoreguidelines-macro-usage)

#pragma endregion

#pragma region GUI

	AOLIB_VAR DWORD chat_gui_module_c__chat_gui_module_c;
	AOLIB_VAR DWORD chat_gui_module_c__handle_group_action;
	AOLIB_VAR DWORD chat_gui_module_c__handle_group_message;
	AOLIB_VAR DWORD chat_gui_module_c__handle_private_group_action;
	AOLIB_VAR DWORD chat_gui_module_c__handle_private_message;
	AOLIB_VAR DWORD chat_gui_module_c__handle_system_message;
	AOLIB_VAR DWORD chat_gui_module_c__handle_vicinity_message;
	AOLIB_VAR DWORD chat_gui_module_c__s_pc_instance;
	AOLIB_VAR ao::chat_gui_module** pp_chat_gui_module;
#define P_CHAT_GUI_MODULE (*pp_chat_gui_module)  // NOLINT(cppcoreguidelines-macro-usage)

	AOLIB_VAR DWORD chat_window_controller_t__d_chat_window_controller_t;
	AOLIB_VAR DWORD chat_window_controller_c__m_pc_instance;
	AOLIB_VAR ao::chat_window_controller** pp_chat_window_controller;
#define P_CHAT_WINDOW_CONTROLLER (*pp_chat_window_controller)  // NOLINT(cppcoreguidelines-macro-usage)

	AOLIB_VAR DWORD chat_window_node_c__parse_text_command;

	AOLIB_VAR DWORD command_interpreter_c__command_interpreter_c;
	AOLIB_VAR DWORD command_interpreter_c__parse_text_command;
	AOLIB_VAR DWORD command_interpreter_c__m_pc_instance;
	AOLIB_VAR ao::command_interpreter** pp_command_interpreter;
#define P_COMMAND_INTERPRETER (*pp_command_interpreter)  // NOLINT(cppcoreguidelines-macro-usage)

	AOLIB_VAR DWORD command_t__execute_1;

	AOLIB_VAR DWORD command_list_t__command_list_t;
	AOLIB_VAR DWORD command_list_t__m_pc_instance;
	AOLIB_VAR ao::command_list_t* p_command_list;
#define P_COMMAND_LIST (p_command_list)  // NOLINT(cppcoreguidelines-macro-usage)

	AOLIB_VAR DWORD flow_control_module_t__slot_autorun;
	AOLIB_VAR DWORD flow_control_module_t__slot_movement_back;
	AOLIB_VAR DWORD flow_control_module_t__slot_movement_forward;
	AOLIB_VAR DWORD flow_control_module_t__slot_movement_jump;
	AOLIB_VAR DWORD flow_control_module_t__slot_movement_left;
	AOLIB_VAR DWORD flow_control_module_t__slot_movement_right;
	AOLIB_VAR DWORD flow_control_module_t__slot_movement_strafe_left;
	AOLIB_VAR DWORD flow_control_module_t__slot_movement_strafe_right;
	AOLIB_VAR DWORD flow_control_module_t__slot_walk_toggle;
	AOLIB_VAR DWORD flow_control_module_t__get_instance;
	AOLIB_VAR DWORD flow_control_module_t__m_pc_instance;
	AOLIB_VAR ao::flow_control** pp_flow_control;
#define P_FLOW_CONTROL (*pp_flow_control)  // NOLINT(cppcoreguidelines-macro-usage)

	AOLIB_VAR DWORD html_parser_c__html_parser_c_1;
	AOLIB_VAR DWORD html_parser_c__html_parser_c_2;
	AOLIB_VAR DWORD html_parser_c__d_html_parser_c;	
	AOLIB_VAR DWORD html_parser_c__extract_text;

	AOLIB_VAR DWORD input_config_t__m_pc_instance;
	AOLIB_VAR ao::input_config** pp_input_config;
#define P_INPUT_CONFIG (*pp_input_config)  // NOLINT(cppcoreguidelines-macro-usage)
	AOLIB_VAR DWORD input_config_t__m_as_input_method_id_table;
	AOLIB_VAR ao::input_method_id_table* p_input_method_id_table;
#define P_INPUT_METHOD_ID_TABLE (p_input_method_id_table)  // NOLINT(cppcoreguidelines-macro-usage)
	AOLIB_VAR DWORD input_config_t__m_as_input_modes_id_table;
	AOLIB_VAR ao::input_mode_id_table* p_input_mode_id_table;
#define P_INPUT_MODE_ID_TABLE (p_input_mode_id_table)  // NOLINT(cppcoreguidelines-macro-usage)
	AOLIB_VAR DWORD input_config_t__get_instance;
	AOLIB_VAR DWORD input_config_t__set_current_target;
	AOLIB_VAR DWORD input_config_t__process_input;
	AOLIB_VAR DWORD input_config_t__check_input;

	AOLIB_VAR DWORD targeting_module_t__m_pc_instance;
	AOLIB_VAR ao::targeting_module** pp_targeting_module;
#define P_TARGETING_MODULE (*pp_targeting_module)  // NOLINT(cppcoreguidelines-macro-usage)
	AOLIB_VAR DWORD targeting_module_t__m_pc_selection_indicator;
	AOLIB_VAR ao::indicator_t** pp_selection_indicator;
#define P_SELECTION_INDICATOR (*pp_selection_indicator)  // NOLINT(cppcoreguidelines-macro-usage)
	AOLIB_VAR DWORD targeting_module_t__m_pc_attacking_indicator;
	AOLIB_VAR ao::indicator_t** pp_attacking_indicator;
#define P_ATTACKING_INDICATOR (*pp_attacking_indicator)  // NOLINT(cppcoreguidelines-macro-usage)
	AOLIB_VAR DWORD targeting_module_t__m_c_last_target;
	AOLIB_VAR ao::identity_t* p_last_target;
#define P_LAST_TARGET (p_last_target)  // NOLINT(cppcoreguidelines-macro-usage)
	AOLIB_VAR DWORD targeting_module_t__targeting_module_t;
	AOLIB_VAR DWORD targeting_module_t__initialise_message;
	AOLIB_VAR DWORD targeting_module_t__remove_target;
	AOLIB_VAR DWORD targeting_module_t__select_self;
	AOLIB_VAR DWORD targeting_module_t__set_target;
	AOLIB_VAR DWORD targeting_module_t__set_target_pet;

	AOLIB_VAR DWORD window_controller_t__get_instance;
	AOLIB_VAR DWORD window_controller_t__handle_key_down;
	AOLIB_VAR DWORD window_controller_t__handle_key_up;
	AOLIB_VAR DWORD window_controller_c__s_pc_instance;
	
	

#pragma endregion

#pragma region Interfaces

	AOLIB_VAR DWORD client_t__s_n_char_id;
	AOLIB_VAR DWORD* gp_character_id;
#define G_CHARACTER_ID (*gp_character_id)  // NOLINT(cppcoreguidelines-macro-usage)
	AOLIB_VAR DWORD client_t__process_message;

#pragma endregion

#pragma region Vehicle

	AOLIB_VAR DWORD vehicle_t__set_rel_rot;
	AOLIB_VAR DWORD vehicle_t__steering_dir_arrive;
	AOLIB_VAR DWORD vehicle_t__steering_flee;

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

#pragma region MessageProtocol

	AOLIB_VAR DWORD message_t__data_block_size_get;
	AOLIB_VAR DWORD message_t__dest_id_get;
	AOLIB_VAR DWORD message_t__header_size;
	AOLIB_VAR DWORD message_t__message_size_get;
	AOLIB_VAR DWORD message_t__message_type_get;
	AOLIB_VAR DWORD message_t__priority_get;
	AOLIB_VAR DWORD message_t__source_id_get;
	
	AOLIB_VAR DWORD n3_message_t__duplicate_body;
	AOLIB_VAR DWORD n3_message_t__message_body_get;

	AOLIB_VAR DWORD text_message_t__message_body_get;
	AOLIB_VAR DWORD text_message_t__message_body_len;

#pragma endregion

#pragma region DatabaseController

	AOLIB_VAR DWORD resource_database_t__get_db_object_1;

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
	AOLIB_VAR isxao_log* gp_isxao_log;
	// move_to
	AOLIB_VAR bool g_is_moving_to_location;
	AOLIB_VAR bool g_is_move_to_stuck;
	AOLIB_VAR float g_distance_moved_since_last;
	AOLIB_VAR ao::vector3_t g_move_to_location;
	AOLIB_VAR ao::vector3_t g_last_location;

	AOLIB_VAR Concurrency::concurrent_queue<isxao::internal::PN3MESSAGEINFO> g_n3message_queue;
	AOLIB_VAR Concurrency::concurrent_queue<isxao::internal::PGROUPMESSAGEINFO> g_group_message_queue;
	AOLIB_VAR Concurrency::concurrent_queue<isxao::internal::PPRIVATEMESSAGEINFO> g_private_message_queue;
	AOLIB_VAR Concurrency::concurrent_queue<isxao::internal::PPRIVATEMESSAGEINFO> g_vicinity_message_queue;
	AOLIB_VAR Concurrency::concurrent_queue<isxao::internal::PSYSTEMCHATINFO> g_system_chat_queue;

#pragma endregion

#pragma region PlayerVehicle

	AOLIB_VAR DWORD PlayerVehicle_t__UseWaypointPath;

#pragma endregion

#pragma region LoginModule

	AOLIB_VAR DWORD LoginModule_c__m_pcInstance;
	AOLIB_VAR ao::login_module_t** ppLoginModule;
#define pLoginModule (*ppLoginModule)

#pragma endregion

#pragma region ChatWindowController

	

	AOLIB_VAR DWORD ChatGroupController_c__sub_10083D9C;

#pragma endregion

#pragma region FriendListController

	AOLIB_VAR DWORD FriendListController_c__sub_100A68E6;

#pragma endregion

#pragma region ChatWindowNode	

	AOLIB_VAR DWORD ChatWindowNode_c__sub_1009BB79;

#pragma endregion

#pragma region LookAtIIR

	AOLIB_VAR DWORD LookAtIIR_t__sub_10073E4D;

#pragma endregion

	bool initialize_offsets();
	bool get_function_address(const std::vector<unsigned char>& data, const char* function_pattern, DWORD& module_base_address, DWORD& function_address, const char* function_offset_name);
	bool get_static_address_from_function(const DWORD& function_base_address, DWORD& static_address, const char* static_address_name, const size_t& offset);
	bool get_relative_address_from_function(const DWORD& function_base_address, DWORD& relative_address, const char* relative_address_name, const size_t& offset, const size_t& bytes_to_next_line);
	bool get_proc_address(const HMODULE& module_handle, DWORD& function_address, const char* function_name, const char* mangled_function_name);
	bool resolve_function_address(const std::vector<BYTE>& data, HMODULE& module_handle, DWORD& function_address, const char* function_address_name, const char* mangled_function_name, const char* function_pattern, DWORD offset = 0x0, DWORD bytes_to_next_line = 0x0, DWORD relative_function_base_address = 0x0);
	bool resolve_static_instance_address(HMODULE& module_handle, DWORD& static_instance_address, const char* static_instance_name, const char* mangled_name, DWORD offset = 0, DWORD relative_function_base_address = 0);

#endif // ISXAO_GLOBALS_H

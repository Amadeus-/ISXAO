#pragma once

namespace isxao
{

#pragma region N3

// Module
constexpr char* const n3_module_name = static_cast<char*>("N3.dll");

// Functions

#pragma region n3_camera_t__set_secondary_target

constexpr char* const n3_camera_t__set_secondary_target_mangled_name = static_cast<char*>(
	"?SetSecondaryTarget@n3Camera_t@@QAEXPAVLocalitySource_t@@@Z");
constexpr char* const n3_camera_t__set_secondary_target_pattern = static_cast<char*>(
	"55 8B EC 56 8B F1 8B 4E 50 6A 00");
constexpr DWORD n3_camera_t__set_secondary_target_offset = 0;
constexpr DWORD n3_camera_t__set_secondary_target_bytes_to_next = 0;

#pragma endregion

#pragma region n3_camera_t__set_selected_target

constexpr char* const n3_camera_t__set_selected_target_mangled_name = static_cast<char*>(
	"?SetSelectedTarget@n3Camera_t@@QAEXABVIdentity_t@@@Z");
constexpr char* const n3_camera_t__set_selected_target_pattern = static_cast<char*>(
	"55 8B EC 83 EC 10 56 57 8B F9");
constexpr DWORD n3_camera_t__set_selected_target_offset = 0;
constexpr DWORD n3_camera_t__set_selected_target_bytes_to_next = 0;

#pragma endregion

#pragma region n3_database_handler_t__initialize

constexpr char* const n3_database_handler_t__initialize_mangled_name = static_cast<char*>(
	"?Initialize@n3DatabaseHandler_t@@SAXXZ");
constexpr char* const n3_database_handler_t__initialize_pattern = static_cast<char*>(
	"83 3D ?? ?? ?? ?? 00 75 ?? 6A 0C");
constexpr DWORD n3_database_handler_t__initialize_offset = 0x0;
constexpr DWORD n3_database_handler_t__initialize_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_dynel_t__n3_dynel_t

constexpr char* const n3_dynel_t__n3_dynel_t_mangled_name = static_cast<char*>(
	"??0n3Dynel_t@@IAE@ABVIdentity_t@@@Z");
constexpr char* const n3_dynel_t__n3_dynel_t_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 51 53 56 8B F1 57 89 75 F0 FF 15 ?? ?? ?? ??");
constexpr DWORD n3_dynel_t__n3_dynel_t_offset = 0;
constexpr DWORD n3_dynel_t__n3_dynel_t_bytes_to_next = 0;

#pragma endregion

#pragma region n3_dynel_t__d_n3_dynel_t

constexpr char* const n3_dynel_t__d_n3_dynel_t_mangled_name = static_cast<char*>(
	"??1n3Dynel_t@@MAE@XZ");
constexpr char* const n3_dynel_t__d_n3_dynel_t_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 51 56 8B F1 57 89 75 F0 C7 06 ?? ?? ?? ?? C7 46 04 ?? ?? ?? ?? C7 46 0C ?? ?? ?? ?? FF 76 60");
constexpr DWORD n3_dynel_t__d_n3_dynel_t_offset = 0;
constexpr DWORD n3_dynel_t__d_n3_dynel_t_bytes_to_next = 0;

#pragma endregion

#pragma region n3_dynel_t__get_dynel

constexpr char* const n3_dynel_t__get_dynel_mangled_name = static_cast<char*>(
	"?GetDynel@n3Dynel_t@@SAPAV1@ABVIdentity_t@@@Z");
constexpr char* const n3_dynel_t__get_dynel_pattern = static_cast<char*>(
	"55 8B EC 51 56 FF 75 08 8B 35 ?? ?? ?? ?? 8D 45 FC 50 8B CE E8 ?? ?? ?? ?? 8B 45 FC 3B 46 04 5E 75 ??");
constexpr DWORD n3_dynel_t__get_dynel_offset = 0;
constexpr DWORD n3_dynel_t__get_dynel_bytes_to_next = 0;

#pragma endregion

#pragma region n3_dynel_t__send_iir_to_observers

constexpr char* const n3_dynel_t__send_iir_to_observers_mangled_name = static_cast<char*>(
	"?SendIIRToObservers@n3Dynel_t@@QAEXAAVn3InfoItemRemote_t@@@Z");
constexpr char* const n3_dynel_t__send_iir_to_observers_pattern = static_cast<char*>(
	"55 8B EC 51 80 79 6B 00");
constexpr DWORD n3_dynel_t__send_iir_to_observers_offset = 0;
constexpr DWORD n3_dynel_t__send_iir_to_observers_bytes_to_next = 0;

#pragma endregion

#pragma region n3_dynel_t__set_playfield

constexpr char* const n3_dynel_t__set_playfield_mangled_name = static_cast<char*>(
	"?SetPlayfield@n3Dynel_t@@IAEXI@Z");
constexpr char* const n3_dynel_t__set_playfield_pattern = static_cast<char*>(
	"55 8B EC 53 8B 5D 08 56 57 8B F1");
constexpr DWORD n3_dynel_t__set_playfield_offset = 0;
constexpr DWORD n3_dynel_t__set_playfield_bytes_to_next = 0;

#pragma endregion

#pragma region n3_dynel_t__update_locality_listeners

constexpr char* const n3_dynel_t__update_locality_listeners_mangled_name = static_cast<char*>(
	"?UpdateLocalityListeners@n3Dynel_t@@QAEXXZ");
constexpr char* const n3_dynel_t__update_locality_listeners_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_dynel_t__update_locality_listeners_offset = 0x32;
constexpr DWORD n3_dynel_t__update_locality_listeners_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_dynel_t__update_where

constexpr char* const n3_dynel_t__update_where_mangled_name = static_cast<char*>(
	"?UpdateWhere@n3Dynel_t@@IAEXIABVVector3_t@@ABVQuaternion_t@@@Z");
constexpr char* const n3_dynel_t__update_where_pattern = static_cast<char*>(
	"55 8B EC 56 57 FF 75 08");
constexpr DWORD n3_dynel_t__update_where_offset = 0;
constexpr DWORD n3_dynel_t__update_where_bytes_to_next = 0;

#pragma endregion

#pragma region n3_engine_t__n3_engine_t

constexpr char* const n3_engine_t__n3_engine_t_mangled_name = static_cast<char*>(
	"??0n3Engine_t@@IAE@XZ");
constexpr char* const n3_engine_t__n3_engine_t_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 10 53 56 8B F1");
constexpr DWORD n3_engine_t__n3_engine_t_offset = 0;
constexpr DWORD n3_engine_t__n3_engine_t_bytes_to_next = 0;

#pragma endregion

#pragma region n3_engine_client_t__get_client_control_dynel

constexpr char* const n3_engine_client_t__get_client_control_dynel_mangled_name = static_cast<char*>(
	"?GetClientControlDynel@n3EngineClient_t@@QBEPAVn3VisualDynel_t@@XZ");
constexpr char* const n3_engine_client_t__get_client_control_dynel_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_t__get_client_control_dynel_offset = 0x8D;
constexpr DWORD n3_engine_client_t__get_client_control_dynel_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_t__set_main_dynel

constexpr char* const n3_engine_client_t__set_main_dynel_mangled_name = static_cast<char*>(
	"?SetMainDynel@n3EngineClient_t@@UAEXPAVn3Dynel_t@@@Z");
constexpr char* const n3_engine_client_t__set_main_dynel_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 8B 45 08 83 EC 58");
constexpr DWORD n3_engine_client_t__set_main_dynel_offset = 0x0;
constexpr DWORD n3_engine_client_t__set_main_dynel_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_playfield_t__add_child_dynel

constexpr char* const n3_playfield_t__add_child_dynel_mangled_name = static_cast<char*>(
	"?AddChildDynel@n3Playfield_t@@QAEXPAVn3Dynel_t@@ABVVector3_t@@ABVQuaternion_t@@@Z");
constexpr char* const n3_playfield_t__add_child_dynel_pattern = static_cast<char*>(
	"55 8B EC 51 56 57 8B 7D 08 8B F1 8B CF E8 ?? ?? ?? ?? 8B CF");
constexpr DWORD n3_playfield_t__add_child_dynel_offset = 0x0;
constexpr DWORD n3_playfield_t__add_child_dynel_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_playfield_t__debug_draw_pathfinder

constexpr char* const n3_playfield_t__debug_draw_pathfinder_mangled_name = static_cast<char*>(
	"?DebugDrawPathFinder@n3Playfield_t@@AAEXXZ");
constexpr char* const n3_playfield_t__debug_draw_pathfinder_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_playfield_t__debug_draw_pathfinder_offset = 0x0;
constexpr DWORD n3_playfield_t__debug_draw_pathfinder_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_playfield_t__get_playfield_1

constexpr char* const n3_playfield_t__get_playfield_1_mangled_name = static_cast<char*>(
	"?GetPlayfield@n3Playfield_t@@SAPAV1@ABVIdentity_t@@@Z");
constexpr char* const n3_playfield_t__get_playfield_1_pattern = static_cast<char*>(
	"55 8B EC 8B 45 08 FF 70 04");
constexpr DWORD n3_playfield_t__get_playfield_1_offset = 0x0;
constexpr DWORD n3_playfield_t__get_playfield_1_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_playfield_t__get_playfield_2

constexpr char* const n3_playfield_t__get_playfield_2_mangled_name = static_cast<char*>(
	"?GetPlayfield@n3Playfield_t@@SAPAV1@I@Z");
constexpr char* const n3_playfield_t__get_playfield_2_pattern = static_cast<char*>(
	"55 8B EC 51 56 8B 35 ?? ?? ?? ??");
constexpr DWORD n3_playfield_t__get_playfield_2_offset = 0x0;
constexpr DWORD n3_playfield_t__get_playfield_2_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_playfield_t__get_playfield_3

constexpr char* const n3_playfield_t__get_playfield_3_mangled_name = static_cast<char*>(
	"?GetPlayfield@n3Playfield_t@@SAPAV1@XZ");
constexpr char* const n3_playfield_t__get_playfield_3_pattern = static_cast<char*>(
	"A1 ?? ?? ?? ?? 83 78 08 00");
constexpr DWORD n3_playfield_t__get_playfield_3_offset = 0x0;
constexpr DWORD n3_playfield_t__get_playfield_3_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_playfield_t__line_of_sight

constexpr char* const n3_playfield_t__line_of_sight_mangled_name = static_cast<char*>(
	"?LineOfSight@n3Playfield_t@@QBE_NABVVector3_t@@0H_N@Z");
constexpr char* const n3_playfield_t__line_of_sight_pattern = static_cast<char*>(
	"55 8B EC F6 05 ?? ?? ?? ?? 01 57");
constexpr DWORD n3_playfield_t__line_of_sight_offset = 0x0;
constexpr DWORD n3_playfield_t__line_of_sight_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_playfield_t__remove_child

constexpr char* const n3_playfield_t__remove_child_mangled_name = static_cast<char*>(
	"?RemoveChild@n3Playfield_t@@UAEXPAVn3Dynel_t@@@Z");
constexpr char* const n3_playfield_t__remove_child_pattern = static_cast<char*>(
	"55 8B EC 56 57 8B 7D 08 8B F1 85 FF");
constexpr DWORD n3_playfield_t__remove_child_offset = 0x0;
constexpr DWORD n3_playfield_t__remove_child_bytes_to_next = 0x0;

#pragma endregion

// Instances

#pragma region n3_database_handler_t__s_pc_instance

constexpr char* const n3_database_handler_t__s_pc_instance_mangled_name = static_cast<char*>(
	"?s_pcInstance@n3DatabaseHandler_t@@0PAV1@A");
constexpr DWORD n3_database_handler_t__s_pc_instance_offset = 0x1;

#pragma endregion

#pragma region n3_dynel_t__m_pc_dynel_dir_instance

constexpr char* const n3_dynel_t__m_pc_dynel_dir_instance_mangled_name = static_cast<char*>(
	"?m_pcDynelDir@n3Dynel_t@@0PAVDynelMap_t@@A");
constexpr DWORD n3_dynel_t__m_pc_dynel_dir_instance_offset = 0xA;

#pragma endregion

#pragma region n3_engine_t__m_pc_instance

constexpr char* const n3_engine_t__m_pc_instance_mangled_name = static_cast<char*>(
	"?m_pcInstance@n3Engine_t@@0PAV1@A");
constexpr DWORD n3_engine_t__m_pc_instance_offset = 0x5B;

#pragma endregion

#pragma region n3_playfield_t__m_pc_playfield_dir_instance

constexpr char* const n3_playfield_t__m_pc_playfield_dir_instance_mangled_name = static_cast<char*>(
	// ReSharper disable once StringLiteralTypo
	"?m_pcPlayfieldDir@n3Playfield_t@@0PAV?$map@IPAVn3Playfield_t@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIPAVn3Playfield_t@@@std@@@3@@std@@A");
constexpr DWORD n3_playfield_t__m_pc_playfield_dir_instance_offset = 0x7;

#pragma endregion

#pragma endregion

#pragma region Gamecode

constexpr char* const gamecode_module_name = static_cast<char*>("Gamecode.dll");

// Functions

#pragma region f_stat_to_string

constexpr char* const f_stat_to_string_mangled_name = static_cast<char*>(
	"?fStatToString@@YAPBDW4Stat_e@GameData@@@Z");
constexpr char* const f_stat_to_string_pattern = static_cast<char*>(
	"55 8B EC 51 80 3D ?? ?? ?? ?? 00 75 ?? E8 ?? ?? ?? ?? 56 57 8B 7D 08 8D 45 08 50 8D 45 FC BE ?? ?? ?? ?? 50 8B CE 89 7D 08 E8 ?? ?? ?? ?? 8B 00 3B 05 ?? ?? ?? ?? 74 ?? 8D 45 08 50 8B CE 89 7D 08 E8 ?? ?? ?? ?? 8B 00");
constexpr DWORD f_stat_to_string_offset = 0;
constexpr DWORD f_stat_to_string_bytes_to_next = 0;

#pragma endregion

#pragma region f_get_nano_item

constexpr char* const f_get_nano_item_mangled_name = static_cast<char*>(nullptr);
constexpr char* const f_get_nano_item_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 0C 56 8D 45 08");
constexpr DWORD  f_get_nano_item_offset = 0;
constexpr DWORD  f_get_nano_item_bytes_to_next = 0;

#pragma endregion

#pragma region game_time_t__get_instance

constexpr char* const game_time_t__get_instance_mangled_name = static_cast<char*>(
	"?GetInstance@GameTime_t@@SAPAV1@XZ");
constexpr char* const game_time_t__get_instance_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 51 83 3D ?? ?? ?? ?? 00 75 ?? 68 C8 00 00 00");
constexpr DWORD  game_time_t__get_instance_offset = 0;
constexpr DWORD  game_time_t__get_instance_bytes_to_next = 0;

#pragma endregion

#pragma region item_manager_t__item_manager_t

constexpr char* const item_manager_t__item_manager_t_mangled_name = static_cast<char*>(nullptr);
constexpr char* const item_manager_t__item_manager_t_pattern = static_cast<char*>(nullptr);
constexpr DWORD item_manager_t__item_manager_t_offset = 0xF3;
constexpr DWORD item_manager_t__item_manager_t_bytes_to_next = 0x0;

#pragma endregion

#pragma region look_at_iir_t__look_at_iir_t

constexpr char* const look_at_iir_t__look_at_iir_t_mangled_name = static_cast<char*>(nullptr);
constexpr char* const look_at_iir_t__look_at_iir_t_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 1C 53 56 6A 0B 8B F1 33 DB 68 ?? ?? ?? ?? 8D 4D D8 C7 45 EC 0F 00 00 00 89 5D E8 88 5D D8 E8 ?? ?? ?? ?? 8D 45 D8 50 FF 75 08 8B CE 89 5D FC FF 15 ?? ?? ?? ?? 53 6A 01 8D 4D D8 E8 ?? ?? ?? ?? 8B 45 0C C7 06 ?? ?? ?? ??");
constexpr DWORD  look_at_iir_t__look_at_iir_t_offset = 0;
constexpr DWORD  look_at_iir_t__look_at_iir_t_bytes_to_next = 0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_engine_client_anarchy_t

constexpr char* const n3_engine_client_anarchy_t__n3_engine_client_anarchy_t_mangled_name = static_cast<char*>(
	"??0n3EngineClientAnarchy_t@@QAE@XZ");
constexpr char* const n3_engine_client_anarchy_t__n3_engine_client_anarchy_t_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 24 53 56 8B F1 89 75 F0");
constexpr DWORD  n3_engine_client_anarchy_t__n3_engine_client_anarchy_t_offset = 0;
constexpr DWORD  n3_engine_client_anarchy_t__n3_engine_client_anarchy_t_bytes_to_next = 0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t

constexpr char* const n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t_mangled_name = static_cast<char*>(
	"??1n3EngineClientAnarchy_t@@UAE@XZ");
constexpr char* const n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 51 53 56 8B F1 57 89 75 F0 C7 06 ?? ?? ?? ?? 8B 9E 00 01 00 00");
constexpr DWORD  n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t_offset = 0;
constexpr DWORD  n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t_bytes_to_next = 0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__convert_criteria

constexpr char* const n3_engine_client_anarchy_t__convert_criteria_mangled_name = static_cast<char*>(
	"?ConvertCriteria@n3EngineClientAnarchy_t@@ABE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@ABVCriterion_t@GameData@@@Z");
constexpr char* const n3_engine_client_anarchy_t__convert_criteria_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 81 EC C8 04 00 00");
constexpr DWORD  n3_engine_client_anarchy_t__convert_criteria_offset = 0;
constexpr DWORD  n3_engine_client_anarchy_t__convert_criteria_bytes_to_next = 0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__get_breed_str

constexpr char* const n3_engine_client_anarchy_t__get_breed_str_mangled_name = static_cast<char*>(
	"?GetBreedStr@n3EngineClientAnarchy_t@@SAPBDH@Z");
constexpr char* const n3_engine_client_anarchy_t__get_breed_str_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__get_breed_str_offset = 0xB89;
constexpr DWORD n3_engine_client_anarchy_t__get_breed_str_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__get_client_char

constexpr char* const n3_engine_client_anarchy_t__get_client_char_mangled_name = static_cast<char*>(
	"?GetClientChar@n3EngineClientAnarchy_t@@QBEPAVSimpleChar_t@@XZ");
constexpr char* const n3_engine_client_anarchy_t__get_client_char_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__get_client_char_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__get_client_char_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__get_client_dynel_id

constexpr char* const n3_engine_client_anarchy_t__get_client_dynel_id_mangled_name = static_cast<char*>(
	"?GetClientDynelId@n3EngineClientAnarchy_t@@UBE?AVIdentity_t@@XZ");
constexpr char* const n3_engine_client_anarchy_t__get_client_dynel_id_pattern = static_cast<char*>(
	"55 8B EC 8B 45 08 8B 89 80 00 00 00");
constexpr DWORD n3_engine_client_anarchy_t__get_client_dynel_id_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__get_client_dynel_id_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__get_current_movement_mode

constexpr char* const n3_engine_client_anarchy_t__get_current_movement_mode_mangled_name = static_cast<char*>(
	"?GetCurrentMovementMode@n3EngineClientAnarchy_t@@QBE?AW4Mode_e@Movement_n@@XZ");
constexpr char* const n3_engine_client_anarchy_t__get_current_movement_mode_pattern = static_cast<char*>(
	"83 B9 84 00 00 00 00 74 ?? FF 15 ?? ?? ?? ?? 85 C0 74 ?? 8B C8 E8 ?? ?? ?? ?? 8B C8 E8 ?? ?? ?? ?? 8B C8");
constexpr DWORD n3_engine_client_anarchy_t__get_current_movement_mode_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__get_current_movement_mode_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__get_faction_str

constexpr char* const n3_engine_client_anarchy_t__get_faction_str_mangled_name = static_cast<char*>(
	"?GetFactionStr@n3EngineClientAnarchy_t@@QBEPBDH_N@Z");
constexpr char* const n3_engine_client_anarchy_t__get_faction_str_pattern = static_cast<char*>(
	"55 8B EC FF 75 0C FF 75 08 E8 ?? ?? ?? ?? 59 59 5D");
constexpr DWORD n3_engine_client_anarchy_t__get_faction_str_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__get_faction_str_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__get_faction_title

constexpr char* const n3_engine_client_anarchy_t__get_faction_title_mangled_name = static_cast<char*>(
	"?GetFactionTitle@n3EngineClientAnarchy_t@@QBEPBDH@Z");
constexpr char* const n3_engine_client_anarchy_t__get_faction_title_pattern = static_cast<char*>(
	"55 8B EC FF 15 ?? ?? ?? ?? 85 C0 74 ?? 8B 80 C0 01 00 00");
constexpr DWORD n3_engine_client_anarchy_t__get_faction_title_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__get_faction_title_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__get_gender_string

constexpr char* const n3_engine_client_anarchy_t__get_gender_string_mangled_name = static_cast<char*>(
	"?GetGenderString@n3EngineClientAnarchy_t@@QBEPBDABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__get_gender_string_pattern = static_cast<char*>(
	"55 8B EC 6A 00 68 ?? ?? ?? ?? 68 ?? ?? ?? ?? 6A 00 FF 75 08 FF 15 ?? ?? ?? ?? 59 50 E8 ?? ?? ?? ?? 83 C4 14 85 C0 74 ?? 8D 88 EC 00 00 00 8B 01 6A 02 6A 3B");
constexpr DWORD n3_engine_client_anarchy_t__get_gender_string_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__get_gender_string_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__get_item_by_template

constexpr char* const n3_engine_client_anarchy_t__get_item_by_template_mangled_name = static_cast<char*>(
	"?GetItemByTemplate@n3EngineClientAnarchy_t@@ABEPAVDummyItemBase_t@@VIdentity_t@@ABV3@@Z");
constexpr char* const n3_engine_client_anarchy_t__get_item_by_template_pattern = static_cast<char*>(
	"55 8B EC 83 EC 0C 8B 45 08");
constexpr DWORD n3_engine_client_anarchy_t__get_item_by_template_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__get_item_by_template_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__get_sex_str

constexpr char* const n3_engine_client_anarchy_t__get_sex_str_mangled_name = static_cast<char*>(
	"?GetSexStr@n3EngineClientAnarchy_t@@SAPBDH@Z");
constexpr char* const n3_engine_client_anarchy_t__get_sex_str_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__get_sex_str_offset = 0xC1D;
constexpr DWORD n3_engine_client_anarchy_t__get_sex_str_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__get_title_str

constexpr char* const n3_engine_client_anarchy_t__get_title_str_mangled_name = static_cast<char*>(
	"?GetTitleStr@n3EngineClientAnarchy_t@@QBEPBDHH@Z");
constexpr char* const n3_engine_client_anarchy_t__get_title_str_pattern = static_cast<char*>(
	"55 8B EC 8B 45 08 6B C0 64");
constexpr DWORD n3_engine_client_anarchy_t__get_title_str_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__get_title_str_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__is_first_login

constexpr char* const n3_engine_client_anarchy_t__is_first_login_mangled_name = static_cast<char*>(
	"?IsFirstLogin@n3EngineClientAnarchy_t@@QBE_NXZ");
constexpr char* const n3_engine_client_anarchy_t__is_first_login_pattern = static_cast<char*>("8A 81 04 01 00 00");
constexpr DWORD n3_engine_client_anarchy_t__is_first_login_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__is_first_login_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__is_fixture

constexpr char* const n3_engine_client_anarchy_t__is_fixture_mangled_name = static_cast<char*>(
	"?IsFixture@n3EngineClientAnarchy_t@@QBE_NABVIdentity_t@@0@Z");
constexpr char* const n3_engine_client_anarchy_t__is_fixture_pattern = static_cast<char*>(
	"55 8B EC 8B 45 0C 53 33 DB 39 18 75 ?? 39 58 04 75 ?? FF 15 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__is_fixture_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__is_fixture_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_activate_mech

constexpr char* const n3_engine_client_anarchy_t__n3_msg_activate_mech_mangled_name = static_cast<char*>(
	"?N3Msg_AddToQueue@n3EngineClientAnarchy_t@@QAEXH@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_activate_mech_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 70 53 56 FF 15 ?? ?? ?? ?? 8B F0 33 DB 3B F3 74 ?? 53 68 ?? ?? ?? ?? 8D 4D D0 C7 45 E4 0F 00 00 00 89 5D E0 88 5D D0 E8 ?? ?? ?? ?? 8B 45 08");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_activate_mech_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_activate_mech_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_airstrike

constexpr char* const n3_engine_client_anarchy_t__n3_msg_airstrike_mangled_name = static_cast<char*>(
	"?N3Msg_Airstrike@n3EngineClientAnarchy_t@@QAEXABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_airstrike_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 68 53 56 FF 15 ?? ?? ?? ?? 8B F0 33 DB 3B F3 74 ?? 53 68 ?? ?? ?? ?? 8D 4D D8 C7 45 EC 0F 00 00 00 89 5D E8 88 5D D8 E8 ?? ?? ?? ?? 8D 4D D8 51 FF 75 08 8D 46 14 68 03 01 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_airstrike_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_airstrike_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_artillery_attack

constexpr char* const n3_engine_client_anarchy_t__n3_msg_artillery_attack_mangled_name = static_cast<char*>(
	"?N3Msg_ArtilleryAttack@n3EngineClientAnarchy_t@@QAEXABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_artillery_attack_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 68 53 56 FF 15 ?? ?? ?? ?? 8B F0 33 DB 3B F3 74 ?? 53 68 ?? ?? ?? ?? 8D 4D D8 C7 45 EC 0F 00 00 00 89 5D E8 88 5D D8 E8 ?? ?? ?? ?? 8D 4D D8 51 FF 75 08 8D 46 14 68 01 01 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_artillery_attack_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_artillery_attack_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_assist_fight

constexpr char* const n3_engine_client_anarchy_t__n3_msg_assist_fight_mangled_name = static_cast<char*>(
	"?N3Msg_AssistFight@n3EngineClientAnarchy_t@@QBEXABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_assist_fight_pattern = static_cast<char*>(
	"55 8B EC 53 56 E8 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_assist_fight_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_assist_fight_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_can_attack

constexpr char* const n3_engine_client_anarchy_t__n3_msg_can_attack_mangled_name = static_cast<char*>(
	"?N3Msg_CanAttack@n3EngineClientAnarchy_t@@QBE_NABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_can_attack_pattern = static_cast<char*>(
	"55 8B EC E8 ?? ?? ?? ?? 85 C0 75 ?? 32 C0 EB ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_can_attack_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_can_attack_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_can_click_target_target

constexpr char* const n3_engine_client_anarchy_t__n3_msg_can_click_target_target_mangled_name = static_cast<char*>(
	"?N3Msg_CanClickTargetTarget@n3EngineClientAnarchy_t@@QAE_NABVIdentity_t@@0@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_can_click_target_target_pattern = static_cast<char*>(
	"55 8B EC 53 56 57 FF 75 08 E8 ?? ?? ?? ?? FF 75 0C");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_can_click_target_target_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_can_click_target_target_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_can_use_mech

constexpr char* const n3_engine_client_anarchy_t__n3_msg_can_use_mech_mangled_name = static_cast<char*>(
	"?N3Msg_CanUseMech@n3EngineClientAnarchy_t@@QAE_NXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_can_use_mech_pattern = static_cast<char*>(
	"56 E8 ?? ?? ?? ?? 8B F0 85 F6 75 ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_can_use_mech_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_can_use_mech_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_cast_nano_spell

constexpr char* const n3_engine_client_anarchy_t__n3_msg_cast_nano_spell_mangled_name = static_cast<char*>(
	"?N3Msg_CastNanoSpell@n3EngineClientAnarchy_t@@QAEXABVIdentity_t@@0@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_cast_nano_spell_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 74 53 56 89 4D F0");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_cast_nano_spell_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_cast_nano_spell_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_consider

constexpr char* const n3_engine_client_anarchy_t__n3_msg_consider_mangled_name = static_cast<char*>(
	"?N3Msg_Consider@n3EngineClientAnarchy_t@@QBE?AW4Consider_e@@ABVIdentity_t@@AAM@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_consider_pattern = static_cast<char*>(
	"55 8B EC 51 51 56 57 33 F6");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_consider_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_consider_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_container_add_item

constexpr char* const n3_engine_client_anarchy_t__n3_msg_container_add_item_mangled_name = static_cast<char*>(
	"?N3Msg_ContainerAddItem@n3EngineClientAnarchy_t@@QAEXABVIdentity_t@@0@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_container_add_item_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 30 56 57 8B 7D 0C");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_container_add_item_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_container_add_item_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_crawl_toggle

constexpr char* const n3_engine_client_anarchy_t__n3_msg_crawl_toggle_mangled_name = static_cast<char*>(
	"?N3Msg_CrawlToggle@n3EngineClientAnarchy_t@@QAEXXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_crawl_toggle_pattern = static_cast<char*>(
	"53 57 8B D9 E8 ?? ?? ?? ?? 8B F8");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_crawl_toggle_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_crawl_toggle_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_create_raid

constexpr char* const n3_engine_client_anarchy_t__n3_msg_create_raid_mangled_name = static_cast<char*>(
	"?N3Msg_CreateRaid@n3EngineClientAnarchy_t@@QAEXXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_create_raid_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 4C 56 57 FF 15 ?? ?? ?? ?? 8B F0 33 FF 3B F7 74 ?? 8B CE");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_create_raid_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_create_raid_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_default_action_on_dynel

constexpr char* const n3_engine_client_anarchy_t__n3_msg_default_action_on_dynel_mangled_name = static_cast<char*>(
	"?N3Msg_DefaultActionOnDynel@n3EngineClientAnarchy_t@@QAEXABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_default_action_on_dynel_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 2C 56 8B 75 08");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_default_action_on_dynel_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_default_action_on_dynel_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_default_attack

constexpr char* const n3_engine_client_anarchy_t__n3_msg_default_attack_mangled_name = static_cast<char*>(
	"?N3Msg_DefaultAttack@n3EngineClientAnarchy_t@@QBEXABVIdentity_t@@_N@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_default_attack_pattern = static_cast<char*>(
	"55 8B EC 51 53 56 57 8B D9 E8 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_default_attack_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_default_attack_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_delete_item

constexpr char* const n3_engine_client_anarchy_t__n3_msg_delete_item_mangled_name = static_cast<char*>(
	"?N3Msg_DeleteItem@n3EngineClientAnarchy_t@@QBEXABVIdentity_t@@0@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_delete_item_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 70 53 56 FF 15 ?? ?? ?? ?? 8B F0 33 DB 3B F3 0F 84 ?? ?? ?? ?? 8B 8E BC 01 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_delete_item_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_delete_item_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_delete_nano

constexpr char* const n3_engine_client_anarchy_t__n3_msg_delete_nano_mangled_name = static_cast<char*>(
	"?N3Msg_DeleteNano@n3EngineClientAnarchy_t@@QAEXABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_delete_nano_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 70 53 56 FF 15 ?? ?? ?? ?? 8B F0 33 DB 3B F3 0F 84 ?? ?? ?? ?? 57");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_delete_nano_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_delete_nano_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_do_social_action

constexpr char* const n3_engine_client_anarchy_t__n3_msg_do_social_action_mangled_name = static_cast<char*>(
	"?N3Msg_DoSocialAction@n3EngineClientAnarchy_t@@QAEXW4AbstractAnimID_e@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_do_social_action_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 0C 53 56 8B D9");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_do_social_action_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_do_social_action_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_drop_item

constexpr char* const n3_engine_client_anarchy_t__n3_msg_drop_item_mangled_name = static_cast<char*>(
	"?N3Msg_DropItem@n3EngineClientAnarchy_t@@QBEXABVIdentity_t@@ABVVector3_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_drop_item_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 48 53 E8 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_drop_item_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_drop_item_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_duel_accept

constexpr char* const n3_engine_client_anarchy_t__n3_msg_duel_accept_mangled_name = static_cast<char*>(
	"?N3Msg_Duel_Accept@n3EngineClientAnarchy_t@@QAEXXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_duel_accept_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 81 EC 88 00 00 00 53 56 33 DB");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_duel_accept_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_duel_accept_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_duel_challenge

constexpr char* const n3_engine_client_anarchy_t__n3_msg_duel_challenge_mangled_name = static_cast<char*>(
	"?N3Msg_Duel_Challenge@n3EngineClientAnarchy_t@@QAEXABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_duel_challenge_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 70 53 56 33 DB 53 8B F1 68 ?? ?? ?? ?? 8D 4D D0 C7 45 E4 0F 00 00 00 89 5D E0 88 5D D0 E8 ?? ?? ?? ?? 8B 86 84 00 00 00 8D 4D D0 51 8D 4D EC 51 68 06 01 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_duel_challenge_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_duel_challenge_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_duel_draw

constexpr char* const n3_engine_client_anarchy_t__n3_msg_duel_draw_mangled_name = static_cast<char*>(
	"?N3Msg_Duel_Draw@n3EngineClientAnarchy_t@@QAEXXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_duel_draw_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 78 53 56 33 DB 53 8B F1 68 ?? ?? ?? ?? 8D 4D C8 C7 45 DC 0F 00 00 00 89 5D D8 88 5D C8 E8 ?? ?? ?? ?? 8B 86 84 00 00 00 8D 4D C8 51 8D 4D EC 51 68 06 01 00 00 53 8D 4D E4 51 83 C0 14 50 8D 8D 7C FF FF FF 89 5D FC C7 45 EC 04 00 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_duel_draw_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_duel_draw_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_duel_refuse

constexpr char* const n3_engine_client_anarchy_t__n3_msg_duel_refuse_mangled_name = static_cast<char*>(
	"?N3Msg_Duel_Refuse@n3EngineClientAnarchy_t@@QAEXXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_duel_refuse_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 81 EC 84 00 00 00 53 56");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_duel_refuse_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_duel_refuse_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_duel_stop

constexpr char* const n3_engine_client_anarchy_t__n3_msg_duel_stop_mangled_name = static_cast<char*>(
	"?N3Msg_Duel_Stop@n3EngineClientAnarchy_t@@QAEXXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_duel_stop_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 78 53 56 33 DB 53 8B F1 68 ?? ?? ?? ?? 8D 4D C8 C7 45 DC 0F 00 00 00 89 5D D8 88 5D C8 E8 ?? ?? ?? ?? 8B 86 84 00 00 00 8D 4D C8 51 8D 4D EC 51 68 06 01 00 00 53 8D 4D E4 51 83 C0 14 50 8D 8D 7C FF FF FF 89 5D FC C7 45 EC 03 00 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_duel_stop_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_duel_stop_bytes_to_next = 0x0;

#pragma endregion

#pragma region  n3_engine_client_anarchy_t__n3_msg_forage

constexpr char* const n3_engine_client_anarchy_t__n3_msg_forage_mangled_name = static_cast<char*>(
	"?N3Msg_Forage@n3EngineClientAnarchy_t@@QAEXXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_forage_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 78 53 56 33 DB 53 8B F1 68 ?? ?? ?? ?? 8D 4D C8 C7 45 DC 0F 00 00 00 89 5D D8 88 5D C8 E8 ?? ?? ?? ?? 8B 86 84 00 00 00 8D 4D C8 51 8D 4D EC 51 68 CA 00 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_forage_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_forage_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_action_by_name

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_action_by_name_mangled_name = static_cast<char*>(
	"?N3Msg_GetActionByName@n3EngineClientAnarchy_t@@QBE?AW4AbstractAnimID_e@@PBD@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_action_by_name_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_action_by_name_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_action_by_name_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_action_progress

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_action_progress_mangled_name = static_cast<char*>(
	"?N3Msg_GetActionProgress@n3EngineClientAnarchy_t@@QBEMABVIdentity_t@@PAH1@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_action_progress_pattern = static_cast<char*>(
	"55 8B EC 56 57 E8 ?? ?? ?? ?? 8B F0 85 F6 0F 84 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_action_progress_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_action_progress_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_agg_def

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_agg_def_mangled_name = static_cast<char*>(
	"?N3Msg_GetAggDef@n3EngineClientAnarchy_t@@QBEHXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_agg_def_pattern = static_cast<char*>(
	"E8 ?? ?? ?? ?? 85 C0 75 ?? C3 8D 88 EC 00 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_agg_def_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_agg_def_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_alien_level_string

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_alien_level_string_mangled_name = static_cast<char*>(
	"?N3Msg_GetAlienLevelString@n3EngineClientAnarchy_t@@QBEPBDABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_alien_level_string_pattern = static_cast<char*>(
	"55 8B EC 6A 00 68 ?? ?? ?? ?? 68 ?? ?? ?? ?? 6A 00 FF 75 08 FF 15 ?? ?? ?? ?? 59 50 E8 ?? ?? ?? ?? 83 C4 14 85 C0 74 ?? 8D 88 EC 00 00 00 8B 01 6A 02 68 A9 00 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_alien_level_string_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_alien_level_string_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_area_name

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_area_name_mangled_name = static_cast<char*>(
	"?N3Msg_GetAreaName@n3EngineClientAnarchy_t@@QBEXPAPBD@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_area_name_pattern = static_cast<char*>(
	"55 8B EC 8B 45 08 83 20 00 8B 89 84 00 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_area_name_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_area_name_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_attacking_id

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_attacking_id_mangled_name = static_cast<char*>(
	"?N3Msg_GetAttackingID@n3EngineClientAnarchy_t@@QBE_NAAVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_attacking_id_pattern = static_cast<char*>(
	"55 8B EC E8 ?? ?? ?? ?? 85 C0 74 ?? 8B 88 D8 01 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_attacking_id_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_attacking_id_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_breed_str

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_breed_str_mangled_name = static_cast<char*>(
	"?N3Msg_GetBreedStr@n3EngineClientAnarchy_t@@QBEPBDABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_breed_str_pattern = static_cast<char*>(
	"55 8B EC 56 6A 00 68 ?? ?? ?? ?? 68 ?? ?? ?? ?? 6A 00 FF 75 08 FF 15 ?? ?? ?? ?? 59 50 E8 ?? ?? ?? ?? 83 C4 14");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_breed_str_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_breed_str_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_buff_current_time

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_buff_current_time_mangled_name = static_cast<char*>(
	"?N3Msg_GetBuffCurrentTime@n3EngineClientAnarchy_t@@QAEHABVIdentity_t@@0@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_buff_current_time_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_buff_current_time_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_buff_current_time_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_buff_total_time

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_buff_total_time_mangled_name = static_cast<char*>(
	"?N3Msg_GetBuffTotalTime@n3EngineClientAnarchy_t@@QAEHABVIdentity_t@@0@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_buff_total_time_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_buff_total_time_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_buff_total_time_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_character_body_shape

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_character_body_shape_mangled_name = static_cast<char*>(
	"?N3Msg_GetCharacterBodyShape@n3EngineClientAnarchy_t@@QAE_NAAEVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_character_body_shape_pattern = static_cast<char*>(
	"55 8B EC 83 7D 10 00 75 ?? 83 7D 0C 00 75 ?? FF 15 ?? ?? ?? ?? EB ?? 8D 45 0C 50 E8 ?? ?? ?? ?? 59 85 C0 75 ?? 32 C0 EB ?? 8B C8");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_character_body_shape_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_character_body_shape_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_char_orientation_data

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_char_orientation_data_mangled_name = static_cast<char*>(
	"?N3Msg_GetCharOrientationData@n3EngineClientAnarchy_t@@QBE_NABVIdentity_t@@AAVVector3_t@@AAVQuaternion_t@@AAM@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_char_orientation_data_pattern = static_cast<char*>(
	"55 8B EC 83 EC 10 53 FF 75 08");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_char_orientation_data_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_char_orientation_data_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_city_name_for_clan_member

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_city_name_for_clan_member_mangled_name = static_cast<char*>(
	"?N3Msg_GetCityNameForClanMember@n3EngineClientAnarchy_t@@QBEPBDABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_city_name_for_clan_member_pattern = static_cast<char*>(
	"55 8B EC 56 6A 00 68 ?? ?? ?? ?? 68 ?? ?? ?? ?? 6A 00 FF 75 08 FF 15 ?? ?? ?? ?? 59 50 E8 ?? ?? ?? ?? 8B F0 83 C4 14 85 F6 74 ?? 8B CE E8 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_city_name_for_clan_member_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_city_name_for_clan_member_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_clan_level_string

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_clan_level_string_mangled_name = static_cast<char*>(
	"?N3Msg_GetClanLevelString@n3EngineClientAnarchy_t@@QBEPBDABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_clan_level_string_pattern = static_cast<char*>(
	"55 8B EC FF 75 08 E8 ?? ?? ?? ?? 59 85 C0 74 ?? 8B C8 E8 ?? ?? ?? ?? 8B 40 7C 85 C0");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_clan_level_string_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_clan_level_string_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_clan_string

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_clan_string_mangled_name = static_cast<char*>(
	"?N3Msg_GetClanString@n3EngineClientAnarchy_t@@QBEPBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@ABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_clan_string_pattern = static_cast<char*>(
	"55 8B EC FF 75 08 E8 ?? ?? ?? ?? 59 85 C0 74 ?? 8B C8 E8 ?? ?? ?? ?? 8B 80 A0 00 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_clan_string_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_clan_string_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_client_pet_id

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_client_pet_id_mangled_name = static_cast<char*>(
	"?N3Msg_GetClientPetID@n3EngineClientAnarchy_t@@QBE?AVIdentity_t@@H@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_client_pet_id_pattern = static_cast<char*>(
	"55 8B EC FF 15 ?? ?? ?? ?? 85 C0 75 ?? 8B 45 08");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_client_pet_id_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_client_pet_id_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_close_target

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_close_target_mangled_name = static_cast<char*>(
	"?N3Msg_GetCloseTarget@n3EngineClientAnarchy_t@@QBE_NAAVIdentity_t@@_N1@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_close_target_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 70 53 8B 99 84 00 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_close_target_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_close_target_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_container_inventory_list

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_container_inventory_list_mangled_name = static_cast<char*>(
	"?N3Msg_GetContainerInventoryList@n3EngineClientAnarchy_t@@QBEPBV?$list@VInventoryEntry_t@@V?$allocator@VInventoryEntry_t@@@std@@@std@@ABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_container_inventory_list_pattern = static_cast<char*>(
	"55 8B EC 51 53 8B 5D 08 81 3B 50 C3 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_container_inventory_list_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_container_inventory_list_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_correct_action_id

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_correct_action_id_mangled_name = static_cast<char*>(
	"?N3Msg_GetCorrectActionID@n3EngineClientAnarchy_t@@QBEXAAVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_correct_action_id_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_correct_action_id_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_correct_action_id_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_current_room

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_current_room_mangled_name = static_cast<char*>(
	"?N3Msg_GetCurrentRoom@n3EngineClientAnarchy_t@@QBEIXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_current_room_pattern = static_cast<char*>(
	"56 57 FF 15 ?? ?? ?? ?? 8B F8 85 FF");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_current_room_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_current_room_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_current_room_name

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_current_room_name_mangled_name = static_cast<char*>(
	"?N3Msg_GetCurrentRoomName@n3EngineClientAnarchy_t@@QBEPBDXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_current_room_name_pattern = static_cast<char*>(
	"8B 89 84 00 00 00 85 C9 74 ?? E8 ?? ?? ?? ?? 8B C8 E9 ?? ?? ?? ?? 33 C0");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_current_room_name_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_current_room_name_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_district_fight_mode

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_district_fight_mode_mangled_name = static_cast<char*>(
	"?N3Msg_GetDistrictFightMode@n3EngineClientAnarchy_t@@QAE?AW4FightTypeAllowed_e@@XZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_district_fight_mode_pattern = static_cast<char*>(
	"8B 89 84 00 00 00 85 C9 74 ?? E8 ?? ?? ?? ?? 8B C8 E9 ?? ?? ?? ?? 83 C8 FF");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_district_fight_mode_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_district_fight_mode_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_dynels_in_vicinity

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_dynels_in_vicinity_mangled_name = static_cast<char*>(
	"?N3Msg_GetDynelsInVicinity@n3EngineClientAnarchy_t@@QBEXAAV?$vector@VIdentity_t@@V?$allocator@VIdentity_t@@@std@@@std@@_N1W4TypeID_e@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_dynels_in_vicinity_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 14 53 56 57 8B F9 FF 15 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_dynels_in_vicinity_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_dynels_in_vicinity_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_faction_info_string

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_faction_info_string_mangled_name = static_cast<char*>(
	"?N3Msg_GetFactionInfoString@n3EngineClientAnarchy_t@@QBE_NABVIdentity_t@@AAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_faction_info_string_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 5C 53 56 57 33 DB");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_faction_info_string_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_faction_info_string_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_faction_range

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_faction_range_mangled_name = static_cast<char*>(
	"?N3Msg_GetFactionRange@n3EngineClientAnarchy_t@@QBE_NHAAH0@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_faction_range_pattern = static_cast<char*>(
	"55 8B EC FF 75 10 FF 75 0C");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_faction_range_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_faction_range_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_first_name

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_first_name_mangled_name = static_cast<char*>(
	"?N3Msg_GetFirstName@n3EngineClientAnarchy_t@@QBEPBDABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_first_name_pattern = static_cast<char*>(
	"55 8B EC 6A 00 68 ?? ?? ?? ?? 68 ?? ?? ?? ?? 6A 00 FF 75 08 FF 15 ?? ?? ?? ?? 59 50 E8 ?? ?? ?? ?? 83 C4 14 85 C0 74 ?? 05 74 01 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_first_name_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_first_name_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_formula_progress

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_formula_progress_mangled_name = static_cast<char*>(
	"?N3Msg_GetFormulaProgress@n3EngineClientAnarchy_t@@QBEMABVIdentity_t@@PAH1@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_formula_progress_pattern = static_cast<char*>(
	"55 8B EC 6A 00 68 ?? ?? ?? ?? 68 ?? ?? ?? ?? 6A 00 FF 15 ?? ?? ?? ?? 50 E8 ?? ?? ?? ?? 83 C4 14 85 C0 74 ?? FF 75 10");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_formula_progress_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_formula_progress_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_formula_radius

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_formula_radius_mangled_name = static_cast<char*>(
	"?N3Msg_GetFormularRadius@n3EngineClientAnarchy_t@@QBEHABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_formula_radius_pattern = static_cast<char*>(
	"55 8B EC 8B 45 08 81 38 1B CF 00 00 75 ?? FF 70 04 E8 ?? ?? ?? ?? 59 85 C0 74 ?? 8B 80 B8 00 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_formula_radius_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_formula_radius_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_full_perk_map

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_full_perk_map_mangled_name = static_cast<char*>(
	"?N3Msg_GetFullPerkMap@n3EngineClientAnarchy_t@@QBEABV?$vector@VPerk_t@@V?$allocator@VPerk_t@@@std@@@std@@XZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_full_perk_map_pattern = static_cast<char*>(
	"E8 ?? ?? ?? ?? 83 C0 34 C3");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_full_perk_map_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_full_perk_map_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_global_character_position

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_global_character_position_mangled_name = static_cast<char*>(
	"?N3Msg_GetGlobalCharacterPosition@n3EngineClientAnarchy_t@@QAEXAAVVector3_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_global_character_position_pattern = static_cast<char*>(
	"55 8B EC FF 15 ?? ?? ?? ?? 85 C0 74 ?? 56");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_global_character_position_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_global_character_position_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_global_character_rotation

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_global_character_rotation_mangled_name = static_cast<char*>(
	"?N3Msg_GetGlobalCharacterRotation@n3EngineClientAnarchy_t@@QAEXAAVQuaternion_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_global_character_rotation_pattern = static_cast<char*>(
	"55 8B EC 83 EC 10 FF 15 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_global_character_rotation_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_global_character_rotation_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_1

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_1_mangled_name = static_cast<char*>(
	"?N3Msg_GetGridDestinationList@n3EngineClientAnarchy_t@@QBEPBVGridDestinationList_t@@ABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_1_pattern = static_cast<char*>(
	"55 8B EC 6A 00 68 ?? ?? ?? ?? 68 ?? ?? ?? ?? 6A 00 FF 75 08 FF 15 ?? ?? ?? ?? 59 50 E8 ?? ?? ?? ?? 83 C4 14 85 C0 74 ?? 8B C8 E8 ?? ?? ?? ?? 8B 40 7C");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_1_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_1_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_2

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_2_mangled_name = static_cast<char*>(
	"?N3Msg_GetGridDestinationList@n3EngineClientAnarchy_t@@QBEPBVGridDestinationList_t@@ABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_2_pattern = static_cast<char*>(
	"8D 81 A0 00 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_2_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_grid_destination_list_2_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_inventory_vec

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_inventory_vec_mangled_name = static_cast<char*>(
	"?N3Msg_GetInventoryVec@n3EngineClientAnarchy_t@@QAEPBV?$vector@PAVNewInventoryEntry_t@@V?$allocator@PAVNewInventoryEntry_t@@@std@@@std@@ABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_inventory_vec_pattern = static_cast<char*>(
	"55 8B EC 8B 45 08 81 38 50 C3 00 00 6A 00 75 ?? 68 ?? ?? ?? ?? 68 ?? ?? ?? ?? 6A 00 50 FF 15 ?? ?? ?? ?? 59 50 E8 ?? ?? ?? ?? 83 C4 14 85 C0 74 ?? 8B 80 BC 01 00 00 8B 40 08");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_inventory_vec_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_inventory_vec_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_item

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_item_mangled_name = static_cast<char*>(
	"?N3Msg_GetItem@n3EngineClientAnarchy_t@@QBEXABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_item_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 20 56 E8 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_item_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_item_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_item_progress

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_item_progress_mangled_name = static_cast<char*>(
	"?N3Msg_GetItemProgress@n3EngineClientAnarchy_t@@QBEMABVIdentity_t@@PAH1@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_item_progress_pattern = static_cast<char*>(
	"55 8B EC 6A 00 68 ?? ?? ?? ?? 68 ?? ?? ?? ?? 6A 00 FF 15 ?? ?? ?? ?? 50 E8 ?? ?? ?? ?? 83 C4 14 85 C0 74 ?? 8B 88 BC 01 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_item_progress_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_item_progress_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_movement_mode

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_movement_mode_mangled_name = static_cast<char*>(
	"?N3Msg_GetMovementMode@n3EngineClientAnarchy_t@@QBEHXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_movement_mode_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_movement_mode_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_movement_mode_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_name

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_name_mangled_name = static_cast<char*>(
	"?N3Msg_GetName@n3EngineClientAnarchy_t@@QBEPBDABVIdentity_t@@0@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_name_pattern = static_cast<char*>(
	"55 8B EC 83 EC 18 53 56 8B 75 08 57 89 4D F4");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_name_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_name_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_nano_cost_modifier

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_nano_cost_modifier_mangled_name = static_cast<char*>(
	"?N3Msg_GetNanoCostModifier@n3EngineClientAnarchy_t@@QBEHXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_nano_cost_modifier_pattern = static_cast<char*>(
	"E8 ?? ?? ?? ?? 85 C0 75 ?? C3 8B 88 C4 01 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_nano_cost_modifier_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_nano_cost_modifier_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_nano_spell_list

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_nano_spell_list_mangled_name = static_cast<char*>(
	"?N3Msg_GetNanoSpellList@n3EngineClientAnarchy_t@@QAEPBV?$list@HV?$allocator@H@std@@@std@@XZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_nano_spell_list_pattern = static_cast<char*>(
	"FF 15 ?? ?? ?? ?? 85 C0 74 ?? 8B 80 C4 01 00 00 83 C0 14");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_nano_spell_list_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_nano_spell_list_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_1

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_1_mangled_name = static_cast<char*>(
	"?N3Msg_GetNanoTemplateInfoList@n3EngineClientAnarchy_t@@QBEPAV?$list@VNanoTemplateInfo_c@@V?$allocator@VNanoTemplateInfo_c@@@std@@@std@@ABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_1_pattern = static_cast<char*>(
	"55 8B EC 6A 00 68 ?? ?? ?? ?? 68 ?? ?? ?? ?? 6A 00 FF 75 08 FF 15 ?? ?? ?? ?? 59 50 E8 ?? ?? ?? ?? 83 C4 14 85 C0 74 ?? 8B 80 C4 01 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_1_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_1_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_2

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_2_mangled_name = static_cast<char*>(
	"?N3Msg_GetNanoTemplateInfoList@n3EngineClientAnarchy_t@@QBEPAV?$list@VNanoTemplateInfo_c@@V?$allocator@VNanoTemplateInfo_c@@@std@@@std@@XZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_2_pattern = static_cast<char*>(
	"FF 15 ?? ?? ?? ?? 85 C0 74 ?? 8B 80 C4 01 00 00 83 C0 20");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_2_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_nano_template_info_list_2_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_next_target

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_next_target_mangled_name = static_cast<char*>(
	"?N3Msg_GetNextTarget@n3EngineClientAnarchy_t@@QAE?AVIdentity_t@@ABV2@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_next_target_pattern = static_cast<char*>(
	"55 8B EC 51 51 8B 49 7C");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_next_target_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_next_target_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_number_of_available_alien_perks

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_number_of_available_alien_perks_mangled_name = static_cast<char*>(
	"?N3Msg_GetNumberOfAvailableAlienPerks@n3EngineClientAnarchy_t@@QAEHXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_number_of_available_alien_perks_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_available_alien_perks_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_available_alien_perks_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_number_of_available_perks

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_number_of_available_perks_mangled_name = static_cast<char*>(
	"?N3Msg_GetNumberOfAvailablePerks@n3EngineClientAnarchy_t@@QAEHXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_number_of_available_perks_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_available_perks_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_available_perks_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_number_of_free_inventory_slots

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_number_of_free_inventory_slots_mangled_name = static_cast<char*>(
	"?N3Msg_GetNumberOfFreeInventorySlots@n3EngineClientAnarchy_t@@QAEHXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_number_of_free_inventory_slots_pattern = static_cast<char*>(
	"E8 ?? ?? ?? ?? 85 C0 74 ?? 8B 88 BC 01 00 00 E9 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_free_inventory_slots_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_free_inventory_slots_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_number_of_used_alien_perks

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_number_of_used_alien_perks_mangled_name = static_cast<char*>(
	"?N3Msg_GetNumberOfUsedAlienPerks@n3EngineClientAnarchy_t@@QAEHXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_number_of_used_alien_perks_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_used_alien_perks_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_used_alien_perks_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_number_of_used_perks

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_number_of_used_perks_mangled_name = static_cast<char*>(
	"?N3Msg_GetNumberOfUsedPerks@n3EngineClientAnarchy_t@@QAEHXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_number_of_used_perks_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_used_perks_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_number_of_used_perks_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_over_equip_level

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_over_equip_level_mangled_name = static_cast<char*>(
	"?N3Msg_GetOverEquipLevel@n3EngineClientAnarchy_t@@QBEHABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_over_equip_level_pattern = static_cast<char*>(
	"55 8B EC 56 8B 75 08 8B 06 83 F8 65");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_over_equip_level_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_over_equip_level_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_pf_name_1

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_pf_name_1_mangled_name = static_cast<char*>(
	"?N3Msg_GetPFName@n3EngineClientAnarchy_t@@QBEPBDI@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_pf_name_1_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_pf_name_1_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_pf_name_1_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_pf_name_2

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_pf_name_2_mangled_name = static_cast<char*>(
	"?N3Msg_GetPFName@n3EngineClientAnarchy_t@@QBEPBDXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_pf_name_2_pattern = static_cast<char*>(
	"55 8B EC 8B 89 84 00 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_pf_name_2_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_pf_name_2_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_parent

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_parent_mangled_name = static_cast<char*>(
	"?N3Msg_GetParent@n3EngineClientAnarchy_t@@QBE_NABVIdentity_t@@AAV2@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_parent_pattern = static_cast<char*>(
	"55 8B EC FF 75 08 FF 15 ?? ?? ?? ?? 59 85 C0 74 ?? 8B C8 FF 15 ?? ?? ?? ?? 8B 10");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_parent_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_parent_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_pos

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_pos_mangled_name = static_cast<char*>(
	"?N3Msg_GetPos@n3EngineClientAnarchy_t@@QBE_NABVIdentity_t@@AAVVector3_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_pos_pattern = static_cast<char*>(
	"55 8B EC FF 75 08 FF 15 ?? ?? ?? ?? 59 85 C0 74 ?? 56");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_pos_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_pos_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_skill_1

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_skill_1_mangled_name = static_cast<char*>(
	"?N3Msg_GetSkill@n3EngineClientAnarchy_t@@QBEHW4Stat_e@GameData@@H@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_skill_1_pattern = static_cast<char*>(
	"55 8B EC E8 ?? ?? ?? ?? 33 D2");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_skill_1_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_skill_1_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_skill_2

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_skill_2_mangled_name = static_cast<char*>(
	"?N3Msg_GetSkill@n3EngineClientAnarchy_t@@QBEHABVIdentity_t@@W4Stat_e@GameData@@H0@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_skill_2_pattern = static_cast<char*>(
	"55 8B EC 51 51 56 8B 75 08 57 8B F9 68 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_skill_2_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_skill_2_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_skill_max

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_skill_max_mangled_name = static_cast<char*>(
	"?N3Msg_GetSkillMax@n3EngineClientAnarchy_t@@QAEHW4Stat_e@GameData@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_skill_max_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_skill_max_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_skill_max_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_special_action_list

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_special_action_list_mangled_name = static_cast<char*>(
	"?N3Msg_GetSpecialActionList@n3EngineClientAnarchy_t@@QAEPAV?$list@VSpecialAction_t@@V?$allocator@VSpecialAction_t@@@std@@@std@@XZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_special_action_list_pattern = static_cast<char*>(
	"E8 ?? ?? ?? ?? 85 C0 74 ?? 8B C8 E8 ?? ?? ?? ?? 8B C8 E9 ?? ?? ?? ?? 33 C0");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_special_action_list_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_special_action_list_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_special_action_state

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_special_action_state_mangled_name = static_cast<char*>(
	"?N3Msg_GetSpecialActionState@n3EngineClientAnarchy_t@@QAEHABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_special_action_state_pattern = static_cast<char*>(
	"55 8B EC E8 ?? ?? ?? ?? 85 C0 74 ?? FF 75 08 8B C8 E8 ?? ?? ?? ?? 8B C8 E8 ?? ?? ?? ?? EB ?? 33 C0 40");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_special_action_state_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_special_action_state_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_special_attack_weapon_name

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_special_attack_weapon_name_mangled_name = static_cast<char*>(
	"?N3Msg_GetSpecialAttackWeaponName@n3EngineClientAnarchy_t@@QBEPBDABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_special_attack_weapon_name_pattern = static_cast<char*>(
	"55 8B EC E8 ?? ?? ?? ?? 85 C0 74 ?? 8B 80 D8 01 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_special_attack_weapon_name_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_special_attack_weapon_name_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_stat_name_map

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_stat_name_map_mangled_name = static_cast<char*>(
	"?N3Msg_GetStatNameMap@n3EngineClientAnarchy_t@@QAEABV?$map@HPBDU?$less@H@std@@V?$allocator@U?$pair@$$CBHPBD@std@@@2@@std@@XZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_stat_name_map_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_stat_name_map_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_stat_name_map_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_target_target

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_target_target_mangled_name = static_cast<char*>(
	"?N3Msg_GetTargetTarget@n3EngineClientAnarchy_t@@QAE?AVIdentity_t@@AAV2@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_target_target_pattern = static_cast<char*>(
	"55 8B EC FF 75 0C E8 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_target_target_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_target_target_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_get_team_member_list

constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_team_member_list_mangled_name = static_cast<char*>(
	"?N3Msg_GetTeamMemberList@n3EngineClientAnarchy_t@@QAEPAV?$vector@PAVTeamEntry_t@@V?$allocator@PAVTeamEntry_t@@@std@@@std@@H@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_get_team_member_list_pattern = static_cast<char*>(
	"55 8B EC 56 FF 15 ?? ?? ?? ?? 8B F0 85 F6 74 ?? 8B CE E8 ?? ?? ?? ?? 8B C8 E8 ?? ?? ?? ?? 84 C0 74 ?? 8B CE E8 ?? ?? ?? ?? 8B C8");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_team_member_list_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_get_team_member_list_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_has_perk

constexpr char* const n3_engine_client_anarchy_t__n3_msg_has_perk_mangled_name = static_cast<char*>(
	"?N3Msg_HasPerk@n3EngineClientAnarchy_t@@QAE_NI@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_has_perk_pattern = static_cast<char*>(
	"55 8B EC E8 ?? ?? ?? ?? 85 C0 74 ?? FF 75 08 8B C8 E8 ?? ?? ?? ?? 8B C8 E8 ?? ?? ?? ?? F7 D8");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_has_perk_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_has_perk_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_hide_against_opponent
constexpr char* const n3_engine_client_anarchy_t__n3_msg_hide_against_opponent_mangled_name = static_cast<char*>(
	"?N3Msg_HideAgainstOpponent@n3EngineClientAnarchy_t@@QBEXABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_hide_against_opponent_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 70 53 56 33 DB 53 8B F1 68 ?? ?? ?? ?? 8D 4D D0 C7 45 E4 0F 00 00 00 89 5D E0 88 5D D0 E8 ?? ?? ?? ?? 8B 86 84 00 00 00 8D 4D D0 51 8D 4D EC 51 6A 36");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_hide_against_opponent_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_hide_against_opponent_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_attacking

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_attacking_mangled_name = static_cast<char*>(
	"?N3Msg_IsAttacking@n3EngineClientAnarchy_t@@QBE_NXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_attacking_pattern = static_cast<char*>(
	"53 32 DB E8 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_attacking_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_attacking_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_battle_station

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_battle_station_mangled_name = static_cast<char*>(
	"?N3Msg_IsBattleStation@n3EngineClientAnarchy_t@@QAE_NXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_battle_station_pattern = static_cast<char*>(
	"FF 15 ?? ?? ?? ?? 85 C0 74 ?? 8B C8 FF 15 ?? ?? ?? ?? 50 FF 15 ?? ?? ?? ?? 59 85 C0 74 ?? 8B C8");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_battle_station_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_battle_station_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_character_in_mech

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_character_in_mech_mangled_name = static_cast<char*>(
	"?N3Msg_IsCharacterInMech@n3EngineClientAnarchy_t@@QAE_NVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_character_in_mech_pattern = static_cast<char*>(
	"55 8B EC 83 7D 0C 00 75 ?? 83 7D 08 00 75 ?? FF 15 ?? ?? ?? ?? EB ?? 8D 45 08 50 E8 ?? ?? ?? ?? 59 85 C0 75 ?? 32 C0 EB ?? 8B C8");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_character_in_mech_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_character_in_mech_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_character_morphed

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_character_morphed_mangled_name = static_cast<char*>(
	"?N3Msg_IsCharacterMorphed@n3EngineClientAnarchy_t@@QAE_NVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_character_morphed_pattern = static_cast<char*>(
	"55 8B EC 83 7D 0C 00 75 ?? 83 7D 08 00 75 ?? FF 15 ?? ?? ?? ?? EB ?? 8D 45 08 50 E8 ?? ?? ?? ?? 59 85 C0 75 ?? 32 C0 EB ?? 8B 80 DC 01 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_character_morphed_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_character_morphed_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_dungeon

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_dungeon_mangled_name = static_cast<char*>(
	"?N3Msg_IsDungeon@n3EngineClientAnarchy_t@@QBE_NXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_dungeon_pattern = static_cast<char*>(
	"8B 89 84 00 00 00 85 C9 74 ?? FF 15 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_dungeon_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_dungeon_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_formula_ready

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_formula_ready_mangled_name = static_cast<char*>(
	"?N3Msg_IsFormulaReady@n3EngineClientAnarchy_t@@QBE_NABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_formula_ready_pattern = static_cast<char*>(
	"55 8B EC 56 6A 00 68 ?? ?? ?? ?? 68 ?? ?? ?? ?? 6A 00 FF 15 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_formula_ready_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_formula_ready_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_general_perk

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_general_perk_mangled_name = static_cast<char*>(
	"?N3Msg_IsGeneralPerk@n3EngineClientAnarchy_t@@QBE_NI@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_general_perk_pattern = static_cast<char*>(
	"55 8B EC E8 ?? ?? ?? ?? FF 75 08 8B C8 E8 ?? ?? ?? ?? 85 C0 74 ?? 33 C9");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_general_perk_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_general_perk_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_group_perk

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_group_perk_mangled_name = static_cast<char*>(
	"?N3Msg_IsGroupPerk@n3EngineClientAnarchy_t@@QBE_NI@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_group_perk_pattern = static_cast<char*>(
	"55 8B EC 56 57 E8 ?? ?? ?? ?? 8B F8");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_group_perk_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_group_perk_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_in_raid_team

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_in_raid_team_mangled_name = static_cast<char*>(
	"?N3Msg_IsInRaidTeam@n3EngineClientAnarchy_t@@QAE_NXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_in_raid_team_pattern = static_cast<char*>(
	"FF 15 ?? ?? ?? ?? 85 C0 74 ?? 8B C8 E8 ?? ?? ?? ?? 8B C8 E9 ?? ?? ?? ?? 32 C0");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_in_raid_team_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_in_raid_team_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_in_team

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_in_team_mangled_name = static_cast<char*>(
	"?N3Msg_IsInTeam@n3EngineClientAnarchy_t@@QBE_NABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_in_team_pattern = static_cast<char*>(
	"55 8B EC 8B 45 08 83 38 00 75 ?? 83 78 04 00 75 ?? FF 15 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_in_team_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_in_team_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_item_disabled

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_item_disabled_mangled_name = static_cast<char*>(
	"?N3Msg_IsItemDisabled@n3EngineClientAnarchy_t@@QBE_NABVIdentity_t@@0@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_item_disabled_pattern = static_cast<char*>(
	"55 8B EC 8B 45 0C 53 33 DB 39 18 75 ?? 39 58 04 75 ?? E8 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_item_disabled_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_item_disabled_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_item_mine

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_item_mine_mangled_name = static_cast<char*>(
	"?N3Msg_IsItemMine@n3EngineClientAnarchy_t@@QBE_NABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_item_mine_pattern = static_cast<char*>(
	"55 8B EC FF 15 ?? ?? ?? ?? 85 C0 74 ?? 8B 80 BC 01 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_item_mine_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_item_mine_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_item_nf_crystal

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_item_nf_crystal_mangled_name = static_cast<char*>(
	"?N3Msg_IsItemNFCrystal@n3EngineClientAnarchy_t@@QBE_NAAVIdentity_t@@ABV2@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_item_nf_crystal_pattern = static_cast<char*>(
	"55 8B EC 83 EC 18 53 56 8B 75 08 8B 16");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_item_nf_crystal_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_item_nf_crystal_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_item_possible_to_un_wear

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_item_possible_to_un_wear_mangled_name = static_cast<char*>(
	"?N3Msg_IsItemPossibleToUnWear@n3EngineClientAnarchy_t@@QBE_NABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_item_possible_to_un_wear_pattern = static_cast<char*>(
	"55 8B EC 56 8B 75 08 8B 06 57 8B F9 83 F8 65");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_item_possible_to_un_wear_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_item_possible_to_un_wear_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_item_possible_to_wear

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_item_possible_to_wear_mangled_name = static_cast<char*>(
	"?N3Msg_IsItemPossibleToWear@n3EngineClientAnarchy_t@@QBE_NABVIdentity_t@@HH_NW4InventoryId_e@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_item_possible_to_wear_pattern = static_cast<char*>(
	"55 8B EC 51 51 57 E8 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_item_possible_to_wear_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_item_possible_to_wear_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_moving

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_moving_mangled_name = static_cast<char*>(
	"?N3Msg_IsMoving@n3EngineClientAnarchy_t@@QBE_NXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_moving_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_moving_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_moving_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_my_pet_id

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_my_pet_id_mangled_name = static_cast<char*>(
	"?N3Msg_IsMyPetID@n3EngineClientAnarchy_t@@QBE_NABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_my_pet_id_pattern = static_cast<char*>(
	"55 8B EC FF 15 ?? ?? ?? ?? 85 C0 75 ?? 32 C0");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_my_pet_id_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_my_pet_id_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_nano_self_only

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_nano_self_only_mangled_name = static_cast<char*>(
	"?N3Msg_IsNanoSelfOnly@n3EngineClientAnarchy_t@@QBE_NABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_nano_self_only_pattern = static_cast<char*>(
	"55 8B EC 8B 45 08 81 38 1B CF 00 00 75 ?? FF 70 04 E8 ?? ?? ?? ?? 59 85 C0 74 ?? 8A 80 BC 00 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_nano_self_only_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_nano_self_only_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_npc

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_npc_mangled_name = static_cast<char*>(
	"?N3Msg_IsNpc@n3EngineClientAnarchy_t@@QBE_NABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_npc_pattern = static_cast<char*>(
	"55 8B EC 6A 00 68 ?? ?? ?? ?? 68 ?? ?? ?? ?? 6A 00 FF 75 08 FF 15 ?? ?? ?? ?? 59 50 E8 ?? ?? ?? ?? 83 C4 14 85 C0 74 ?? 80 B8 20 02 00 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_npc_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_npc_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_perk

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_perk_mangled_name = static_cast<char*>(
	"?N3Msg_IsPerk@n3EngineClientAnarchy_t@@QBE_NI@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_perk_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_perk_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_perk_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_is_pet_tower

constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_pet_tower_mangled_name = static_cast<char*>(
	"?N3Msg_IsPetTower@n3EngineClientAnarchy_t@@QBE_NABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_is_pet_tower_pattern = static_cast<char*>(
	"55 8B EC FF 75 08 E8 ?? ?? ?? ?? 59 85 C0 75 ?? 32 C0 EB ?? 8D 88 EC 00 00 00 8B 01 6A 02 68 00 02 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_pet_tower_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_is_pet_tower_bytes_to_next = 0x0;

#pragma endregion








#pragma region n3_engine_client_anarchy_t__n3_msg_movement_changed

constexpr char* const n3_engine_client_anarchy_t__n3_msg_movement_changed_mangled_name = static_cast<char*>(
	"?N3Msg_MovementChanged@n3EngineClientAnarchy_t@@QAEXW4MovementAction_e@Movement_n@@MM_N@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_movement_changed_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 70 53 56 57 8B F9");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_movement_changed_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_movement_changed_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_name_to_id

constexpr char* const n3_engine_client_anarchy_t__n3_msg_name_to_id_mangled_name = static_cast<char*>(
	"?N3Msg_NameToID@n3EngineClientAnarchy_t@@QBE_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AAVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_name_to_id_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 10 E8 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_name_to_id_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_name_to_id_bytes_to_next = 0x0;

#pragma endregion


#pragma region n3_engine_client_anarchy_t__n3_msg_perform_special_action_1

constexpr char* const n3_engine_client_anarchy_t__n3_msg_perform_special_action_1_mangled_name = static_cast<char*>(
	"?N3Msg_PerformSpecialAction@n3EngineClientAnarchy_t@@QAE_NW4Action_e@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_perform_special_action_1_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_perform_special_action_1_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_perform_special_action_1_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_perform_special_action_2

constexpr char* const n3_engine_client_anarchy_t__n3_msg_perform_special_action_2_mangled_name = static_cast<char*>(
	"?N3Msg_PerformSpecialAction@n3EngineClientAnarchy_t@@QAE_NABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_perform_special_action_2_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_perform_special_action_2_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_perform_special_action_2_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_request_info_packet

constexpr char* const n3_engine_client_anarchy_t__n3_msg_request_info_packet_mangled_name = static_cast<char*>(
	"?N3Msg_RequestInfoPacket@n3EngineClientAnarchy_t@@QAEXABVIdentity_t@@@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_request_info_packet_pattern = static_cast<char*>(nullptr);
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_request_info_packet_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_request_info_packet_bytes_to_next = 0x0;

#pragma endregion


#pragma region n3_engine_client_anarchy_t__n3_msg_send_pet_command

constexpr char* const n3_engine_client_anarchy_t__n3_msg_send_pet_command_mangled_name = static_cast<char*>(
	"?N3Msg_SendPetCommand@n3EngineClientAnarchy_t@@QBEXHABVIdentity_t@@HHPBD@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_send_pet_command_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 48 53 56 57 FF 75 18");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_send_pet_command_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_send_pet_command_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_sit_toggle

constexpr char* const n3_engine_client_anarchy_t__n3_msg_sit_toggle_mangled_name = static_cast<char*>(
	"?N3Msg_SitToggle@n3EngineClientAnarchy_t@@QAEXXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_sit_toggle_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 81 EC 04 01 00 00");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_sit_toggle_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_sit_toggle_bytes_to_next = 0x0;


#pragma endregion


#pragma region n3_engine_client_anarchy_t__n3_msg_stop_attack

constexpr char* const n3_engine_client_anarchy_t__n3_msg_stop_attack_mangled_name = static_cast<char*>(
	"?N3Msg_StopAttack@n3EngineClientAnarchy_t@@QBEXXZ");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_stop_attack_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 1C 56 8B F1 E8 ?? ?? ?? ??");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_stop_attack_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_stop_attack_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_use_item

constexpr char* const n3_engine_client_anarchy_t__n3_msg_use_item_mangled_name = static_cast<char*>(
	"?N3Msg_UseItem@n3EngineClientAnarchy_t@@QAEXABVIdentity_t@@_N@Z");
constexpr char* const n3_engine_client_anarchy_t__n3_msg_use_item_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 81 EC A8 00 00 00 53 56 57");
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_use_item_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__n3_msg_use_item_bytes_to_next = 0x0;

#pragma endregion

#pragma region n3_engine_client_anarchy_t__on_closed

constexpr char* const n3_engine_client_anarchy_t__on_closed_mangled_name = static_cast<char*>(
	"?OnClosed@n3EngineClientAnarchy_t@@UAEXXZ");
constexpr char* const n3_engine_client_anarchy_t__on_closed_pattern = static_cast<char*>(
	"56 8D B1 90 00 00 00");
constexpr DWORD n3_engine_client_anarchy_t__on_closed_offset = 0x0;
constexpr DWORD n3_engine_client_anarchy_t__on_closed_bytes_to_next = 0x0;

#pragma endregion

#pragma region playfield_anarchy_t__playfield_anarchy_t

constexpr char* const playfield_anarchy_t__playfield_anarchy_t_mangled_name = static_cast<char*>(
	"??0PlayfieldAnarchy_t@@QAE@ABVPlayfieldProxy_t@@@Z");
constexpr char* const playfield_anarchy_t__playfield_anarchy_t_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 51 56 57 FF 75 08 8B F1 89 75 F0 FF 15 ?? ?? ?? ??");
constexpr DWORD playfield_anarchy_t__playfield_anarchy_t_offset = 0x0;
constexpr DWORD playfield_anarchy_t__playfield_anarchy_t_bytes_to_next = 0x0;

#pragma endregion

#pragma region playfield_anarchy_t__d_playfield_anarchy_t

constexpr char* const playfield_anarchy_t__d_playfield_anarchy_t_mangled_name = static_cast<char*>(
	"??1PlayfieldAnarchy_t@@MAE@XZ");
constexpr char* const playfield_anarchy_t__d_playfield_anarchy_t_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 51 51 53 56 8B F1 57 89 75 EC C7 06 ?? ?? ?? ?? 8B 86 A0 00 00 00");
constexpr DWORD playfield_anarchy_t__d_playfield_anarchy_t_offset = 0x0;
constexpr DWORD playfield_anarchy_t__d_playfield_anarchy_t_bytes_to_next = 0x0;

#pragma endregion


#pragma region simple_char_t__check_los

constexpr char* const simple_char_t__check_los_mangled_name = static_cast<char*>(nullptr);
constexpr char* const simple_char_t__check_los_pattern = static_cast<char*>(
	"55 8B EC 83 EC 30 56 57 8B 7D 08");
constexpr DWORD simple_char_t__check_los_offset = 0x0;
constexpr DWORD simple_char_t__check_los_bytes_to_next = 0x0;

#pragma endregion

#pragma region static_item_manager_t__static_item_manager_t

constexpr char* const static_item_manager_t__static_item_manager_t_mangled_name = static_cast<char*>(nullptr);
constexpr char* const static_item_manager_t__static_item_manager_t_pattern = static_cast<char*>(nullptr);
constexpr DWORD static_item_manager_t__static_item_manager_t_offset = 0x76;
constexpr DWORD static_item_manager_t__static_item_manager_t_bytes_to_next = 0x0;

#pragma endregion

// Instances

#pragma region game_time_t__m_pc_instance

constexpr char* const game_time_t__m_pc_instance_mangled_name = static_cast<char*>(
	"?m_pcInstance@GameTime_t@@0PAV1@A");
constexpr DWORD game_time_t__m_pc_instance_offset = 0xB;

#pragma endregion

#pragma region m_c_nano_item_dir

constexpr char* const m_c_nano_item_dir_mangled_name = static_cast<char*>(nullptr);
constexpr DWORD m_c_nano_item_dir_offset = 0x13;

#pragma endregion

#pragma region m_c_stat_name_dir

constexpr char* const m_c_stat_name_dir_mangled_name = static_cast<char*>(nullptr);
constexpr DWORD m_c_stat_name_dir_offset = 0x1F;

#pragma endregion

#pragma region item_manager_t__m_ppc_instance

constexpr char* const item_manager_t__m_ppc_instance_mangled_name = static_cast<char*>(nullptr);
constexpr DWORD item_manager_t__m_ppc_instance_offset = 0xC;

#pragma endregion

#pragma region static_item_manager_t__m_ppc_instance

constexpr char* const static_item_manager_t__m_ppc_instance_mangled_name = static_cast<char*>(nullptr);
constexpr DWORD static_item_manager_t__m_ppc_instance_offset = 0xC;

#pragma endregion

#pragma endregion

#pragma region GUI

// Module
constexpr char* const gui_module_name = static_cast<char*>("GUI.dll");

// Functions

#pragma region chat_gui_module_c__chat_gui_module_c

constexpr char* const chat_gui_module_c__chat_gui_module_c_mangled_name = static_cast<char*>(
	"??0ChatGUIModule_c@@QAE@XZ");
constexpr char* const chat_gui_module_c__chat_gui_module_c_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 40 53 56 57 8B 3D ?? ?? ?? ??");
constexpr DWORD chat_gui_module_c__chat_gui_module_c_offset = 0x0;
constexpr DWORD chat_gui_module_c__chat_gui_module_c_bytes_to_next = 0x0;

#pragma endregion

#pragma region chat_gui_module_c__handle_group_action

constexpr char* const chat_gui_module_c__handle_group_action_mangled_name = static_cast<char*>(
	"?HandleGroupAction@ChatGUIModule_c@@AAEXPBUGroupAction_t@Client_c@ppj@@@Z");
constexpr char* const chat_gui_module_c__handle_group_action_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 3C 56 8B 75 08 8B 46 08");
constexpr DWORD chat_gui_module_c__handle_group_action_offset = 0x0;
constexpr DWORD chat_gui_module_c__handle_group_action_bytes_to_next = 0x0;

#pragma endregion

#pragma region chat_gui_module_c__handle_group_message

constexpr char* const chat_gui_module_c__handle_group_message_mangled_name = static_cast<char*>(
	"?HandleGroupMessage@ChatGUIModule_c@@AAEXPBUGroupMessage_t@Client_c@ppj@@@Z");
constexpr char* const chat_gui_module_c__handle_group_message_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 81 EC 18 01 00 00 53 33 DB");
constexpr DWORD chat_gui_module_c__handle_group_message_offset = 0x0;
constexpr DWORD chat_gui_module_c__handle_group_message_bytes_to_next = 0x0;

#pragma endregion

#pragma region chat_gui_module_c__handle_private_group_action

constexpr char* const chat_gui_module_c__handle_private_group_action_mangled_name = static_cast<char*>(
	"?HandlePrivateGroupAction@ChatGUIModule_c@@AAEXPBUPrivateGroupAction_t@Client_c@ppj@@@Z");
constexpr char* const chat_gui_module_c__handle_private_group_action_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 38 56 8B 75 08");
constexpr DWORD chat_gui_module_c__handle_private_group_action_offset = 0x0;
constexpr DWORD chat_gui_module_c__handle_private_group_action_bytes_to_next = 0x0;

#pragma endregion

#pragma region chat_gui_module_c__handle_private_message

constexpr char* const chat_gui_module_c__handle_private_message_mangled_name = static_cast<char*>(
	"?HandlePrivateMessage@ChatGUIModule_c@@AAEXPBUPrivateMessage_t@Client_c@ppj@@@Z");
constexpr char* const chat_gui_module_c__handle_private_message_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 81 EC 0C 07 00 00");
constexpr DWORD chat_gui_module_c__handle_private_message_offset = 0x0;
constexpr DWORD chat_gui_module_c__handle_private_message_bytes_to_next = 0x0;

#pragma endregion

#pragma region chat_gui_module_c__handle_system_message

constexpr char* const chat_gui_module_c__handle_system_message_mangled_name = static_cast<char*>(
	"?HandleSystemMessage@ChatGUIModule_c@@AAEXPBUSystemMessage_t@Client_c@ppj@@@Z");
constexpr char* const chat_gui_module_c__handle_system_message_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 44 53 56 8B 75 08");
constexpr DWORD chat_gui_module_c__handle_system_message_offset = 0x0;
constexpr DWORD chat_gui_module_c__handle_system_message_bytes_to_next = 0x0;

#pragma endregion

#pragma region chat_gui_module_c__handle_vicinity_message

constexpr char* const chat_gui_module_c__handle_vicinity_message_mangled_name = static_cast<char*>(
	"?HandleVicinityMessage@ChatGUIModule_c@@AAEXPBUVisinityMessage_t@Client_c@ppj@@@Z");
constexpr char* const chat_gui_module_c__handle_vicinity_message_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 81 EC 44 02 00 00");
constexpr DWORD chat_gui_module_c__handle_vicinity_message_offset = 0x0;
constexpr DWORD chat_gui_module_c__handle_vicinity_message_bytes_to_next = 0x0;

#pragma endregion

#pragma region chat_window_node_c__parse_text_command

constexpr char* const chat_window_node_c__parse_text_command_mangled_name = static_cast<char*>(nullptr);
constexpr char* const chat_window_node_c__parse_text_command_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 5C 56 FF 75 08");
constexpr DWORD chat_window_node_c__parse_text_command_offset = 0;
constexpr DWORD chat_window_node_c__parse_text_command_bytes_to_next = 0;

#pragma endregion

#pragma region command_interpreter_c__command_interpreter_c

constexpr char* const command_interpreter_c__command_interpreter_c_mangled_name = static_cast<char*>(nullptr);
constexpr char* const command_interpreter_c__command_interpreter_c_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 51 A1 ?? ?? ?? ?? 85 C0 75 ?? 68 80 00 00 00");
constexpr DWORD command_interpreter_c__command_interpreter_c_offset = 0x0;
constexpr DWORD command_interpreter_c__command_interpreter_c_bytes_to_next = 0x0;

#pragma endregion

#pragma region command_interpreter_c__parse_text_command

constexpr char* const command_interpreter_c__parse_text_command_mangled_name = static_cast<char*>(nullptr);
constexpr char* const command_interpreter_c__parse_text_command_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 81 EC 84 00 00 00 53 56 33 F6");
constexpr DWORD command_interpreter_c__parse_text_command_offset = 0x0;
constexpr DWORD command_interpreter_c__parse_text_command_bytes_to_next = 0x0;

#pragma endregion

#pragma region command_t__execute_1

constexpr char* const command_t__execute_1_mangled_name = static_cast<char*>(
	"?Execute@Command_t@@QBEXPAPBVIdentity_t@@HPAXPAVVector3_t@@@Z");
constexpr char* const command_t__execute_1_pattern = static_cast<char*>(
	"55 8B EC 51 8B C1 83 78 04 FF");
constexpr DWORD command_t__execute_1_offset = 0x0;
constexpr DWORD command_t__execute_1_bytes_to_next = 0x0;

#pragma endregion

#pragma region command_list_t__command_list_t

constexpr char* const command_list_t__command_list_t_mangled_name = static_cast<char*>(
	"??0CommandList_t@@AAE@XZ");
constexpr char* const command_list_t__command_list_t_pattern = static_cast<char*>(
	"56 8B F1 89 35 ?? ?? ?? ??");
constexpr DWORD command_list_t__command_list_t_offset = 0x0;
constexpr DWORD command_list_t__command_list_t_bytes_to_next = 0x0;

#pragma endregion

#pragma region flow_control_module_t__get_instance

constexpr char* const flow_control_module_t__get_instance_mangled_name = static_cast<char*>(
	"?GetInstance@FlowControlModule_t@@SAPAV1@XZ");
constexpr char* const flow_control_module_t__get_instance_pattern = static_cast<char*>(nullptr);
constexpr DWORD flow_control_module_t__get_instance_offset = 0x0;
constexpr DWORD flow_control_module_t__get_instance_bytes_to_next = 0x0;

#pragma endregion

#pragma region flow_control_module_t__slot_movement_back

constexpr char* const flow_control_module_t__slot_movement_back_mangled_name = static_cast<char*>(
	"?SlotMovementBack@FlowControlModule_t@@AAEX_N@Z");
constexpr char* const flow_control_module_t__slot_movement_back_pattern = static_cast<char*>(
	"55 8B EC 51 56 8B 35 ?? ?? ?? ?? FF D6 8B C8 FF 15 ?? ?? ?? ?? 83 F8 08 75 ?? 68 E3 00 00 00 6A 0A FF 15 ?? ?? ?? ?? 8B C8 FF 15 ?? ?? ?? ?? D9 EE 8D 45 FC 50 D9 5D FC 33 C0 38 45 08 0F 95 C0 83 C0 03");
constexpr DWORD flow_control_module_t__slot_movement_back_offset = 0x0;
constexpr DWORD flow_control_module_t__slot_movement_back_bytes_to_next = 0x0;

#pragma endregion

#pragma region flow_control_module_t__slot_movement_forward

constexpr char* const flow_control_module_t__slot_movement_forward_mangled_name = static_cast<char*>(
	"?SlotMovementForward@FlowControlModule_t@@AAEX_N@Z");
constexpr char* const flow_control_module_t__slot_movement_forward_pattern = static_cast<char*>(
	"55 8B EC 51 56 8B 35 ?? ?? ?? ?? FF D6 8B C8 FF 15 ?? ?? ?? ?? 83 F8 08 75 ?? 68 E3 00 00 00 6A 0A FF 15 ?? ?? ?? ?? 8B C8 FF 15 ?? ?? ?? ?? D9 EE 8D 45 FC 50 D9 5D FC 33 C0 38 45 08 0F 95 C0 40");
constexpr DWORD flow_control_module_t__slot_movement_forward_offset = 0x0;
constexpr DWORD flow_control_module_t__slot_movement_forward_bytes_to_next = 0x0;

#pragma endregion

#pragma region flow_control_module_t__slot_movement_jump

constexpr char* const flow_control_module_t__slot_movement_jump_mangled_name = static_cast<char*>(
	"?SlotMovementJump@FlowControlModule_t@@AAEX_N@Z");
constexpr char* const flow_control_module_t__slot_movement_jump_pattern = static_cast<char*>(
	"55 8B EC 80 7D 08 00 75 ?? D9 EE");
constexpr DWORD flow_control_module_t__slot_movement_jump_offset = 0x0;
constexpr DWORD flow_control_module_t__slot_movement_jump_bytes_to_next = 0x0;

#pragma endregion

#pragma region flow_control_module_t__slot_movement_left

constexpr char* const flow_control_module_t__slot_movement_left_mangled_name = static_cast<char*>(
	"?SlotMovementLeft@FlowControlModule_t@@AAEX_N@Z");
constexpr char* const flow_control_module_t__slot_movement_left_pattern = static_cast<char*>(
	"55 8B EC 51 D9 EE 8D 45 FC 50 D9 5D FC 33 C0 38 45 08 0F 95 C0 8D 44 00 0C");
constexpr DWORD flow_control_module_t__slot_movement_left_offset = 0x0;
constexpr DWORD flow_control_module_t__slot_movement_left_bytes_to_next = 0x0;

#pragma endregion

#pragma region flow_control_module_t__slot_movement_right

constexpr char* const flow_control_module_t__slot_movement_right_mangled_name = static_cast<char*>(
	"?SlotMovementRight@FlowControlModule_t@@AAEX_N@Z");
constexpr char* const flow_control_module_t__slot_movement_right_pattern = static_cast<char*>(
	"55 8B EC 51 D9 EE 8D 45 FC 50 D9 5D FC 33 C0 38 45 08 0F 95 C0 8D 44 00 09");
constexpr DWORD flow_control_module_t__slot_movement_right_offset = 0x0;
constexpr DWORD flow_control_module_t__slot_movement_right_bytes_to_next = 0x0;

#pragma endregion

#pragma region flow_control_module_t__slot_movement_strafe_left

constexpr char* const flow_control_module_t__slot_movement_strafe_left_mangled_name = static_cast<char*>(
	"?SlotMovementStrafeLeft@FlowControlModule_t@@AAEX_N@Z");
constexpr char* const flow_control_module_t__slot_movement_strafe_left_pattern = static_cast<char*>(
	"55 8B EC 51 56 8B 35 ?? ?? ?? ?? FF D6 8B C8 FF 15 ?? ?? ?? ?? 83 F8 08 75 ?? 68 E3 00 00 00 6A 0A FF 15 ?? ?? ?? ?? 8B C8 FF 15 ?? ?? ?? ?? D9 EE 8D 45 FC 50 D9 5D FC 33 C0 38 45 08 0F 95 C0 83 C0 07");
constexpr DWORD flow_control_module_t__slot_movement_strafe_left_offset = 0x0;
constexpr DWORD flow_control_module_t__slot_movement_strafe_left_bytes_to_next = 0x0;

#pragma endregion

#pragma region flow_control_module_t__slot_movement_strafe_right

constexpr char* const flow_control_module_t__slot_movement_strafe_right_mangled_name = static_cast<char*>(
	"?SlotMovementStrafeRight@FlowControlModule_t@@AAEX_N@Z");
constexpr char* const flow_control_module_t__slot_movement_strafe_right_pattern = static_cast<char*>(
	"55 8B EC 51 56 8B 35 ?? ?? ?? ?? FF D6 8B C8 FF 15 ?? ?? ?? ?? 83 F8 08 75 ?? 68 E3 00 00 00 6A 0A FF 15 ?? ?? ?? ?? 8B C8 FF 15 ?? ?? ?? ?? D9 EE 8D 45 FC 50 D9 5D FC 33 C0 38 45 08 0F 95 C0 83 C0 05");
constexpr DWORD flow_control_module_t__slot_movement_strafe_right_offset = 0x0;
constexpr DWORD flow_control_module_t__slot_movement_strafe_right_bytes_to_next = 0x0;

#pragma endregion

#pragma region flow_control_module_t__slot_walk_toggle

constexpr char* const flow_control_module_t__slot_walk_toggle_mangled_name = static_cast<char*>(
	"?SlotMovementWalkToggle@FlowControlModule_t@@AAEX_N@Z");
constexpr char* const flow_control_module_t__slot_walk_toggle_pattern = static_cast<char*>(
	"55 8B EC 80 7D 08 00 75 ?? 56 8B 35 ?? ?? ?? ?? FF D6");
constexpr DWORD flow_control_module_t__slot_walk_toggle_offset = 0x0;
constexpr DWORD flow_control_module_t__slot_walk_toggle_bytes_to_next = 0x0;

#pragma endregion

#pragma region html_parser_c__html_parser_c_1

const char* const html_parser_c__html_parser_c_1_mangled_name = static_cast<char*>(
	"??0HTMLParser_c@@QAE@ABV0@@Z");
const char* const html_parser_c__html_parser_c_1_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 51 56 57 8B 7D 08 8B F1 8D 47 04");
constexpr DWORD html_parser_c__html_parser_c_1_offset = 0;
constexpr DWORD html_parser_c__html_parser_c_1_bytes_to_next = 0;

#pragma endregion

#pragma region html_parser_c__html_parser_c_2

const char* const html_parser_c__html_parser_c_2_mangled_name = static_cast<char*>(
	"??0HTMLParser_c@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@IW4FontID_e@@_N@Z");
const char* const html_parser_c__html_parser_c_2_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 48 53 56 8B F1 57 FF 75 08");
constexpr DWORD html_parser_c__html_parser_c_2_offset = 0;
constexpr DWORD html_parser_c__html_parser_c_2_bytes_to_next = 0;

#pragma endregion

#pragma region html_parser_c__d_html_parser_c

const char* const html_parser_c__d_html_parser_c_mangled_name = static_cast<char*>(
	"??1HTMLParser_c@@UAE@XZ");
const char* const html_parser_c__d_html_parser_c_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 51 56 8B F1 89 75 F0 C7 06 ?? ?? ?? ?? 8D 4E 30");
constexpr DWORD html_parser_c__d_html_parser_c_offset = 0;
constexpr DWORD html_parser_c__d_html_parser_c_bytes_to_next = 0;

#pragma endregion

#pragma region html_parser_c__extract_text

const char* const html_parser_c__extract_text_mangled_name = static_cast<char*>(
	"?ExtractText@HTMLParser_c@@QBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@HHI@Z");
const char* const html_parser_c__extract_text_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 20 83 65 F0 00 53 8B 5D 10");
constexpr DWORD html_parser_c__extract_text_offset = 0;
constexpr DWORD html_parser_c__extract_text_bytes_to_next = 0;

#pragma endregion

#pragma region input_config_t__get_instance

const char* const input_config_t__get_instance_mangled_name = static_cast<char*>(
	"?GetInstance@InputConfig_t@@SAPAV1@XZ");
const char* const input_config_t__get_instance_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 51 83 3D ?? ?? ?? ?? 00 75 ?? 68 D0 01 00 00");
constexpr DWORD input_config_t__get_instance_offset = 0;
constexpr DWORD input_config_t__get_instance_bytes_to_next = 0;

#pragma endregion

#pragma region input_config_t__set_current_target

const char* const input_config_t__set_current_target_mangled_name = static_cast<char*>(
	"?SetCurrentTarget@InputConfig_t@@QAEXABVIdentity_t@@@Z");
const char* const input_config_t__set_current_target_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 0C 56 57 8B 7D 08 8D B1 C0 00 00 00");
constexpr DWORD input_config_t__set_current_target_offset = 0;
constexpr DWORD input_config_t__set_current_target_bytes_to_next = 0;

#pragma endregion

#pragma region input_config_t__check_input

constexpr char* const input_config_t__check_input_mangled_name = static_cast<char*>(
	"?CheckInput@InputConfig_t@@QAEXABVInputInfo_t@@@Z");
constexpr char* const input_config_t__check_input_pattern = static_cast<char*>(
	"55 8B EC 51 53 56 57 8B 7D 08 8B F1 8B 0F");
constexpr DWORD input_config_t__check_input_offset = 0x0;
constexpr DWORD input_config_t__check_input_bytes_to_next = 0x0;

#pragma endregion

#pragma region input_config_t__process_input

constexpr char* const input_config_t__process_input_mangled_name = static_cast<char*>(
	"?ProcessInput@InputConfig_t@@QAE_NHW4RepeatMode_e@1@@Z");
constexpr char* const input_config_t__process_input_pattern = static_cast<char*>(
	"55 8B EC 83 EC 24 57");
constexpr DWORD input_config_t__process_input_offset = 0x0;
constexpr DWORD input_config_t__process_input_bytes_to_next = 0x0;

#pragma endregion

#pragma region targeting_module_t__initialise_message

const char* const targeting_module_t__initialise_message_mangled_name = static_cast<char*>(
	"?InitialiseMessage@TargetingModule_t@@CAXXZ");
const char* const targeting_module_t__initialise_message_pattern = static_cast<char*>(
	"8B 0D ?? ?? ?? ?? 56 57");
constexpr DWORD targeting_module_t__initialise_message_offset = 0;
constexpr DWORD targeting_module_t__initialise_message_bytes_to_next = 0;

#pragma endregion

#pragma region targeting_module_t__remove_target

constexpr char* const targeting_module_t__remove_target_mangled_name = static_cast<char*>(
	"?RemoveTarget@TargetingModule_t@@CAXABVIdentity_t@@@Z");
constexpr char* const targeting_module_t__remove_target_pattern = static_cast<char*>(
	"55 8B EC 8B 45 08 8B 08 89 0D ?? ?? ?? ??");
constexpr DWORD targeting_module_t__remove_target_offset = 0x0;
constexpr DWORD targeting_module_t__remove_target_bytes_to_next = 0x0;

#pragma endregion

#pragma region targeting_module_t__select_self

constexpr char* const targeting_module_t__select_self_mangled_name = static_cast<char*>(
	"?SelectSelf@TargetingModule_t@@QAEXXZ");
constexpr char* const targeting_module_t__select_self_pattern = static_cast<char*>(
	"55 8B EC 51 51 E8 ?? ?? ?? ?? 8B 88 D8 00 00 00");
constexpr DWORD targeting_module_t__select_self_offset = 0x0;
constexpr DWORD targeting_module_t__select_self_bytes_to_next = 0x0;

#pragma endregion

#pragma region targeting_module_t__set_target

const char* const targeting_module_t__set_target_mangled_name = static_cast<char*>(
	"?SetTarget@TargetingModule_t@@CAXABVIdentity_t@@_N@Z");
const char* const targeting_module_t__set_target_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 51 51 A1 ?? ?? ?? ??");
constexpr DWORD targeting_module_t__set_target_offset = 0x0;
constexpr DWORD targeting_module_t__set_target_bytes_to_next = 0x0;

#pragma endregion

#pragma region targeting_module_t__set_target_pet

constexpr char* const targeting_module_t__set_target_pet_mangled_name = static_cast<char*>(
	"?SetTargetPet@TargetingModule_t@@AAEXH@Z");
constexpr char* const targeting_module_t__set_target_pet_pattern = static_cast<char*>(
	"55 8B EC 51 51 FF 75 08 8D 45 F8 50 E8 ?? ?? ?? ?? 8B C8");
constexpr DWORD targeting_module_t__set_target_pet_offset = 0x0;
constexpr DWORD targeting_module_t__set_target_pet_bytes_to_next = 0x0;

#pragma endregion

#pragma region targeting_module_t__targeting_module_t

const char* const targeting_module_t__targeting_module_t_mangled_name = static_cast<char*>(
	"??0TargetingModule_t@@AAE@XZ");
const char* const targeting_module_t__targeting_module_t_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 14 53 56 8B F1 57 89 75 F0 FF 15 ?? ?? ?? ?? D9 EE");
constexpr DWORD targeting_module_t__targeting_module_t_offset = 0x0;
constexpr DWORD targeting_module_t__targeting_module_t_bytes_to_next = 0x0;

#pragma endregion

#pragma region window_controller_t__get_instance

const char* const window_controller_t__get_instance_mangled_name = static_cast<char*>(
	"?GetInstance@WindowController_c@@SAPAV1@XZ");
const char* const window_controller_t__get_instance_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 51 A1 ?? ?? ?? ?? 85 C0 75 ?? 68 98 01 00 00");
constexpr DWORD window_controller_t__get_instance_offset = 0x0;
constexpr DWORD window_controller_t__get_instance_bytes_to_next = 0x0;

#pragma endregion

#pragma region window_controller_t__handle_key_down

constexpr char* const window_controller_t__handle_key_down_mangled_name = static_cast<char*>(
	"?HandleKeyDown@WindowController_c@@QAEXABI0@Z");
constexpr char* const window_controller_t__handle_key_down_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 10 57 8B F9 33 D2");
constexpr DWORD window_controller_t__handle_key_down_offset = 0x0;
constexpr DWORD window_controller_t__handle_key_down_bytes_to_next = 0x0;

#pragma endregion

#pragma region window_controller_t__handle_key_up

constexpr char* const window_controller_t__handle_key_up_mangled_name = static_cast<char*>(
	"?HandleKeyUp@WindowController_c@@QAEXABI0@Z");
constexpr char* const window_controller_t__handle_key_up_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 10 56 8B F1 33 D2");
constexpr DWORD window_controller_t__handle_key_up_offset = 0x0;
constexpr DWORD window_controller_t__handle_key_up_bytes_to_next = 0x0;

#pragma endregion

// Instances

#pragma region chat_gui_module_c__s_pc_instance

constexpr char* const chat_gui_module_c__s_pc_instance_mangled_name = static_cast<char*>(
	"?s_pcInstance@ChatGUIModule_c@@0PAV1@A");
constexpr DWORD chat_gui_module_c__s_pc_instance_offset = 0x169;

#pragma endregion

#pragma region command_interpreter_c__m_pc_instance

constexpr char* const command_interpreter_c__m_pc_instance_mangled_name = static_cast<char*>(nullptr);
constexpr DWORD command_interpreter_c__m_pc_instance_offset = 0xC;

#pragma endregion

#pragma region command_list_t__m_pc_instance

constexpr char* const command_list_t__m_pc_instance_mangled_name = static_cast<char*>(
	"?m_pcInstance@CommandList_t@@0PAV1@A");
constexpr DWORD command_list_t__m_pc_instance_offset = 0x4;

#pragma endregion

#pragma region flow_control_module_t__m_pc_instance

constexpr char* const flow_control_module_t__m_pc_instance_mangled_name = static_cast<char*>(
	"?m_pcInstance@FlowControlModule_t@@0PAV1@A");
constexpr DWORD flow_control_module_t__m_pc_instance_offset = 0xC;

#pragma endregion

#pragma region input_config_t__m_pc_instance

constexpr char* const input_config_t__m_pc_instance_mangled_name = static_cast<char*>(
	"?m_pcInstance@InputConfig_t@@0PAV1@A");
constexpr DWORD input_config_t__m_pc_instance_offset = 0xC;

#pragma endregion

#pragma region targeting_module_t__m_pc_instance

constexpr char* const targeting_module_t__m_pc_instance_mangled_name = static_cast<char*>(
	"?m_pcInstance@TargetingModule_t@@0PAV1@A");
constexpr DWORD targeting_module_t__m_pc_instance_offset = 0xD;

#pragma endregion

#pragma region targeting_module_t__m_pc_selection_indicator

constexpr char* const targeting_module_t__m_pc_selection_indicator_mangled_name = static_cast<char*>(
	"?m_pcSelectionIndicator@TargetingModule_t@@0PAVIndicator_t@@A");
constexpr DWORD targeting_module_t__m_pc_selection_indicator_offset = 0x1A;

#pragma endregion

#pragma region targeting_module_t__m_pc_attacking_indicator

constexpr char* const targeting_module_t__m_pc_attacking_indicator_mangled_name = static_cast<char*>(
	"?m_pcAttackingIndicator@TargetingModule_t@@0PAVIndicator_t@@A");
constexpr DWORD targeting_module_t__m_pc_attacking_indicator_offset = 0x1F;

#pragma endregion

#pragma region targeting_module_t__m_c_last_target

constexpr char* const targeting_module_t__m_c_last_target_mangled_name = static_cast<char*>(
	"?m_cLastTarget@TargetingModule_t@@0VIdentity_t@@A");
constexpr DWORD targeting_module_t__m_c_last_target_offset = 0x25;

#pragma endregion

#pragma region window_controller_c__s_pc_instance

constexpr char* const window_controller_c__s_pc_instance_mangled_name = static_cast<char*>(
	"?s_pcInstance@WindowController_c@@0PAV1@A");
constexpr DWORD window_controller_c__s_pc_instance_offset = 0xC;

#pragma endregion

#pragma endregion

#pragma region Interfaces

constexpr char* const interfaces_module_name = static_cast<char*>("Interfaces.dll");

constexpr char* const client_t__s_n_char_id_mangled_name = static_cast<char*>(
	"?s_nCharID@Client_t@@0IA");

constexpr char* const client_t__process_message_mangled_name = static_cast<char*>(
	"?ProcessMessage@Client_t@@AAEHPAVMessage_t@@@Z");
constexpr char* const client_t__process_message_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 81 EC 40 06 00 00");

#pragma endregion

#pragma region Vehicle

constexpr char* const vehicle_module_name = static_cast<char*>("Vehicle.dll");

constexpr char* const vehicle_t__set_rel_rot_mangled_name = static_cast<char*>(
	"?SetRelRot@Vehicle_t@@QAEXABVQuaternion_t@@@Z");
constexpr char* const vehicle_t__set_rel_rot_pattern = static_cast<char*>(
	"55 8B EC 83 EC 18 53");

#pragma endregion

#pragma region Pathfinder

constexpr char* const pathfinder_module_name = static_cast<char*>("Pathfinder.dll");

constexpr char* const graph_path_finder_t__graph_path_finder_t_1_mangled_name = static_cast<char*>(
	"??0GraphPathFinder_t@@QAE@ABV0@@Z");
constexpr char* const graph_path_finder_t__graph_path_finder_t_1_pattern = static_cast<char*>(
	"55 8B EC 8B C1 8B 4D 08 C7 00 ?? ?? ?? ??");

constexpr char* const graph_path_finder_t__graph_path_finder_t_2_mangled_name = static_cast<char*>(
	"??0GraphPathFinder_t@@QAE@I@Z");
constexpr char* const graph_path_finder_t__graph_path_finder_t_2_pattern = static_cast<char*>(
	"56 8B F1 E8 ?? ?? ?? ?? D9 05 ?? ?? ?? ??");

constexpr char* const graph_path_finder_t__d_graph_path_finder_t_mangled_name = static_cast<char*>(
	"??1GraphPathFinder_t@@UAE@XZ");
constexpr char* const graph_path_finder_t__d_graph_path_finder_t_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 51 56 8B F1 57 89 75 F0");

constexpr char* const graph_path_finder_t__configure_mangled_name = static_cast<char*>(
	"?Configure@GraphPathFinder_t@@QAEXHHMM@Z");
constexpr char* const graph_path_finder_t__configure_pattern = static_cast<char*>(
	"55 8B EC 8B 45 08 D9 45 10");

constexpr char* const graph_path_finder_t__create_from_data_mangled_name = static_cast<char*>(
	"?CreateFromData@GraphPathFinder_t@@QAEXABVVisibilityGraphData_t@GameData@@@Z");

constexpr char* const graph_path_finder_t__find_path_mangled_name = static_cast<char*>(
	"?FindPath@GraphPathFinder_t@@UBE?AW4PathStatus_e@Pathfinder_i@@ABVVector3_t@@0AAV?$vector@VVector3_t@@V?$allocator@VVector3_t@@@std@@@std@@PAVLocalitySource_t@@_N3@Z");
constexpr char* const graph_path_finder_t__find_path_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 44 53 56 8B F1 33 DB");

constexpr char* const graph_path_finder_t__generate_graph_mangled_name = static_cast<char*>(
	"?GenerateGraph@GraphPathFinder_t@@QAEXAAV?$vector@VVector3_t@@V?$allocator@VVector3_t@@@std@@@std@@MMMMPAVProgressMonitor_i@@_N@Z");
constexpr char* const graph_path_finder_t__generate_graph_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 81 EC 80 00 00 00");

constexpr char* const graph_path_finder_t__generate_graph_for_room_mangled_name = static_cast<char*>(
	"?GenerateGraphForRoom@GraphPathFinder_t@@QAEXABV?$vector@VBoxRegion_t@@V?$allocator@VBoxRegion_t@@@std@@@std@@ABV?$vector@VVector3_t@@V?$allocator@VVector3_t@@@std@@@3@ABV?$vector@U?$pair@IVVector3_t@@@std@@V?$allocator@U?$pair@IVVector3_t@@@std@@@2@@3@MMMMH@Z");
constexpr char* const graph_path_finder_t__generate_graph_for_room_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 EC 64 53 56 8B F1 E8 ?? ?? ?? ??");

constexpr char* const graph_path_finder_t__init_mangled_name = static_cast<char*>(
	"?Init@GraphPathFinder_t@@QAEXXZ");
constexpr char* const graph_path_finder_t__init_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 51 56 8B F1 57 8B 7E 04");

constexpr char* const graph_path_finder_t__set_space_for_graph_mangled_name = static_cast<char*>(
	"?SetSpaceForGraph@GraphPathFinder_t@@QAEXPAVSpace_i@@@Z");
constexpr char* const graph_path_finder_t__set_space_for_graph_pattern = static_cast<char*>(
	"55 8B EC 56 8B F1 8B 4E 0C");

constexpr char* const graph_path_finder_t__set_surface_mangled_name = static_cast<char*>(
	"?SetSurface@GraphPathFinder_t@@QAEXPBVSurface_i@@@Z");
constexpr char* const graph_path_finder_t__set_surface_pattern = static_cast<char*>(
	"55 8B EC 8B 45 08 89 41 10");

#pragma endregion

#pragma region MessageProtocol

constexpr char* const message_protocol_module_name = static_cast<char*>("MessageProtocol.dll");

constexpr char* const message_t__data_block_size_get_mangled_name = static_cast<char*>(
	"?DataBlockSizeGet@Message_t@@QBEIXZ");
constexpr char* const message_t__data_block_size_get_pattern = static_cast<char*>(
	"E8 ?? ?? ?? ?? 83 C0 03 83 E0 FC C3");

constexpr char* const message_t__dest_id_get_mangled_name = static_cast<char*>(
	"?DestIdGet@Message_t@@QBEIXZ");
constexpr char* const message_t__dest_id_get_pattern = static_cast<char*>(
	"8B 41 10 C3");

constexpr char* const message_t__header_size_mangled_name = static_cast<char*>(
	"?HeaderSize@Message_t@@SAII@Z");
constexpr char* const message_t__header_size_pattern = static_cast<char*>(
	"55 8B EC 8B 4D 08 33 C0");

constexpr char* const message_t__message_size_get_mangled_name = static_cast<char*>(
	"?MessageSizeGet@Message_t@@QBEIXZ");
constexpr char* const message_t__message_size_get_pattern = static_cast<char*>(
	"8B D1");

constexpr char* const message_t__message_type_get_mangled_name = static_cast<char*>(
	"?MessageTypeGet@Message_t@@QBEIXZ");
constexpr char* const message_t__message_type_get_pattern = static_cast<char*>(
	"8B 41 08 C3");

constexpr char* const message_t__priority_get_mangled_name = static_cast<char*>(
	"?PriorityGet@Message_t@@QBEKXZ");
constexpr char* const message_t__priority_get_pattern = static_cast<char*>(
	"8B 41 14 C3");

constexpr char* const message_t__source_id_get_mangled_name = static_cast<char*>(
	"?SourceIdGet@Message_t@@QBEIXZ");
constexpr char* const message_t__source_id_get_pattern = static_cast<char*>(
	"8B 41 0C");

constexpr char* const n3_message_t__duplicate_body_mangled_name = static_cast<char*>(
	"?DuplicateBody@N3Message_t@@QBEPAVACE_Data_Block@@XZ");

constexpr char* const n3_message_t__message_body_get_mangled_name = static_cast<char*>(
	"?MessageBodyGet@N3Message_t@@UBEPADXZ");
constexpr char* const n3_message_t__message_body_get_pattern = static_cast<char*>(
	"8B 41 1C 85 C0");

constexpr char* const text_message_t__message_body_get_mangled_name = static_cast<char*>(
	"?MessageBodyGet@TextMessage_t@@UBEPADXZ");
constexpr char* const text_message_t__message_body_get_pattern = static_cast<char*>(
	"8B 41 1C 8B 40 14");

constexpr char* const text_message_t__message_body_len_mangled_name = static_cast<char*>(
	"?MessageBodyLen@TextMessage_t@@UBEIXZ");
constexpr char* const text_message_t__message_body_len_pattern = static_cast<char*>(
	"8B 41 24 C3");

#pragma endregion

#pragma region DatabaseController

constexpr char* database_controller_module_name = static_cast<char*>("DatabaseController.dll");

#pragma region resource_database_t__get_db_object_1

constexpr char* const resource_database_t__get_db_object_1_mangled_name = static_cast<char*>(
	"?DeleteDbObject@ResourceDatabase_t@@UAEXABVIdentity_t@@@Z");
constexpr char* const resource_database_t__get_db_object_1_pattern = static_cast<char*>(
	"B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 51 51 53 56 8B F1 8B 5E 08");
constexpr DWORD resource_database_t__get_db_object_1_offset = 0x0;
constexpr DWORD resource_database_t__get_db_object_1_bytes_to_next = 0x0;

#pragma endregion

#pragma endregion

#pragma region EngineClientAnarchy

// #define n3EngineClientAnarchy_t__GetFactionStr_x							0x16942
#define n3EngineClientAnarchy_t__GetFactionTitle_x							0x17B24
#define n3EngineClientAnarchy_t__GetGenderString_x							0x168CD
#define n3EngineClientAnarchy_t__GetItemByTemplate_x						0x18310
#define n3EngineClientAnarchy_t__GetTitleStr_x								0x16956
//#define n3EngineClientAnarchy_t__IsFirstLogin_x								0x16B7D
#define n3EngineClientAnarchy_t__IsFixture_x								0x17950
#define n3EngineClientAnarchy_t__N3Msg_ActivateMech_x						0x28DAF
#define n3EngineClientAnarchy_t__N3Msg_Airstrike_x							0x1C37A
#define n3EngineClientAnarchy_t__N3Msg_ArtilleryAttack_x					0x1C24A
#define n3EngineClientAnarchy_t__N3Msg_AssistFight_x						0x27D55
#define n3EngineClientAnarchy_t__N3Msg_CanAttack_x							0x2A5C4
#define n3EngineClientAnarchy_t__N3Msg_CanClickTargetTarget_x				0x16C90
#define n3EngineClientAnarchy_t__N3Msg_CanUseMech_x							0x27B75
#define n3EngineClientAnarchy_t__N3Msg_CastNanoSpell_x						0x1CACE
#define n3EngineClientAnarchy_t__N3Msg_Consider_x							0x17CF2
#define n3EngineClientAnarchy_t__N3Msg_ContainerAddItem_x					0x28E85
#define n3EngineClientAnarchy_t__N3Msg_CrawlToggle_x						0x282AA
#define n3EngineClientAnarchy_t__N3Msg_CreateRaid_x							0x18D71
#define n3EngineClientAnarchy_t__N3Msg_DefaultActionOnDynel_x				0x29DCA
#define n3EngineClientAnarchy_t__N3Msg_DefaultAttack_x						0x28A81
#define n3EngineClientAnarchy_t__N3Msg_DeleteNano_x							0x1CBD5
#define n3EngineClientAnarchy_t__N3Msg_DoSocialAction_x						0x274C8
#define n3EngineClientAnarchy_t__N3Msg_DropItem_x							0x2868B
#define n3EngineClientAnarchy_t__N3Msg_Duel_Accept_x						0x1BD4F
#define n3EngineClientAnarchy_t__N3Msg_Duel_Challenge_x						0x1BCB2
#define n3EngineClientAnarchy_t__N3Msg_Duel_Draw_x							0x1C05C
#define n3EngineClientAnarchy_t__N3Msg_Duel_Refuse_x						0x1BE7F
#define n3EngineClientAnarchy_t__N3Msg_Duel_Stop_x							0x1BFAD
#define n3EngineClientAnarchy_t__N3Msg_Forage_x								0x2A3D3
#define n3EngineClientAnarchy_t__N3Msg_GenerateMissions_x					0x16A47
#define n3EngineClientAnarchy_t__N3Msg_GetActionByName_x					0x274B8
#define n3EngineClientAnarchy_t__N3Msg_GetActionProgress_x					0x27FD8
#define n3EngineClientAnarchy_t__N3Msg_GetAggDef_x							0x27724
#define n3EngineClientAnarchy_t__N3Msg_GetAlienLevelString_x				0x17580
#define n3EngineClientAnarchy_t__N3Msg_GetAreaName_x						0x18223
//#define n3EngineClientAnarchy_t__N3Msg_GetAttackingID_x						0x27459
#define n3EngineClientAnarchy_t__N3Msg_GetBreedStr_x						0x16853
#define n3EngineClientAnarchy_t__N3Msg_GetBuffCurrentTime_x					0x1808D
#define n3EngineClientAnarchy_t__N3Msg_GetBuffTotalTime_x					0x18030
#define n3EngineClientAnarchy_t__N3Msg_GetCharacterBodyShape_x				0x18FC0
#define n3EngineClientAnarchy_t__N3Msg_GetCharOrientationData_x				0x27973
#define n3EngineClientAnarchy_t__N3Msg_GetCityNameForClanMember_x			0x175E1
#define n3EngineClientAnarchy_t__N3Msg_GetClanLevelString_x					0x196F5
#define n3EngineClientAnarchy_t__N3Msg_GetClanString_x						0x16E3B
#define n3EngineClientAnarchy_t__N3Msg_GetClientPetID_x						0x1A58F
#define n3EngineClientAnarchy_t__N3Msg_GetCloseTarget_x						0x1D990
#define n3EngineClientAnarchy_t__N3Msg_GetContainerInventoryList_x			0x17D9A
#define n3EngineClientAnarchy_t__N3Msg_GetCorrectActionID_x					0x27D1D
#define n3EngineClientAnarchy_t__N3Msg_GetCurrentRoom_x						0x185D6
#define n3EngineClientAnarchy_t__N3Msg_GetCurrentRoomName_x					0x18247
#define n3EngineClientAnarchy_t__N3Msg_GetDistrictFightMode_x				0x18209
#define n3EngineClientAnarchy_t__N3Msg_GetFactionInfoString_x				0x1E2C8
#define n3EngineClientAnarchy_t__N3Msg_GetFactionRange_x					0x17533
#define n3EngineClientAnarchy_t__N3Msg_GetFirstName_x						0x19147
#define n3EngineClientAnarchy_t__N3Msg_GetFormulaProgress_x					0x16F6D
#define n3EngineClientAnarchy_t__N3Msg_GetFormulaRadius_x					0x16D31
#define n3EngineClientAnarchy_t__N3Msg_GetGlobalCharacterPosition_x			0x17A53
#define n3EngineClientAnarchy_t__N3Msg_GetGlobalCharacterRotation_x			0x17A26
//#define n3EngineClientAnarchy_t__N3Msg_GetGridDestinationList_1_x			0x1748A
//#define n3EngineClientAnarchy_t__N3Msg_GetGridDestinationList_2_x			0x174CD
#define n3EngineClientAnarchy_t__N3Msg_GetInventoryVec_x					0x17307
#define n3EngineClientAnarchy_t__N3Msg_GetItem_x							0x285CD
#define n3EngineClientAnarchy_t__N3Msg_GetItemProgress_x					0x16FB1
#define n3EngineClientAnarchy_t__N3Msg_GetMovementMode_x					0x188D7
#define n3EngineClientAnarchy_t__N3Msg_GetName_x							0x19EC7
#define n3EngineClientAnarchy_t__N3Msg_GetNanoCostModifier_x				0x278CC
//#define n3EngineClientAnarchy_t__N3Msg_GetNanoSpellList_x					0x17CDB
#define n3EngineClientAnarchy_t__N3Msg_GetNanoTemplateInfoList_1_x			0x1754B
//#define n3EngineClientAnarchy_t__N3Msg_GetNanoTemplateInfoList_2_x			0x18AC8
#define n3EngineClientAnarchy_t__N3Msg_GetNextTarget_x						0x17638
#define n3EngineClientAnarchy_t__N3Msg_GetNumberOfAvailableAlienPerks_x		0x2835B
#define n3EngineClientAnarchy_t__N3Msg_GetNumberOfAvailablePerks_x			0x27F2A
#define n3EngineClientAnarchy_t__N3Msg_GetNumberOfFreeInventorySlots_x		0x27D3E
#define n3EngineClientAnarchy_t__N3Msg_GetNumberOfUsedAlienPerks_x			0x28340
#define n3EngineClientAnarchy_t__N3Msg_GetNumberOfUsedPerks_x				0x27F0F
#define n3EngineClientAnarchy_t__N3Msg_GetOverEquipLevel_x					0x184BF
#define n3EngineClientAnarchy_t__N3Msg_GetPFName_1_x						0x172CB
#define n3EngineClientAnarchy_t__N3Msg_GetPFName_2_x						0x1854C
#define	n3EngineClientAnarchy_t__N3Msg_GetParent_x							0x16C0F
#define n3EngineClientAnarchy_t__N3Msg_GetPos_x								0x16B8C
#define n3EngineClientAnarchy_t__N3Msg_GetSkill_1_x							0x2785B
#define n3EngineClientAnarchy_t__N3Msg_GetSkill_2_x							0x279C8
#define n3EngineClientAnarchy_t__N3Msg_GetSkillMax_x						0x2791D
//#define n3EngineClientAnarchy_t__N3Msg_GetSpecialActionList_x				0x27D03
#define n3EngineClientAnarchy_t__N3Msg_GetSpecialActionState_x				0x27C93
#define n3EngineClientAnarchy_t__N3Msg_GetSpecialAttackWeaponName_x			0x27C73
#define n3EngineClientAnarchy_t__N3Msg_GetStatNameMap_x						0x27E64
#define n3EngineClientAnarchy_t__N3Msg_GetTargetTarget_x					0x16C5C
#define n3EngineClientAnarchy_t__N3Msg_GetTeamMemberList_x					0x18BEA
#define n3EngineClientAnarchy_t__N3Msg_HasPerk_x							0x28115
//#define n3EngineClientAnarchy_t__N3Msg_IsAttacking_x						0x2743C
#define n3EngineClientAnarchy_t__N3Msg_IsBattleStation_x					0x18BA5
#define n3EngineClientAnarchy_t__N3Msg_IsCharacterInMech_x					0x18FFB
#define n3EngineClientAnarchy_t__N3Msg_IsCharacterMorphed_x					0x1902F
#define n3EngineClientAnarchy_t__N3Msg_IsDungeon_x							0x1859D
#define n3EngineClientAnarchy_t__N3Msg_IsFormulaReady_x						0x16EFF
#define n3EngineClientAnarchy_t__N3Msg_IsGeneralPerk_x						0x281F9
#define n3EngineClientAnarchy_t__N3Msg_IsGroupPerk_x						0x281AB
#define n3EngineClientAnarchy_t__N3Msg_IsInRaidTeam_x						0x18C40
#define n3EngineClientAnarchy_t__N3Msg_IsInTeam_x							0x17EDF
#define n3EngineClientAnarchy_t__N3Msg_IsItemDisabled_x						0x27E6A
#define n3EngineClientAnarchy_t__N3Msg_IsItemMine_x							0x17F63
#define n3EngineClientAnarchy_t__N3Msg_IsItemNFCrystal_x					0x1A213
#define n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToUnWear_x				0x27327
#define n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToWear_x				0x275D0
#define n3EngineClientAnarchy_t__N3Msg_IsMoving_x							0x27B49
#define n3EngineClientAnarchy_t__N3Msg_IsMyPetID_x							0x1B4D0
#define n3EngineClientAnarchy_t__N3Msg_IsNanoSelfOnly_x						0x16D5A
#define n3EngineClientAnarchy_t__N3Msg_IsNpc_x								0x16EAB
#define n3EngineClientAnarchy_t__N3Msg_IsPerk_x								0x28291
#define n3EngineClientAnarchy_t__N3Msg_IsPetTower_x							0x17503
#define n3EngineClientAnarchy_t__N3Msg_IsProfessionPerk_x					0x28165
#define n3EngineClientAnarchy_t__N3Msg_IsResearch_x							0x28245
#define n3EngineClientAnarchy_t__N3Msg_IsSecondarySpecialAttackAvailable_x	0x27B55
#define n3EngineClientAnarchy_t__N3Msg_IsShieldDisablerItem_x				0x27EC2
#define n3EngineClientAnarchy_t__N3Msg_IsSpecialPerk_x						0x2826D
#define n3EngineClientAnarchy_t__N3Msg_IsTeamLeader_x						0x17E9D
#define n3EngineClientAnarchy_t__N3Msg_IsTeamMission_x						0x17C69
#define n3EngineClientAnarchy_t__N3Msg_IsTeamMissionCopy_x					0x17C9F
#define n3EngineClientAnarchy_t__N3Msg_IsTeamNano_x							0x16D83
#define n3EngineClientAnarchy_t__N3Msg_IsTower_x							0x174D4
#define n3EngineClientAnarchy_t__N3Msg_IsVisible_x							0x283D7
#define n3EngineClientAnarchy_t__N3Msg_JoinItems_x							0x1D024
#define n3EngineClientAnarchy_t__N3Msg_KickTeamMember_x						0x1CC9A
#define n3EngineClientAnarchy_t__N3Msg_LeaveBattle_x						0x18B55
#define n3EngineClientAnarchy_t__N3Msg_LeaveTeam_x							0x1CD4D
#define n3EngineClientAnarchy_t__N3Msg_MeetsPerkCriteria_x					0x28140
#define n3EngineClientAnarchy_t__N3Msg_MoveItemToInventory_x				0x28411
#define n3EngineClientAnarchy_t__N3Msg_MoveRaidMember_x						0x18C5B
#define n3EngineClientAnarchy_t__N3Msg_NameToID_x							0x2A678
#define n3EngineClientAnarchy_t__N3Msg_NPCChatAddTradeItem_x				0x18709
#define n3EngineClientAnarchy_t__N3Msg_NPCChatCloseWindow_x					0x1B868
#define n3EngineClientAnarchy_t__N3Msg_NPCChatEndTrade_x					0x1881A
#define n3EngineClientAnarchy_t__N3Msg_NPCChatRemoveTradeItem_x				0x1879A
#define n3EngineClientAnarchy_t__N3Msg_NPCChatRequestDescription_x			0x186BF
#define n3EngineClientAnarchy_t__N3Msg_NPCChatStartTrade_x					0x1B8EF
#define n3EngineClientAnarchy_t__N3Msg_OrbitalAttack_x						0x1C2E2
#define n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_1_x				0x27CB9
#define n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_2_x				0x27CDE
#define n3EngineClientAnarchy_t__N3Msg_PetDuel_Accept_x						0x1BAA1
#define n3EngineClientAnarchy_t__N3Msg_PetDuel_Challenge_x					0x1BA00
#define n3EngineClientAnarchy_t__N3Msg_PetDuel_Refuse_x						0x1BB54
#define n3EngineClientAnarchy_t__N3Msg_PetDuel_Stop_x						0x1BC03
#define n3EngineClientAnarchy_t__N3Msg_RemoveBuff_x							0x1D3E3
#define n3EngineClientAnarchy_t__N3Msg_RemoveQuest_x						0x1AAB8
#define n3EngineClientAnarchy_t__N3Msg_RequestCharacterInventory_x			0x2723A
#define n3EngineClientAnarchy_t__N3Msg_RequestClothInventory_x				0x2724F
#define n3EngineClientAnarchy_t__N3Msg_RequestImplantInventory_x			0x272BB
#define n3EngineClientAnarchy_t__N3Msg_RequestSocialInventory_x				0x272F1
#define n3EngineClientAnarchy_t__N3Msg_RequestWeaponInventory_x				0x27285
#define n3EngineClientAnarchy_t__N3Msg_SecondarySpecialAttack_x				0x28B89
#define n3EngineClientAnarchy_t__N3Msg_SelectedTarget_x						0x17F84
#define n3EngineClientAnarchy_t__N3Msg_SendPetCommand_x						0x1C7E4
#define n3EngineClientAnarchy_t__N3Msg_SitToggle_x							0x299FA
#define n3EngineClientAnarchy_t__N3Msg_SplitItem_x							0x1D20D
#define n3EngineClientAnarchy_t__N3Msg_StartAltState_x						0x2A275
#define n3EngineClientAnarchy_t__N3Msg_StartCamping_x						0x1DECB
#define n3EngineClientAnarchy_t__N3Msg_StartPvP_x							0x18ADF
#define n3EngineClientAnarchy_t__N3Msg_StartTreatment_x						0x1B127
#define n3EngineClientAnarchy_t__N3Msg_StopAltState_x						0x2A324
#define n3EngineClientAnarchy_t__N3Msg_StopAttack_x							0x28A1A
#define n3EngineClientAnarchy_t__N3Msg_StopCamping_x						0x1E068
#define n3EngineClientAnarchy_t__N3Msg_StringToStat_x						0x27E54
#define n3EngineClientAnarchy_t__N3Msg_SwitchTarget_x						0x28E74
#define n3EngineClientAnarchy_t__N3Msg_TeamJoinRequest_x					0x1CEAC
#define n3EngineClientAnarchy_t__N3Msg_TemplateIDToDynelID_x				0x18633
#define n3EngineClientAnarchy_t__N3Msg_TextCommand_x						0x17F37
#define n3EngineClientAnarchy_t__N3Msg_ToggleReclaim_x						0x1C684
#define n3EngineClientAnarchy_t__N3Msg_TradeAbort_x							0x16508
#define n3EngineClientAnarchy_t__N3Msg_TradeAccept_x						0x16436
#define n3EngineClientAnarchy_t__N3Msg_TradeAddItem_x						0x1A717
#define n3EngineClientAnarchy_t__N3Msg_TradeConfirm_x						0x1649F
#define n3EngineClientAnarchy_t__N3Msg_TradeGetInventory_x					0x16663
#define n3EngineClientAnarchy_t__N3Msg_TradeGetInventoryCost_x				0x16577
#define n3EngineClientAnarchy_t__N3Msg_TradeRemoveItem_x					0x17A78
#define n3EngineClientAnarchy_t__N3Msg_TradeSetCash_x						0x165F5
#define n3EngineClientAnarchy_t__N3Msg_TradeStart_x							0x1A601
#define n3EngineClientAnarchy_t__N3Msg_TradeskillCombine_x					0x290E1
#define n3EngineClientAnarchy_t__N3Msg_TrainPerk_x							0x27F60
#define n3EngineClientAnarchy_t__N3Msg_TransferTeamLeadership_x				0x1CDF9
#define n3EngineClientAnarchy_t__N3Msg_TryAbortNanoFormula_x				0x185C0
#define n3EngineClientAnarchy_t__N3Msg_TryEnterSneakMode_x					0x29FB0
#define n3EngineClientAnarchy_t__N3Msg_UntrainPerk_x						0x27F85
#define n3EngineClientAnarchy_t__N3Msg_UseItem_x							0x2925D
#define n3EngineClientAnarchy_t__N3Msg_UseItemOnItem_x						0x2894B
#define n3EngineClientAnarchy_t__N3Msg_UseSkill_x							0x29D29

#define n3Engine_t__SetTeleportStatus_x										0x6D8E

#define n3EngineClient_t__SetMainDynel_x									0x87A5

#define n3EngineClientAnarchy_t__SetMainDynel_x								0x1ABE3

#pragma endregion

#pragma region ItemManager

#define ItemManager_t__m_ppcInstance_x							0x2E2B94
#define NanoItemManager_t__m_pcInstance_x						0x152090
#define StaticItemManager_t_mppcInstance_x						0x2E2BA0



#pragma endregion

#pragma region Playfield

#define PlayfieldAnarchy_t__PlayfieldAnarchy_t_x				0x121ACE
#define PlayfieldAnarchy_t__dPlayfieldAnarchy_t_x				0x121998

// Functions
//#define n3EngineClientAnarchy_t__N3Msg_GetDynelsInVicinity_x	0x1E726


#pragma endregion

#pragma region Gametime

#define Gametime_t__m_pcInstance_x								0x2DFDF4

#pragma endregion

#pragma region HTMLParser

#define HTMLParser_c__HTMLParser_c_x		0x15C89D
#define HTMLParser_c__dHTMLParser_c_x		0x15B427
#define HTMLParser_c__HTMLParser_c_copy_x	0x454A
#define HTMLParser_c__ExtractText_x			0x15B4F0

#pragma endregion

#pragma region Input Config

#define InputConfig_t__m_pcInstance_x								0x273948
#define InputConfig_t__SetCurrentTarget_x							0x1A4C5

#pragma endregion

#pragma region FlowControl

#define FlowControlModule_t__m_pcInstance_x							0x2753A0
#define FlowControlModule_t__m_isLauncherRun_x						0x2753AC
#define FlowControlModule_t__m_bIsGameClosing_x						0x27539C
#define FlowControlModule_t__m_nCloseFrames_x						0x275398
#define FlowControlModule_t__m_isTeleporting_x						0x2625D8
#define FlowControlModule_t__m_eLoggingOutTimed_x					0x2753A8
#define FlowControlModule_t__m_isClientToRestartAtExit_x			0x27539F

#pragma endregion

#pragma region TargetingModule

#define TargetingModule_t__m_pcInstance_x							0x274CE8
#define TargetingModule_t__m_cLastTarget_x							0x274CF8
#define TargetingModule_t__m_pcSelectionIndicator_x					0x274CEC
#define TargetingModule_t__m_pcAttackingIndicator_x					0x274CF0
#define TargetingModule_t__m_cLastTarget_x							0x274CF8
#define TargetingModule_t__RemoveTarget_x							0x269C5
#define TargetingModule_t__SelectSelf_x								0x269EB
#define TargetingModule_t__SetTarget_x								0x2682E
#define TargetingModule_t__SetTargetPet_x							0x26C1A

#pragma endregion

#pragma region ChatGUIModule

#define ChatGUIModule_c__s_pcInstance_x								0x275558

#define ChatGUIModule_c__HandleGroupAction_x						0x8686B
#define ChatGUIModule_c__HandleGroupMessage_x						0x86B95
#define ChatGUIModule_c__HandlePrivateGroupAction_x					0x864F3
#define ChatGUIModule_c__HandlePrivateMessage_x						0x880C4
#define ChatGUIModule_c__HandleSystemMessage_x						0x865A7
#define ChatGUIModule_c__HandleVicinityMessage_x					0x86EBE

#pragma endregion

#pragma region Vehicle

#define Vehicle_t__SetRelRot_x										0xD119

#pragma endregion

#pragma region Client

#define Client_t__s_nCharID_x										0x31928

#define Client_t__ProcessMessage_x									0x2A64

#pragma endregion

#pragma region Messaging

#define Message_t__DataBlockSizeGet_x								0x1D8E
#define Message_t__MessageSizeGet_x									0x1D75

#define N3Message_t__DuplicateBody_x								0x20D8
#define N3Message_t__MessageBodyGet_x								0x2107
#define N3Message_t__MessageBodyLen_x								0x1E7D

#define TextMessage_t__MessageBodyGet_x								0x2FB1
#define TextMessage_t__MessageBodyLen_x								0x1E75

#pragma endregion

#pragma region vTables

#define AccessCard_t__vTable_x			0x1618B4
#define CentralController_t__vTable_x	0x161BCC
#define Chest_t__vTable_x				0x161EBC
#define CityTerminal_t__vTable_x		0x1713B4
#define Corpse_t__vTable_x				0x1620C4
#define Door_t__vTable_x				0x1622EC
#define LockableItem_t__vTable_x		0x162B04
#define Mine_t__vTable_x				0x162E34
#define PlayerShop_t__vTable_x			0x163134
#define QuestBooth_t__vTable_x			0x16336C
#define ReclaimBooth_t__vTable_x		0x163594
#define SimpleChar_t__vTable_x			0x15F984
#define SimpleItem_t__vTable_x			0x163944
#define TrapItem_t__vTable_x			0x165E1C
#define VendingMachine_t__vTable_x		0x16606C
#define Weapon_t__vTable_x				0x1663E4
#define WearableItem_t__vTable_x		0x1665F4

#pragma endregion

#pragma region SimpleChar

#define SimpleChar_t__SimpleChar_t_x			0x5DAB5
#define SimpleChar_t__dSimpleChar_t_x			0x60284
#define SimpleChar_t__CheckLOS_x				0x59691



#pragma endregion

#pragma region PlayerVehicle

#define PlayerVehicle_t__UseWaypointPath_x		0x6EA40

#pragma endregion

#pragma region Internal

#define GAMESTATE_NOT_IN_GAME				1
#define GAMESTATE_WAITING_FOR_PLAYFIELD		2
#define GAMESTATE_WAITING_FOR_CLIENT_CHAR	3
#define GAMESTATE_IN_GAME					4

#pragma endregion

#pragma region LoginModule

#define LoginModule_c__m_pcInstance_x			0x273708

#pragma endregion

#pragma region ChatWindowController

#define ChatWindowController_c__m_pcInstance_x				0x275574

#define ChatGroupController_c__sub_10083D9C_x				0x83D9C

#pragma endregion

#pragma region FriendListController

#define FriendListController_c__sub_100A68E6_x				0xA68E6

#pragma endregion

#pragma region CommandInterpreter

#define CommandInterpreter_c__m_pcInstance_x				0x2755A4
#define CommandInterpreter_c__ParseTextCommand_x			0xA4139

#pragma endregion

#pragma region ChatWindowNode

#define ChatWindowNode_c__ParseTextCommand_x				/*0x9AA38*/0x9A9A2
#define ChatWindowNode_c__sub_1009E2D2_x					0x9E2D2

#define ChatWindowNode_c__sub_1009BB79_x					0x9BB79

#pragma endregion

#pragma region LookAtIIR

#define LookAtIIR_t__sub_10073E4D_x			0x73E4D

#pragma endregion

#pragma region Resource Database

#define ResourceDatabase_t__GetDbObject_1_x		0x2BA5
#define ResourceDatabase_t__GetIdentityVec_x	0x3378

#pragma endregion

#pragma region n3DatabaseHandler

#define n3DatabaseHandler_t__s_pcInstance_x		0x605B8

#pragma endregion

#pragma region GraphPathFinder

#define GraphPathFinder_t__GraphPathFinder_t_x			0x2095
#define GraphPathFinder_t__GraphPathFinder_t_Copy_x		0x1EB5
#define GraphPathFinder_t__dGraphPathFinder_t_x			0x2219
#define GraphPathFinder_t__Configure_x					0x20E8
#define GraphPathFinder_t__CreateFromData_x				0x2768
#define GraphPathFinder_t__FindPath_x					0x2988
#define GraphPathFinder_t__GenerateGraph_x				0x2B3C
#define GraphPathFinder_t__GenerateGraphForRoom_x		0x2DA6
#define GraphPathFinder_t__Init_x						0x261E
#define GraphPathFinder_t__SetSpaceForGraph_x			0x20CA
#define GraphPathFinder_t__SetSurface_x					0x1EA4

#pragma endregion

}
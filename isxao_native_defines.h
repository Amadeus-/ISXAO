#pragma once

#pragma region N3

#undef N3_CAMERA_T__SET_SECONDARY_TARGET_USE_PATTERN

#undef N3_CAMERA_T__SET_SELECTED_TARGET_USE_PATTERN

#undef N3_ENGINE_T__M_PC_INSTANCE_USE_PATTERN

#undef N3_DYNEL_T__M_PC_DYNEL_DIR_INSTANCE_USE_PATTERN

#undef N3_DYNEL_T__N3_DYNEL_T_USE_PATTERN

#undef N3_DYNEL_T__D_N3_DYNEL_T_USE_PATTERN

#undef N3_DYNEL_T__GET_DYNEL_USE_PATTERN
#define N3_DYNEL_T__GET_DYNEL_USE_NATIVE

#undef N3_DYNEL_T__SEND_IIR_TO_OBSERVERS_USE_PATTERN
#define N3_DYNEL_T__SEND_IIR_TO_OBSERVERS_USE_NATIVE

#undef N3_DYNEL_T__SET_PLAYFIELD_USE_PATTERN

#undef N3_DYNEL_T__UPDATE_LOCALITY_LISTENERS_USE_PATTERN
#define N3_DYNEL_T__UPDATE_LOCALITY_LISTENERS_USE_NATIVE

#undef N3_DYNEL_T__UPDATE_WHERE_USE_PATTERN

#undef N3_ENGINE_T__N3_ENGINE_T_USE_PATTERN

#undef N3_ENGINE_CLIENT_T__GET_CLIENT_CONTROL_DYNEL_USE_PATTERN

#undef N3_PLAYFIELD_T__ADD_CHILD_DYNEL_USE_PATTERN

#undef N3_PLAYFIELD_T__GET_PLAYFIELD_1_USE_PATTERN

#undef N3_PLAYFIELD_T__GET_PLAYFIELD_2_USE_PATTERN

#undef N3_PLAYFIELD_T__GET_PLAYFIELD_3_USE_PATTERN

#undef N3_PLAYFIELD_T__LINE_OF_SIGHT_USE_PATTERN

#undef N3_PLAYFIELD_T__REMOVE_CHILD_USE_PATTERN

#undef N3_PLAYFIELD_T__M_PC_PLAYFIELD_DIR_INSTANCE_USE_PATTERN

#pragma endregion

#pragma region Gamecode

// Functions

#define F_GET_NANO_ITEM_USE_PATTERN
#define F_GET_NANO_ITEM_USE_NATIVE

#undef F_STAT_TO_STRING_USE_PATTERN
#define F_STAT_TO_STRING_USE_NATIVE

#define ITEM_MANAGER_T__ITEM_MANAGER_T_USE_PATTERN

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_ENGINE_CLIENT_ANARCHY_T_USE_PATTERN

#undef N3_ENGINE_CLIENT_ANARCHY_T__D_N3_ENGINE_CLIENT_ANARCHY_T_USE_PATTERN

#undef N3_ENGINE_CLIENT_ANARCHY_T__GET_BREED_STR_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__GET_BREED_STR_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__GET_CLIENT_CHAR_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__GET_CLIENT_CHAR_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__GET_CLIENT_DYNEL_ID_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__GET_CLIENT_DYNEL_ID_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__CONVERT_CRITERIA_USE_PATTERN

#undef N3_ENGINE_CLIENT_ANARCHY_T__GET_CURRENT_MOVEMENT_MODE_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__GET_CURRENT_MOVEMENT_MODE_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__GET_FACTION_STR_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__GET_FACTION_STR_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__GET_FACTION_TITLE_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__GET_FACTION_TITLE_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__GET_GENDER_STRING_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__GET_GENDER_STRING_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__GET_ITEM_BY_TEMPLATE_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__GET_ITEM_BY_TEMPLATE_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__GET_SEX_STR_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__GET_SEX_STR_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__GET_TITLE_STR_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__GET_TITLE_STR_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__IS_FIRST_LOGIN_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__IS_FIRST_LOGIN_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__IS_FIXTURE_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__IS_FIXTURE_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_ACTIVATE_MECH_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_ACTIVATE_MECH_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_AIRSTRIKE_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_AIRSTRIKE_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_ARTILLERY_ATTACK_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_ARTILLERY_ATTACK_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_ASSIST_FIGHT_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_ASSIST_FIGHT_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CAN_ATTACK_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CAN_ATTACK_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CAN_CLICK_TARGET_TARGET_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CAN_CLICK_TARGET_TARGET_USE_NATIVE

#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CAN_USE_MECH_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CAN_USE_MECH_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CAST_NANO_SPELL_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CAST_NANO_SPELL_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CONSIDER_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CONSIDER_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CONTAINER_ADD_ITEM_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CONTAINER_ADD_ITEM_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CRAWL_TOGGLE_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CRAWL_TOGGLE_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CREATE_RAID_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_CREATE_RAID_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DEFAULT_ACTION_ON_DYNEL_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DEFAULT_ACTION_ON_DYNEL_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DEFAULT_ATTACK_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DEFAULT_ATTACK_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DELETE_ITEM_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DELETE_ITEM_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DELETE_NANO_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DELETE_NANO_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DO_SOCIAL_ACTION_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DO_SOCIAL_ACTION_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DROP_ITEM_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DROP_ITEM_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_ACCEPT_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_ACCEPT_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_CHALLENGE_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_CHALLENGE_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_DRAW_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_DRAW_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_REFUSE_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_REFUSE_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_STOP_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_DUEL_STOP_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_FORAGE_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_FORAGE_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ACTION_BY_NAME_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ACTION_BY_NAME_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ACTION_PROGRESS_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ACTION_PROGRESS_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_AGG_DEF_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_AGG_DEF_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ALIEN_LEVEL_STRING_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ALIEN_LEVEL_STRING_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_AREA_NAME_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_AREA_NAME_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ATTACKING_ID_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ATTACKING_ID_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_BREED_STR_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_BREED_STR_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_BUFF_CURRENT_TIME_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_BUFF_CURRENT_TIME_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_BUFF_TOTAL_TIME_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_BUFF_TOTAL_TIME_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CHARACTER_BODY_SHAPE_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CHARACTER_BODY_SHAPE_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CHAR_ORIENTATION_DATA_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CHAR_ORIENTATION_DATA_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CITY_NAME_FOR_CLAN_MEMBER_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CITY_NAME_FOR_CLAN_MEMBER_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CLAN_LEVEL_STRING_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CLAN_LEVEL_STRING_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CLAN_STRING_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CLAN_STRING_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CLIENT_PET_ID_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CLIENT_PET_ID_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CLOSE_TARGET_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CLOSE_TARGET_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CONTAINER_INVENTORY_LIST_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CONTAINER_INVENTORY_LIST_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CORRECT_ACTION_ID_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CORRECT_ACTION_ID_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CURRENT_ROOM_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CURRENT_ROOM_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CURRENT_ROOM_NAME_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_CURRENT_ROOM_NAME_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_DISTRICT_FIGHT_MODE_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_DISTRICT_FIGHT_MODE_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_DYNELS_IN_VICINITY_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_DYNELS_IN_VICINITY_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FACTION_INFO_STRING_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FACTION_INFO_STRING_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FACTION_RANGE_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FACTION_RANGE_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FIRST_NAME_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FIRST_NAME_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FORMULA_PROGRESS_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FORMULA_PROGRESS_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FORMULA_RADIUS_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_FORMULA_RADIUS_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_GLOBAL_CHARACTER_POSITION_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_GLOBAL_CHARACTER_POSITION_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_GLOBAL_CHARACTER_ROTATION_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_GLOBAL_CHARACTER_ROTATION_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_GRID_DESTINATION_1_LIST_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_GRID_DESTINATION_1_LIST_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_GRID_DESTINATION_2_LIST_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_GRID_DESTINATION_2_LIST_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_INVENTORY_VEC_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_INVENTORY_VEC_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ITEM_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ITEM_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ITEM_PROGRESS_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_ITEM_PROGRESS_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_MOVEMENT_MODE_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_MOVEMENT_MODE_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NAME_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NAME_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NANO_COST_MODIFIER_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NANO_COST_MODIFIER_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NANO_SPELL_LIST_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NANO_SPELL_LIST_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NANO_TEMPLATE_INFO_LIST_1_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NANO_TEMPLATE_INFO_LIST_1_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NANO_TEMPLATE_INFO_LIST_2_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NANO_TEMPLATE_INFO_LIST_2_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NEXT_TARGET_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NEXT_TARGET_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_AVAILABLE_ALIEN_PERKS_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_AVAILABLE_ALIEN_PERKS_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_AVAILABLE_PERKS_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_AVAILABLE_PERKS_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_FREE_INVENTORY_SLOTS_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_FREE_INVENTORY_SLOTS_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_USED_ALIEN_PERKS_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_USED_ALIEN_PERKS_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_USED_PERKS_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_NUMBER_OF_USED_PERKS_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_OVER_EQUIP_LEVEL_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_OVER_EQUIP_LEVEL_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_PLAYFIELD_NAME_1_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_PLAYFIELD_NAME_1_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_PLAYFIELD_NAME_2_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_PLAYFIELD_NAME_2_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_PARENT_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_PARENT_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_POS_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_POS_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SKILL_1_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SKILL_1_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SKILL_2_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SKILL_2_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SKILL_MAX_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SKILL_MAX_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SPECIAL_ACTION_LIST_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SPECIAL_ACTION_LIST_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SPECIAL_ACTION_STATE_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SPECIAL_ACTION_STATE_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SPECIAL_ATTACK_WEAPON_NAME_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_SPECIAL_ATTACK_WEAPON_NAME_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_STAT_NAME_MAP_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_STAT_NAME_MAP_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_TARGET_TARGET_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_TARGET_TARGET_USE_NATIVE



#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_IS_NPC_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_IS_NPC_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_PERFORM_SPECIAL_ACTION_1_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_PERFORM_SPECIAL_ACTION_1_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_PERFORM_SPECIAL_ACTION_2_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_PERFORM_SPECIAL_ACTION_2_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_SEND_PET_COMMAND_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_SEND_PET_COMMAND_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_STOP_ATTACK_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_STOP_ATTACK_USE_NATIVE

#undef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_USE_ITEM_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_USE_ITEM_USE_NATIVE


#undef N3_ENGINE_CLIENT_ANARCHY_T__ON_CLOSED_USE_PATTERN
#define N3_ENGINE_CLIENT_ANARCHY_T__ON_CLOSED_USE_NATIVE


#define SIMPLE_CHAR_T__CHECK_LOS_USE_PATTERN
#define SIMPLE_CHAR_T__CHECK_LOS_USE_NATIVE

#define STATIC_ITEM_MANAGER_T__STATIC_ITEM_MANAGER_T_USE_PATTERN

// Instances

#define M_C_NANO_ITEM_DIR_USE_PATTERN

#define M_C_STAT_NAME_DIR_USE_PATTERN

#define ITEM_MANAGER_T__M_PPC_INSTANCE_USE_PATTERN

#define STATIC_ITEM_MANAGER_T__M_PPC_INSTANCE_USE_PATTERN

#pragma endregion

#pragma region GUI

#define TARGETING_MODULE_T__INITIALISE_MESSAGE_USE_PATTERN

#undef TARGETING_MODULE_T__SET_TARGET_USE_PATTERN
#define TARGETING_MODULE_T__SET_TARGET_USE_NATIVE

#undef TARGETING_MODULE_T__TARGETING_MODULE_T_USE_PATTERN
#define TARGETING_MODULE_T__TARGETING_MODULE_T_USE_NATIVE

#undef TARGETING_MODULE_T__M_PC_INSTANCE_USE_PATTERN

#undef TARGETING_MODULE_T__M_C_LAST_TARGET_USE_PATTERN

#undef TARGETING_MODULE_T__M_PC_SELECTION_INDICATOR_USE_PATTERN

#undef TARGETING_MODULE_T__M_PC_ATTACKING_INDICATOR_USE_PATTERN

#pragma endregion

#pragma region Interfaces

#undef CLIENT_T__S_N_CHAR_ID_USE_PATTERN

#undef CLIENT_T__PROCESS_MESSAGE_USE_PATTERN

#pragma endregion

#pragma region Vehicle

#undef VEHICLE_T__SET_REL_ROT_USE_PATTERN
#define VEHICLE_T__SET_REL_ROT_USE_NATIVE

#pragma endregion
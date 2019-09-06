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

	DWORD hDatabaseController = DWORD(GetModuleHandle("DatabaseController.dll"));
	
	DWORD hGUI = DWORD(GetModuleHandle("GUI.dll"));
	DWORD hVehicle = DWORD(GetModuleHandle("Vehicle.dll"));
	DWORD hMessageProtocol = DWORD(GetModuleHandle("MessageProtocol.dll"));
	DWORD hPathFinder = DWORD(GetModuleHandle("PathFinder.dll"));
	DWORD hInterfaces = DWORD(GetModuleHandle("Interfaces.dll"));

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

#pragma region Process

		process_handle = GetCurrentProcess();

#pragma endregion

#pragma region N3

		// Module
		GetModuleInformation(process_handle, n3_module_handle, &n3_module_info, sizeof(n3_module_info));
		auto n3_module_base = DWORD(n3_module_handle);
		const auto n3_data_begin = reinterpret_cast<unsigned char*>(n3_module_base);
		const auto n3_data_end = n3_data_begin + n3_module_info.SizeOfImage;
		const vector<unsigned char> n3_data(n3_data_begin, n3_data_end);

		// Functions
		GET_FUNCTION_ADDRESS(n3, n3_camera_t__set_secondary_target);
		GET_FUNCTION_ADDRESS(n3, n3_camera_t__set_selected_target);

		// Functions
		GET_FUNCTION_ADDRESS(n3, n3_dynel_t__n3_dynel_t);
		GET_FUNCTION_ADDRESS(n3, n3_dynel_t__d_n3_dynel_t);
		GET_FUNCTION_ADDRESS(n3, n3_dynel_t__get_dynel);
		GET_FUNCTION_ADDRESS(n3, n3_dynel_t__send_iir_to_observers);
		GET_FUNCTION_ADDRESS(n3, n3_dynel_t__set_playfield);
		GET_FUNCTION_ADDRESS(n3, n3_dynel_t__update_where);
		GET_ADDRESS_FROM_FUNCTION_OFFSET(n3_dynel_t__update_where, n3_dynel_t__update_locality_listeners);
		GET_RELATIVE_ADDRESS_FROM_FUNCTION_OFFSET(n3_dynel_t__update_where, n3_dynel_t__update_locality_listeners);

		// Instances
		GET_ADDRESS_FROM_FUNCTION_OFFSET(n3_dynel_t__get_dynel, n3_dynel_t__m_pc_dynel_dir_instance);
		pp_dynel_dir = reinterpret_cast<dynel_dir_t**>(n3_dynel_t__m_pc_dynel_dir_instance);

		// Functions
		GET_FUNCTION_ADDRESS(n3, n3_engine_t__n3_engine_t);		

		// Instances
		GET_ADDRESS_FROM_FUNCTION_OFFSET(n3_engine_t__n3_engine_t, n3_engine_t__m_pc_instance);

		// Functions
		GET_RELATIVE_ADDRESS_FROM_FUNCTION_OFFSET(n3_camera_t__set_selected_target, n3_engine_client_t__get_client_control_dynel);

		// Functions
		GET_FUNCTION_ADDRESS(n3, n3_playfield_t__add_child_dynel);
		GET_FUNCTION_ADDRESS(n3, n3_playfield_t__get_playfield);
		GET_FUNCTION_ADDRESS(n3, n3_playfield_t__line_of_sight);
		GET_FUNCTION_ADDRESS(n3, n3_playfield_t__remove_child);

		// Instances
		GET_ADDRESS_FROM_FUNCTION_OFFSET(n3_playfield_t__get_playfield, n3_playfield_t__m_pc_playfield_dir_instance);
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

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__N3_MSG_GET_GLOBAL_CHARACTER_POSITION_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_global_character_position)
#else
		GET_PROC_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_msg_get_global_character_position)
#endif

#ifdef SIMPLE_CHAR_T__CHECK_LOS_USE_PATTERN
		GET_FUNCTION_ADDRESS(gamecode, simple_char_t__check_los)
#else
		static_assert(false, "simple_char_t__check_los requires a pattern for the function address to be found.")
#endif


		// Instances
		n3_engine_client_anarchy_t__m_pc_instance = n3_engine_t__m_pc_instance;
		pp_engine_client_anarchy = reinterpret_cast<isxao_classes::engine_client_anarchy**>(n3_engine_client_anarchy_t__m_pc_instance);

#pragma endregion

#pragma endregion

		return true;
	}

#pragma region Process

	HANDLE process_handle = nullptr;

#pragma endregion

#pragma region Globals

	DWORD __N3Msg_GetFullPerkMap = 0;
	DWORD __SetTarget = 0;
	DWORD m_cStatNameDir = 0;
	stat_name_dir_t StatNameDir;
	stat_name_dir_t *pStatNameDir = nullptr;
	DWORD __RequestInfo = 0;
	DWORD __StatToString = 0;

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
	dynel_dir_t **pp_dynel_dir = nullptr;

	// Functions
	DWORD n3_engine_t__n3_engine_t = 0;

	// Functions
	DWORD n3_engine_client_t__get_client_control_dynel = 0;

	// Instances
	DWORD n3_engine_t__m_pc_instance = 0;

	// Functions
	DWORD n3_playfield_t__add_child_dynel = 0;
	DWORD n3_playfield_t__get_playfield = 0;
	DWORD n3_playfield_t__line_of_sight = 0;
	DWORD n3_playfield_t__remove_child = 0;

	// Instances
	DWORD n3_playfield_t__m_pc_playfield_dir_instance = 0;
	PlayfieldDir** pp_playfield_dir = nullptr;

#pragma endregion

#pragma region Gamecode

	// Functions
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

	DWORD n3_engine_client_anarchy_t__n3_msg_get_global_character_position = 0;

	// Instances
	DWORD n3_engine_client_anarchy_t__m_pc_instance = 0;
	isxao_classes::engine_client_anarchy **pp_engine_client_anarchy = nullptr;

#pragma endregion

#pragma region EngineClientAnarchy		
	
	
	DWORD n3EngineClientAnarchy_t__N3Msg_CanAttack = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_CanClickTargetTarget = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_CanUseMech = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_CastNanoSpell = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_Consider = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_ContainerAddItem = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_CrawlToggle = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_CreateRaid = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_DefaultActionOnDynel = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_DefaultAttack = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_DeleteNano = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_DoSocialAction = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_DropItem = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_Duel_Accept = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_Duel_Challenge = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_Duel_Draw = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_Duel_Refuse = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_Duel_Stop = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_Forage = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetActionByName = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetActionProgress = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetAggDef = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetAlienLevelString = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetAreaName = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetAttackingID = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetBreedStr = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetBuffCurrentTime = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetBuffTotalTime = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetCharacterBodyShape = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetCharOrientationData = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetCityNameForClanMember = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetClanLevelString = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetClanString = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetClientPetID = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetCloseTarget = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetContainerInventoryList = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetCorrectActionID = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetCurrentRoom = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetCurrentRoomName = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetDistrictFightMode = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetDynelsInVicinity = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetFactionInfoString = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetFactionRange = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetFirstName = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetFormulaProgress = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetFormulaRadius = 0;
	
	DWORD n3EngineClientAnarchy_t__N3Msg_GetGlobalCharacterRotation = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetGridDestinationList_1 = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetGridDestinationList_2 = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetInventoryVec = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetItem = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetItemProgress = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetMovementMode = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetName = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetNanoCostModifier = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetNanoSpellList = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetNanoTemplateInfoList_1 = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetNanoTemplateInfoList_2 = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetNextTarget = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetNumberOfAvailableAlienPerks = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetNumberOfAvailablePerks = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetNumberOfFreeInventorySlots = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetNumberOfUsedAlienPerks = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetNumberOfUsedPerks = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetOverEquipLevel = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetPFName_1 = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetPFName_2 = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetParent = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetPos = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetSkill_1 = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetSkill_2 = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetSkillMax = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetSpecialActionList = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetSpecialActionState = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetStatNameMap = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetSpecialAttackWeaponName = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_GetTargetTarget = 0;
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
	DWORD n3EngineClientAnarchy_t__N3Msg_IsNpc = 0;
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
	DWORD n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_1 = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_2 = 0;
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
	DWORD n3EngineClientAnarchy_t__N3Msg_SendPetCommand = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_SitToggle = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_SplitItem = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_StartAltState = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_StartCamping = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_StartPvP = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_StartTreatment;
	DWORD n3EngineClientAnarchy_t__N3Msg_StopAltState = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_StopAttack = 0;
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
	DWORD n3EngineClientAnarchy_t__N3Msg_UseItem = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_UseItemOnItem = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_UseSkill = 0;
	DWORD n3EngineClientAnarchy_t__SetMainDynel = 0;

	DWORD n3Engine_t__SetTeleportStatus = 0;

	DWORD n3EngineClient_t__SetMainDynel = 0;

#pragma endregion
	
#pragma region ItemManagement

	DWORD ItemManager_t__m_ppcInstance = 0;
	std::vector<acg_game_item_t> ***pppItemVector = nullptr;
	DWORD NanoItemManager_t__m_pcInstance = 0;
	nano_item_dir_t **ppNanoItemDir = nullptr;
	DWORD NanoItem_t__GetNanoItem = 0;
	DWORD StaticItemManager_t_mppcInstance;
	std::vector<static_item_t> ***pppStaticItemVector = nullptr;
	

#pragma endregion

#pragma region Playfield	
	
	DWORD n3Playfield_t__OnChildDynelBeingRemoved = 0;
	

	DWORD PlayfieldAnarchy_t__PlayfieldAnarchy_t = 0;
	DWORD PlayfieldAnarchy_t__dPlayfieldAnarchy_t = 0;

#pragma endregion

#pragma region Camera

	

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

	DWORD TargetingModule_t__m_pcInstance = 0;
	TargetingModule** ppTargetingModule = nullptr;
	DWORD TargetingModule_t__m_pcSelectionIndicator = 0;
	indicator_t** ppSelectionIndicator = nullptr;
	DWORD TargetingModule_t__m_pcAttackingIndicator = 0;
	indicator_t** ppAttackingIndicator = nullptr;
	DWORD TargetingModule_t__m_cLastTarget = 0;
	identity_t* pLastTarget = nullptr;
	DWORD TargetingModule_t__RemoveTarget = 0;
	DWORD TargetingModule_t__SelectSelf = 0;
	DWORD TargetingModule_t__SetTarget = 0;
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

#pragma region Vehicle

	DWORD Vehicle_t__SetRelRot = 0;

#pragma endregion

#pragma region Client

	DWORD Client_t__s_nCharID = 0;
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
	DWORD simple_char_t__check_los = 0;

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
			printf("Cannot find %s function address.", function_offset_name);
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
			printf("Cannot find %s function address.", function_address);
			return false;
		}
		return true;
	}

}
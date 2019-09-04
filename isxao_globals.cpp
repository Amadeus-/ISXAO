#include "isxao_main.h"

#define GET_FUNCTION_ADDRESS(module, function_address) get_function_address((module##_data), (function_address##_pattern), (module##_module_base), (function_address), #function_address) // NOLINT(cppcoreguidelines-macro-usage)
#define GET_ADDRESS_FROM_FUNCTION_OFFSET(function_base, static_address) get_static_address_from_function((function_base), (static_address), #static_address, (static_address##_offset))  // NOLINT(cppcoreguidelines-macro-usage)
#define GET_RELATIVE_ADDRESS_FROM_FUNCTION_OFFSET(function_base, relative_address) get_relative_address_from_function((function_base), (relative_address), #relative_address, (relative_address##_offset), (relative_address##_bytes_to_next))  // NOLINT(cppcoreguidelines-macro-usage)

namespace isxao_globals
{

#pragma region Modules

	HMODULE gamecode_module_handle = GetModuleHandle("Gamecode.dll");
	MODULEINFO gamecode_module_info;
	HMODULE n3_module_handle = GetModuleHandle("N3.dll");
	MODULEINFO n3_module_info;

	DWORD hDatabaseController = DWORD(GetModuleHandle("DatabaseController.dll"));
	
	DWORD hGUI = DWORD(GetModuleHandle("GUI.dll"));
	DWORD hVehicle = DWORD(GetModuleHandle("Vehicle.dll"));
	DWORD hMessageProtocol = DWORD(GetModuleHandle("MessageProtocol.dll"));
	DWORD hPathFinder = DWORD(GetModuleHandle("PathFinder.dll"));
	DWORD hInterfaces = DWORD(GetModuleHandle("Interfaces.dll"));

#pragma endregion

	bool InitializeOffsets()
	{
		/*if (!n3_module_handle || !gamecode_module_handle|| !hDatabaseController || !hGUI || !hVehicle || !hMessageProtocol || !hInterfaces || !hPathFinder)
			return false;*/

		if (!gamecode_module_handle)
		{
			printf("Could not find handle to module \"Gamecode.dll\". Aborting offset initialization.");
			return false;
		}

		if (!n3_module_handle)
		{
			printf("Could not find handle to module \"N3.dll\". Aborting offset initialization.");
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
		auto gamecode_module_base = DWORD(gamecode_module_handle);
		const auto gamecode_data_begin = reinterpret_cast<unsigned char*>(gamecode_module_base);
		const auto gamecode_data_end = gamecode_data_begin + gamecode_module_info.SizeOfImage;
		const vector<unsigned char> gamecode_data(gamecode_data_begin, gamecode_data_end);

		// Functions
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__n3_engine_client_anarchy_t);
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t);
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__convert_criteria);
		n3_engine_client_anarchy_t__get_client_char = n3_engine_client_t__get_client_control_dynel;
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_client_dynel_id);
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_current_movement_mode);
		GET_FUNCTION_ADDRESS(gamecode, n3_engine_client_anarchy_t__get_faction_str);

		// Instances
		n3_engine_client_anarchy_t__m_pc_instance = n3_engine_t__m_pc_instance;
		pp_engine_client_anarchy = reinterpret_cast<engine_client_anarchy**>(n3_engine_client_anarchy_t__m_pc_instance);

#pragma endregion



//#pragma region Globals
//
//#ifdef __GetBreedStr_x
//		__GetBreedStr = __GetBreedStr_x + gamecode_module_handle;
//#endif
//#ifdef __GetNanoItem_x
//		__GetNanoItem = __GetNanoItem_x + gamecode_module_handle;
//#endif
//#ifdef __GetSexStr_x
//		__GetSexStr = __GetSexStr_x + gamecode_module_handle;
//#endif
//#ifdef __GetFullPerkMap_x
//		__N3Msg_GetFullPerkMap = __GetFullPerkMap_x + gamecode_module_handle;
//#endif
//#ifdef __SetTarget_x
//		__SetTarget = __SetTarget_x + hGUI;
//#endif
//#ifdef m_cStatNameDir_x
//		m_cStatNameDir = m_cStatNameDir_x + gamecode_module_handle;
//		StatNameDir = (*reinterpret_cast<stat_name_dir_t*>(m_cStatNameDir));
//		pStatNameDir = &StatNameDir;
//#endif
//#ifdef __RequestInfo_x
//		__RequestInfo = __RequestInfo_x + gamecode_module_handle;
//#endif
//
//#ifdef __StatToString_x
//		__StatToString = __StatToString_x + gamecode_module_handle;
//#endif
//
//#pragma endregion
//
//#pragma region EngineClientAnarchy
//
//		// Instance
//		n3_engine_client_anarchy_t__m_pc_instance = n3EngineClientAnarchy_t__m_pcInstance_x + n3_module_handle;
//		pp_engine_client_anarchy = reinterpret_cast<EngineClientAnarchy**>(n3_engine_client_anarchy_t__m_pc_instance);
//
//		// Functions
//#ifdef n3EngineClientAnarchy_t__n3EngineClientAnarchy_t_x
//		n3_engine_client_anarchy_t__n3_engine_client_anarchy_t = n3EngineClientAnarchy_t__n3EngineClientAnarchy_t_x + gamecode_module_handle;
//#endif
//
//#ifdef n3EngineClientAnarchy_t__dn3EngineClientAnarchy_t_x
//		n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t = n3EngineClientAnarchy_t__dn3EngineClientAnarchy_t_x + gamecode_module_handle;
//#endif
//
//#ifdef n3EngineClientAnarchy_t__GetClientChar_x
//		n3_engine_client_anarchy_t__get_client_char = n3EngineClientAnarchy_t__GetClientChar_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__GetClientDynelId_x
//		n3_engine_client_anarchy_t__get_client_dynel_id = n3EngineClientAnarchy_t__GetClientDynelId_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__GetCurrentMovementMode_x
//		n3_engine_client_anarchy_t__get_current_movement_mode = n3EngineClientAnarchy_t__GetCurrentMovementMode_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__GetFactionStr_x
//		n3_engine_client_anarchy_t__get_faction_str = n3EngineClientAnarchy_t__GetFactionStr_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__GetFactionTitle_x
//		n3_engine_client_anarchy_t__get_faction_title = n3EngineClientAnarchy_t__GetFactionTitle_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__GetGenderString_x
//		n3EngineClientAnarchy_t__GetGenderString = n3EngineClientAnarchy_t__GetGenderString_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__GetItemByTemplate_x
//		n3EngineClientAnarchy_t__GetItemByTemplate = n3EngineClientAnarchy_t__GetItemByTemplate_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__GetTitleStr_x
//		n3EngineClientAnarchy_t__GetTitleStr = n3EngineClientAnarchy_t__GetTitleStr_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__IsFirstLogin_x
//		n3EngineClientAnarchy_t__IsFirstLogin = n3EngineClientAnarchy_t__IsFirstLogin_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__IsFixture_x
//		n3EngineClientAnarchy_t__IsFixture = n3EngineClientAnarchy_t__IsFixture_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_ActivateMech_x
//		n3EngineClientAnarchy_t__N3Msg_ActivateMech = n3EngineClientAnarchy_t__N3Msg_ActivateMech_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_Airstrike_x
//		n3EngineClientAnarchy_t__N3Msg_Airstrike = n3EngineClientAnarchy_t__N3Msg_Airstrike_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_ArtilleryAttack_x
//		n3EngineClientAnarchy_t__N3Msg_ArtilleryAttack = n3EngineClientAnarchy_t__N3Msg_ArtilleryAttack_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_AssistFight_x
//		n3EngineClientAnarchy_t__N3Msg_AssistFight = n3EngineClientAnarchy_t__N3Msg_AssistFight_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_CanAttack_x
//		n3EngineClientAnarchy_t__N3Msg_CanAttack = n3EngineClientAnarchy_t__N3Msg_CanAttack_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_CanClickTargetTarget_x
//		n3EngineClientAnarchy_t__N3Msg_CanClickTargetTarget = n3EngineClientAnarchy_t__N3Msg_CanClickTargetTarget_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_CanUseMech_x
//		n3EngineClientAnarchy_t__N3Msg_CanUseMech = n3EngineClientAnarchy_t__N3Msg_CanUseMech_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_CastNanoSpell_x
//		n3EngineClientAnarchy_t__N3Msg_CastNanoSpell = n3EngineClientAnarchy_t__N3Msg_CastNanoSpell_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_Consider_x
//		n3EngineClientAnarchy_t__N3Msg_Consider = n3EngineClientAnarchy_t__N3Msg_Consider_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_ContainerAddItem_x
//		n3EngineClientAnarchy_t__N3Msg_ContainerAddItem = n3EngineClientAnarchy_t__N3Msg_ContainerAddItem_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_CrawlToggle_x
//		n3EngineClientAnarchy_t__N3Msg_CrawlToggle = n3EngineClientAnarchy_t__N3Msg_CrawlToggle_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_CreateRaid_x
//		n3EngineClientAnarchy_t__N3Msg_CreateRaid = n3EngineClientAnarchy_t__N3Msg_CreateRaid_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_DefaultActionOnDynel_x
//		n3EngineClientAnarchy_t__N3Msg_DefaultActionOnDynel = n3EngineClientAnarchy_t__N3Msg_DefaultActionOnDynel_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_DefaultAttack_x
//		n3EngineClientAnarchy_t__N3Msg_DefaultAttack = n3EngineClientAnarchy_t__N3Msg_DefaultAttack_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_DeleteNano_x
//		n3EngineClientAnarchy_t__N3Msg_DeleteNano = n3EngineClientAnarchy_t__N3Msg_DeleteNano_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_DoSocialAction_x
//		n3EngineClientAnarchy_t__N3Msg_DoSocialAction = n3EngineClientAnarchy_t__N3Msg_DoSocialAction_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_DropItem_x
//		n3EngineClientAnarchy_t__N3Msg_DropItem = n3EngineClientAnarchy_t__N3Msg_DropItem_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_Duel_Accept_x
//		n3EngineClientAnarchy_t__N3Msg_Duel_Accept = n3EngineClientAnarchy_t__N3Msg_Duel_Accept_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_Duel_Challenge_x
//		n3EngineClientAnarchy_t__N3Msg_Duel_Challenge = n3EngineClientAnarchy_t__N3Msg_Duel_Challenge_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_Duel_Draw_x
//		n3EngineClientAnarchy_t__N3Msg_Duel_Draw = n3EngineClientAnarchy_t__N3Msg_Duel_Draw_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_Duel_Refuse_x
//		n3EngineClientAnarchy_t__N3Msg_Duel_Refuse = n3EngineClientAnarchy_t__N3Msg_Duel_Refuse_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_Duel_Stop_x
//		n3EngineClientAnarchy_t__N3Msg_Duel_Stop = n3EngineClientAnarchy_t__N3Msg_Duel_Stop_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_Forage_x
//		n3EngineClientAnarchy_t__N3Msg_Forage = n3EngineClientAnarchy_t__N3Msg_Forage_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetActionByName_x
//		n3EngineClientAnarchy_t__N3Msg_GetActionByName = n3EngineClientAnarchy_t__N3Msg_GetActionByName_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetActionProgress_x
//		n3EngineClientAnarchy_t__N3Msg_GetActionProgress = n3EngineClientAnarchy_t__N3Msg_GetActionProgress_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetAggDef_x
//		n3EngineClientAnarchy_t__N3Msg_GetAggDef = n3EngineClientAnarchy_t__N3Msg_GetAggDef_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetAlienLevelString_x
//		n3EngineClientAnarchy_t__N3Msg_GetAlienLevelString = n3EngineClientAnarchy_t__N3Msg_GetAlienLevelString_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetAreaName_x
//		n3EngineClientAnarchy_t__N3Msg_GetAreaName = n3EngineClientAnarchy_t__N3Msg_GetAreaName_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetAttackingID_x
//		n3EngineClientAnarchy_t__N3Msg_GetAttackingID = n3EngineClientAnarchy_t__N3Msg_GetAttackingID_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetBreedStr_x
//		n3EngineClientAnarchy_t__N3Msg_GetBreedStr = n3EngineClientAnarchy_t__N3Msg_GetBreedStr_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetBuffCurrentTime_x
//		n3EngineClientAnarchy_t__N3Msg_GetBuffCurrentTime = n3EngineClientAnarchy_t__N3Msg_GetBuffCurrentTime_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetBuffTotalTime_x
//		n3EngineClientAnarchy_t__N3Msg_GetBuffTotalTime = n3EngineClientAnarchy_t__N3Msg_GetBuffTotalTime_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetCharacterBodyShape_x
//		n3EngineClientAnarchy_t__N3Msg_GetCharacterBodyShape = n3EngineClientAnarchy_t__N3Msg_GetCharacterBodyShape_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetCharOrientationData_x
//		n3EngineClientAnarchy_t__N3Msg_GetCharOrientationData = n3EngineClientAnarchy_t__N3Msg_GetCharOrientationData_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetCityNameForClanMember_x
//		n3EngineClientAnarchy_t__N3Msg_GetCityNameForClanMember = n3EngineClientAnarchy_t__N3Msg_GetCityNameForClanMember_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetClanLevelString_x
//		n3EngineClientAnarchy_t__N3Msg_GetClanLevelString = n3EngineClientAnarchy_t__N3Msg_GetClanLevelString_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetClanString_x
//		n3EngineClientAnarchy_t__N3Msg_GetClanString = n3EngineClientAnarchy_t__N3Msg_GetClanString_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetClientPetID_x
//		n3EngineClientAnarchy_t__N3Msg_GetClientPetID = n3EngineClientAnarchy_t__N3Msg_GetClientPetID_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetCloseTarget_x
//		n3EngineClientAnarchy_t__N3Msg_GetCloseTarget = n3EngineClientAnarchy_t__N3Msg_GetCloseTarget_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetContainerInventoryList_x
//		n3EngineClientAnarchy_t__N3Msg_GetContainerInventoryList = n3EngineClientAnarchy_t__N3Msg_GetContainerInventoryList_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetCorrectActionID_x
//		n3EngineClientAnarchy_t__N3Msg_GetCorrectActionID = n3EngineClientAnarchy_t__N3Msg_GetCorrectActionID_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetCurrentRoom_x
//		n3EngineClientAnarchy_t__N3Msg_GetCurrentRoom = n3EngineClientAnarchy_t__N3Msg_GetCurrentRoom_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetCurrentRoomName_x
//		n3EngineClientAnarchy_t__N3Msg_GetCurrentRoomName = n3EngineClientAnarchy_t__N3Msg_GetCurrentRoomName_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetDistrictFightMode_x
//		n3EngineClientAnarchy_t__N3Msg_GetDistrictFightMode = n3EngineClientAnarchy_t__N3Msg_GetDistrictFightMode_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetDynelsInVicinity_x
//		n3EngineClientAnarchy_t__N3Msg_GetDynelsInVicinity = n3EngineClientAnarchy_t__N3Msg_GetDynelsInVicinity_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetFactionInfoString_x
//		n3EngineClientAnarchy_t__N3Msg_GetFactionInfoString = n3EngineClientAnarchy_t__N3Msg_GetFactionInfoString_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetFactionRange_x
//		n3EngineClientAnarchy_t__N3Msg_GetFactionRange = n3EngineClientAnarchy_t__N3Msg_GetFactionRange_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetFirstName_x
//		n3EngineClientAnarchy_t__N3Msg_GetFirstName = n3EngineClientAnarchy_t__N3Msg_GetFirstName_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetFormulaProgress_x
//		n3EngineClientAnarchy_t__N3Msg_GetFormulaProgress = n3EngineClientAnarchy_t__N3Msg_GetFormulaProgress_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetFormulaRadius_x
//		n3EngineClientAnarchy_t__N3Msg_GetFormulaRadius = n3EngineClientAnarchy_t__N3Msg_GetFormulaRadius_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetGlobalCharacterPosition_x
//		n3EngineClientAnarchy_t__N3Msg_GetGlobalCharacterPosition = n3EngineClientAnarchy_t__N3Msg_GetGlobalCharacterPosition_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetGlobalCharacterRotation_x
//		n3EngineClientAnarchy_t__N3Msg_GetGlobalCharacterRotation = n3EngineClientAnarchy_t__N3Msg_GetGlobalCharacterRotation_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetGridDestinationList_1_x
//		n3EngineClientAnarchy_t__N3Msg_GetGridDestinationList_1 = n3EngineClientAnarchy_t__N3Msg_GetGridDestinationList_1_x + gamecode_module_handle;
//#endif
//#ifdef  n3EngineClientAnarchy_t__N3Msg_GetGridDestinationList_2_x
//		n3EngineClientAnarchy_t__N3Msg_GetGridDestinationList_2 = n3EngineClientAnarchy_t__N3Msg_GetGridDestinationList_2_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetInventoryVec_x
//		n3EngineClientAnarchy_t__N3Msg_GetInventoryVec = n3EngineClientAnarchy_t__N3Msg_GetInventoryVec_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetItem_x
//		n3EngineClientAnarchy_t__N3Msg_GetItem = n3EngineClientAnarchy_t__N3Msg_GetItem_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetItemProgress_x
//		n3EngineClientAnarchy_t__N3Msg_GetItemProgress = n3EngineClientAnarchy_t__N3Msg_GetItemProgress_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetMovementMode_x
//		n3EngineClientAnarchy_t__N3Msg_GetMovementMode = n3EngineClientAnarchy_t__N3Msg_GetMovementMode_x + gamecode_module_handle;
//#endif
//#ifdef 	n3EngineClientAnarchy_t__N3Msg_GetName_x
//		n3EngineClientAnarchy_t__N3Msg_GetName = n3EngineClientAnarchy_t__N3Msg_GetName_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetNanoCostModifier_x
//		n3EngineClientAnarchy_t__N3Msg_GetNanoCostModifier = n3EngineClientAnarchy_t__N3Msg_GetNanoCostModifier_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetNanoSpellList_x
//		n3EngineClientAnarchy_t__N3Msg_GetNanoSpellList = n3EngineClientAnarchy_t__N3Msg_GetNanoSpellList_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetNanoTemplateInfoList_1_x
//		n3EngineClientAnarchy_t__N3Msg_GetNanoTemplateInfoList_1 = n3EngineClientAnarchy_t__N3Msg_GetNanoTemplateInfoList_1_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetNanoTemplateInfoList_2_x
//		n3EngineClientAnarchy_t__N3Msg_GetNanoTemplateInfoList_2 = n3EngineClientAnarchy_t__N3Msg_GetNanoTemplateInfoList_2_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetNextTarget_x
//		n3EngineClientAnarchy_t__N3Msg_GetNextTarget = n3EngineClientAnarchy_t__N3Msg_GetNextTarget_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetNumberOfAvailableAlienPerks_x
//		n3EngineClientAnarchy_t__N3Msg_GetNumberOfAvailableAlienPerks = n3EngineClientAnarchy_t__N3Msg_GetNumberOfAvailableAlienPerks_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetNumberOfAvailablePerks_x
//		n3EngineClientAnarchy_t__N3Msg_GetNumberOfAvailablePerks = n3EngineClientAnarchy_t__N3Msg_GetNumberOfAvailablePerks_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetNumberOfFreeInventorySlots_x
//		n3EngineClientAnarchy_t__N3Msg_GetNumberOfFreeInventorySlots = n3EngineClientAnarchy_t__N3Msg_GetNumberOfFreeInventorySlots_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetNumberOfUsedAlienPerks_x
//		n3EngineClientAnarchy_t__N3Msg_GetNumberOfUsedAlienPerks = n3EngineClientAnarchy_t__N3Msg_GetNumberOfUsedAlienPerks_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetNumberOfUsedPerks_x
//		n3EngineClientAnarchy_t__N3Msg_GetNumberOfUsedPerks = n3EngineClientAnarchy_t__N3Msg_GetNumberOfUsedPerks_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetOverEquipLevel_x
//		n3EngineClientAnarchy_t__N3Msg_GetOverEquipLevel = n3EngineClientAnarchy_t__N3Msg_GetOverEquipLevel_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetPFName_1_x
//		n3EngineClientAnarchy_t__N3Msg_GetPFName_1 = n3EngineClientAnarchy_t__N3Msg_GetPFName_1_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetPFName_2_x
//		n3EngineClientAnarchy_t__N3Msg_GetPFName_2 = n3EngineClientAnarchy_t__N3Msg_GetPFName_2_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetParent_x
//		n3EngineClientAnarchy_t__N3Msg_GetParent = n3EngineClientAnarchy_t__N3Msg_GetParent_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetPos_x
//		n3EngineClientAnarchy_t__N3Msg_GetPos = n3EngineClientAnarchy_t__N3Msg_GetPos_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetSkill_1_x
//		n3EngineClientAnarchy_t__N3Msg_GetSkill_1 = n3EngineClientAnarchy_t__N3Msg_GetSkill_1_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetSkill_2_x
//		n3EngineClientAnarchy_t__N3Msg_GetSkill_2 = n3EngineClientAnarchy_t__N3Msg_GetSkill_2_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetSkillMax_x
//		n3EngineClientAnarchy_t__N3Msg_GetSkillMax = n3EngineClientAnarchy_t__N3Msg_GetSkillMax_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetSpecialActionList_x
//		n3EngineClientAnarchy_t__N3Msg_GetSpecialActionList = n3EngineClientAnarchy_t__N3Msg_GetSpecialActionList_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetSpecialActionState_x
//		n3EngineClientAnarchy_t__N3Msg_GetSpecialActionState = n3EngineClientAnarchy_t__N3Msg_GetSpecialActionState_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetSpecialAttackWeaponName_x
//		n3EngineClientAnarchy_t__N3Msg_GetSpecialAttackWeaponName = n3EngineClientAnarchy_t__N3Msg_GetSpecialAttackWeaponName_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetStatNameMap_x
//		n3EngineClientAnarchy_t__N3Msg_GetStatNameMap = n3EngineClientAnarchy_t__N3Msg_GetStatNameMap_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetTargetTarget_x
//		n3EngineClientAnarchy_t__N3Msg_GetTargetTarget = n3EngineClientAnarchy_t__N3Msg_GetTargetTarget_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetTeamMemberList_x
//		n3EngineClientAnarchy_t__N3Msg_GetTeamMemberList = n3EngineClientAnarchy_t__N3Msg_GetTeamMemberList_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_HasPerk_x
//		n3EngineClientAnarchy_t__N3Msg_HasPerk = n3EngineClientAnarchy_t__N3Msg_HasPerk_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsAttacking_x
//		n3EngineClientAnarchy_t__N3Msg_IsAttacking = n3EngineClientAnarchy_t__N3Msg_IsAttacking_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsBattleStation_x
//		n3EngineClientAnarchy_t__N3Msg_IsBattleStation = n3EngineClientAnarchy_t__N3Msg_IsBattleStation_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsCharacterInMech_x
//		n3EngineClientAnarchy_t__N3Msg_IsCharacterInMech = n3EngineClientAnarchy_t__N3Msg_IsCharacterInMech_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsCharacterMorphed_x
//		n3EngineClientAnarchy_t__N3Msg_IsCharacterMorphed = n3EngineClientAnarchy_t__N3Msg_IsCharacterMorphed_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsDungeon_x
//		n3EngineClientAnarchy_t__N3Msg_IsDungeon = n3EngineClientAnarchy_t__N3Msg_IsDungeon_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsFormulaReady_x
//		n3EngineClientAnarchy_t__N3Msg_IsFormulaReady = n3EngineClientAnarchy_t__N3Msg_IsFormulaReady_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsGeneralPerk_x
//		n3EngineClientAnarchy_t__N3Msg_IsGeneralPerk = n3EngineClientAnarchy_t__N3Msg_IsGeneralPerk_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsGroupPerk_x
//		n3EngineClientAnarchy_t__N3Msg_IsGroupPerk = n3EngineClientAnarchy_t__N3Msg_IsGroupPerk_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsInRaidTeam_x
//		n3EngineClientAnarchy_t__N3Msg_IsInRaidTeam = n3EngineClientAnarchy_t__N3Msg_IsInRaidTeam_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsInTeam_x
//		n3EngineClientAnarchy_t__N3Msg_IsInTeam = n3EngineClientAnarchy_t__N3Msg_IsInTeam_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsItemDisabled_x
//		n3EngineClientAnarchy_t__N3Msg_IsItemDisabled = n3EngineClientAnarchy_t__N3Msg_IsItemDisabled_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsItemMine_x
//		n3EngineClientAnarchy_t__N3Msg_IsItemMine = n3EngineClientAnarchy_t__N3Msg_IsItemMine_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToUnWear_x
//		n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToUnWear = n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToUnWear_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToWear_x
//		n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToWear = n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToWear_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsMoving_x
//		n3EngineClientAnarchy_t__N3Msg_IsMoving = n3EngineClientAnarchy_t__N3Msg_IsMoving_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsMyPetID_x
//		n3EngineClientAnarchy_t__N3Msg_IsMyPetID = n3EngineClientAnarchy_t__N3Msg_IsMyPetID_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsNanoSelfOnly_x
//		n3EngineClientAnarchy_t__N3Msg_IsNanoSelfOnly = n3EngineClientAnarchy_t__N3Msg_IsNanoSelfOnly_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsNpc_x
//		n3EngineClientAnarchy_t__N3Msg_IsNpc = n3EngineClientAnarchy_t__N3Msg_IsNpc_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsPerk_x
//		n3EngineClientAnarchy_t__N3Msg_IsPerk = n3EngineClientAnarchy_t__N3Msg_IsPerk_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsPetTower_x
//		n3EngineClientAnarchy_t__N3Msg_IsPetTower = n3EngineClientAnarchy_t__N3Msg_IsPetTower_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsProfessionPerk_x
//		n3EngineClientAnarchy_t__N3Msg_IsProfessionPerk = n3EngineClientAnarchy_t__N3Msg_IsProfessionPerk_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsResearch_x
//		n3EngineClientAnarchy_t__N3Msg_IsResearch = n3EngineClientAnarchy_t__N3Msg_IsResearch_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsSecondarySpecialAttackAvailable_x
//		n3EngineClientAnarchy_t__N3Msg_IsSecondarySpecialAttackAvailable = n3EngineClientAnarchy_t__N3Msg_IsSecondarySpecialAttackAvailable_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsShieldDisablerItem_x
//		n3EngineClientAnarchy_t__N3Msg_IsShieldDisablerItem = n3EngineClientAnarchy_t__N3Msg_IsShieldDisablerItem_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsSpecialPerk_x
//		n3EngineClientAnarchy_t__N3Msg_IsSpecialPerk = n3EngineClientAnarchy_t__N3Msg_IsSpecialPerk_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsTeamLeader_x
//		n3EngineClientAnarchy_t__N3Msg_IsTeamLeader = n3EngineClientAnarchy_t__N3Msg_IsTeamLeader_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsTeamMission_x
//		n3EngineClientAnarchy_t__N3Msg_IsTeamMission = n3EngineClientAnarchy_t__N3Msg_IsTeamMission_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsTeamMissionCopy_x
//		n3EngineClientAnarchy_t__N3Msg_IsTeamMissionCopy = n3EngineClientAnarchy_t__N3Msg_IsTeamMissionCopy_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsTeamNano_x
//		n3EngineClientAnarchy_t__N3Msg_IsTeamNano = n3EngineClientAnarchy_t__N3Msg_IsTeamNano_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsTower_x
//		n3EngineClientAnarchy_t__N3Msg_IsTower = n3EngineClientAnarchy_t__N3Msg_IsTower_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_IsVisible_x
//		n3EngineClientAnarchy_t__N3Msg_IsVisible = n3EngineClientAnarchy_t__N3Msg_IsVisible_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_JoinItems_x
//		n3EngineClientAnarchy_t__N3Msg_JoinItems = n3EngineClientAnarchy_t__N3Msg_JoinItems_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_KickTeamMember_x
//		n3EngineClientAnarchy_t__N3Msg_KickTeamMember = n3EngineClientAnarchy_t__N3Msg_KickTeamMember_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_LeaveBattle_x
//		n3EngineClientAnarchy_t__N3Msg_LeaveBattle = n3EngineClientAnarchy_t__N3Msg_LeaveBattle_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_LeaveTeam_x
//		n3EngineClientAnarchy_t__N3Msg_LeaveTeam = n3EngineClientAnarchy_t__N3Msg_LeaveTeam_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_MeetsPerkCriteria_x
//		n3EngineClientAnarchy_t__N3Msg_MeetsPerkCriteria = n3EngineClientAnarchy_t__N3Msg_MeetsPerkCriteria_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_MoveItemToInventory_x
//		n3EngineClientAnarchy_t__N3Msg_MoveItemToInventory = n3EngineClientAnarchy_t__N3Msg_MoveItemToInventory_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_MoveRaidMember_x
//		n3EngineClientAnarchy_t__N3Msg_MoveRaidMember = n3EngineClientAnarchy_t__N3Msg_MoveRaidMember_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_NameToID_x
//		n3EngineClientAnarchy_t__N3Msg_NameToID = n3EngineClientAnarchy_t__N3Msg_NameToID_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatAddTradeItem_x
//		n3EngineClientAnarchy_t__N3Msg_NPCChatAddTradeItem = n3EngineClientAnarchy_t__N3Msg_NPCChatAddTradeItem_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatCloseWindow_x
//		n3EngineClientAnarchy_t__N3Msg_NPCChatCloseWindow = n3EngineClientAnarchy_t__N3Msg_NPCChatCloseWindow_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatEndTrade_x
//		n3EngineClientAnarchy_t__N3Msg_NPCChatEndTrade = n3EngineClientAnarchy_t__N3Msg_NPCChatEndTrade_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatRemoveTradeItem_x
//		n3EngineClientAnarchy_t__N3Msg_NPCChatRemoveTradeItem = n3EngineClientAnarchy_t__N3Msg_NPCChatRemoveTradeItem_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatStartTrade_x
//		n3EngineClientAnarchy_t__N3Msg_NPCChatStartTrade = n3EngineClientAnarchy_t__N3Msg_NPCChatStartTrade_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_OrbitalAttack_x
//		n3EngineClientAnarchy_t__N3Msg_OrbitalAttack = n3EngineClientAnarchy_t__N3Msg_OrbitalAttack_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_1_x
//		n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_1 = n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_1_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_2_x
//		n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_2 = n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_2_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_PetDuel_Accept_x
//		n3EngineClientAnarchy_t__N3Msg_PetDuel_Accept = n3EngineClientAnarchy_t__N3Msg_PetDuel_Accept_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_PetDuel_Challenge_x
//		n3EngineClientAnarchy_t__N3Msg_PetDuel_Challenge = n3EngineClientAnarchy_t__N3Msg_PetDuel_Challenge_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_PetDuel_Refuse_x
//		n3EngineClientAnarchy_t__N3Msg_PetDuel_Refuse = n3EngineClientAnarchy_t__N3Msg_PetDuel_Refuse_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_PetDuel_Stop_x
//		n3EngineClientAnarchy_t__N3Msg_PetDuel_Stop = n3EngineClientAnarchy_t__N3Msg_PetDuel_Stop + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_RemoveBuff_x
//		n3EngineClientAnarchy_t__N3Msg_RemoveBuff = n3EngineClientAnarchy_t__N3Msg_RemoveBuff_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_RemoveQuest_x
//		n3EngineClientAnarchy_t__N3Msg_RemoveQuest = n3EngineClientAnarchy_t__N3Msg_RemoveQuest_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_RequestCharacterInventory_x
//		n3EngineClientAnarchy_t__N3Msg_RequestCharacterInventory = n3EngineClientAnarchy_t__N3Msg_RequestCharacterInventory_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_RequestClothInventory_x
//		n3EngineClientAnarchy_t__N3Msg_RequestClothInventory = n3EngineClientAnarchy_t__N3Msg_RequestClothInventory_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_RequestImplantInventory_x
//		n3EngineClientAnarchy_t__N3Msg_RequestImplantInventory = n3EngineClientAnarchy_t__N3Msg_RequestImplantInventory_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_RequestSocialInventory_x
//		n3EngineClientAnarchy_t__N3Msg_RequestSocialInventory = n3EngineClientAnarchy_t__N3Msg_RequestSocialInventory_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_RequestWeaponInventory_x
//		n3EngineClientAnarchy_t__N3Msg_RequestWeaponInventory = n3EngineClientAnarchy_t__N3Msg_RequestWeaponInventory_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_SecondarySpecialAttack_x
//		n3EngineClientAnarchy_t__N3Msg_SecondarySpecialAttack = n3EngineClientAnarchy_t__N3Msg_SecondarySpecialAttack_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_SelectedTarget_x
//		n3EngineClientAnarchy_t__N3Msg_SelectedTarget = n3EngineClientAnarchy_t__N3Msg_SelectedTarget_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_SendPetCommand_x
//		n3EngineClientAnarchy_t__N3Msg_SendPetCommand = n3EngineClientAnarchy_t__N3Msg_SendPetCommand_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_SitToggle_x
//		n3EngineClientAnarchy_t__N3Msg_SitToggle = n3EngineClientAnarchy_t__N3Msg_SitToggle_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_SplitItem_x
//		n3EngineClientAnarchy_t__N3Msg_SplitItem = n3EngineClientAnarchy_t__N3Msg_SplitItem_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_StartAltState_x
//		n3EngineClientAnarchy_t__N3Msg_StartAltState = n3EngineClientAnarchy_t__N3Msg_StartAltState_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_StartCamping_x
//		n3EngineClientAnarchy_t__N3Msg_StartCamping = n3EngineClientAnarchy_t__N3Msg_StartCamping_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_StartTreatment_x
//		n3EngineClientAnarchy_t__N3Msg_StartTreatment = n3EngineClientAnarchy_t__N3Msg_StartTreatment_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_StopAltState_x
//		n3EngineClientAnarchy_t__N3Msg_StopAltState = n3EngineClientAnarchy_t__N3Msg_StopAltState_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_StopAttack_x
//		n3EngineClientAnarchy_t__N3Msg_StopAttack = n3EngineClientAnarchy_t__N3Msg_StopAttack_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_StopCamping_x
//		n3EngineClientAnarchy_t__N3Msg_StopCamping = n3EngineClientAnarchy_t__N3Msg_StopCamping_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_StringToStat_x
//		n3EngineClientAnarchy_t__N3Msg_StringToStat = n3EngineClientAnarchy_t__N3Msg_StringToStat_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_SwitchTarget_x
//		n3EngineClientAnarchy_t__N3Msg_SwitchTarget = n3EngineClientAnarchy_t__N3Msg_SwitchTarget_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_TeamJoinRequest_x
//		n3EngineClientAnarchy_t__N3Msg_TeamJoinRequest = n3EngineClientAnarchy_t__N3Msg_TeamJoinRequest_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_TemplateIDToDynelID_x
//		n3EngineClientAnarchy_t__N3Msg_TemplateIDToDynelID = n3EngineClientAnarchy_t__N3Msg_TemplateIDToDynelID_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_TextCommand_x
//		n3EngineClientAnarchy_t__N3Msg_TextCommand = n3EngineClientAnarchy_t__N3Msg_TextCommand_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_ToggleReclaim_x
//		n3EngineClientAnarchy_t__N3Msg_ToggleReclaim = n3EngineClientAnarchy_t__N3Msg_ToggleReclaim_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_TradeAbort_x
//		n3EngineClientAnarchy_t__N3Msg_TradeAbort = n3EngineClientAnarchy_t__N3Msg_TradeAbort + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_TradeAccept_x
//		n3EngineClientAnarchy_t__N3Msg_TradeAccept = n3EngineClientAnarchy_t__N3Msg_TradeAccept_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_TradeAddItem_x
//		n3EngineClientAnarchy_t__N3Msg_TradeAddItem = n3EngineClientAnarchy_t__N3Msg_TradeAddItem_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_TradeConfirm_x
//		n3EngineClientAnarchy_t__N3Msg_TradeConfirm = n3EngineClientAnarchy_t__N3Msg_TradeConfirm_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_TradeGetInventory_x
//		n3EngineClientAnarchy_t__N3Msg_TradeGetInventory = n3EngineClientAnarchy_t__N3Msg_TradeGetInventory_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_TradeRemoveItem_x
//		n3EngineClientAnarchy_t__N3Msg_TradeRemoveItem = n3EngineClientAnarchy_t__N3Msg_TradeRemoveItem_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_TradeSetCash_x
//		n3EngineClientAnarchy_t__N3Msg_TradeSetCash = n3EngineClientAnarchy_t__N3Msg_TradeSetCash_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_TradeStart_x
//		n3EngineClientAnarchy_t__N3Msg_TradeStart = n3EngineClientAnarchy_t__N3Msg_TradeStart_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_TradeskillCombine_x
//		n3EngineClientAnarchy_t__N3Msg_TradeskillCombine = n3EngineClientAnarchy_t__N3Msg_TradeskillCombine_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_TrainPerk_x
//		n3EngineClientAnarchy_t__N3Msg_TrainPerk = n3EngineClientAnarchy_t__N3Msg_TrainPerk_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_TransferTeamLeadership_x
//		n3EngineClientAnarchy_t__N3Msg_TransferTeamLeadership = n3EngineClientAnarchy_t__N3Msg_TransferTeamLeadership_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_TryAbortNanoFormula_x
//		n3EngineClientAnarchy_t__N3Msg_TryAbortNanoFormula = n3EngineClientAnarchy_t__N3Msg_TryAbortNanoFormula_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_TryEnterSneakMode_x
//		n3EngineClientAnarchy_t__N3Msg_TryEnterSneakMode = n3EngineClientAnarchy_t__N3Msg_TryEnterSneakMode_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_UntrainPerk_x
//		n3EngineClientAnarchy_t__N3Msg_UntrainPerk = n3EngineClientAnarchy_t__N3Msg_UntrainPerk_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_UseItem_x
//		n3EngineClientAnarchy_t__N3Msg_UseItem = n3EngineClientAnarchy_t__N3Msg_UseItem_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_UseItemOnItem_x
//		n3EngineClientAnarchy_t__N3Msg_UseItemOnItem = n3EngineClientAnarchy_t__N3Msg_UseItemOnItem_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__N3Msg_UseSkill_x
//		n3EngineClientAnarchy_t__N3Msg_UseSkill = n3EngineClientAnarchy_t__N3Msg_UseSkill_x + gamecode_module_handle;
//#endif
//#ifdef n3EngineClientAnarchy_t__SetMainDynel_x
//		n3EngineClientAnarchy_t__SetMainDynel = n3EngineClientAnarchy_t__SetMainDynel_x + gamecode_module_handle;
//#endif
//
//
//#ifdef n3Engine_t__SetTeleportStatus_x
//		n3Engine_t__SetTeleportStatus = n3Engine_t__SetTeleportStatus_x + n3_module_handle;
//#endif
//
//#ifdef n3EngineClient_t__SetMainDynel_x
//		n3EngineClient_t__SetMainDynel = n3EngineClient_t__SetMainDynel_x + n3_module_handle;
//#endif
//
//
//
//#pragma endregion
//
//#pragma region ItemManagement
//#ifdef ItemManager_t__m_ppcInstance_x
//		ItemManager_t__m_ppcInstance = ItemManager_t__m_ppcInstance_x + gamecode_module_handle;
//		pppItemVector = reinterpret_cast<std::vector<acg_game_item_t>***>(ItemManager_t__m_ppcInstance);
//#endif
//#ifdef 	NanoItemManager_t__m_pcInstance_x
//		NanoItemManager_t__m_pcInstance = NanoItemManager_t__m_pcInstance_x + gamecode_module_handle;
//		ppNanoItemDir = reinterpret_cast<nano_item_dir_t**>(NanoItemManager_t__m_pcInstance);
//#endif
//#ifdef __GetNanoItem_x
//		NanoItem_t__GetNanoItem = __GetNanoItem_x + gamecode_module_handle;
//#endif
//#ifdef StaticItemManager_t_mppcInstance_x
//		StaticItemManager_t_mppcInstance = StaticItemManager_t_mppcInstance_x + gamecode_module_handle;
//		pppStaticItemVector = reinterpret_cast<std::vector<static_item_t>***>(StaticItemManager_t_mppcInstance);
//#endif
//
//#pragma endregion
//
//#pragma region Dynel
//
//#ifdef n3Dynel_t__m_pcDynelDir_x
//		n3_dynel_t__m_pc_dynel_dir_instance = n3Dynel_t__m_pcDynelDir_x + n3_module_handle;
//		pp_dynel_dir = reinterpret_cast<dynel_dir_t**>(n3_dynel_t__m_pc_dynel_dir_instance);
//#endif
//
//#ifdef n3Dynel_t__SendIIRToObservers_x
//		n3_dynel_t__send_iir_to_observers = n3Dynel_t__SendIIRToObservers_x + n3_module_handle;
//#endif
//
//#ifdef n3Dynel_t__SetPlayfield_x
//		n3_dynel_t__set_playfield = n3Dynel_t__SetPlayfield_x + n3_module_handle;
//#endif
//
//#ifdef n3Dynel_t__UpdateLocalityListeners_x
//		n3_dynel_t__update_locality_listeners = n3Dynel_t__UpdateLocalityListeners_x + n3_module_handle;
//#endif
//
//#ifdef n3Dynel_t__n3Dynel_t_x
//		n3_dynel_t__n3_dynel_t = n3Dynel_t__n3Dynel_t_x + n3_module_handle;
//#endif
//#ifdef n3Dynel_t__dn3Dynel_t_x
//		n3_dynel_t__d_n3_dynel_t = n3Dynel_t__dn3Dynel_t_x + n3_module_handle;
//#endif
//#pragma endregion
//
//#pragma region Playfield
//		// Instances
//#ifdef n3Playfield_t__m_pcPlayfieldDir_x
//		n3Playfield_t__m_pcPlayfieldDir = n3Playfield_t__m_pcPlayfieldDir_x + n3_module_handle;
//		//pp_playfield_dir = (**(*reinterpret_cast<PlayfieldAnarchy*****>(n3Playfield_t__m_pcPlayfieldDir) + 1) + 4);
//		pp_playfield_dir = reinterpret_cast<PlayfieldDir**>(n3Playfield_t__m_pcPlayfieldDir);
//#endif
//		// Functions
//#ifdef n3EngineClientAnarchy_t__N3Msg_GetDynelsInVicinity_x
//		n3EngineClientAnarchy_t__N3Msg_GetDynelsInVicinity = n3EngineClientAnarchy_t__N3Msg_GetDynelsInVicinity_x + n3_module_handle;
//#endif
//
//#ifdef n3Playfield_t__LineOfSight_x
//		n3_playfield_t__line_of_sight = n3Playfield_t__LineOfSight_x + n3_module_handle;
//#endif
//
//#ifdef n3Playfield_t__AddChildDynel_x
//		n3_playfield_t__add_child_dynel = n3Playfield_t__AddChildDynel_x + n3_module_handle;
//#endif
//
//#ifdef n3Playfield_t__OnChildDynelBeingRemoved_x
//		n3Playfield_t__OnChildDynelBeingRemoved = n3Playfield_t__OnChildDynelBeingRemoved_x + gamecode_module_handle;
//#endif
//
//#ifdef n3Playfield_t__RemoveChild_x
//		n3_playfield_t__remove_child = n3Playfield_t__RemoveChild_x + n3_module_handle;
//#endif
//
//#ifdef PlayfieldAnarchy_t__PlayfieldAnarchy_t_x
//		PlayfieldAnarchy_t__PlayfieldAnarchy_t = PlayfieldAnarchy_t__PlayfieldAnarchy_t_x + gamecode_module_handle;
//#endif
//
//#ifdef PlayfieldAnarchy_t__dPlayfieldAnarchy_t_x
//		PlayfieldAnarchy_t__dPlayfieldAnarchy_t = PlayfieldAnarchy_t__dPlayfieldAnarchy_t_x + gamecode_module_handle;
//#endif
//
//
//#pragma endregion
//
//#pragma region Camera
//#ifdef n3Camera_t__SetSelectedTarget_x
//		n3_camera_t__set_selected_target = n3Camera_t__SetSelectedTarget_x + n3_module_handle;
//#endif
//#ifdef n3Camera_t__SetSecondaryTarget_x
//		n3_camera_t__set_secondary_target = n3Camera_t__SetSecondaryTarget_x + n3_module_handle;
//#endif
//#pragma endregion
//
//#pragma region Gametime
//#ifdef Gametime_t__m_pcInstance_x
//		Gametime_t__m_pcInstance = Gametime_t__m_pcInstance_x + gamecode_module_handle;
//		ppGametime = reinterpret_cast<GameTime**>(Gametime_t__m_pcInstance);
//#endif	
//#pragma endregion
//	
//#pragma region InputConfig
//
//#ifdef InputConfig_t__m_pcInstance_x
//		InputConfig_t__m_pcInstance = InputConfig_t__m_pcInstance_x + hGUI;
//		ppInputConfig = reinterpret_cast<InputConfig**>(InputConfig_t__m_pcInstance);
//#endif
//#ifdef InputConfig_t__SetCurrentTarget_x
//		InputConfig_t__SetCurrentTarget = InputConfig_t__SetCurrentTarget_x + hGUI;
//#endif
//
//#pragma endregion
//
//#pragma region FlowControl
//
//#ifdef FlowControlModule_t__m_pcInstance_x
//		FlowControlModule_t__m_pcInstance = FlowControlModule_t__m_pcInstance_x + hGUI;
//#endif
//#ifdef FlowControlModule_t__m_isLauncherRun_x
//		FlowControlModule_t__m_isLauncherRun = FlowControlModule_t__m_isLauncherRun_x + hGUI;
//#endif
//#ifdef FlowControlModule_t__m_bIsGameClosing_x
//		FlowControlModule_t__m_bIsGameClosing = FlowControlModule_t__m_bIsGameClosing_x + hGUI;
//#endif
//#ifdef FlowControlModule_t__m_nCloseFrames_x
//		FlowControlModule_t__m_nCloseFrames = FlowControlModule_t__m_nCloseFrames_x + hGUI;
//#endif
//#ifdef FlowControlModule_t__m_isTeleporting_x
//		FlowControlModule_t__m_isTeleporting = FlowControlModule_t__m_isTeleporting_x + hGUI;
//		gpbIsTeleporting = reinterpret_cast<bool*>(FlowControlModule_t__m_isTeleporting);
//#endif
//#ifdef FlowControlModule_t__m_eLoggingOutTimed_x
//		FlowControlModule_t__m_eLoggingOutTimed = FlowControlModule_t__m_eLoggingOutTimed_x + hGUI;
//#endif
//#ifdef FlowControlModule_t__m_isClientToRestartAtExit_x
//		FlowControlModule_t__m_isClientToRestartAtExit = FlowControlModule_t__m_isClientToRestartAtExit_x + hGUI;
//#endif
//
//#pragma endregion
//
//#pragma region TargetingModule
//
//#ifdef TargetingModule_t__m_pcInstance_x
//		TargetingModule_t__m_pcInstance = TargetingModule_t__m_pcInstance_x + hGUI;
//		ppTargetingModule = reinterpret_cast<TargetingModule**>(TargetingModule_t__m_pcInstance);
//#endif
//
//#ifdef TargetingModule_t__m_pcSelectionIndicator_x
//		TargetingModule_t__m_pcSelectionIndicator = TargetingModule_t__m_pcSelectionIndicator_x + hGUI;
//		ppSelectionIndicator = reinterpret_cast<indicator_t**>(TargetingModule_t__m_pcSelectionIndicator);
//#endif
//#ifdef TargetingModule_t__m_pcAttackingIndicator_x
//		TargetingModule_t__m_pcAttackingIndicator = TargetingModule_t__m_pcAttackingIndicator_x + hGUI;
//		ppAttackingIndicator = reinterpret_cast<indicator_t**>(TargetingModule_t__m_pcAttackingIndicator);
//#endif
//#ifdef TargetingModule_t__m_cLastTarget_x
//		TargetingModule_t__m_cLastTarget = TargetingModule_t__m_cLastTarget_x + hGUI;
//		pLastTarget = reinterpret_cast<identity_t*>(TargetingModule_t__m_cLastTarget);
//#endif
//#ifdef TargetingModule_t__RemoveTarget_x
//		TargetingModule_t__RemoveTarget = TargetingModule_t__RemoveTarget_x + hGUI;
//#endif
//#ifdef TargetingModule_t__SelectSelf_x
//		TargetingModule_t__SelectSelf = TargetingModule_t__SelectSelf_x + hGUI;
//#endif
//#ifdef TargetingModule_t__SetTarget_x
//		TargetingModule_t__SetTarget = TargetingModule_t__SetTarget_x + hGUI;
//#endif
//#ifdef TargetingModule_t__SetTargetPet_x
//		TargetingModule_t__SetTargetPet = TargetingModule_t__SetTargetPet_x + hGUI;
//#endif
//
//
//#pragma endregion
//
//#pragma region ChatGUIModule
//
//#ifdef ChatGUIModule_c__s_pcInstance_x
//		ChatGUIModule_c__s_pcInstance = ChatGUIModule_c__s_pcInstance_x + hGUI;
//		ppChatGUIModule = reinterpret_cast<ChatGUIModule**>(ChatGUIModule_c__s_pcInstance);
//#endif
//
//#ifdef ChatGUIModule_c__HandleGroupAction_x
//		ChatGUIModule_c__HandleGroupAction = ChatGUIModule_c__HandleGroupAction_x + hGUI;
//#endif
//
//#ifdef ChatGUIModule_c__HandleGroupMessage_x
//		ChatGUIModule_c__HandleGroupMessage = ChatGUIModule_c__HandleGroupMessage_x + hGUI;
//#endif
//
//#ifdef ChatGUIModule_c__HandlePrivateGroupAction_x
//		ChatGUIModule_c__HandlePrivateGroupAction = ChatGUIModule_c__HandlePrivateGroupAction_x + hGUI;
//#endif
//
//#ifdef ChatGUIModule_c__HandlePrivateMessage_x
//		ChatGUIModule_c__HandlePrivateMessage = ChatGUIModule_c__HandlePrivateMessage_x + hGUI;
//#endif
//
//#ifdef ChatGUIModule_c__HandleSystemMessage_x
//		ChatGUIModule_c__HandleSystemMessage = ChatGUIModule_c__HandleSystemMessage_x + hGUI;
//#endif
//
//#ifdef ChatGUIModule_c__HandleVicinityMessage_x
//		ChatGUIModule_c__HandleVicinityMessage = ChatGUIModule_c__HandleVicinityMessage_x + hGUI;
//#endif
//
//
//
//
//
//#pragma endregion
//
//#pragma region Vehicle
//
//#ifdef Vehicle_t__SetRelRot_x
//		Vehicle_t__SetRelRot = Vehicle_t__SetRelRot_x + hVehicle;
//#endif
//
//#pragma endregion
//
//#pragma region Client
//
//#ifdef Client_t__s_nCharID_x
//		Client_t__s_nCharID = Client_t__s_nCharID_x + hInterfaces;
//		gp_character_id = PDWORD(Client_t__s_nCharID);
//#endif
//
//#ifdef Client_t__ProcessMessage_x
//		Client_t__ProcessMessage = Client_t__ProcessMessage_x + hInterfaces;
//#endif
//
//#pragma endregion
//
//#pragma region Messaging
//
//#ifdef Message_t__DataBlockSizeGet_x
//		Message_t__DataBlockSizeGet = Message_t__DataBlockSizeGet_x + hMessageProtocol;
//#endif
//#ifdef Message_t__MessageSizeGet_x
//		Message_t__MessageSizeGet = Message_t__MessageSizeGet_x + hMessageProtocol;
//#endif
//
//#ifdef N3Message_t__DuplicateBody_x
//		N3Message_t__DuplicateBody = N3Message_t__DuplicateBody_x + hMessageProtocol;
//#endif
//#ifdef N3Message_t__MessageBodyGet_x
//		N3Message_t__MessageBodyGet = N3Message_t__MessageBodyGet_x + hMessageProtocol;
//#endif
//#ifdef N3Message_t__MessageBodyLen_x
//		N3Message_t__MessageBodyLen = N3Message_t__MessageBodyLen_x + hMessageProtocol;
//#endif
//
//#ifdef TextMessage_t__MessageBodyGet_x
//		TextMessage_t__MessageBodyGet = TextMessage_t__MessageBodyGet_x + hMessageProtocol;
//#endif
//
//#ifdef TextMessage_t__MessageBodyLen_x
//		TextMessage_t__MessageBodyLen = TextMessage_t__MessageBodyLen_x + hMessageProtocol;
//#endif
//
//#pragma endregion
//
//#pragma region vTables
//
//#ifdef AccessCard_t__vTable_x
//		AccessCard_t__vTable = AccessCard_t__vTable_x + gamecode_module_handle;
//#endif
//#ifdef CentralController_t__vTable_x
//		CentralController_t__vTable = CentralController_t__vTable_x + gamecode_module_handle;
//#endif
//#ifdef Chest_t__vTable_x
//		Chest_t__vTable = Chest_t__vTable_x + gamecode_module_handle;
//#endif
//#ifdef CityTerminal_t__vTable_x
//		CityTerminal_t__vTable = CityTerminal_t__vTable_x + gamecode_module_handle;
//#endif
//#ifdef Corpse_t__vTable_x
//		Corpse_t__vTable = Corpse_t__vTable_x + gamecode_module_handle;
//#endif
//#ifdef Door_t__vTable_x
//		Door_t__vTable = Door_t__vTable_x + gamecode_module_handle;
//#endif
//#ifdef LockableItem_t__vTable_x
//		LockableItem_t__vTable = LockableItem_t__vTable_x + gamecode_module_handle;
//#endif
//#ifdef Mine_t__vTable_x
//		Mine_t__vTable = Mine_t__vTable_x + gamecode_module_handle;
//#endif
//#ifdef PlayerShop_t__vTable_x
//		PlayerShop_t__vTable = PlayerShop_t__vTable_x + gamecode_module_handle;
//#endif
//#ifdef QuestBooth_t__vTable_x
//		QuestBooth_t__vTable = QuestBooth_t__vTable_x + gamecode_module_handle;
//#endif
//#ifdef ReclaimBooth_t__vTable_x
//		ReclaimBooth_t__vTable = ReclaimBooth_t__vTable_x + gamecode_module_handle;
//#endif
//#ifdef SimpleChar_t__vTable_x
//		SimpleChar_t__vTable = SimpleChar_t__vTable_x + gamecode_module_handle;
//#endif
//#ifdef SimpleItem_t__vTable_x
//		SimpleItem_t__vTable = SimpleItem_t__vTable_x + gamecode_module_handle;
//#endif
//#ifdef TrapItem_t__vTable_x
//		TrapItem_t__vTable = TrapItem_t__vTable_x + gamecode_module_handle;
//#endif
//#ifdef VendingMachine_t__vTable_x
//		VendingMachine_t__vTable = VendingMachine_t__vTable_x + gamecode_module_handle;
//#endif
//#ifdef Weapon_t__vTable_x
//		Weapon_t__vTable = Weapon_t__vTable_x + gamecode_module_handle;
//#endif
//
//
//#pragma endregion
//
//#pragma region SimpleChar
//
//#ifdef SimpleChar_t__SimpleChar_t_x
//		SimpleChar_t__SimpleChar_t = SimpleChar_t__SimpleChar_t_x + gamecode_module_handle;
//#endif
//#ifdef SimpleChar_t__dSimpleChar_t_x
//		SimpleChar_t__dSimpleChar_t = SimpleChar_t__dSimpleChar_t_x + gamecode_module_handle;
//#endif
//#ifdef SimpleChar_t__CheckLOS_x
//		SimpleChar_t__CheckLOS = SimpleChar_t__CheckLOS_x + gamecode_module_handle;
//#endif
//
//#pragma endregion
//
//#pragma region PlayerVehicle
//
//#ifdef PlayerVehicle_t__UseWaypointPath_x
//		PlayerVehicle_t__UseWaypointPath = PlayerVehicle_t__UseWaypointPath_x + gamecode_module_handle;
//#endif
//
//#pragma endregion
//
//#pragma region LoginModule
//
//#ifdef LoginModule_c__m_pcInstance_x
//		LoginModule_c__m_pcInstance = LoginModule_c__m_pcInstance_x + hGUI;
//		ppLoginModule = reinterpret_cast<login_module_t**>(LoginModule_c__m_pcInstance);
//#endif
//
//#pragma endregion
//
//#pragma region ChatWindowController
//
//#ifdef ChatWindowController_c__m_pcInstance_x
//		ChatWindowController_c__m_pcInstance = ChatWindowController_c__m_pcInstance_x + hGUI;
//		ppChatWindowController = reinterpret_cast<ChatWindowController**>(ChatWindowController_c__m_pcInstance);
//#endif
//
//#ifdef ChatGroupController_c__sub_10083D9C_x
//		ChatGroupController_c__sub_10083D9C = ChatGroupController_c__sub_10083D9C_x + hGUI;
//#endif
//
//#pragma endregion
//
//#pragma region FriendListController
//
//#ifdef FriendListController_c__sub_100A68E6_x
//		FriendListController_c__sub_100A68E6 = FriendListController_c__sub_100A68E6_x + hGUI;
//#endif
//
//#pragma endregion
//
//#pragma region CommandInterpreter
//
//#ifdef CommandInterpreter_c__m_pcInstance_x
//		CommandInterpreter_c__m_pcInstance = CommandInterpreter_c__m_pcInstance_x + hGUI;
//		ppCommandInterpreter = reinterpret_cast<CommandInterpreter**>(CommandInterpreter_c__m_pcInstance);
//#endif
//
//#ifdef CommandInterpreter_c__ParseTextCommand_x
//		CommandInterpreter_c__ParseTextCommand = CommandInterpreter_c__ParseTextCommand_x + hGUI;
//#endif
//
//#pragma endregion
//
//#pragma region ChatWindowNode
//#ifdef ChatWindowNode_c__ParseTextCommand_x
//		ChatWindowNode_c__ParseTextCommand = ChatWindowNode_c__ParseTextCommand_x + hGUI;
//#endif
//
//#ifdef ChatWindowNode_c__sub_1009BB79_x
//		ChatWindowNode_c__sub_1009BB79 = ChatWindowNode_c__sub_1009BB79_x + hGUI;
//#endif
//
//#pragma endregion
//
//#pragma region HTMLParser
//
//#ifdef HTMLParser_c__HTMLParser_c_x
//		HTMLParser_c__HTMLParser_c = HTMLParser_c__HTMLParser_c_x + hGUI;
//#endif
//
//#ifdef HTMLParser_c__dHTMLParser_c_x
//		HTMLParser_c__dHTMLParser_c = HTMLParser_c__dHTMLParser_c_x + hGUI;
//#endif
//
//#ifdef HTMLParser_c__HTMLParser_c_copy_x
//		HTMLParser_c__HTMLParser_c_copy = HTMLParser_c__HTMLParser_c_copy_x + hGUI;
//#endif
//
//#ifdef HTMLParser_c__ExtractText_x
//		HTMLParser_c__ExtractText = HTMLParser_c__ExtractText_x + hGUI;
//#endif
//
//
//#pragma endregion
//
//#pragma region LookAtIIR
//
//#ifdef LookAtIIR_t__sub_10073E4D_x
//		LookAtIIR_t__sub_10073E4D = LookAtIIR_t__sub_10073E4D_x + gamecode_module_handle;
//#endif
//
//#pragma endregion
//
//#pragma region ResourceDatabase
//
//#ifdef ResourceDatabase_t__GetDbObject_1_x
//		ResourceDatabase_t__GetDbObject_1 = ResourceDatabase_t__GetDbObject_1_x + hDatabaseController;
//#endif
//
//#ifdef ResourceDatabase_t__GetIdentityVec_x
//		ResourceDatabase_t__GetIdentityVec = ResourceDatabase_t__GetIdentityVec_x + hDatabaseController;
//#endif
//
//#pragma endregion
//
//#pragma region n3DatabaseHandler
//
//#ifdef n3DatabaseHandler_t__s_pcInstance_x
//		n3DatabaseHandler_t__s_pcInstance = n3DatabaseHandler_t__s_pcInstance_x + n3_module_handle;
//		ppDatabaseHandler = reinterpret_cast<DatabaseHandler**>(n3DatabaseHandler_t__s_pcInstance);
//#endif
//		
//
//#pragma endregion
//
//#pragma region PathGraphFinder
//
//#ifdef GraphPathFinder_t__GraphPathFinder_t_x
//		GraphPathFinder_t__GraphPathFinder_t = GraphPathFinder_t__GraphPathFinder_t_x + hPathFinder;
//#endif
//
//#ifdef GraphPathFinder_t__GraphPathFinder_t_Copy_x
//		GraphPathFinder_t__GraphPathFinder_t_Copy = GraphPathFinder_t__GraphPathFinder_t_Copy_x + hPathFinder;
//#endif
//
//#ifdef GraphPathFinder_t__dGraphPathFinder_t_x
//		GraphPathFinder_t__dGraphPathFinder_t = GraphPathFinder_t__dGraphPathFinder_t_x + hPathFinder;
//#endif
//
//#ifdef GraphPathFinder_t__Configure_x
//		GraphPathFinder_t__Configure = GraphPathFinder_t__Configure_x + hPathFinder;
//#endif
//
//#ifdef GraphPathFinder_t__CreateFromData_x
//		GraphPathFinder_t__CreateFromData = GraphPathFinder_t__CreateFromData_x + hPathFinder;
//#endif
//
//#ifdef GraphPathFinder_t__FindPath_x
//		GraphPathFinder_t__FindPath = GraphPathFinder_t__FindPath_x + hPathFinder;
//#endif
//
//#ifdef GraphPathFinder_t__GenerateGraph_x
//		GraphPathFinder_t__GenerateGraph = GraphPathFinder_t__GenerateGraph_x + hPathFinder;
//#endif
//
//#ifdef GraphPathFinder_t__GenerateGraphForRoom_x
//		GraphPathFinder_t__GenerateGraphForRoom = GraphPathFinder_t__GenerateGraphForRoom_x + hPathFinder;
//#endif
//
//#ifdef GraphPathFinder_t__Init_x
//		GraphPathFinder_t__Init = GraphPathFinder_t__Init_x + hPathFinder;
//#endif
//
//#ifdef GraphPathFinder_t__SetSpaceForGraph_x
//		GraphPathFinder_t__SetSpaceForGraph = GraphPathFinder_t__SetSpaceForGraph_x + hPathFinder;
//#endif
//
//#ifdef GraphPathFinder_t__SetSurface_x
//		GraphPathFinder_t__SetSurface = GraphPathFinder_t__SetSurface_x + hPathFinder;
//#endif

#pragma endregion

		return true;
	}

#pragma region Process

	HANDLE process_handle = nullptr;

#pragma endregion

#pragma region Globals

	DWORD __GetBreedStr = 0;
	DWORD __GetNanoItem = 0;
	DWORD __GetSexStr = 0;	
	DWORD __N3Msg_GetFullPerkMap = 0;
	DWORD __SetTarget = 0;
	DWORD m_cStatNameDir = 0;
	stat_name_dir_t StatNameDir;
	stat_name_dir_t *pStatNameDir = nullptr;
	DWORD __RequestInfo = 0;
	DWORD __StatToString = 0;

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

	// Instances
	DWORD n3_engine_client_anarchy_t__m_pc_instance = 0;
	engine_client_anarchy **pp_engine_client_anarchy = nullptr;

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

#pragma region EngineClientAnarchy

	// Client Instance
	

	// Client Functions
	
	
	
	
	
		
	DWORD n3EngineClientAnarchy_t__GetGenderString = 0;
	DWORD n3EngineClientAnarchy_t__GetItemByTemplate = 0;	
	DWORD n3EngineClientAnarchy_t__GetTitleStr = 0;
	DWORD n3EngineClientAnarchy_t__IsFirstLogin = 0;
	DWORD n3EngineClientAnarchy_t__IsFixture = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_ActivateMech = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_Airstrike = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_ArtilleryAttack = 0;
	DWORD n3EngineClientAnarchy_t__N3Msg_AssistFight = 0;
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
	DWORD n3EngineClientAnarchy_t__N3Msg_GetGlobalCharacterPosition = 0;
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
	DWORD SimpleChar_t__CheckLOS = 0;

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

	bool get_static_address_from_function(const DWORD& function_base_address, DWORD& static_address, const char* static_address_name, const size_t offset)
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

	bool get_relative_address_from_function(const DWORD& function_base_address, DWORD& relative_address, const char* relative_address_name, const size_t offset, const size_t bytes_to_next_line)
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

}
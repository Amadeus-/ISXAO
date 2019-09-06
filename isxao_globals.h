
namespace isxao_globals
{
	bool initialize_offsets();

#pragma region Process

	AOLIB_VAR HANDLE process_handle;

#pragma endregion

#pragma region Modules

	AOLIB_VAR HMODULE gamecode_module_handle;
	AOLIB_VAR MODULEINFO gamecode_module_info;
	AOLIB_VAR HMODULE n3_module_handle;
	AOLIB_VAR MODULEINFO n3_module_info;
	AOLIB_VAR DWORD hGUI;
	AOLIB_VAR DWORD hVehicle;
	AOLIB_VAR DWORD hMessageProtocol;
	AOLIB_VAR DWORD hInterfaces;

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
	AOLIB_VAR dynel_dir_t **pp_dynel_dir;
#define P_DYNEL_DIR (*pp_dynel_dir)  // NOLINT(cppcoreguidelines-macro-usage)

	// Functions
	AOLIB_VAR DWORD n3_engine_t__n3_engine_t;

	// Instances
	AOLIB_VAR DWORD n3_engine_t__m_pc_instance;

	// Functions
	AOLIB_VAR DWORD n3_engine_client_t__get_client_control_dynel;

	// Functions
	AOLIB_VAR DWORD n3_playfield_t__add_child_dynel;
	AOLIB_VAR DWORD n3_playfield_t__get_playfield;
	AOLIB_VAR DWORD n3_playfield_t__line_of_sight;
	AOLIB_VAR DWORD n3_playfield_t__remove_child;

	// Instances
	AOLIB_VAR DWORD n3_playfield_t__m_pc_playfield_dir_instance;
	AOLIB_VAR PlayfieldDir** pp_playfield_dir;
#define P_PLAYFIELD_DIR (*pp_playfield_dir)  // NOLINT(cppcoreguidelines-macro-usage)

#pragma endregion

#pragma region Gamecode

	// Functions
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

	// Instances
	AOLIB_VAR DWORD n3_engine_client_anarchy_t__m_pc_instance;
	AOLIB_VAR isxao_classes::engine_client_anarchy **pp_engine_client_anarchy;
#define P_ENGINE_CLIENT_ANARCHY (*pp_engine_client_anarchy)  // NOLINT(cppcoreguidelines-macro-usage)

#pragma endregion

#pragma region Globals

	AOLIB_VAR DWORD __N3Msg_GetFullPerkMap;
	AOLIB_VAR DWORD __SetTarget;
	AOLIB_VAR DWORD m_cStatNameDir;
	AOLIB_VAR stat_name_dir_t StatNameDir;
	AOLIB_VAR stat_name_dir_t *pStatNameDir;
	AOLIB_VAR DWORD __RequestInfo;
	AOLIB_VAR DWORD __StatToString;

#pragma endregion

#pragma region EngineClientAnarchy		
	
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_CanAttack;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_CanClickTargetTarget;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_CanUseMech;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_CastNanoSpell;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_Consider;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_ContainerAddItem;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_CrawlToggle;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_CreateRaid;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_DefaultActionOnDynel;	
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_DefaultAttack;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_DeleteNano;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_DoSocialAction;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_DropItem;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_Duel_Accept;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_Duel_Challenge;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_Duel_Draw;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_Duel_Refuse;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_Duel_Stop;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_FlashHead;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_Forage;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetActionByName;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetActionProgress;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetAggDef;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetAlienLevelString;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetAreaName;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetAttackingID;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetBreedStr;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetBuffCurrentTime;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetBuffTotalTime;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetCharacterBodyShape;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetCharOrientationData;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetCityNameForClanMember;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetClanLevelString;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetClanString;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetClientPetID;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetCloseTarget;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetContainerInventoryList;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetCorrectActionID;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetCurrentRoom;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetCurrentRoomName;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetDistrictFightMode;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetDynelsInVicinity;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetFactionInfoString;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetFactionRange;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetFirstName;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetFormulaProgress;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetFormulaRadius;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetGlobalCharacterPosition;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetGlobalCharacterRotation;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetGridDestinationList_1;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetGridDestinationList_2;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetInventoryVec;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetItem;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetItemProgress;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetMovementMode;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetName;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetNanoCostModifier;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetNanoSpellList;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetNanoTemplateInfoList_1;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetNanoTemplateInfoList_2;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetNextTarget;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetNumberOfAvailableAlienPerks;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetNumberOfAvailablePerks;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetNumberOfFreeInventorySlots;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetNumberOfUsedAlienPerks;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetNumberOfUsedPerks;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetOverEquipLevel;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetPFName_1;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetPFName_2;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetParent;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetPos;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetSkill_1;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetSkill_2;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetSkillMax;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetSpecialActionList;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetSpecialActionState;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetSpecialAttackWeaponName;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetStatNameMap;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetTargetTarget;
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
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_IsNpc;
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
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_1;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_2;
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
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_SendPetCommand;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_SitToggle;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_SplitItem;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_StartAltState;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_StartCamping;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_StartPvP;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_StartTreatment;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_StopAltState;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_StopAttack;
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
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_UseItem;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_UseItemOnItem;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_UseSkill;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__SetMainDynel;

	AOLIB_VAR DWORD n3Engine_t__SetTeleportStatus;

	AOLIB_VAR DWORD n3EngineClient_t__SetMainDynel;

#pragma endregion

#pragma region ItemManager

	// Item Vector Instance
	AOLIB_VAR DWORD ItemManager_t__m_ppcInstance;
	AOLIB_VAR std::vector<acg_game_item_t> ***pppItemVector;
#define pItemVector (**pppItemVector)
	// NanoMap Instance
	AOLIB_VAR DWORD NanoItemManager_t__m_pcInstance;
	AOLIB_VAR nano_item_dir_t **ppNanoItemDir;
#define pNanoItemDir (*ppNanoItemDir)
	AOLIB_VAR DWORD NanoItem_t__GetNanoItem;
	// Action Item Manager
	AOLIB_VAR DWORD StaticItemManager_t_mppcInstance;
	AOLIB_VAR std::vector<static_item_t> ***pppStaticItemVector;
#define pStaticItemVector (**pppStaticItemVector)
	
#pragma endregion


#pragma region Playfield

	
	AOLIB_VAR DWORD n3Playfield_t__OnChildDynelBeingRemoved;
	

	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetDynelsInVicinity;


	AOLIB_VAR DWORD PlayfieldAnarchy_t__PlayfieldAnarchy_t;
	AOLIB_VAR DWORD PlayfieldAnarchy_t__dPlayfieldAnarchy_t;

#pragma endregion

#pragma region Gametime
	AOLIB_VAR DWORD Gametime_t__m_pcInstance;
	AOLIB_VAR GameTime** ppGametime;
#define pGametime (*ppGametime)
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

#pragma region TargetingModule

	AOLIB_VAR DWORD TargetingModule_t__m_pcInstance;
	AOLIB_VAR TargetingModule** ppTargetingModule;
#define pTargetingModule (*ppTargetingModule)
	AOLIB_VAR DWORD TargetingModule_t__m_pcSelectionIndicator;
	AOLIB_VAR indicator_t** ppSelectionIndicator;
#define pSelectionIndicator (*ppSelectionIndicator)
	AOLIB_VAR DWORD TargetingModule_t__m_pcAttackingIndicator;
	AOLIB_VAR indicator_t** ppAttackingIndicator;
#define pAttackingIndicator (*ppAttackingIndicator)
	AOLIB_VAR DWORD TargetingModule_t__m_cLastTarget;
	AOLIB_VAR identity_t* pLastTarget;
#define LastTarget (*pLastTarget)
	AOLIB_VAR DWORD TargetingModule_t__RemoveTarget;
	AOLIB_VAR DWORD TargetingModule_t__SelectSelf;
	AOLIB_VAR DWORD TargetingModule_t__SetTarget;
	AOLIB_VAR DWORD TargetingModule_t__SetTargetPet;



#pragma endregion

#pragma region ChatGUIModule

	AOLIB_VAR DWORD  ChatGUIModule_c__s_pcInstance;
	AOLIB_VAR ChatGUIModule** ppChatGUIModule;
#define pChatGUIModule (*ppChatGUIModule)

	AOLIB_VAR DWORD ChatGUIModule_c__HandleGroupAction;
	AOLIB_VAR DWORD ChatGUIModule_c__HandleGroupMessage;
	AOLIB_VAR DWORD ChatGUIModule_c__HandlePrivateGroupAction;
	AOLIB_VAR DWORD ChatGUIModule_c__HandlePrivateMessage;
	AOLIB_VAR DWORD ChatGUIModule_c__HandleSystemMessage;
	AOLIB_VAR DWORD ChatGUIModule_c__HandleVicinityMessage;


#pragma endregion

#pragma region Vehicle

	AOLIB_VAR DWORD Vehicle_t__SetRelRot;

#pragma endregion

#pragma region Client

	AOLIB_VAR DWORD Client_t__s_nCharID;
	AOLIB_VAR PDWORD gp_character_id;
#define g_character_id (*gp_character_id)
	AOLIB_VAR DWORD Client_t__ProcessMessage;

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
	AOLIB_VAR DWORD SimpleChar_t__CheckLOS;

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
	AOLIB_VAR ChatWindowController** ppChatWindowController;
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

	AOLIB_VAR DWORD ChatWindowNode_c__ParseTextCommand;

	AOLIB_VAR DWORD ChatWindowNode_c__sub_1009BB79;

#pragma endregion

#pragma region HTMLParser

	AOLIB_VAR DWORD HTMLParser_c__HTMLParser_c;
	AOLIB_VAR DWORD HTMLParser_c__dHTMLParser_c;
	AOLIB_VAR DWORD HTMLParser_c__HTMLParser_c_copy;
	AOLIB_VAR DWORD HTMLParser_c__ExtractText;

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
	AOLIB_VAR DatabaseHandler** ppDatabaseHandler;
#define pDatabaseHandler (*ppDatabaseHandler)

#pragma endregion

#pragma region GraphPathFinder

	AOLIB_VAR DWORD GraphPathFinder_t__GraphPathFinder_t;
	AOLIB_VAR DWORD GraphPathFinder_t__GraphPathFinder_t_Copy;
	AOLIB_VAR DWORD GraphPathFinder_t__dGraphPathFinder_t;
	AOLIB_VAR DWORD GraphPathFinder_t__Configure;
	AOLIB_VAR DWORD GraphPathFinder_t__CreateFromData;
	AOLIB_VAR DWORD GraphPathFinder_t__FindPath;
	AOLIB_VAR DWORD GraphPathFinder_t__GenerateGraph;
	AOLIB_VAR DWORD GraphPathFinder_t__GenerateGraphForRoom;
	AOLIB_VAR DWORD GraphPathFinder_t__Init;
	AOLIB_VAR DWORD GraphPathFinder_t__SetSpaceForGraph;
	AOLIB_VAR DWORD GraphPathFinder_t__SetSurface;

#pragma endregion

	bool get_function_address(const std::vector<unsigned char>& data, const char* function_pattern, DWORD& module_base_address, DWORD& function_address, const char* function_offset_name);
	bool get_static_address_from_function(const DWORD& function_base_address, DWORD& static_address, const char* static_address_name, const size_t& offset);
	bool get_relative_address_from_function(const DWORD& function_base_address, DWORD& relative_address, const char* relative_address_name, const size_t& offset, const size_t& bytes_to_next_line);
	bool get_proc_address(const HMODULE& module_handle, DWORD& function_address, const char* function_name, const char* mangled_function_name);

}
using namespace isxao_globals;

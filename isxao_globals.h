
namespace isxao_globals
{
	bool InitializeOffsets();

#pragma region Modules

	AOLIB_VAR DWORD hGamecode;
	AOLIB_VAR DWORD hN3;
	AOLIB_VAR DWORD hGUI;
	AOLIB_VAR DWORD hVehicle;
	AOLIB_VAR DWORD hMessageProtocol;
	AOLIB_VAR DWORD hInterfaces;

#pragma endregion

#pragma region Globals

	AOLIB_VAR DWORD __GetBreedStr;	
	AOLIB_VAR DWORD __GetDynel;
	AOLIB_VAR DWORD __GetNanoItem;
	AOLIB_VAR DWORD __GetSexStr;	
	AOLIB_VAR DWORD __N3Msg_GetFullPerkMap;
	AOLIB_VAR DWORD __SetTarget;
	AOLIB_VAR DWORD m_cStatNameDir;
	AOLIB_VAR STATNAMEDIR StatNameDir;
	AOLIB_VAR STATNAMEDIR *pStatNameDir;
	AOLIB_VAR DWORD __RequestInfo;

#pragma endregion

#pragma region EngineClientAnarchy

	// Client Instance
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__m_pcInstance;
	AOLIB_VAR EngineClientAnarchy **ppEngineClientAnarchy;
#define pEngineClientAnarchy (*ppEngineClientAnarchy)

	// Client Functions
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__n3EngineClientAnarchy_t;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__dn3EngineClientAnarchy_t;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__GetClientChar;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__GetClientDynelId;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__GetCurrentMovementMode;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__GetFactionStr;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__GetFactionTitle;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__GetGenderString;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__GetItemByTemplate;	
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__GetTitleStr;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__IsFirstLogin;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__IsFixture;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_ActivateMech;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_Airstrike;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_ArtilleryAttack;
	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_AssistFight;
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
	AOLIB_VAR std::vector<ACGGAMEITEM> ***pppItemVector;
#define pItemVector (**pppItemVector)
	// NanoMap Instance
	AOLIB_VAR DWORD NanoItemManager_t__m_pcInstance;
	AOLIB_VAR NANOITEMDIR **ppNanoItemDir;
#define pNanoItemDir (*ppNanoItemDir)
	AOLIB_VAR DWORD NanoItem_t__GetNanoItem;
	// Action Item Manager
	AOLIB_VAR DWORD StaticItemManager_t_mppcInstance;
	AOLIB_VAR std::vector<STATICITEM> ***pppStaticItemVector;
#define pStaticItemVector (**pppStaticItemVector)
	
#pragma endregion

#pragma region Dynel
	// Instances
	AOLIB_VAR DWORD n3Dynel_t__m_pcDynelDir;
	AOLIB_VAR DYNELDIR **ppDynelDir;
#define pDynelDir (*ppDynelDir)
	// Functions
	AOLIB_VAR DWORD n3Dynel_t__SendIIRToObservers;
	AOLIB_VAR DWORD n3Dynel_t__SetPlayfield;
	AOLIB_VAR DWORD n3Dynel_t__UpdateLocalityListeners;
	AOLIB_VAR DWORD n3Dynel_t__n3Dynel_t;
	AOLIB_VAR DWORD n3Dynel_t__dn3Dynel_t;
#pragma endregion

#pragma region Playfield
	// Instance
	AOLIB_VAR DWORD n3Playfield_t__m_pcPlayfieldDir;
	AOLIB_VAR PlayfieldDir** ppPlayfieldDir;
#define pPlayfieldDir (*ppPlayfieldDir)
	// Functions
	AOLIB_VAR DWORD n3Playfield_t__AddChildDynel;
	AOLIB_VAR DWORD n3Playfield_t__LineOfSight;
	AOLIB_VAR DWORD n3Playfield_t__OnChildDynelBeingRemoved;
	AOLIB_VAR DWORD n3Playfield_t__RemoveChild;

	AOLIB_VAR DWORD n3EngineClientAnarchy_t__N3Msg_GetDynelsInVicinity;




	AOLIB_VAR DWORD PlayfieldAnarchy_t__PlayfieldAnarchy_t;
	AOLIB_VAR DWORD PlayfieldAnarchy_t__dPlayfieldAnarchy_t;

#pragma endregion

#pragma region Camera

	AOLIB_VAR DWORD n3Camera_t__SetSelectedTarget;
	AOLIB_VAR DWORD n3Camera_t__SetSecondaryTarget;

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
	AOLIB_VAR INDICATOR** ppSelectionIndicator;
#define pSelectionIndicator (*ppSelectionIndicator)
	AOLIB_VAR DWORD TargetingModule_t__m_pcAttackingIndicator;
	AOLIB_VAR INDICATOR** ppAttackingIndicator;
#define pAttackingIndicator (*ppAttackingIndicator)
	AOLIB_VAR DWORD TargetingModule_t__m_cLastTarget;
	AOLIB_VAR IDENTITY* pLastTarget;
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
	AOLIB_VAR LOGINMODULE** ppLoginModule;
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

}
using namespace isxao_globals;

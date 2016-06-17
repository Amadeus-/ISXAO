#pragma once

class EngineClientAnarchy
{
public:
	AOLIB_OBJECT Character* GetClientChar() const;
	AOLIB_OBJECT PIDENTITY GetClientDynelId(IDENTITY &id) const;
	AOLIB_OBJECT DWORD GetCurrentMovementMode() const;
	AOLIB_OBJECT N3ENGINECLIENTANARCHY GetEngineClientAnarchyData() const;
	AOLIB_OBJECT PCSTR GetFactionStr(DWORD faction_id, bool unknown);
	AOLIB_OBJECT PCSTR GetFactionTitle(DWORD faction_id);
	AOLIB_OBJECT PCSTR GetGenderString(const IDENTITY &id);
	AOLIB_OBJECT PDUMMYITEMBASE GetItemByTemplate(IDENTITY template_id, const IDENTITY & container_id);
	AOLIB_OBJECT PCSTR GetTitleStr(DWORD base, DWORD level);
	AOLIB_OBJECT bool IsFirstLogin() const;
	AOLIB_OBJECT bool IsFixture(const IDENTITY &template_id, const IDENTITY &container_id);
	AOLIB_OBJECT void N3Msg_ActivateMech(DWORD mech_id);
	AOLIB_OBJECT void N3Msg_Airstrike(const IDENTITY &target_id);
	AOLIB_OBJECT void N3Msg_ArtilleryAttack(const IDENTITY &target_id);
	AOLIB_OBJECT void N3Msg_AssistFight(const IDENTITY &assist_id);
	AOLIB_OBJECT bool N3Msg_CanAttack(IDENTITY const &target_id);
	AOLIB_OBJECT bool N3Msg_CanClickTargetTarget(const IDENTITY &, const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_CanUseMech();
	AOLIB_OBJECT void N3Msg_CastNanoSpell(const IDENTITY &, const IDENTITY &);
	AOLIB_OBJECT DWORD N3Msg_Consider(const IDENTITY &, float &);
	AOLIB_OBJECT void N3Msg_ContainerAddItem(const IDENTITY &, const IDENTITY &);
	AOLIB_OBJECT void N3Msg_CrawlToggle();
	AOLIB_OBJECT void N3Msg_CreateRaid();
	AOLIB_OBJECT void N3Msg_DefaultActionOnDynel(const IDENTITY &);
	AOLIB_OBJECT void N3Msg_DefaultAttack(const IDENTITY &, bool);
	AOLIB_OBJECT void N3Msg_DeleteNano(const IDENTITY &);
	AOLIB_OBJECT DWORD N3Msg_DoSocialAction(DWORD);
	AOLIB_OBJECT void N3Msg_DropItem(const IDENTITY &, const VECTOR3 &);
	AOLIB_OBJECT void N3Msg_Duel_Accept();
	AOLIB_OBJECT void N3Msg_Duel_Challenge(const IDENTITY &);
	AOLIB_OBJECT void N3Msg_Duel_Draw();
	AOLIB_OBJECT void N3Msg_Duel_Refuse();
	AOLIB_OBJECT void N3Msg_Duel_Stop();
	AOLIB_OBJECT void N3Msg_Forage();
	AOLIB_OBJECT DWORD N3Msg_GetActionByName(PCSTR);
	AOLIB_OBJECT double N3Msg_GetActionProgress(const IDENTITY &, DWORD*, DWORD*);
	AOLIB_OBJECT LONG N3Msg_GetAggDef();
	AOLIB_OBJECT PCSTR N3Msg_GetAlienLevelString(const IDENTITY &);
	AOLIB_OBJECT void N3Msg_GetAreaName(PCSTR*);
	AOLIB_OBJECT bool N3Msg_GetAttackingID(IDENTITY &) const;
	AOLIB_OBJECT PCSTR N3Msg_GetBreedStr(const IDENTITY &);
	AOLIB_OBJECT DWORD N3Msg_GetBuffCurrentTime(const IDENTITY &, const IDENTITY &);
	AOLIB_OBJECT DWORD N3Msg_GetBuffTotalTime(const IDENTITY &, const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_GetCharacterBodyShape(BYTE &, IDENTITY);
	AOLIB_OBJECT bool N3Msg_GetCharOrientationData(const IDENTITY &, VECTOR3 &, QUATERNION &, float &);
	AOLIB_OBJECT PCSTR N3Msg_GetCityNameForClanMember(const IDENTITY &);
	AOLIB_OBJECT PCSTR N3Msg_GetClanLevelString(const IDENTITY &);
	AOLIB_OBJECT std::string* N3Msg_GetClanString(const IDENTITY &);
	AOLIB_OBJECT PIDENTITY N3Msg_GetClientPetID(IDENTITY &, DWORD);
	AOLIB_OBJECT bool N3Msg_GetCloseTarget(IDENTITY &, bool, bool);
	AOLIB_OBJECT PVOID N3Msg_GetContainerInventoryList(const IDENTITY &);
	AOLIB_OBJECT void N3Msg_GetCorrectActionID(IDENTITY &);
	AOLIB_OBJECT LONG N3Msg_GetCurrentRoom();
	AOLIB_OBJECT PCSTR N3Msg_GetCurrentRoomName();
	AOLIB_OBJECT DWORD N3Msg_GetDistrictFightMode();
	AOLIB_OBJECT bool N3Msg_GetFactionInfoString(const IDENTITY &, std::string &);
	AOLIB_OBJECT bool N3Msg_GetFactionRange(DWORD, DWORD &, DWORD &);
	AOLIB_OBJECT PCSTR N3Msg_GetFirstName(const IDENTITY &);
	AOLIB_OBJECT double N3Msg_GetFormulaProgress(const IDENTITY &, DWORD &, DWORD &);
	AOLIB_OBJECT DWORD N3Msg_GetFormulaRadius(const IDENTITY &);
	AOLIB_OBJECT void N3Msg_GetGlobalCharacterPosition(VECTOR3 &);
	AOLIB_OBJECT void N3Msg_GetGlobalCharacterRotation(QUATERNION &);
	AOLIB_OBJECT PVOID N3Msg_GetGridDestinationList() const;
	AOLIB_OBJECT std::vector<PINVENTORYDATA>* N3Msg_GetInventoryVec(const IDENTITY &);
	AOLIB_OBJECT void N3Msg_GetItem(const IDENTITY &);
	AOLIB_OBJECT double N3Msg_GetItemProgress(const IDENTITY &, DWORD &, DWORD &);
	AOLIB_OBJECT DWORD N3Msg_GetMovementMode();
	AOLIB_OBJECT PCSTR N3Msg_GetName(const IDENTITY &, const IDENTITY &);
	AOLIB_OBJECT DWORD N3Msg_GetNanoCostModifier();
	AOLIB_OBJECT std::list<DWORD>* N3Msg_GetNanoSpellList() const;
	AOLIB_OBJECT std::list<NANOTEMPLATE>* N3Msg_GetNanoTemplateInfoList(const IDENTITY &);
	AOLIB_OBJECT std::list<NANOTEMPLATE>* N3Msg_GetNanoTemplateInfoList() const;
	AOLIB_OBJECT PIDENTITY N3Msg_GetNextTarget(IDENTITY &, DWORD);
	AOLIB_OBJECT DWORD N3Msg_GetNumberOfAvailableAlienPerks();
	AOLIB_OBJECT DWORD N3Msg_GetNumberOfAvailablePerks();
	AOLIB_OBJECT DWORD N3Msg_GetNumberOfFreeInventorySlots();
	AOLIB_OBJECT DWORD N3Msg_GetNumberOfUsedAlienPerks();
	AOLIB_OBJECT DWORD N3Msg_GetNumberOfUsedPerks();
	AOLIB_OBJECT DWORD N3Msg_GetOverEquipLevel(const IDENTITY &);
	AOLIB_OBJECT PCSTR N3Msg_GetPFName(DWORD);
	AOLIB_OBJECT PCSTR N3Msg_GetPFName();
	AOLIB_OBJECT bool N3Msg_GetParent(const IDENTITY &, IDENTITY &);
	AOLIB_OBJECT bool N3Msg_GetPos(const IDENTITY &, VECTOR3 &);
	AOLIB_OBJECT LONG N3Msg_GetSkill(DWORD, DWORD);
	AOLIB_OBJECT LONG N3Msg_GetSkill(const IDENTITY &, DWORD, DWORD, const IDENTITY &);
	AOLIB_OBJECT LONG N3Msg_GetSkillMax(DWORD);
	AOLIB_OBJECT std::list<SPECIALACTION>* N3Msg_GetSpecialActionList() const;
	AOLIB_OBJECT DWORD N3Msg_GetSpecialActionState(const IDENTITY &);
	AOLIB_OBJECT PCSTR N3Msg_GetSpecialAttackWeaponName(const IDENTITY &);
	AOLIB_OBJECT PIDENTITY N3Msg_GetTargetTarget(IDENTITY &, const IDENTITY &);
	AOLIB_OBJECT PVOID N3Msg_GetTeamMemberList(LONG);
	AOLIB_OBJECT bool N3Msg_HasPerk(DWORD);
	AOLIB_OBJECT bool N3Msg_IsAttacking() const;
	AOLIB_OBJECT bool N3Msg_IsBattleStation();
	AOLIB_OBJECT bool N3Msg_IsCharacterInMech(IDENTITY);
	AOLIB_OBJECT bool N3Msg_IsCharacterMorphed(IDENTITY);
	AOLIB_OBJECT bool N3Msg_IsDungeon();
	AOLIB_OBJECT bool N3Msg_IsFormulaReady(const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_IsGeneralPerk(DWORD);
	AOLIB_OBJECT bool N3Msg_IsGroupPerk(DWORD);
	AOLIB_OBJECT bool N3Msg_IsInRaidTeam();
	AOLIB_OBJECT bool N3Msg_IsInTeam(const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_IsItemDisabled(const IDENTITY &, const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_IsItemMine(const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_IsItemNFCrystal(const IDENTITY &, const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_IsItemPossibleToUnWear(const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_IsItemPossibleToWear(const IDENTITY &, DWORD, DWORD, bool, DWORD);
	AOLIB_OBJECT bool N3Msg_IsMoving();
	AOLIB_OBJECT bool N3Msg_IsMyPetID(const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_IsNanoSelfOnly(const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_IsNpc(const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_IsPerk(DWORD);
	AOLIB_OBJECT bool N3Msg_IsPetTower(const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_IsProfessionPerk(DWORD);
	AOLIB_OBJECT bool N3Msg_IsResearch(DWORD);
	AOLIB_OBJECT bool N3Msg_IsSecondarySpecialAttackAvailable(DWORD);
	AOLIB_OBJECT bool N3Msg_IsShieldDisablerItem(const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_IsSpecialPerk(DWORD);
	AOLIB_OBJECT bool N3Msg_IsTeamLeader(const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_IsTeamMission(const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_IsTeamMissionCopy(const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_IsTeamNano(const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_IsTower(const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_IsVisible(const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_JoinItems(const IDENTITY &, const IDENTITY &);
	AOLIB_OBJECT void N3Msg_KickTeamMember(const IDENTITY &);
	AOLIB_OBJECT void N3Msg_LeaveBattle();
	AOLIB_OBJECT void N3Msg_LeaveTeam();
	AOLIB_OBJECT bool N3Msg_MeetsPerkCriteria(DWORD);
	AOLIB_OBJECT bool N3Msg_MoveItemToInventory(const IDENTITY &, DWORD, DWORD);
	AOLIB_OBJECT void N3Msg_MoveRaidMember(const IDENTITY &, DWORD);
	AOLIB_OBJECT bool N3Msg_NameToID(const std::string &, IDENTITY &);
	AOLIB_OBJECT void N3Msg_NPCChatAddTradeItem(const IDENTITY &, const IDENTITY &, const IDENTITY &);
	AOLIB_OBJECT void N3Msg_NPCChatCloseWindow(const IDENTITY &, const IDENTITY &);
	AOLIB_OBJECT void N3Msg_NPCChatEndTrade(const IDENTITY &, const IDENTITY &, DWORD, bool);
	AOLIB_OBJECT void N3Msg_NPCChatRemoveTradeItem(const IDENTITY &, const IDENTITY &, const IDENTITY &);
	AOLIB_OBJECT void N3Msg_NPCChatRequestDescription(const IDENTITY &, const IDENTITY &);
	AOLIB_OBJECT void N3Msg_NPCChatStartTrade(const IDENTITY &, const IDENTITY &);
	AOLIB_OBJECT void N3Msg_OrbitalAttack(const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_PerformSpecialAction(DWORD);
	AOLIB_OBJECT bool N3Msg_PerformSpecialAction(const IDENTITY &);
	AOLIB_OBJECT void N3Msg_PetDuel_Accept();
	AOLIB_OBJECT void N3Msg_PetDuel_Challenge(const IDENTITY &);
	AOLIB_OBJECT void N3Msg_PetDuel_Refuse();
	AOLIB_OBJECT void N3Msg_PetDuel_Stop();
	AOLIB_OBJECT bool N3Msg_RemoveBuff(const IDENTITY &);
	AOLIB_OBJECT void N3Msg_RemoveQuest(const IDENTITY &);
	AOLIB_OBJECT std::list<INVENTORYENTRY>* N3Msg_RequestCharacterInventory();
	AOLIB_OBJECT std::list<INVENTORYENTRY>* N3Msg_RequestClothInventory(const IDENTITY &);
	AOLIB_OBJECT std::list<INVENTORYENTRY>* N3Msg_RequestImplantInventory(const IDENTITY &);
	AOLIB_OBJECT std::list<INVENTORYENTRY>* N3Msg_RequestSocialInventory(const IDENTITY &);
	AOLIB_OBJECT std::list<INVENTORYENTRY>* N3Msg_RequestWeaponInventory(const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_SecondarySpecialAttack(const IDENTITY &, DWORD);
	AOLIB_OBJECT void N3Msg_SelectedTarget(const IDENTITY&);
	AOLIB_OBJECT void N3Msg_SendPetCommand(DWORD, const IDENTITY &, DWORD, DWORD, PCSTR); // 0, PetIdentity&, PetCommand_e, 0, nullptr
	AOLIB_OBJECT void N3Msg_SitToggle();
	AOLIB_OBJECT bool N3Msg_SplitItem(const IDENTITY &, DWORD);
	AOLIB_OBJECT void N3Msg_StartAltState();
	AOLIB_OBJECT bool N3Msg_StartCamping();
	AOLIB_OBJECT void N3Msg_StartPvP(const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_StartTreatment(const IDENTITY &);
	AOLIB_OBJECT void N3Msg_StopAltState();
	AOLIB_OBJECT void N3Msg_StopAttack();
	AOLIB_OBJECT void N3Msg_StopCamping();
	AOLIB_OBJECT DWORD N3Msg_StringToStat(PCSTR);
	AOLIB_OBJECT void N3Msg_SwitchTarget(const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_TeamJoinRequest(const IDENTITY &, bool);
	AOLIB_OBJECT PIDENTITY N3Msg_TemplateIDToDynelID(IDENTITY &, const IDENTITY &); // dummy, template
	AOLIB_OBJECT bool N3Msg_TextCommand(DWORD, PCSTR, const IDENTITY &);
	AOLIB_OBJECT void N3Msg_ToggleReclaim(bool);
	AOLIB_OBJECT void N3Msg_TradeAbort(bool);
	AOLIB_OBJECT void N3Msg_TradeAccept();
	AOLIB_OBJECT void N3Msg_TradeAddItem(const IDENTITY &, const IDENTITY &, DWORD);
	AOLIB_OBJECT void N3Msg_TradeConfirm();
	AOLIB_OBJECT PVOID N3Msg_TradeGetInventory(const IDENTITY &);
	AOLIB_OBJECT DWORD N3Msg_TradeGetInventoryCost(const IDENTITY &);
	AOLIB_OBJECT void N3Msg_TradeRemoveItem(const IDENTITY &, const IDENTITY &);
	AOLIB_OBJECT void N3Msg_TradeSetCash(DWORD);
	AOLIB_OBJECT void N3Msg_TradeStart(const IDENTITY &);
	AOLIB_OBJECT void N3Msg_TradeskillCombine(const IDENTITY &, const IDENTITY &);
	AOLIB_OBJECT bool N3Msg_TrainPerk(DWORD);
	AOLIB_OBJECT void N3Msg_TransferTeamLeadership(const IDENTITY &);
	AOLIB_OBJECT void N3Msg_TryAbortNanoFormula();
	AOLIB_OBJECT void N3Msg_TryEnterSneakMode();
	AOLIB_OBJECT bool N3Msg_UntrainPerk(DWORD);
	AOLIB_OBJECT void N3Msg_UseItem(const IDENTITY &, bool);
	AOLIB_OBJECT void N3Msg_UseItemOnItem(const IDENTITY &, const IDENTITY &);	


	private:
	N3ENGINECLIENTANARCHY n3_engine_client_anarchy_;






};
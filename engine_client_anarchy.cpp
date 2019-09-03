#include "isxao_main.h"

namespace isxao_classes
{
#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_CLIENT_CHAR
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(Character* EngineClientAnarchy::get_client_char(void), n3_engine_client_anarchy_t__get_client_char);
#else
	Character* EngineClientAnarchy::GetClientChar(void)
	{
		return reinterpret_cast<Character*>(n3_engine_client_anarchy_.p_client_control_char);
	}
#endif	

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_CLIENT_DYNEL_ID
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(p_identity_t EngineClientAnarchy::get_client_dynel_id(identity_t &), n3_engine_client_anarchy_t__get_client_dynel_id);
#else
	p_identity_t EngineClientAnarchy::GetClientDynelId(identity_t& id)
	{
		id.Type = 50000;
		id.Id = n3_engine_client_anarchy_.client_inst_id;
		return &id;
	}
#endif	

#ifdef N3_ENGINE_CLIENT_ANARCHY_T__GET_CURRENT_MOVEMENT_MODE
	FUNCTION_AT_ADDRESS(DWORD EngineClientAnarchy::get_current_movement_mode(void), n3_engine_client_anarchy_t__get_current_movement_mode);
#else
	DWORD EngineClientAnarchy::GetCurrentMovementMode() const
	{
		return n3_engine_client_anarchy_.p_client_control_char->pVehicle->pCharMovementStatus->MovementMode;
	}
#endif

	

	n3_engine_client_anarchy_t EngineClientAnarchy::get_engine_client_anarchy_data() const
	{
		return n3_engine_client_anarchy_;
	}

	FUNCTION_AT_ADDRESS(PCSTR EngineClientAnarchy::GetFactionStr(DWORD, bool), n3_engine_client_anarchy_t__get_faction_str);

	FUNCTION_AT_ADDRESS(PCSTR EngineClientAnarchy::GetFactionTitle(DWORD), n3_engine_client_anarchy_t__get_faction_title);


#ifdef n3EngineClientAnarchy_t__GetGenderString_x
	FUNCTION_AT_ADDRESS(PCSTR EngineClientAnarchy::GetGenderString(const identity_t &), n3EngineClientAnarchy_t__GetGenderString);
#endif

#ifdef n3EngineClientAnarchy_t__GetItemByTemplate_x
	FUNCTION_AT_ADDRESS(p_dummy_item_base_t EngineClientAnarchy::GetItemByTemplate(identity_t, const identity_t &), n3EngineClientAnarchy_t__GetItemByTemplate);
#endif

#ifdef n3EngineClientAnarchy_t__GetTitleStr_x
	FUNCTION_AT_ADDRESS(PCSTR EngineClientAnarchy::GetTitleStr(DWORD, DWORD), n3EngineClientAnarchy_t__GetTitleStr);
#endif

#ifdef n3EngineClientAnarchy_t__IsFirstLogin_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::IsFirstLogin(void), n3EngineClientAnarchy_t__IsFirstLogin);
#endif

	bool EngineClientAnarchy::IsFirstLogin(void) const
	{
		return n3_engine_client_anarchy_.is_first_login == 1;
	}

#ifdef n3EngineClientAnarchy_t__IsFixture_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::IsFixture(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__IsFixture);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_ActivateMech_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_ActivateMech(DWORD), n3EngineClientAnarchy_t__N3Msg_ActivateMech);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_Airstrike_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_Airstrike(const identity_t &), n3EngineClientAnarchy_t__N3Msg_Airstrike);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_ArtilleryAttack_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_ArtilleryAttack(const identity_t &), n3EngineClientAnarchy_t__N3Msg_ArtilleryAttack);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_AssistFight_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_AssistFight(const identity_t &), n3EngineClientAnarchy_t__N3Msg_AssistFight);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_CanAttack_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_CanAttack(const identity_t &), n3EngineClientAnarchy_t__N3Msg_CanAttack);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_CanClickTargetTarget_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_CanClickTargetTarget(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_CanClickTargetTarget);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_CanUseMech_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_CanUseMech(void), n3EngineClientAnarchy_t__N3Msg_CanUseMech);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_CastNanoSpell_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_CastNanoSpell(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_CastNanoSpell);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_Consider_x
	FUNCTION_AT_ADDRESS(DWORD EngineClientAnarchy::N3Msg_Consider(const identity_t &, float &), n3EngineClientAnarchy_t__N3Msg_Consider);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_ContainerAddItem_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_ContainerAddItem(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_ContainerAddItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_CrawlToggle_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_CrawlToggle(void), n3EngineClientAnarchy_t__N3Msg_CrawlToggle);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_CreateRaid_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_CreateRaid(void), n3EngineClientAnarchy_t__N3Msg_CreateRaid);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_DefaultActionOnDynel_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_DefaultActionOnDynel(const identity_t &), n3EngineClientAnarchy_t__N3Msg_DefaultActionOnDynel);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_DefaultAttack_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_DefaultAttack(const identity_t &, bool), n3EngineClientAnarchy_t__N3Msg_DefaultAttack);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_DeleteNano_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_DeleteNano(const identity_t &), n3EngineClientAnarchy_t__N3Msg_DeleteNano);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_DoSocialAction_x
	FUNCTION_AT_ADDRESS(DWORD EngineClientAnarchy::N3Msg_DoSocialAction(DWORD), n3EngineClientAnarchy_t__N3Msg_DoSocialAction);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_DropItem_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_DropItem(const identity_t &, const vector3_t &), n3EngineClientAnarchy_t__N3Msg_DropItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_Duel_Accept_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_Duel_Accept(void), n3EngineClientAnarchy_t__N3Msg_Duel_Accept);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_Duel_Challenge_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_Duel_Challenge(const identity_t &), n3EngineClientAnarchy_t__N3Msg_Duel_Challenge);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_Duel_Draw_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_Duel_Draw(void), n3EngineClientAnarchy_t__N3Msg_Duel_Draw);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_Duel_Refuse_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_Duel_Refuse(void), n3EngineClientAnarchy_t__N3Msg_Duel_Refuse);
#endif

#ifdef  n3EngineClientAnarchy_t__N3Msg_Duel_Stop_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_Duel_Stop(void), n3EngineClientAnarchy_t__N3Msg_Duel_Stop);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_Forage_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_Forage(void), n3EngineClientAnarchy_t__N3Msg_Forage);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetActionByName_x
	FUNCTION_AT_ADDRESS(DWORD EngineClientAnarchy::N3Msg_GetActionByName(PCSTR), n3EngineClientAnarchy_t__N3Msg_GetActionByName);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetActionProgress_x
	FUNCTION_AT_ADDRESS(double EngineClientAnarchy::N3Msg_GetActionProgress(const identity_t &, DWORD*, DWORD*), n3EngineClientAnarchy_t__N3Msg_GetActionProgress);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetAggDef_x
	FUNCTION_AT_ADDRESS(LONG EngineClientAnarchy::N3Msg_GetAggDef(void), n3EngineClientAnarchy_t__N3Msg_GetAggDef);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetAlienLevelString_x
	FUNCTION_AT_ADDRESS(PCSTR EngineClientAnarchy::N3Msg_GetAlienLevelString(const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetAlienLevelString)
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetAreaName_x
		FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_GetAreaName(PCSTR*), n3EngineClientAnarchy_t__N3Msg_GetAreaName);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetAttackingID_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_GetAttackingID(const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetAttackingID);
#endif

	bool EngineClientAnarchy::N3Msg_GetAttackingID(identity_t& id) const
	{
		if (n3_engine_client_anarchy_.p_client_control_char->pWeaponHolder->IsAttacking == 1)
		{
			id = n3_engine_client_anarchy_.p_client_control_char->pWeaponHolder->WeaponTargetIdentity;
			return true;
		}
		return false;
	}

#ifdef n3EngineClientAnarchy_t__N3Msg_GetBreedStr_x
	FUNCTION_AT_ADDRESS(PCSTR EngineClientAnarchy::N3Msg_GetBreedStr(const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetBreedStr);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetBuffCurrentTime_x
	FUNCTION_AT_ADDRESS(DWORD EngineClientAnarchy::N3Msg_GetBuffCurrentTime(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetBuffCurrentTime);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetBuffTotalTime_x
	FUNCTION_AT_ADDRESS(DWORD EngineClientAnarchy::N3Msg_GetBuffTotalTime(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetBuffTotalTime);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetCharacterBodyShape_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_GetCharacterBodyShape(BYTE &, identity_t), n3EngineClientAnarchy_t__N3Msg_GetCharacterBodyShape);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetCharOrientationData_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_GetCharOrientationData(const identity_t &, vector3_t &, quaternion_t &, float &), n3EngineClientAnarchy_t__N3Msg_GetCharOrientationData);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetCityNameForClanMember_x
	FUNCTION_AT_ADDRESS(PCSTR EngineClientAnarchy::N3Msg_GetCityNameForClanMember(const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetCityNameForClanMember);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetClanLevelString_x
	FUNCTION_AT_ADDRESS(PCSTR EngineClientAnarchy::N3Msg_GetClanLevelString(const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetClanLevelString);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetClanString_x
	FUNCTION_AT_ADDRESS(std::string* EngineClientAnarchy::N3Msg_GetClanString(const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetClanString);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetClientPetID_x
	FUNCTION_AT_ADDRESS(p_identity_t EngineClientAnarchy::N3Msg_GetClientPetID(identity_t &, DWORD), n3EngineClientAnarchy_t__N3Msg_GetClientPetID);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetCloseTarget_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_GetCloseTarget(identity_t &, bool, bool), n3EngineClientAnarchy_t__N3Msg_GetCloseTarget);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetContainerInventoryList_x
	FUNCTION_AT_ADDRESS(PVOID EngineClientAnarchy::N3Msg_GetContainerInventoryList(const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetContainerInventoryList);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetCorrectActionID_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_GetCorrectActionID(identity_t &), n3EngineClientAnarchy_t__N3Msg_GetCorrectActionID);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetCurrentRoom_x
	FUNCTION_AT_ADDRESS(LONG EngineClientAnarchy::N3Msg_GetCurrentRoom(void), n3EngineClientAnarchy_t__N3Msg_GetCurrentRoom);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetCurrentRoomName_x
	FUNCTION_AT_ADDRESS(PCSTR EngineClientAnarchy::N3Msg_GetCurrentRoomName(void), n3EngineClientAnarchy_t__N3Msg_GetCurrentRoomName);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetDistrictFightMode_x
	FUNCTION_AT_ADDRESS(DWORD EngineClientAnarchy::N3Msg_GetDistrictFightMode(void), n3EngineClientAnarchy_t__N3Msg_GetDistrictFightMode);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetFactionInfoString_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_GetFactionInfoString(const identity_t &, std::string &), n3EngineClientAnarchy_t__N3Msg_GetFactionInfoString);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetFactionRange_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_GetFactionRange(DWORD, DWORD &, DWORD &), n3EngineClientAnarchy_t__N3Msg_GetFactionRange);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetFirstName_x
	FUNCTION_AT_ADDRESS(PCSTR EngineClientAnarchy::N3Msg_GetFirstName(const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetFirstName);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetFormulaProgress_x
	FUNCTION_AT_ADDRESS(double EngineClientAnarchy::N3Msg_GetFormulaProgress(const identity_t &, DWORD &, DWORD &), n3EngineClientAnarchy_t__N3Msg_GetFormulaProgress);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetFormulaRadius_x
	FUNCTION_AT_ADDRESS(DWORD EngineClientAnarchy::N3Msg_GetFormulaRadius(const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetFormulaRadius);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetGlobalCharacterPosition_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_GetGlobalCharacterPosition(vector3_t &), n3EngineClientAnarchy_t__N3Msg_GetGlobalCharacterPosition);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetGlobalCharacterRotation_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_GetGlobalCharacterRotation(quaternion_t &), n3EngineClientAnarchy_t__N3Msg_GetGlobalCharacterRotation);
#endif

#ifdef  n3EngineClientAnarchy_t__N3Msg_GetGridDestinationList_2_x
	FUNCTION_AT_ADDRESS(PVOID EngineClientAnarchy::N3Msg_GetGridDestinationList(void), n3EngineClientAnarchy_t__N3Msg_GetGridDestinationList_2);
#endif

	PVOID EngineClientAnarchy::N3Msg_GetGridDestinationList(void) const
	{
		return n3_engine_client_anarchy_.p_grid_destination_list;
	}

#ifdef n3EngineClientAnarchy_t__N3Msg_GetInventoryVec_x
	FUNCTION_AT_ADDRESS(std::vector<p_inventory_data_t>* EngineClientAnarchy::N3Msg_GetInventoryVec(const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetInventoryVec);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetItem_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_GetItem(const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetItemProgress_x
	FUNCTION_AT_ADDRESS(double EngineClientAnarchy::N3Msg_GetItemProgress(const identity_t &, DWORD &, DWORD &), n3EngineClientAnarchy_t__N3Msg_GetItemProgress);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetMovementMode_x
	FUNCTION_AT_ADDRESS(DWORD EngineClientAnarchy::N3Msg_GetMovementMode(void), n3EngineClientAnarchy_t__N3Msg_GetMovementMode);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetName_x
	FUNCTION_AT_ADDRESS(PCSTR EngineClientAnarchy::N3Msg_GetName(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetName);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetNanoCostModifier_x
	FUNCTION_AT_ADDRESS(DWORD EngineClientAnarchy::N3Msg_GetNanoCostModifier(void), n3EngineClientAnarchy_t__N3Msg_GetNanoCostModifier);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetNanoSpellList_x
	FUNCTION_AT_ADDRESS(PVOID EngineClientAnarchy::N3Msg_GetNanoSpellList(void), n3EngineClientAnarchy_t__N3Msg_GetNanoSpellList);
#endif

	std::list<DWORD>* EngineClientAnarchy::N3Msg_GetNanoSpellList() const
	{
		return &n3_engine_client_anarchy_.p_client_control_char->pSpellTemplateData->SpellList;
	}

#ifdef n3EngineClientAnarchy_t__N3Msg_GetNanoTemplateInfoList_1_x
	FUNCTION_AT_ADDRESS(std::list<NANOTEMPLATE>* EngineClientAnarchy::N3Msg_GetNanoTemplateInfoList(const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetNanoTemplateInfoList_1);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetNanoTemplateInfoList_2_x
	FUNCTION_AT_ADDRESS(PVOID EngineClientAnarchy::N3Msg_GetNanoTemplateInfoList(void), n3EngineClientAnarchy_t__N3Msg_GetNanoTemplateInfoList_2);
#endif

	std::list<NANOTEMPLATE>* EngineClientAnarchy::N3Msg_GetNanoTemplateInfoList(void) const
	{
		return &n3_engine_client_anarchy_.p_client_control_char->pSpellTemplateData->NanoTemplateList;
	}

#ifdef n3EngineClientAnarchy_t__N3Msg_GetNextTarget_x
	FUNCTION_AT_ADDRESS(p_identity_t EngineClientAnarchy::N3Msg_GetNextTarget(identity_t &, DWORD), n3EngineClientAnarchy_t__N3Msg_GetNextTarget);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetNumberOfAvailableAlienPerks_x
	FUNCTION_AT_ADDRESS(DWORD EngineClientAnarchy::N3Msg_GetNumberOfAvailableAlienPerks(void), n3EngineClientAnarchy_t__N3Msg_GetNumberOfAvailableAlienPerks);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetNumberOfAvailablePerks_x
	FUNCTION_AT_ADDRESS(DWORD EngineClientAnarchy::N3Msg_GetNumberOfAvailablePerks(void), n3EngineClientAnarchy_t__N3Msg_GetNumberOfAvailablePerks);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetNumberOfFreeInventorySlots_x
	FUNCTION_AT_ADDRESS(DWORD EngineClientAnarchy::N3Msg_GetNumberOfFreeInventorySlots(void), n3EngineClientAnarchy_t__N3Msg_GetNumberOfFreeInventorySlots);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetNumberOfUsedAlienPerks_x
	FUNCTION_AT_ADDRESS(DWORD EngineClientAnarchy::N3Msg_GetNumberOfUsedAlienPerks(void), n3EngineClientAnarchy_t__N3Msg_GetNumberOfUsedAlienPerks);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetNumberOfUsedPerks_x
	FUNCTION_AT_ADDRESS(DWORD EngineClientAnarchy::N3Msg_GetNumberOfUsedPerks(void), n3EngineClientAnarchy_t__N3Msg_GetNumberOfUsedPerks);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetOverEquipLevel_x
	FUNCTION_AT_ADDRESS(DWORD EngineClientAnarchy::N3Msg_GetOverEquipLevel(const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetOverEquipLevel);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetPFName_1_x
	FUNCTION_AT_ADDRESS(PCSTR EngineClientAnarchy::N3Msg_GetPFName(DWORD), n3EngineClientAnarchy_t__N3Msg_GetPFName_1);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetPFName_2_x
	FUNCTION_AT_ADDRESS(PCSTR EngineClientAnarchy::N3Msg_GetPFName(void), n3EngineClientAnarchy_t__N3Msg_GetPFName_2);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetParent_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_GetParent(const identity_t &, identity_t &), n3EngineClientAnarchy_t__N3Msg_GetParent);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetPos_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_GetPos(const identity_t &, vector3_t &), n3EngineClientAnarchy_t__N3Msg_GetPos);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetSkill_1_x
	FUNCTION_AT_ADDRESS(LONG EngineClientAnarchy::N3Msg_GetSkill(DWORD, DWORD), n3EngineClientAnarchy_t__N3Msg_GetSkill_1);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetSkill_2_x
	FUNCTION_AT_ADDRESS(LONG EngineClientAnarchy::N3Msg_GetSkill(const identity_t &, DWORD, DWORD, const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetSkill_2);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetSkillMax_x
	FUNCTION_AT_ADDRESS(LONG EngineClientAnarchy::N3Msg_GetSkillMax(DWORD), n3EngineClientAnarchy_t__N3Msg_GetSkillMax);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetSpecialActionList_x
	FUNCTION_AT_ADDRESS(PVOID EngineClientAnarchy::N3Msg_GetSpecialActionList(void), n3EngineClientAnarchy_t__N3Msg_GetSpecialActionList);
#endif

	std::list<SPECIALACTION>* EngineClientAnarchy::N3Msg_GetSpecialActionList() const
	{
		return n3_engine_client_anarchy_.p_client_control_char->pSpecialActionHolder->pSpecialActionsList;
	}

#ifdef n3EngineClientAnarchy_t__N3Msg_GetSpecialActionState_x
	FUNCTION_AT_ADDRESS(DWORD EngineClientAnarchy::N3Msg_GetSpecialActionState(const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetSpecialActionState);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetSpecialAttackWeaponName_x
	FUNCTION_AT_ADDRESS(PCSTR EngineClientAnarchy::N3Msg_GetSpecialAttackWeaponName(const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetSpecialAttackWeaponName);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetTargetTarget_x
	FUNCTION_AT_ADDRESS(p_identity_t EngineClientAnarchy::N3Msg_GetTargetTarget(identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_GetTargetTarget);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_GetTeamMemberList_x
	FUNCTION_AT_ADDRESS(PVOID EngineClientAnarchy::N3Msg_GetTeamMemberList(LONG), n3EngineClientAnarchy_t__N3Msg_GetTeamMemberList);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_HasPerk_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_HasPerk(DWORD), n3EngineClientAnarchy_t__N3Msg_HasPerk);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsAttacking_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsAttacking(void), n3EngineClientAnarchy_t__N3Msg_IsAttacking);
#endif

	bool EngineClientAnarchy::N3Msg_IsAttacking(void) const
	{
		return n3_engine_client_anarchy_.p_client_control_char->pWeaponHolder->IsAttacking == 1;
	}

#ifdef n3EngineClientAnarchy_t__N3Msg_IsBattleStation_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsBattleStation(void), n3EngineClientAnarchy_t__N3Msg_IsBattleStation);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsCharacterInMech_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsCharacterInMech(identity_t), n3EngineClientAnarchy_t__N3Msg_IsCharacterInMech);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsCharacterMorphed_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsCharacterMorphed(identity_t), n3EngineClientAnarchy_t__N3Msg_IsCharacterMorphed);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsDungeon_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsDungeon(void), n3EngineClientAnarchy_t__N3Msg_IsDungeon);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsFormulaReady_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsFormulaReady(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsFormulaReady);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsGeneralPerk_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsGeneralPerk(DWORD), n3EngineClientAnarchy_t__N3Msg_IsGeneralPerk);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsGroupPerk_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsGroupPerk(DWORD), n3EngineClientAnarchy_t__N3Msg_IsGroupPerk);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsInRaidTeam_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsInRaidTeam(void), n3EngineClientAnarchy_t__N3Msg_IsInRaidTeam);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsInTeam_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsInTeam(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsInTeam);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsItemDisabled_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsItemDisabled(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsItemDisabled);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsItemMine_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsItemMine(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsItemMine);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsItemNFCrystal_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsItemNFCrystal(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsItemNFCrystal);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToUnWear_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsItemPossibleToUnWear(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToUnWear);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToWear_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsItemPossibleToWear(const identity_t &, DWORD, DWORD, bool, DWORD), n3EngineClientAnarchy_t__N3Msg_IsItemPossibleToWear);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsMoving_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsMoving(void), n3EngineClientAnarchy_t__N3Msg_IsMoving);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsMyPetID_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsMyPetID(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsMyPetID);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsNanoSelfOnly_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsNanoSelfOnly(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsNanoSelfOnly);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsNpc_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsNpc(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsNpc);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsPerk_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsPerk(DWORD), n3EngineClientAnarchy_t__N3Msg_IsPerk);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsPetTower_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsPetTower(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsPetTower);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsProfessionPerk_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsProfessionPerk(DWORD), n3EngineClientAnarchy_t__N3Msg_IsProfessionPerk);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsResearch_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsResearch(DWORD), n3EngineClientAnarchy_t__N3Msg_IsResearch);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsSecondarySpecialAttackAvailable_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsSecondarySpecialAttackAvailable(DWORD), n3EngineClientAnarchy_t__N3Msg_IsSecondarySpecialAttackAvailable);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsShieldDisablerItem_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsShieldDisablerItem(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsShieldDisablerItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsSpecialPerk_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsSpecialPerk(DWORD), n3EngineClientAnarchy_t__N3Msg_IsSpecialPerk);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsTeamLeader_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsTeamLeader(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsTeamLeader);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsTeamMission_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsTeamMission(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsTeamMission);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsTeamMissionCopy_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsTeamMissionCopy(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsTeamMissionCopy);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsTeamNano_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsTeamNano(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsTeamNano);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsTower_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsTower(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsTower);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_IsVisible_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_IsVisible(const identity_t &), n3EngineClientAnarchy_t__N3Msg_IsVisible);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_JoinItems_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_JoinItems(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_JoinItems);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_KickTeamMember_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_KickTeamMember(const identity_t &), n3EngineClientAnarchy_t__N3Msg_KickTeamMember);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_LeaveBattle_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_LeaveBattle(void), n3EngineClientAnarchy_t__N3Msg_LeaveBattle);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_LeaveTeam_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_LeaveTeam(void), n3EngineClientAnarchy_t__N3Msg_LeaveTeam);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_MeetsPerkCriteria_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_MeetsPerkCriteria(DWORD), n3EngineClientAnarchy_t__N3Msg_MeetsPerkCriteria);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_MoveItemToInventory_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_MoveItemToInventory(const identity_t &, DWORD, DWORD), n3EngineClientAnarchy_t__N3Msg_MoveItemToInventory);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_MoveRaidMember_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_MoveRaidMember(const identity_t &, DWORD), n3EngineClientAnarchy_t__N3Msg_MoveRaidMember);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_NameToID_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_NameToID(const std::string &, identity_t &), n3EngineClientAnarchy_t__N3Msg_NameToID);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatAddTradeItem_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_NPCChatAddTradeItem(const identity_t &, const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_NPCChatAddTradeItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatCloseWindow_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_NPCChatCloseWindow(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_NPCChatCloseWindow);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatEndTrade_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_NPCChatEndTrade(const identity_t &, const identity_t &, DWORD, bool), n3EngineClientAnarchy_t__N3Msg_NPCChatEndTrade);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatRemoveTradeItem_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_NPCChatRemoveTradeItem(const identity_t &, const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_NPCChatRemoveTradeItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatRequestDescription_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_NPCChatRequestDescription(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_NPCChatRequestDescription);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_NPCChatStartTrade_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_NPCChatStartTrade(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_NPCChatStartTrade);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_OrbitalAttack_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_OrbitalAttack(const identity_t &), n3EngineClientAnarchy_t__N3Msg_OrbitalAttack);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_1_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_PerformSpecialAction(DWORD), n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_1);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_2_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_PerformSpecialAction(const identity_t &), n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_2);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_PetDuel_Accept_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_PetDuel_Accept(void), n3EngineClientAnarchy_t__N3Msg_PetDuel_Accept);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_PetDuel_Challenge_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_PetDuel_Challenge(const identity_t &), n3EngineClientAnarchy_t__N3Msg_PetDuel_Challenge);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_PetDuel_Refuse_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_PetDuel_Refuse(void), n3EngineClientAnarchy_t__N3Msg_PetDuel_Refuse);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_PetDuel_Stop_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_PetDuel_Stop(void), n3EngineClientAnarchy_t__N3Msg_PetDuel_Stop);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_RemoveBuff_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_RemoveBuff(const identity_t &), n3EngineClientAnarchy_t__N3Msg_RemoveBuff);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_RemoveQuest_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_RemoveQuest(const identity_t &), n3EngineClientAnarchy_t__N3Msg_RemoveQuest);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_RequestCharacterInventory_x
	FUNCTION_AT_ADDRESS(std::list<INVENTORYENTRY>* EngineClientAnarchy::N3Msg_RequestCharacterInventory(void), n3EngineClientAnarchy_t__N3Msg_RequestCharacterInventory);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_RequestClothInventory_x
	FUNCTION_AT_ADDRESS(std::list<INVENTORYENTRY>* EngineClientAnarchy::N3Msg_RequestClothInventory(const identity_t &), n3EngineClientAnarchy_t__N3Msg_RequestClothInventory);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_RequestImplantInventory_x
	FUNCTION_AT_ADDRESS(std::list<INVENTORYENTRY>* EngineClientAnarchy::N3Msg_RequestImplantInventory(const identity_t &), n3EngineClientAnarchy_t__N3Msg_RequestImplantInventory);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_RequestSocialInventory_x
	FUNCTION_AT_ADDRESS(std::list<INVENTORYENTRY>* EngineClientAnarchy::N3Msg_RequestSocialInventory(const identity_t &), n3EngineClientAnarchy_t__N3Msg_RequestSocialInventory);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_RequestWeaponInventory_x
	FUNCTION_AT_ADDRESS(std::list<INVENTORYENTRY>* EngineClientAnarchy::N3Msg_RequestWeaponInventory(const identity_t &), n3EngineClientAnarchy_t__N3Msg_RequestWeaponInventory);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_SecondarySpecialAttack_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_SecondarySpecialAttack(const identity_t &, DWORD), n3EngineClientAnarchy_t__N3Msg_SecondarySpecialAttack);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_SelectedTarget_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_SelectedTarget(const identity_t&), n3EngineClientAnarchy_t__N3Msg_SelectedTarget);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_SendPetCommand_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_SendPetCommand(DWORD, const identity_t &, DWORD, DWORD, PCSTR), n3EngineClientAnarchy_t__N3Msg_SendPetCommand);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_SitToggle_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_SitToggle(void), n3EngineClientAnarchy_t__N3Msg_SitToggle);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_SplitItem_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_SplitItem(const identity_t &, DWORD), n3EngineClientAnarchy_t__N3Msg_SplitItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_StartAltState_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_StartAltState(void), n3EngineClientAnarchy_t__N3Msg_StartAltState);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_StartCamping_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_StartCamping(void), n3EngineClientAnarchy_t__N3Msg_StartCamping);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_StartPvP_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_StartPvP(const identity_t &), n3EngineClientAnarchy_t__N3Msg_StartPvP);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_StartTreatment_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_StartTreatment(const identity_t &), n3EngineClientAnarchy_t__N3Msg_StartTreatment);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_StopAltState_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_StopAltState(void), n3EngineClientAnarchy_t__N3Msg_StopAltState);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_StopAttack_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_StopAttack(void), n3EngineClientAnarchy_t__N3Msg_StopAttack);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_StopCamping_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_StopCamping(void), n3EngineClientAnarchy_t__N3Msg_StopCamping);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_StringToStat_x
	FUNCTION_AT_ADDRESS(DWORD EngineClientAnarchy::N3Msg_StringToStat(PCSTR), n3EngineClientAnarchy_t__N3Msg_StringToStat);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_SwitchTarget_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_SwitchTarget(const identity_t &), n3EngineClientAnarchy_t__N3Msg_SwitchTarget);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TeamJoinRequest_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_TeamJoinRequest(const identity_t &, bool), n3EngineClientAnarchy_t__N3Msg_TeamJoinRequest);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TemplateIDToDynelID_x
	FUNCTION_AT_ADDRESS(p_identity_t EngineClientAnarchy::N3Msg_TemplateIDToDynelID(identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_TemplateIDToDynelID);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TextCommand_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_TextCommand(DWORD, PCSTR, const identity_t &), n3EngineClientAnarchy_t__N3Msg_TextCommand);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_ToggleReclaim_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_ToggleReclaim(bool), n3EngineClientAnarchy_t__N3Msg_ToggleReclaim);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeAbort_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_TradeAbort(bool), n3EngineClientAnarchy_t__N3Msg_TradeAbort);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeAccept_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_TradeAccept(void), n3EngineClientAnarchy_t__N3Msg_TradeAccept);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeAddItem_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_TradeAddItem(const identity_t &, const identity_t &, DWORD), n3EngineClientAnarchy_t__N3Msg_TradeAddItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeConfirm_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_TradeConfirm(void), n3EngineClientAnarchy_t__N3Msg_TradeConfirm);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeGetInventory_x
	FUNCTION_AT_ADDRESS(PVOID EngineClientAnarchy::N3Msg_TradeGetInventory(const identity_t &), n3EngineClientAnarchy_t__N3Msg_TradeGetInventory);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeGetInventoryCost_x
	FUNCTION_AT_ADDRESS(DWORD EngineClientAnarchy::N3Msg_TradeGetInventoryCost(const identity_t &), n3EngineClientAnarchy_t__N3Msg_TradeGetInventoryCost);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeRemoveItem_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_TradeRemoveItem(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_TradeRemoveItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeSetCash_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_TradeSetCash(DWORD), n3EngineClientAnarchy_t__N3Msg_TradeSetCash);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeStart_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_TradeStart(const identity_t &), n3EngineClientAnarchy_t__N3Msg_TradeStart);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TradeskillCombine_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_TradeskillCombine(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_TradeskillCombine);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TrainPerk_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_TrainPerk(DWORD), n3EngineClientAnarchy_t__N3Msg_TrainPerk);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TransferTeamLeadership_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_TransferTeamLeadership(const identity_t &), n3EngineClientAnarchy_t__N3Msg_TransferTeamLeadership);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TryAbortNanoFormula_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_TryAbortNanoFormula(void), n3EngineClientAnarchy_t__N3Msg_TryAbortNanoFormula);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_TryEnterSneakMode_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_TryEnterSneakMode(void), n3EngineClientAnarchy_t__N3Msg_TryEnterSneakMode);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_UntrainPerk_x
	FUNCTION_AT_ADDRESS(bool EngineClientAnarchy::N3Msg_UntrainPerk(DWORD), n3EngineClientAnarchy_t__N3Msg_UntrainPerk);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_UseItem_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_UseItem(const identity_t&, bool), n3EngineClientAnarchy_t__N3Msg_UseItem);
#endif

#ifdef n3EngineClientAnarchy_t__N3Msg_UseItemOnItem_x
	FUNCTION_AT_ADDRESS(void EngineClientAnarchy::N3Msg_UseItemOnItem(const identity_t &, const identity_t &), n3EngineClientAnarchy_t__N3Msg_UseItemOnItem);
#endif


}
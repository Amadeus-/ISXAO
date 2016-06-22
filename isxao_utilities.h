#pragma once

namespace isxao_utilities
{
	
#pragma region Strings

	AOLIB_API PCSTR __cdecl GetBreedStr(DWORD);
	AOLIB_API PCSTR GetProfessionStr(DWORD);
	AOLIB_API PCSTR __cdecl GetSexStr(DWORD);
	AOLIB_API PCSTR GetSideStr(DWORD);
	AOLIB_API PCSTR GetStatName(DWORD);
	AOLIB_API PCSTR GetNanoSchoolStr(DWORD);
	AOLIB_API PCSTR __cdecl StatToString(DWORD);
	AOLIB_API PCSTR GetItemRarityStr(DWORD);

#pragma endregion

#pragma region Objects

	AOLIB_API DWORD __cdecl GetFullPerkMap(void);
	AOLIB_API Dynel* __cdecl GetDynel(const IDENTITY &);
	AOLIB_API Actor* __cdecl GetActor(const IDENTITY &);
	AOLIB_API PNANOITEM __cdecl GetNanoItem(DWORD);

	AOLIB_API bool IsValidDynel(PN3DYNEL);

	AOLIB_API PVOID RequestInfo(const IDENTITY &);

#pragma endregion

#pragma region SearchDynel

	AOLIB_API void ClearSearchActor(PSEARCHACTOR);
	AOLIB_API Actor* NthNearestActor(PSEARCHACTOR p_search_actor, DWORD nth, Actor* p_origin, bool include_origin = false);
	AOLIB_API DWORD CountMatchingActors(PSEARCHACTOR p_search_actor, Actor* p_character, bool include_char = false);
	AOLIB_API bool ActorMatchesSearch(PSEARCHACTOR p_search_actor, Actor* p_character, Actor* p_actor);
	AOLIB_API DWORD ParseSearchActorArg(int arg, int argc, char *argv[], SEARCHACTOR &search_actor);
	AOLIB_API void ParseSearchActor(int begin_inclusive, int end_exclusive, char *argv[], SEARCHACTOR &search_actor);
	AOLIB_API bool IsPCNear(Actor* p_actor, float radius);

#pragma endregion

#pragma region Collections

	void RecursiveAddDynelToDynelMap(std::map<IDENTITY, PN3DYNEL>& m, PDYNELNODE pNode, PDYNELROOT pRoot, DWORD& count);
	void GetDynelMap(std::map<IDENTITY, PN3DYNEL>& m);
	void RecursiveAddPerkToPerkMap(std::map<IDENTITY, DWORD>& m, PPERKNODE pNode, PPERKROOT pRoot, DWORD& count);
	void GetPerkMap(std::map<IDENTITY, DWORD>& m, PPERKDIR pDir);
	void RecursiveAddPetToPetMap(std::map<IDENTITY, DWORD>& m, PPETNODE pNode, PPETROOT pRoot, DWORD& count);
	void GetPetMap(std::map<IDENTITY, DWORD>& m, PPETDIR pPetDir);
	void RecursiveAddNanoToNanoMap(std::map<DWORD, PNANOITEM>& m, PNANOITEMNODE pNode, PNANOITEMROOT pRoot, DWORD& count);
	void GetNanoMap(std::map<DWORD, PNANOITEM>& m);
	void RecursiveAddStatNameToStatNameMap(std::map<DWORD, PCSTR>& m, PSTATNAMENODE pNode, PSTATNAMEROOT pRoot, DWORD& count);
	void GetStatNameMap(std::map<DWORD, PCSTR>& m);
	void GetStaticItemMap(std::map<IDENTITY, PDUMMYITEMBASE>& m);
	void RecursiveAddStatToStatMap(std::map<DWORD, LONG>& m, PSTATNODE pNode, PSTATROOT pRoot, DWORD& count);
	void GetStatMap(std::map<DWORD, LONG>& m, PSTATDIR pDir);
	void RecursiveAddWeaponItemToWeaponItemMap(std::map<DWORD, PWEAPONITEM>& m, PWEAPONITEMNODE pNode, PWEAPONITEMROOT pRoot, DWORD& count);
	void GetWeaponItemMap(std::map<DWORD, PWEAPONITEM>& m, WEAPONITEMDIR& dir);
	void RecursiveAddChatWindowNodeToChatWindowNodeMap(std::map<string, ChatWindowNode*>& m, PCHATWINDOWNODENODE pNode, PCHATWINDOWNODEROOT pRoot, DWORD& count);
	void GetChatWindowNodeMap(std::map<string, ChatWindowNode*>& m, CHATWINDOWNODEDIR &dir);
	void RecursiveAddLockIdToLockIdMap(std::map<DWORD, DWORD>& m, PLOCKIDNODE pNode, PLOCKIDROOT pRoot, DWORD& count);
	void GetLockIdMap(std::map<DWORD, DWORD>& m, PLOCKIDDIR pDir);

#pragma endregion

#pragma region Inventory

	bool GetInvSlotIdentity(AOData::ArmorSlot_e slot, IDENTITY& id);
	bool GetInvSlotIdentity(AOData::ImplantSlot_e slot, IDENTITY& id);
	bool GetInvSlotIdentity(AOData::WeaponSlot_e slot, IDENTITY& id);
	bool GetInvSlotIdentity(DWORD slot, IDENTITY& id);
	PCSTR GetInvSlotName(const IDENTITY& slot);
	bool GetInvSlotIdentity(PCSTR slot_name, IDENTITY &id);

#pragma endregion

#pragma region Lavishscript

	AOLIB_API LSTypeDefinition* GetRealType(Dynel* pObject);

#pragma endregion

#pragma region Utility

	DWORD GetGameState();
	void PrintToChat(string message, PCSTR chat_type);

#pragma endregion

#pragma region Message Handling

	void HandleN3Message(PN3MESSAGEINFO message_info);
	void HandleAddPetMessage(AddPetMessage);
	void HandleAttackMessage(AttackMessage);
	void HandleCastNanoSpellMessage(CastNanoSpellMessage);
	void HandleCharacterActionMessage(CharacterActionMessage);
	void HandleFollowTargetMessage(FollowTargetMessage);
	void HandleRemovePetMessage(RemovePetMessage);
	void HandleShieldAttackMessage(ShieldAttackMessage);

	void HandleGroupMessage(PGROUPMESSAGEINFO);

	void HandlePrivateMessage(PPRIVATEMESSAGEINFO);

	void HandleVicinityMessage(PPRIVATEMESSAGEINFO);

	void HandleSystemChat(PSYSTEMCHATINFO);

#pragma endregion


}

using namespace isxao_utilities;
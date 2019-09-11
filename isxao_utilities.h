#pragma once

namespace isxao_utilities
{
	
#pragma region Strings
	AOLIB_API PCSTR stat_to_string(stat_e stat_id);
	AOLIB_API PCSTR get_breed_str_local(breed_e);
	AOLIB_API PCSTR get_sex_str_local(gender_e);
	AOLIB_API PCSTR GetProfessionStr(DWORD);
	AOLIB_API PCSTR GetSideStr(DWORD);
	AOLIB_API PCSTR GetNanoSchoolStr(DWORD);
	AOLIB_API PCSTR GetItemRarityStr(DWORD);

#pragma endregion

#pragma region Objects

	AOLIB_API DWORD __cdecl GetFullPerkMap(void);
	AOLIB_API dynel* __cdecl GetDynel(const identity_t &);
	AOLIB_API actor* __cdecl GetActor(const identity_t &);
	AOLIB_API p_nano_item_t get_nano_item(DWORD);

	AOLIB_API bool IsValidDynel(p_n3_dynel_t);

	AOLIB_API PVOID RequestInfo(const identity_t &);

#pragma endregion

#pragma region SearchDynel

	AOLIB_API void ClearSearchActor(PSEARCHACTOR);
	AOLIB_API actor* NthNearestActor(PSEARCHACTOR p_search_actor, DWORD nth, actor* p_origin, bool include_origin = false);
	AOLIB_API DWORD CountMatchingActors(PSEARCHACTOR p_search_actor, actor* p_character, bool include_char = false);
	AOLIB_API bool ActorMatchesSearch(PSEARCHACTOR p_search_actor, actor* p_character, actor* p_actor);
	AOLIB_API DWORD ParseSearchActorArg(int arg, int argc, char *argv[], SEARCHACTOR &search_actor);
	AOLIB_API void ParseSearchActor(int begin_inclusive, int end_exclusive, char *argv[], SEARCHACTOR &search_actor);
	AOLIB_API bool IsPCNear(actor* p_actor, float radius);

#pragma endregion

#pragma region Collections

	AOLIB_API void recursive_add_dynel_to_dynel_map(std::map<identity_t, p_n3_dynel_t>& m, p_dynel_node_t p_node, p_dynel_root_t p_root, DWORD& count);
	AOLIB_API void get_dynel_map(std::map<identity_t, p_n3_dynel_t>& m);
	AOLIB_API void RecursiveAddPerkToPerkMap(std::map<identity_t, DWORD>& m, p_perk_node_t pNode, p_perk_root_t pRoot, DWORD& count);
	AOLIB_API void GetPerkMap(std::map<identity_t, DWORD>& m, p_perk_dir_t pDir);
	AOLIB_API void RecursiveAddPetToPetMap(std::map<identity_t, DWORD>& m, p_pet_node_t pNode, p_pet_root_t pRoot, DWORD& count);
	AOLIB_API void GetPetMap(std::map<identity_t, DWORD>& m, p_pet_dir_t pPetDir);
	AOLIB_API void get_nano_map(std::map<DWORD, p_nano_item_t>& m);
	AOLIB_API void get_stat_name_map(map<stat_e, PCSTR>& m);
	AOLIB_API void GetStaticItemMap(std::map<identity_t, p_dummy_item_base_t>& m);
	AOLIB_API void RecursiveAddStatToStatMap(std::map<DWORD, LONG>& m, p_stat_node_t pNode, p_stat_root_t pRoot, DWORD& count);
	AOLIB_API void GetStatMap(std::map<DWORD, LONG>& m, p_stat_dir_t pDir);
	AOLIB_API void RecursiveAddWeaponItemToWeaponItemMap(std::map<DWORD, p_weapon_item_t>& m, p_weapon_item_node_t pNode, p_weapon_item_root_t pRoot, DWORD& count);
	AOLIB_API void GetWeaponItemMap(std::map<DWORD, p_weapon_item_t>& m, weapon_item_dir_t& dir);
	AOLIB_API void RecursiveAddChatWindowNodeToChatWindowNodeMap(std::map<string, ChatWindowNode*>& m, p_chat_window_node_node_t pNode, p_chat_window_node_root_t pRoot, DWORD& count);
	AOLIB_API void GetChatWindowNodeMap(std::map<string, ChatWindowNode*>& m, chat_window_node_dir_t &dir);
	AOLIB_API void RecursiveAddLockIdToLockIdMap(std::map<DWORD, DWORD>& m, p_lock_id_node_t pNode, p_lock_id_root_t pRoot, DWORD& count);
	AOLIB_API void GetLockIdMap(std::map<DWORD, DWORD>& m, p_lock_id_dir_t pDir);

#pragma endregion

#pragma region Inventory

	bool GetInvSlotIdentity(ao_data::ArmorSlot_e slot, identity_t& id);
	bool GetInvSlotIdentity(ao_data::ImplantSlot_e slot, identity_t& id);
	bool GetInvSlotIdentity(ao_data::WeaponSlot_e slot, identity_t& id);
	bool GetInvSlotIdentity(DWORD slot, identity_t& id);
	PCSTR GetInvSlotName(const identity_t& slot);
	bool GetInvSlotIdentity(PCSTR slot_name, identity_t &id);
	p_inventory_data_t GetInvSlotData(INVENTORYSLOT *slot);

#pragma endregion

#pragma region Lavishscript

	AOLIB_API LSTypeDefinition* GetRealType(dynel* pObject);

#pragma endregion

#pragma region Utility

	AOLIB_API DWORD GetGameState();
	AOLIB_API void PrintToChat(string message, PCSTR chat_type);

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
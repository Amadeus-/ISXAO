#pragma once

namespace isxao_utilities
{
	
#pragma region Strings
	AOLIB_API PCSTR stat_to_string(ao::stat_e stat_id);
	AOLIB_API PCSTR get_breed_str_local(ao::breed_e);
	AOLIB_API PCSTR get_sex_str_local(ao::gender_e);
	AOLIB_API PCSTR get_profession_str(DWORD);
	AOLIB_API PCSTR get_side_str(DWORD);
	AOLIB_API PCSTR get_nano_school_str(DWORD);
	AOLIB_API PCSTR get_item_rarity_str(DWORD);

#pragma endregion

#pragma region Objects

	AOLIB_API bool IsValidDynel(ao::p_n3_dynel_t);

#pragma endregion

#pragma region SearchDynel

	AOLIB_API void ClearSearchActor(PSEARCHACTOR);
	AOLIB_API ao::actor* NthNearestActor(PSEARCHACTOR p_search_actor, DWORD nth, ao::actor* p_origin, bool include_origin = false);
	AOLIB_API DWORD CountMatchingActors(PSEARCHACTOR p_search_actor, ao::actor* p_character, bool include_char = false);
	AOLIB_API bool ActorMatchesSearch(PSEARCHACTOR p_search_actor, ao::actor* p_character, ao::actor* p_actor);
	AOLIB_API DWORD ParseSearchActorArg(int arg, int argc, char *argv[], SEARCHACTOR &search_actor);
	AOLIB_API void ParseSearchActor(int begin_inclusive, int end_exclusive, char *argv[], SEARCHACTOR &search_actor);
	AOLIB_API bool IsPCNear(ao::actor* p_actor, float radius);

#pragma endregion

#pragma region Collections

	AOLIB_API void RecursiveAddPerkToPerkMap(std::map<ao::identity_t, DWORD>& m, ao::p_perk_node_t pNode, ao::p_perk_root_t pRoot, DWORD& count);
	AOLIB_API void GetPerkMap(std::map<ao::identity_t, DWORD>& m, ao::p_perk_dir_t pDir);
	AOLIB_API void RecursiveAddPetToPetMap(std::map<ao::identity_t, DWORD>& m, ao::p_pet_node_t pNode, ao::p_pet_root_t pRoot, DWORD& count);
	AOLIB_API void GetPetMap(std::map<ao::identity_t, DWORD>& m, ao::p_pet_dir_t pPetDir);
	AOLIB_API void get_nano_map(std::map<DWORD, ao::p_nano_item_t>& m);
	AOLIB_API void get_stat_name_map(std::map<ao::stat_e, PCSTR>& m);
	AOLIB_API void GetStaticItemMap(std::map<ao::identity_t, ao::p_dummy_item_base_t>& m);
	AOLIB_API void RecursiveAddStatToStatMap(std::map<DWORD, LONG>& m, ao::p_stat_node_t pNode, ao::p_stat_root_t pRoot, DWORD& count);
	AOLIB_API void GetStatMap(std::map<DWORD, LONG>& m, ao::p_stat_dir_t pDir);
	AOLIB_API void RecursiveAddWeaponItemToWeaponItemMap(std::map<DWORD, ao::p_weapon_item_t>& m, ao::p_weapon_item_node_t pNode, ao::p_weapon_item_root_t pRoot, DWORD& count);
	AOLIB_API void GetWeaponItemMap(std::map<DWORD, ao::p_weapon_item_t>& m, ao::weapon_item_dir_t& dir);
	AOLIB_API void RecursiveAddChatWindowNodeToChatWindowNodeMap(std::map<string, ao::chat_window_node*>& m, ao::p_chat_window_node_node_t pNode, ao::p_chat_window_node_root_t pRoot, DWORD& count);
	AOLIB_API void GetChatWindowNodeMap(std::map<string, ao::chat_window_node*>& m, ao::chat_window_node_dir_t &dir);
	AOLIB_API void RecursiveAddLockIdToLockIdMap(std::map<DWORD, DWORD>& m, ao::p_lock_id_node_t pNode, ao::p_lock_id_root_t pRoot, DWORD& count);
	AOLIB_API void GetLockIdMap(std::map<DWORD, DWORD>& m, ao::p_lock_id_dir_t pDir);

#pragma endregion

#pragma region Inventory

	bool GetInvSlotIdentity(ao::ArmorSlot_e slot, ao::identity_t& id);
	bool GetInvSlotIdentity(ao::ImplantSlot_e slot, ao::identity_t& id);
	bool GetInvSlotIdentity(ao::WeaponSlot_e slot, ao::identity_t& id);
	bool GetInvSlotIdentity(DWORD slot, ao::identity_t& id);
	PCSTR GetInvSlotName(const ao::identity_t& slot);
	bool GetInvSlotIdentity(PCSTR slot_name, ao::identity_t &id);
	ao::p_inventory_data_t GetInvSlotData(ao::inventory_slot_t *slot);

#pragma endregion

#pragma region Lavishscript

	AOLIB_API LSTypeDefinition* get_real_type(ao::dynel* pObject);

#pragma endregion

#pragma region Utility

	AOLIB_API DWORD get_game_state();
	AOLIB_API void PrintToChat(string message, PCSTR chat_type);
	AOLIB_API void get_arg(char current_arg[MAX_VARSTRING], int argc, char *argv[], DWORD& arg_num);

#pragma endregion

#pragma region Message Handling

	void HandleN3Message(PN3MESSAGEINFO message_info);
	void HandleAddPetMessage(isxao_classes::add_pet_message);
	void HandleAttackMessage(isxao_classes::attack_message);
	void HandleCastNanoSpellMessage(isxao_classes::cast_nano_spell_message);
	void HandleCharacterActionMessage(isxao_classes::character_action_message);
	void HandleFollowTargetMessage(isxao_classes::follow_target_message);
	void HandleRemovePetMessage(isxao_classes::remove_pet_message);
	void HandleShieldAttackMessage(isxao_classes::shield_attack_message);

	void HandleGroupMessage(PGROUPMESSAGEINFO);

	void HandlePrivateMessage(PPRIVATEMESSAGEINFO);

	void HandleVicinityMessage(PPRIVATEMESSAGEINFO);

	void HandleSystemChat(PSYSTEMCHATINFO);

#pragma endregion


}

using namespace isxao_utilities;
#pragma once

namespace isxao
{
	
#pragma region Strings
	//AOLIB_API PCSTR stat_to_string(ao::stat_e stat_id);
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

	AOLIB_API void ClearSearchActor(internal::PSEARCHACTOR);
	AOLIB_API ao::actor* NthNearestActor(internal::PSEARCHACTOR p_search_actor, DWORD nth, ao::actor* p_origin, bool include_origin = false);
	AOLIB_API DWORD CountMatchingActors(internal::PSEARCHACTOR p_search_actor, ao::actor* p_character, bool include_char = false);
	AOLIB_API bool ActorMatchesSearch(internal::PSEARCHACTOR p_search_actor, ao::actor* p_character, ao::actor* p_actor);
	AOLIB_API DWORD ParseSearchActorArg(int arg, int argc, char *argv[], internal::SEARCHACTOR &search_actor);
	AOLIB_API void ParseSearchActor(int begin_inclusive, int end_exclusive, char *argv[], internal::SEARCHACTOR &search_actor);
	AOLIB_API bool IsPCNear(ao::actor* p_actor, float radius);

#pragma endregion

#pragma region Collections

	//AOLIB_API void get_stat_name_map(std::map<ao::stat_e, PCSTR>& m);
	AOLIB_API void get_static_item_map(std::map<ao::identity_t, ao::p_dummy_item_base_t>& m);

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

	void HandleN3Message(internal::PN3MESSAGEINFO message_info);
	void HandleAddPetMessage(add_pet_message);
	void HandleAttackMessage(attack_message);
	void HandleCastNanoSpellMessage(cast_nano_spell_message);
	void HandleCharacterActionMessage(character_action_message);
	void HandleFollowTargetMessage(follow_target_message);
	void HandleRemovePetMessage(remove_pet_message);
	void HandleShieldAttackMessage(shield_attack_message);

	void HandleGroupMessage(internal::PGROUPMESSAGEINFO);

	void HandlePrivateMessage(internal::PPRIVATEMESSAGEINFO);

	void HandleVicinityMessage(internal::PPRIVATEMESSAGEINFO);

	void HandleSystemChat(internal::PSYSTEMCHATINFO);

#pragma endregion


}
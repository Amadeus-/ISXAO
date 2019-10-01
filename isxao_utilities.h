#pragma once
#include "isxao_message_parser.h"

namespace isxao
{	

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


#pragma region Lavishscript

	AOLIB_API LSTypeDefinition* get_real_type(ao::dynel* pObject);

#pragma endregion

#pragma region Utility

	AOLIB_API DWORD get_game_state();
	AOLIB_API void print_to_chat(string message, PCSTR chat_type);
	AOLIB_API void get_arg(char* current_arg, int argc, char *argv[], DWORD& arg_num);

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

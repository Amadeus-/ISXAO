#include "isxao_main.h"

namespace isxao
{

#pragma region n3_engine_client_anarchy_t__set_main_dynel

	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	DETOUR_TRAMPOLINE_EMPTY(void ao_detours::n3_engine_client_t__set_main_dynel__trampoline(ao::dynel*));

	void ao_detours::n3_engine_client_t__set_main_dynel__detour(ao::dynel* p_dynel)
	{
		if (!p_dynel)
			GamestateService(pExtension, GamestateWaitingForCharacter, nullptr);
		n3_engine_client_t__set_main_dynel__trampoline(p_dynel);
		if (p_dynel)
			GamestateService(pExtension, GamestateInGame, nullptr);
	}

#pragma endregion

#pragma region playfield_anarchy_t__playfield_anarchy_t

	// ReSharper disable once CppMemberFunctionMayBeStatic
	DETOUR_TRAMPOLINE_EMPTY(ao::playfield_anarchy* ao_detours::playfield_anarchy_t__playfield_anarchy_t__trampoline(PVOID));

	ao::playfield_anarchy* ao_detours::playfield_anarchy_t__playfield_anarchy_t__detour(PVOID p_playfield_proxy)
	{
		GamestateService(pExtension, GamestateWaitingForCharacter, nullptr);
		return playfield_anarchy_t__playfield_anarchy_t__trampoline(p_playfield_proxy);		
	}

#pragma endregion

#pragma region playfield_anarchy_t__d_playfield_anarchy_t

	// ReSharper disable once CppMemberFunctionMayBeStatic
	DETOUR_TRAMPOLINE_EMPTY(void ao_detours::playfield_anarchy_t__d_playfield_anarchy_t__trampoline());

	void ao_detours::playfield_anarchy_t__d_playfield_anarchy_t__detour()
	{
		GamestateService(pExtension, GamestateWaitingForPlayfield, nullptr);
		playfield_anarchy_t__d_playfield_anarchy_t__trampoline();
	}

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_engine_client_anarchy_t

	// ReSharper disable once CppMemberFunctionMayBeStatic
	DETOUR_TRAMPOLINE_EMPTY(ao::engine_client_anarchy* ao_detours::n3_engine_client_anarchy_t__n3_engine_client_anarchy_t__trampoline());

	PVOID ao_detours::n3_engine_client_anarchy_t__n3_engine_client_anarchy_t__detour()
	{
		GamestateService(pExtension, GamestateWaitingForPlayfield, nullptr);
		return n3_engine_client_anarchy_t__n3_engine_client_anarchy_t__trampoline();
	}

#pragma endregion

#pragma region n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t

	// ReSharper disable once CppMemberFunctionMayBeStatic
	DETOUR_TRAMPOLINE_EMPTY(PVOID ao_detours::n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t__trampoline());

	PVOID ao_detours::n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t__detour()
	{
		GamestateService(pExtension, GamestateNotInGame, nullptr);
		return n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t__trampoline();
	}

#pragma endregion

#pragma region n3_playfield_t__add_child_dynel

	// ReSharper disable once CppMemberFunctionMayBeStatic
	DETOUR_TRAMPOLINE_EMPTY(void ao_detours::n3_playfield_t__add_child_dynel__trampoline(ao::dynel*, const ao::vector3_t&, const ao::quaternion_t&));

	void ao_detours::n3_playfield_t__add_child_dynel__detour(ao::dynel* p_dynel, const ao::vector3_t &position, const ao::quaternion_t &rotation)
	{
		ActorService(pExtension, AddActor, p_dynel);
		n3_playfield_t__add_child_dynel__trampoline(p_dynel, position, rotation);
	}

#pragma endregion

#pragma region n3_dynel_t__set_playfield

	// ReSharper disable once CppMemberFunctionMayBeStatic
	DETOUR_TRAMPOLINE_EMPTY(void ao_detours::n3_dynel_t__set_playfield__trampoline(DWORD))

	void ao_detours::n3_dynel_t__set_playfield__detour(DWORD instance)
	{
		if (instance == 0)
		{
			ao::p_n3_dynel_t p_dynel;
			__asm {mov[p_dynel], ecx};
			ActorService(pExtension, RemoveActor, p_dynel);
		}
		n3_dynel_t__set_playfield__trampoline(instance);
	}

#pragma endregion

#pragma region n3_engine_client_anarchy_t__n3_msg_movement_changed

	// ReSharper disable once CppMemberFunctionMayBeStatic
	DETOUR_TRAMPOLINE_EMPTY(void ao_detours::n3_engine_client_anarchy_t__n3_msg_movement_changed__trampoline(DWORD, float, float, bool))

	void ao_detours::n3_engine_client_anarchy_t__n3_msg_movement_changed__detour(DWORD movement_mode, float unknown_1, float unknown_2, bool unknown_3)
	{
		char move_data[MAX_VARSTRING];
		sprintf_s(move_data, sizeof(move_data), "[Move Data] Movement Mode: %d, Unknown_1: %.4f, Unknown_2: %.4f, Unknown_3: %d", movement_mode, unknown_1, unknown_2, unknown_3);
		gp_isxao_log->add_line(move_data);
		n3_engine_client_anarchy_t__n3_msg_movement_changed__trampoline(movement_mode, unknown_1, unknown_2, unknown_3);
	}

#pragma endregion

#pragma region Client ProcessMessage and Handling

	DETOUR_TRAMPOLINE_EMPTY(DWORD ao_detours::client_t__process_message_trampoline(ao::message*));

	DWORD ao_detours::client_t__process_message_detour(ao::message* p1)
	{
		//if (GetGameState() == GAMESTATE_IN_GAME)
		//{
			//FILE * pFILE;
			//char buffer[MAX_VARSTRING];

			switch (ao::PacketType_e(p1->message_type_get()))
			{
			case ao::PT_SYSTEM_MESSAGE: break;
			case ao::PT_TEXT_MESSAGE:
			{
				break;
			}
			case ao::PT_N3_MESSAGE:
			{
				size_t length = static_cast<ao::n3_message*>(p1)->message_body_len();
				PCHAR message = static_cast<ao::n3_message*>(p1)->message_body_get();
				PVOID export_message = malloc(length);
				memcpy_s(export_message, length, message, length);
				PN3MESSAGEINFO message_info = new N3MESSAGEINFO(export_message, length);
				g_n3message_queue.push(message_info);
				//auto p = isxao_classes::Parser(ao_message, length);
				//N3Header header = N3Header(p);
				//sprintf_s(buffer, "\tN3MessageType: 0x%.8X\n", header.N3Type());
				//pFILE = fopen("messages.txt", "a");
				//fputs(buffer, pFILE);
				//fclose(pFILE);
				//switch (::N3MessageType_e(header.N3Type()))
				//{
				//case ::N3T_ACTION:
				//{
				//	break;
				//}
				//case ::N3T_ADD_PET:
				//{
				//	export_message = malloc(length * sizeof(char));
				//	memcpy_s(export_message, sizeof(export_message), ao_message, length * sizeof(char));
				//	g_n3message_queue.push(export_message);
				//	//auto apm = isxao_classes::AddPetMessage(p);
				//	//HandleAddPetMessage(apm);
				//	break;
				//	//sprintf_s(buffer, "Type: %d, Id: %d\n", apm.Identity().Type(), apm.Identity().Id());
				//	//fopen_s(&pFILE, "messages.txt", "a");
				//	//fputs(buffer, pFILE);
				//	//fclose(pFILE);
				//	//sprintf_s(buffer, "Size: 0x%.8X\n", static_cast<N3Message*>(p1)->MessageBodyLen());
				//	//fopen_s(&pFILE, "messages.txt", "a");
				//	//fputs(buffer, pFILE);
				//	//fclose(pFILE);
				//}
				//case ::N3T_ATTACK:
				//{
				//	//auto am = isxao_classes::AttackMessage(p);
				//	//HandleAttackMessage(am);
				//	break;
				//	//sprintf_s(buffer, "Type: %d, Id: %d Unknown:%d\n", am.Type(), am.Id(), am.Unknown());
				//	//fopen_s(&pFILE, "messages.txt", "a");
				//	//fputs(buffer, pFILE);
				//	//fclose(pFILE);


				//}
				//case ::N3T_CAST_NANO_SPELL:
				//{
				//	//auto cnsm = isxao_classes::CastNanoSpellMessage(p);
				//	//HandleCastNanoSpellMessage(cnsm);
				//	break;
				//}
				//case ::N3T_CHARACTER_ACTION:
				//{
				//	//auto cam = isxao_classes::CharacterActionMessage(p);
				//	//HandleCharacterActionMessage(cam);
				//	/*sprintf_s(buffer, "Type: 0x%.8X, unknown_0x4: %d, TargetType: %d, TargetId: %d, Param1: %d, Param2: %d, unknown_0x24: %d\n",
				//	cam.CharacterActionType(), cam.unknown_0x4(), cam.Identity().Type(), cam.Identity().Id(), cam.Param1(), cam.Param2(), cam.Param3());
				//	fopen_s(&pFILE, "messages.txt", "a");
				//	fputs(buffer, pFILE);
				//	fclose(pFILE);*/
				//	break;
				//}
				//case ::N3T_FOLLOW_TARGET:
				//{
				//	//auto ftm = isxao_classes::FollowTargetMessage(p);
				//	//HandleFollowTargetMessage(ftm);
				//	break;
				//}
				//case ::N3T_KNUBOT_NPC_DESCRIPTION: break;
				//case ::N3T_ADD_TEMPLATE: break;
				//case ::N3T_GRID_DESTINATION_SELECT: break;
				//case ::N3T_WEATHER_CONTROL: break;
				//case ::N3T_PET_TO_MASTER: break;
				//case ::N3T_FLUSH_RDB_CACHES: break;
				//case ::N3T_SHOP_SEARCH_RESULT: break;
				//case ::N3T_SHOP_SEARCH_REQUEST: break;
				//case ::N3T_ACCEPT_BS_INVITE: break;
				//case ::N3T_SET_POS: break;
				//case ::N3T_REFLECT_ATTACK: break;
				//case ::N3T_SPECIAL_ATTACK_WEAPON:
				//{
				//	//sprintf_s(buffer, "Size: 0x%.8X\n", static_cast<N3Message*>(p1)->MessageBodyLen());
				//	//fopen_s(&pFILE, "messages.txt", "a");
				//	//fputs(buffer, pFILE);
				//	//fclose(pFILE);
				//	//auto sawm = SpecialAttackWeaponMessage(p);
				//	//sprintf_s(buffer, "1: %d\n2: %d\n3: %d\n4: %d\n5: %d\n6: %d\n7: %d\n8: %d\n9: %d\n10: %d\n11: %d\n12: %d\n13: %d\n14: %d\n15: %d\n16: %d\n17: %d\n18: %d\n"
				//	//	, sawm.m_Unknown1, sawm.m_Unknown2, sawm.m_Unknown3, sawm.m_Unknown4, sawm.m_Unknown5, sawm.m_Unknown6, sawm.m_Unknown7, sawm.m_Unknown8, sawm.m_Unknown9,
				//	//	sawm.m_Unknown10, sawm.m_Unknown11, sawm.m_Unknown12, sawm.m_Unknown13, sawm.m_Unknown14, sawm.m_Unknown15, sawm.m_Unknown16, sawm.m_Unknown17, sawm.m_Unknown18);
				//	//fopen_s(&pFILE, "messages.txt", "a");
				//	//fputs(buffer, pFILE);
				//	//fclose(pFILE);
				//}
				//case ::N3T_MENTOR_INVITE: break;
				//case ::N3T_SCRIPT: break;
				//case ::N3T_FORMAT_FEEDBACK: break;
				//case ::N3T_KNUBOT_ANSWER: break;
				//case ::N3T_QUEST: break;
				//case ::N3T_MINE_FULL_UPDATE: break;
				//case ::N3T_LOOK_AT: break;
				//case ::N3T_SHIELD_ATTACK: break;
				//case ::N3T_RESEARCH_UPDATE: break;
				//case ::N3T_RELOCATE_DYNELS: break;
				//case ::N3T_ABSORB: break;
				//case ::N3T_RELOAD: break;
				//case ::N3T_KNUBOT_CLOSE_CHAT_WINDOW: break;
				//case ::N3T_SIMPLE_CHAR_FULL_UPDATE: break;
				//case ::N3T_START_LOGOUT: break;
				//case ::N3T_TEAM_MEMBER_INFO: break;
				//case ::N3T_FULL_CHARACTER: break;
				//case ::N3T_LASER_TARGET_LIST: break;
				//case ::N3T_TRAP_DISARMED: break;
				//case ::N3T_FOV: break;
				//case ::N3T_STAT: break;
				//case ::N3T_QUEUE_UPDATE: break;
				//case ::N3T_KNUBOT_REJECTED_ITEMS: break;
				//case ::N3T_PLAYER_SHOP_FULL_UPDATE: break;
				//case ::N3T_ORG_INFO_PACKET: break;
				//case ::N3T_N3_PLAYFIELD_FULL_UPDATE: break;
				//case ::N3T_RESEARCH_REQUEST: break;
				//case ::N3T_AREA_FORMULA: break;
				//case ::N3T_IN_FROM_PLAYER: break;
				//case ::N3T_MAIL: break;
				//case ::N3T_APPLY_SPELLS: break;
				//case ::N3T_BANK: break;
				//case ::N3T_SHOP_INVENTORY: break;
				//case ::N3T_TEMPLATE_ACTION: break;
				//case ::N3T_TRADE: break;
				//case ::N3T_DESPAWN: break;
				//case ::N3T_DOOR_FULL_UPDATE: break;
				//case ::N3T_CITY_ADVANTAGES: break;
				//case ::N3T_HEALTH_DAMAGE:
				//{
				//	//sprintf_s(buffer, "Size: 0x%.8X\n", static_cast<N3Message*>(p1)->MessageBodyLen());
				//	//fopen_s(&pFILE, "messages.txt", "a");
				//	//fputs(buffer, pFILE);
				//	//fclose(pFILE);
				//}
				//case ::N3T_FIGHT_MODE_UPDATE: break;
				//case ::N3T_SET_SHOP_NAME: break;
				//case ::N3T_BUFF: break;
				//case ::N3T_KNUBOT_TRADE: break;
				//case ::N3T_DROP_TEMPLATE: break;
				//case ::N3T_GRID_SELECTED: break;
				//case ::N3T_SIMPLEITEM_FULL_UPDATE: break;
				//case ::N3T_KNUBOT_OPEN_CHAT_WINDOW: break;
				//case ::N3T_WEAPONITEM_FULL_UPDATE: break;
				//case ::N3T_SOCIAL_ACTION_CMD: break;
				//case ::N3T_RAID: break;
				//case ::N3T_SHADOW_LEVEL: break;
				//case ::N3T_CLONE: break;
				//case ::N3T_SHOP_COMMISSION: break;
				//case ::N3T_SERVER_PATH_POS_DEBUG_INFO: break;
				//case ::N3T_SKILL: break;
				//case ::N3T_LEAVE_BATTLE: break;
				//case ::N3T_SHOP_INFO: break;
				//case ::N3T_APPEARANCE_UPDATE: break;
				//case ::N3T_N3_TELEPORT: break;
				//case ::N3T_PERK_UPDATE: break;
				//case ::N3T_SEND_SCORE: break;
				//case ::N3T_RESURRECT: break;
				//case ::N3T_UPDATE_CLIENT_VISUAL: break;
				//case ::N3T_HOUSE_DEMOLISH_START: break;
				//case ::N3T_PLAY_SOUND1: break;
				//case ::N3T_ATTACK_INFO: break;
				//case ::N3T_TEAM_MEMBER: break;
				//case ::N3T_SPAWN_MECH: break;
				//case ::N3T_QUEST_FULL_UPDATE: break;
				//case ::N3T_CHESTITEM_FULL_UPDATE: break;
				//case ::N3T_NANO_ATTACK: break;
				//case ::N3T_DROP_DYNEL: break;
				//case ::N3T_CONTAINER_ADD_ITEM: break;
				//case ::N3T_VISIBILITY: break;
				//case ::N3T_STOP_FIGHT: break;
				//case ::N3T_BATTLE_OVER: break;
				//case ::N3T_INVENTORY_UPDATED: break;
				//case ::N3T_DOOR_STATUS_UPDATE: break;
				//case ::N3T_TEAM_INVITE: break;
				//case ::N3T_SHOP_STATUS: break;
				//case ::N3T_INFO_PACKET: break;
				//case ::N3T_SPELL_LIST: break;
				//case ::N3T_INVENTORY_UPDATE: break;
				//case ::N3T_CORPSE_FULL_UPDATE: break;
				//case ::N3T_FEEDBACK: break;
				//case ::N3T_CHAR_SEC_SPEC_ATTACK: break;
				//case ::N3T_BANK_CORPSE: break;
				//case ::N3T_GENERIC_CMD: break;
				//case ::N3T_PATH_MOVE_CMD: break;
				//case ::N3T_ARRIVE_AT_BS: break;
				//case ::N3T_CHAR_DC_MOVE: break;
				//case ::N3T_PLAYFIELD_ALL_TOWERS: break;
				//case ::N3T_KNUBOT_FINISH_TRADE: break;
				//case ::N3T_KNUBOT_ANSWER_LIST: break;
				//case ::N3T_STOP_LOGOUT: break;
				//case ::N3T_CHAR_IN_PLAY: break;
				//case ::N3T_SHOP_UPDATE: break;
				//case ::N3T_MECH_INFO: break;
				//case ::N3T_REMOVE_PET: break;
				//case ::N3T_PLAYFIELD_ALL_CITIES: break;
				//case ::N3T_TRAPITEM_FULL_UPDATE: break;
				//case ::N3T_INSPECT: break;
				//case ::N3T_PLAYFIELD_TOWER_UPDATE_CLIENT: break;
				//case ::N3T_SERVER_POS_DEBUG_INFO: break;
				//case ::N3T_QUEST_ALTERNATIVE: break;
				//case ::N3T_FULL_AUTO: break;
				//case ::N3T_CHAT_CMD: break;
				//case ::N3T_MISSED_ATTACK_INFO: break;
				//case ::N3T_KNUBOT_APPEND_TEXT: break;
				//case ::N3T_HOUSE_DISAPPEARED: break;
				//case ::N3T_IMPULSE: break;
				//case ::N3T_PLAYFIELD_ANARCHY_F: break;
				//case ::N3T_CHAT_TEXT: break;
				//case ::N3T_GAME_TIME: break;
				//case ::N3T_SET_WANTED_DIRECTION: break;
				//case ::N3T_AO_TRANSPORT_SIGNAL: break;
				//case ::N3T_PET_COMMAND: break;
				//case ::N3T_ORG_SERVER: break;
				//case ::N3T_SET_STAT: break;
				//case ::N3T_SET_NAME: break;
				//case ::N3T_STOP_MOVING_CMD: break;
				//case ::N3T_SPECIAL_ATTACK_INFO: break;
				//case ::N3T_GIVE_QUEST_TO_MEMBER: break;
				//case ::N3T_KNUBOT_START_TRADE: break;
				//case ::N3T_GFX_TRIGGER: break;
				//case ::N3T_SHOP_ITEM_PRICE: break;
				//case ::N3T_NEW_LEVEL: break;
				//case ::N3T_ORG_CLIENT: break;
				//case ::N3T_VENDING_MACHINE_FULL_UPDATE: break;
				//default:
				//	break;
				//}
				break;
			}
			case ao::PT_PING_MESSAGE: break;
			case ao::PT_OPERATOR_MESSAGE: break;
			case ao::PT_INITIATE_COMPRESSION_MESSAGE: break;
			default: break;
			}
		//}

		return client_t__process_message_trampoline(p1);
	}

#pragma endregion

#pragma region SetTeleportStatus

	DETOUR_TRAMPOLINE_EMPTY(void ao_detours::n3Engine_t__SetTeleportStatus_Trampoline(bool));

	void ao_detours::n3Engine_t__SetTeleportStatus_Detour(bool status)
	{
		if (status)
		{
			TeleportService(pExtension, StartTeleport, nullptr);
			pISInterface->ExecuteEvent(GetEventId("AO_onZoneBegin"), 0, 0);
		}
		else
		{
			TeleportService(pExtension, StopTeleport, nullptr);
			pISInterface->ExecuteEvent(GetEventId("AO_onZoneEnd"), 0, 0);
		}
		n3Engine_t__SetTeleportStatus_Trampoline(status);
	}

#pragma endregion

#pragma region ChatGUIModule Message Handling

	DETOUR_TRAMPOLINE_EMPTY(void ao_detours::ChatGUIModule_c__HandleGroupAction_Trampoline(ao::p_ppj_client_group_action_t));

	void ao_detours::ChatGUIModule_c__HandleGroupAction_Detour(ao::p_ppj_client_group_action_t m)
	{
		if(get_game_state() == GAMESTATE_IN_GAME)
		{
/*			FILE * pFILE;
			char buffer[MAX_VARSTRING];
			sprintf_s(buffer, "Group Action:\n\t%d\n\t%d\n\t%s\n\t%d\n\t%d\n\t%d\n\t%d\n\t%d\n\t%d\n\t%d\n\t%d\n", m->unknown_0x4, m->Unknown0x8, m->String1.c_str(), m->unknown_0x28, m->unknown_0x2C, m->unknown_0x30, m->Unknown0x34, m->Unknown0x38, m->Unknown0x3C, m->unknown_0x40, m->unknown_0x44);
			fopen_s(&pFILE, "messages.txt", "a");
			fputs(buffer, pFILE);
			fclose(pFILE);	*/		
		}
		ChatGUIModule_c__HandleGroupAction_Trampoline(m);
	}

	DETOUR_TRAMPOLINE_EMPTY(void ao_detours::ChatGUIModule_c__HandleGroupMessage_Trampoline(ao::p_ppj_group_message_t));

	void ao_detours::ChatGUIModule_c__HandleGroupMessage_Detour(ao::p_ppj_group_message_t m)
	{
		if(get_game_state() == GAMESTATE_IN_GAME)
		{
			PGROUPMESSAGEINFO group_message_info = new GROUPMESSAGEINFO(m->sender_id, m->sender, m->channel_name, m->message);
			g_group_message_queue.push(group_message_info);
		}
		ChatGUIModule_c__HandleGroupMessage_Trampoline(m);
	}
	
	DETOUR_TRAMPOLINE_EMPTY(void ao_detours::ChatGUIModule_c__HandlePrivateGroupAction_Trampoline(ao::p_ppj_client_private_group_action_t));

	void ao_detours::ChatGUIModule_c__HandlePrivateGroupAction_Detour(ao::p_ppj_client_private_group_action_t m)
	{
		if(get_game_state() == GAMESTATE_IN_GAME)
		{
			//FILE * pFILE;
			//char buffer[MAX_VARSTRING];
			//sprintf_s(buffer, "PrivateGroupAction Message:\n\t%d\n\t%d\n\t%s\n\t%d\n\t%d\n\t%s\n", m->unknown_0x04, m->unknown_0x08, m->String1.c_str(), m->unknown_0x28, m->unknown_0x2C, m->String2.c_str());
			//fopen_s(&pFILE, "messages.txt", "a");
			//fputs(buffer, pFILE);
			//fclose(pFILE);
		}
		ChatGUIModule_c__HandlePrivateGroupAction_Trampoline(m);
	}

	DETOUR_TRAMPOLINE_EMPTY(void ao_detours::ChatGUIModule_c__HandlePrivateMessage_Trampoline(ao::p_ppj_client_private_message_t));

	void ao_detours::ChatGUIModule_c__HandlePrivateMessage_Detour(ao::p_ppj_client_private_message_t m)
	{
		if(get_game_state() == GAMESTATE_IN_GAME)
		{
			//FILE * pFILE;
			//char buffer[MAX_VARSTRING];
			//sprintf_s(buffer, "Private Message:\n\t%d\n\t%d\n\t%s\n\t%s\n\t%d\n\t%d\n\t%d\n\t%d\n", m->unknown_0x4, m->SenderId, m->Sender.c_str(), m->Message.c_str(), m->unknown_0x44, m->unknown_0x48, m->Unknown0x4C, m->Unknown0x50);
			//fopen_s(&pFILE,"messages.txt", "a");
			//fputs(buffer, pFILE);
			//fclose(pFILE);

			PPRIVATEMESSAGEINFO private_message_info = new PRIVATEMESSAGEINFO(m->sender_id, m->sender, m->message);
			g_private_message_queue.push(private_message_info);
		}
		ChatGUIModule_c__HandlePrivateMessage_Trampoline(m);
	}

	DETOUR_TRAMPOLINE_EMPTY(void ao_detours::ChatGUIModule_c__HandleSystemMessage_Trampoline(ao::p_ppj_client_system_message_t));

	void ao_detours::ChatGUIModule_c__HandleSystemMessage_Detour(ao::p_ppj_client_system_message_t m)
	{
		if(get_game_state() == GAMESTATE_IN_GAME)
		{
			//FILE * pFILE;
			//char buffer[MAX_VARSTRING];
			//sprintf_s(buffer, "System Message:\n\t%d\n\t%d\n\t%s\n\t%d\n\t%s\n", m->unknown_0x4, m->Unknown0x8, m->String1.c_str(), m->unknown_0x28, m->String2.c_str());
			//fopen_s(&pFILE, "messages.txt", "a");
			//fputs(buffer, pFILE);
			//fclose(pFILE);
		}
		ChatGUIModule_c__HandleSystemMessage_Trampoline(m);
	}

	DETOUR_TRAMPOLINE_EMPTY(void ao_detours::ChatGUIModule_c__HandleVicinityMessage_Trampoline(ao::p_ppj_client_vicinity_message_t));

	void ao_detours::ChatGUIModule_c__HandleVicinityMessage_Detour(ao::p_ppj_client_vicinity_message_t m)
	{
		if (get_game_state() == GAMESTATE_IN_GAME)
		{
			//FILE * pFILE;
			//char buffer[MAX_VARSTRING];
			//sprintf_s(buffer, "Vicinity Message:\n\t%d\n\t%d\n\t%s\n\t%s\n\t%d\n\t%d\n\t%d\n\t%d\n", m->unknown_0x4, m->SenderId, m->Sender.c_str(), m->Message.c_str(), m->unknown_0x44, m->unknown_0x48, m->Unknown0x4C, m->Unknown0x50);
			//fopen_s(&pFILE, "messages.txt", "a");
			//fputs(buffer, pFILE);
			//fclose(pFILE);
			//char sender[MAX_VARSTRING];
			//char ao_message[MAX_VARSTRING];
			//char id[MAX_VARSTRING];
			//strcpy_s(sender, MAX_VARSTRING, m->Sender.c_str());
			//strcpy_s(ao_message, MAX_VARSTRING, m->Message.c_str());
			//identity_t identity;
			//identity.Type = 50000;
			//identity.Id = m->SenderId;
			//sprintf_s(id, MAX_VARSTRING, "%I64u", identity.get_combined_identity());
			//char *argv[] = { sender, ao_message, id };
			//pISInterface->ExecuteEvent(GetEventId("AO_onVicinityMessageReceived"), 0, 3, argv);
			//delete argv;
			PPRIVATEMESSAGEINFO vicintity_message_info = new PRIVATEMESSAGEINFO(m->sender_id, m->sender, m->message);
			g_vicinity_message_queue.push(vicintity_message_info);
		}
		ChatGUIModule_c__HandleVicinityMessage_Trampoline(m);
	}

#pragma endregion

#pragma region ChatGroupController

	DETOUR_TRAMPOLINE_EMPTY(void ao_detours::ChatGroupController_c__sub_10083D9C_Trampoline(int, string*, int));

	void ao_detours::ChatGroupController_c__sub_10083D9C_Detour(int group_id, string* chat_text, int unknown)
	{
		if (get_game_state() == GAMESTATE_IN_GAME)
		{
			//char text[MAX_VARSTRING];
			//strcpy_s(text, sizeof(text), chat_text->c_str());		
			//char chat_type[MAX_VARSTRING];
			//switch (::ChatGroup_e(group_id))
			//{
			//case ::CG_SYSTEM:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "SYSTEM");
			//	break;
			//}
			//case ::CG_VICINITY:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "VICINITY");
			//	break;
			//}
			//case ::CG_TELL_MESSAGES:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "TELL_MESSAGES");
			//	break;
			//}
			//case ::CG_YOUR_PETS:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "YOUR_PETS");
			//	break;
			//}
			//case ::CG_OTHERS_PETS:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "OTHERS_PETS");
			//	break;
			//}
			//case ::CG_ME_HIT_BY_ENVIRONMENT:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "ME_HIT_BY_ENVIRONMENT");
			//	break;
			//}
			//case ::CG_ME_HIT_BY_NANO:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "ME_HIT_BY_NANO");
			//	break;
			//}
			//case ::CG_YOUR_PET_HIT_BY_NANO:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "YOUR_PET_HIT_BY_NANO");
			//	break;
			//}
			//case ::CG_OTHER_HIT_BY_NANO:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "OTHER_HIT_BY_NANO");
			//	break;
			//}
			//case ::CG_YOU_HIT_OTHER_WITH_NANO:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "YOU_HIT_OTHER_WITH_NANO");
			//	break;
			//}
			//case ::CG_ME_HIT_BY_MONSTER:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "ME_HIT_BY_MONSTER");
			//	break;
			//}
			//case ::CG_ME_HIT_BY_PLAYER:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "ME_HIT_BY_PLAYER");
			//	break;
			//}
			//case ::CG_YOU_HIT_OTHER:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "YOU_HIT_OTHER");
			//	break;
			//}
			//case ::CG_YOUR_PET_HIT_BY_OTHER:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "YOUR_PET_HIT_BY_OTHER");
			//	break;
			//}
			//case ::CG_OTHER_HIT_BY_OTHER:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "OTHER_HIT_BY_OTHER");
			//	break;
			//}
			//case ::CG_ME_GOT_XP:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "ME_GOT_XP");
			//	break;
			//}
			//case ::CG_ME_GOT_SK:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "ME_GOT_SK");
			//	break;
			//}
			//case ::CG_YOUR_PET_HIT_BY_MONSTER:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "YOUR_PET_HIT_BY_MONSTER");
			//	break;
			//}
			//case ::CG_YOUR_MISSES:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "YOUR_MISSES");
			//	break;
			//}
			//case ::CG_OTHER_MISSES:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "OTHER_MISSES");
			//	break;
			//}
			//case ::CG_YOU_GAVE_HEALTH:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "YOU_GAVE_HEALTH");
			//	break;
			//}
			//case ::CG_ME_GOT_HEALTH:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "ME_GOT_HEALTH");
			//	break;
			//}
			//case ::CG_ME_GOT_NANO:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "ME_GOT_NANO");
			//	break;
			//}
			//case ::CG_YOU_GAVE_NANO:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "YOU_GAVE_NANO");
			//	break;
			//}
			//case ::CG_ME_CAST_NANO:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "ME_CAST_NANO");
			//	break;
			//}
			//case ::CG_TEAM_LOOT_MESSAGES:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "TEAM_LOOT_MESSAGES");
			//	break;
			//}
			//case ::CG_VICINITY_LOOT_MESSAGES:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "VICINITY_LOOT_MESSAGES");
			//	break;
			//}
			//case ::CG_RESEARCH:
			//{
			//	strcpy_s(chat_type, sizeof(chat_type), "RESEARCH");
			//	break;
			//}
			//default:
			//	sprintf_s(chat_type, sizeof(chat_type), "%d", group_id);
			//	break;
			//}
			//char *argv[] = { chat_type, text };
			//pISInterface->ExecuteEvent(GetEventId("AO_onIncomingSystemText"), 0, 2, argv);
			//delete argv;
			PSYSTEMCHATINFO system_chat_info = new SYSTEMCHATINFO(group_id, chat_text);
			g_system_chat_queue.push(system_chat_info);
		}
		ChatGroupController_c__sub_10083D9C_Trampoline(group_id, chat_text, unknown);
	}


#pragma endregion

#pragma region FriendListController

	DETOUR_TRAMPOLINE_EMPTY(PVOID ao_detours::FriendListController_c__sub_100A68E6_Trampoline(string*, int, string*, int));

	// Tells
	PVOID ao_detours::FriendListController_c__sub_100A68E6_Detour(string* a, int sender_id, string* c, int d)
	{
		//FILE * pFILE;
		//char buffer[MAX_VARSTRING];
		//sprintf_s(buffer, "Chat Text:\n\t%s\n\t%d\n\t%s\n\t%d\n", a->c_str(), sender_id, c->c_str(), d);
		//fopen_s(&pFILE, "messages.txt", "a");
		//fputs(buffer, pFILE);
		//fclose(pFILE);
		return FriendListController_c__sub_100A68E6_Trampoline(a, sender_id, c, d);
	}
	
#pragma endregion

#pragma region ChatWindowNode

	DETOUR_TRAMPOLINE_EMPTY(PVOID ao_detours::ChatWindowNode_c__sub_1009BB79_Trampoline(int, int, string*, string*, int, int, char));

	PVOID ao_detours::ChatWindowNode_c__sub_1009BB79_Detour(int a, int b, string* c, string* d, int e, int f, char g)
	{
		//FILE * pFILE;
		//char buffer[MAX_VARSTRING];
		//sprintf_s(buffer, "Text:\n\t%d\n\t%d\n\t%s\n\t%s\n\t%d\n\t%d\n\t%d\n", a, b, c->c_str(), d->c_str(), e, f, g);
		//fopen_s(&pFILE, "messages.txt", "a");
		//fputs(buffer, pFILE);
		//fclose(pFILE);
		return ChatWindowNode_c__sub_1009BB79_Trampoline(a, b, c, d, e, f, g);
	}


#pragma endregion

#pragma region CommandInterpreter

	DETOUR_TRAMPOLINE_EMPTY(bool ao_detours::CommandInterpreter_c__ParseTextCommand_Trampoline(ao::chat_window_node*, string*));

	bool ao_detours::CommandInterpreter_c__ParseTextCommand_Detour(ao::chat_window_node* node, string* text)
	{
		if(text->c_str()[0] == '/')
		{
			std::vector<PCHAR> v;
			char line[MAX_VARSTRING];
			strcpy_s(line, sizeof(line), text->c_str());
			PCSTR delim = " ";
			PCHAR token;
			PCHAR next_token;
			token = strtok_s(line, delim, &next_token);
			if(IsISXAOCommand(token))
			{
				string adjusted_text = *text;
				adjusted_text.erase(0, 1);
				pISInterface->ExecuteCommand(adjusted_text.c_str());
				return true;
			}			
		}
		return CommandInterpreter_c__ParseTextCommand_Trampoline(node, text);
	}

#pragma endregion

#pragma region WindowController

	DETOUR_TRAMPOLINE_EMPTY(void ao_detours::window_controller_c__handle_key_down__trampoline(const DWORD&, const DWORD&))

	void ao_detours::window_controller_c__handle_key_down__detour(const DWORD& a, const DWORD& b)
	{
		char message[MAX_VARSTRING];
		sprintf_s(message, sizeof(message), "[KEY DOWN] a = %d, b = %d", a, b);
		gp_isxao_log->add_line(message);
		window_controller_c__handle_key_down__trampoline(a, b);
	}

	DETOUR_TRAMPOLINE_EMPTY(void ao_detours::window_controller_c__handle_key_up__trampoline(const DWORD&, const DWORD&))

	void ao_detours::window_controller_c__handle_key_up__detour(const DWORD& a, const DWORD& b)
	{
		char message[MAX_VARSTRING];
		sprintf_s(message, sizeof(message), "[KEY UP] a = %d, b = %d", a, b);
		gp_isxao_log->add_line(message);
		window_controller_c__handle_key_up__trampoline(a, b);
	}

#pragma endregion

	void ao_detours::initialize()
	{		
#pragma region gamestate_service


		EzDetour(n3_engine_client_t__set_main_dynel, &ao_detours::n3_engine_client_t__set_main_dynel__detour, &ao_detours::n3_engine_client_t__set_main_dynel__trampoline);

		EzDetour(playfield_anarchy_t__playfield_anarchy_t, &ao_detours::playfield_anarchy_t__playfield_anarchy_t__detour, &ao_detours::playfield_anarchy_t__playfield_anarchy_t__trampoline);
		EzDetour(playfield_anarchy_t__d_playfield_anarchy_t, &ao_detours::playfield_anarchy_t__d_playfield_anarchy_t__detour, &ao_detours::playfield_anarchy_t__d_playfield_anarchy_t__trampoline);

		EzDetour(n3_engine_client_anarchy_t__n3_engine_client_anarchy_t, &ao_detours::n3_engine_client_anarchy_t__n3_engine_client_anarchy_t__detour, &ao_detours::n3_engine_client_anarchy_t__n3_engine_client_anarchy_t__trampoline);
		EzDetour(n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t, &ao_detours::n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t__detour, &ao_detours::n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t__trampoline);

#pragma endregion

#pragma region actor_service

		EzDetour(n3_playfield_t__add_child_dynel, &ao_detours::n3_playfield_t__add_child_dynel__detour, &ao_detours::n3_playfield_t__add_child_dynel__trampoline);
		EzDetour(n3_dynel_t__set_playfield, &ao_detours::n3_dynel_t__set_playfield__detour, &ao_detours::n3_dynel_t__set_playfield__trampoline);

#pragma endregion

		// EzDetour(n3_engine_client_anarchy_t__n3_msg_movement_changed, &n3_engine_client_anarchy_t__n3_msg_movement_changed__detour, &n3_engine_client_anarchy_t__n3_msg_movement_changed__trampoline);

		EzDetour(client_t__process_message, &ao_detours::client_t__process_message_detour, &ao_detours::client_t__process_message_trampoline);

		//EzDetour(n3Engine_t__SetTeleportStatus, &AODetours::n3Engine_t__SetTeleportStatus_Detour, &AODetours::n3Engine_t__SetTeleportStatus_Trampoline);

		//EzDetour(ChatGUIModule_c__HandleGroupAction, &AODetours::ChatGUIModule_c__HandleGroupAction_Detour, &AODetours::ChatGUIModule_c__HandleGroupAction_Trampoline);
		EzDetour(chat_gui_module_c__handle_group_message, &ao_detours::ChatGUIModule_c__HandleGroupMessage_Detour, &ao_detours::ChatGUIModule_c__HandleGroupMessage_Trampoline);
		//EzDetour(ChatGUIModule_c__HandlePrivateGroupAction, &AODetours::ChatGUIModule_c__HandlePrivateGroupAction_Detour, &AODetours::ChatGUIModule_c__HandlePrivateGroupAction_Trampoline);
		EzDetour(chat_gui_module_c__handle_private_message, &ao_detours::ChatGUIModule_c__HandlePrivateMessage_Detour, &ao_detours::ChatGUIModule_c__HandlePrivateMessage_Trampoline);
		//EzDetour(ChatGUIModule_c__HandleSystemMessage, &AODetours::ChatGUIModule_c__HandleSystemMessage_Detour, &AODetours::ChatGUIModule_c__HandleSystemMessage_Trampoline);
		EzDetour(chat_gui_module_c__handle_vicinity_message, &ao_detours::ChatGUIModule_c__HandleVicinityMessage_Detour, &ao_detours::ChatGUIModule_c__HandleVicinityMessage_Trampoline);

		// EzDetour(ChatGroupController_c__sub_10083D9C, &ao_detours::ChatGroupController_c__sub_10083D9C_Detour, &ao_detours::ChatGroupController_c__sub_10083D9C_Trampoline);

		//EzDetour(FriendListController_c__sub_100A68E6, &AODetours::FriendListController_c__sub_100A68E6_Detour, &AODetours::FriendListController_c__sub_100A68E6_Trampoline);

		//EzDetour(ChatWindowNode_c__sub_1009BB79, &AODetours::ChatWindowNode_c__sub_1009BB79_Detour, &AODetours::ChatWindowNode_c__sub_1009BB79_Trampoline);

		EzDetour(command_interpreter_c__parse_text_command, &ao_detours::CommandInterpreter_c__ParseTextCommand_Detour, &ao_detours::CommandInterpreter_c__ParseTextCommand_Trampoline);

		EzDetour(window_controller_t__handle_key_down, &ao_detours::window_controller_c__handle_key_down__detour, &ao_detours::window_controller_c__handle_key_down__trampoline);
		EzDetour(window_controller_t__handle_key_up, &ao_detours::window_controller_c__handle_key_up__detour, &ao_detours::window_controller_c__handle_key_up__trampoline);
	}

	void ao_detours::shutdown()
	{

#pragma region gamestate_service

		EzUnDetour(n3_engine_client_t__set_main_dynel);

		EzUnDetour(playfield_anarchy_t__playfield_anarchy_t);
		EzUnDetour(playfield_anarchy_t__d_playfield_anarchy_t);

		EzUnDetour(n3_engine_client_anarchy_t__n3_engine_client_anarchy_t);
		EzUnDetour(n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t);

#pragma endregion

#pragma region actor_service

		EzUnDetour(n3_playfield_t__add_child_dynel);
		EzUnDetour(n3_dynel_t__set_playfield);

#pragma endregion

		// EzUnDetour(n3_engine_client_anarchy_t__n3_msg_movement_changed);

		EzUnDetour(client_t__process_message);

		//EzUnDetour(n3Engine_t__SetTeleportStatus);

		//EzUnDetour(ChatGUIModule_c__HandleGroupAction);
		EzUnDetour(chat_gui_module_c__handle_group_message);
		//EzUnDetour(ChatGUIModule_c__HandlePrivateGroupAction);
		EzUnDetour(chat_gui_module_c__handle_private_message);
		//EzUnDetour(ChatGUIModule_c__HandleSystemMessage);
		EzUnDetour(chat_gui_module_c__handle_vicinity_message);

		// EzUnDetour(ChatGroupController_c__sub_10083D9C);

		//EzUnDetour(FriendListController_c__sub_100A68E6);

		//EzUnDetour(ChatWindowNode_c__sub_1009BB79);

		EzUnDetour(command_interpreter_c__parse_text_command);

		EzUnDetour(window_controller_t__handle_key_down);
		EzUnDetour(window_controller_t__handle_key_up);
	}
	
}
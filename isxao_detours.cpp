#include "isxao_main.h"

namespace isxao_detours
{

#pragma region Set MainDynel

	DETOUR_TRAMPOLINE_EMPTY(void AODetours::n3EngineClientAnarchy_t__SetMainDynel_Trampoline(PVOID));

	void AODetours::n3EngineClientAnarchy_t__SetMainDynel_Detour(PVOID p_dynel)
	{
		if (!p_dynel)
			GamestateService(pExtension, GamestateWaitingForCharacter, nullptr);
		n3EngineClientAnarchy_t__SetMainDynel_Trampoline(p_dynel);
		if (p_dynel)
			GamestateService(pExtension, GamestateInGame, nullptr);
	}

#pragma endregion

#pragma region Playfield Ctor/Dtor

	DETOUR_TRAMPOLINE_EMPTY(PVOID AODetours::PlayfieldAnarchy_t__PlayfieldAnarchy_t_Trampoline(PVOID));

	PVOID AODetours::PlayfieldAnarchy_t__PlayfieldAnarchy_t_Detour(PVOID p_playfield_proxy)
	{
		GamestateService(pExtension, GamestateWaitingForCharacter, nullptr);
		return PlayfieldAnarchy_t__PlayfieldAnarchy_t_Trampoline(p_playfield_proxy);		
	}

	DETOUR_TRAMPOLINE_EMPTY(void AODetours::PlayfieldAnarchy_t__dPlayfieldAnarchy_t_Trampoline());

	void AODetours::PlayfieldAnarchy_t__dPlayfieldAnarchy_t_Detour()
	{
		GamestateService(pExtension, GamestateWaitingForPlayfield, nullptr);
		PlayfieldAnarchy_t__dPlayfieldAnarchy_t_Trampoline();
	}

#pragma endregion

#pragma region n3EngineClientAnarchy Ctor/Dtor

	DETOUR_TRAMPOLINE_EMPTY(PVOID AODetours::n3EngineClientAnarchy_t__n3EngineClientAnarchy_t_Trampoline());

	PVOID AODetours::n3EngineClientAnarchy_t__n3EngineClientAnarchy_t_Detour()
	{
		GamestateService(pExtension, GamestateWaitingForPlayfield, nullptr);
		return n3EngineClientAnarchy_t__n3EngineClientAnarchy_t_Trampoline();
	}

	DETOUR_TRAMPOLINE_EMPTY(PVOID AODetours::n3EngineClientAnarchy_t__dn3EngineClientAnarchy_t_Trampoline());

	PVOID AODetours::n3EngineClientAnarchy_t__dn3EngineClientAnarchy_t_Detour()
	{
		GamestateService(pExtension, GamestateNotInGame, nullptr);
		return n3EngineClientAnarchy_t__dn3EngineClientAnarchy_t_Trampoline();
	}

#pragma endregion

#pragma region Adding and Removing Playfield Dynels

	DETOUR_TRAMPOLINE_EMPTY(void AODetours::Playfield_t__AddChildDynel_Trampoline(Dynel*, const VECTOR3&, const QUATERNION&));

	void AODetours::Playfield_t__AddChildDynel_Detour(Dynel* p_dynel, const VECTOR3 &position, const QUATERNION &rotation)
	{
		ActorService(pExtension, AddActor, p_dynel);
		Playfield_t__AddChildDynel_Trampoline(p_dynel, position, rotation);
	}

	DETOUR_TRAMPOLINE_EMPTY(void AODetours::n3Dynel_t__SetPlayfield_Trampoline(DWORD));

	void AODetours::n3Dynel_t__SetPlayfield_Detour(DWORD instance)
	{
		if (instance == 0)
		{
			PN3DYNEL p_dynel;
			__asm {mov[p_dynel], ecx};
			ActorService(pExtension, RemoveActor, p_dynel);
		}
		n3Dynel_t__SetPlayfield_Trampoline(instance);
	}

#pragma endregion

#pragma region Client ProcessMessage and Handling

	DETOUR_TRAMPOLINE_EMPTY(DWORD AODetours::Client_t__ProcessMessage_Trampoline(Message*));

	DWORD AODetours::Client_t__ProcessMessage_Detour(Message* p1)
	{
		//if (GetGameState() == GAMESTATE_IN_GAME)
		//{
			//FILE * pFILE;
			//char buffer[MAX_STRING];

			switch (::PacketType_e(p1->MessageTypeGet()))
			{
			case ::PT_SYSTEM_MESSAGE: break;
			case ::PT_TEXT_MESSAGE:
			{
				break;
			}
			case ::PT_N3_MESSAGE:
			{
				size_t length = static_cast<N3Message*>(p1)->MessageBodyLen();
				PCHAR message = static_cast<N3Message*>(p1)->MessageBodyGet();
				PVOID export_message = malloc(length);
				memcpy_s(export_message, length, message, length);
				PN3MESSAGEINFO message_info = new N3MESSAGEINFO(export_message, length);
				g_n3message_queue.push(message_info);
				//auto p = isxao_classes::Parser(message, length);
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
				//	memcpy_s(export_message, sizeof(export_message), message, length * sizeof(char));
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
				//	/*sprintf_s(buffer, "Type: 0x%.8X, Unknown0x4: %d, TargetType: %d, TargetId: %d, Param1: %d, Param2: %d, Unknown0x24: %d\n",
				//	cam.CharacterActionType(), cam.Unknown0x4(), cam.Identity().Type(), cam.Identity().Id(), cam.Param1(), cam.Param2(), cam.Param3());
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
			case ::PT_PING_MESSAGE: break;
			case ::PT_OPERATOR_MESSAGE: break;
			case ::PT_INITATE_COMPRESSION_MESSAGE: break;
			default: break;
			}
		//}

		return Client_t__ProcessMessage_Trampoline(p1);
	}

#pragma endregion

#pragma region SetTeleportStatus

	DETOUR_TRAMPOLINE_EMPTY(void AODetours::n3Engine_t__SetTeleportStatus_Trampoline(bool));

	void AODetours::n3Engine_t__SetTeleportStatus_Detour(bool status)
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

	DETOUR_TRAMPOLINE_EMPTY(void AODetours::ChatGUIModule_c__HandleGroupAction_Trampoline(PPPJCLIENTGROUPACTION));

	void AODetours::ChatGUIModule_c__HandleGroupAction_Detour(PPPJCLIENTGROUPACTION m)
	{
		if(GetGameState() == GAMESTATE_IN_GAME)
		{
/*			FILE * pFILE;
			char buffer[MAX_STRING];
			sprintf_s(buffer, "Group Action:\n\t%d\n\t%d\n\t%s\n\t%d\n\t%d\n\t%d\n\t%d\n\t%d\n\t%d\n\t%d\n\t%d\n", m->Unknown0x4, m->Unknown0x8, m->String1.c_str(), m->Unknown0x28, m->Unknown0x2C, m->Unknown0x30, m->Unknown0x34, m->Unknown0x38, m->Unknown0x3C, m->Unknown0x40, m->Unknown0x44);
			fopen_s(&pFILE, "messages.txt", "a");
			fputs(buffer, pFILE);
			fclose(pFILE);	*/		
		}
		ChatGUIModule_c__HandleGroupAction_Trampoline(m);
	}

	DETOUR_TRAMPOLINE_EMPTY(void AODetours::ChatGUIModule_c__HandleGroupMessage_Trampoline(PPPJCLIENTGROUPMESSAGE));

	void AODetours::ChatGUIModule_c__HandleGroupMessage_Detour(PPPJCLIENTGROUPMESSAGE m)
	{
		if(GetGameState() == GAMESTATE_IN_GAME)
		{
			PGROUPMESSAGEINFO group_message_info = new GROUPMESSAGEINFO(m->SenderId, m->Sender, m->ChannelName, m->Message);
			g_group_message_queue.push(group_message_info);
		}
		ChatGUIModule_c__HandleGroupMessage_Trampoline(m);
	}
	
	DETOUR_TRAMPOLINE_EMPTY(void AODetours::ChatGUIModule_c__HandlePrivateGroupAction_Trampoline(PPPJCLIENTPRIVATEGROUPACTION));

	void AODetours::ChatGUIModule_c__HandlePrivateGroupAction_Detour(PPPJCLIENTPRIVATEGROUPACTION m)
	{
		if(GetGameState() == GAMESTATE_IN_GAME)
		{
			//FILE * pFILE;
			//char buffer[MAX_STRING];
			//sprintf_s(buffer, "PrivateGroupAction Message:\n\t%d\n\t%d\n\t%s\n\t%d\n\t%d\n\t%s\n", m->Unknown0x04, m->Unknown0x08, m->String1.c_str(), m->Unknown0x28, m->Unknown0x2C, m->String2.c_str());
			//fopen_s(&pFILE, "messages.txt", "a");
			//fputs(buffer, pFILE);
			//fclose(pFILE);
		}
		ChatGUIModule_c__HandlePrivateGroupAction_Trampoline(m);
	}

	DETOUR_TRAMPOLINE_EMPTY(void AODetours::ChatGUIModule_c__HandlePrivateMessage_Trampoline(PPPJCLIENTPRIVATEMESSAGE));

	void AODetours::ChatGUIModule_c__HandlePrivateMessage_Detour(PPPJCLIENTPRIVATEMESSAGE m)
	{
		if(GetGameState() == GAMESTATE_IN_GAME)
		{
			//FILE * pFILE;
			//char buffer[MAX_STRING];
			//sprintf_s(buffer, "Private Message:\n\t%d\n\t%d\n\t%s\n\t%s\n\t%d\n\t%d\n\t%d\n\t%d\n", m->Unknown0x4, m->SenderId, m->Sender.c_str(), m->Message.c_str(), m->Unknown0x44, m->Unknown0x48, m->Unknown0x4C, m->Unknown0x50);
			//fopen_s(&pFILE,"messages.txt", "a");
			//fputs(buffer, pFILE);
			//fclose(pFILE);

			PPRIVATEMESSAGEINFO private_message_info = new PRIVATEMESSAGEINFO(m->SenderId, m->Sender, m->Message);
			g_private_message_queue.push(private_message_info);
		}
		ChatGUIModule_c__HandlePrivateMessage_Trampoline(m);
	}

	DETOUR_TRAMPOLINE_EMPTY(void AODetours::ChatGUIModule_c__HandleSystemMessage_Trampoline(PPPJCLIENTSYSTEMMESSAGE));

	void AODetours::ChatGUIModule_c__HandleSystemMessage_Detour(PPPJCLIENTSYSTEMMESSAGE m)
	{
		if(GetGameState() == GAMESTATE_IN_GAME)
		{
			//FILE * pFILE;
			//char buffer[MAX_STRING];
			//sprintf_s(buffer, "System Message:\n\t%d\n\t%d\n\t%s\n\t%d\n\t%s\n", m->Unknown0x4, m->Unknown0x8, m->String1.c_str(), m->Unknown0x28, m->String2.c_str());
			//fopen_s(&pFILE, "messages.txt", "a");
			//fputs(buffer, pFILE);
			//fclose(pFILE);
		}
		ChatGUIModule_c__HandleSystemMessage_Trampoline(m);
	}

	DETOUR_TRAMPOLINE_EMPTY(void AODetours::ChatGUIModule_c__HandleVicinityMessage_Trampoline(PPPJCLIENTVICINITYMESSAGE));

	void AODetours::ChatGUIModule_c__HandleVicinityMessage_Detour(PPPJCLIENTVICINITYMESSAGE m)
	{
		if (GetGameState() == GAMESTATE_IN_GAME)
		{
			//FILE * pFILE;
			//char buffer[MAX_STRING];
			//sprintf_s(buffer, "Vicinity Message:\n\t%d\n\t%d\n\t%s\n\t%s\n\t%d\n\t%d\n\t%d\n\t%d\n", m->Unknown0x4, m->SenderId, m->Sender.c_str(), m->Message.c_str(), m->Unknown0x44, m->Unknown0x48, m->Unknown0x4C, m->Unknown0x50);
			//fopen_s(&pFILE, "messages.txt", "a");
			//fputs(buffer, pFILE);
			//fclose(pFILE);
			//char sender[MAX_STRING];
			//char message[MAX_STRING];
			//char id[MAX_STRING];
			//strcpy_s(sender, MAX_STRING, m->Sender.c_str());
			//strcpy_s(message, MAX_STRING, m->Message.c_str());
			//IDENTITY identity;
			//identity.Type = 50000;
			//identity.Id = m->SenderId;
			//sprintf_s(id, MAX_STRING, "%I64u", identity.GetCombinedIdentity());
			//char *argv[] = { sender, message, id };
			//pISInterface->ExecuteEvent(GetEventId("AO_onVicinityMessageReceived"), 0, 3, argv);
			//delete argv;
			PPRIVATEMESSAGEINFO vicintity_message_info = new PRIVATEMESSAGEINFO(m->SenderId, m->Sender, m->Message);
			g_vicinity_message_queue.push(vicintity_message_info);
		}
		ChatGUIModule_c__HandleVicinityMessage_Trampoline(m);
	}

#pragma endregion

#pragma region ChatGroupController

	DETOUR_TRAMPOLINE_EMPTY(void AODetours::ChatGroupController_c__sub_10083D9C_Trampoline(int, string*, int));

	void AODetours::ChatGroupController_c__sub_10083D9C_Detour(int group_id, string* chat_text, int unknown)
	{
		if (GetGameState() == GAMESTATE_IN_GAME)
		{
			//char text[MAX_STRING];
			//strcpy_s(text, sizeof(text), chat_text->c_str());		
			//char chat_type[MAX_STRING];
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

	DETOUR_TRAMPOLINE_EMPTY(PVOID AODetours::FriendListController_c__sub_100A68E6_Trampoline(string*, int, string*, int));

	// Tells
	PVOID AODetours::FriendListController_c__sub_100A68E6_Detour(string* a, int sender_id, string* c, int d)
	{
		//FILE * pFILE;
		//char buffer[MAX_STRING];
		//sprintf_s(buffer, "Chat Text:\n\t%s\n\t%d\n\t%s\n\t%d\n", a->c_str(), sender_id, c->c_str(), d);
		//fopen_s(&pFILE, "messages.txt", "a");
		//fputs(buffer, pFILE);
		//fclose(pFILE);
		return FriendListController_c__sub_100A68E6_Trampoline(a, sender_id, c, d);
	}
	
#pragma endregion

#pragma region ChatWindowNode

	DETOUR_TRAMPOLINE_EMPTY(PVOID AODetours::ChatWindowNode_c__sub_1009BB79_Trampoline(int, int, string*, string*, int, int, char));

	PVOID AODetours::ChatWindowNode_c__sub_1009BB79_Detour(int a, int b, string* c, string* d, int e, int f, char g)
	{
		//FILE * pFILE;
		//char buffer[MAX_STRING];
		//sprintf_s(buffer, "Text:\n\t%d\n\t%d\n\t%s\n\t%s\n\t%d\n\t%d\n\t%d\n", a, b, c->c_str(), d->c_str(), e, f, g);
		//fopen_s(&pFILE, "messages.txt", "a");
		//fputs(buffer, pFILE);
		//fclose(pFILE);
		return ChatWindowNode_c__sub_1009BB79_Trampoline(a, b, c, d, e, f, g);
	}


#pragma endregion

#pragma region CommandInterpreter

	DETOUR_TRAMPOLINE_EMPTY(bool AODetours::CommandInterpreter_c__ParseTextCommand_Trampoline(ChatWindowNode*, string*));

	bool AODetours::CommandInterpreter_c__ParseTextCommand_Detour(ChatWindowNode* node, string* text)
	{
		if(text->c_str()[0] == '/')
		{
			std::vector<PCHAR> v;
			char line[MAX_STRING];
			strcpy_s(line, sizeof(line), text->c_str());
			PCSTR delim = " ";
			PCHAR token;
			PCHAR next_token;
			token = strtok_s(line, delim, &next_token);
			if(IsISXAOCommand(token))
			{
				/*v.push_back(token);
				while (token != nullptr)
				{
					token = strtok_s(nullptr, delim, &next_token);
					if (token != nullptr)
						v.push_back(token);
				}
				int argc = v.size();
				char **argv;
				argv = new char*[argc];
				for (int i = 0; i < argc; i++)
					argv[i] = v[i];*/
				string adjusted_text = *text;
				adjusted_text.erase(0, 1);
				pISInterface->ExecuteCommand(adjusted_text.c_str());
				//delete(argv);
				return true;
			}			
		}
		return CommandInterpreter_c__ParseTextCommand_Trampoline(node, text);
	}

#pragma endregion

	void AODetours::Initialize()
	{
		//gEzDetour(n3EngineClientAnarchy_t__SetMainDynel, &AODetours::n3EngineClientAnarchy_t__SetMainDynel_Detour, &AODetours::n3EngineClientAnarchy_t__SetMainDynel_Trampoline);

		//EzDetour(PlayfieldAnarchy_t__PlayfieldAnarchy_t, &AODetours::PlayfieldAnarchy_t__PlayfieldAnarchy_t_Detour, &AODetours::PlayfieldAnarchy_t__PlayfieldAnarchy_t_Trampoline);
		//EzDetour(PlayfieldAnarchy_t__dPlayfieldAnarchy_t, &AODetours::PlayfieldAnarchy_t__dPlayfieldAnarchy_t_Detour, &AODetours::PlayfieldAnarchy_t__dPlayfieldAnarchy_t_Trampoline);

		//EzDetour(n3_engine_client_anarchy_t__n3_engine_client_anarchy_t, &AODetours::n3EngineClientAnarchy_t__n3EngineClientAnarchy_t_Detour, &AODetours::n3EngineClientAnarchy_t__n3EngineClientAnarchy_t_Trampoline);
		//EzDetour(n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t, &AODetours::n3EngineClientAnarchy_t__dn3EngineClientAnarchy_t_Detour, &AODetours::n3EngineClientAnarchy_t__dn3EngineClientAnarchy_t_Trampoline);

		//EzDetour(n3_playfield_t__add_child_dynel, &AODetours::Playfield_t__AddChildDynel_Detour, &AODetours::Playfield_t__AddChildDynel_Trampoline);
		//EzDetour(n3_dynel_t__set_playfield, &AODetours::n3Dynel_t__SetPlayfield_Detour, &AODetours::n3Dynel_t__SetPlayfield_Trampoline);

		EzDetour(Client_t__ProcessMessage, &AODetours::Client_t__ProcessMessage_Detour, &AODetours::Client_t__ProcessMessage_Trampoline);

		//EzDetour(n3Engine_t__SetTeleportStatus, &AODetours::n3Engine_t__SetTeleportStatus_Detour, &AODetours::n3Engine_t__SetTeleportStatus_Trampoline);

		//EzDetour(ChatGUIModule_c__HandleGroupAction, &AODetours::ChatGUIModule_c__HandleGroupAction_Detour, &AODetours::ChatGUIModule_c__HandleGroupAction_Trampoline);
		EzDetour(ChatGUIModule_c__HandleGroupMessage, &AODetours::ChatGUIModule_c__HandleGroupMessage_Detour, &AODetours::ChatGUIModule_c__HandleGroupMessage_Trampoline);
		//EzDetour(ChatGUIModule_c__HandlePrivateGroupAction, &AODetours::ChatGUIModule_c__HandlePrivateGroupAction_Detour, &AODetours::ChatGUIModule_c__HandlePrivateGroupAction_Trampoline);
		EzDetour(ChatGUIModule_c__HandlePrivateMessage, &AODetours::ChatGUIModule_c__HandlePrivateMessage_Detour, &AODetours::ChatGUIModule_c__HandlePrivateMessage_Trampoline);
		//EzDetour(ChatGUIModule_c__HandleSystemMessage, &AODetours::ChatGUIModule_c__HandleSystemMessage_Detour, &AODetours::ChatGUIModule_c__HandleSystemMessage_Trampoline);
		EzDetour(ChatGUIModule_c__HandleVicinityMessage, &AODetours::ChatGUIModule_c__HandleVicinityMessage_Detour, &AODetours::ChatGUIModule_c__HandleVicinityMessage_Trampoline);

		EzDetour(ChatGroupController_c__sub_10083D9C, &AODetours::ChatGroupController_c__sub_10083D9C_Detour, &AODetours::ChatGroupController_c__sub_10083D9C_Trampoline);

		//EzDetour(FriendListController_c__sub_100A68E6, &AODetours::FriendListController_c__sub_100A68E6_Detour, &AODetours::FriendListController_c__sub_100A68E6_Trampoline);

		//EzDetour(ChatWindowNode_c__sub_1009BB79, &AODetours::ChatWindowNode_c__sub_1009BB79_Detour, &AODetours::ChatWindowNode_c__sub_1009BB79_Trampoline);

		EzDetour(CommandInterpreter_c__ParseTextCommand, &AODetours::CommandInterpreter_c__ParseTextCommand_Detour, &AODetours::CommandInterpreter_c__ParseTextCommand_Trampoline);
	}

	void AODetours::Shutdown()
	{
		//EzUnDetour(n3EngineClientAnarchy_t__SetMainDynel);

		//EzUnDetour(PlayfieldAnarchy_t__PlayfieldAnarchy_t);
		//EzUnDetour(PlayfieldAnarchy_t__dPlayfieldAnarchy_t);

		//EzUnDetour(n3_engine_client_anarchy_t__n3_engine_client_anarchy_t);
		//EzUnDetour(n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t);

		//EzUnDetour(n3_playfield_t__add_child_dynel);
		//EzUnDetour(n3_dynel_t__set_playfield);

		EzUnDetour(Client_t__ProcessMessage);

		//EzUnDetour(n3Engine_t__SetTeleportStatus);

		//EzUnDetour(ChatGUIModule_c__HandleGroupAction);
		EzUnDetour(ChatGUIModule_c__HandleGroupMessage);
		//EzUnDetour(ChatGUIModule_c__HandlePrivateGroupAction);
		EzUnDetour(ChatGUIModule_c__HandlePrivateMessage);
		//EzUnDetour(ChatGUIModule_c__HandleSystemMessage);
		EzUnDetour(ChatGUIModule_c__HandleVicinityMessage);

		EzUnDetour(ChatGroupController_c__sub_10083D9C);

		//EzUnDetour(FriendListController_c__sub_100A68E6);

		//EzUnDetour(ChatWindowNode_c__sub_1009BB79);

		EzUnDetour(CommandInterpreter_c__ParseTextCommand);
	}
	
}
#include "isxao_main.h"
#include "atlbase.h"
#include "iostream"
#include "command_interpreter.h"
#include "engine_client_anarchy.h"

namespace isxao
{

#pragma region Strings





#pragma endregion

#pragma region Objects


	bool IsValidDynel(ao::p_n3_dynel_t pDynel)
	{
		if (pDynel && pDynel->p_v_table)
		{
			//auto d = DWORD(pDynel->p_v_table);
			//if (d < DWORD(gamecode_module_handle) || d > DWORD(gamecode_module_handle + gamecode_module_info.SizeOfImage))
			//	return false;
			//if (d == AccessCard_t__vTable || d == CentralController_t__vTable || d == Chest_t__vTable || d == CityTerminal_t__vTable ||
			//	d == Corpse_t__vTable || d == Door_t__vTable || d == LockableItem_t__vTable || d == Mine_t__vTable ||
			//	d == PlayerShop_t__vTable || d == QuestBooth_t__vTable || d == ReclaimBooth_t__vTable || d == SimpleChar_t__vTable ||
			//	d == SimpleItem_t__vTable || d == TrapItem_t__vTable || d == VendingMachine_t__vTable || d == Weapon_t__vTable ||
			//	d == WearableItem_t__vTable)
			//	return true;
		}
		return false;
	}

#pragma endregion

#pragma region SearchActor

	DWORD ParseSearchActorArg(int arg, int argc, char *argv[], internal::SEARCHACTOR &search_actor)
	{
		if (arg >= argc)
			return 0;
		DWORD ExtraUsed = 0;
		{
			if (!_stricmp(argv[arg], "pc"))
			{
				search_actor.actor_type = internal::MOB_PC;
			}
			else if (!_stricmp(argv[arg], "npc"))
			{
				search_actor.actor_type = internal::MOB_NPC;
			}
			else if (!_stricmp(argv[arg], "pet"))
			{
				search_actor.actor_type = internal::MOB_PET;
			}
			else if (!_stricmp(argv[arg], "mypet"))
			{
				search_actor.actor_type = internal::MOB_MYPET;
			}
			else if (!_stricmp(argv[arg], "nopet"))
			{
				search_actor.no_pets = true;
			}
			else if (!_stricmp(argv[arg], "healer"))
			{
				search_actor.is_healer = true;
			}
			else if (!_stricmp(argv[arg], "tank"))
			{
				search_actor.is_tank = true;
			}
			else if (!_stricmp(argv[arg], "support"))
			{
				search_actor.is_support = true;
			}
			else if (!_stricmp(argv[arg], "dps"))
			{
				search_actor.is_dps = true;
			}
			else if (!_stricmp(argv[arg], "range"))
			{
				if (arg + 2 < argc)
				{
					search_actor.min_level = atoi(argv[arg + 1]);
					search_actor.max_level = atoi(argv[arg + 2]);
				}
				ExtraUsed = 2;
			}
			else if (!_stricmp(argv[arg], "loc"))
			{
				if (arg + 2 < argc)
				{
					search_actor.is_known_location = true;
					search_actor.x_loc = FLOAT(atof(argv[arg + 1]));
					search_actor.z_loc = FLOAT(atof(argv[arg + 2]));
				}
				ExtraUsed = 2;
			}
			else if (!_stricmp(argv[arg], "id"))
			{
				search_actor.is_dynel_id = true;
				if (arg + 1 < argc)
				{
					search_actor.actor_id = atoui64(argv[arg + 1]);
				}
				ExtraUsed = 1;
			}
			else if (!_stricmp(argv[arg], "radius"))
			{
				if (arg + 1 < argc)
					search_actor.f_radius = atof(argv[arg + 1]);
				ExtraUsed = 1;
			}
			else if (!_stricmp(argv[arg], "yradius"))
			{
				if (arg + 1 < argc)
					search_actor.y_radius = atof(argv[arg + 1]);
				ExtraUsed = 1;
			}
			else if (!_stricmp(argv[arg], "notid"))
			{
				if (arg + 1 < argc)
					search_actor.not_id = atoui64(argv[arg + 1]);
				ExtraUsed = 1;
			}
			else if (!_stricmp(argv[arg], "nopcnear"))
			{
				search_actor.radius = 0.0f;
				if (arg + 1 < argc)
					search_actor.radius = FLOAT(atof(argv[arg + 1]));
				if (search_actor.radius == 0.0f)
					search_actor.radius = 200.0f;
				ExtraUsed = 1;
			}
			else if (IsNumber(argv[arg]))
			{
				search_actor.min_level = atoi(argv[arg]);
				search_actor.max_level = search_actor.min_level;
			}
			else
			{
				strcpy_s(search_actor.name, sizeof(search_actor.name), argv[arg]);
				_strlwr_s(search_actor.name);
			}
		}
		return ExtraUsed;
	}

	void ClearSearchActor(internal::PSEARCHACTOR p_search_actor)
	{
		if (!p_search_actor) return;
		ZeroMemory(p_search_actor, sizeof(internal::SEARCHACTOR));
		p_search_actor->max_level = MAX_LEVEL;
		p_search_actor->y_radius = 10000.0f;
		p_search_actor->f_radius = 10000.0f;
	}

	void ParseSearchActor(int begin_inclusive, int end_exclusive, char *argv[], internal::SEARCHACTOR &search_actor)
	{
		for (int arg = begin_inclusive; arg < end_exclusive; arg++)
			arg += ParseSearchActorArg(arg, end_exclusive, argv, search_actor);
	}

	bool ActorMatchesSearch(internal::PSEARCHACTOR p_search_actor, ao::actor* p_character, ao::actor* p_actor)
	{
		char szName[MAX_VARSTRING] = { 0 };
		char szSearchName[MAX_VARSTRING] = { 0 };
		DWORD actor_type;
		if (p_actor->get_identity().type != 50000)
			actor_type = internal::MOB_OTHER;
		else if (p_actor->is_actor())
		{
			if (p_actor->is_pet() && is_client_id(p_actor->get_master_id()))
				actor_type = internal::MOB_MYPET;
			else if (p_actor->is_pet())
				actor_type = internal::MOB_PET;
			else
				actor_type = internal::MOB_NPC;
		}
		else
			actor_type = internal::MOB_PC;
		if (p_search_actor->actor_type != actor_type && p_search_actor->actor_type != internal::MOB_NONE)
			return false;
		strcpy_s(szName, MAX_VARSTRING, p_actor->get_name());
		_strlwr_s(szName);
		strcpy_s(szSearchName, MAX_VARSTRING, p_search_actor->name);
		_strlwr_s(szSearchName);
		if (!strstr(szName, szSearchName))
			return false;
		if (p_search_actor->min_level && DWORD(p_actor->get_skill(ao::ST_LEVEL)) < p_search_actor->min_level)
			return false;
		if (p_search_actor->max_level && DWORD(p_actor->get_skill(ao::ST_LEVEL)) > p_search_actor->max_level)
			return false;
		if (p_search_actor->not_id == p_actor->get_identity().get_combined_identity())
			return false;
		if (p_search_actor->is_dynel_id && p_search_actor->actor_id != p_actor->get_identity().get_combined_identity())
			return false;
		if (p_search_actor->is_known_location)
		{
			if (p_search_actor->x_loc != p_actor->get_position().x || p_search_actor->z_loc != p_actor->get_position().z)
			{
				ao::vector3_t knownLoc;
				knownLoc.x = p_search_actor->x_loc;
				knownLoc.y = 0.0f;
				knownLoc.z = p_search_actor->z_loc;
				if (p_search_actor->f_radius < 10000.0f && p_actor->get_distance_to(knownLoc) > p_search_actor->f_radius)
					return false;
			}
		}
		if (p_search_actor->radius > 0.0f && IsPCNear(p_actor, p_search_actor->radius))
			return false;
		if (ao::g_y_filter < 10000.0f)
		{
			ao::vector3_t client = p_character->get_position();
			if (p_actor->get_position().y > client.y + ao::g_y_filter || p_actor->get_position().y < client.y - ao::g_y_filter)
				return false;
		}
		if (p_search_actor->y_radius < 10000.0f)
		{
			ao::vector3_t client = p_character->get_position();
			if (p_actor->get_position().y > client.y + p_search_actor->y_radius || p_actor->get_position().y < client.y - p_search_actor->y_radius)
				return false;
		}
		return true;
	}

	bool IsPCNear(ao::actor* p_actor, float radius)
	{
		ao::actor* p_close_actor = nullptr;
		if (P_ENGINE_CLIENT_ANARCHY)
		{
			std::vector<ao::actor*> v;
			P_PLAYFIELD_DIR->get_playfield()->get_playfield_actors(v);
			for (auto it = v.begin(); it != v.end(); ++it)
			{
				if ((*it)->get_identity().type == 50000 && !P_ENGINE_CLIENT_ANARCHY->n3_msg_is_npc((*it)->get_identity()))
				{
					if ((*it) != p_actor)
					{
						ao::vector3_t c = (*it)->get_position();
						if (p_actor->get_distance_to(c) < radius)
							return true;
					}
				}
			}
		}
		return false;
	}

	DWORD CountMatchingActors(internal::PSEARCHACTOR p_search_actor, ao::actor* p_character, bool include_char)
	{
		if (!p_search_actor || !p_character)
			return 0;
		DWORD total_matching = 0;
		std::vector<ao::actor*> v;
		P_PLAYFIELD_DIR->get_playfield()->get_playfield_actors(v);
		for (auto it = v.begin(); it != v.end(); ++it)
		{
			if (include_char)
			{
				if (ActorMatchesSearch(p_search_actor, p_character, (*it)))
				{
					total_matching++;
				}
			}
			else
			{
				if (p_character != (*it) && ActorMatchesSearch(p_search_actor, p_character, (*it)))
				{
					total_matching++;
				}
			}
		}
		return total_matching;
	}

	ao::actor* NthNearestActor(internal::PSEARCHACTOR p_search_actor, DWORD nth, ao::actor* p_origin, bool include_char)
	{
		if (!p_search_actor || !nth || !p_origin)
			return nullptr;
		CIndex<internal::PAORANK> actor_set;
		ao::vector3_t pos = p_origin->get_position();
		std::vector<ao::actor*> v;
		P_PLAYFIELD_DIR->get_playfield()->get_playfield_actors(v);
		DWORD TotalMatching = 0;
		if (include_char)
		{
			for (auto it = v.begin(); it != v.end(); ++it)
			{
				if (ActorMatchesSearch(p_search_actor, p_origin, *it))
				{
					TotalMatching++;
					internal::PAORANK pNewRank = new internal::AORANK;
					pNewRank->VarPtr.Ptr = *it;
					pNewRank->Value.Float = (*it)->get_distance_to(pos);
					actor_set += pNewRank;
				}
			}
		}
		else
		{
			for (auto it = v.begin(); it != v.end(); ++it)
			{
				if (*it != p_origin && ActorMatchesSearch(p_search_actor, p_origin, *it))
				{
					TotalMatching++;
					internal::PAORANK pNewRank = new internal::AORANK;
					pNewRank->VarPtr.Ptr = *it;
					pNewRank->Value.Float = (*it)->get_distance_to(pos);
					actor_set += pNewRank;
				}
			}
		}
		if (TotalMatching < nth)
		{
			actor_set.Cleanup();
			return nullptr;
		}
		std::sort(&actor_set.List[0], &actor_set[0] + TotalMatching, internal::pAORankFloatCompare);
		auto p_actor = static_cast<ao::actor*>(actor_set[nth - 1]->VarPtr.Ptr);
		actor_set.Cleanup();
		return p_actor;
	}
	
	//void ClearSearchActor(PSEARCHACTOR p_search_actor)
	//{
	//	if (!p_search_actor) return;
	//	ZeroMemory(p_search_actor, sizeof(SEARCHACTOR));
	//	p_search_actor->MaxLevel = MAX_LEVEL;
	//	p_search_actor->Range.Y = 10000.0f;
	//	p_search_actor->MaxRadius = 10000.0f;
	//	p_search_actor->ActorType = AT_NONE;
	//}

	//DWORD ParseSearchActorArg(int arg, int argc, char *argv[], SEARCHACTOR &search_actor)
	//{
	//	if (arg >= argc)
	//		return 0;
	//	DWORD extra_used = 0;
	//	if (!_stricmp(argv[arg], "pc"))
	//	{
	//		search_actor.ActorType = MOB_PC;
	//	}
	//	else if (!_stricmp(argv[arg], "npc"))
	//	{
	//		search_actor.ActorType = MOB_NPC;
	//	}
	//	else if (!_stricmp(argv[arg], "pet"))
	//	{
	//		search_actor.ActorType = MOB_PET;
	//	}
	//	else if (!_stricmp(argv[arg], "level"))
	//	{
	//		if (arg + 1 < argc)
	//		{
	//			search_actor.MinLevel = atoi(argv[arg + 1]);
	//			search_actor.MaxLevel = search_actor.MinLevel;
	//			extra_used = 1;
	//		}
	//	}
	//	else if (!_stricmp(argv[arg], "levels"))
	//	{
	//		if (arg + 2 < argc)
	//		{
	//			search_actor.MinLevel = atoi(argv[arg + 1]);
	//			search_actor.MaxLevel = atoi(argv[arg + 2]);
	//			extra_used = 2;
	//		}
	//	}
	//	return extra_used;
	//}

	//void ParseSearchActor(int begin_inclusive, int end_exclusive, char *argv[], SEARCHACTOR &search_actor)
	//{
	//	for (auto arg = begin_inclusive; arg < end_exclusive; arg++)
	//		arg += ParseSearchActorArg(arg, end_exclusive, argv, search_actor);
	//}

	//bool ActorMatchesSearch(PSEARCHACTOR p_search_actor, actor* p_character, actor* p_actor)
	//{
	//	DWORD actor_type;
	//	if (p_actor->IsPlayer())
	//		actor_type = AT_PC;
	//	else if (p_actor->IsPet() && IsClientId(p_actor->GetMasterId()))
	//		actor_type = AT_MYPET;
	//	else if (p_actor->IsPet())
	//		actor_type = AT_PET;		
	//	else if (p_actor->IsNPC())
	//		actor_type = AT_NPC;
	//	else
	//		actor_type = AT_NONE;
	//	if (p_search_actor->ActorType != AT_NONE &&actor_type != p_search_actor->ActorType)
	//		return false;
	//	//if (p_search_actor->MinLevel && p_actor->GetSkill(ST_LEVEL) > p_search_actor->MinLevel)
	//	//	return false;
	//	//if (p_search_actor->MaxLevel && p_actor->GetSkill(ST_LEVEL) < p_search_actor->MaxLevel)
	//	//	return false;
	//	return true;
	//}

	//actor* NearestActor(PSEARCHACTOR p_search_actor, actor* p_origin, bool include_character)
	//{
	//	if (!p_search_actor || !p_origin)
	//		return nullptr;
	//	auto point_of_origin = p_origin->GetPosition();
	//	std::vector<actor*> v;
	//	P_PLAYFIELD_DIR->GetPlayfield()->GetPlayfieldActors(v);
	//	std::sort(v.begin(), v.end(), dynel::pDynelCompare);
	//	if(include_character)
	//	{
	//		for (auto it = v.begin(); it != v.end(); ++it)
	//		{
	//			if (ActorMatchesSearch(p_search_actor, P_ENGINE_CLIENT_ANARCHY->GetClientChar(), (*it)))
	//				return (*it);
	//		}
	//	}
	//	else
	//	{
	//		for (auto it = v.begin(); it != v.end(); ++it)
	//		{
	//			if (ActorMatchesSearch(p_search_actor, P_ENGINE_CLIENT_ANARCHY->GetClientChar(), (*it)) && !IsClientId((*it)->GetIdentity().Id))
	//				return (*it);
	//		}
	//	}
	//	return nullptr;
	//}



#pragma endregion



#pragma region Lavishscript

	LSTypeDefinition* get_real_type(ao::dynel* pObject)
	{
		if (pObject && pObject->get_identity().type == 50000)
		{
			if (pObject->is_character())
				return pCharacterType;
			if (pObject->is_player())
				return pActorType;	
			if (pObject->is_pet() && is_client_id(pObject->to_actor()->get_master_id()))
				return pPetType;
			if (pObject->is_actor())
				return pActorType;
		}
		return pDynelType;
	}

#pragma endregion

#pragma region Utility

	DWORD get_game_state()
	{
		if (!P_ENGINE_CLIENT_ANARCHY)
			return GAMESTATE_NOT_IN_GAME;
		if (!P_PLAYFIELD_DIR->get_playfield())
			return GAMESTATE_WAITING_FOR_PLAYFIELD;
		if (!P_ENGINE_CLIENT_ANARCHY->get_client_char())
			return GAMESTATE_WAITING_FOR_CLIENT_CHAR;
		return GAMESTATE_IN_GAME;
	}

	void print_to_chat(string message, PCSTR chat_type)
	{
		if(ao::g_game_state == GAMESTATE_IN_GAME)
		{
			string s;
			s = "<font color=\"" + string(chat_type) + "\">" + message + "</font>";
			P_COMMAND_INTERPRETER->parse_text(s);
		}
	}

	void get_arg(char current_arg[MAX_VARSTRING], const int argc, char *argv[], DWORD& arg_num)
	{
		if (arg_num > DWORD(argc))
		{
			sprintf_s(current_arg, sizeof(current_arg), nullptr);
			return;
		}		
		sprintf_s(current_arg, sizeof(current_arg), argv[arg_num]);
	}

#pragma endregion

#pragma region MessageHandling

	void HandleN3Message(internal::PN3MESSAGEINFO message_info)
	{
		auto p = parser(PCHAR(message_info->message), message_info->size);
		const auto n3 = n3_header(p);
		switch(ao::N3MessageType_e(n3.n3_type()))
		{
		case ao::N3T_KNUBOT_NPC_DESCRIPTION: break;
		case ao::N3T_ADD_TEMPLATE: break;
		case ao::N3T_GRID_DESTINATION_SELECT: break;
		case ao::N3T_WEATHER_CONTROL: break;
		case ao::N3T_PET_TO_MASTER:
		{
			break;
		}
		case ao::N3T_FLUSH_RDB_CACHES: break;
		case ao::N3T_SHOP_SEARCH_RESULT: break;
		case ao::N3T_SHOP_SEARCH_REQUEST: break;
		case ao::N3T_ACCEPT_BS_INVITE: break;
		case ao::N3T_ADD_PET:
		{
			if(message_info->size == 0x15)
			{
				const auto a_p_msg = add_pet_message(p);
				HandleAddPetMessage(a_p_msg);
			}			
			break;
		}
		case ao::N3T_SET_POS: break;
		case ao::N3T_REFLECT_ATTACK:
		{
			//printf("0x%.8X", message_info->size);
			break;
		}
		case ao::N3T_SPECIAL_ATTACK_WEAPON: break;
		case ao::N3T_MENTOR_INVITE: break;
		case ao::N3T_ACTION:
		{
			//printf("0x%.8X", message_info->size);
			break;
		}
		case ao::N3T_SCRIPT: break;
		case ao::N3T_FORMAT_FEEDBACK: break;
		case ao::N3T_KNUBOT_ANSWER: break;
		case ao::N3T_QUEST: break;
		case ao::N3T_MINE_FULL_UPDATE: break;
		case ao::N3T_LOOK_AT: break;
		case ao::N3T_SHIELD_ATTACK:
		{
			if(message_info->size == 0x1D)
			{
				auto a1 = p.pop_integer();
				auto a2 = p.pop_integer();
				auto a3 = p.pop_integer();
				auto a4 = p.pop_integer();
				printf("%d %d %d %d", a1, a2, a3, a4);
			}
			//printf("0x%.8X", message_info->size);
			break;
		}
		case ao::N3T_CAST_NANO_SPELL:
		{			
			if(message_info->size == 0x25)
			{
				auto c_n_s_msg = cast_nano_spell_message(p);
				HandleCastNanoSpellMessage(c_n_s_msg);
			}			
			break;
		}
		case ao::N3T_RESEARCH_UPDATE: break;
		case ao::N3T_FOLLOW_TARGET:
		{
			if(message_info->size == 0x28)
			{
				auto f_t_msg = follow_target_message(p);
				HandleFollowTargetMessage(f_t_msg);
			}			
			break;
		}
		case ao::N3T_RELOCATE_DYNELS: break;
		case ao::N3T_ABSORB: break;
		case ao::N3T_RELOAD: break;
		case ao::N3T_KNUBOT_CLOSE_CHAT_WINDOW: break;
		case ao::N3T_SIMPLE_CHAR_FULL_UPDATE: break;
		case ao::N3T_START_LOGOUT: break;
		case ao::N3T_ATTACK:
		{
			if(message_info->size == 0x16)
			{
				auto a_msg = attack_message(p);
				HandleAttackMessage(a_msg);
			}			
			break;
		}
		case ao::N3T_TEAM_MEMBER_INFO: break;
		case ao::N3T_FULL_CHARACTER: break;
		case ao::N3T_LASER_TARGET_LIST: break;
		case ao::N3T_TRAP_DISARMED: break;
		case ao::N3T_FOV: break;
		case ao::N3T_STAT: break;
		case ao::N3T_QUEUE_UPDATE: break;
		case ao::N3T_KNUBOT_REJECTED_ITEMS: break;
		case ao::N3T_PLAYER_SHOP_FULL_UPDATE: break;
		case ao::N3T_ORG_INFO_PACKET: break;
		case ao::N3T_N3_PLAYFIELD_FULL_UPDATE: break;
		case ao::N3T_RESEARCH_REQUEST: break;
		case ao::N3T_AREA_FORMULA: break;
		case ao::N3T_IN_FROM_PLAYER: break;
		case ao::N3T_MAIL: break;
		case ao::N3T_APPLY_SPELLS: break;
		case ao::N3T_BANK: break;
		case ao::N3T_SHOP_INVENTORY: break;
		case ao::N3T_TEMPLATE_ACTION: break;
		case ao::N3T_TRADE: break;
		case ao::N3T_DESPAWN: break;
		case ao::N3T_DOOR_FULL_UPDATE: break;
		case ao::N3T_CITY_ADVANTAGES: break;
		case ao::N3T_HEALTH_DAMAGE: break;
		case ao::N3T_FIGHT_MODE_UPDATE: break;
		case ao::N3T_SET_SHOP_NAME: break;
		case ao::N3T_BUFF: break;
		case ao::N3T_KNUBOT_TRADE: break;
		case ao::N3T_DROP_TEMPLATE: break;
		case ao::N3T_GRID_SELECTED: break;
		case ao::N3T_SIMPLEITEM_FULL_UPDATE: break;
		case ao::N3T_KNUBOT_OPEN_CHAT_WINDOW: break;
		case ao::N3T_WEAPONITEM_FULL_UPDATE: break;
		case ao::N3T_SOCIAL_ACTION_CMD: break;
		case ao::N3T_RAID: break;
		case ao::N3T_SHADOW_LEVEL: break;
		case ao::N3T_CLONE: break;
		case ao::N3T_SHOP_COMMISSION: break;
		case ao::N3T_SERVER_PATH_POS_DEBUG_INFO: break;
		case ao::N3T_SKILL: break;
		case ao::N3T_LEAVE_BATTLE: break;
		case ao::N3T_SHOP_INFO: break;
		case ao::N3T_APPEARANCE_UPDATE: break;
		case ao::N3T_N3_TELEPORT: break;
		case ao::N3T_PERK_UPDATE: break;
		case ao::N3T_SEND_SCORE: break;
		case ao::N3T_RESURRECT: break;
		case ao::N3T_UPDATE_CLIENT_VISUAL: break;
		case ao::N3T_HOUSE_DEMOLISH_START: break;
		case ao::N3T_PLAY_SOUND1: break;
		case ao::N3T_ATTACK_INFO: break;
		case ao::N3T_TEAM_MEMBER: break;
		case ao::N3T_SPAWN_MECH: break;
		case ao::N3T_QUEST_FULL_UPDATE: break;
		case ao::N3T_CHESTITEM_FULL_UPDATE: break;
		case ao::N3T_NANO_ATTACK: break;
		case ao::N3T_DROP_DYNEL: break;
		case ao::N3T_CONTAINER_ADD_ITEM: break;
		case ao::N3T_VISIBILITY: break;
		case ao::N3T_STOP_FIGHT: break;
		case ao::N3T_BATTLE_OVER: break;
		case ao::N3T_INVENTORY_UPDATED: break;
		case ao::N3T_DOOR_STATUS_UPDATE: break;
		case ao::N3T_TEAM_INVITE: break;
		case ao::N3T_SHOP_STATUS: break;
		case ao::N3T_INFO_PACKET: break;
		case ao::N3T_SPELL_LIST: break;
		case ao::N3T_INVENTORY_UPDATE: break;
		case ao::N3T_CORPSE_FULL_UPDATE: break;
		case ao::N3T_FEEDBACK: break;
		case ao::N3T_CHAR_SEC_SPEC_ATTACK: break;
		case ao::N3T_BANK_CORPSE: break;
		case ao::N3T_GENERIC_CMD: break;
		case ao::N3T_PATH_MOVE_CMD: break;
		case ao::N3T_ARRIVE_AT_BS: break;
		case ao::N3T_CHAR_DC_MOVE: break;
		case ao::N3T_PLAYFIELD_ALL_TOWERS: break;
		case ao::N3T_KNUBOT_FINISH_TRADE: break;
		case ao::N3T_KNUBOT_ANSWER_LIST: break;
		case ao::N3T_STOP_LOGOUT: break;
		case ao::N3T_CHAR_IN_PLAY: break;
		case ao::N3T_SHOP_UPDATE: break;
		case ao::N3T_MECH_INFO: break;
		case ao::N3T_REMOVE_PET:
		{
			if (message_info->size == 0x15)
			{
				auto r_p_msg = remove_pet_message(p);
				HandleRemovePetMessage(r_p_msg);
			}			
			break;
		}
		case ao::N3T_PLAYFIELD_ALL_CITIES: break;
		case ao::N3T_TRAPITEM_FULL_UPDATE: break;
		case ao::N3T_INSPECT: break;
		case ao::N3T_PLAYFIELD_TOWER_UPDATE_CLIENT: break;
		case ao::N3T_SERVER_POS_DEBUG_INFO: break;
		case ao::N3T_QUEST_ALTERNATIVE: break;
		case ao::N3T_FULL_AUTO: break;
		case ao::N3T_CHAT_CMD: break;
		case ao::N3T_MISSED_ATTACK_INFO: break;
		case ao::N3T_KNUBOT_APPEND_TEXT: break;
		case ao::N3T_CHARACTER_ACTION:
		{
			if(message_info->size == 0x27)
			{
				auto c_a_msg = character_action_message(p);
				HandleCharacterActionMessage(c_a_msg);
			}			
			break;
		}
		case ao::N3T_HOUSE_DISAPPEARED: break;
		case ao::N3T_IMPULSE: break;
		case ao::N3T_PLAYFIELD_ANARCHY_F: break;
		case ao::N3T_CHAT_TEXT: break;
		case ao::N3T_GAME_TIME: break;
		case ao::N3T_SET_WANTED_DIRECTION: break;
		case ao::N3T_AO_TRANSPORT_SIGNAL: break;
		case ao::N3T_PET_COMMAND: break;
		case ao::N3T_ORG_SERVER: break;
		case ao::N3T_SET_STAT: break;
		case ao::N3T_SET_NAME: break;
		case ao::N3T_STOP_MOVING_CMD: break;
		case ao::N3T_SPECIAL_ATTACK_INFO: break;
		case ao::N3T_GIVE_QUEST_TO_MEMBER: break;
		case ao::N3T_KNUBOT_START_TRADE: break;
		case ao::N3T_GFX_TRIGGER: break;
		case ao::N3T_SHOP_ITEM_PRICE: break;
		case ao::N3T_NEW_LEVEL: break;
		case ao::N3T_ORG_CLIENT: break;
		case ao::N3T_VENDING_MACHINE_FULL_UPDATE: break;
		default: break;
		}
		delete message_info;
	}

	void HandleAddPetMessage(add_pet_message pet_message)
	{
		char pet[MAX_VARSTRING];
		sprintf_s(pet, sizeof(pet), "%I64u",pet_message.identity().combined_identity());
		char *argv[] = { pet };
		pISInterface->ExecuteEvent(events::GetEventId("AO_onAddPet"), 0, 1, argv);
		//delete argv;
	}

	void HandleAttackMessage(attack_message attack_message)
	{
		char target[MAX_VARSTRING];
		sprintf_s(target, sizeof(target), "%I64u", attack_message.target().combined_identity());
		char *argv[] = { target };
		pISInterface->ExecuteEvent(events::GetEventId("AO_onAttack"), 0, 1, argv);
	}

	void HandleCastNanoSpellMessage(cast_nano_spell_message cast_nano_spell_message)
	{
		char nano_id[MAX_VARSTRING];
		char target[MAX_VARSTRING];
		char caster[MAX_VARSTRING];
		sprintf_s(nano_id, sizeof(nano_id), "%d", cast_nano_spell_message.nano_id());
		sprintf_s(target, sizeof(target), "%I64u", cast_nano_spell_message.target().combined_identity());
		sprintf_s(caster, sizeof(caster), "%I64u", cast_nano_spell_message.caster().combined_identity());
		char *argv[] = { nano_id, target, caster };
		pISInterface->ExecuteEvent(events::GetEventId("AO_onCastNanoSpell"), 0, 3, argv);
		if (is_client_id(cast_nano_spell_message.target().id()))
			pISInterface->ExecuteEvent(events::GetEventId("AO_onCastNanoSpell_TargetSelf"), 0, 3, argv);
		else
			pISInterface->ExecuteEvent(events::GetEventId("AO_onCastNanoSpell_TargetOther"), 0, 3, argv);
		if (is_client_id(cast_nano_spell_message.caster().id()))
			pISInterface->ExecuteEvent(events::GetEventId("AO_onCastNanoSpell_CasterSelf"), 0, 3, argv);
		else
			pISInterface->ExecuteEvent(events::GetEventId("AO_onCastNanoSpell_CasterOther"), 0, 3, argv);
	}

	void HandleCharacterActionMessage(character_action_message character_action_message)
	{
		switch (ao::TypeCharacterAction_e(character_action_message.character_action_type()))
		{
		case ao::CAT_FINISH_NANO_CASTING:
		{
			char nano_id[MAX_VARSTRING];
			sprintf_s(nano_id, sizeof(nano_id), "%d", character_action_message.param_2());
			char * argv[] = { nano_id };
			pISInterface->ExecuteEvent(events::GetEventId("AO_onFinishedCastingNano"), 0, 1, argv);
			break;
		}
		case ao::CAT_SET_NANO_DURATION:
		{
			ao::identity_t caster_identity;
			caster_identity.type = 50000;
			caster_identity.id = character_action_message.param_1();
			char nano_id[MAX_VARSTRING];
			sprintf_s(nano_id, sizeof(nano_id), "%d", character_action_message.identity().id());
			char caster_id[MAX_VARSTRING];
			sprintf_s(caster_id, sizeof(caster_id), "%I64u", caster_identity.get_combined_identity());
			char duration[MAX_VARSTRING];
			sprintf_s(duration, sizeof(duration), "%d", character_action_message.param_2());
			char * argv[] = { nano_id, caster_id, duration };
			pISInterface->ExecuteEvent(events::GetEventId("AO_onNanoApplied"), 0, 3, argv);
			break;
		}
		case ao::CAT_STAND_UP:
		{
			pISInterface->ExecuteEvent(events::GetEventId("AO_onStand"));
			break;
		}
		case ao::CAT_TEAM_REQUEST: break;
		case ao::CAT_CAST_NANO: break;
		case ao::CAT_TEAM_REQUEST_REPLY: break;
		case ao::CAT_LEAVE_TEAM: break;
		case ao::CAT_ACCEPT_TEAM_REQUEST: break;
		case ao::CAT_REMOVE_FRIENDLY_NANO: break;
		case ao::CAT_USE_ITEM_ON_ITEM: break;
		case ao::CAT_UNKNOWN_3: break;
		case ao::CAT_INFO_REQUEST: break;
		case ao::CAT_INTERRUPT_NANO_CASTING: break;
		case ao::CAT_DELETE_ITEM: break;
		case ao::CAT_LOGOUT: break;
		case ao::CAT_STOPLOGOUT: break;
		case ao::CAT_EQUIP: break;
		case ao::CAT_STARTED_SNEAKING: break;
		case ao::CAT_START_SNEAK: break;
		case ao::CAT_CHANGE_VISUAL_FLAG: break;
		case ao::CAT_CHANGE_ANIMATION_AND_STANCE: break;
		case ao::CAT_UPLOAD_NANO: break;
		case ao::CAT_TRADESKILL_SOURCE_CHANGED: break;
		case ao::CAT_TRADESKILL_TARGET_CHANGED: break;
		case ao::CAT_TRADESKILL_BUILD_PRESSED: break;
		case ao::CAT_TRADESKILL_SOURCE: break;
		case ao::CAT_TRADESKILL_TARGET: break;
		case ao::CAT_TRADESKILL_NOT_VALID: break;
		case ao::CAT_TRADESKILL_OUT_OF_RANGE: break;
		case ao::CAT_TRADESKILL_REQUIREMENT: break;
		case ao::CAT_TRADESKILL_RESULT: break;
		default: break;
		}
	}

	void HandleFollowTargetMessage(follow_target_message follow_message)
	{
		char target[MAX_VARSTRING];
		sprintf_s(target, sizeof(target), "%I64u", follow_message.target().combined_identity());
		char *argv[] = { target };
		pISInterface->ExecuteEvent(events::GetEventId("AO_onFollowTarget"), 0, 1, argv);
		//delete argv;
	}
	
	void HandleRemovePetMessage(remove_pet_message remove_pet_message)
	{
		char pet[MAX_VARSTRING];
		sprintf_s(pet, sizeof(pet), "%I64u", remove_pet_message.identity().combined_identity());
		char *argv[] = { pet };
		pISInterface->ExecuteEvent(events::GetEventId("AO_onRemovePet"), 0, 1, argv);
		//delete argv;
	}

	void HandleShieldAttackMessage(shield_attack_message shield_attack_message)
	{
		char damage[MAX_VARSTRING];
		char shieldee[MAX_VARSTRING];
		sprintf_s(damage, sizeof(damage), "%d", shield_attack_message.damage_shielded());
		sprintf_s(shieldee, sizeof(shieldee), "%I64u", shield_attack_message.shieldee().combined_identity());
		char *argv[] = { damage, shieldee };
		pISInterface->ExecuteEvent(events::GetEventId("AO_onAttackShielded"), 0, 2, argv);
		//delete argv;
	}

	void HandleGroupMessage(internal::PGROUPMESSAGEINFO group_message_info)
	{
		char* sender = _strdup(group_message_info->SenderName.c_str());
		char* channel = _strdup(group_message_info->ChatChannel.c_str());
		char* message = _strdup(group_message_info->Message.c_str());
		char id[MAX_VARSTRING];
		sprintf_s(id, sizeof(id), "%I64u", group_message_info->SenderIdentity.get_combined_identity());
		char *argv[] = { sender, channel, message, id };
		pISInterface->ExecuteEvent(events::GetEventId("AO_onGroupMessageReceived"), 0, 4, argv);
		delete group_message_info;
	}

	void HandlePrivateMessage(internal::PPRIVATEMESSAGEINFO private_message_info)
	{
		char* sender = _strdup(private_message_info->SenderName.c_str());
		char* message = _strdup(private_message_info->Message.c_str());
		char id[MAX_VARSTRING];
		sprintf_s(id, sizeof(id), "%I64u", private_message_info->SenderIdentity.get_combined_identity());
		char *argv[] = { sender, message, id };
		pISInterface->ExecuteEvent(events::GetEventId("AO_onTellReceived"), 0, 3, argv);
		delete private_message_info;
	}

	void HandleVicinityMessage(internal::PPRIVATEMESSAGEINFO vicinity_message_info)
	{
		char* sender = _strdup(vicinity_message_info->SenderName.c_str());
		char* message = _strdup(vicinity_message_info->Message.c_str());
		char id[MAX_VARSTRING];
		sprintf_s(id, sizeof(id), "%I64u", vicinity_message_info->SenderIdentity.get_combined_identity());
		char *argv[] = { sender, message, id };
		pISInterface->ExecuteEvent(events::GetEventId("AO_onVicinityMessageReceived"), 0, 3, argv);
		delete vicinity_message_info;
	}

	void HandleSystemChat(internal::PSYSTEMCHATINFO system_chat_info)
	{
		char chat_type[MAX_VARSTRING];
		char* text = _strdup(system_chat_info->Text.c_str());
		switch (ao::ChatGroup_e(system_chat_info->ChatType))
		{
		case ao::CG_SYSTEM:
		{
			strcpy_s(chat_type, sizeof(chat_type), "SYSTEM");
			break;
		}
		case ao::CG_VICINITY:
		{
			strcpy_s(chat_type, sizeof(chat_type), "VICINITY");
			break;
		}
		case ao::CG_TELL_MESSAGES:
		{
			strcpy_s(chat_type, sizeof(chat_type), "TELL_MESSAGES");
			break;
		}
		case ao::CG_YOUR_PETS:
		{
			strcpy_s(chat_type, sizeof(chat_type), "YOUR_PETS");
			break;
		}
		case ao::CG_OTHERS_PETS:
		{
			strcpy_s(chat_type, sizeof(chat_type), "OTHERS_PETS");
			break;
		}
		case ao::CG_ME_HIT_BY_ENVIRONMENT:
		{
			strcpy_s(chat_type, sizeof(chat_type), "ME_HIT_BY_ENVIRONMENT");
			break;
		}
		case ao::CG_ME_HIT_BY_NANO:
		{
			strcpy_s(chat_type, sizeof(chat_type), "ME_HIT_BY_NANO");
			break;
		}
		case ao::CG_YOUR_PET_HIT_BY_NANO:
		{
			strcpy_s(chat_type, sizeof(chat_type), "YOUR_PET_HIT_BY_NANO");
			break;
		}
		case ao::CG_OTHER_HIT_BY_NANO:
		{
			strcpy_s(chat_type, sizeof(chat_type), "OTHER_HIT_BY_NANO");
			break;
		}
		case ao::CG_YOU_HIT_OTHER_WITH_NANO:
		{
			strcpy_s(chat_type, sizeof(chat_type), "YOU_HIT_OTHER_WITH_NANO");
			break;
		}
		case ao::CG_ME_HIT_BY_MONSTER:
		{
			strcpy_s(chat_type, sizeof(chat_type), "ME_HIT_BY_MONSTER");
			break;
		}
		case ao::CG_ME_HIT_BY_PLAYER:
		{
			strcpy_s(chat_type, sizeof(chat_type), "ME_HIT_BY_PLAYER");
			break;
		}
		case ao::CG_YOU_HIT_OTHER:
		{
			strcpy_s(chat_type, sizeof(chat_type), "YOU_HIT_OTHER");
			break;
		}
		case ao::CG_YOUR_PET_HIT_BY_OTHER:
		{
			strcpy_s(chat_type, sizeof(chat_type), "YOUR_PET_HIT_BY_OTHER");
			break;
		}
		case ao::CG_OTHER_HIT_BY_OTHER:
		{
			strcpy_s(chat_type, sizeof(chat_type), "OTHER_HIT_BY_OTHER");
			break;
		}
		case ao::CG_ME_GOT_XP:
		{
			strcpy_s(chat_type, sizeof(chat_type), "ME_GOT_XP");
			break;
		}
		case ao::CG_ME_GOT_SK:
		{
			strcpy_s(chat_type, sizeof(chat_type), "ME_GOT_SK");
			break;
		}
		case ao::CG_YOUR_PET_HIT_BY_MONSTER:
		{
			strcpy_s(chat_type, sizeof(chat_type), "YOUR_PET_HIT_BY_MONSTER");
			break;
		}
		case ao::CG_YOUR_MISSES:
		{
			strcpy_s(chat_type, sizeof(chat_type), "YOUR_MISSES");
			break;
		}
		case ao::CG_OTHER_MISSES:
		{
			strcpy_s(chat_type, sizeof(chat_type), "OTHER_MISSES");
			break;
		}
		case ao::CG_YOU_GAVE_HEALTH:
		{
			strcpy_s(chat_type, sizeof(chat_type), "YOU_GAVE_HEALTH");
			break;
		}
		case ao::CG_ME_GOT_HEALTH:
		{
			strcpy_s(chat_type, sizeof(chat_type), "ME_GOT_HEALTH");
			break;
		}
		case ao::CG_ME_GOT_NANO:
		{
			strcpy_s(chat_type, sizeof(chat_type), "ME_GOT_NANO");
			break;
		}
		case ao::CG_YOU_GAVE_NANO:
		{
			strcpy_s(chat_type, sizeof(chat_type), "YOU_GAVE_NANO");
			break;
		}
		case ao::CG_ME_CAST_NANO:
		{
			strcpy_s(chat_type, sizeof(chat_type), "ME_CAST_NANO");
			break;
		}
		case ao::CG_TEAM_LOOT_MESSAGES:
		{
			strcpy_s(chat_type, sizeof(chat_type), "TEAM_LOOT_MESSAGES");
			break;
		}
		case ao::CG_VICINITY_LOOT_MESSAGES:
		{
			strcpy_s(chat_type, sizeof(chat_type), "VICINITY_LOOT_MESSAGES");
			break;
		}
		case ao::CG_RESEARCH:
		{
			strcpy_s(chat_type, sizeof(chat_type), "RESEARCH");
			break;
		}
		default:
			sprintf_s(chat_type, sizeof(chat_type), "%d", system_chat_info->ChatType);
			break;
		}
		char *argv[] = { chat_type, text };
		pISInterface->ExecuteEvent(events::GetEventId("AO_onIncomingSystemText"), 0, 2, argv);
		delete system_chat_info;
	}

#pragma endregion

}
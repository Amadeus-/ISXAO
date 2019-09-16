#include "isxao_main.h"
#include "atlbase.h"
#include "iostream"

namespace isxao_utilities
{

#pragma region Strings

#ifdef F_STAT_TO_STRING_USE_NATIVE
	FUNCTION_AT_ADDRESS(PCSTR stat_to_string(ao_data::stat_e stat_id), f_stat_to_string)
#else
	// ReSharper disable once CppParameterMayBeConst
	PCSTR stat_to_string(ao_data::stat_e stat_id)
	{
		auto result = "NoName";
		std::map<stat_e, PCSTR> m;
		get_stat_name_map(m);
		if (m.count(stat_id))
			result = m.find(stat_id)->second;
		return result;
	}
#endif

	// ReSharper disable once CppParameterMayBeConst
	PCSTR get_breed_str_local(breed_e breed_id)
	{
		switch(breed_id)
		{
		case BT_NOTHING:
			return "Nothing";
		case BT_SOLITUS:
			return "Solitus";
		case BT_OPIFEX:
			return "Opifex";
		case BT_NANOMAGE:
			return "Nanomage";
		case BT_ATROX:
			return "Atrox";
		case BT_SPECIAL:
			return "Special";
		case BT_MONSTER:
			return "Monster";
		case BT_HUMAN_MONSTER: 
			return "human monster";
		default:			
			char buffer[MAX_VARSTRING];
			sprintf_s(buffer, sizeof(buffer), "Missing breed: %d", DWORD(breed_id));
			return PCSTR(pISInterface->GetTempBuffer(sizeof(buffer), buffer));
		}
	}

	// ReSharper disable once CppParameterMayBeConst
	PCSTR get_sex_str_local(gender_e gender_id)
	{
		switch(gender_id)
		{
		case GT_NONE:
			return "NONE";
		case GT_UNI: 
			return "uni";
		case GT_MALE: 
			return "male";
		case GT_FEMALE: 
			return "female";
		default:
			char buffer[MAX_VARSTRING];
			sprintf_s(buffer, sizeof(buffer), "Missing sex: %d", DWORD(gender_id));
			return PCSTR(pISInterface->GetTempBuffer(sizeof(buffer), buffer));
		}
	}

	PCSTR GetProfessionStr(DWORD prof)
	{
		switch (prof)
		{
		case PT_NONE:
			return "None";
		case PT_SOLDIER:
			return "Soldier";
		case PT_MARTIALARTIST:
			return "Martial Artist";
		case PT_ENGINEER:
			return "Engineer";
		case PT_FIXER:
			return "Fixer";
		case PT_AGENT:
			return "Agent";
		case PT_ADVENTURER:
			return "Adventurer";
		case PT_TRADER:
			return "Trader";
		case PT_BUREAUCRAT:
			return "Bureaucrat";
		case PT_ENFORCER:
			return "Enforcer";
		case PT_DOCTOR:
			return "Doctor";
		case PT_NANOTECHNICIAN:
			return "Nano Technician";
		case PT_METAPHYSICIST:
			return "Meta-Physicist";
		case PT_MONSTER:
			return "Monster";
		case PT_KEEPER:
			return "Keeper";
		case PT_SHADE:
			return "Shade";
		default:
			return "Unknown";
		}
	}

	PCSTR GetSideStr(DWORD side)
	{
		switch (side)
		{
		case SD_NEUTRAL:
			return "Neutral";
		case SD_CLAN:
			return "Clan";
		case SD_OMNI:
			return "Omni";
		case SD_MONSTER:
			return "Monster";
		case SD_ADVISOR:
			return "Advisor";
		case SD_GUARDIAN:
			return "Guardian";
		case SD_GM:
			return "GM";
		case SD_MIXED:
			return "Mixed";
		default:
			return "Unknown";
		}
	}

	

	PCSTR GetNanoSchoolStr(DWORD school)
	{
		auto result = "Unknown";
		switch(school)
		{
		case 1:
			result = "Combat";
			break;
		case 2:
			result = "Medical";
			break;
		case 3:
			result = "Protection";
			break;
		case 4:
			result = "Psi";
			break;
		case 5:
			result = "Space";
			break;
		default:
			break;
		}
		return result;
	}

	PCSTR GetItemRarityStr(DWORD rarity)
	{
		PCSTR result = "Unknown";
		switch(rarity)
		{
		case 1:
			result = "Trash";
			break;
		case 2:
			result = "Normal";
			break;
		case 3:
			result = "Exotic";
			break;
		case 4:
			result = "Quest";
			break;
		case 5:
			result = "Social";
			break;
		default:
			break;
		}
		return result;
	}


#pragma endregion

#pragma region Objects

	FUNCTION_AT_ADDRESS(dynel* __cdecl GetDynel(const identity_t &), n3_dynel_t__get_dynel);
	FUNCTION_AT_ADDRESS(actor* __cdecl GetActor(const identity_t &), n3_dynel_t__get_dynel);

#ifdef __GetFullPerkMap_x
	FUNCTION_AT_ADDRESS(DWORD __cdecl GetFullPerkMap(void), __N3Msg_GetFullPerkMap);
#endif

#ifdef F_GET_NANO_ITEM_USE_NATIVE
	FUNCTION_AT_ADDRESS(p_nano_item_t get_nano_item(DWORD), f_get_nano_item)
#else
	tatic_assert(false, "get_nano_item(DWORD) requires a native function.");
#endif

	bool IsValidDynel(p_n3_dynel_t pDynel)
	{
		if (pDynel && pDynel->p_v_table)
		{
			auto d = DWORD(pDynel->p_v_table);
			if (d < DWORD(gamecode_module_handle) || d > DWORD(gamecode_module_handle + GetModuleInfo("Gamecode.dll").SizeOfImage))
				return false;
			if (d == AccessCard_t__vTable || d == CentralController_t__vTable || d == Chest_t__vTable || d == CityTerminal_t__vTable ||
				d == Corpse_t__vTable || d == Door_t__vTable || d == LockableItem_t__vTable || d == Mine_t__vTable ||
				d == PlayerShop_t__vTable || d == QuestBooth_t__vTable || d == ReclaimBooth_t__vTable || d == SimpleChar_t__vTable ||
				d == SimpleItem_t__vTable || d == TrapItem_t__vTable || d == VendingMachine_t__vTable || d == Weapon_t__vTable ||
				d == WearableItem_t__vTable)
				return true;
		}
		return false;
	}

	PVOID RequestInfo(const identity_t &id)
	{
		typedef PVOID(__thiscall * tRequestInfo)(special_action_holder*, const identity_t&);
		auto pLookAt = tRequestInfo(__RequestInfo);
		return pLookAt(P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_special_action_holder(), id);
	}

#pragma endregion

#pragma region SearchActor

	DWORD ParseSearchActorArg(int arg, int argc, char *argv[], SEARCHACTOR &search_actor)
	{
		if (arg >= argc)
			return 0;
		DWORD ExtraUsed = 0;
		{
			if (!_stricmp(argv[arg], "pc"))
			{
				search_actor.actor_type = MOB_PC;
			}
			else if (!_stricmp(argv[arg], "npc"))
			{
				search_actor.actor_type = MOB_NPC;
			}
			else if (!_stricmp(argv[arg], "pet"))
			{
				search_actor.actor_type = MOB_PET;
			}
			else if (!_stricmp(argv[arg], "mypet"))
			{
				search_actor.actor_type = MOB_MYPET;
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

	void ClearSearchActor(PSEARCHACTOR p_search_actor)
	{
		if (!p_search_actor) return;
		ZeroMemory(p_search_actor, sizeof(SEARCHACTOR));
		p_search_actor->max_level = MAX_LEVEL;
		p_search_actor->y_radius = 10000.0f;
		p_search_actor->f_radius = 10000.0f;
	}

	void ParseSearchActor(int begin_inclusive, int end_exclusive, char *argv[], SEARCHACTOR &search_actor)
	{
		for (int arg = begin_inclusive; arg < end_exclusive; arg++)
			arg += ParseSearchActorArg(arg, end_exclusive, argv, search_actor);
	}

	bool ActorMatchesSearch(PSEARCHACTOR p_search_actor, actor* p_character, actor* p_actor)
	{
		char szName[MAX_STRING] = { 0 };
		char szSearchName[MAX_STRING] = { 0 };
		DWORD actor_type;
		if (p_actor->get_identity().type != 50000)
			actor_type = MOB_OTHER;
		else if (p_actor->is_actor())
		{
			if (p_actor->is_pet() && IsClientId(p_actor->get_master_id()))
				actor_type = MOB_MYPET;
			else if (p_actor->is_pet())
				actor_type = MOB_PET;
			else
				actor_type = MOB_NPC;
		}
		else
			actor_type = MOB_PC;
		if (p_search_actor->actor_type != actor_type && p_search_actor->actor_type != MOB_NONE)
			return false;
		strcpy_s(szName, MAX_STRING, p_actor->get_name());
		_strlwr_s(szName);
		strcpy_s(szSearchName, MAX_STRING, p_search_actor->name);
		_strlwr_s(szSearchName);
		if (!strstr(szName, szSearchName))
			return false;
		if (p_search_actor->min_level && DWORD(p_actor->get_skill(ST_LEVEL)) < p_search_actor->min_level)
			return false;
		if (p_search_actor->max_level && DWORD(p_actor->get_skill(ST_LEVEL)) > p_search_actor->max_level)
			return false;
		if (p_search_actor->not_id == p_actor->get_identity().get_combined_identity())
			return false;
		if (p_search_actor->is_dynel_id && p_search_actor->actor_id != p_actor->get_identity().get_combined_identity())
			return false;
		if (p_search_actor->is_known_location)
		{
			if (p_search_actor->x_loc != p_actor->get_position().x || p_search_actor->z_loc != p_actor->get_position().z)
			{
				vector3_t knownLoc;
				knownLoc.x = p_search_actor->x_loc;
				knownLoc.y = 0.0f;
				knownLoc.z = p_search_actor->z_loc;
				if (p_search_actor->f_radius < 10000.0f && p_actor->get_distance_to(knownLoc) > p_search_actor->f_radius)
					return false;
			}
		}
		if (p_search_actor->radius > 0.0f && IsPCNear(p_actor, p_search_actor->radius))
			return false;
		if (g_y_filter < 10000.0f)
		{
			vector3_t client = p_character->get_position();
			if (p_actor->get_position().y > client.y + g_y_filter || p_actor->get_position().y < client.y - g_y_filter)
				return false;
		}
		if (p_search_actor->y_radius < 10000.0f)
		{
			vector3_t client = p_character->get_position();
			if (p_actor->get_position().y > client.y + p_search_actor->y_radius || p_actor->get_position().y < client.y - p_search_actor->y_radius)
				return false;
		}
		return true;
	}

	bool IsPCNear(actor* p_actor, float radius)
	{
		actor* p_close_actor = nullptr;
		if (P_ENGINE_CLIENT_ANARCHY)
		{
			std::vector<actor*> v;
			P_PLAYFIELD_DIR->GetPlayfield()->GetPlayfieldActors(v);
			for (auto it = v.begin(); it != v.end(); ++it)
			{
				if ((*it)->get_identity().type == 50000 && !P_ENGINE_CLIENT_ANARCHY->n3_msg_is_npc((*it)->get_identity()))
				{
					if ((*it) != p_actor)
					{
						vector3_t c = (*it)->get_position();
						if (p_actor->get_distance_to(c) < radius)
							return true;
					}
				}
			}
		}
		return false;
	}

	DWORD CountMatchingActors(PSEARCHACTOR p_search_actor, actor* p_character, bool include_char)
	{
		if (!p_search_actor || !p_character)
			return 0;
		DWORD total_matching = 0;
		std::vector<actor*> v;
		P_PLAYFIELD_DIR->GetPlayfield()->GetPlayfieldActors(v);
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

	actor* NthNearestActor(PSEARCHACTOR p_search_actor, DWORD nth, actor* p_origin, bool include_char)
	{
		if (!p_search_actor || !nth || !p_origin)
			return nullptr;
		CIndex<PAORANK> actor_set;
		vector3_t pos = p_origin->get_position();
		std::vector<actor*> v;
		P_PLAYFIELD_DIR->GetPlayfield()->GetPlayfieldActors(v);
		DWORD TotalMatching = 0;
		if (include_char)
		{
			for (auto it = v.begin(); it != v.end(); ++it)
			{
				if (ActorMatchesSearch(p_search_actor, p_origin, *it))
				{
					TotalMatching++;
					PAORANK pNewRank = new AORANK;
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
					PAORANK pNewRank = new AORANK;
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
		std::sort(&actor_set.List[0], &actor_set[0] + TotalMatching, pAORankFloatCompare);
		auto p_actor = static_cast<actor*>(actor_set[nth - 1]->VarPtr.Ptr);
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

#pragma region Collections
	
	void RecursiveAddPerkToPerkMap(std::map<identity_t, DWORD>& m, p_perk_node_t pNode, p_perk_root_t pRoot, DWORD& count)
	{
		m.insert_or_assign(pNode->perk_identity, pNode->perk_id);
		count--;
		if (reinterpret_cast<PVOID>(pNode->p_lower) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddPerkToPerkMap(m, pNode->p_lower, pRoot, count);
		if (reinterpret_cast<PVOID>(pNode->p_higher) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddPerkToPerkMap(m, pNode->p_higher, pRoot, count);
	}

	void GetPerkMap(std::map<identity_t, DWORD>& m, p_perk_dir_t pDir)
	{
		auto count = pDir->count;
		auto pRoot = pDir->p_root;
		auto pNode = pRoot->p_node;
		if (count > 0)
			RecursiveAddPerkToPerkMap(m, pNode, pRoot, count);
	}

	void RecursiveAddPetToPetMap(std::map<identity_t, DWORD>& m, p_pet_node_t pNode, p_pet_root_t pRoot, DWORD& count)
	{
		m.insert_or_assign(pNode->identity, pNode->index);
		count--;
		if (reinterpret_cast<PVOID>(pNode->p_lower) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddPetToPetMap(m, pNode->p_lower, pRoot, count);
		if (reinterpret_cast<PVOID>(pNode->p_higher) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddPetToPetMap(m, pNode->p_higher, pRoot, count);
	}

	void GetPetMap(std::map<identity_t, DWORD>& m, p_pet_dir_t pPetDir)
	{
		auto count = pPetDir->count;
		auto pRoot = pPetDir->p_root;
		auto pNode = pRoot->p_node;
		if (count > 0)
			RecursiveAddPetToPetMap(m, pNode, pRoot, count);
	}

	void get_nano_map(std::map<DWORD, p_nano_item_t>& m)
	{
		if (P_NANO_ITEM_MAP)
		{
			P_NANO_ITEM_MAP->copy_map(m);
		}
	}

	void get_stat_name_map(std::map<stat_e, PCSTR>& m)
	{
		if (P_STAT_NAME_MAP)
		{
			P_STAT_NAME_MAP->copy_map(m);
		}
	}

	void GetStaticItemMap(std::map<identity_t, p_dummy_item_base_t>& m)
	{
		auto count = P_STATIC_ITEM_VECTOR->size();
		for (DWORD i = 0; i < count; i++)
		{
			if (P_STATIC_ITEM_VECTOR->at(i).p_dummy_item)
				m.insert_or_assign(P_STATIC_ITEM_VECTOR->at(i).p_dummy_item->identity, P_STATIC_ITEM_VECTOR->at(i).p_dummy_item);
		}
	}

	void RecursiveAddStatToStatMap(std::map<DWORD, LONG>& m, p_stat_node_t pNode, p_stat_root_t pRoot, DWORD& count)
	{
		m.insert_or_assign(pNode->stat, pNode->modifier);
		count--;
		if (reinterpret_cast<PVOID>(pNode->p_lower) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddStatToStatMap(m, pNode->p_lower, pRoot, count);
		if (reinterpret_cast<PVOID>(pNode->p_higher) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddStatToStatMap(m, pNode->p_higher, pRoot, count);
	}

	void GetStatMap(std::map<DWORD, LONG>& m, p_stat_dir_t pDir)
	{
		auto count = pDir->count;
		auto pRoot = pDir->p_root;
		auto pNode = pRoot->p_node;
		if (count > 0)
			RecursiveAddStatToStatMap(m, pNode, pRoot, count);
	}

	void RecursiveAddWeaponItemToWeaponItemMap(std::map<DWORD, p_weapon_item_t>& m, p_weapon_item_node_t pNode, p_weapon_item_root_t pRoot, DWORD& count)
	{
		m.insert_or_assign(pNode->action_id, pNode->p_weapon_item);
		count--;
		if (reinterpret_cast<PVOID>(pNode->p_lower) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddWeaponItemToWeaponItemMap(m, pNode->p_lower, pRoot, count);
		if (reinterpret_cast<PVOID>(pNode->p_higher) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddWeaponItemToWeaponItemMap(m, pNode->p_higher, pRoot, count);
	}

	void GetWeaponItemMap(std::map<DWORD, p_weapon_item_t>& m, weapon_item_dir_t& dir)
	{
		auto count = dir.count;
		auto pRoot = dir.p_root;
		auto pNode = pRoot->p_node;
		if (count > 0)
			RecursiveAddWeaponItemToWeaponItemMap(m, pNode, pRoot, count);
	}

	void RecursiveAddChatWindowNodeToChatWindowNodeMap(std::map<string, chat_window_node*>& m, p_chat_window_node_node_t pNode, p_chat_window_node_root_t pRoot, DWORD& count)
	{
		m.insert_or_assign(pNode->window_name, reinterpret_cast<chat_window_node*>(pNode->p_chat_window));
		count--;
		if (reinterpret_cast<PVOID>(pNode->p_lower) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddChatWindowNodeToChatWindowNodeMap(m, pNode->p_lower, pRoot, count);
		if (reinterpret_cast<PVOID>(pNode->p_higher) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddChatWindowNodeToChatWindowNodeMap(m, pNode->p_higher, pRoot, count);
	}

	void GetChatWindowNodeMap(std::map<string, chat_window_node*>& m, chat_window_node_dir_t &dir)
	{
		auto count = dir.count;
		auto pRoot = dir.p_root;
		auto pNode = pRoot->p_node;
		if (count > 0)
			RecursiveAddChatWindowNodeToChatWindowNodeMap(m, pNode, pRoot, count);
	}

	void RecursiveAddLockIdToLockIdMap(std::map<DWORD, DWORD>& m, p_lock_id_node_t pNode, p_lock_id_root_t pRoot, DWORD& count)
	{
		m.insert_or_assign(pNode->lock_id, pNode->action_id);
		count--;
		if (reinterpret_cast<PVOID>(pNode->p_lower) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddLockIdToLockIdMap(m, pNode->p_lower, pRoot, count);
		if (reinterpret_cast<PVOID>(pNode->p_higher) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddLockIdToLockIdMap(m, pNode->p_higher, pRoot, count);
	}

	void GetLockIdMap(std::map<DWORD, DWORD>& m, p_lock_id_dir_t pDir)
	{
		auto count = pDir->count;
		auto pRoot = pDir->p_root;
		auto pNode = pRoot->p_node;
		if (count > 0)
			RecursiveAddLockIdToLockIdMap(m, pNode, pRoot, count);
	}

#pragma endregion

#pragma region Inventory

	bool GetInvSlotIdentity(ao_data::ArmorSlot_e slot, identity_t& id)
	{
		id.type = 102;
		switch (slot)
		{
		case AS_NECK:
		case AS_HEAD:
		case AS_BACK:
		case AS_R_SHOULDER:
		case AS_CHEST:
		case AS_L_SHOULDER:
		case AS_R_ARM:
		case AS_HANDS:
		case AS_L_ARM:
		case AS_R_WRIST:
		case AS_LEGS:
		case AS_L_WRIST:
		case AS_R_FINGER:
		case AS_FEET:
		case AS_L_FINGER:
			id.id = DWORD(slot) + 16;
			break;
		default:
			return false;;
		}
		return true;
	}

	bool GetInvSlotIdentity(ao_data::ImplantSlot_e slot, identity_t& id)
	{
		id.type = 103;
		switch (slot)
		{
		case IS_EYES:
		case IS_HEAD:
		case IS_EARS:
		case IS_R_ARM:
		case IS_CHEST:
		case IS_L_ARM:
		case IS_R_WRIST:
		case IS_WAIST:
		case IS_L_WRIST:
		case IS_R_HAND:
		case IS_LEGS:
		case IS_L_HAND:
		case IS_FEET:
			id.id = DWORD(slot) + 32;
			break;
		default:
			return false;
		}
		return true;
	}

	bool GetInvSlotIdentity(ao_data::WeaponSlot_e slot, identity_t& id)
	{
		id.type = 101;
		switch (slot)
		{
		case WS_HUD_1:
		case WS_HUD_3:
		case WS_UTIL_1:
		case WS_UTIL_2:
		case WS_UTIL_3:
		case WS_R_HAND:
		case WS_BELT:
		case WS_L_HAND:
		case WS_NCU_1:
		case WS_NCU_2:
		case WS_NCU_3:
		case WS_NCU_4:
		case WS_NCU_5:
		case WS_NCU_6:
		case WS_HUD_2:
			id.id = DWORD(slot);
			break;
		default:
			return false;
		}
		return true;
	}

	bool GetInvSlotIdentity(DWORD slot, identity_t& id)
	{
		id.id = slot;
		switch (slot)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			id.type = 101;
			break;
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 22:
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
			id.type = 102;
			break;
		case 33:
		case 34:
		case 35:
		case 36:
		case 37:
		case 38:
		case 39:
		case 40:
		case 41:
		case 42:
		case 43:
		case 44:
		case 45:
			id.type = 103;
			break;
		case 64:
		case 65:
		case 66:
		case 67:
		case 68:
		case 69:
		case 70:
		case 71:
		case 72:
		case 73:
		case 74:
		case 75:
		case 76:
		case 77:
		case 78:
		case 79:
		case 80:
		case 81:
		case 82:
		case 83:
		case 84:
		case 85:
		case 86:
		case 87:
		case 88:
		case 89:
		case 90:
		case 91:
		case 92:
		case 93:
		case 94:
			id.type = 104;
			break;
		default:
			return false;
		}
		return true;
	}

	PCSTR GetInvSlotName(const identity_t& slot)
	{
		switch (slot.type)
		{
		case 101:
		{
			switch (slot.id)
			{
			case 1:
				return "WS_HUD1";
			case 2:
				return "WS_HUD3";
			case 3:
				return "WS_UTIL1";
			case 4:
				return "WS_UTIL2";
			case 5:
				return "WS_UTIL3";
			case 6:
				return "WS_RHAND";
			case 7:
				return "WS_BELT";
			case 8:
				return "WS_LHAND";
			case 9:
				return "WS_NCU1";
			case 10:
				return "WS_NCU2";
			case 11:
				return "WS_NCU3";
			case 12:
				return "WS_NCU4";
			case 13:
				return "WS_NCU5";
			case 14:
				return "WS_NCU6";
			case 15:
				return "WS_HUD2";
			default:
				return "Unknown";
			}
		}
		case 102:
		{
			switch (slot.id - 16)
			{
			case 1:
				return "AS_NECK";
			case 2:
				return "AS_HEAD";
			case 3:
				return "AS_BACK";
			case 4:
				return "AS_RSHOULDER";
			case 5:
				return "AS_CHEST";
			case 6:
				return "AS_LSHOULDER";
			case 7:
				return "AS_RARM";
			case 8:
				return "AS_HANDS";
			case 9:
				return "AS_LARM";
			case 10:
				return "AS_RWRIST";
			case 11:
				return "AS_LEGS";
			case 12:
				return "AS_LWRIST";
			case 13:
				return "AS_RFINGER";
			case 14:
				return "AS_FEET";
			case 15:
				return "AS_LFINGER";
			default:
				return "Unknown";
			}
		}
		case 103:
		{
			switch (slot.id - 32)
			{
			case 1:
				return "IS_EYES";
			case 2:
				return "IS_HEAD";
			case 3:
				return "IS_EARS";
			case 4:
				return "IS_RARM";
			case 5:
				return "IS_CHEST";
			case 6:
				return "IS_LARM";
			case 7:
				return "IS_RWRIST";
			case 8:
				return "IS_WAIST";
			case 9:
				return "IS_LWRIST";
			case 10:
				return "IS_RHAND";
			case 11:
				return "IS_LEGS";
			case 12:
				return "IS_LHAND";
			case 13:
				return "IS_FEET";
			default:
				return "Unknown";
			}
		}
		case 104:
		{
			switch (slot.id - 63)
			{
			case 1:
				return "GI_64";
			case 2:
				return "GI_65";
			case 3:
				return "GI_66";
			case 4:
				return "GI_67";
			case 5:
				return "GI_68";
			case 6:
				return "GI_69";
			case 7:
				return "GI_70";
			case 8:
				return "GI_71";
			case 9:
				return "GI_72";
			case 10:
				return "GI_73";
			case 11:
				return "GI_74";
			case 12:
				return "GI_75";
			case 13:
				return "GI_76";
			case 14:
				return "GI_77";
			case 15:
				return "GI_78";
			case 16:
				return "GI_79";
			case 17:
				return "GI_80";
			case 18:
				return "GI_81";
			case 19:
				return "GI_82";
			case 20:
				return "GI_83";
			case 21:
				return "GI_84";
			case 22:
				return "GI_85";
			case 23:
				return "GI_86";
			case 24:
				return "GI_87";
			case 25:
				return "GI_88";
			case 26:
				return "GI_89";
			case 27:
				return "GI_90";
			case 28:
				return "GI_91";
			case 29:
				return "GI_92";
			case 30:
				return "GI_93";
			}
		}
		default:
			break;
		}
		return "Unknown";
	}

	bool GetInvSlotIdentity(PCSTR slot_name, identity_t &id)
	{
		char search_name[MAX_STRING];
		strcpy_s(search_name, MAX_STRING, slot_name);
		_strlwr_s(search_name);
		if (!strcmp(search_name, "ws_hud1"))
			GetInvSlotIdentity(::WS_HUD_1, id);
		else if (!strcmp(search_name, "ws_hud2"))
			GetInvSlotIdentity(::WS_HUD_2, id);
		else if (!strcmp(search_name, "ws_hud3"))
			GetInvSlotIdentity(::WS_HUD_3, id);
		else if (!strcmp(search_name, "ws_util1"))
			GetInvSlotIdentity(::WS_UTIL_1, id);
		else if (!strcmp(search_name, "ws_util2"))
			GetInvSlotIdentity(::WS_UTIL_2, id);
		else if (!strcmp(search_name, "ws_util3"))
			GetInvSlotIdentity(::WS_UTIL_3, id);
		else if (!strcmp(search_name, "ws_rhand"))
			GetInvSlotIdentity(::WS_R_HAND, id);
		else if (!strcmp(search_name, "ws_belt"))
			GetInvSlotIdentity(::WS_BELT, id);
		else if (!strcmp(search_name, "ws_lhand"))
			GetInvSlotIdentity(::WS_L_HAND, id);
		else if (!strcmp(search_name, "ws_ncu1"))
			GetInvSlotIdentity(::WS_NCU_1, id);
		else if (!strcmp(search_name, "ws_ncu2"))
			GetInvSlotIdentity(::WS_NCU_2, id);
		else if (!strcmp(search_name, "ws_ncu3"))
			GetInvSlotIdentity(::WS_NCU_3, id);
		else if (!strcmp(search_name, "ws_ncu4"))
			GetInvSlotIdentity(::WS_NCU_4, id);
		else if (!strcmp(search_name, "ws_ncu5"))
			GetInvSlotIdentity(::WS_NCU_5, id);
		else if (!strcmp(search_name, "ws_ncu6"))
			GetInvSlotIdentity(::WS_NCU_6, id);
		else if (!strcmp(search_name, "as_neck"))
			GetInvSlotIdentity(::AS_NECK, id);
		else if (!strcmp(search_name, "as_head"))
			GetInvSlotIdentity(::AS_HEAD, id);
		else if (!strcmp(search_name, "as_back"))
			GetInvSlotIdentity(::AS_BACK, id);
		else if (!strcmp(search_name, "as_rshoulder"))
			GetInvSlotIdentity(::AS_R_SHOULDER, id);
		else if (!strcmp(search_name, "as_chest"))
			GetInvSlotIdentity(::AS_CHEST, id);
		else if (!strcmp(search_name, "as_lshoulder"))
			GetInvSlotIdentity(::AS_L_SHOULDER, id);
		else if (!strcmp(search_name, "as_rarm"))
			GetInvSlotIdentity(::AS_R_ARM, id);
		else if (!strcmp(search_name, "as_hands"))
			GetInvSlotIdentity(::AS_HANDS, id);
		else if (!strcmp(search_name, "as_larm"))
			GetInvSlotIdentity(::AS_L_ARM, id);
		else if (!strcmp(search_name, "as_rwrist"))
			GetInvSlotIdentity(::AS_R_WRIST, id);
		else if (!strcmp(search_name, "as_legs"))
			GetInvSlotIdentity(::AS_LEGS, id);
		else if (!strcmp(search_name, "as_lwrist"))
			GetInvSlotIdentity(::AS_L_WRIST, id);
		else if (!strcmp(search_name, "as_rfinger"))
			GetInvSlotIdentity(::AS_R_FINGER, id);
		else if (!strcmp(search_name, "as_feet"))
			GetInvSlotIdentity(::AS_FEET, id);
		else if (!strcmp(search_name, "as_lfinger"))
			GetInvSlotIdentity(::AS_L_FINGER, id);
		else if (!strcmp(search_name, "is_eyes"))
			GetInvSlotIdentity(::IS_EYES, id);
		else if (!strcmp(search_name, "is_head"))
			GetInvSlotIdentity(::IS_HEAD, id);
		else if (!strcmp(search_name, "is_ears"))
			GetInvSlotIdentity(::IS_EARS, id);
		else if (!strcmp(search_name, "is_rarm"))
			GetInvSlotIdentity(::IS_R_ARM, id);
		else if (!strcmp(search_name, "is_chest"))
			GetInvSlotIdentity(::IS_CHEST, id);
		else if (!strcmp(search_name, "is_larm"))
			GetInvSlotIdentity(::IS_L_ARM, id);
		else if (!strcmp(search_name, "is_rwrist"))
			GetInvSlotIdentity(::IS_R_WRIST, id);
		else if (!strcmp(search_name, "is_waist"))
			GetInvSlotIdentity(::IS_WAIST, id);
		else if (!strcmp(search_name, "is_lwrist"))
			GetInvSlotIdentity(::IS_L_WRIST, id);
		else if (!strcmp(search_name, "is_rhand"))
			GetInvSlotIdentity(::IS_R_HAND, id);
		else if (!strcmp(search_name, "is_legs"))
			GetInvSlotIdentity(::IS_LEGS, id);
		else if (!strcmp(search_name, "is_lhand"))
			GetInvSlotIdentity(::IS_L_HAND, id);
		else if (!strcmp(search_name, "is_feet"))
			GetInvSlotIdentity(::IS_FEET, id);
		else if (!strcmp(search_name, "gi_64"))
			GetInvSlotIdentity(64, id);
		else if (!strcmp(search_name, "gi_65"))
			GetInvSlotIdentity(65, id);
		else if (!strcmp(search_name, "gi_66"))
			GetInvSlotIdentity(66, id);
		else if (!strcmp(search_name, "gi_67"))
			GetInvSlotIdentity(67, id);
		else if (!strcmp(search_name, "gi_68"))
			GetInvSlotIdentity(68, id);
		else if (!strcmp(search_name, "gi_69"))
			GetInvSlotIdentity(69, id);
		else if (!strcmp(search_name, "gi_70"))
			GetInvSlotIdentity(70, id);
		else if (!strcmp(search_name, "gi_71"))
			GetInvSlotIdentity(71, id);
		else if (!strcmp(search_name, "gi_72"))
			GetInvSlotIdentity(72, id);
		else if (!strcmp(search_name, "gi_73"))
			GetInvSlotIdentity(73, id);
		else if (!strcmp(search_name, "gi_74"))
			GetInvSlotIdentity(74, id);
		else if (!strcmp(search_name, "gi_75"))
			GetInvSlotIdentity(75, id);
		else if (!strcmp(search_name, "gi_76"))
			GetInvSlotIdentity(76, id);
		else if (!strcmp(search_name, "gi_77"))
			GetInvSlotIdentity(77, id);
		else if (!strcmp(search_name, "gi_78"))
			GetInvSlotIdentity(78, id);
		else if (!strcmp(search_name, "gi_79"))
			GetInvSlotIdentity(79, id);
		else if (!strcmp(search_name, "gi_80"))
			GetInvSlotIdentity(80, id);
		else if (!strcmp(search_name, "gi_81"))
			GetInvSlotIdentity(81, id);
		else if (!strcmp(search_name, "gi_82"))
			GetInvSlotIdentity(82, id);
		else if (!strcmp(search_name, "gi_83"))
			GetInvSlotIdentity(83, id);
		else if (!strcmp(search_name, "gi_84"))
			GetInvSlotIdentity(84, id);
		else if (!strcmp(search_name, "gi_85"))
			GetInvSlotIdentity(85, id);
		else if (!strcmp(search_name, "gi_86"))
			GetInvSlotIdentity(86, id);
		else if (!strcmp(search_name, "gi_87"))
			GetInvSlotIdentity(87, id);
		else if (!strcmp(search_name, "gi_88"))
			GetInvSlotIdentity(88, id);
		else if (!strcmp(search_name, "gi_89"))
			GetInvSlotIdentity(89, id);
		else if (!strcmp(search_name, "gi_90"))
			GetInvSlotIdentity(90, id);
		else if (!strcmp(search_name, "gi_91"))
			GetInvSlotIdentity(91, id);
		else if (!strcmp(search_name, "gi_92"))
			GetInvSlotIdentity(92, id);
		else if (!strcmp(search_name, "gi_93"))
			GetInvSlotIdentity(93, id);
		else if (!strcmp(search_name, "gi_94"))
			GetInvSlotIdentity(94, id);
		if (id.type != 0)
			return true;
		return false;
	}

	p_inventory_data_t GetInvSlotData(inventory_slot_t *slot)
	{
		return P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_inventory_holder()->get_inventory_holder_data().p_regular_inventory->p_inventory_data[slot->slot_id.id];
	}

#pragma endregion

#pragma region Lavishscript

	LSTypeDefinition* GetRealType(dynel* pObject)
	{
		if (pObject && pObject->get_identity().type == 50000)
		{
			if (pObject->is_character())
				return pCharacterType;
			if (pObject->is_player())
				return pActorType;	
			if (pObject->is_pet() && isxao_inlines::IsClientId(pObject->to_actor()->get_master_id()))
				return pPetType;
			if (pObject->is_actor())
				return pActorType;
		}
		return pDynelType;
	}

#pragma endregion

#pragma region Utility

	DWORD GetGameState()
	{
		if (!P_ENGINE_CLIENT_ANARCHY)
			return GAMESTATE_NOT_IN_GAME;
		//if (!P_PLAYFIELD_DIR->GetPlayfield())
		//	return GAMESTATE_WAITING_FOR_PLAYFIELD;
		if (!P_ENGINE_CLIENT_ANARCHY->get_client_char())
			return GAMESTATE_WAITING_FOR_CLIENT_CHAR;
		return GAMESTATE_IN_GAME;
	}

	void PrintToChat(string message, PCSTR chat_type)
	{
		if(isxao_utilities::GetGameState() == GAMESTATE_IN_GAME)
		{
			string s;
			s = "<font color=\"" + string(chat_type) + "\">" + message + "</font>";
			pCommandInterpreter->ParseText(s);
		}
	}

#pragma endregion

#pragma region MessageHandling

	void HandleN3Message(PN3MESSAGEINFO message_info)
	{
		auto parser = isxao_classes::parser(PCHAR(message_info->message), message_info->size);
		const auto n3_header = isxao_classes::n3_header(parser);
		switch(N3MessageType_e(n3_header.n3_type()))
		{
		case N3T_KNUBOT_NPC_DESCRIPTION: break;
		case N3T_ADD_TEMPLATE: break;
		case N3T_GRID_DESTINATION_SELECT: break;
		case N3T_WEATHER_CONTROL: break;
		case N3T_PET_TO_MASTER:
		{
			break;
		}
		case N3T_FLUSH_RDB_CACHES: break;
		case N3T_SHOP_SEARCH_RESULT: break;
		case N3T_SHOP_SEARCH_REQUEST: break;
		case N3T_ACCEPT_BS_INVITE: break;
		case N3T_ADD_PET:
		{
			if(message_info->size == 0x15)
			{
				const auto add_pet_message = isxao_classes::add_pet_message(parser);
				HandleAddPetMessage(add_pet_message);
			}			
			break;
		}
		case N3T_SET_POS: break;
		case N3T_REFLECT_ATTACK:
		{
			//printf("0x%.8X", message_info->size);
			break;
		}
		case N3T_SPECIAL_ATTACK_WEAPON: break;
		case N3T_MENTOR_INVITE: break;
		case N3T_ACTION:
		{
			//printf("0x%.8X", message_info->size);
			break;
		}
		case N3T_SCRIPT: break;
		case N3T_FORMAT_FEEDBACK: break;
		case N3T_KNUBOT_ANSWER: break;
		case N3T_QUEST: break;
		case N3T_MINE_FULL_UPDATE: break;
		case N3T_LOOK_AT: break;
		case N3T_SHIELD_ATTACK:
		{
			if(message_info->size == 0x1D)
			{
				auto a1 = parser.pop_integer();
				auto a2 = parser.pop_integer();
				auto a3 = parser.pop_integer();
				auto a4 = parser.pop_integer();
				printf("%d %d %d %d", a1, a2, a3, a4);
			}
			//printf("0x%.8X", message_info->size);
			break;
		}
		case N3T_CAST_NANO_SPELL:
		{			
			if(message_info->size == 0x25)
			{
				auto cast_nano_spell_message = isxao_classes::cast_nano_spell_message(parser);
				HandleCastNanoSpellMessage(cast_nano_spell_message);
			}			
			break;
		}
		case N3T_RESEARCH_UPDATE: break;
		case N3T_FOLLOW_TARGET:
		{
			if(message_info->size == 0x28)
			{
				auto follow_target_message = isxao_classes::follow_target_message(parser);
				HandleFollowTargetMessage(follow_target_message);
			}			
			break;
		}
		case N3T_RELOCATE_DYNELS: break;
		case N3T_ABSORB: break;
		case N3T_RELOAD: break;
		case N3T_KNUBOT_CLOSE_CHAT_WINDOW: break;
		case N3T_SIMPLE_CHAR_FULL_UPDATE: break;
		case N3T_START_LOGOUT: break;
		case N3T_ATTACK:
		{
			if(message_info->size == 0x16)
			{
				auto attack_message = isxao_classes::attack_message(parser);
				HandleAttackMessage(attack_message);
			}			
			break;
		}
		case N3T_TEAM_MEMBER_INFO: break;
		case N3T_FULL_CHARACTER: break;
		case N3T_LASER_TARGET_LIST: break;
		case N3T_TRAP_DISARMED: break;
		case N3T_FOV: break;
		case N3T_STAT: break;
		case N3T_QUEUE_UPDATE: break;
		case N3T_KNUBOT_REJECTED_ITEMS: break;
		case N3T_PLAYER_SHOP_FULL_UPDATE: break;
		case N3T_ORG_INFO_PACKET: break;
		case N3T_N3_PLAYFIELD_FULL_UPDATE: break;
		case N3T_RESEARCH_REQUEST: break;
		case N3T_AREA_FORMULA: break;
		case N3T_IN_FROM_PLAYER: break;
		case N3T_MAIL: break;
		case N3T_APPLY_SPELLS: break;
		case N3T_BANK: break;
		case N3T_SHOP_INVENTORY: break;
		case N3T_TEMPLATE_ACTION: break;
		case N3T_TRADE: break;
		case N3T_DESPAWN: break;
		case N3T_DOOR_FULL_UPDATE: break;
		case N3T_CITY_ADVANTAGES: break;
		case N3T_HEALTH_DAMAGE: break;
		case N3T_FIGHT_MODE_UPDATE: break;
		case N3T_SET_SHOP_NAME: break;
		case N3T_BUFF: break;
		case N3T_KNUBOT_TRADE: break;
		case N3T_DROP_TEMPLATE: break;
		case N3T_GRID_SELECTED: break;
		case N3T_SIMPLEITEM_FULL_UPDATE: break;
		case N3T_KNUBOT_OPEN_CHAT_WINDOW: break;
		case N3T_WEAPONITEM_FULL_UPDATE: break;
		case N3T_SOCIAL_ACTION_CMD: break;
		case N3T_RAID: break;
		case N3T_SHADOW_LEVEL: break;
		case N3T_CLONE: break;
		case N3T_SHOP_COMMISSION: break;
		case N3T_SERVER_PATH_POS_DEBUG_INFO: break;
		case N3T_SKILL: break;
		case N3T_LEAVE_BATTLE: break;
		case N3T_SHOP_INFO: break;
		case N3T_APPEARANCE_UPDATE: break;
		case N3T_N3_TELEPORT: break;
		case N3T_PERK_UPDATE: break;
		case N3T_SEND_SCORE: break;
		case N3T_RESURRECT: break;
		case N3T_UPDATE_CLIENT_VISUAL: break;
		case N3T_HOUSE_DEMOLISH_START: break;
		case N3T_PLAY_SOUND1: break;
		case N3T_ATTACK_INFO: break;
		case N3T_TEAM_MEMBER: break;
		case N3T_SPAWN_MECH: break;
		case N3T_QUEST_FULL_UPDATE: break;
		case N3T_CHESTITEM_FULL_UPDATE: break;
		case N3T_NANO_ATTACK: break;
		case N3T_DROP_DYNEL: break;
		case N3T_CONTAINER_ADD_ITEM: break;
		case N3T_VISIBILITY: break;
		case N3T_STOP_FIGHT: break;
		case N3T_BATTLE_OVER: break;
		case N3T_INVENTORY_UPDATED: break;
		case N3T_DOOR_STATUS_UPDATE: break;
		case N3T_TEAM_INVITE: break;
		case N3T_SHOP_STATUS: break;
		case N3T_INFO_PACKET: break;
		case N3T_SPELL_LIST: break;
		case N3T_INVENTORY_UPDATE: break;
		case N3T_CORPSE_FULL_UPDATE: break;
		case N3T_FEEDBACK: break;
		case N3T_CHAR_SEC_SPEC_ATTACK: break;
		case N3T_BANK_CORPSE: break;
		case N3T_GENERIC_CMD: break;
		case N3T_PATH_MOVE_CMD: break;
		case N3T_ARRIVE_AT_BS: break;
		case N3T_CHAR_DC_MOVE: break;
		case N3T_PLAYFIELD_ALL_TOWERS: break;
		case N3T_KNUBOT_FINISH_TRADE: break;
		case N3T_KNUBOT_ANSWER_LIST: break;
		case N3T_STOP_LOGOUT: break;
		case N3T_CHAR_IN_PLAY: break;
		case N3T_SHOP_UPDATE: break;
		case N3T_MECH_INFO: break;
		case N3T_REMOVE_PET:
		{
			if (message_info->size == 0x15)
			{
				auto remove_pet_message = isxao_classes::remove_pet_message(parser);
				HandleRemovePetMessage(remove_pet_message);
			}			
			break;
		}
		case N3T_PLAYFIELD_ALL_CITIES: break;
		case N3T_TRAPITEM_FULL_UPDATE: break;
		case N3T_INSPECT: break;
		case N3T_PLAYFIELD_TOWER_UPDATE_CLIENT: break;
		case N3T_SERVER_POS_DEBUG_INFO: break;
		case N3T_QUEST_ALTERNATIVE: break;
		case N3T_FULL_AUTO: break;
		case N3T_CHAT_CMD: break;
		case N3T_MISSED_ATTACK_INFO: break;
		case N3T_KNUBOT_APPEND_TEXT: break;
		case N3T_CHARACTER_ACTION:
		{
			if(message_info->size == 0x27)
			{
				auto character_action_message = isxao_classes::character_action_message(parser);
				HandleCharacterActionMessage(character_action_message);
			}			
			break;
		}
		case N3T_HOUSE_DISAPPEARED: break;
		case N3T_IMPULSE: break;
		case N3T_PLAYFIELD_ANARCHY_F: break;
		case N3T_CHAT_TEXT: break;
		case N3T_GAME_TIME: break;
		case N3T_SET_WANTED_DIRECTION: break;
		case N3T_AO_TRANSPORT_SIGNAL: break;
		case N3T_PET_COMMAND: break;
		case N3T_ORG_SERVER: break;
		case N3T_SET_STAT: break;
		case N3T_SET_NAME: break;
		case N3T_STOP_MOVING_CMD: break;
		case N3T_SPECIAL_ATTACK_INFO: break;
		case N3T_GIVE_QUEST_TO_MEMBER: break;
		case N3T_KNUBOT_START_TRADE: break;
		case N3T_GFX_TRIGGER: break;
		case N3T_SHOP_ITEM_PRICE: break;
		case N3T_NEW_LEVEL: break;
		case N3T_ORG_CLIENT: break;
		case N3T_VENDING_MACHINE_FULL_UPDATE: break;
		default: break;
		}
		delete message_info;
	}

	void HandleAddPetMessage(add_pet_message pet_message)
	{
		char pet[MAX_STRING];
		sprintf_s(pet, sizeof(pet), "%I64u",pet_message.identity().combined_identity());
		char *argv[] = { pet };
		pISInterface->ExecuteEvent(GetEventId("AO_onAddPet"), 0, 1, argv);
		//delete argv;
	}

	void HandleAttackMessage(attack_message attack_message)
	{
		char target[MAX_STRING];
		sprintf_s(target, sizeof(target), "%I64u", attack_message.target().combined_identity());
		char *argv[] = { target };
		pISInterface->ExecuteEvent(GetEventId("AO_onAttack"), 0, 1, argv);
		//delete argv;
	}

	void HandleCastNanoSpellMessage(cast_nano_spell_message cast_nano_spell_message)
	{
		char nano_id[MAX_STRING];
		char target[MAX_STRING];
		char caster[MAX_STRING];
		sprintf_s(nano_id, sizeof(nano_id), "%d", cast_nano_spell_message.nano_id());
		sprintf_s(target, sizeof(target), "%I64u", cast_nano_spell_message.target().combined_identity());
		sprintf_s(caster, sizeof(caster), "%I64u", cast_nano_spell_message.caster().combined_identity());
		char *argv[] = { nano_id, target, caster };
		pISInterface->ExecuteEvent(GetEventId("AO_onCastNanoSpell"), 0, 3, argv);
		if (IsClientId(cast_nano_spell_message.target().id()))
			pISInterface->ExecuteEvent(GetEventId("AO_onCastNanoSpell_TargetSelf"), 0, 3, argv);
		else
			pISInterface->ExecuteEvent(GetEventId("AO_onCastNanoSpell_TargetOther"), 0, 3, argv);
		if (IsClientId(cast_nano_spell_message.caster().id()))
			pISInterface->ExecuteEvent(GetEventId("AO_onCastNanoSpell_CasterSelf"), 0, 3, argv);
		else
			pISInterface->ExecuteEvent(GetEventId("AO_onCastNanoSpell_CasterOther"), 0, 3, argv);
	}

	void HandleCharacterActionMessage(isxao_classes::character_action_message character_action_message)
	{
		switch (::TypeCharacterAction_e(character_action_message.character_action_type()))
		{
		case ::CAT_FINISH_NANO_CASTING:
		{
			char nano_id[MAX_STRING];
			sprintf_s(nano_id, sizeof(nano_id), "%d", character_action_message.param_2());
			char * argv[] = { nano_id };
			pISInterface->ExecuteEvent(GetEventId("AO_onFinishedCastingNano"), 0, 1, argv);
			break;
		}
		case ::CAT_SET_NANO_DURATION:
		{
			identity_t caster_identity;
			caster_identity.type = 50000;
			caster_identity.id = character_action_message.param_1();
			char nano_id[MAX_STRING];
			sprintf_s(nano_id, sizeof(nano_id), "%d", character_action_message.identity().id());
			char caster_id[MAX_STRING];
			sprintf_s(caster_id, sizeof(caster_id), "%I64u", caster_identity.get_combined_identity());
			char duration[MAX_STRING];
			sprintf_s(duration, sizeof(duration), "%d", character_action_message.param_2());
			char * argv[] = { nano_id, caster_id, duration };
			pISInterface->ExecuteEvent(GetEventId("AO_onNanoApplied"), 0, 3, argv);
			break;
		}
		case ::CAT_STAND_UP:
		{
			pISInterface->ExecuteEvent(GetEventId("AO_onStand"));
			break;
		}
		case ::CAT_TEAM_REQUEST: break;
		case ::CAT_CAST_NANO: break;
		case ::CAT_TEAM_REQUEST_REPLY: break;
		case ::CAT_LEAVE_TEAM: break;
		case ::CAT_ACCEPT_TEAM_REQUEST: break;
		case ::CAT_REMOVE_FRIENDLY_NANO: break;
		case ::CAT_USE_ITEM_ON_ITEM: break;
		case ::CAT_UNKNOWN_3: break;
		case ::CAT_INFO_REQUEST: break;
		case ::CAT_INTERRUPT_NANO_CASTING: break;
		case ::CAT_DELETE_ITEM: break;
		case ::CAT_LOGOUT: break;
		case ::CAT_STOPLOGOUT: break;
		case ::CAT_EQUIP: break;
		case ::CAT_STARTED_SNEAKING: break;
		case ::CAT_START_SNEAK: break;
		case ::CAT_CHANGE_VISUAL_FLAG: break;
		case ::CAT_CHANGE_ANIMATION_AND_STANCE: break;
		case ::CAT_UPLOAD_NANO: break;
		case ::CAT_TRADESKILL_SOURCE_CHANGED: break;
		case ::CAT_TRADESKILL_TARGET_CHANGED: break;
		case ::CAT_TRADESKILL_BUILD_PRESSED: break;
		case ::CAT_TRADESKILL_SOURCE: break;
		case ::CAT_TRADESKILL_TARGET: break;
		case ::CAT_TRADESKILL_NOT_VALID: break;
		case ::CAT_TRADESKILL_OUT_OF_RANGE: break;
		case ::CAT_TRADESKILL_REQUIREMENT: break;
		case ::CAT_TRADESKILL_RESULT: break;
		default: break;
		}
	}

	void HandleFollowTargetMessage(follow_target_message follow_message)
	{
		char target[MAX_STRING];
		sprintf_s(target, sizeof(target), "%I64u", follow_message.target().combined_identity());
		char *argv[] = { target };
		pISInterface->ExecuteEvent(GetEventId("AO_onFollowTarget"), 0, 1, argv);
		//delete argv;
	}
	
	void HandleRemovePetMessage(remove_pet_message remove_pet_message)
	{
		char pet[MAX_STRING];
		sprintf_s(pet, sizeof(pet), "%I64u", remove_pet_message.identity().combined_identity());
		char *argv[] = { pet };
		pISInterface->ExecuteEvent(GetEventId("AO_onRemovePet"), 0, 1, argv);
		//delete argv;
	}

	void HandleShieldAttackMessage(shield_attack_message shield_attack_message)
	{
		char damage[MAX_STRING];
		char shieldee[MAX_STRING];
		sprintf_s(damage, sizeof(damage), "%d", shield_attack_message.damage_shielded());
		sprintf_s(shieldee, sizeof(shieldee), "%I64u", shield_attack_message.shieldee().combined_identity());
		char *argv[] = { damage, shieldee };
		pISInterface->ExecuteEvent(GetEventId("AO_onAttackShielded"), 0, 2, argv);
		//delete argv;
	}

	void HandleGroupMessage(PGROUPMESSAGEINFO group_message_info)
	{
		char* sender = _strdup(group_message_info->SenderName.c_str());
		char* channel = _strdup(group_message_info->ChatChannel.c_str());
		char* message = _strdup(group_message_info->Message.c_str());
		char id[MAX_STRING];
		sprintf_s(id, sizeof(id), "%I64u", group_message_info->SenderIdentity.get_combined_identity());
		char *argv[] = { sender, channel, message, id };
		pISInterface->ExecuteEvent(GetEventId("AO_onGroupMessageReceived"), 0, 4, argv);
		delete group_message_info;
	}

	void HandlePrivateMessage(PPRIVATEMESSAGEINFO private_message_info)
	{
		char* sender = _strdup(private_message_info->SenderName.c_str());
		char* message = _strdup(private_message_info->Message.c_str());
		char id[MAX_STRING];
		sprintf_s(id, sizeof(id), "%I64u", private_message_info->SenderIdentity.get_combined_identity());
		char *argv[] = { sender, message, id };
		pISInterface->ExecuteEvent(GetEventId("AO_onTellReceived"), 0, 3, argv);
		delete private_message_info;
	}

	void HandleVicinityMessage(PPRIVATEMESSAGEINFO vicinity_message_info)
	{
		char* sender = _strdup(vicinity_message_info->SenderName.c_str());
		char* message = _strdup(vicinity_message_info->Message.c_str());
		char id[MAX_STRING];
		sprintf_s(id, sizeof(id), "%I64u", vicinity_message_info->SenderIdentity.get_combined_identity());
		char *argv[] = { sender, message, id };
		pISInterface->ExecuteEvent(GetEventId("AO_onVicinityMessageReceived"), 0, 3, argv);
		delete vicinity_message_info;
	}

	void HandleSystemChat(PSYSTEMCHATINFO system_chat_info)
	{
		char chat_type[MAX_STRING];
		char* text = _strdup(system_chat_info->Text.c_str());
		switch (::ChatGroup_e(system_chat_info->ChatType))
		{
		case ::CG_SYSTEM:
		{
			strcpy_s(chat_type, sizeof(chat_type), "SYSTEM");
			break;
		}
		case ::CG_VICINITY:
		{
			strcpy_s(chat_type, sizeof(chat_type), "VICINITY");
			break;
		}
		case ::CG_TELL_MESSAGES:
		{
			strcpy_s(chat_type, sizeof(chat_type), "TELL_MESSAGES");
			break;
		}
		case ::CG_YOUR_PETS:
		{
			strcpy_s(chat_type, sizeof(chat_type), "YOUR_PETS");
			break;
		}
		case ::CG_OTHERS_PETS:
		{
			strcpy_s(chat_type, sizeof(chat_type), "OTHERS_PETS");
			break;
		}
		case ::CG_ME_HIT_BY_ENVIRONMENT:
		{
			strcpy_s(chat_type, sizeof(chat_type), "ME_HIT_BY_ENVIRONMENT");
			break;
		}
		case ::CG_ME_HIT_BY_NANO:
		{
			strcpy_s(chat_type, sizeof(chat_type), "ME_HIT_BY_NANO");
			break;
		}
		case ::CG_YOUR_PET_HIT_BY_NANO:
		{
			strcpy_s(chat_type, sizeof(chat_type), "YOUR_PET_HIT_BY_NANO");
			break;
		}
		case ::CG_OTHER_HIT_BY_NANO:
		{
			strcpy_s(chat_type, sizeof(chat_type), "OTHER_HIT_BY_NANO");
			break;
		}
		case ::CG_YOU_HIT_OTHER_WITH_NANO:
		{
			strcpy_s(chat_type, sizeof(chat_type), "YOU_HIT_OTHER_WITH_NANO");
			break;
		}
		case ::CG_ME_HIT_BY_MONSTER:
		{
			strcpy_s(chat_type, sizeof(chat_type), "ME_HIT_BY_MONSTER");
			break;
		}
		case ::CG_ME_HIT_BY_PLAYER:
		{
			strcpy_s(chat_type, sizeof(chat_type), "ME_HIT_BY_PLAYER");
			break;
		}
		case ::CG_YOU_HIT_OTHER:
		{
			strcpy_s(chat_type, sizeof(chat_type), "YOU_HIT_OTHER");
			break;
		}
		case ::CG_YOUR_PET_HIT_BY_OTHER:
		{
			strcpy_s(chat_type, sizeof(chat_type), "YOUR_PET_HIT_BY_OTHER");
			break;
		}
		case ::CG_OTHER_HIT_BY_OTHER:
		{
			strcpy_s(chat_type, sizeof(chat_type), "OTHER_HIT_BY_OTHER");
			break;
		}
		case ::CG_ME_GOT_XP:
		{
			strcpy_s(chat_type, sizeof(chat_type), "ME_GOT_XP");
			break;
		}
		case ::CG_ME_GOT_SK:
		{
			strcpy_s(chat_type, sizeof(chat_type), "ME_GOT_SK");
			break;
		}
		case ::CG_YOUR_PET_HIT_BY_MONSTER:
		{
			strcpy_s(chat_type, sizeof(chat_type), "YOUR_PET_HIT_BY_MONSTER");
			break;
		}
		case ::CG_YOUR_MISSES:
		{
			strcpy_s(chat_type, sizeof(chat_type), "YOUR_MISSES");
			break;
		}
		case ::CG_OTHER_MISSES:
		{
			strcpy_s(chat_type, sizeof(chat_type), "OTHER_MISSES");
			break;
		}
		case ::CG_YOU_GAVE_HEALTH:
		{
			strcpy_s(chat_type, sizeof(chat_type), "YOU_GAVE_HEALTH");
			break;
		}
		case ::CG_ME_GOT_HEALTH:
		{
			strcpy_s(chat_type, sizeof(chat_type), "ME_GOT_HEALTH");
			break;
		}
		case ::CG_ME_GOT_NANO:
		{
			strcpy_s(chat_type, sizeof(chat_type), "ME_GOT_NANO");
			break;
		}
		case ::CG_YOU_GAVE_NANO:
		{
			strcpy_s(chat_type, sizeof(chat_type), "YOU_GAVE_NANO");
			break;
		}
		case ::CG_ME_CAST_NANO:
		{
			strcpy_s(chat_type, sizeof(chat_type), "ME_CAST_NANO");
			break;
		}
		case ::CG_TEAM_LOOT_MESSAGES:
		{
			strcpy_s(chat_type, sizeof(chat_type), "TEAM_LOOT_MESSAGES");
			break;
		}
		case ::CG_VICINITY_LOOT_MESSAGES:
		{
			strcpy_s(chat_type, sizeof(chat_type), "VICINITY_LOOT_MESSAGES");
			break;
		}
		case ::CG_RESEARCH:
		{
			strcpy_s(chat_type, sizeof(chat_type), "RESEARCH");
			break;
		}
		default:
			sprintf_s(chat_type, sizeof(chat_type), "%d", system_chat_info->ChatType);
			break;
		}
		char *argv[] = { chat_type, text };
		pISInterface->ExecuteEvent(GetEventId("AO_onIncomingSystemText"), 0, 2, argv);
		delete system_chat_info;
	}

#pragma endregion

}

using namespace isxao_utilities;
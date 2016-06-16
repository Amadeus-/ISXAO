#include "isxao_main.h"
#include "atlbase.h"
#include "iostream"

namespace isxao_utilities
{

#pragma region Strings

#ifdef __GetBreedStr_x
	FUNCTION_AT_ADDRESS(PCSTR __cdecl GetBreedStr(DWORD), __GetBreedStr);
#endif

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

#ifdef __GetSexStr_x
	FUNCTION_AT_ADDRESS(PCSTR __cdecl GetSexStr(DWORD), __GetSexStr);
#endif

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

	PCSTR GetStatName(DWORD stat)
	{
		auto result = "NoName";
		std::map<DWORD, PCSTR> m;
		GetStatNameMap(m);
		if (m.count(stat))
			result = m.find(stat)->second;
		return result;
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


#pragma endregion

#pragma region Objects

#ifdef __GetDynel_x
	FUNCTION_AT_ADDRESS(Dynel* __cdecl GetDynel(const IDENTITY &), __GetDynel);
	FUNCTION_AT_ADDRESS(Actor* __cdecl GetActor(const IDENTITY &), __GetDynel);
#endif

#ifdef __GetNanoItem_x
	FUNCTION_AT_ADDRESS(PNANOITEM __cdecl GetNanoItem(DWORD), __GetNanoItem);
#endif

#ifdef __GetFullPerkMap_x
	FUNCTION_AT_ADDRESS(DWORD __cdecl GetFullPerkMap(void), __N3Msg_GetFullPerkMap);
#endif

	bool IsValidDynel(PN3DYNEL pDynel)
	{
		if (pDynel && pDynel->pvTable)
		{
			auto d = DWORD(pDynel->pvTable);
			if (d < hGamecode || d >(hGamecode + GetModuleInfo("Gamecode.dll").SizeOfImage))
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

	PVOID RequestInfo(const IDENTITY &id)
	{
		typedef PVOID(__thiscall * tRequestInfo)(SpecialActionHolder*, const IDENTITY&);
		auto pLookAt = tRequestInfo(__RequestInfo);
		return pLookAt(pEngineClientAnarchy->GetClientChar()->GetSpecialActionHolder(), id);
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

	bool ActorMatchesSearch(PSEARCHACTOR p_search_actor, Actor* p_character, Actor* p_actor)
	{
		char szName[MAX_STRING] = { 0 };
		char szSearchName[MAX_STRING] = { 0 };
		DWORD actor_type;
		if (p_actor->GetIdentity().Type != 50000)
			actor_type = MOB_OTHER;
		else if (p_actor->IsActor())
		{
			if (p_actor->IsPet() && IsClientId(p_actor->GetMasterId()))
				actor_type = MOB_MYPET;
			else if (p_actor->IsPet())
				actor_type = MOB_PET;
			else
				actor_type = MOB_NPC;
		}
		else
			actor_type = MOB_PC;
		if (p_search_actor->actor_type != actor_type && p_search_actor->actor_type != MOB_NONE)
			return false;
		strcpy_s(szName, MAX_STRING, p_actor->GetName());
		_strlwr_s(szName);
		strcpy_s(szSearchName, MAX_STRING, p_search_actor->name);
		_strlwr_s(szSearchName);
		if (!strstr(szName, szSearchName))
			return false;
		if (p_search_actor->min_level && DWORD(p_actor->GetSkill(ST_LEVEL)) < p_search_actor->min_level)
			return false;
		if (p_search_actor->max_level && DWORD(p_actor->GetSkill(ST_LEVEL)) > p_search_actor->max_level)
			return false;
		if (p_search_actor->not_id == p_actor->GetIdentity().GetCombinedIdentity())
			return false;
		if (p_search_actor->is_dynel_id && p_search_actor->actor_id != p_actor->GetIdentity().GetCombinedIdentity())
			return false;
		if (p_search_actor->is_known_location)
		{
			if (p_search_actor->x_loc != p_actor->GetPosition().X || p_search_actor->z_loc != p_actor->GetPosition().Z)
			{
				VECTOR3 knownLoc;
				knownLoc.X = p_search_actor->x_loc;
				knownLoc.Y = 0.0f;
				knownLoc.Z = p_search_actor->z_loc;
				if (p_search_actor->f_radius < 10000.0f && p_actor->GetDistanceTo(knownLoc) > p_search_actor->f_radius)
					return false;
			}
		}
		if (p_search_actor->radius > 0.0f && IsPCNear(p_actor, p_search_actor->radius))
			return false;
		if (g_y_filter < 10000.0f)
		{
			VECTOR3 client = p_character->GetPosition();
			if (p_actor->GetPosition().Y > client.Y + g_y_filter || p_actor->GetPosition().Y < client.Y - g_y_filter)
				return false;
		}
		if (p_search_actor->y_radius < 10000.0f)
		{
			VECTOR3 client = p_character->GetPosition();
			if (p_actor->GetPosition().Y > client.Y + p_search_actor->y_radius || p_actor->GetPosition().Y < client.Y - p_search_actor->y_radius)
				return false;
		}
		return true;
	}

	bool IsPCNear(Actor* p_actor, float radius)
	{
		Actor* p_close_actor = nullptr;
		if (pEngineClientAnarchy)
		{
			std::vector<Actor*> v;
			pPlayfieldDir->GetPlayfield()->GetPlayfieldActors(v);
			for (auto it = v.begin(); it != v.end(); ++it)
			{
				if ((*it)->GetIdentity().Type == 50000 && !pEngineClientAnarchy->N3Msg_IsNpc((*it)->GetIdentity()))
				{
					if ((*it) != p_actor)
					{
						VECTOR3 c = (*it)->GetPosition();
						if (p_actor->GetDistanceTo(c) < radius)
							return true;
					}
				}
			}
		}
		return false;
	}

	DWORD CountMatchingActors(PSEARCHACTOR p_search_actor, Actor* p_character, bool include_char)
	{
		if (!p_search_actor || !p_character)
			return 0;
		DWORD total_matching = 0;
		std::vector<Actor*> v;
		pPlayfieldDir->GetPlayfield()->GetPlayfieldActors(v);
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

	Actor* NthNearestActor(PSEARCHACTOR p_search_actor, DWORD nth, Actor* p_origin, bool include_char)
	{
		if (!p_search_actor || !nth || !p_origin)
			return nullptr;
		CIndex<PAORANK> actor_set;
		VECTOR3 pos = p_origin->GetPosition();
		std::vector<Actor*> v;
		pPlayfieldDir->GetPlayfield()->GetPlayfieldActors(v);
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
					pNewRank->Value.Float = (*it)->GetDistanceTo(pos);
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
					pNewRank->Value.Float = (*it)->GetDistanceTo(pos);
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
		auto p_actor = static_cast<Actor*>(actor_set[nth - 1]->VarPtr.Ptr);
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

	//bool ActorMatchesSearch(PSEARCHACTOR p_search_actor, Actor* p_character, Actor* p_actor)
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

	//Actor* NearestActor(PSEARCHACTOR p_search_actor, Actor* p_origin, bool include_character)
	//{
	//	if (!p_search_actor || !p_origin)
	//		return nullptr;
	//	auto point_of_origin = p_origin->GetPosition();
	//	std::vector<Actor*> v;
	//	pPlayfieldDir->GetPlayfield()->GetPlayfieldActors(v);
	//	std::sort(v.begin(), v.end(), Dynel::pDynelCompare);
	//	if(include_character)
	//	{
	//		for (auto it = v.begin(); it != v.end(); ++it)
	//		{
	//			if (ActorMatchesSearch(p_search_actor, pEngineClientAnarchy->GetClientChar(), (*it)))
	//				return (*it);
	//		}
	//	}
	//	else
	//	{
	//		for (auto it = v.begin(); it != v.end(); ++it)
	//		{
	//			if (ActorMatchesSearch(p_search_actor, pEngineClientAnarchy->GetClientChar(), (*it)) && !IsClientId((*it)->GetIdentity().Id))
	//				return (*it);
	//		}
	//	}
	//	return nullptr;
	//}



#pragma endregion

#pragma region Collections
	
	void RecursiveAddDynelToDynelMap(std::map<IDENTITY, PN3DYNEL>& m, PDYNELNODE pNode, PDYNELROOT pRoot, DWORD& count)
	{
		m.insert_or_assign(pNode->Identity, pNode->pDynel);
		count--;
		if (reinterpret_cast<PVOID>(pNode->pLower) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddDynelToDynelMap(m, pNode->pLower, pRoot, count);
		if (reinterpret_cast<PVOID>(pNode->pHigher) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddDynelToDynelMap(m, pNode->pHigher, pRoot, count);
	}

	void GetDynelMap(std::map<IDENTITY, PN3DYNEL>& m)
	{
		auto count = pDynelDir->Count;
		auto pRoot = pDynelDir->pRoot;
		auto pNode = pRoot->pNode;
		if (count > 0)
			RecursiveAddDynelToDynelMap(m, pNode, pRoot, count);
	}

	void RecursiveAddPerkToPerkMap(std::map<IDENTITY, DWORD>& m, PPERKNODE pNode, PPERKROOT pRoot, DWORD& count)
	{
		m.insert_or_assign(pNode->PerkIdentity, pNode->PerkID);
		count--;
		if (reinterpret_cast<PVOID>(pNode->pLower) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddPerkToPerkMap(m, pNode->pLower, pRoot, count);
		if (reinterpret_cast<PVOID>(pNode->pHigher) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddPerkToPerkMap(m, pNode->pHigher, pRoot, count);
	}

	void GetPerkMap(std::map<IDENTITY, DWORD>& m, PPERKDIR pDir)
	{
		auto count = pDir->Count;
		auto pRoot = pDir->pRoot;
		auto pNode = pRoot->pNode;
		if (count > 0)
			RecursiveAddPerkToPerkMap(m, pNode, pRoot, count);
	}

	void RecursiveAddPetToPetMap(std::map<IDENTITY, DWORD>& m, PPETNODE pNode, PPETROOT pRoot, DWORD& count)
	{
		m.insert_or_assign(pNode->Identity, pNode->Index);
		count--;
		if (reinterpret_cast<PVOID>(pNode->pLower) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddPetToPetMap(m, pNode->pLower, pRoot, count);
		if (reinterpret_cast<PVOID>(pNode->pHigher) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddPetToPetMap(m, pNode->pHigher, pRoot, count);
	}

	void GetPetMap(std::map<IDENTITY, DWORD>& m, PPETDIR pPetDir)
	{
		auto count = pPetDir->Count;
		auto pRoot = pPetDir->pRoot;
		auto pNode = pRoot->pNode;
		if (count > 0)
			RecursiveAddPetToPetMap(m, pNode, pRoot, count);
	}

	void RecursiveAddNanoToNanoMap(std::map<DWORD, PNANOITEM>& m, PNANOITEMNODE pNode, PNANOITEMROOT pRoot, DWORD& count)
	{
		m.insert_or_assign(pNode->NanoItemId, pNode->pNanoItem);
		count--;
		if (reinterpret_cast<PVOID>(pNode->pLower) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddNanoToNanoMap(m, pNode->pLower, pRoot, count);
		if (reinterpret_cast<PVOID>(pNode->pHigher) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddNanoToNanoMap(m, pNode->pHigher, pRoot, count);
	}

	void GetNanoMap(std::map<DWORD, PNANOITEM>& m)
	{
		auto count = pNanoItemDir->Count;
		auto pRoot = pNanoItemDir->pRoot;
		auto pNode = pRoot->pNode;
		if (count > 0)
			RecursiveAddNanoToNanoMap(m, pNode, pRoot, count);
	}

	void RecursiveAddStatNameToStatNameMap(std::map<DWORD, PCSTR>& m, PSTATNAMENODE pNode, PSTATNAMEROOT pRoot, DWORD& count)
	{
		m.insert_or_assign(pNode->Stat, pNode->pName);
		count--;
		if (reinterpret_cast<PVOID>(pNode->pLower) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddStatNameToStatNameMap(m, pNode->pLower, pRoot, count);
		if (reinterpret_cast<PVOID>(pNode->pHigher) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddStatNameToStatNameMap(m, pNode->pHigher, pRoot, count);
	}

	void GetStatNameMap(std::map<DWORD, PCSTR>& m)
	{
		if (pStatNameDir)
		{
			auto count = pStatNameDir->Count;
			auto pRoot = pStatNameDir->pRoot;
			auto pNode = pRoot->pNode;
			if (count > 0)
				RecursiveAddStatNameToStatNameMap(m, pNode, pRoot, count);
		}
	}

	void GetStaticItemMap(std::map<IDENTITY, PDUMMYITEMBASE>& m)
	{
		auto count = pStaticItemVector->size();
		for (DWORD i = 0; i < count; i++)
		{
			if (pStaticItemVector->at(i).pDummyItem)
				m.insert_or_assign(pStaticItemVector->at(i).pDummyItem->Identity, pStaticItemVector->at(i).pDummyItem);
		}
	}

	void RecursiveAddStatToStatMap(std::map<DWORD, LONG>& m, PSTATNODE pNode, PSTATROOT pRoot, DWORD& count)
	{
		m.insert_or_assign(pNode->Stat, pNode->Modifier);
		count--;
		if (reinterpret_cast<PVOID>(pNode->pLower) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddStatToStatMap(m, pNode->pLower, pRoot, count);
		if (reinterpret_cast<PVOID>(pNode->pHigher) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddStatToStatMap(m, pNode->pHigher, pRoot, count);
	}

	void GetStatMap(std::map<DWORD, LONG>& m, PSTATDIR pDir)
	{
		auto count = pDir->Count;
		auto pRoot = pDir->pRoot;
		auto pNode = pRoot->pNode;
		if (count > 0)
			RecursiveAddStatToStatMap(m, pNode, pRoot, count);
	}

	void RecursiveAddWeaponItemToWeaponItemMap(std::map<DWORD, PWEAPONITEM>& m, PWEAPONITEMNODE pNode, PWEAPONITEMROOT pRoot, DWORD& count)
	{
		m.insert_or_assign(pNode->ActionID, pNode->pWeaponItem);
		count--;
		if (reinterpret_cast<PVOID>(pNode->pLower) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddWeaponItemToWeaponItemMap(m, pNode->pLower, pRoot, count);
		if (reinterpret_cast<PVOID>(pNode->pHigher) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddWeaponItemToWeaponItemMap(m, pNode->pHigher, pRoot, count);
	}

	void GetWeaponItemMap(std::map<DWORD, PWEAPONITEM>& m, WEAPONITEMDIR& dir)
	{
		auto count = dir.Count;
		auto pRoot = dir.pRoot;
		auto pNode = pRoot->pNode;
		if (count > 0)
			RecursiveAddWeaponItemToWeaponItemMap(m, pNode, pRoot, count);
	}

	void RecursiveAddChatWindowNodeToChatWindowNodeMap(std::map<string, ChatWindowNode*>& m, PCHATWINDOWNODENODE pNode, PCHATWINDOWNODEROOT pRoot, DWORD& count)
	{
		m.insert_or_assign(pNode->WindowName, reinterpret_cast<ChatWindowNode*>(pNode->pChatWindow));
		count--;
		if (reinterpret_cast<PVOID>(pNode->pLower) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddChatWindowNodeToChatWindowNodeMap(m, pNode->pLower, pRoot, count);
		if (reinterpret_cast<PVOID>(pNode->pHigher) != reinterpret_cast<PVOID>(pRoot) && count > 0)
			RecursiveAddChatWindowNodeToChatWindowNodeMap(m, pNode->pHigher, pRoot, count);
	}

	void GetChatWindowNodeMap(std::map<string, ChatWindowNode*>& m, CHATWINDOWNODEDIR &dir)
	{
		auto count = dir.Count;
		auto pRoot = dir.pRoot;
		auto pNode = pRoot->pNode;
		if (count > 0)
			RecursiveAddChatWindowNodeToChatWindowNodeMap(m, pNode, pRoot, count);
	}

#pragma endregion

#pragma region Inventory

	bool GetInvSlotIdentity(AOData::ArmorSlot_e slot, IDENTITY& id)
	{
		id.Type = 102;
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
			id.Id = DWORD(slot) + 17;
			break;
		default:
			return false;;
		}
		return true;
	}

	bool GetInvSlotIdentity(AOData::ImplantSlot_e slot, IDENTITY& id)
	{
		id.Type = 103;
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
			id.Id = DWORD(slot) + 32;
			break;
		default:
			return false;
		}
		return true;
	}

	bool GetInvSlotIdentity(AOData::WeaponSlot_e slot, IDENTITY& id)
	{
		id.Type = 101;
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
			id.Id = DWORD(slot);
			break;
		default:
			return false;
		}
		return true;
	}

	bool GetInvSlotIdentity(DWORD slot, IDENTITY& id)
	{
		id.Id = slot;
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
			id.Type = 101;
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
			id.Type = 102;
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
			id.Type = 103;
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
			id.Type = 104;
			break;
		default:
			return false;
		}
		return true;
	}

	void GetInvSlotName(const IDENTITY& slot, PCHAR pName)
	{
		switch (slot.Type)
		{
		case 101:
		{
			switch (slot.Id)
			{
			case 1:
				pName = "WS_HUD1";
				return;
			case 2:
				pName = "WS_HUD3";
				return;
			case 3:
				pName = "WS_UTIL1";
				return;
			case 4:
				pName = "WS_UTIL2";
				return;
			case 5:
				pName = "WS_UTIL3";
				return;
			case 6:
				pName = "WS_RHAND";
				return;
			case 7:
				pName = "WS_BELT";
				return;
			case 8:
				pName = "WS_LHAND";
				return;
			case 9:
				pName = "WS_NCU1";
				return;
			case 10:
				pName = "WS_NCU2";
				return;
			case 11:
				pName = "WS_NCU3";
				return;
			case 12:
				pName = "WS_NCU4";
				return;
			case 13:
				pName = "WS_NCU5";
				return;
			case 14:
				pName = "WS_NCU6";
				return;
			case 15:
				pName = "WS_HUD2";
				return;
			default:
				pName = "Unknown";
				return;
			}
		}
		case 102:
		{
			switch (slot.Id - 16)
			{
			case 1:
				pName = "AS_NECK";
				return;
			case 2:
				pName = "AS_HEAD";
				return;
			case 3:
				pName = "AS_BACK";
				return;
			case 4:
				pName = "AS_RSHOULDER";
				return;
			case 5:
				pName = "AS_CHEST";
				return;
			case 6:
				pName = "AS_LSHOULDER";
				return;
			case 7:
				pName = "AS_RARM";
				return;
			case 8:
				pName = "AS_HANDS";
				return;
			case 9:
				pName = "AS_LARM";
				return;
			case 10:
				pName = "AS_RWRIST";
				return;
			case 11:
				pName = "AS_LEGS";
				return;
			case 12:
				pName = "AS_LWRIST";
				return;
			case 13:
				pName = "AS_RFINGER";
				return;
			case 14:
				pName = "AS_FEET";
				return;
			case 15:
				pName = "AS_LFINGER";
				return;
			default:
				pName = "Unknown";
				return;
			}
		}
		case 103:
		{
			switch (slot.Id - 32)
			{
			case 1:
				pName = "IS_EYES";
				return;
			case 2:
				pName = "IS_HEAD";
				return;
			case 3:
				pName = "IS_EARS";
				return;
			case 4:
				pName = "IS_RARM";
				return;
			case 5:
				pName = "IS_CHEST";
				return;
			case 6:
				pName = "IS_LARM";
				return;
			case 7:
				pName = "IS_RWRIST";
				return;
			case 8:
				pName = "IS_WAIST";
				return;
			case 9:
				pName = "IS_LWRIST";
				return;
			case 10:
				pName = "IS_RHAND";
				return;
			case 11:
				pName = "IS_LEGS";
				return;
			case 12:
				pName = "IS_LHAND";
				return;
			case 13:
				pName = "IS_FEET";
				return;
			default:
				pName = "Unknown";
				return;
			}
		}
		case 104:
		{
			sprintf_s(pName, MAX_STRING, "GI_%d", slot.Id);
			return;
		}
		default:
			break;
		}
		pName = "Unknown";
	}

	bool GetInvSlotIdentity(PCSTR slot_name, IDENTITY &id)
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
		if (id.Type != 0)
			return true;
		return false;
	}

#pragma endregion

#pragma region Lavishscript

	LSTypeDefinition* GetRealType(Dynel* pObject)
	{
		if (pObject && pObject->GetIdentity().Type == 50000)
		{
			if (pObject->IsCharacter())
				return pCharacterType;
			if (pObject->IsTeamMember())
				return pTeamMemberType;
			if (pObject->IsPlayer())
			{
				//printf("IsPlayer");
				return pPlayerType;
			}				
			if (pObject->IsPet() && isxao_inlines::IsClientId(pObject->ToActor()->GetMasterId()))
				return pPetType;
			if (pObject->IsActor())
				return pActorType;
		}
		//printf("IsDynel");
		return pDynelType;
	}

#pragma endregion

#pragma region Utility

	DWORD GetGameState()
	{
		if (!pEngineClientAnarchy)
			return GAMESTATE_NOT_IN_GAME;
		if (!pPlayfieldDir->GetPlayfield())
			return GAMESTATE_WAITING_FOR_PLAYFIELD;
		if (!pEngineClientAnarchy->GetClientChar())
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
		auto parser = Parser(PCHAR(message_info->message), message_info->size);
		auto n3_header = N3Header(parser);
		switch(N3MessageType_e(n3_header.N3Type()))
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
				auto add_pet_message = AddPetMessage(parser);
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
				auto a1 = parser.PopInteger();
				auto a2 = parser.PopInteger();
				auto a3 = parser.PopInteger();
				auto a4 = parser.PopInteger();
				printf("%d %d %d %d", a1, a2, a3, a4);
			}
			//printf("0x%.8X", message_info->size);
			break;
		}
		case N3T_CAST_NANO_SPELL:
		{			
			if(message_info->size == 0x25)
			{
				auto cast_nano_spell_message = CastNanoSpellMessage(parser);
				HandleCastNanoSpellMessage(cast_nano_spell_message);
			}			
			break;
		}
		case N3T_RESEARCH_UPDATE: break;
		case N3T_FOLLOW_TARGET:
		{
			if(message_info->size == 0x28)
			{
				auto follow_target_message = FollowTargetMessage(parser);
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
				auto attack_message = AttackMessage(parser);
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
				auto remove_pet_message = RemovePetMessage(parser);
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
				auto character_action_message = CharacterActionMessage(parser);
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

	void HandleAddPetMessage(AddPetMessage pet_message)
	{
		char pet[MAX_STRING];
		sprintf_s(pet, sizeof(pet), "%I64u",pet_message.Identity().CombinedIdentity());
		char *argv[] = { pet };
		pISInterface->ExecuteEvent(GetEventId("AO_onAddPet"), 0, 1, argv);
		//delete argv;
	}

	void HandleAttackMessage(AttackMessage attack_message)
	{
		char target[MAX_STRING];
		sprintf_s(target, sizeof(target), "%I64u", attack_message.Target().CombinedIdentity());
		char *argv[] = { target };
		pISInterface->ExecuteEvent(GetEventId("AO_onAttack"), 0, 1, argv);
		//delete argv;
	}

	void HandleCastNanoSpellMessage(CastNanoSpellMessage cast_nano_spell_message)
	{
		char nano_id[MAX_STRING];
		char target[MAX_STRING];
		char caster[MAX_STRING];
		sprintf_s(nano_id, sizeof(nano_id), "%d", cast_nano_spell_message.NanoId());
		sprintf_s(target, sizeof(target), "%I64u", cast_nano_spell_message.Target().CombinedIdentity());
		sprintf_s(caster, sizeof(caster), "%I64u", cast_nano_spell_message.Caster().CombinedIdentity());
		char *argv[] = { nano_id, target, caster };
		pISInterface->ExecuteEvent(GetEventId("AO_onCastNanoSpell"), 0, 3, argv);
		if (IsClientId(cast_nano_spell_message.Target().Id()))
			pISInterface->ExecuteEvent(GetEventId("AO_onCastNanoSpell_TargetSelf"), 0, 3, argv);
		else
			pISInterface->ExecuteEvent(GetEventId("AO_onCastNanoSpell_TargetOther"), 0, 3, argv);
		if (IsClientId(cast_nano_spell_message.Caster().Id()))
			pISInterface->ExecuteEvent(GetEventId("AO_onCastNanoSpell_CasterSelf"), 0, 3, argv);
		else
			pISInterface->ExecuteEvent(GetEventId("AO_onCastNanoSpell_CasterOther"), 0, 3, argv);
	}

	void HandleCharacterActionMessage(isxao_classes::CharacterActionMessage character_action_message)
	{
		switch (::TypeCharacterAction_e(character_action_message.CharacterActionType()))
		{
		case ::CAT_FINISH_NANO_CASTING:
		{
			char nano_id[MAX_STRING];
			sprintf_s(nano_id, sizeof(nano_id), "%d", character_action_message.Param2());
			char * argv[] = { nano_id };
			pISInterface->ExecuteEvent(GetEventId("AO_onFinishedCastingNano"), 0, 1, argv);
			break;
		}
		case ::CAT_SET_NANO_DURATION:
		{
			IDENTITY caster_identity;
			caster_identity.Type = 50000;
			caster_identity.Id = character_action_message.Param1();
			char nano_id[MAX_STRING];
			sprintf_s(nano_id, sizeof(nano_id), "%d", character_action_message.Identity().Id());
			char caster_id[MAX_STRING];
			sprintf_s(caster_id, sizeof(caster_id), "%I64u", caster_identity.GetCombinedIdentity());
			char duration[MAX_STRING];
			sprintf_s(duration, sizeof(duration), "%d", character_action_message.Param2());
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

	void HandleFollowTargetMessage(FollowTargetMessage follow_message)
	{
		char target[MAX_STRING];
		sprintf_s(target, sizeof(target), "%I64u", follow_message.Target().CombinedIdentity());
		char *argv[] = { target };
		pISInterface->ExecuteEvent(GetEventId("AO_onFollowTarget"), 0, 1, argv);
		//delete argv;
	}
	
	void HandleRemovePetMessage(RemovePetMessage remove_pet_message)
	{
		char pet[MAX_STRING];
		sprintf_s(pet, sizeof(pet), "%I64u", remove_pet_message.Identity().CombinedIdentity());
		char *argv[] = { pet };
		pISInterface->ExecuteEvent(GetEventId("AO_onRemovePet"), 0, 1, argv);
		//delete argv;
	}

	void HandleShieldAttackMessage(ShieldAttackMessage shield_attack_message)
	{
		char damage[MAX_STRING];
		char shieldee[MAX_STRING];
		sprintf_s(damage, sizeof(damage), "%d", shield_attack_message.DamageShielded());
		sprintf_s(shieldee, sizeof(shieldee), "%I64u", shield_attack_message.Shieldee().CombinedIdentity());
		char *argv[] = { damage, shieldee };
		pISInterface->ExecuteEvent(GetEventId("AO_onAttackShielded"), 0, 2, argv);
		//delete argv;
	}

#pragma endregion

}

using namespace isxao_utilities;
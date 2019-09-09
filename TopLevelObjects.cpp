#include "isxao_main.h"

// A LavishScript Top-Level Object is similar to a global C++ object.  The main difference is that
// a TLO can give ANY data type it wants; it is not limited to a single type.  You may wish to give
// a different type depending on the index (parameters, dimensions, etc) for example.  Usually, though,
// you simply give one specific type.

#pragma region AO

bool __cdecl TLO_AO(int argc, char *argv[], LSTYPEVAR &Dest)
{
	// argc and argv are used if the object access uses an index, such as AO[1] or 
	// AO[my coat,1,seventeen].  argc is the number of parameters (or dimensions) separated 
	// by commas, and does NOT include the name of the object.

	// LSTYPEVAR, used for Dest, is a VarPtr with a Type.  Type should be set to a pointer to a data type,
	// such as Dest.Type=pIntType for integers.  Do not set the Type or return true if the data retrieval
	// fails (there is no object).  For example, if the requested data is a string, and the string does
	// not exist, return false and do not set the type.

	Dest.DWord=1;
	Dest.Type=pAOType;
	return true;
}

#pragma endregion

#pragma region ISXAO

bool __cdecl TLO_ISXAO(int argc, char *argv[], LSTYPEVAR &Dest)
{
	Dest.DWord = 1;
	Dest.Type = pISXAOType;
	return true;
}

#pragma endregion

#pragma region Me

bool __cdecl TLO_ME(int argc, char *argv[], LSTYPEVAR &Dest)
{
	if(isxao_utilities::GetGameState() == GAMESTATE_IN_GAME)
	{
		Dest.Ptr = P_ENGINE_CLIENT_ANARCHY->get_client_char();
		Dest.Type = pCharacterType;
		return true;
	}
	return false;
}

#pragma endregion

#pragma region SelectionTarget

bool __cdecl TLO_SELECTIONTARGET(int argc, char *argv[], LSTYPEVAR &Dest)
{
	if (isxao_utilities::GetGameState() == GAMESTATE_IN_GAME)
	{
		identity_t identity;
		if (pSelectionIndicator)
		{
			auto d = GetDynel(pSelectionIndicator->identity);
			Dest.Ptr = d;
			Dest.Type = isxao_utilities::GetRealType(d);
			return true;
		}
	}
	return false;
}

#pragma endregion

#pragma region AttackTarget

bool __cdecl TLO_ATTACKTARGET(int argc, char *argv[], LSTYPEVAR &Dest)
{
	if (isxao_utilities::GetGameState() == GAMESTATE_IN_GAME)
	{
		identity_t identity;
		if (pAttackingIndicator)
		{
			auto d = reinterpret_cast<dynel*>(GetDynel(pAttackingIndicator->identity));
			Dest.Ptr = d;
			Dest.Type = isxao_utilities::GetRealType(d);
			return true;
		}
	}
	return false;
}

#pragma endregion

#pragma region ActorSearch

bool __cdecl TLO_ACTORSEARCH(int argc, char *argv[], LSTYPEVAR&Dest)
{
	if (isxao_utilities::GetGameState() == GAMESTATE_IN_GAME)
	{
		if (ISINDEX())
		{
			DWORD nth;
			SEARCHACTOR search_actor;
			ClearSearchActor(&search_actor);
			search_actor.f_radius = 999999.0f;
			identity_t identity;
			std::vector<Actor*> v;
			auto actor_count = P_PLAYFIELD_DIR->GetPlayfield()->GetPlayfieldActors(v);
			if (!ISNUMBER())
			{
				char first_arg[MAX_STRING];
				sprintf_s(first_arg, MAX_STRING, argv[0]);
				_strlwr_s(first_arg);
				if (!strcmp(first_arg, "me"))
				{
					Dest.Ptr = P_ENGINE_CLIENT_ANARCHY->get_client_char();
					Dest.Type = pCharacterType;
					return true;
				}
				nth = 1;
				ParseSearchActor(0, argc, argv, search_actor);
			}
			else
			{
				nth = GETNUMBER();
				ParseSearchActor(1, argc, argv, search_actor);
			}
			for (DWORD N = 0; N < actor_count; N++)
			{
				if (v[N]->get_distance_to_client() > search_actor.f_radius && !search_actor.is_known_location)
					return false;
				if (ActorMatchesSearch(&search_actor, P_ENGINE_CLIENT_ANARCHY->get_client_char(), v[N]))
				{
					if (--nth == 0)
					{
						Dest.Ptr = v[N];
						Dest.Type = GetRealType(v[N]);
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool __cdecl TLO_ACTORSEARCHCOUNT(int argc, char *argv[], LSTYPEVAR&Dest)
{
	if (isxao_utilities::GetGameState() == GAMESTATE_IN_GAME)
	{
		if (ISINDEX())
		{
			SEARCHACTOR search_actor;
			ClearSearchActor(&search_actor);
			ParseSearchActor(0, argc, argv, search_actor);
			Dest.DWord = CountMatchingActors(&search_actor, P_ENGINE_CLIENT_ANARCHY->get_client_char(), true);
			Dest.Type = pUintType;
			return true;
		}
		std::vector<Actor*> v;
		P_PLAYFIELD_DIR->GetPlayfield()->GetPlayfieldActors(v);
		Dest.DWord = v.size();
		Dest.Type = pUintType;
		return true;
	}
	return false;
}

#pragma endregion

#pragma region NanoSpell

bool __cdecl TLO_NANOSPELL(int argc, char *argv[], LSTYPEVAR&Dest)
{
	if (isxao_utilities::GetGameState() == GAMESTATE_IN_GAME)
	{
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				const identity_t i(53019, GETNUMBER());
				const identity_t d(0, 0);
				if ((Dest.Ptr = P_ENGINE_CLIENT_ANARCHY->get_item_by_template(i, d)))
				{
					Dest.Type = pNanoSpellType;
					return true;
				}
				return false;
			}
			char szName[MAX_STRING];
			char szSearchName[MAX_STRING];
			strcpy_s(szSearchName, MAX_STRING, argv[0]);
			_strlwr_s(szSearchName);
			std::map<DWORD, p_nano_item_t> m;
			::GetNanoMap(m);
			for (auto it = m.begin(); it != m.end(); ++it)
			{
				strcpy_s(szName, MAX_STRING, reinterpret_cast<NanoItem*>(it->second)->GetName());
				_strlwr_s(szName);

				if (strstr(szName, szSearchName))
				{
					if ((Dest.Ptr = it->second))
					{
						Dest.Type = pNanoSpellType;
						return true;
					}
					return false;
				}
			}
		}
	}
	return false;
}

#pragma endregion

#pragma region Playfield

bool __cdecl TLO_PLAYFIELD(int argc, char *argv[], LSTYPEVAR&Dest)
{
	if(isxao_utilities::GetGameState() == GAMESTATE_IN_GAME)
	{
		Dest.Ptr = P_PLAYFIELD_DIR->GetPlayfield();
		Dest.Type = pPlayfieldType;
		return true;
	}
	return false;
}

#pragma endregion

#pragma region TeamRaid

bool __cdecl TLO_TEAMRAID(int argc, char *argv[], LSTYPEVAR &Dest)
{
	if(isxao_utilities::GetGameState() == GAMESTATE_IN_GAME)
	{
		Dest.Ptr = P_ENGINE_CLIENT_ANARCHY->get_client_char()->GetTeamRaid();
		Dest.Type = pTeamRaidType;
		return true;
	}
	return false;
}

#pragma endregion

#pragma region SpecialAction

bool __cdecl TLO_SPECIALACTION(int argc, char *argv[], LSTYPEVAR&Dest)
{
	if(isxao_utilities::GetGameState() == GAMESTATE_IN_GAME)
	{
		if(ISINDEX())
		{
			if(ISNUMBER())
			{
				identity_t dummy_identity;
				identity_t identity;
				identity.type = 57008;
				identity.id = atoi(argv[0]);
				if ((Dest.Ptr = P_ENGINE_CLIENT_ANARCHY->get_item_by_template(identity, dummy_identity)))
				{
					Dest.Type = pSpecialActionType;
					return true;
				}
				return false;
			}
			char name[MAX_STRING];
			char search_name[MAX_STRING];
			strcpy_s(search_name, sizeof(search_name), argv[0]);
			_strlwr_s(search_name);
			std::vector<SpecialActionTemplate*> v;
			P_ENGINE_CLIENT_ANARCHY->get_client_char()->GetSpecialActionHolder()->GetSpecialActions(v);
			for (auto it = v.begin(); it != v.end(); ++it)
			{
				strcpy_s(name, sizeof(name), (*it)->GetName());
				_strlwr_s(name);
				if(strstr(name, search_name))
				{
					if((Dest.Ptr = (*it)))
					{
						Dest.Type = pSpecialActionType;
						return true;
					}
					return false;
				}
			}
			return false;
		}
		return false;
	}
	return false;
}

#pragma endregion
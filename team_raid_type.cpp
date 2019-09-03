#include "isxao_main.h"

bool TeamRaidType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pTeamRaid ((TeamRaid*)ObjectData.Ptr)
		switch (TeamRaidTypeMembers(Member->ID))
		{
		case Leader:
		{
			if((Object.Ptr = pTeamRaid->GetTeamLeader()))
			{
				Object.Type = pTeamEntryType;
				return true;
			}
			return false;
		}
		case RaidCount:
		{
			Object.DWord = pTeamRaid->GetRaidCount();
			Object.Type = pUintType;
			break;
		}
		case Raid:
		{
			if(ISINDEX())
			{
				DWORD index = GETNUMBER();
				if((Object.Ptr = pTeamRaid->GetRaidMember(index - 1)))
				{
					Object.Type = pTeamEntryType;
					return true;
				}
				return false;
			}
			if ((Object.Ptr = pTeamRaid->GetRaidMember(argv[0])))
			{
				Object.Type = pTeamEntryType;
				return true;
			}
			return false;
		}
		case TeamCount:
		{
			Object.DWord = pTeamRaid->GetTeamCount();
			Object.Type = pUintType;
			break;
		}
		case Team:
		{
			if (ISINDEX())
			{
				DWORD index = GETNUMBER();
				if ((Object.Ptr = pTeamRaid->GetTeamMember(index - 1)))
				{
					Object.Type = pTeamEntryType;
					return true;
				}
				return false;
			}
			if ((Object.Ptr = pTeamRaid->GetTeamMember(argv[0])))
			{
				Object.Type = pTeamEntryType;
				return true;
			}
			return false;
		}
		case GetTeam:
		{
			if(ISINDEX())
			{
				LSOBJECT IndexObject;
				if (!pISInterface->DataParse(argv[0], IndexObject))
					return false;
				if (IndexObject.Type != pIndexType)
					return false;
				LSIndex *pIndex = (LSIndex*)IndexObject.Ptr;
				if (pIndex->GetType() != pTeamEntryType)
					return false;
				Object.DWord = pTeamRaid->BuildLSTeam(pIndex);
				Object.Type = pUintType;
				return true;
			}
			return false;
		}
		case GetRaid:
		{
			if (ISINDEX())
			{
				LSOBJECT IndexObject;
				if (!pISInterface->DataParse(argv[0], IndexObject))
					return false;
				if (IndexObject.Type != pIndexType)
					return false;
				LSIndex *pIndex = (LSIndex*)IndexObject.Ptr;
				if (pIndex->GetType() != pTeamEntryType)
					return false;
				Object.DWord = pTeamRaid->BuildLSRaid(pIndex);
				Object.Type = pUintType;
				return true;
			}
			return false;
		}
		default:
			return false;
		}
#undef pTeamRaid
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool TeamRaidType::GetMethod(LSOBJECTDATA& ObjectData, PLSTYPEMETHOD pMethod, int argc, char* argv[])
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pTeamRaid ((TeamRaid*)ObjectData.Ptr)
		switch (TeamRaidTypeMethods(pMethod->ID))
		{
		case CreateRaid:
		{
			pTeamRaid->CreateRaid();
			return true;
		}
		default: break;
		}
#undef pTeamRaid
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, pMethod->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool TeamRaidType::ToText(LSOBJECTDATA ObjectData, char* buf, unsigned buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define pTeamRaid ((TeamRaid*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%I64d", pTeamRaid->GetTeamIdentity().get_combined_identity());
#undef pTeamRaid
	return true;
}
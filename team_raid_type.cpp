#include "isxao_main.h"

bool TeamRaidType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define P_TEAM_RAID ((ao::team_raid*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (TeamRaidTypeMembers(Member->ID))
		{
		case Leader:
		{
			if((Object.Ptr = P_TEAM_RAID->get_team_leader()))
			{
				Object.Type = pTeamEntryType;
				return true;
			}
			return false;
		}
		case RaidCount:
		{
			Object.DWord = P_TEAM_RAID->get_raid_count();
			Object.Type = pUintType;
			break;
		}
		case Raid:
		{
			if(IS_INDEX())
			{
				DWORD index = GET_NUMBER();
				if((Object.Ptr = P_TEAM_RAID->get_raid_member(index - 1)))
				{
					Object.Type = pTeamEntryType;
					return true;
				}
				return false;
			}
			if ((Object.Ptr = P_TEAM_RAID->get_raid_member(argv[0])))
			{
				Object.Type = pTeamEntryType;
				return true;
			}
			return false;
		}
		case TeamCount:
		{
			Object.DWord = P_TEAM_RAID->get_team_count();
			Object.Type = pUintType;
			break;
		}
		case Team:
		{
			if (IS_INDEX())
			{
				DWORD index = GET_NUMBER();
				if ((Object.Ptr = P_TEAM_RAID->get_team_member(index - 1)))
				{
					Object.Type = pTeamEntryType;
					return true;
				}
				return false;
			}
			if ((Object.Ptr = P_TEAM_RAID->get_team_member(argv[0])))
			{
				Object.Type = pTeamEntryType;
				return true;
			}
			return false;
		}
		case GetTeam:
		{
			if(IS_INDEX())
			{
				LSOBJECT IndexObject;
				if (!pISInterface->DataParse(argv[0], IndexObject))
					return false;
				if (IndexObject.Type != pIndexType)
					return false;
				LSIndex *pIndex = (LSIndex*)IndexObject.Ptr;
				if (pIndex->GetType() != pTeamEntryType)
					return false;
				Object.DWord = P_TEAM_RAID->build_ls_team(pIndex);
				Object.Type = pUintType;
				return true;
			}
			return false;
		}
		case GetRaid:
		{
			if (IS_INDEX())
			{
				LSOBJECT IndexObject;
				if (!pISInterface->DataParse(argv[0], IndexObject))
					return false;
				if (IndexObject.Type != pIndexType)
					return false;
				LSIndex *pIndex = (LSIndex*)IndexObject.Ptr;
				if (pIndex->GetType() != pTeamEntryType)
					return false;
				Object.DWord = P_TEAM_RAID->build_ls_raid(pIndex);
				Object.Type = pUintType;
				return true;
			}
			return false;
		}
		default:
			return false;
		}
#undef P_TEAM_RAID
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
#define P_TEAM_RAID ((ao::team_raid*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (TeamRaidTypeMethods(pMethod->ID))
		{
		case CreateRaid:
		{
			P_TEAM_RAID->create_raid();
			return true;
		}
		default: break;
		}
#undef P_TEAM_RAID
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
#define P_TEAM_RAID ((ao::team_raid*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
	sprintf_s(buf, buflen, "%I64d", P_TEAM_RAID->get_team_identity().get_combined_identity());
#undef P_TEAM_RAID
	return true;
}
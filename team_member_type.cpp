#include "isxao_main.h"

bool TeamMemberType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pTeamMember ((TeamMember*)ObjectData.Ptr)
		switch (TeamMemberTypeMembers(Member->ID))
		{
		case CurrentNano:
		{
			Object.DWord = pTeamMember->GetSkill(ST_CURRENTNANO);
			Object.Type = pUintType;
			break;
		}
		case IsInMyRaidTeam:
		{
			Object.DWord = pTeamMember->IsInMyRaidTeam();
			Object.Type = pBoolType;
			break;
		}
		case MaxNano:
		{
			Object.DWord = pTeamMember->GetSkill(ST_MAXNANOENERGY);
			Object.Type = pUintType;
			break;
		}
		case PctNano:
		{
			Object.DWord = pTeamMember->GetSkill(ST_PERCENTREMAININGNANO);
			Object.Type = pUintType;
			break;
		}
		default:
			return false;
		}
#undef pTeamMember
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool TeamMemberType::GetMethod(LSOBJECTDATA& ObjectData, PLSTYPEMETHOD pMethod, int argc, char* argv[])
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pTeamMember ((TeamMember*)ObjectData.Ptr)
		switch (TeamMemberTypeMethods(pMethod->ID))
		{
		case Kick:
		{
			pTeamMember->Kick();
			break;
		}
		case MakeLeader:
		{
			pTeamMember->MakeLeader();
			break;
		}
		//case MoveRaidMember:
		//{
		//	if(ISINDEX())
		//	{
		//		auto index = GETNUMBER();
		//		printf("%d", index);
		//		pTeamMember->MoveRaidMember(index);
		//		return true;
		//	}
		//	return false;
		//}
		default: break;
		}
#undef pTeamMember
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, pMethod->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool TeamMemberType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define pTeamMember ((TeamMember*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%I64d", pTeamMember->GetIdentity().GetCombinedIdentity());
#undef pTeamMember

	return true;
}
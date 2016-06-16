#include "isxao_main.h"

bool PlayerType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pPlayer ((Player*)ObjectData.Ptr)
		switch (PlayerTypeMembers(Member->ID))
		{
		case IsInMyTeam:
		{
			Object.DWord = pPlayer->IsInMyTeam();
			Object.Type = pBoolType;
			break;
		}
		case IsInTeam:
		{
			Object.DWord = pPlayer->IsInTeam();
			Object.Type = pBoolType;
			break;
		}
		case ProfessionLevel:
		{
			Object.DWord = pPlayer->GetSkill(::ST_PROFESSIONLEVEL);
			Object.Type = pUintType;
			break;
		}
		case VisualProfession:
		{
			Object.ConstCharPtr = GetProfessionStr(pPlayer->GetSkill(::ST_VISUALPROFESSION));
			Object.Type = pStringType;
			break;
		}
		default:
			return false;
		}
#undef pPlayer
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool PlayerType::GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[])
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pPlayer ((Player*)ObjectData.Ptr)
		switch (PlayerTypeMethods(pMethod->ID))
		{
		case Invite:
		{
			pPlayer->SendTeamInvite();
			break;
		}
		default: break;
		}
#undef pPlayer
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, pMethod->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool PlayerType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define pPlayer ((Player*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%I64u", pPlayer->GetIdentity().GetCombinedIdentity());
#undef pPlayer

	return true;
}
#include "isxao_main.h"

bool TeamEntryType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pTeamEntry ((TeamEntry*)ObjectData.Ptr)
		switch (TeamEntryTypeMembers(Member->ID))
		{
		case Name:
		{
			Object.ConstCharPtr = pTeamEntry->GetName();
			Object.Type = pStringType;
			break;
		}
		case Identity:
		{
			auto identity = pTeamEntry->GetIdentity();
			auto p_identity = pISInterface->GetTempBuffer(sizeof(IDENTITY), &identity);
			Object.Ptr = p_identity;
			Object.Type = pIdentityType;
			break;
		}
		case ToTeamMember:
		{
			if((Object.Ptr = static_cast<TeamMember*>(isxao_utilities::GetDynel(pTeamEntry->GetIdentity()))))
			{
				Object.Type = pActorType;
				return true;
			}
			return false;
		}
		default:
			return false;
		}
#undef pTeamEntry
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool TeamEntryType::GetMethod(LSOBJECTDATA& ObjectData, PLSTYPEMETHOD pMethod, int argc, char* argv[])
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pTeamEntry ((TeamEntry*)ObjectData.Ptr)
		switch (TeamEntryTypeMethods(pMethod->ID))
		{
		case Kick:
		{
			P_ENGINE_CLIENT_ANARCHY->N3Msg_KickTeamMember(pTeamEntry->GetIdentity());
			break;
		}
		case MakeLeader:
		{
			P_ENGINE_CLIENT_ANARCHY->N3Msg_TransferTeamLeadership(pTeamEntry->GetIdentity());
			break;
		}
		default: break;
		}
#undef pTeamEntry
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, pMethod->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool TeamEntryType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define pTeamEntry ((TeamMember*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%I64u", pTeamEntry->GetIdentity().GetCombinedIdentity());
#undef pTeamEntry

	return true;
}
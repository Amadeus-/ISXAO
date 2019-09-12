#include "isxao_main.h"

bool TeamEntryType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define P_TEAM_ENTRY ((team_entry*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (TeamEntryTypeMembers(Member->ID))
		{
		case Name:
		{
			Object.ConstCharPtr = P_TEAM_ENTRY->get_name();
			Object.Type = pStringType;
			break;
		}
		case Identity:
		{
			auto identity = P_TEAM_ENTRY->get_identity();
			const auto p_identity = pISInterface->GetTempBuffer(sizeof(identity_t), &identity);
			Object.Ptr = p_identity;
			Object.Type = pIdentityType;
			break;
		}
		case ToTeamMember:
		{
			if((Object.Ptr = reinterpret_cast<team_member*>(isxao_classes::dynel::get_dynel(P_TEAM_ENTRY->get_identity()))))
			{
				Object.Type = pActorType;
				return true;
			}
			return false;
		}
		default:
			return false;
		}
#undef P_TEAM_ENTRY
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
#define P_TEAM_ENTRY ((team_entry*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (TeamEntryTypeMethods(pMethod->ID))
		{
		case Kick:
		{
			P_ENGINE_CLIENT_ANARCHY->N3Msg_KickTeamMember(P_TEAM_ENTRY->get_identity());
			break;
		}
		case MakeLeader:
		{
			P_ENGINE_CLIENT_ANARCHY->N3Msg_TransferTeamLeadership(P_TEAM_ENTRY->get_identity());
			break;
		}
		default: break;
		}
#undef P_TEAM_ENTRY
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
#define P_TEAM_ENTRY ((team_entry*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
	sprintf_s(buf, buflen, "%I64u", P_TEAM_ENTRY->get_identity().get_combined_identity());
#undef P_TEAM_ENTRY

	return true;
}
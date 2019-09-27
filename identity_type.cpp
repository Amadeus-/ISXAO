#include "isxao_main.h"

bool IdentityType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (ao::g_game_state != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define P_IDENTITY ((ao::identity_t*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (IdentityTypeMembers(Member->ID))
		{
		case Type:
		{
			Object.DWord = P_IDENTITY->type;
			Object.Type = pUintType;
			break;
		}
		case Id:
		{
			Object.DWord = P_IDENTITY->id;
			Object.Type = pUintType;
			break;
		}
		case Combined:
		{
			Object.Int64 = P_IDENTITY->get_combined_identity();
			Object.Type = pInt64Type;
			break;
		}
		default:
			return false;
		}
#undef P_IDENTITY
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool IdentityType::ToText(LSOBJECTDATA ObjectData, char* buf, unsigned buflen)
{
	if (ao::g_game_state != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define P_IDENTITY ((ao::identity_t*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
	sprintf_s(buf, buflen, "%I64d", P_IDENTITY->get_combined_identity());
#undef P_IDENTITY
	return true;
}
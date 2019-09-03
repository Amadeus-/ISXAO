#include "isxao_main.h"

bool IdentityType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pIdentity ((identity_t*)ObjectData.Ptr)
		switch (IdentityTypeMembers(Member->ID))
		{
		case Type:
		{
			Object.DWord = pIdentity->type;
			Object.Type = pUintType;
			break;
		}
		case Id:
		{
			Object.DWord = pIdentity->id;
			Object.Type = pUintType;
			break;
		}
		case Combined:
		{
			Object.Int64 = pIdentity->get_combined_identity();
			Object.Type = pInt64Type;
			break;
		}
		default:
			return false;
		}
#undef pIdentity
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool IdentityType::ToText(LSOBJECTDATA ObjectData, char* buf, unsigned buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define pIdentity ((identity_t*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%I64d", pIdentity->get_combined_identity());
#undef pIdentity
	return true;
}
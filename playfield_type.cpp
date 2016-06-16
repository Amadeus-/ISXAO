#include "isxao_main.h"

bool PlayfieldType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pPlayfield ((PlayfieldAnarchy*)ObjectData.Ptr)
		switch (PlayfieldTypeMembers(Member->ID))
		{
		case Name:
		{
			Object.ConstCharPtr = pPlayfield->GetPlayfieldName();
			Object.Type = pStringType;
			break;
		}
		case ID:
		{
			Object.DWord = pPlayfield->GetPlayfieldInstance();
			Object.Type = pUintType;
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

bool PlayfieldType::ToText(LSOBJECTDATA ObjectData, char* buf, unsigned buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define pPlayfield ((PlayfieldAnarchy*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%s", pPlayfield->GetPlayfieldName());
#undef pIdentity
	return true;
}
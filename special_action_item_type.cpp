#include "isxao_main.h"

bool SpecialActionItemType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pSpecialActionItem ((SpecialActionItem*)ObjectData.Ptr)
		switch (SpecialActionItemTypeMembers(Member->ID))
		{
		case IsGeneralAction:
		{
			Object.DWord = pSpecialActionItem->IsGeneralAction();
			Object.Type = pBoolType;
			break;
		}
		case IsPerk:
		{
			Object.DWord = pSpecialActionItem->IsPerk();
			Object.Type = pBoolType;
			break;
		}
		case IsSpecialAction:
		{
			Object.DWord = pSpecialActionItem->IsSpecialAction();
			Object.Type = pBoolType;
			break;
		}
		default: break;
		}
#undef pSpecialActionItem
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool SpecialActionItemType::GetMethod(LSOBJECTDATA& ObjectData, PLSTYPEMETHOD pMethod, int argc, char* argv[])
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pSpecialActionItem ((SpecialActionItem*)ObjectData.Ptr)
		switch (SpecialActionItemTypeMethods(pMethod->ID))
		{

		default: break;
		}
#undef pSpecialActionItem
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, pMethod->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool SpecialActionItemType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define pSpecialActionItem ((SpecialActionItem*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%s", "Item");
#undef pSpecialActionItem

	return true;
}
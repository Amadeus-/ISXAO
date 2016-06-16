#include "isxao_main.h"

bool SpecialActionType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pSpecialAction ((SpecialAction*)ObjectData.Ptr)
		switch (SpecialActionTypeMembers(Member->ID))
		{		
		case Identity:
		{
			IDENTITY id = pSpecialAction->GetIdentity();
			PIDENTITY pId = PIDENTITY(pISInterface->GetTempBuffer(sizeof(IDENTITY), &id));
			Object.Ptr = pId;
			Object.Type = pIdentityType;
			break;
		}
		case Name:
		{
			Object.ConstCharPtr = pSpecialAction->GetName();
			Object.Type = pStringType;
			break;
		}
		case IsLocked:
		{
			Object.DWord = pSpecialAction->IsLocked();
			Object.Type = pBoolType;
			break;
		}
		case LockInfo:
		{
			if((Object.Ptr = pEngineClientAnarchy->GetClientChar()->GetStatHolder()->GetSkillLock(pSpecialAction)))
			{
				Object.Type = pActionLockType;
				return true;
			}
			return false;
		}
		default: 
			break;
		}
#undef pSpecialAction
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool SpecialActionType::GetMethod(LSOBJECTDATA& ObjectData, PLSTYPEMETHOD pMethod, int argc, char* argv[])
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pSpecialAction ((SpecialAction*)ObjectData.Ptr)
		switch (SpecialActionTypeMethods(pMethod->ID))
		{
		case Use:
		{
			pEngineClientAnarchy->N3Msg_PerformSpecialAction(pSpecialAction->GetIdentity());
			return true;
		}
		default: break;
		}
#undef pNanoTemplate
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, pMethod->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool SpecialActionType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define pSpecialAction ((SpecialAction*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%I64u", pSpecialAction->GetIdentity().GetCombinedIdentity());
#undef pSpecialAction

	return true;
}
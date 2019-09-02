#include "isxao_main.h"

bool SpecialActionTemplateType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pSpecialActionTemplate ((SpecialActionTemplate*)ObjectData.Ptr)
		switch (SpecialActionTemplateTypeMembers(Member->ID))
		{		
		case Identity:
		{
			IDENTITY id = pSpecialActionTemplate->GetIdentity();
			PIDENTITY pId = PIDENTITY(pISInterface->GetTempBuffer(sizeof(IDENTITY), &id));
			Object.Ptr = pId;
			Object.Type = pIdentityType;
			break;
		}
		case Name:
		{
			Object.ConstCharPtr = pSpecialActionTemplate->GetName();
			Object.Type = pStringType;
			break;
		}
		case IsLocked:
		{
			Object.DWord = pSpecialActionTemplate->IsLocked();
			Object.Type = pBoolType;
			break;
		}
		case LockOutRemaining:
		{
			Object.DWord = pSpecialActionTemplate->GetLockoutTimeRemaining();
			Object.Type = pUintType;
			break;
		}
		default: 
			break;
		}
#undef pSpecialActionTemplate
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool SpecialActionTemplateType::GetMethod(LSOBJECTDATA& ObjectData, PLSTYPEMETHOD pMethod, int argc, char* argv[])
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pSpecialActionTemplate ((SpecialActionTemplate*)ObjectData.Ptr)
		switch (SpecialActionTemplateTypeMethods(pMethod->ID))
		{
		case Use:
		{
			P_ENGINE_CLIENT_ANARCHY->N3Msg_PerformSpecialAction(pSpecialActionTemplate->GetIdentity());
			return true;
		}
		default: break;
		}
#undef pSpecialActionTemplate
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, pMethod->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool SpecialActionTemplateType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define pSpecialActionTemplate ((SpecialActionTemplate*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%d", pSpecialActionTemplate->GetIdentity().Id);
#undef pSpecialActionTemplate

	return true;
}
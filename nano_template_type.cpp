#include "isxao_main.h"

bool NanoTemplateType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pNanoTemplate ((NanoTemplate*)ObjectData.Ptr)
		switch (NanoTemplateTypeMembers(Member->ID))
		{
		case CasterId:
		{
			IDENTITY id = pNanoTemplate->GetCasterIdentity();
			PIDENTITY pId = static_cast<PIDENTITY>(pISInterface->GetTempBuffer(sizeof(IDENTITY), &id));
			Object.Ptr = pId;
			Object.Type = pIdentityType;
			break;
		}
		case NanoId:
		{
			Object.DWord = pNanoTemplate->GetNanoIdentity().Id;
			Object.Type = pUintType;
			break;
		}
		case TimeCast:
		{
			Object.DWord = pNanoTemplate->GetStartTime() / 100;
			Object.Type = pUintType;
			break;
		}
		case TimeRemaining:
		{
			Object.Float = pNanoTemplate->GetTimeRemaining();
			Object.Type = pfloatType;
			break;
		}
		case TotalDuration:
		{
			Object.DWord = pNanoTemplate->GetDuration() / 100;
			Object.Type = pUintType;
			break;
		}
		default: break;
		}
#undef pNanoTemplate
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool NanoTemplateType::GetMethod(LSOBJECTDATA& ObjectData, PLSTYPEMETHOD pMethod, int argc, char* argv[])
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pNanoTemplate ((NanoTemplate*)ObjectData.Ptr)
		switch (NanoTemplateTypeMethods(pMethod->ID))
		{
		case Remove:
		{
			pNanoTemplate->Remove();
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

bool NanoTemplateType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define pNanoTemplate ((NanoTemplate*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%d", pNanoTemplate->GetNanoIdentity().Id);
#undef pNanoTemplate

	return true;
}
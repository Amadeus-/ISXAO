#include "isxao_main.h"

bool NanoTemplateType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define P_NANO_TEMPLATE ((nano_template*)ObjectData.Ptr)
		switch (NanoTemplateTypeMembers(Member->ID))
		{
		case CasterId:
		{
			identity_t id = P_NANO_TEMPLATE->get_caster_identity();
			p_identity_t pId = static_cast<p_identity_t>(pISInterface->GetTempBuffer(sizeof(identity_t), &id));
			Object.Ptr = pId;
			Object.Type = pIdentityType;
			break;
		}
		case NanoId:
		{
			Object.DWord = P_NANO_TEMPLATE->get_nano_identity().id;
			Object.Type = pUintType;
			break;
		}
		case TimeCast:
		{
			Object.DWord = P_NANO_TEMPLATE->get_start_time() / 100;
			Object.Type = pUintType;
			break;
		}
		case TimeRemaining:
		{
			Object.Float = P_NANO_TEMPLATE->get_time_remaining();
			Object.Type = pfloatType;
			break;
		}
		case TotalDuration:
		{
			Object.DWord = P_NANO_TEMPLATE->get_duration() / 100;
			Object.Type = pUintType;
			break;
		}
		default: break;
		}
#undef P_NANO_TEMPLATE
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
#define P_NANO_TEMPLATE ((nano_template*)ObjectData.Ptr)
		switch (NanoTemplateTypeMethods(pMethod->ID))
		{
		case Remove:
		{
			P_NANO_TEMPLATE->remove();
			return true;
		}
		default: break;
		}
#undef P_NANO_TEMPLATE
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
#define P_NANO_TEMPLATE ((nano_template*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%d", P_NANO_TEMPLATE->get_nano_identity().id);
#undef P_NANO_TEMPLATE

	return true;
}
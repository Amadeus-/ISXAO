#include "isxao_main.h"

bool SpecialActionTemplateType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define P_SPECIAL_ACTION_TEMPLATE ((ao::special_action_template*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (SpecialActionTemplateTypeMembers(Member->ID))
		{		
		case Identity:
		{
			auto id = P_SPECIAL_ACTION_TEMPLATE->get_identity();
			const auto pId = ao::p_identity_t(pISInterface->GetTempBuffer(sizeof(ao::identity_t), &id));
			Object.Ptr = pId;
			Object.Type = pIdentityType;
			break;
		}
		case Name:
		{
			Object.ConstCharPtr = P_SPECIAL_ACTION_TEMPLATE->get_name();
			Object.Type = pStringType;
			break;
		}
		case IsLocked:
		{
			Object.DWord = P_SPECIAL_ACTION_TEMPLATE->is_locked();
			Object.Type = pBoolType;
			break;
		}
		case LockOutRemaining:
		{
			Object.DWord = P_SPECIAL_ACTION_TEMPLATE->get_lockout_time_remaining();
			Object.Type = pUintType;
			break;
		}
		default: 
			break;
		}
#undef P_SPECIAL_ACTION_TEMPLATE
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
#define P_SPECIAL_ACTION_TEMPLATE ((ao::special_action_template*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (SpecialActionTemplateTypeMethods(pMethod->ID))
		{
		case Use:
		{
			P_ENGINE_CLIENT_ANARCHY->n3_msg_perform_special_action(P_SPECIAL_ACTION_TEMPLATE->get_identity());
			return true;
		}
		default: break;
		}
#undef P_SPECIAL_ACTION_TEMPLATE
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
#define P_SPECIAL_ACTION_TEMPLATE ((ao::special_action_template*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
	sprintf_s(buf, buflen, "%d", P_SPECIAL_ACTION_TEMPLATE->get_identity().id);
#undef P_SPECIAL_ACTION_TEMPLATE

	return true;
}
#include "isxao_main.h"

bool NanoTemplateType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (g_game_state != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define P_NANO_TEMPLATE ((ao::nano_template*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (NanoTemplateTypeMembers(Member->ID))
		{
		case CasterId:
		{
			auto id = P_NANO_TEMPLATE->get_caster_identity();
			const auto p_id = static_cast<ao::p_identity_t>(pISInterface->GetTempBuffer(sizeof(ao::identity_t), &id));
			Object.Ptr = p_id;
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
	if (g_game_state != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define P_NANO_TEMPLATE ((ao::nano_template*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (NanoTemplateTypeMethods(pMethod->ID))
		{
		case Remove:
		{
			// ReSharper disable once CppExpressionWithoutSideEffects
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
	if (g_game_state != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define P_NANO_TEMPLATE ((ao::nano_template*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
	sprintf_s(buf, buflen, "%d", P_NANO_TEMPLATE->get_nano_identity().id);
#undef P_NANO_TEMPLATE

	return true;
}
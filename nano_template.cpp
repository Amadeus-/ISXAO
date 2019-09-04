#include "isxao_main.h"

namespace isxao_classes
{

	identity_t NanoTemplate::GetCasterIdentity() const
	{
		return GetNanoTemplateData().caster_identity;
	}

	DWORD NanoTemplate::GetDuration() const
	{
		return GetNanoTemplateData().duration;
	}

	identity_t NanoTemplate::GetNanoIdentity() const
	{
		return GetNanoTemplateData().nano_identity;
	}

	nano_template_t NanoTemplate::GetNanoTemplateData() const
	{
		return nano_template_;
	}

	DWORD NanoTemplate::GetStartTime() const
	{
		return GetNanoTemplateData().start_time;
	}

	float NanoTemplate::GetTimeRemaining() const
	{
		auto result = 0.0f;
		result = float(float((GetStartTime() + GetDuration()) / 100) - pGametime->GetNormalTime());
		if (result < 0.0f)
			result = 0.0f;
		return result;
	}

	bool NanoTemplate::NanoTemplateCompare(NanoTemplate &a, NanoTemplate &b)
	{
		return a.GetNanoIdentity().id < b.GetNanoIdentity().id;
	}

	bool NanoTemplate::Remove() const
	{
		return P_ENGINE_CLIENT_ANARCHY->N3Msg_RemoveBuff(GetNanoIdentity());
	}

}
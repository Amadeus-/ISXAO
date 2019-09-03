#include "isxao_main.h"

namespace isxao_classes
{

	identity_t NanoTemplate::GetCasterIdentity() const
	{
		return GetNanoTemplateData().CasterIdentity;
	}

	DWORD NanoTemplate::GetDuration() const
	{
		return GetNanoTemplateData().Duration;
	}

	identity_t NanoTemplate::GetNanoIdentity() const
	{
		return GetNanoTemplateData().NanoIdentity;
	}

	NANOTEMPLATE NanoTemplate::GetNanoTemplateData() const
	{
		return nano_template_;
	}

	DWORD NanoTemplate::GetStartTime() const
	{
		return GetNanoTemplateData().StartTime;
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
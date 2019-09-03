#include "isxao_main.h"

namespace isxao_classes
{
	void InputConfig::SetCurrentTarget(const identity_t& id)
	{
		typedef void(__thiscall * tSetCurrentTarget)(PVOID, const identity_t&);
		auto pSetCurrentTarget = tSetCurrentTarget(InputConfig_t__SetCurrentTarget);
		pSetCurrentTarget(this, id);
	}
}


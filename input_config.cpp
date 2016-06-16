#include "isxao_main.h"

namespace isxao_classes
{
	void InputConfig::SetCurrentTarget(const IDENTITY& id)
	{
		typedef void(__thiscall * tSetCurrentTarget)(PVOID, const IDENTITY&);
		auto pSetCurrentTarget = tSetCurrentTarget(InputConfig_t__SetCurrentTarget);
		pSetCurrentTarget(this, id);
	}
}


#pragma once
#include "isxao_main.h"

namespace isxao
{
	namespace events
	{
		bool RegisterEvents();

		int GetEventId(PCSTR pszEvent);
	}
}

#pragma once
#include "isxao_main.h"

namespace isxao_events
{

	bool RegisterEvents();

	int GetEventId(PCSTR pszEvent);

}

using namespace isxao_events;
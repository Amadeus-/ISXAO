#include "isxao_main.h"

namespace ao
{
#ifdef INPUT_CONFIG_T__SET_CURRENT_TARGET_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(void input_config::set_current_target(const identity_t&), input_config_t__set_current_target)
#else
	static_assert(false, "input_config::set_current_target(const identity_t&) requires a native function.");
#endif
}


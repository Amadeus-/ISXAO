#include "isxao_main.h"

namespace ao
{

#if true
	FUNCTION_AT_ADDRESS(void targeting_module::remove_target(const identity_t &), targeting_module_t__remove_target)
#else
	static_assert(false, "targeting_module::remove_target(const identity_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void targeting_module::select_self(), targeting_module_t__select_self)
#else
	static_assert(false, "targeting_module::set_target(const identity_t&, bool) requires a native function.");
#endif

#if true
	FUNCTION_AT_ADDRESS(void targeting_module::set_target(const identity_t&, bool), targeting_module_t__set_target)
#else
	static_assert(false, "targeting_module::set_target(const identity_t&, bool) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void targeting_module::set_target_pet(DWORD), targeting_module_t__set_target_pet)
#else
	static_assert(false, "targeting_module::set_target_pet(DWORD) requires a native function.");
#endif

}


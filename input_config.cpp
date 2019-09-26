#include "isxao_main.h"

namespace ao
{
#ifdef INPUT_CONFIG_T__SET_CURRENT_TARGET_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void input_config::set_current_target(const identity_t&), input_config_t__set_current_target)
#else
	static_assert(false, "input_config::set_current_target(const identity_t&) requires a native function.");
#endif

#ifdef false
	static_assert(false, "input_config::get_method_id_name(const DWORD id) does not have a native function.");
#else
	PCSTR input_config::get_method_id_name(const DWORD id)
	{
		for (auto i = 0; i < 0x7E ; i++)
		{
			if (P_INPUT_METHOD_ID_TABLE->list[i].id == id)
				return P_INPUT_METHOD_ID_TABLE->list[i].name;
		}
		return nullptr;
	}
#endif

#if false
	static_assert(false, "input_config::get_mode_id_name(const DWORD id) does not have a native function.");
#else
	PCSTR input_config::get_mode_id_name(const DWORD id)
	{
		for (auto i = 0; i < 0x3F; i++)
		{
			if (P_INPUT_MODE_ID_TABLE->list[i].id == id)
				return P_INPUT_MODE_ID_TABLE->list[i].name;
		}
		return nullptr;
	}
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(char input_config::process_input(ao::keypress_info_t, DWORD), input_config_t__process_input)
#else
	static_assert(false, "input_config::process_input(ao::keypress_info_t) requires a native function.");
#endif

}


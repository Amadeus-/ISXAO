#include "isxao_main.h"
#include "command_interpreter.h"

namespace ao
{

#if false
	static_assert(false, "command_interpreter::parse_text(string& text) does not have a native function.");
#else
	bool command_interpreter::parse_text(string& text)
	{
		return parse_text(nullptr, text);
}
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool command_interpreter::parse_text(chat_window_node*, string&), command_interpreter_c__parse_text_command)
#else
	static_assert(false, "engine_client_anarchy::get_faction_str(DWORD, bool) requires a native function.");
#endif

}

#include "isxao_main.h"

namespace ao
{

	command_interpreter_t command_interpreter::get_command_interpreter_data() const
	{
		return command_interpreter_;
	}

	bool command_interpreter::parse_text(string& text)
	{
		return parse_text(nullptr, text);
	}

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(bool command_interpreter::parse_text(chat_window_node*, string&), command_interpreter_c__parse_text_command)
#else
	static_assert(false, "engine_client_anarchy::get_faction_str(DWORD, bool) requires a native function.");
#endif

}

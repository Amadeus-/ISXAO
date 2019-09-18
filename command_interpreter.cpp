#include "isxao_main.h"

namespace ao
{

	command_interpreter_t command_interpreter::get_command_interpreter_data() const
	{
		return command_interpreter_;
	}

	bool command_interpreter::ParseText(string& text)
	{
		return ParseText(nullptr, text);
	}

	FUNCTION_AT_ADDRESS(bool command_interpreter::ParseText(chat_window_node*, string&), CommandInterpreter_c__ParseTextCommand);

}

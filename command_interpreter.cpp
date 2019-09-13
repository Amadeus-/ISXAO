#include "isxao_main.h"

namespace isxao_classes
{

	command_interpreter_t CommandInterpreter::GetCommandInterpreterData() const
	{
		return command_interpreter_;
	}

	bool CommandInterpreter::ParseText(string& text)
	{
		return ParseText(nullptr, text);
	}

	FUNCTION_AT_ADDRESS(bool CommandInterpreter::ParseText(chat_window_node*, string&), CommandInterpreter_c__ParseTextCommand);

}

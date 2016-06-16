#include "isxao_main.h"

namespace isxao_classes
{

	COMMANDINTERPRETER CommandInterpreter::GetCommandInterpreterData() const
	{
		return command_interpreter_;
	}

	bool CommandInterpreter::ParseText(string& text)
	{
		return ParseText(nullptr, text);
	}

	FUNCTION_AT_ADDRESS(bool CommandInterpreter::ParseText(ChatWindowNode*, string&), CommandInterpreter_c__ParseTextCommand);

}

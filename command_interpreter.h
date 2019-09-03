#pragma once

class CommandInterpreter
{
public:
	AOLIB_OBJECT command_interpreter_t GetCommandInterpreterData() const;
	AOLIB_OBJECT bool ParseText(string&);
private:
	bool ParseText(ChatWindowNode*, string&);
	command_interpreter_t command_interpreter_;
};
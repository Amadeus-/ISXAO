#pragma once

class CommandInterpreter
{
public:
	AOLIB_OBJECT COMMANDINTERPRETER GetCommandInterpreterData() const;
	AOLIB_OBJECT bool ParseText(string&);
private:
	bool ParseText(ChatWindowNode*, string&);
	COMMANDINTERPRETER command_interpreter_;
};
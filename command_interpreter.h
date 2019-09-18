#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class command_interpreter
{
public:
	ao::command_interpreter_t get_command_interpreter_data() const;
	bool ParseText(string&);
private:
	bool ParseText(ao::chat_window_node*, string&);
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::command_interpreter_t command_interpreter_;
};

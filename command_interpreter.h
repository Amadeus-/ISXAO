#pragma once
#include "game_object.h"

namespace std
{
	//class string;
}

namespace ao
{
	class chat_window_node;
	struct ao_command_interpreter;
	typedef ao_command_interpreter command_interpreter_t, *p_command_interpreter_t;

	class command_interpreter : public game_object<command_interpreter_t>
	{
	public:
		bool parse_text(std::string&);
	private:
		bool parse_text(chat_window_node*, std::string&);
	};

}
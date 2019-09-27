#pragma once
#include "game_object.h"

struct ao_chat_window_node;
typedef ao_chat_window_node chat_window_node_t, *p_chat_window_node_t;

namespace ao
{
	class chat_window_node : game_object<chat_window_node_t>
	{
	public:
		bool parse_text_command(std::string&);
	};
}
#pragma once
#include "game_object.h"

namespace std
{
	template <typename _Key, typename _Tp, typename _Compare, typename _Alloc>
	class map;
}

namespace ao
{
	struct ao_chat_window_controller;
	typedef ao_chat_window_controller chat_window_controller_t, *p_chat_window_controller;

	class chat_window_controller : public game_object<chat_window_controller_t>
	{
	public:
		unsigned long get_chat_window_nodes(std::map<std::string, chat_window_node*>&);
	};
}
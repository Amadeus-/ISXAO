#include "isxao_main.h"

namespace ao
{
	
	chat_window_controller_t chat_window_controller::get_chat_window_controller_data() const
	{
		return chat_window_controller_;
	}

	DWORD chat_window_controller::get_chat_window_nodes(std::map<string, chat_window_node*>& m)
	{
		std::map<string, chat_window_node*> map;
		if (chat_window_controller_.chat_window_node_dir.copy_map(map))
		{
			for (auto it = map.begin(); it != map.end(); ++it)  // NOLINT(modernize-loop-convert)
				m.insert_or_assign(it->first, reinterpret_cast<chat_window_node*>(it->second));
		}		
		return m.size();
	}

}
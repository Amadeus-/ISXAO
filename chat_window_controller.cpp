#include "isxao_main.h"
#include "chat_window_controller.h"

namespace ao
{

	DWORD chat_window_controller::get_chat_window_nodes(std::map<std::string, chat_window_node*>& m)
	{
		std::map<std::string, chat_window_node*> map;
		if (this->get_data()->chat_window_node_dir.copy_map(map))
		{
			for (auto it = map.begin(); it != map.end(); ++it)  // NOLINT(modernize-loop-convert)
				m.insert_or_assign(it->first, reinterpret_cast<chat_window_node*>(it->second));
		}		
		return m.size();
	}

}
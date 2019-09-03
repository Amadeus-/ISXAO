#include "isxao_main.h"

namespace isxao_classes
{
	
	chat_window_controller_t ChatWindowController::GetChatWindowControllerData() const
	{
		return chat_window_controller_;
	}

	std::map<string, ChatWindowNode*> ChatWindowController::GetChatWindowNodes() const
	{
		std::map<string, ChatWindowNode*> chat_window_node_map;
		auto chat_window_node_dir = GetChatWindowControllerData().chat_window_node_dir;
		GetChatWindowNodeMap(chat_window_node_map, chat_window_node_dir);
		return chat_window_node_map;
	}

}
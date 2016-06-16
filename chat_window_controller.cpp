#include "isxao_main.h"

namespace isxao_classes
{
	
	CHATWINDOWCONTROLLER ChatWindowController::GetChatWindowControllerData() const
	{
		return chat_window_controller_;
	}

	std::map<string, ChatWindowNode*> ChatWindowController::GetChatWindowNodes() const
	{
		std::map<string, ChatWindowNode*> chat_window_node_map;
		auto chat_window_node_dir = GetChatWindowControllerData().ChatWindowNodeDir;
		GetChatWindowNodeMap(chat_window_node_map, chat_window_node_dir);
		return chat_window_node_map;
	}

}
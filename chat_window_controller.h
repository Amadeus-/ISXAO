#pragma once

class ChatWindowController
{
public:
	AOLIB_OBJECT chat_window_controller_t GetChatWindowControllerData() const;
	AOLIB_OBJECT std::map<string, ChatWindowNode*> GetChatWindowNodes() const;
private:
	chat_window_controller_t chat_window_controller_;
};
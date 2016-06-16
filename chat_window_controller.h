#pragma once

class ChatWindowController
{
public:
	AOLIB_OBJECT CHATWINDOWCONTROLLER GetChatWindowControllerData() const;
	AOLIB_OBJECT std::map<string, ChatWindowNode*> GetChatWindowNodes() const;
private:
	CHATWINDOWCONTROLLER chat_window_controller_;
};
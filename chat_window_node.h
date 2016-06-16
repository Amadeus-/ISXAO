#pragma once

class ChatWindowNode
{
public:
	AOLIB_OBJECT CHATWINDOWNODE GetData() const;
	AOLIB_OBJECT bool ParseTextCommand(string&);
private:
	CHATWINDOWNODE chat_window_node_;
};
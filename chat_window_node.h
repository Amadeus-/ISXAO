#pragma once

class ChatWindowNode
{
public:
	AOLIB_OBJECT chat_window_node_t GetData() const;
	AOLIB_OBJECT bool ParseTextCommand(string&);
private:
	chat_window_node_t chat_window_node_;
};
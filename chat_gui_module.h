#pragma once

class ChatGUIModule
{
public:
	static void HandleSystemMessage(PPPJCLIENTSYSTEMMESSAGE);
private:
	chat_gui_module_t chat_gui_module_;
};
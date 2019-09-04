#pragma once

class ChatGUIModule
{
public:
	static void HandleSystemMessage(p_ppj_client_system_message_t);
private:
	chat_gui_module_t chat_gui_module_;
};
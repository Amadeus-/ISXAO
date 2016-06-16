#pragma once

class ChatGUIModule
{
public:
	static void HandleSystemMessage(PPPJCLIENTSYSTEMMESSAGE);
private:
	CHATGUIMODULE chat_gui_module_;
};
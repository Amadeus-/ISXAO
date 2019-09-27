#pragma once
#include "door.h"

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class chat_gui_module
{
public:
	static void handle_system_message(ao::p_ppj_client_system_message_t);
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::chat_gui_module_t chat_gui_module_;
};
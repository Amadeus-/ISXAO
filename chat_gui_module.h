#pragma once
#include "game_object.h"

namespace ao
{
	struct ao_chat_gui_module;
	struct ppj_client_system_message;

	typedef ao_chat_gui_module chat_gui_module_t, *p_chat_gui_module_t;
	typedef ppj_client_system_message ppj_client_system_message_t, *p_ppj_client_system_message_t;

	// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
	class chat_gui_module : public game_object<chat_gui_module_t>
	{
	public:
		static void handle_system_message(p_ppj_client_system_message_t);
	};
}
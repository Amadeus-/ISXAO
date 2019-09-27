#include "isxao_main.h"
#include "chat_gui_module.h"

namespace ao {

#if true
	FUNCTION_AT_ADDRESS(void chat_gui_module::handle_system_message(p_ppj_client_system_message_t), chat_gui_module_c__handle_system_message)
#else
	static_assert(false, "chat_gui_module::handle_system_message(p_ppj_client_system_message_t) requires a native function.");
#endif

}
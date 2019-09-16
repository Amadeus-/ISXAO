#include "isxao_main.h"

namespace isxao_classes
{

#ifdef TEXT_MESSAGE_T__MESSAGE_BODY_GET_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(PCSTR text_message::message_body_get(), text_message_t__message_body_get)
#else
	static_assert(false, "text_message::message_body_get() requires a native function.");
#endif

#ifdef TEXT_MESSAGE_T__MESSAGE_BODY_LEN_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(DWORD text_message::message_body_len(), text_message_t__message_body_len)
#else
	static_assert(false, "text_message::message_body_len() requires a native function.");
#endif

}
#include "isxao_main.h"

namespace ao
{

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(char* n3_message::duplicate_body(), n3_message_t__duplicate_body)
#else
	static_assert(false, "n3_message::duplicate_body() requires a native function.");
#endif

	p_n3_message_t n3_message::get_n3_message_data()
	{
		return p_n3_message_t(get_data());
	}

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(PCHAR n3_message::message_body_get(), n3_message_t__message_body_get)
#else
	static_assert(false, "n3_message::message_body_get() requires a native function.");
#endif

DWORD n3_message::message_body_len()
{
	return this->get_n3_message_data()->message_body_len;
}

}


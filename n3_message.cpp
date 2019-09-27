#include "isxao_main.h"
#include "n3_message.h"

namespace ao
{
#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(char* n3_message::duplicate_body(), n3_message_t__duplicate_body)
#else
	static_assert(false, "n3_message::duplicate_body() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(const char* n3_message::message_body_get(), n3_message_t__message_body_get)
#else
	static_assert(false, "n3_message::message_body_get() requires a native function.");
#endif

DWORD n3_message::message_body_len()
{
	return this->get_data()->message_body_len;
}

#if true
// ReSharper disable once CppMemberFunctionMayBeStatic
// ReSharper disable once CppMemberFunctionMayBeConst
FUNCTION_AT_ADDRESS(unsigned long n3_message::data_block_size_get(), message_t__data_block_size_get)
#else
static_assert(false, "message::data_block_size_get() requires a native function.");
#endif

#if true
// ReSharper disable once CppMemberFunctionMayBeStatic
// ReSharper disable once CppMemberFunctionMayBeConst
FUNCTION_AT_ADDRESS(unsigned long n3_message::dest_id_get(), message_t__dest_id_get)
#else
// ReSharper disable once CppMemberFunctionMayBeConst
unsigned long n3_message::dest_id_get()
{
	return get_data()->dest_id;
}
#endif

#if true
FUNCTION_AT_ADDRESS(unsigned long n3_message::header_size(const unsigned long), message_t__header_size)
#else
unsigned long n3_message::header_size(const unsigned long type)
{
	const unsigned long result = 0;
	if (type != 1 && type != 5)
	{
		if (type == 10)
			return 16;
		if (type == 11)
			return 40;
		if (type != 14)
			return result;
	}
	return 20;
}
#endif

#if true
// ReSharper disable once CppMemberFunctionMayBeStatic
// ReSharper disable once CppMemberFunctionMayBeConst
FUNCTION_AT_ADDRESS(unsigned long n3_message::message_size_get(), message_t__message_size_get)
#else
static_assert(false, "message::message_size_get() requires a native function.");
#endif

#if true
// ReSharper disable once CppMemberFunctionMayBeStatic
// ReSharper disable once CppMemberFunctionMayBeConst
FUNCTION_AT_ADDRESS(unsigned long n3_message::message_type_get(), message_t__message_type_get)
#else
// ReSharper disable once CppMemberFunctionMayBeConst
unsigned long n3_message::message_type_get()
{
	return get_data()->message_type;
}
#endif

#if true
// ReSharper disable once CppMemberFunctionMayBeStatic
// ReSharper disable once CppMemberFunctionMayBeConst
FUNCTION_AT_ADDRESS(unsigned long n3_message::priority_get(), message_t__priority_get)
#else
unsigned long n3_message::priority_get()
{
	return get_data()->priority;
}
#endif

#if true
// ReSharper disable once CppMemberFunctionMayBeStatic
// ReSharper disable once CppMemberFunctionMayBeConst
FUNCTION_AT_ADDRESS(unsigned long n3_message::source_id_get(), message_t__source_id_get)
#else
// ReSharper disable once CppMemberFunctionMayBeConst
unsigned long message::source_id_get()
{
	return get_data()->source_id;
}
#endif
}


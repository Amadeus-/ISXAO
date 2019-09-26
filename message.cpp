#include "isxao_main.h"

namespace ao
{
	
#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD message::data_block_size_get(), message_t__data_block_size_get)
#else
	static_assert(false, "message::data_block_size_get() requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD message::dest_id_get(), message_t__dest_id_get)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	DWORD message::dest_id_get()
	{
		return message_.dest_id;
	}
#endif

#if true
	FUNCTION_AT_ADDRESS(DWORD message::header_size(const DWORD), message_t__header_size)
#else
	DWORD message::header_size(const DWORD type)
	{
		const DWORD result = 0;
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
	FUNCTION_AT_ADDRESS(DWORD message::message_size_get(), message_t__message_size_get)
#else
	static_assert(false, "message::message_size_get() requires a native function.");
#endif
	
	PVOID message::get_data()
	{
		return &message_;
	}

	message_t message::get_message_data() const
	{
		return message_;
	}

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD message::message_type_get(), message_t__message_type_get)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	DWORD message::message_type_get()
	{
		return message_.message_type;
	}
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD message::priority_get(), message_t__priority_get)
#else
	DWORD message::priority_get()
	{
		return message_.priority;
	}
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(DWORD message::source_id_get(), message_t__source_id_get)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	DWORD message::source_id_get()
	{
		return message_.source_id;
	}
#endif	

}


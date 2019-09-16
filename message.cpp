#include "isxao_main.h"

namespace isxao_classes
{
	
#ifdef MESSAGE_T__DATA_BLOCK_SIZE_GET_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(DWORD message::data_block_size_get(), message_t__data_block_size_get)
#else
	static_assert(false, "message::data_block_size_get() requires a native function.");
#endif

#ifdef MESSAGE_T__DEST_ID_GET_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(DWORD message::dest_id_get(), message_t__dest_id_get)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	DWORD message::dest_id_get()
	{
		return message_.dest_id;
	}
#endif

#ifdef MESSAGE_T__HEADER_SIZE_USE_NATIVE
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

#ifdef MESSAGE_T__MESSAGE_SIZE_GET_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
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

#ifdef MESSAGE_T__MESSAGE_TYPE_GET_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(DWORD message::message_type_get(), message_t__message_type_get)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	DWORD message::message_type_get()
	{
		return message_.message_type;
	}
#endif

#ifdef MESSAGE_T__PRIORITY_GET_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(DWORD message::priority_get(), message_t__priority_get)
#else
	DWORD message::priority_get()
	{
		return message_.priority;
	}
#endif

#ifdef MESSAGE_T__SOURCE_ID_GET_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(DWORD message::source_id_get(), message_t__source_id_get)
#else
	// ReSharper disable once CppMemberFunctionMayBeConst
	DWORD message::source_id_get()
	{
		return message_.source_id;
	}
#endif	

}


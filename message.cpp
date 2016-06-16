#include "isxao_main.h"

namespace isxao_classes
{
	
#ifdef Message_t__DataBlockSizeGet_x
	FUNCTION_AT_ADDRESS(DWORD Message::DataBlockSizeGet(), Message_t__DataBlockSizeGet);
#endif

	DWORD Message::DestIdGet() const
	{
		return message_.DestId;
	}

	PVOID Message::GetData()
	{
		return &message_;
	}

	MESSAGE Message::GetMessageData() const
	{
		return message_;
	}

	DWORD Message::HeaderSize(DWORD type)
	{
		DWORD result = 0;
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

#ifdef Message_t__MessageSizeGet_x
	FUNCTION_AT_ADDRESS(DWORD Message::MessageSizeGet(), Message_t__MessageSizeGet);
#endif

	DWORD Message::MessageTypeGet() const
	{
		return message_.MessageType;
	}

	DWORD Message::PriorityGet() const
	{
		return message_.Priority;
	}

	DWORD Message::SourceIdGet() const
	{
		return message_.SourceId;
	}

}


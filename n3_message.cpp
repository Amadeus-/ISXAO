#include "isxao_main.h"

namespace isxao_classes
{

#ifdef N3Message_t__DuplicateBody_x
	FUNCTION_AT_ADDRESS(char* N3Message::DuplicateBody(void), N3Message_t__DuplicateBody);
#endif

	p_n3_message_t N3Message::GetN3MessageData()
	{
		return p_n3_message_t(GetData());
	}

#ifdef N3Message_t__MessageBodyGet_x
	FUNCTION_AT_ADDRESS(PCHAR N3Message::MessageBodyGet(void), N3Message_t__MessageBodyGet);
#endif

#ifdef N3Message_t__MessageBodyLen_x
	FUNCTION_AT_ADDRESS(DWORD N3Message::MessageBodyLen(void), N3Message_t__MessageBodyLen);
#endif

}


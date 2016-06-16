#pragma once

class TextMessage : public Message
{
public:
	PCHAR MessageBodyGet();
	DWORD MessageBodyLen();
};
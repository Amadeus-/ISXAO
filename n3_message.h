#pragma once

class N3Message : public Message
{
public:
	AOLIB_OBJECT char* DuplicateBody();
	AOLIB_OBJECT p_n3_message_t GetN3MessageData();
	AOLIB_OBJECT PCHAR MessageBodyGet();
	AOLIB_OBJECT DWORD MessageBodyLen();
private:
	n3_message_t n3message_;
};
#pragma once

class N3Message : public Message
{
public:
	AOLIB_OBJECT char* DuplicateBody();
	AOLIB_OBJECT PN3MESSAGE GetN3MessageData();
	AOLIB_OBJECT PCHAR MessageBodyGet();
	AOLIB_OBJECT DWORD MessageBodyLen();
private:
	N3MESSAGE n3message_;
};
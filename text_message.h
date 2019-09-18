#pragma once

class text_message : public ao::message
{
public:
	PCSTR message_body_get();
	DWORD message_body_len();
};
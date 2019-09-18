#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class n3_message : public ao::message
{
public:
	char* duplicate_body();
	ao::p_n3_message_t get_n3_message_data();
	PCHAR message_body_get();
	DWORD message_body_len();
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::n3_message_t n3_message_;
};

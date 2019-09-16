#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class n3_message : public message
{
public:
	AOLIB_OBJECT char* duplicate_body();
	AOLIB_OBJECT p_n3_message_t get_n3_message_data();
	AOLIB_OBJECT PCHAR message_body_get();
	AOLIB_OBJECT DWORD message_body_len();
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	n3_message_t n3_message_;
};

#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class message
{
public:
	AOLIB_OBJECT DWORD data_block_size_get();
	AOLIB_OBJECT DWORD dest_id_get();
	AOLIB_OBJECT PVOID get_data();
	AOLIB_OBJECT message_t get_message_data() const;
	AOLIB_OBJECT static DWORD header_size(DWORD);
	AOLIB_OBJECT DWORD message_size_get();
	AOLIB_OBJECT DWORD message_type_get();
	AOLIB_OBJECT DWORD priority_get();
	AOLIB_OBJECT DWORD source_id_get();
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	message_t message_;
};

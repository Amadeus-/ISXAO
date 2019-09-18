#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class message
{
public:
	DWORD data_block_size_get();
	DWORD dest_id_get();
	PVOID get_data();
	ao::message_t get_message_data() const;
	static DWORD header_size(DWORD);
	DWORD message_size_get();
	DWORD message_type_get();
	DWORD priority_get();
	DWORD source_id_get();
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::message_t message_;
};

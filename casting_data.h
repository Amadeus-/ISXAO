#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class casting_data
{
public:
	AOLIB_OBJECT identity_t get_caster() const;
	AOLIB_OBJECT casting_data_t get_casting_data() const;
	AOLIB_OBJECT DWORD get_nano_id() const;
	AOLIB_OBJECT NanoItem* get_nano_item() const;
	AOLIB_OBJECT identity_t get_target() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	casting_data_t casting_data_;
};

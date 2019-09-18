#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class casting_data
{
public:
	ao::identity_t get_caster() const;
	ao::casting_data_t get_casting_data() const;
	DWORD get_nano_id() const;
	ao::nano_item* get_nano_item() const;
	ao::identity_t get_target() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::casting_data_t casting_data_;
};

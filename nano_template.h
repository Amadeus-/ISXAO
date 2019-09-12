#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class nano_template
{
public:
	AOLIB_OBJECT DWORD get_duration() const;
	AOLIB_OBJECT identity_t get_caster_identity() const;
	AOLIB_OBJECT identity_t get_nano_identity() const;
	AOLIB_OBJECT nano_template_t get_nano_template_data() const;
	AOLIB_OBJECT DWORD get_start_time() const;
	AOLIB_OBJECT float get_time_remaining() const;
	AOLIB_OBJECT static bool nano_template_compare(nano_template &, nano_template &);
	AOLIB_OBJECT bool remove() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	nano_template_t nano_template_;
};

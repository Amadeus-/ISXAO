#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class nano_template
{
public:
	DWORD get_duration() const;
	ao::identity_t get_caster_identity() const;
	ao::identity_t get_nano_identity() const;
	ao::nano_template_t get_nano_template_data() const;
	DWORD get_start_time() const;
	float get_time_remaining() const;
	static bool nano_template_compare(nano_template &, nano_template &);
	bool remove() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::nano_template_t nano_template_;
};

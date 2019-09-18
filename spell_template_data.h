#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class spell_template_data
{
public:
	DWORD build_ls_nano_spell_list(LSIndex*) const;
	DWORD get_active_nano_effects(std::vector<ao::identity_t>&) const;
	ao::casting_data* get_casting_data() const;
	DWORD get_nano_being_cast() const;
	DWORD get_nano_spell_list(std::vector<DWORD>&) const;
	DWORD get_nano_template_list(std::vector<ao::nano_template>&) const;
	ao::spell_template_data_t get_spell_template_data_data() const;
	bool is_casting() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::spell_template_data_t spell_template_data_;
};

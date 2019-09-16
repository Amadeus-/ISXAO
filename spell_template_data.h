#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class spell_template_data
{
public:
	AOLIB_OBJECT DWORD build_ls_nano_spell_list(LSIndex*) const;
	AOLIB_OBJECT DWORD get_active_nano_effects(std::vector<identity_t>&) const;
	AOLIB_OBJECT casting_data* get_casting_data() const;
	AOLIB_OBJECT DWORD get_nano_being_cast() const;
	AOLIB_OBJECT DWORD get_nano_spell_list(std::vector<DWORD>&) const;
	AOLIB_OBJECT DWORD get_nano_template_list(std::vector<nano_template>&) const;
	AOLIB_OBJECT spell_template_data_t get_spell_template_data_data() const;
	AOLIB_OBJECT bool is_casting() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	spell_template_data_t spell_template_data_;
};

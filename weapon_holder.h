#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class weapon_holder
{
public:
	ao::weapon_holder_t get_weapon_holder_data() const;
	DWORD get_weapon_items(std::map<DWORD, ao::p_dummy_item_base_t>&);
	ao::identity_t get_weapon_target() const;
	bool is_attacking() const;
	PVOID get_data();
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::weapon_holder_t weapon_holder_;
};

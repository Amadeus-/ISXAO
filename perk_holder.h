#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class perk_holder
{
public:
	AOLIB_OBJECT perk_holder_t get_perk_holder_data() const;
	AOLIB_OBJECT DWORD get_perk_locks(vector<action_lock*>&) const;
	AOLIB_OBJECT DWORD get_perk_map(map<identity_t, DWORD> &m) const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	perk_holder_t perk_holder_;
};

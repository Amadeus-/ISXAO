#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class perk_holder
{
public:
	ao::perk_holder_t get_perk_holder_data() const;
	DWORD get_perk_locks(std::vector<ao::action_lock*>&) const;
	DWORD get_perk_map(std::map<ao::identity_t, DWORD> &m) const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::perk_holder_t perk_holder_;
};

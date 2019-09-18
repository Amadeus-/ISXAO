#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class npc_holder
{
public:
	ao::npc_holder_t get_npc_holder_data() const;
	DWORD get_pet_map(std::map<DWORD, ao::identity_t> &m) const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::npc_holder_t npc_holder_;
};

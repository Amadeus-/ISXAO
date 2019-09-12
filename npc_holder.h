#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class npc_holder
{
public:
	AOLIB_OBJECT npc_holder_t get_npc_holder_data() const;
	AOLIB_OBJECT DWORD get_pet_map(map<DWORD, identity_t> &m) const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	npc_holder_t npc_holder_;
};

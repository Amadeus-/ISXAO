#pragma once

class targeting_module
{
public:
	static void __cdecl remove_target(const ao::identity_t &);
	void select_self();
	static void __cdecl set_target(const ao::identity_t&, bool);
	//static void __cdecl SetTargetPet(DWORD);
};
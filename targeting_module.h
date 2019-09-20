#pragma once

class targeting_module
{
public:
	static void remove_target(const ao::identity_t &);
	void select_self();
	static void set_target(const ao::identity_t&, bool);
	void set_target_pet(DWORD);
};
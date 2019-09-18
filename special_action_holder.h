#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class special_action_holder
{
public:
	DWORD build_ls_special_actions(LSIndex*) const;
	DWORD get_lock_id_map(std::map<DWORD, DWORD> &m) const;
	ao::special_action_holder_t get_special_action_holder_data() const;
	DWORD get_special_actions(std::vector<ao::special_action_template>&) const;
	DWORD get_special_actions(std::vector<ao::special_action_template*>&) const;
	ao::special_action_template* get_special_action(PCSTR) const;
	ao::special_action_template* get_special_action(DWORD) const;
	ao::special_action_template* get_special_action(const ao::identity_t&) const;
	DWORD get_special_action_count() const;
	ao::identity_t get_special_action_target() const;
	ao::action_lock* get_action_lock(ao::special_action_template*) const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::special_action_holder_t special_action_holder_;
};

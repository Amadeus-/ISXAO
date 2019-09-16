#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class special_action_holder
{
public:
	AOLIB_OBJECT DWORD build_ls_special_actions(LSIndex*) const;
	AOLIB_OBJECT DWORD get_lock_id_map(std::map<DWORD, DWORD> &m) const;
	AOLIB_OBJECT special_action_holder_t get_special_action_holder_data() const;
	AOLIB_OBJECT DWORD get_special_actions(std::vector<special_action_template>&) const;
	AOLIB_OBJECT DWORD get_special_actions(std::vector<special_action_template*>&) const;
	AOLIB_OBJECT special_action_template* get_special_action(PCSTR) const;
	AOLIB_OBJECT special_action_template* get_special_action(DWORD) const;
	AOLIB_OBJECT special_action_template* get_special_action(const identity_t&) const;
	AOLIB_OBJECT DWORD get_special_action_count() const;
	AOLIB_OBJECT identity_t get_special_action_target() const;
	AOLIB_OBJECT action_lock* get_action_lock(special_action_template*) const;	
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	special_action_holder_t special_action_holder_;
};

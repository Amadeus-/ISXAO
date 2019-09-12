#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class special_action_template
{
public:
	AOLIB_OBJECT identity_t get_identity() const;
	AOLIB_OBJECT DWORD get_locked_skill_id_1() const;
	AOLIB_OBJECT DWORD get_locked_skill_id_2() const;
	AOLIB_OBJECT DWORD get_lockout_time_remaining() const;
	AOLIB_OBJECT PCSTR get_name() const;
	AOLIB_OBJECT special_action_t get_special_action_data() const;
	AOLIB_OBJECT identity_t get_weapon_identity() const;
	AOLIB_OBJECT bool is_locked() const;
	AOLIB_OBJECT SpecialActionItem* get_special_action_item() const;
	AOLIB_OBJECT double get_special_action_progress(DWORD&, DWORD&) const;
	AOLIB_OBJECT static bool special_action_compare(special_action_template &, special_action_template &);
	AOLIB_OBJECT static bool p_special_action_compare(special_action_template*, special_action_template*);
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	special_action_t special_action_;
};

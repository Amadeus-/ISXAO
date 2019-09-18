#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class special_action_template
{
public:
	ao::identity_t get_identity() const;
	DWORD get_locked_skill_id_1() const;
	DWORD get_locked_skill_id_2() const;
	DWORD get_lockout_time_remaining() const;
	PCSTR get_name() const;
	ao::special_action_t get_special_action_data() const;
	ao::identity_t get_weapon_identity() const;
	bool is_locked() const;
	ao::special_action_item* get_special_action_item() const;
	double get_special_action_progress(DWORD&, DWORD&) const;
	static bool special_action_compare(special_action_template &, special_action_template &);
	static bool p_special_action_compare(special_action_template*, special_action_template*);
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::special_action_t special_action_;
};

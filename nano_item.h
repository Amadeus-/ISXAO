#pragma once

class nano_item : public ao::dummy_item_base
{
public:
	bool can_apply_on_friendly();
	bool can_apply_on_hostile();
	bool can_apply_on_self();
	bool can_apply_on_fighting_target();
	void cast();
	float get_attack_delay();
	DWORD get_attack_range();
	float get_cooldown_remaining();
	double get_formula_progress(DWORD&, DWORD&);
	DWORD get_formula_radius();
	ao::identity_t get_nano_identity();
	ao::p_nano_item_t get_nano_item_data();
	DWORD get_ncu_cost();
	DWORD get_nano_points();
	DWORD get_nano_school();
	DWORD get_nano_strain();
	float get_recharge_delay();
	LONG get_skill(DWORD);
	DWORD get_stacking_order();
	bool is_buff();
	bool is_hostile();
	bool is_nano_self_only();
	bool is_no_resist_cannot_fumble();
	bool is_ready();
	bool is_shape_change_nano();
	bool is_team_nano();
	bool will_break_on_attack();
	bool will_break_on_debuff();
	bool will_break_on_spell_attack();
private:
	DWORD get_nano_none_flags();
	DWORD get_nano_can_flags();
};
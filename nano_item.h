#pragma once
#include "dummy_item_base.h"

namespace ao
{
	struct ao_nano_item;
	typedef ao_nano_item nano_item_t, *p_nano_item_t;

	class nano_item : public dummy_item_base
	{
	public:
		bool can_apply_on_friendly();
		bool can_apply_on_hostile();
		bool can_apply_on_self();
		bool can_apply_on_fighting_target();
		void cast();
		float get_attack_delay();
		unsigned long get_attack_range();
		float get_cooldown_remaining();
		double get_formula_progress(unsigned long&, unsigned long&);
		unsigned long get_formula_radius();
		ao::identity_t get_nano_identity();
		ao::p_nano_item_t get_nano_item_data();
		unsigned long get_ncu_cost();
		unsigned long get_nano_points();
		unsigned long get_nano_school();
		unsigned long get_nano_strain();
		float get_recharge_delay();
		long get_skill(unsigned long);
		unsigned long get_stacking_order();
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
		unsigned long get_nano_none_flags();
		unsigned long get_nano_can_flags();
	};
}
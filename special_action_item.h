#pragma once
#include "dummy_item_base.h"
namespace ao
{
	class special_action_item : public dummy_item_base
	{
	public:
		bool can_apply_on_friendly();
		bool can_apply_on_hostile();
		bool can_apply_on_self();
		bool can_apply_on_fighting_target();
		bool can_use();
		float get_attack_delay();
		unsigned long get_range();
		long get_skill(unsigned long);
		bool is_buff();
		bool is_general_action();
		bool is_hostile();
		bool is_no_remove_no_ncu_is_friendly();
		bool is_no_resist();
		bool is_no_resist_no_fumble();
		bool is_not_removable();
		bool is_perk();
		bool is_special_action();
		bool will_break_on_attack();
		bool will_break_on_debuff();
		bool will_break_on_spell_attack();

	};
}
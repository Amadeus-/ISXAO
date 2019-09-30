#pragma once
#include "game_object.h"

namespace ao
{
	class special_action_item;

	struct ao_identity;
	struct ao_special_action;

	typedef ao_identity identity_t, *p_identity_t;
	typedef ao_special_action special_action_t, *p_special_action_t;

	class special_action_template : game_object<special_action_t>
	{
	public:
		ao::identity_t get_identity();
		unsigned long get_locked_skill_id_1();
		unsigned long get_locked_skill_id_2();
		unsigned long get_lockout_time_remaining();
		const char* get_name();
		ao::identity_t get_weapon_identity();
		bool is_locked();
		ao::special_action_item* get_special_action_item();
		double get_special_action_progress(unsigned long&, unsigned long&);
		static bool special_action_compare(special_action_template &, special_action_template &);
		static bool p_special_action_compare(special_action_template*, special_action_template*);
	};
}
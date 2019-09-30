#pragma once
#include "game_object.h"

namespace ao
{
	struct ao_identity;
	struct ao_targeting_module;

	typedef ao_identity identity_t, *p_identity_t;
	typedef ao_targeting_module targeting_module_t, *p_targeting_module_t;

	class targeting_module : public game_object<targeting_module_t>
	{
	public:
		static void remove_target(const identity_t &);
		void select_self();
		static void set_target(const identity_t&, bool);
		void set_target_pet(unsigned long);
	};
}

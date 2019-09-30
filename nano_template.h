#pragma once
#include "game_object.h"

namespace ao
{
	struct ao_identity;
	struct ao_nano_template;

	typedef ao_identity identity_t, *p_identity_t;
	typedef ao_nano_template nano_template_t, *p_nano_template_t;

	class nano_template : public game_object<nano_template_t>
	{
	public:
		unsigned long get_duration();
		identity_t get_caster_identity();
		identity_t get_nano_identity();
		unsigned long get_start_time();
		float get_time_remaining();
		static bool nano_template_compare(nano_template &, nano_template &);
		bool remove();
	};
}

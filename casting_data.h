#pragma once
#include "game_object.h"

namespace ao
{
	class nano_item;

	struct ao_casting_data;
	struct ao_identity;

	typedef ao_casting_data casting_data_t, *p_casting_data_t;
	typedef ao_identity identity_t, *p_identity_t;

	class casting_data : public game_object<casting_data_t>
	{
	public:
		identity_t get_caster();
		unsigned long get_nano_id();
		ao::nano_item* get_nano_item();
		ao::identity_t get_target();
	};
}

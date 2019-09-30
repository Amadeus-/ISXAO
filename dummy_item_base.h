#pragma once
#include "game_object.h"

namespace ao
{
	struct ao_dummy_item_base;
	struct ao_identity;

	typedef ao_dummy_item_base dummy_item_base_t, *p_dummy_item_base_t;
	typedef ao_identity identity_t, *p_identity_t;

	class dummy_item_base : public game_object<dummy_item_base_t>
	{
	public:
		const char* get_description();
		identity_t get_identity();
		const char* get_name();
		identity_t get_parent_identity();
	};
}

#pragma once
#include "game_object.h"

namespace ao
{
	struct ao_identity;
	struct ao_inventory_data;
	struct ao_rdb_identity;

	typedef ao_identity identity_t, *p_identity_t;
	typedef ao_inventory_data inventory_data_t, *p_inventory_data_t;
	typedef ao_rdb_identity rdb_identity_t, *p_rdb_identity_t;

	class inventory_data : public game_object<inventory_data_t>
	{
	public:
		identity_t get_dynel_id();
		unsigned long get_item_count();
		ao::rdb_identity_t get_rdb_identity();
		unsigned long get_quality_level();
	};
}

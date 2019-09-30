#pragma once
#include "game_object.h"

namespace std
{
	template <typename _Tp, typename _Alloc>
	class list;
	template <typename _Key, typename _Tp, typename _Compare, typename _Alloc>
	class map;
	template <typename _Tp, typename _Alloc>
	class vector;
}

namespace ao
{
	class inventory_data;

	struct ao_identity;
	struct ao_new_inventory;

	typedef ao_identity identity_t, *p_identity_t;
	typedef ao_new_inventory new_inventory_t, *p_new_inventory_t;

	class new_inventory : public game_object<new_inventory_t>
	{
	public:
		unsigned long get_inventory(std::vector<ao::inventory_data*>&);
		identity_t get_inventory_identity();
		unsigned long get_inventory_size();
	};
}
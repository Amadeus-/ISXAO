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

	struct ao_bank_entry;
	struct ao_identity;

	typedef ao_bank_entry bank_entry_t, *p_bank_entry_t;
	typedef ao_identity identity_t, *p_identity_t;

	class bank_entry : public game_object<bank_entry_t>
	{
	public:
		unsigned long get_inventory(std::vector<ao::inventory_data*> &v);
		identity_t get_inventory_identity();
		unsigned long get_inventory_size();
	};
}
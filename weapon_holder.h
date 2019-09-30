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
	struct ao_dummy_item_base;
	struct ao_identity;
	struct ao_weapon_holder;

	typedef ao_dummy_item_base dummy_item_base_t, *p_dummy_item_base_t;
	typedef ao_identity identity_t, *p_identity_t;
	typedef ao_weapon_holder weapon_holder_t, *p_weapon_holder_t;

	class weapon_holder : public game_object<weapon_holder_t>
	{
	public:
		unsigned long get_weapon_items(std::map<unsigned long, ao::p_dummy_item_base_t>&);
		ao::identity_t get_weapon_target();
		bool is_attacking();
	};
}
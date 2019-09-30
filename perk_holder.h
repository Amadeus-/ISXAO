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
	class action_lock;

	struct ao_identity;
	struct ao_perk_holder;

	typedef ao_identity identity_t, *p_identity_t;
	typedef ao_perk_holder perk_holder_t, *p_perk_holder_t;

	class perk_holder : game_object<perk_holder_t>
	{
	public:
		unsigned long get_perk_locks(std::vector<ao::action_lock*>&);
		unsigned long get_perk_map(std::map<ao::identity_t, unsigned long> &m);
	};
}
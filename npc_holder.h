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
	struct ao_identity;
	struct ao_npc_holder;

	typedef ao_identity identity_t, *p_identity_t;
	typedef ao_npc_holder npc_holder_t, *p_npc_holder_t;

	class npc_holder : public game_object<npc_holder_t>
	{
	public:
		unsigned long get_pet_map(std::map<unsigned long, identity_t> &m);
		unsigned long get_raw_pet_map(std::map<identity_t, unsigned long>&);
	};
}
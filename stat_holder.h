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
	class special_action_template;

	struct ao_stat_holder;

	typedef ao_stat_holder stat_holder_t, *p_stat_holder_t;

	class stat_holder : public game_object<stat_holder_t>
	{
	public:
		unsigned long get_skill_locks(std::vector<action_lock*>&);
		action_lock* get_skill_lock(special_action_template*);
		unsigned long get_stat_map(std::map<unsigned long, long>&);
	};
}
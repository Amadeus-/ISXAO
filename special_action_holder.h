#pragma once
#include "game_object.h"

class LSIndex;

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

	struct ao_identity;
	struct ao_special_action_holder;

	typedef ao_identity identity_t, *p_identity_t;
	typedef ao_special_action_holder special_action_holder_t, *p_special_action_holder_t;

	class special_action_holder : public game_object<special_action_holder_t>
	{
	public:
		unsigned long build_ls_special_actions(LSIndex*);
		unsigned long get_lock_id_map(std::map<unsigned long, unsigned long> &m);
		unsigned long get_special_actions(std::vector<special_action_template>&);
		unsigned long get_special_actions(std::vector<special_action_template*>&);
		special_action_template* get_special_action(const char*);
		special_action_template* get_special_action(unsigned long);
		special_action_template* get_special_action(const identity_t&);
		unsigned long get_special_action_count();
		identity_t get_special_action_target();
		action_lock* get_action_lock(special_action_template*);
	};
}
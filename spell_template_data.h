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
	class casting_data;
	class nano_template;

	struct ao_identity;
	struct ao_spell_template_data;

	typedef ao_identity identity_t, *p_identity_t;
	typedef ao_spell_template_data spell_template_data_t, *p_spell_template_data_t;

	class spell_template_data : public game_object<spell_template_data_t>
	{
	public:
		unsigned long build_ls_nano_spell_list(LSIndex*);
		unsigned long get_active_nano_effects(std::vector<ao::identity_t>&);
		ao::casting_data* get_casting_data();
		unsigned long get_nano_being_cast();
		unsigned long get_nano_spell_list(std::vector<unsigned long>&);
		unsigned long get_nano_template_list(std::vector<ao::nano_template>&);
		bool is_casting();
	};
}
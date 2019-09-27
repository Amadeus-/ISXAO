#pragma once
#include "game_object.h"

namespace ao
{
	struct ao_identity;
	//struct ao_keypress_info;

	typedef ao_identity identity_t, *p_identity_t;
	//typedef ao_keypress_info keypress_info_t, *p_keypress_info_t;

	class input_config
	{
	public:
		void set_current_target(const ao::identity_t&);
		static const char* get_method_id_name(unsigned long);
		static const char* get_mode_id_name(unsigned long);
		char process_input(ao::keypress_info_t, unsigned long);
	};
}
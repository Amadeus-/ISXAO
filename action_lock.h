#pragma once
#include "game_object.h"
namespace ao
{
	struct ao_action_lock;
	struct ao_identity;

	typedef ao_action_lock action_lock_t, *p_action_lock_t;
	typedef ao_identity identity_t, *p_identity_t;

	class action_lock : public game_object<action_lock_t>
	{
	public:
		ao::identity_t get_action_identity();
		DWORD get_lock_out_time_remaining();
		DWORD get_total_lock_out_time();
		static bool p_action_lock_compare(action_lock*, action_lock*);
	};
}
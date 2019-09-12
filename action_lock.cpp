#include "isxao_main.h"

namespace isxao_classes
{

	identity_t action_lock::get_action_identity() const
	{
		return get_action_lock_data().action_identity;
	}

	action_lock_t action_lock::get_action_lock_data() const
	{
		return action_lock_;
	}

	DWORD action_lock::get_lock_out_time_remaining() const
	{
		return get_action_lock_data().lockout_time_remaining;
	}

	DWORD action_lock::get_total_lock_out_time() const
	{
		return get_action_lock_data().total_lockout_time;
	}

	bool action_lock::p_action_lock_compare(action_lock* a, action_lock* b)
	{
		return a->get_lock_out_time_remaining() < b->get_lock_out_time_remaining();
	}


}
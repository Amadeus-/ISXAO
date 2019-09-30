#include "isxao_main.h"
#include "action_lock.h"

namespace ao
{

	identity_t action_lock::get_action_identity()
	{
		return get_data()->action_identity;
	}

	DWORD action_lock::get_lock_out_time_remaining()
	{
		return get_data()->lockout_time_remaining;
	}

	DWORD action_lock::get_total_lock_out_time()
	{
		return get_data()->total_lockout_time;
	}

	bool action_lock::p_action_lock_compare(action_lock* a, action_lock* b)
	{
		return a->get_lock_out_time_remaining() < b->get_lock_out_time_remaining();
	}

}
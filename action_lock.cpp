#include "isxao_main.h"

namespace isxao_classes
{

	identity_t ActionLock::GetActionIdentity() const
	{
		return GetActionLockData().action_identity;
	}

	action_lock_t ActionLock::GetActionLockData() const
	{
		return action_lock_;
	}

	DWORD ActionLock::GetLockOutTimeRemaining() const
	{
		return GetActionLockData().lockout_time_remaining;
	}

	DWORD ActionLock::GetTotalLockOutTime() const
	{
		return GetActionLockData().total_lockout_time;
	}

	bool ActionLock::pActionLockCompare(ActionLock* a, ActionLock* b)
	{
		return a->GetLockOutTimeRemaining() < b->GetLockOutTimeRemaining();
	}


}
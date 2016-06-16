#include "isxao_main.h"

namespace isxao_classes
{

	IDENTITY ActionLock::GetActionIdentity() const
	{
		return GetActionLockData().ActionIdentity;
	}

	ACTIONLOCK ActionLock::GetActionLockData() const
	{
		return action_lock_;
	}

	DWORD ActionLock::GetLockOutTimeRemaining() const
	{
		return GetActionLockData().LockoutTimeRemaining;
	}

	DWORD ActionLock::GetTotalLockOutTime() const
	{
		return GetActionLockData().TotalLockoutTime;
	}

	bool ActionLock::pActionLockCompare(ActionLock* a, ActionLock* b)
	{
		return a->GetLockOutTimeRemaining() < b->GetLockOutTimeRemaining();
	}


}
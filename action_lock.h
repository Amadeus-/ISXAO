#pragma once

class ActionLock
{
public:
	AOLIB_OBJECT identity_t GetActionIdentity() const;
	AOLIB_OBJECT action_lock_t GetActionLockData() const;
	AOLIB_OBJECT DWORD GetLockOutTimeRemaining() const;
	AOLIB_OBJECT DWORD GetTotalLockOutTime() const;
	AOLIB_OBJECT static bool pActionLockCompare(ActionLock*, ActionLock*);
private:
	action_lock_t action_lock_;
};
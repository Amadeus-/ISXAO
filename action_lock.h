#pragma once

class ActionLock
{
public:
	AOLIB_OBJECT IDENTITY GetActionIdentity() const;
	AOLIB_OBJECT ACTIONLOCK GetActionLockData() const;
	AOLIB_OBJECT DWORD GetLockOutTimeRemaining() const;
	AOLIB_OBJECT DWORD GetTotalLockOutTime() const;
	AOLIB_OBJECT static bool pActionLockCompare(ActionLock*, ActionLock*);
private:
	ACTIONLOCK action_lock_;
};
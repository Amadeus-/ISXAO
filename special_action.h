#pragma once

class SpecialAction
{
public:
	AOLIB_OBJECT IDENTITY GetIdentity() const;
	AOLIB_OBJECT DWORD GetLockedSkillId1() const;
	AOLIB_OBJECT DWORD GetLockedSkillId2() const;
	//AOLIB_OBJECT DWORD GetLockoutTimeRemaining() const;
	AOLIB_OBJECT float GetLockoutTimeRemaining() const;
	AOLIB_OBJECT PCSTR GetName() const;
	AOLIB_OBJECT SPECIALACTION GetSpecialActionData() const;
	AOLIB_OBJECT IDENTITY GetWeaponIdentity() const;
	AOLIB_OBJECT bool IsLocked() const;
	AOLIB_OBJECT SpecialActionItem* GetSpecialActionItem();
	AOLIB_OBJECT static bool SpecialActionCompare(SpecialAction &, SpecialAction &);
	AOLIB_OBJECT static bool pSpecialActionCompare(SpecialAction*, SpecialAction*);
private:
	SPECIALACTION special_action_;
};
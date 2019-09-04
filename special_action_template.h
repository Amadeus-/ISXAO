#pragma once

class SpecialActionTemplate
{
public:
	AOLIB_OBJECT identity_t GetIdentity() const;
	AOLIB_OBJECT DWORD GetLockedSkillId1() const;
	AOLIB_OBJECT DWORD GetLockedSkillId2() const;
	AOLIB_OBJECT DWORD GetLockoutTimeRemaining() const;
	//AOLIB_OBJECT float GetLockoutTimeRemaining() const;
	AOLIB_OBJECT PCSTR GetName() const;
	AOLIB_OBJECT special_action_t GetSpecialActionData() const;
	AOLIB_OBJECT identity_t GetWeaponIdentity() const;
	AOLIB_OBJECT bool IsLocked() const;
	AOLIB_OBJECT SpecialActionItem* GetSpecialActionItem();
	AOLIB_OBJECT double GetSpecialActionProgress(DWORD&, DWORD&) const;
	AOLIB_OBJECT static bool SpecialActionCompare(SpecialActionTemplate &, SpecialActionTemplate &);
	AOLIB_OBJECT static bool pSpecialActionCompare(SpecialActionTemplate*, SpecialActionTemplate*);
private:
	special_action_t special_action_;
};
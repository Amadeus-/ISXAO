#pragma once

class SpecialActionItem : public DummyItemBase
{
public:
	AOLIB_OBJECT bool CanApplyOnFriendly();
	AOLIB_OBJECT bool CanApplyOnHostile();
	AOLIB_OBJECT bool CanApplyOnSelf();
	AOLIB_OBJECT bool CanApplyOnFightingTarget();
	AOLIB_OBJECT bool CanUse();
	AOLIB_OBJECT float GetAttackDelay();
	AOLIB_OBJECT DWORD GetRange();
	AOLIB_OBJECT LONG GetSkill(DWORD);
	AOLIB_OBJECT bool IsBuff();
	AOLIB_OBJECT bool IsGeneralAction();
	AOLIB_OBJECT bool IsHostile();
	AOLIB_OBJECT bool IsNoRemoveNoNCUIsFriendly();
	AOLIB_OBJECT bool IsNoResist();
	AOLIB_OBJECT bool IsNoResistNoFumble();
	AOLIB_OBJECT bool IsNotRemovable();
	AOLIB_OBJECT bool IsPerk();
	AOLIB_OBJECT bool IsSpecialAction();
	AOLIB_OBJECT bool WillBreakOnAttack();
	AOLIB_OBJECT bool WillBreakOnDebuff();
	AOLIB_OBJECT bool WillBreakOnSpellAttack();

};
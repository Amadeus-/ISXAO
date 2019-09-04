#pragma once

class NanoItem : public DummyItemBase
{
public:
	AOLIB_OBJECT bool CanApplyOnFriendly();
	AOLIB_OBJECT bool CanApplyOnHostile();
	AOLIB_OBJECT bool CanApplyOnSelf();
	AOLIB_OBJECT bool CanApplyOnFightingTarget();
	AOLIB_OBJECT void Cast();
	AOLIB_OBJECT float GetAttackDelay();
	AOLIB_OBJECT DWORD GetAttackRange();
	AOLIB_OBJECT float GetCooldownRemaining();
	AOLIB_OBJECT double GetFormulaProgress(DWORD&, DWORD&);
	AOLIB_OBJECT DWORD GetFormulaRadius();
	AOLIB_OBJECT identity_t GetNanoIdentity();
	AOLIB_OBJECT p_nano_item_t GetNanoItemData();
	AOLIB_OBJECT DWORD GetNCUCost();
	AOLIB_OBJECT DWORD GetNanoPoints();
	AOLIB_OBJECT DWORD GetNanoSchool();
	AOLIB_OBJECT DWORD GetNanoStrain();
	AOLIB_OBJECT float GetRechargeDelay();
	AOLIB_OBJECT LONG GetSkill(DWORD);
	AOLIB_OBJECT DWORD GetStackingOrder();
	AOLIB_OBJECT bool IsBuff();
	AOLIB_OBJECT bool IsHostile();
	AOLIB_OBJECT bool IsNanoSelfOnly();
	AOLIB_OBJECT bool IsNoResistCannotFumble();
	AOLIB_OBJECT bool IsReady();
	AOLIB_OBJECT bool IsShapeChangeNano();
	AOLIB_OBJECT bool IsTeamNano();
	AOLIB_OBJECT bool WillBreakOnAttack();
	AOLIB_OBJECT bool WillBreakOnDebuff();
	AOLIB_OBJECT bool WillBreakOnSpellAttack();
private:
	DWORD GetNanoNoneFlags();
	DWORD GetNanoCanFlags();
};
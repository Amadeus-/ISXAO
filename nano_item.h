#pragma once

class NanoItem : public DummyItemBase
{
public:
	AOLIB_OBJECT void Cast();
	AOLIB_OBJECT float GetAttackDelay();
	AOLIB_OBJECT DWORD GetAttackRange();
	AOLIB_OBJECT double GetFormulaProgress();
	AOLIB_OBJECT DWORD GetFormulaRadius();
	AOLIB_OBJECT IDENTITY GetNanoIdentity();
	AOLIB_OBJECT PNANOITEM GetNanoItemData();
	AOLIB_OBJECT DWORD GetNCUCost();
	AOLIB_OBJECT DWORD GetNanoPoints();
	AOLIB_OBJECT DWORD GetNanoSchool();
	AOLIB_OBJECT DWORD GetNanoStrain();
	AOLIB_OBJECT float GetRechargeDelay();
	AOLIB_OBJECT LONG GetSkill(DWORD);
	AOLIB_OBJECT DWORD GetStackingOrder();
	AOLIB_OBJECT bool IsBuff();
	AOLIB_OBJECT bool IsFormulaReady();
	AOLIB_OBJECT bool IsHostile();
	AOLIB_OBJECT bool IsNanoSelfOnly();
	AOLIB_OBJECT bool IsNoResistCannotFumble();
	AOLIB_OBJECT bool IsShapeChangeNano();
	AOLIB_OBJECT bool IsTeamNano();
	AOLIB_OBJECT bool WillBreakOnAttack();
	AOLIB_OBJECT bool WillBreakOnDebuff();
private:
	DWORD GetNanoNoneFlags();
	DWORD GetNanoCanFlags();
};
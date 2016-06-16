#include "isxao_main.h"

namespace isxao_classes
{
	
	void NanoItem::Cast()
	{
		pEngineClientAnarchy->GetClientChar()->CastNanoSpell(GetNanoIdentity(), pSelectionIndicator->Identity);
	}

	float NanoItem::GetAttackDelay()
	{
		return GetSkill(ST_ITEMDELAY) / 100.0f;
	}

	DWORD NanoItem::GetAttackRange()
	{
		return GetSkill(ST_ATTACKRANGE);
	}

	double NanoItem::GetFormulaProgress()
	{
		DWORD a;
		DWORD b;
		return pEngineClientAnarchy->N3Msg_GetFormulaProgress(GetNanoIdentity(), a, b);
	}

	DWORD NanoItem::GetFormulaRadius()
	{
		return GetNanoItemData()->Radius;
	}

	DWORD NanoItem::GetNanoCanFlags()
	{
		return GetSkill(ST_CAN);
	}

	IDENTITY NanoItem::GetNanoIdentity()
	{
		return GetNanoItemData()->NanoIdentity;
	}

	PNANOITEM NanoItem::GetNanoItemData()
	{
		return PNANOITEM(GetData());
	}

	DWORD NanoItem::GetNCUCost()
	{
		return GetSkill(ST_LEVEL);
	}

	DWORD NanoItem::GetNanoNoneFlags()
	{
		return GetSkill(ST_FLAGS);
	}

	DWORD NanoItem::GetNanoPoints()
	{
		return GetSkill(ST_NANOPOINTS);
	}

	DWORD NanoItem::GetNanoSchool()
	{
		return GetSkill(ST_SCHOOL);
	}

	DWORD NanoItem::GetNanoStrain()
	{
		return GetSkill(ST_METATYPE);
	}

	float NanoItem::GetRechargeDelay()
	{
		return GetSkill(ST_RECHARGEDELAY) / 100.0f;
	}

	LONG NanoItem::GetSkill(DWORD stat)
	{
		IDENTITY dummy_identity;
		ZeroMemory(&dummy_identity, sizeof(IDENTITY));
		return pEngineClientAnarchy->N3Msg_GetSkill(GetNanoIdentity(), stat, 2, dummy_identity);
	}

	DWORD NanoItem::GetStackingOrder()
	{
		return GetSkill(ST_STACKINGORDER);
	}

	bool NanoItem::IsFormulaReady()
	{
		return pEngineClientAnarchy->N3Msg_IsFormulaReady(GetNanoIdentity());
	}

	bool NanoItem::IsBuff()
	{
		return (GetNanoNoneFlags() & NNF_IS_BUFF) == 1;
	}

	bool NanoItem::IsHostile()
	{
		return (GetNanoNoneFlags() & NNF_IS_HOSTILE) == 1;
	}

	bool NanoItem::IsNanoSelfOnly()
	{
		return GetNanoItemData()->IsNanoSelfOnly == 1;
	}

	bool NanoItem::IsNoResistCannotFumble()
	{
		return (GetNanoNoneFlags() & NNF_NO_RESIST_CANNOT_FUMBLE) == 1;
	}

	bool NanoItem::IsShapeChangeNano()
	{
		return (GetNanoNoneFlags() & NNF_IS_SHAPE_CHANGE_NANO) == 1;
	}

	bool NanoItem::IsTeamNano()
	{
		return pEngineClientAnarchy->N3Msg_IsTeamNano(GetNanoIdentity());
	}

	bool NanoItem::WillBreakOnAttack()
	{
		return (GetNanoNoneFlags() & NNF_BREAK_ON_ATTACK) == 1 || (GetNanoNoneFlags() & NNF_BREAK_ON_SPELL_ATTACK) == 1;
	}

	bool NanoItem::WillBreakOnDebuff()
	{
		return (GetNanoNoneFlags() & NNF_BREAK_ON_DEBUFF) == 1;
	}

}



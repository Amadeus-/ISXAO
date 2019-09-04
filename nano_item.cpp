#include "isxao_main.h"

namespace isxao_classes
{
	
	bool NanoItem::CanApplyOnFightingTarget()
	{
		return (GetNanoCanFlags() & ICF_APPLY_ON_FIGHTING_TARGET) == 1;
	}

	bool NanoItem::CanApplyOnFriendly()
	{
		return (GetNanoCanFlags() & ICF_APPLY_ON_FRIENDLY) == 1;
	}

	bool NanoItem::CanApplyOnHostile()
	{
		return (GetNanoCanFlags() & ICF_APPLY_ON_HOSTILE) == 1;
	}

	bool NanoItem::CanApplyOnSelf()
	{
		return (GetNanoCanFlags() & ICF_APPLY_ON_SELF) == 1;
	}

	void NanoItem::Cast()
	{
		if(pSelectionIndicator)
			P_ENGINE_CLIENT_ANARCHY->get_client_char()->CastNanoSpell(GetNanoIdentity(), pSelectionIndicator->identity);
	}

	float NanoItem::GetAttackDelay()
	{
		return GetSkill(ST_ITEMDELAY) / 100.0f;
	}

	DWORD NanoItem::GetAttackRange()
	{
		return GetSkill(ST_ATTACKRANGE);
	}

	float NanoItem::GetCooldownRemaining()
	{
		DWORD a;
		DWORD b;
		auto c = P_ENGINE_CLIENT_ANARCHY->N3Msg_GetFormulaProgress(GetNanoIdentity(), a, b);
		return float((1.0 - c)*b);
	}

	double NanoItem::GetFormulaProgress(DWORD &a, DWORD &b)
	{
		return P_ENGINE_CLIENT_ANARCHY->N3Msg_GetFormulaProgress(GetNanoIdentity(), a, b);
	}

	DWORD NanoItem::GetFormulaRadius()
	{
		return GetNanoItemData()->radius;
	}

	DWORD NanoItem::GetNanoCanFlags()
	{
		return GetSkill(ST_CAN);
	}

	identity_t NanoItem::GetNanoIdentity()
	{
		return GetNanoItemData()->nano_identity;
	}

	p_nano_item_t NanoItem::GetNanoItemData()
	{
		return p_nano_item_t(GetData());
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
		identity_t dummy_identity;
		ZeroMemory(&dummy_identity, sizeof(identity_t));
		return P_ENGINE_CLIENT_ANARCHY->N3Msg_GetSkill(GetNanoIdentity(), stat, 2, dummy_identity);
	}

	DWORD NanoItem::GetStackingOrder()
	{
		return GetSkill(ST_STACKINGORDER);
	}

	bool NanoItem::IsReady()
	{
		return P_ENGINE_CLIENT_ANARCHY->N3Msg_IsFormulaReady(GetNanoIdentity());
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
		return GetNanoItemData()->is_nano_self_only == 1;
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
		return P_ENGINE_CLIENT_ANARCHY->N3Msg_IsTeamNano(GetNanoIdentity());
	}

	bool NanoItem::WillBreakOnAttack()
	{
		return (GetNanoNoneFlags() & NNF_BREAK_ON_ATTACK) == 1;
	}

	bool NanoItem::WillBreakOnDebuff()
	{
		return (GetNanoNoneFlags() & NNF_BREAK_ON_DEBUFF) == 1;
	}

	bool NanoItem::WillBreakOnSpellAttack()
	{
		return (GetNanoNoneFlags() * NNF_BREAK_ON_SPELL_ATTACK) == 1;
	}

}



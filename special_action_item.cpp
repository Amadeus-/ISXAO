#include "isxao_main.h"

namespace isxao_classes
{

	bool SpecialActionItem::CanApplyOnFightingTarget()
	{
		return (GetSkill(ST_CAN) & ICF_APPLY_ON_FIGHTING_TARGET) == 1;
	}

	bool SpecialActionItem::CanApplyOnFriendly()
	{
		return (GetSkill(ST_CAN) & ICF_APPLY_ON_FRIENDLY) == 1;
	}

	bool SpecialActionItem::CanApplyOnHostile()
	{
		return (GetSkill(ST_CAN) & ICF_APPLY_ON_HOSTILE) == 1;
	}

	bool SpecialActionItem::CanApplyOnSelf()
	{
		return (GetSkill(ST_CAN) & ICF_APPLY_ON_SELF) == 1;
	}

	bool SpecialActionItem::CanUse()
	{
		return (GetSkill(ST_CAN) & ICF_USE) == 1;
	}

	float SpecialActionItem::GetAttackDelay()
	{
		return float(GetSkill(ST_ITEMDELAY) / 100.0f);
	}

	DWORD SpecialActionItem::GetRange()
	{
		return GetSkill(ST_ATTACKRANGE);
	}

	LONG SpecialActionItem::GetSkill(DWORD stat)
	{
		IDENTITY dummy_identity;
		ZeroMemory(&dummy_identity, sizeof(IDENTITY));
		return pEngineClientAnarchy->N3Msg_GetSkill(GetIdentity(), stat, 2, dummy_identity);
	}

	bool SpecialActionItem::IsBuff()
	{
		return (GetSkill(ST_FLAGS) & NNF_IS_BUFF) == 1;
	}

	bool SpecialActionItem::IsGeneralAction()
	{
		return GetSkill(ST_ACTIONCATEGORY) == 2;
	}

	bool SpecialActionItem::IsHostile()
	{
		return (GetSkill(ST_FLAGS) & NNF_IS_HOSTILE) == 1;
	}

	bool SpecialActionItem::IsNoRemoveNoNCUIsFriendly()
	{
		return (GetSkill(ST_FLAGS) & NNF_NO_REMOVE_NO_NCU_IS_FRIENDLY) == 1;
	}

	bool SpecialActionItem::IsNoResist()
	{
		return (GetSkill(ST_FLAGS) & NNF_NO_RESIST) == 1;
	}

	bool SpecialActionItem::IsNoResistNoFumble()
	{
		return (GetSkill(ST_FLAGS) & NNF_NO_RESIST_CANNOT_FUMBLE) == 1;
	}

	bool SpecialActionItem::IsNotRemovable()
	{
		return (GetSkill(ST_FLAGS) & NNF_NOT_REMOVABLE) == 1;
	}

	bool SpecialActionItem::IsPerk()
	{
		return GetSkill(ST_ACTIONCATEGORY) == 1;
	}

	bool SpecialActionItem::IsSpecialAction()
	{
		return GetSkill(ST_ACTIONCATEGORY) == 3;
	}

	bool SpecialActionItem::WillBreakOnAttack()
	{
		return (GetSkill(ST_FLAGS) & NNF_BREAK_ON_ATTACK) == 1;
	}

	bool SpecialActionItem::WillBreakOnDebuff()
	{
		return (GetSkill(ST_FLAGS) & NNF_BREAK_ON_DEBUFF) == 1;
	}

	bool SpecialActionItem::WillBreakOnSpellAttack()
	{
		return (GetSkill(ST_FLAGS) & NNF_BREAK_ON_SPELL_ATTACK) == 1;
	}


}
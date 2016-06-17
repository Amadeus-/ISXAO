#include "isxao_main.h"

namespace isxao_classes
{

	IDENTITY SpecialAction::GetIdentity() const
	{
		return GetSpecialActionData().Identity;
	}

	DWORD SpecialAction::GetLockedSkillId1() const
	{
		return special_action_.LockedSkillId1;
	}

	DWORD SpecialAction::GetLockedSkillId2() const
	{
		return special_action_.LockedSkillId2;
	}

	DWORD SpecialAction::GetLockoutTimeRemaining() const
	{
		DWORD a, b;
		DWORD *pA = &a;
		DWORD *pB = &b;
		pEngineClientAnarchy->N3Msg_GetActionProgress(GetIdentity(), pA, pB);
		return a;
	}

	PCSTR SpecialAction::GetName() const
	{
		IDENTITY dummy_identity;
		return pEngineClientAnarchy->N3Msg_GetName(GetIdentity(), dummy_identity);
	}

	SPECIALACTION SpecialAction::GetSpecialActionData() const
	{
		return special_action_;
	}

	SpecialActionItem* SpecialAction::GetSpecialActionItem()
	{
		IDENTITY dummy_identity;
		ZeroMemory(&dummy_identity, sizeof(IDENTITY));
		return reinterpret_cast<SpecialActionItem*>(pEngineClientAnarchy->GetItemByTemplate(GetIdentity(), dummy_identity));
	}


	IDENTITY SpecialAction::GetWeaponIdentity() const
	{
		return GetSpecialActionData().WeaponIdentity;
	}

	bool SpecialAction::IsLocked() const
	{
		return GetSpecialActionData().IsLocked != 0;;
	}

	bool SpecialAction::SpecialActionCompare(SpecialAction &a, SpecialAction &b)
	{
		return a.GetIdentity().Id < b.GetIdentity().Id;
	}

	bool SpecialAction::pSpecialActionCompare(SpecialAction *a, SpecialAction *b)
	{
		return a->GetIdentity().Id < b->GetIdentity().Id;
	}
	
}
#include "isxao_main.h"

namespace isxao_classes
{

	IDENTITY SpecialActionTemplate::GetIdentity() const
	{
		return GetSpecialActionData().Identity;
	}

	DWORD SpecialActionTemplate::GetLockedSkillId1() const
	{
		return special_action_.LockedSkillId1;
	}

	DWORD SpecialActionTemplate::GetLockedSkillId2() const
	{
		return special_action_.LockedSkillId2;
	}

	DWORD SpecialActionTemplate::GetLockoutTimeRemaining() const
	{
		DWORD a, b;
		DWORD *pA = &a;
		DWORD *pB = &b;
		pEngineClientAnarchy->N3Msg_GetActionProgress(GetIdentity(), pA, pB);
		return a;
	}

	//float SpecialAction::GetLockoutTimeRemaining() const
	//{
	//	DWORD a, b;
	//	DWORD *pA = &a;
	//	DWORD *pB = &b;
	//	auto c = pEngineClientAnarchy->N3Msg_GetActionProgress(GetIdentity(), pA, pB);
	//	return float((1.0 - c)*b);
	//}

	PCSTR SpecialActionTemplate::GetName() const
	{
		IDENTITY dummy_identity;
		return pEngineClientAnarchy->N3Msg_GetName(GetIdentity(), dummy_identity);
	}

	SPECIALACTION SpecialActionTemplate::GetSpecialActionData() const
	{
		return special_action_;
	}

	SpecialActionItem* SpecialActionTemplate::GetSpecialActionItem()
	{
		IDENTITY dummy_identity;
		ZeroMemory(&dummy_identity, sizeof(IDENTITY));
		return reinterpret_cast<SpecialActionItem*>(pEngineClientAnarchy->GetItemByTemplate(GetIdentity(), dummy_identity));
	}


	IDENTITY SpecialActionTemplate::GetWeaponIdentity() const
	{
		return GetSpecialActionData().WeaponIdentity;
	}

	bool SpecialActionTemplate::IsLocked() const
	{
		return GetSpecialActionData().IsLocked != 0;;
	}

	bool SpecialActionTemplate::SpecialActionCompare(SpecialActionTemplate &a, SpecialActionTemplate &b)
	{
		return a.GetIdentity().Id < b.GetIdentity().Id;
	}

	bool SpecialActionTemplate::pSpecialActionCompare(SpecialActionTemplate *a, SpecialActionTemplate *b)
	{
		return a->GetIdentity().Id < b->GetIdentity().Id;
	}
	
}
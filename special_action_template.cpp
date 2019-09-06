#include "isxao_main.h"

namespace isxao_classes
{

	identity_t SpecialActionTemplate::GetIdentity() const
	{
		return GetSpecialActionData().identity;
	}

	DWORD SpecialActionTemplate::GetLockedSkillId1() const
	{
		return special_action_.locked_skill_id1;
	}

	DWORD SpecialActionTemplate::GetLockedSkillId2() const
	{
		return special_action_.locked_skill_id2;
	}

	DWORD SpecialActionTemplate::GetLockoutTimeRemaining() const
	{
		DWORD a, b;
		DWORD *pA = &a;
		DWORD *pB = &b;
		P_ENGINE_CLIENT_ANARCHY->N3Msg_GetActionProgress(GetIdentity(), pA, pB);
		return a;
	}

	//float SpecialAction::GetLockoutTimeRemaining() const
	//{
	//	DWORD a, b;
	//	DWORD *pA = &a;
	//	DWORD *pB = &b;
	//	auto c = P_ENGINE_CLIENT_ANARCHY->N3Msg_GetActionProgress(GetIdentity(), pA, pB);
	//	return float((1.0 - c)*b);
	//}

	PCSTR SpecialActionTemplate::GetName() const
	{
		identity_t dummy_identity;
		return P_ENGINE_CLIENT_ANARCHY->N3Msg_GetName(GetIdentity(), dummy_identity);
	}

	special_action_t SpecialActionTemplate::GetSpecialActionData() const
	{
		return special_action_;
	}

	SpecialActionItem* SpecialActionTemplate::GetSpecialActionItem()
	{
		identity_t dummy_identity;
		ZeroMemory(&dummy_identity, sizeof(identity_t));
		return reinterpret_cast<SpecialActionItem*>(P_ENGINE_CLIENT_ANARCHY->get_item_by_template(GetIdentity(), dummy_identity));
	}


	identity_t SpecialActionTemplate::GetWeaponIdentity() const
	{
		return GetSpecialActionData().weapon_identity;
	}

	bool SpecialActionTemplate::IsLocked() const
	{
		return GetSpecialActionData().is_locked != 0;;
	}

	double SpecialActionTemplate::GetSpecialActionProgress(DWORD &a, DWORD &b) const
	{
		return P_ENGINE_CLIENT_ANARCHY->N3Msg_GetItemProgress(GetIdentity(), a, b);
	}

	bool SpecialActionTemplate::SpecialActionCompare(SpecialActionTemplate &a, SpecialActionTemplate &b)
	{
		return a.GetIdentity().id < b.GetIdentity().id;
	}

	bool SpecialActionTemplate::pSpecialActionCompare(SpecialActionTemplate *a, SpecialActionTemplate *b)
	{
		return a->GetIdentity().id < b->GetIdentity().id;
	}
	
}
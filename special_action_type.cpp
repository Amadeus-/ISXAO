#include "isxao_main.h"

bool SpecialActionType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pSpecialAction ((SpecialActionItem*)ObjectData.Ptr)
		switch (SpecialActionTypeMembers(Member->ID))
		{
		case AttackDelay:
		{
			Object.Float = pSpecialAction->GetAttackDelay();
			Object.Type = pfloatType;
			break;
		}
		case CanApplyOnFriendly:
		{
			Object.DWord = pSpecialAction->CanApplyOnFriendly();
			Object.Type = pBoolType;
			break;
		}
		case CanApplyOnHostile:
		{
			Object.DWord = pSpecialAction->CanApplyOnHostile();
			Object.Type = pBoolType;
			break;
		}
		case CanApplyOnSelf:
		{
			Object.DWord = pSpecialAction->CanApplyOnSelf();
			Object.Type = pBoolType;
			break;
		}
		case CanApplyOnFightingTarget:
		{
			Object.DWord = pSpecialAction->CanApplyOnFightingTarget();
			Object.Type = pBoolType;
			break;
		}
		case CanUse:
		{
			Object.DWord = pSpecialAction->CanUse();
			Object.Type = pBoolType;
			break;
		}
		case Description:
		{
			Object.ConstCharPtr = pSpecialAction->GetDescription();
			Object.Type = pStringType;
			break;
		}
		case IsBuff:
		{
			Object.DWord = pSpecialAction->IsBuff();
			Object.Type = pBoolType;
			break;
		}
		case IsGeneralAction:
		{
			Object.DWord = pSpecialAction->IsGeneralAction();
			Object.Type = pBoolType;
			break;
		}
		case IsHostile:
		{
			Object.DWord = pSpecialAction->IsHostile();
			Object.Type = pBoolType;
			break;
		}
		case IsNoRemoveNoNCUIsFriendly:
		{
			Object.DWord = pSpecialAction->IsNoRemoveNoNCUIsFriendly();
			Object.Type = pBoolType;
			break;
		}
		case IsNoResist:
		{
			Object.DWord = pSpecialAction->IsNoResist();
			Object.Type = pBoolType;
			break;
		}
		case IsNoResistNoFumble:
		{
			Object.DWord = pSpecialAction->IsNoResistNoFumble();
			Object.Type = pBoolType;
			break;
		}
		case IsNotRemovable:
		{
			Object.DWord = pSpecialAction->IsNotRemovable();
			Object.Type = pBoolType;
			break;
		}
		case IsPerk:
		{
			Object.DWord = pSpecialAction->IsPerk();
			Object.Type = pBoolType;
			break;
		}
		case IsSpecialAction:
		{
			Object.DWord = pSpecialAction->IsSpecialAction();
			Object.Type = pBoolType;
			break;
		}
		case Name:
		{
			Object.ConstCharPtr = pSpecialAction->GetName();
			Object.Type = pStringType;
			break;
		}
		case Range:
		{
			Object.DWord = pSpecialAction->GetRange();
			Object.Type = pUintType;
			break;
		}
		case SpecialActionId:
		{
			Object.DWord = pSpecialAction->GetIdentity().id;
			Object.Type = pUintType;
			break;
		}		
		case WillBreakOnAttack:
		{
			Object.DWord = pSpecialAction->WillBreakOnAttack();
			Object.Type = pBoolType;
			break;
		}
		case WillBreakOnDebuff:
		{
			Object.DWord = pSpecialAction->WillBreakOnDebuff();
			Object.Type = pBoolType;
			break;
		}
		case WillBreakOnSpellAttack:
		{
			Object.DWord = pSpecialAction->WillBreakOnSpellAttack();
			Object.Type = pBoolType;
			break;
		}
		default: break;
		}
#undef pSpecialAction
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool SpecialActionType::GetMethod(LSOBJECTDATA& ObjectData, PLSTYPEMETHOD pMethod, int argc, char* argv[])
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pSpecialAction ((SpecialActionItem*)ObjectData.Ptr)
		switch (SpecialActionTypeMethods(pMethod->ID))
		{

		default: break;
		}
#undef pSpecialActionItem
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, pMethod->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool SpecialActionType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define pSpecialAction ((SpecialActionItem*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%d", pSpecialAction->GetIdentity().id);
#undef pSpecialAction

	return true;
}
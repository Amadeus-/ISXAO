#include "isxao_main.h"

bool NanoSpellType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pNanoSpell ((NanoItem*)ObjectData.Ptr)
		switch (NanoSpellTypeMembers(Member->ID))
		{
		case CanApplyOnFriendly:
		{
			Object.DWord = pNanoSpell->CanApplyOnFriendly();
			Object.Type = pBoolType;
			break;
		}
		case CanApplyOnFightingTarget:
		{
			Object.DWord = pNanoSpell->CanApplyOnFightingTarget();
			Object.Type = pBoolType;
			break;
		}
		case CanApplyOnHostile:
		{
			Object.DWord = pNanoSpell->CanApplyOnHostile();
			Object.Type = pBoolType;
			break;
		}
		case CanApplyOnSelf:
		{
			Object.DWord = pNanoSpell->CanApplyOnSelf();
			Object.Type = pBoolType;
			break;
		}
		case CastingTime:
		{
			Object.Float = pNanoSpell->GetAttackDelay();
			Object.Type = pfloatType;
			break;
		}
		case FormulaProgress:
		{
			DWORD a;
			DWORD b;
			Object.Float = float(pNanoSpell->GetFormulaProgress(a, b));
			Object.Type = pfloatType;
			break;
		}
		case FormulaRadius:
		{
			Object.DWord = pNanoSpell->GetFormulaRadius();
			Object.Type = pUintType;
			break;
		}
		case IsBuff:
		{
			Object.DWord = pNanoSpell->IsBuff();
			Object.Type = pBoolType;
			break;
		}
		case IsHostile:
		{
			Object.DWord = pNanoSpell->IsHostile();
			Object.Type = pBoolType;
			break;
		}
		case IsNoResistCannotFumble:
		{
			Object.DWord = pNanoSpell->IsNoResistCannotFumble();
			Object.Type = pBoolType;
			break;
		}
		case IsReady:
		{
			Object.DWord = pNanoSpell->IsReady();
			Object.Type = pBoolType;
			break;
		}
		case IsSelfOnly:
		{
			Object.DWord = pNanoSpell->IsNanoSelfOnly();
			Object.Type = pBoolType;
			break;
		}
		case IsShapeChangeNano:
		{
			Object.DWord = pNanoSpell->IsShapeChangeNano();
			Object.Type = pBoolType;
			break;
		}
		case IsTeamNano:
		{
			Object.DWord = pNanoSpell->IsTeamNano();
			Object.Type = pBoolType;
			break;
		}
		case Name:
		{
			Object.ConstCharPtr = pNanoSpell->GetName();
			Object.Type = pStringType;
			break;
		}
		case NanoId:
		{
			Object.DWord = pNanoSpell->GetNanoIdentity().Id;
			Object.Type = pUintType;
			break;
		}
		case NanoSchool:
		{
			Object.ConstCharPtr = isxao_utilities::GetNanoSchoolStr(pNanoSpell->GetNanoSchool());
			Object.Type = pStringType;
			break;
		}
		case NanoStrain:
		{
			Object.DWord = pNanoSpell->GetNanoStrain();
			Object.Type = pUintType;
			break;
		}
		case NCUCost:
		{
			Object.DWord = pNanoSpell->GetNCUCost();
			Object.Type = pUintType;
			break;
		}
		case Range:
		{
			Object.DWord = pNanoSpell->GetAttackRange();
			Object.Type = pUintType;
			break;
		}
		case RechargeDelay:
		{
			Object.Float = pNanoSpell->GetRechargeDelay();
			Object.Type = pfloatType;
			break;
		}
		case StackingOrder:
		{
			Object.DWord = pNanoSpell->GetStackingOrder();
			Object.Type = pUintType;
			break;
		}
		case WillBreakOnAttack:
		{
			Object.DWord = pNanoSpell->WillBreakOnAttack();
			Object.Type = pBoolType;
			break;
		}
		case WillBreakOnDebuff:
		{
			Object.DWord = pNanoSpell->WillBreakOnDebuff();
			Object.Type = pBoolType;
			break;
		}
		case WillBreakOnSpellAttack:
		{
			Object.DWord = pNanoSpell->WillBreakOnSpellAttack();
			Object.Type = pBoolType;
			break;
		}
		default:
			return false;
		}
#undef pNanoSpell
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool NanoSpellType::GetMethod(LSOBJECTDATA& ObjectData, PLSTYPEMETHOD pMethod, int argc, char* argv[])
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pNanoSpell ((NanoItem*)ObjectData.Ptr)
		switch (NanoSpellTypeMethods(pMethod->ID))
		{
		case Cast:
		{
			pNanoSpell->Cast();
		}
		default: break;
		}
#undef pNanoSpell
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, pMethod->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool NanoSpellType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define pNanoSpell ((NanoItem*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%d", pNanoSpell->GetNanoIdentity().Id);
#undef pNanoSpell

	return true;
}
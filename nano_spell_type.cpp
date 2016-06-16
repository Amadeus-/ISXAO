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
		case CastingTime:
		{
			Object.Float = pNanoSpell->GetAttackDelay();
			Object.Type = pfloatType;
			break;
		}
		case FormulaProgress:
		{
			Object.Float = float(pNanoSpell->GetFormulaProgress());
			Object.Type = pfloatType;
			break;
		}
		case FormulaRadius:
		{
			Object.DWord = pNanoSpell->GetFormulaRadius();
			Object.Type = pUintType;
			break;
		}
		case Name:
		{
			Object.ConstCharPtr = pNanoSpell->GetName();
			Object.Type = pStringType;
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
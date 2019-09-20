#include "isxao_main.h"

bool NanoSpellType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (g_game_state != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define P_NANO_SPELL ((ao::nano_item*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (NanoSpellTypeMembers(Member->ID))
		{
		case CanApplyOnFriendly:
		{
			Object.DWord = P_NANO_SPELL->can_apply_on_friendly();
			Object.Type = pBoolType;
			break;
		}
		case CanApplyOnFightingTarget:
		{
			Object.DWord = P_NANO_SPELL->can_apply_on_fighting_target();
			Object.Type = pBoolType;
			break;
		}
		case CanApplyOnHostile:
		{
			Object.DWord = P_NANO_SPELL->can_apply_on_hostile();
			Object.Type = pBoolType;
			break;
		}
		case CanApplyOnSelf:
		{
			Object.DWord = P_NANO_SPELL->can_apply_on_self();
			Object.Type = pBoolType;
			break;
		}
		case CastingTime:
		{
			Object.Float = P_NANO_SPELL->get_attack_delay();
			Object.Type = pfloatType;
			break;
		}
		case FormulaProgress:
		{
			DWORD a;
			DWORD b;
			double result = P_NANO_SPELL->get_formula_progress(a, b);
			Object.DWord = b;
			Object.Type = pUintType;
			break;
		}
		case FormulaRadius:
		{
			Object.DWord = P_NANO_SPELL->get_formula_radius();
			Object.Type = pUintType;
			break;
		}
		case IsBuff:
		{
			Object.DWord = P_NANO_SPELL->is_buff();
			Object.Type = pBoolType;
			break;
		}
		case IsHostile:
		{
			Object.DWord = P_NANO_SPELL->is_hostile();
			Object.Type = pBoolType;
			break;
		}
		case IsNoResistCannotFumble:
		{
			Object.DWord = P_NANO_SPELL->is_no_resist_cannot_fumble();
			Object.Type = pBoolType;
			break;
		}
		case IsReady:
		{
			Object.DWord = P_NANO_SPELL->is_ready();
			Object.Type = pBoolType;
			break;
		}
		case IsSelfOnly:
		{
			Object.DWord = P_NANO_SPELL->is_nano_self_only();
			Object.Type = pBoolType;
			break;
		}
		case IsShapeChangeNano:
		{
			Object.DWord = P_NANO_SPELL->is_shape_change_nano();
			Object.Type = pBoolType;
			break;
		}
		case IsTeamNano:
		{
			Object.DWord = P_NANO_SPELL->is_team_nano();
			Object.Type = pBoolType;
			break;
		}
		case Name:
		{
			Object.ConstCharPtr = P_NANO_SPELL->get_name();
			Object.Type = pStringType;
			break;
		}
		case NanoId:
		{
			Object.DWord = P_NANO_SPELL->get_nano_identity().id;
			Object.Type = pUintType;
			break;
		}
		case NanoSchool:
		{
			Object.ConstCharPtr = ao::engine_client_anarchy::get_nano_school_str(P_NANO_SPELL->get_nano_school());
			Object.Type = pStringType;
			break;
		}
		case NanoStrain:
		{
			Object.DWord = P_NANO_SPELL->get_nano_strain();
			Object.Type = pUintType;
			break;
		}
		case NCUCost:
		{
			Object.DWord = P_NANO_SPELL->get_ncu_cost();
			Object.Type = pUintType;
			break;
		}
		case Range:
		{
			Object.DWord = P_NANO_SPELL->get_attack_range();
			Object.Type = pUintType;
			break;
		}
		case RechargeDelay:
		{
			Object.Float = P_NANO_SPELL->get_recharge_delay();
			Object.Type = pfloatType;
			break;
		}
		case StackingOrder:
		{
			Object.DWord = P_NANO_SPELL->get_stacking_order();
			Object.Type = pUintType;
			break;
		}
		case WillBreakOnAttack:
		{
			Object.DWord = P_NANO_SPELL->will_break_on_attack();
			Object.Type = pBoolType;
			break;
		}
		case WillBreakOnDebuff:
		{
			Object.DWord = P_NANO_SPELL->will_break_on_debuff();
			Object.Type = pBoolType;
			break;
		}
		case WillBreakOnSpellAttack:
		{
			Object.DWord = P_NANO_SPELL->will_break_on_spell_attack();
			Object.Type = pBoolType;
			break;
		}
		default:
			return false;
		}
#undef P_NANO_SPELL
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool NanoSpellType::GetMethod(LSOBJECTDATA& ObjectData, PLSTYPEMETHOD pMethod, int argc, char* argv[])
{
	if (g_game_state != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define P_NANO_SPELL ((ao::nano_item*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (NanoSpellTypeMethods(pMethod->ID))
		{
		case Cast:
		{
			P_NANO_SPELL->cast();
		}
		default: break;
		}
#undef P_NANO_SPELL
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, pMethod->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool NanoSpellType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (g_game_state != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define P_NANO_SPELL ((ao::nano_item*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
	sprintf_s(buf, buflen, "%d", P_NANO_SPELL->get_nano_identity().id);
#undef P_NANO_SPELL

	return true;
}
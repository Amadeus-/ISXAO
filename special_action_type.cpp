#include "isxao_main.h"

bool SpecialActionType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define P_SPECIAL_ACTION ((ao::special_action_item*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (SpecialActionTypeMembers(Member->ID))
		{
		case AttackDelay:
		{
			Object.Float = P_SPECIAL_ACTION->get_attack_delay();
			Object.Type = pfloatType;
			break;
		}
		case CanApplyOnFriendly:
		{
			Object.DWord = P_SPECIAL_ACTION->can_apply_on_friendly();
			Object.Type = pBoolType;
			break;
		}
		case CanApplyOnHostile:
		{
			Object.DWord = P_SPECIAL_ACTION->can_apply_on_hostile();
			Object.Type = pBoolType;
			break;
		}
		case CanApplyOnSelf:
		{
			Object.DWord = P_SPECIAL_ACTION->can_apply_on_self();
			Object.Type = pBoolType;
			break;
		}
		case CanApplyOnFightingTarget:
		{
			Object.DWord = P_SPECIAL_ACTION->can_apply_on_fighting_target();
			Object.Type = pBoolType;
			break;
		}
		case CanUse:
		{
			Object.DWord = P_SPECIAL_ACTION->can_use();
			Object.Type = pBoolType;
			break;
		}
		case Description:
		{
			Object.ConstCharPtr = P_SPECIAL_ACTION->get_description();
			Object.Type = pStringType;
			break;
		}
		case IsBuff:
		{
			Object.DWord = P_SPECIAL_ACTION->is_buff();
			Object.Type = pBoolType;
			break;
		}
		case IsGeneralAction:
		{
			Object.DWord = P_SPECIAL_ACTION->is_general_action();
			Object.Type = pBoolType;
			break;
		}
		case IsHostile:
		{
			Object.DWord = P_SPECIAL_ACTION->is_hostile();
			Object.Type = pBoolType;
			break;
		}
		case IsNoRemoveNoNCUIsFriendly:
		{
			Object.DWord = P_SPECIAL_ACTION->is_no_remove_no_ncu_is_friendly();
			Object.Type = pBoolType;
			break;
		}
		case IsNoResist:
		{
			Object.DWord = P_SPECIAL_ACTION->is_no_resist();
			Object.Type = pBoolType;
			break;
		}
		case IsNoResistNoFumble:
		{
			Object.DWord = P_SPECIAL_ACTION->is_no_resist_no_fumble();
			Object.Type = pBoolType;
			break;
		}
		case IsNotRemovable:
		{
			Object.DWord = P_SPECIAL_ACTION->is_not_removable();
			Object.Type = pBoolType;
			break;
		}
		case IsPerk:
		{
			Object.DWord = P_SPECIAL_ACTION->is_perk();
			Object.Type = pBoolType;
			break;
		}
		case IsSpecialAction:
		{
			Object.DWord = P_SPECIAL_ACTION->is_special_action();
			Object.Type = pBoolType;
			break;
		}
		case Name:
		{
			Object.ConstCharPtr = P_SPECIAL_ACTION->get_name();
			Object.Type = pStringType;
			break;
		}
		case Range:
		{
			Object.DWord = P_SPECIAL_ACTION->get_range();
			Object.Type = pUintType;
			break;
		}
		case SpecialActionId:
		{
			Object.DWord = P_SPECIAL_ACTION->get_identity().id;
			Object.Type = pUintType;
			break;
		}		
		case WillBreakOnAttack:
		{
			Object.DWord = P_SPECIAL_ACTION->will_break_on_attack();
			Object.Type = pBoolType;
			break;
		}
		case WillBreakOnDebuff:
		{
			Object.DWord = P_SPECIAL_ACTION->will_break_on_debuff();
			Object.Type = pBoolType;
			break;
		}
		case WillBreakOnSpellAttack:
		{
			Object.DWord = P_SPECIAL_ACTION->will_break_on_spell_attack();
			Object.Type = pBoolType;
			break;
		}
		default: break;
		}
#undef P_SPECIAL_ACTION
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
#define P_SPECIAL_ACTION ((ao::special_action_item*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
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
#define P_SPECIAL_ACTION ((ao::special_action_item*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
	sprintf_s(buf, buflen, "%d", P_SPECIAL_ACTION->get_identity().id);
#undef P_SPECIAL_ACTION

	return true;
}
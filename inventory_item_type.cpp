#include "isxao_main.h"

bool InventoryItemType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define P_INVENTORY_ITEM ((ao::inventory_item*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (InventoryItemTypeMembers(Member->ID))
		{
		case CanApplyOnFriendly:
		{
			Object.DWord = P_INVENTORY_ITEM->can_apply_on_friendly();
			Object.Type = pBoolType;
			break;
		}
		case CanApplyOnHostile:
		{
			Object.DWord = P_INVENTORY_ITEM->can_apply_on_hostile();
			Object.Type = pBoolType;
			break;
		}
		case CanApplyOnFightingTarget:
		{
			Object.DWord = P_INVENTORY_ITEM->can_apply_on_fighting_target();
			Object.Type = pBoolType;
			break;
		}
		case CanApplyOnSelf:
		{
			Object.DWord = P_INVENTORY_ITEM->can_apply_on_self();
			Object.Type = pBoolType;
			break;
		}
		case CanBeSplit:
		{
			Object.DWord = P_INVENTORY_ITEM->can_be_split();
			Object.Type = pBoolType;
			break;
		}
		case CanUse:
		{
			Object.DWord = P_INVENTORY_ITEM->can_use();
			Object.Type = pBoolType;
			break;
		}
		case Description:
		{
			Object.ConstCharPtr = P_INVENTORY_ITEM->get_description();
			Object.Type = pStringType;
			break;
		}
		case IsArmor:
		{
			Object.DWord = P_INVENTORY_ITEM->is_armor();
			Object.Type = pBoolType;
			break;
		}
		case IsConsumable:
		{
			Object.DWord = P_INVENTORY_ITEM->is_consumable();
			Object.Type = pBoolType;
			break;
		}
		case IsImplant:
		{
			Object.DWord = P_INVENTORY_ITEM->is_implant();
			Object.Type = pBoolType;
			break;
		}
		case IsMisc:
		{
			Object.DWord = P_INVENTORY_ITEM->is_misc();
			Object.Type = pBoolType;
			break;
		}
		case IsNPC:
		{
			Object.DWord = P_INVENTORY_ITEM->is_npc();
			Object.Type = pBoolType;
			break;
		}
		case IsSpirit:
		{
			Object.DWord = P_INVENTORY_ITEM->is_spirit();
			Object.Type = pBoolType;
			break;
		}
		case IsStackable:
		{
			Object.DWord = P_INVENTORY_ITEM->is_stackable();
			Object.Type = pBoolType;
			break;
		}
		case IsTower:
		{
			Object.DWord = P_INVENTORY_ITEM->is_tower();
			Object.Type = pBoolType;
			break;
		}
		case IsWeapon:
		{
			Object.DWord = P_INVENTORY_ITEM->is_weapon();
			Object.Type = pBoolType;
			break;
		}
		case IsUtility:
		{
			Object.DWord = P_INVENTORY_ITEM->is_utility();
			Object.Type = pBoolType;
			break;
		}
		case MustSit:
		{
			Object.DWord = P_INVENTORY_ITEM->must_sit_to_use();
			Object.Type = pBoolType;
			break;
		}
		case Name:
		{
			Object.ConstCharPtr = P_INVENTORY_ITEM->get_name();
			Object.Type = pStringType;
			break;
		}
		case Rarity:
		{
			Object.ConstCharPtr = P_INVENTORY_ITEM->get_rarity();
			Object.Type = pStringType;
			break;
		}
		default: break;
		}
#undef P_INVENTORY_ITEM
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool InventoryItemType::GetMethod(LSOBJECTDATA& ObjectData, PLSTYPEMETHOD pMethod, int argc, char* argv[])
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define P_INVENTORY_ITEM ((ao::inventory_item*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (InventoryItemTypeMethods(pMethod->ID))
		{

		default: break;
		}
#undef P_INVENTORY_ITEM
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, pMethod->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool InventoryItemType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define P_INVENTORY_ITEM ((ao::inventory_item*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
	sprintf_s(buf, buflen, "%s", P_INVENTORY_ITEM->get_name());
#undef P_INVENTORY_ITEM

	return true;
}
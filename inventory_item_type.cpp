#include "isxao_main.h"

bool InventoryItemType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pInventoryItem ((InventoryItem*)ObjectData.Ptr)
		switch (InventoryItemTypeMembers(Member->ID))
		{
		case CanApplyOnFriendly:
		{
			Object.DWord = pInventoryItem->CanApplyOnFriendly();
			Object.Type = pBoolType;
			break;
		}
		case CanApplyOnHostile:
		{
			Object.DWord = pInventoryItem->CanApplyOnHostile();
			Object.Type = pBoolType;
			break;
		}
		case CanApplyOnFightingTarget:
		{
			Object.DWord = pInventoryItem->CanApplyOnFightingTarget();
			Object.Type = pBoolType;
			break;
		}
		case CanApplyOnSelf:
		{
			Object.DWord = pInventoryItem->CanApplyOnSelf();
			Object.Type = pBoolType;
			break;
		}
		case CanBeSplit:
		{
			Object.DWord = pInventoryItem->CanBeSplit();
			Object.Type = pBoolType;
			break;
		}
		case CanUse:
		{
			Object.DWord = pInventoryItem->CanUse();
			Object.Type = pBoolType;
			break;
		}
		case Description:
		{
			Object.ConstCharPtr = pInventoryItem->GetDescription();
			Object.Type = pStringType;
			break;
		}
		case IsArmor:
		{
			Object.DWord = pInventoryItem->IsArmor();
			Object.Type = pBoolType;
			break;
		}
		case IsConsumable:
		{
			Object.DWord = pInventoryItem->IsConsumable();
			Object.Type = pBoolType;
			break;
		}
		case IsImplant:
		{
			Object.DWord = pInventoryItem->IsImplant();
			Object.Type = pBoolType;
			break;
		}
		case IsMisc:
		{
			Object.DWord = pInventoryItem->IsMisc();
			Object.Type = pBoolType;
			break;
		}
		case IsNPC:
		{
			Object.DWord = pInventoryItem->IsNPC();
			Object.Type = pBoolType;
			break;
		}
		case IsReady:
		{
			Object.DWord = !pInventoryItem->IsItemDisabled();
			Object.Type = pBoolType;
			break;
		}
		case IsSpirit:
		{
			Object.DWord = pInventoryItem->IsSpirit();
			Object.Type = pBoolType;
			break;
		}
		case IsStackable:
		{
			Object.DWord = pInventoryItem->IsStackable();
			Object.Type = pBoolType;
			break;
		}
		case IsTower:
		{
			Object.DWord = pInventoryItem->IsTower();
			Object.Type = pBoolType;
			break;
		}
		case IsWeapon:
		{
			Object.DWord = pInventoryItem->IsWeapon();
			Object.Type = pBoolType;
			break;
		}
		case IsUtility:
		{
			Object.DWord = pInventoryItem->IsUtility();
			Object.Type = pBoolType;
			break;
		}
		case MustSit:
		{
			Object.DWord = pInventoryItem->MustSitToUse();
			Object.Type = pBoolType;
			break;
		}
		case Name:
		{
			Object.ConstCharPtr = pInventoryItem->GetName();
			Object.Type = pStringType;
			break;
		}
		case Rarity:
		{
			Object.ConstCharPtr = pInventoryItem->GetRarity();
			Object.Type = pStringType;
			break;
		}
		default: break;
		}
#undef pInventoryItem
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
#define pInventoryItem ((InventoryItem*)ObjectData.Ptr)
		switch (InventoryItemTypeMethods(pMethod->ID))
		{

		default: break;
		}
#undef pInventoryItem
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
#define pInventoryItem ((InventoryItem*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%s", pInventoryItem->GetName());
#undef pInventoryItem

	return true;
}
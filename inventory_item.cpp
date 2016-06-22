#include "isxao_main.h"

namespace isxao_classes
{

	bool InventoryItem::CanApplyOnFightingTarget()
	{
		return (GetCanFlags() & ICF_APPLY_ON_FIGHTING_TARGET) == 1;
	}

	bool InventoryItem::CanApplyOnFriendly()
	{
		return (GetCanFlags() & ICF_APPLY_ON_FRIENDLY) == 1;
	}

	bool InventoryItem::CanApplyOnHostile()
	{
		return (GetCanFlags() & ICF_APPLY_ON_HOSTILE) == 1;
	}

	bool InventoryItem::CanApplyOnSelf()
	{
		return (GetCanFlags() & ICF_APPLY_ON_SELF) == 1;
	}

	bool InventoryItem::CanBeSplit()
	{
		return (GetCanFlags() & ICF_CANT_SPLIT) == 0;
	}

	bool InventoryItem::CanUse()
	{
		return (GetCanFlags() & ICF_USE) == 1;
	}

	DWORD InventoryItem::GetCanFlags()
	{
		return GetSkill(ST_CAN);
	}

	DWORD InventoryItem::GetMass()
	{
		return GetSkill(ST_VOLUMEMASS);
	}

	DWORD InventoryItem::GetNoneFlags()
	{
		return GetSkill(ST_FLAGS);
	}

	DWORD InventoryItem::GetQL()
	{
		return GetSkill(ST_LEVEL);
	}

	PCSTR InventoryItem::GetRarity()
	{
		return isxao_utilities::GetItemRarityStr(GetSkill(ST_RARITY));
	}


	DWORD InventoryItem::GetValue()
	{
		return GetSkill(ST_PRICE);
	}

	LONG InventoryItem::GetSkill(DWORD stat)
	{
		IDENTITY dummy_identity;
		ZeroMemory(&dummy_identity, sizeof(IDENTITY));
		auto result = 1234567890;
		if (pEngineClientAnarchy)
			result = pEngineClientAnarchy->N3Msg_GetSkill(GetIdentity(), stat, 2, dummy_identity);
		return result;
	}

	bool InventoryItem::IsArmor()
	{
		return GetSkill(ST_ITEMCLASS) == IT_ARMOR;
	}

	bool InventoryItem::IsConsumable()
	{
		return (GetCanFlags() & ICF_CONSUME) == 1;
	}

	bool InventoryItem::IsImplant()
	{
		return GetSkill(ST_ITEMCLASS) == IT_IMPLANT;
	}

	bool InventoryItem::IsMisc()
	{
		return GetSkill(ST_ITEMCLASS) == IT_MISC;
	}

	bool InventoryItem::IsNPC()
	{
		return GetSkill(ST_ITEMCLASS) == IT_NPC;
	}

	bool InventoryItem::IsSpirit()
	{
		return GetSkill(ST_ITEMCLASS) == IT_SPIRIT;
	}

	bool InventoryItem::IsStackable()
	{
		return (GetCanFlags() & ICF_STACKABLE) == 1;
	}

	bool InventoryItem::IsTower()
	{
		return GetSkill(ST_ITEMCLASS) == IT_TOWER;
	}

	bool InventoryItem::IsUtility()
	{
		return GetSkill(ST_ITEMCLASS) == IT_UTILITY;
	}

	bool InventoryItem::IsWeapon()
	{
		return GetSkill(ST_ITEMCLASS) == IT_WEAPON;
	}

	bool InventoryItem::MustSitToUse()
	{
		return (GetCanFlags() & ICF_SIT) == 1;
	}

}
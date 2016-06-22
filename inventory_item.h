#pragma once

class InventoryItem : public DummyItemBase
{
public:
	AOLIB_OBJECT bool CanApplyOnFightingTarget();
	AOLIB_OBJECT bool CanApplyOnFriendly();
	AOLIB_OBJECT bool CanApplyOnHostile();
	AOLIB_OBJECT bool CanApplyOnSelf();
	AOLIB_OBJECT bool CanBeSplit();
	AOLIB_OBJECT bool CanUse();
	AOLIB_OBJECT DWORD GetCanFlags();
	AOLIB_OBJECT DWORD GetMass();
	AOLIB_OBJECT DWORD GetNoneFlags();
	AOLIB_OBJECT DWORD GetQL();
	AOLIB_OBJECT PCSTR GetRarity();
	AOLIB_OBJECT LONG GetSkill(DWORD);
	AOLIB_OBJECT DWORD GetValue();
	AOLIB_OBJECT bool IsArmor();
	AOLIB_OBJECT bool IsConsumable();
	AOLIB_OBJECT bool IsImplant();
	AOLIB_OBJECT bool IsMisc();
	AOLIB_OBJECT bool IsNPC();
	AOLIB_OBJECT bool IsSpirit();
	AOLIB_OBJECT bool IsStackable();
	AOLIB_OBJECT bool IsTower();
	AOLIB_OBJECT bool IsWeapon();
	AOLIB_OBJECT bool IsUtility();
	AOLIB_OBJECT bool MustSitToUse();
};
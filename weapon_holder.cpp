#include "isxao_main.h"

namespace isxao_classes
{

	WEAPONHOLDER WeaponHolder::GetWeaponHolderData() const
	{
		return weapon_holder_;
	}

	DWORD WeaponHolder::GetWeaponItems(std::map<DWORD, PWEAPONITEM> &m) const
	{
		auto weapon_item_dir = GetWeaponHolderData().WeaponItemDir;
		GetWeaponItemMap(m, weapon_item_dir);
		return m.size();
	}

	identity_t WeaponHolder::GetWeaponTarget() const
	{
		return GetWeaponHolderData().WeaponTargetIdentity;
	}

	bool WeaponHolder::IsAttacking() const
	{
		return GetWeaponHolderData().IsAttacking != 1;
	}

}
#include "isxao_main.h"

namespace isxao_classes
{

	weapon_holder_t WeaponHolder::GetWeaponHolderData() const
	{
		return weapon_holder_;
	}

	DWORD WeaponHolder::GetWeaponItems(std::map<DWORD, p_weapon_item_t> &m) const
	{
		auto weapon_item_dir = GetWeaponHolderData().weapon_item_dir;
		GetWeaponItemMap(m, weapon_item_dir);
		return m.size();
	}

	identity_t WeaponHolder::GetWeaponTarget() const
	{
		return GetWeaponHolderData().weapon_target_identity;
	}

	bool WeaponHolder::IsAttacking() const
	{
		return GetWeaponHolderData().is_attacking != 1;
	}

}
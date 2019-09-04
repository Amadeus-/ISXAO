#pragma once

class WeaponHolder
{
public:
	AOLIB_OBJECT weapon_holder_t GetWeaponHolderData() const;
	AOLIB_OBJECT DWORD GetWeaponItems(std::map<DWORD, p_weapon_item_t>&) const;
	AOLIB_OBJECT identity_t GetWeaponTarget() const;
	AOLIB_OBJECT bool IsAttacking() const;
private:
	weapon_holder_t weapon_holder_;
};
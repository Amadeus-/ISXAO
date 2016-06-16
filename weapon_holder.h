#pragma once

class WeaponHolder
{
public:
	AOLIB_OBJECT WEAPONHOLDER GetWeaponHolderData() const;
	AOLIB_OBJECT DWORD GetWeaponItems(std::map<DWORD, PWEAPONITEM>&) const;
	AOLIB_OBJECT IDENTITY GetWeaponTarget() const;
	AOLIB_OBJECT bool IsAttacking() const;
private:
	WEAPONHOLDER weapon_holder_;
};
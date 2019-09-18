#include "isxao_main.h"

namespace ao
{

	weapon_holder_t weapon_holder::get_weapon_holder_data() const
	{
		return weapon_holder_;
	}

	DWORD weapon_holder::get_weapon_items(std::map<DWORD, p_weapon_item_t> &m) const
	{
		auto weapon_item_dir = get_weapon_holder_data().weapon_item_dir;
		GetWeaponItemMap(m, weapon_item_dir);
		return m.size();
	}

	identity_t weapon_holder::get_weapon_target() const
	{
		return get_weapon_holder_data().weapon_target_identity;
	}

	bool weapon_holder::is_attacking() const
	{
		return get_weapon_holder_data().is_attacking != 1;
	}

}
#include "isxao_main.h"

namespace ao
{
	PVOID weapon_holder::get_data()
	{
		return &weapon_holder_;
	}

	weapon_holder_t weapon_holder::get_weapon_holder_data() const
	{
		return weapon_holder_;
	}

	DWORD weapon_holder::get_weapon_items(std::map<DWORD, p_dummy_item_base_t> &m)
	{
		return weapon_holder_.weapon_item_dir.copy_map(m);
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
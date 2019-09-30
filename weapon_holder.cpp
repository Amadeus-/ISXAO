#include "isxao_main.h"
#include "weapon_holder.h"

namespace ao
{
	DWORD weapon_holder::get_weapon_items(std::map<DWORD, p_dummy_item_base_t> &m)
	{
		return get_data()->weapon_item_dir.copy_map(m);
	}

	identity_t weapon_holder::get_weapon_target()
	{
		return get_data()->weapon_target_identity;
	}

	bool weapon_holder::is_attacking()
	{
		return get_data()->is_attacking != 1;
	}

}
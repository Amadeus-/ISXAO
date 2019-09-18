#include "isxao_main.h"

namespace ao
{

	DWORD new_inventory::get_inventory(std::vector<inventory_data*> &v) const
	{
		auto inventory_vector = get_new_inventory_data().p_inventory_data;
		for (auto it = inventory_vector.begin(); it != inventory_vector.end(); ++it)  // NOLINT(modernize-loop-convert)
			v.push_back(reinterpret_cast<inventory_data*>(*it));
		return v.size();
	}

	identity_t new_inventory::get_inventory_identity() const
	{
		return get_new_inventory_data().inventory_identity;
	}

	DWORD new_inventory::get_inventory_size() const
	{
		return get_new_inventory_data().count;
	}

	new_inventory_t new_inventory::get_new_inventory_data() const
	{
		return new_inventory_;
	}

}
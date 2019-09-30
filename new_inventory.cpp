#include "isxao_main.h"
#include "new_inventory.h"

namespace ao
{

	unsigned long new_inventory::get_inventory(std::vector<inventory_data*> &v)
	{
		auto inventory_vector = get_data()->p_inventory_data;
		for (auto it = inventory_vector.begin(); it != inventory_vector.end(); ++it)  // NOLINT(modernize-loop-convert)
			v.push_back(reinterpret_cast<inventory_data*>(*it));
		return v.size();
	}

	identity_t new_inventory::get_inventory_identity()
	{
		return get_data()->inventory_identity;
	}

	unsigned long new_inventory::get_inventory_size()
	{
		return get_data()->count;
	}

}
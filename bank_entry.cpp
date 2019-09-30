#include "isxao_main.h"
#include "bank_entry.h"

namespace ao
{

	DWORD bank_entry::get_inventory(std::vector<inventory_data*> &v)
	{
		auto inventory_vector = get_data()->inventory;
		for (auto it = inventory_vector.begin(); it != inventory_vector.end(); ++it)  // NOLINT(modernize-loop-convert)
			v.push_back(reinterpret_cast<inventory_data*>(*it));
		return v.size();
	}

	identity_t bank_entry::get_inventory_identity()
	{
		return get_data()->inventory_identity;
	}

	DWORD bank_entry::get_inventory_size()
	{
		return get_data()->count;
	}

}
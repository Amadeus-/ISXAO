#include "isxao_main.h"

namespace isxao_classes
{

	bank_entry_t bank_entry::get_bank_entry_data() const
	{
		return bank_entry_;
	}

	DWORD bank_entry::get_inventory(std::vector<inventory_data*> &v) const
	{
		auto inventory_vector = get_bank_entry_data().inventory;
		for (auto it = inventory_vector.begin(); it != inventory_vector.end(); ++it)  // NOLINT(modernize-loop-convert)
			v.push_back(reinterpret_cast<inventory_data*>(*it));
		return v.size();
	}

	identity_t bank_entry::get_inventory_identity() const
	{
		return get_bank_entry_data().inventory_identity;
	}

	DWORD bank_entry::get_inventory_size() const
	{
		return get_bank_entry_data().count;
	}

}
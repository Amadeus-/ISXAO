#include "isxao_main.h"

namespace isxao_classes
{

	DWORD NewInventory::GetInventory(std::vector<InventoryData*> &v) const
	{
		auto inventory_vector = GetNewInventoryData().p_inventory_data;
		for (auto it = inventory_vector.begin(); it != inventory_vector.end(); ++it)
			v.push_back(reinterpret_cast<InventoryData*>(*it));
		return v.size();
	}

	identity_t NewInventory::GetInventoryIdentity() const
	{
		return GetNewInventoryData().inventory_identity;
	}

	DWORD NewInventory::GetInventorySize() const
	{
		return GetNewInventoryData().count;
	}

	new_inventory_t NewInventory::GetNewInventoryData() const
	{
		return new_inventory_;
	}

}
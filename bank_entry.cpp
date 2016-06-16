#include "isxao_main.h"

namespace isxao_classes
{

	BANKENTRY BankEntry::GetBankEntryData() const
	{
		return bank_entry_;
	}

	DWORD BankEntry::GetInventory(std::vector<InventoryData*> &v) const
	{
		auto inventory_vector = GetBankEntryData().Inventory;
		for (auto it = inventory_vector.begin(); it != inventory_vector.end(); ++it)
			v.push_back(reinterpret_cast<InventoryData*>(*it));
		return v.size();
	}

	IDENTITY BankEntry::GetInventoryIdentity() const
	{
		return GetBankEntryData().InventoryIdentity;
	}

	DWORD BankEntry::GetInventorySize() const
	{
		return GetBankEntryData().Count;
	}

}
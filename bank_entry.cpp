#include "isxao_main.h"

namespace isxao_classes
{

	bank_entry_t BankEntry::GetBankEntryData() const
	{
		return bank_entry_;
	}

	DWORD BankEntry::GetInventory(std::vector<InventoryData*> &v) const
	{
		auto inventory_vector = GetBankEntryData().inventory;
		for (auto it = inventory_vector.begin(); it != inventory_vector.end(); ++it)
			v.push_back(reinterpret_cast<InventoryData*>(*it));
		return v.size();
	}

	identity_t BankEntry::GetInventoryIdentity() const
	{
		return GetBankEntryData().inventory_identity;
	}

	DWORD BankEntry::GetInventorySize() const
	{
		return GetBankEntryData().count;
	}

}
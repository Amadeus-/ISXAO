#include "isxao_main.h"

namespace isxao_classes
{

	BankEntry* InventoryHolder::GetBankInventory() const
	{
		return reinterpret_cast<BankEntry*>(GetInventoryHolderData().pBankEntry);
	}

	NewInventory* InventoryHolder::GetNewInventory() const
	{
		return reinterpret_cast<NewInventory*>(GetInventoryHolderData().pInventory);
	}

	INVENTORYHOLDER InventoryHolder::GetInventoryHolderData() const
	{
		return inventory_holder_;
	}

	PIDENTITY InventoryHolder::GetInventoryHolderIdentity() const
	{
		return GetInventoryHolderData().pClientIdentity;
	}

	NewInventory* InventoryHolder::GetOverflowInventory() const
	{
		return reinterpret_cast<NewInventory*>(GetInventoryHolderData().pOverflowInventory);
	}

}
#pragma once

class InventoryHolder
{
public:
	AOLIB_OBJECT BankEntry* GetBankInventory() const;
	AOLIB_OBJECT NewInventory* GetNewInventory() const;
	AOLIB_OBJECT INVENTORYHOLDER GetInventoryHolderData() const;
	AOLIB_OBJECT PIDENTITY GetInventoryHolderIdentity() const;
	AOLIB_OBJECT NewInventory* GetOverflowInventory() const;
private:
	INVENTORYHOLDER inventory_holder_;
};
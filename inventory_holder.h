#pragma once

class InventoryHolder
{
public:
	AOLIB_OBJECT DWORD BuildLSInventory(LSObjectCollection *pMap) const;
	AOLIB_OBJECT DWORD BuildLSInventory(LSIndex *pIndex) const;
	AOLIB_OBJECT BankEntry* GetBankInventory() const;
	AOLIB_OBJECT DWORD GetInventoryCount() const;
	AOLIB_OBJECT NewInventory* GetNewInventory() const;
	AOLIB_OBJECT INVENTORYHOLDER GetInventoryHolderData() const;
	AOLIB_OBJECT PIDENTITY GetInventoryHolderIdentity() const;
	AOLIB_OBJECT NewInventory* GetOverflowInventory() const;
	AOLIB_OBJECT DWORD GetInventory(std::map<IDENTITY, InventoryItem*>&) const;
	AOLIB_OBJECT InventoryItem* GetInventoryItem(DWORD) const;
	AOLIB_OBJECT InventoryItem* GetInventoryItem(PCSTR) const;
	AOLIB_OBJECT INVENTORYSLOT GetInventorySlot(DWORD) const;
	AOLIB_OBJECT INVENTORYSLOT GetInventorySlot(PCSTR) const;
private:
	INVENTORYHOLDER inventory_holder_;
};
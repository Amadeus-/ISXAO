#pragma once

class InventoryHolder
{
public:
	AOLIB_OBJECT DWORD BuildLSInventory(LSObjectCollection *pMap) const;
	AOLIB_OBJECT DWORD BuildLSInventory(LSIndex *pIndex) const;
	AOLIB_OBJECT DWORD GetArmorInventory(std::vector<inventory_data_t*> &v);
	AOLIB_OBJECT BankEntry* GetBankInventory() const;
	AOLIB_OBJECT DWORD GetCharacterInventory(std::vector<inventory_data_t*> &v);
	AOLIB_OBJECT DWORD GetImplantInventory(std::vector<inventory_data_t*> &v);
	AOLIB_OBJECT DWORD GetInventoryCount() const;
	AOLIB_OBJECT NewInventory* GetNewInventory() const;
	AOLIB_OBJECT INVENTORYHOLDER GetInventoryHolderData() const;
	AOLIB_OBJECT p_identity_t GetInventoryHolderIdentity() const;
	AOLIB_OBJECT NewInventory* GetOverflowInventory() const;
	AOLIB_OBJECT DWORD GetInventory(std::map<identity_t, InventoryItem*>&) const;
	AOLIB_OBJECT InventoryItem* GetInventoryItem(DWORD) const;
	AOLIB_OBJECT InventoryItem* GetInventoryItem(PCSTR) const;
	AOLIB_OBJECT INVENTORYSLOT GetInventorySlot(DWORD) const;
	AOLIB_OBJECT INVENTORYSLOT GetInventorySlot(PCSTR) const;
	AOLIB_OBJECT DWORD GetWeaponInventory(std::vector<inventory_data_t*> &v);
private:
	INVENTORYHOLDER inventory_holder_;
};
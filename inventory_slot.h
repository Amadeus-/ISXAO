#pragma once

typedef struct _INVENTORYSLOT
{
	identity_t SlotID;
	InventoryItem* pItem;

	PCSTR GetSlotName() const;	

	p_inventory_data_t GetInvSlotData();

	double GetItemProgress(DWORD&, DWORD&) const;

	bool IsItemLocked() const;

} INVENTORYSLOT, *PINVENTORYSLOT;
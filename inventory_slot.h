#pragma once

typedef struct _INVENTORYSLOT
{
	IDENTITY SlotID;
	InventoryItem* pItem;

	PCSTR GetSlotName() const;	

	PINVENTORYDATA GetInvSlotData();

	double GetItemProgress(DWORD&, DWORD&) const;

	bool IsItemLocked() const;

} INVENTORYSLOT, *PINVENTORYSLOT;
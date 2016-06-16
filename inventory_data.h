#pragma once

class InventoryData
{
public:
	AOLIB_OBJECT IDENTITY GetDynelId() const;
	AOLIB_OBJECT INVENTORYDATA GetInventoryDataData() const;
	AOLIB_OBJECT DWORD GetItemCount() const;
	AOLIB_OBJECT RDBIDENTITY GetRDBIdentity() const;
private:
	INVENTORYDATA inventory_data_;
};
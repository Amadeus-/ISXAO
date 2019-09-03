#pragma once

class NewInventory
{
public:
	AOLIB_OBJECT DWORD GetInventory(std::vector<InventoryData*>&) const;
	AOLIB_OBJECT identity_t GetInventoryIdentity() const;
	AOLIB_OBJECT DWORD GetInventorySize() const;
	AOLIB_OBJECT new_inventory_t GetNewInventoryData() const;
private:
	new_inventory_t new_inventory_;
};
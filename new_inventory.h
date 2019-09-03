#pragma once

class NewInventory
{
public:
	AOLIB_OBJECT DWORD GetInventory(std::vector<InventoryData*>&) const;
	AOLIB_OBJECT identity_t GetInventoryIdentity() const;
	AOLIB_OBJECT DWORD GetInventorySize() const;
	AOLIB_OBJECT NEWINVENTORY GetNewInventoryData() const;
private:
	NEWINVENTORY new_inventory_;
};
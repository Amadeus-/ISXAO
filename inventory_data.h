#pragma once

class InventoryData
{
public:
	AOLIB_OBJECT identity_t GetDynelId() const;
	AOLIB_OBJECT inventory_data_t GetInventoryDataData() const;
	AOLIB_OBJECT DWORD GetItemCount() const;
	AOLIB_OBJECT rdb_identity_t GetRDBIdentity() const;
	AOLIB_OBJECT DWORD GetQualityLevel() const;
private:
	inventory_data_t inventory_data_;
};
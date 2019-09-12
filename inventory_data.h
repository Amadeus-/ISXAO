#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class inventory_data
{
public:
	AOLIB_OBJECT identity_t get_dynel_id() const;
	AOLIB_OBJECT inventory_data_t get_inventory_data_data() const;
	AOLIB_OBJECT DWORD get_item_count() const;
	AOLIB_OBJECT rdb_identity_t get_rdb_identity() const;
	AOLIB_OBJECT DWORD get_quality_level() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	inventory_data_t inventory_data_;
};

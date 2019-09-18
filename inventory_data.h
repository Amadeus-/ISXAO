#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class inventory_data
{
public:
	ao::identity_t get_dynel_id() const;
	ao::inventory_data_t get_inventory_data_data() const;
	DWORD get_item_count() const;
	ao::rdb_identity_t get_rdb_identity() const;
	DWORD get_quality_level() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::inventory_data_t inventory_data_;
};

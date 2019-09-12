#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class bank_entry
{
public:
	AOLIB_OBJECT bank_entry_t get_bank_entry_data() const;
	AOLIB_OBJECT DWORD get_inventory(vector<inventory_data*> &v) const;
	AOLIB_OBJECT identity_t get_inventory_identity() const;
	AOLIB_OBJECT DWORD get_inventory_size() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	bank_entry_t bank_entry_;
};

#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class bank_entry
{
public:
	ao::bank_entry_t get_bank_entry_data() const;
	DWORD get_inventory(std::vector<ao::inventory_data*> &v) const;
	ao::identity_t get_inventory_identity() const;
	DWORD get_inventory_size() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::bank_entry_t bank_entry_;
};

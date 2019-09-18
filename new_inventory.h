#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class new_inventory
{
public:
	DWORD get_inventory(std::vector<ao::inventory_data*>&) const;
	ao::identity_t get_inventory_identity() const;
	DWORD get_inventory_size() const;
	ao::new_inventory_t get_new_inventory_data() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::new_inventory_t new_inventory_;
};

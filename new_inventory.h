#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class new_inventory
{
public:
	AOLIB_OBJECT DWORD get_inventory(vector<inventory_data*>&) const;
	AOLIB_OBJECT identity_t get_inventory_identity() const;
	AOLIB_OBJECT DWORD get_inventory_size() const;
	AOLIB_OBJECT new_inventory_t get_new_inventory_data() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	new_inventory_t new_inventory_;
};

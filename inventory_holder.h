#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class inventory_holder
{
public:
	AOLIB_OBJECT DWORD build_ls_inventory(LSObjectCollection *p_map) const;
	AOLIB_OBJECT DWORD build_ls_inventory(LSIndex *p_index) const;
	AOLIB_OBJECT static DWORD get_armor_inventory(std::vector<inventory_data_t*> &v);
	AOLIB_OBJECT bank_entry* get_bank_inventory() const;
	AOLIB_OBJECT static DWORD get_character_inventory(std::vector<inventory_data_t*> &v);
	AOLIB_OBJECT static DWORD get_implant_inventory(std::vector<inventory_data_t*> &v);
	AOLIB_OBJECT DWORD get_inventory_count() const;
	AOLIB_OBJECT new_inventory* get_new_inventory() const;
	AOLIB_OBJECT inventory_holder_t get_inventory_holder_data() const;
	AOLIB_OBJECT p_identity_t get_inventory_holder_identity() const;
	AOLIB_OBJECT new_inventory* get_overflow_inventory() const;
	AOLIB_OBJECT DWORD get_inventory(std::map<identity_t, InventoryItem*>&) const;
	AOLIB_OBJECT InventoryItem* get_inventory_item(DWORD) const;
	AOLIB_OBJECT InventoryItem* get_inventory_item(PCSTR) const;
	AOLIB_OBJECT inventory_slot_t get_inventory_slot(DWORD) const;
	AOLIB_OBJECT inventory_slot_t get_inventory_slot(PCSTR) const;
	AOLIB_OBJECT static DWORD get_weapon_inventory(std::vector<inventory_data_t*> &v);
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	inventory_holder_t inventory_holder_;
};

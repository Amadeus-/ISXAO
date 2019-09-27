#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class inventory_holder
{
public:
	DWORD build_ls_inventory(LSObjectCollection *p_map) const;
	DWORD build_ls_inventory(LSIndex *p_index) const;
	static DWORD get_armor_inventory(std::vector<ao::inventory_data_t*> &v);
	ao::bank_entry* get_bank_inventory() const;
	static DWORD get_character_inventory(std::vector<ao::inventory_data_t*> &v);
	static DWORD get_implant_inventory(std::vector<ao::inventory_data_t*> &v);
	DWORD get_inventory_count() const;
	ao::new_inventory* get_new_inventory() const;
	ao::inventory_holder_t get_inventory_holder_data() const;
	ao::p_identity_t get_inventory_holder_identity() const;
	ao::new_inventory* get_overflow_inventory() const;
	DWORD get_inventory(std::map<ao::identity_t, ao::inventory_item*>&) const;
	ao::inventory_item* get_inventory_item(DWORD) const;
	ao::inventory_item* get_inventory_item(PCSTR) const;
	ao::inventory_slot_t get_inventory_slot(DWORD) const;
	ao::inventory_slot_t get_inventory_slot(PCSTR) const;
	static DWORD get_weapon_inventory(std::vector<ao::inventory_data_t*> &v);
	static bool get_inv_slot_identity(ao::ArmorSlot_e slot, ao::identity_t& id);
	static bool get_inv_slot_identity(ao::ImplantSlot_e slot, ao::identity_t& id);
	static bool get_inv_slot_identity(ao::WeaponSlot_e slot, ao::identity_t& id);
	static bool get_inv_slot_identity(DWORD slot, ao::identity_t& id);
	static PCSTR get_inv_slot_name(const ao::identity_t& slot);
	static bool get_inv_slot_identity(PCSTR slot_name, ao::identity_t &id);
	static ao::p_inventory_data_t get_inv_slot_data(ao::inventory_slot_t *slot);
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::inventory_holder_t inventory_holder_;
};

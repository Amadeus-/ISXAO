#pragma once
#include "game_object.h"

// ReSharper disable CppInconsistentNaming
class LSIndex;
class LSObjectCollection;
// ReSharper restore CppInconsistentNaming

namespace std
{
	template <typename _Tp, typename _Alloc>
	class list;
	template <typename _Key, typename _Tp, typename _Compare, typename _Alloc>
	class map;
	template <typename _Tp, typename _Alloc>
	class vector;
}

namespace ao
{
	class bank_entry;
	class inventory_item;
	class new_inventory;

	enum armor_slot_e : unsigned long;
	enum implant_slot_e : unsigned long;
	enum weapon_slot_e : unsigned long;

	struct ao_identity;
	struct ao_inventory_data;
	struct ao_inventory_holder;
	struct inventory_slot;

	typedef ao_identity identity_t, *p_identity_t;
	typedef ao_inventory_data inventory_data_t, *p_inventory_data_t;
	typedef ao_inventory_holder inventory_holder_t, *p_inventory_holder_t;
	typedef inventory_slot inventory_slot_t, *p_inventory_slot_t;

	class inventory_holder : public game_object<inventory_holder_t>
	{
	public:
		unsigned long build_ls_inventory(LSObjectCollection *p_map);
		unsigned long build_ls_inventory(LSIndex *p_index);
		static unsigned long get_armor_inventory(std::vector<inventory_data_t*> &v);
		bank_entry* get_bank_inventory();
		static unsigned long get_character_inventory(std::vector<inventory_data_t*> &v);
		static unsigned long get_implant_inventory(std::vector<inventory_data_t*> &v);
		unsigned long get_inventory_count();
		new_inventory* get_new_inventory();
		p_identity_t get_inventory_holder_identity();
		new_inventory* get_overflow_inventory();
		unsigned long get_inventory(std::map<identity_t, inventory_item*>&);
		inventory_item* get_inventory_item(unsigned long);
		inventory_item* get_inventory_item(const char*);
		inventory_slot_t get_inventory_slot(unsigned long);
		inventory_slot_t get_inventory_slot(const char*);
		static unsigned long get_weapon_inventory(std::vector<inventory_data_t*> &v);
		static bool get_inv_slot_identity(armor_slot_e slot, identity_t& id);
		static bool get_inv_slot_identity(implant_slot_e slot, identity_t& id);
		static bool get_inv_slot_identity(weapon_slot_e slot, identity_t& id);
		static bool get_inv_slot_identity(unsigned long slot, identity_t& id);
		static const char* get_inv_slot_name(const identity_t& slot);
		static bool get_inv_slot_identity(const char* slot_name, identity_t &id);
		static ao::p_inventory_data_t get_inv_slot_data(inventory_slot_t *slot);
	};
}

#pragma once

namespace ao
{
	class inventory_item;

	struct ao_identity;
	struct ao_inventory_data;

	typedef ao_identity identity_t, *p_identity_t;
	typedef ao_inventory_data inventory_data_t, *p_inventory_data_t;

	typedef struct inventory_slot  // NOLINT(hicpp-member-init, cppcoreguidelines-pro-type-member-init)
	{
		identity_t slot_id;
		inventory_item* p_item;

		const char* get_slot_name() const;
		ao::p_inventory_data_t get_inv_slot_data();
		double get_item_progress(unsigned long&, unsigned long&) const;
		bool is_item_locked() const;

		inventory_slot();
	} inventory_slot_t, *p_inventory_slot_t;
}
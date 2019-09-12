#pragma once

	typedef struct inventory_slot  // NOLINT(hicpp-member-init, cppcoreguidelines-pro-type-member-init)
	{
		identity_t slot_id;
		InventoryItem* p_item;

		PCSTR get_slot_name() const;
		p_inventory_data_t get_inv_slot_data();
		double get_item_progress(DWORD&, DWORD&) const;
		bool is_item_locked() const;

		inventory_slot()
		{
			this->slot_id = identity_t(0, 0);
			this->p_item = nullptr;
		}

	} inventory_slot_t, *p_inventory_slot_t;


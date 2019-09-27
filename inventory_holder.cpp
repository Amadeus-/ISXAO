#include "isxao_main.h"

namespace ao
{

	DWORD inventory_holder::build_ls_inventory(LSObjectCollection *p_map) const
	{
		const identity_t d(0, 0);
		const auto count = get_new_inventory()->get_inventory_size();
		for (DWORD i = 0; i < count; i++)
		{
			identity_t slot;
			get_inv_slot_identity(i, slot);
			auto p_item = P_ENGINE_CLIENT_ANARCHY->get_item_by_template(slot, d);
			if (p_item)
			{
				p_map->SetItem(get_inv_slot_name(slot), reinterpret_cast<LSOBJECTDATA&>(p_item));
			}
		}
		return p_map->GetContainerUsed();
	}

	DWORD inventory_holder::build_ls_inventory(LSIndex* p_index) const
	{
		const identity_t d(0, 0);
		const auto count = get_new_inventory()->get_inventory_size();
		for (DWORD i = 0; i < count; i++)
		{
			identity_t slot;
			get_inv_slot_identity(i, slot);
			const auto p_item = P_ENGINE_CLIENT_ANARCHY->get_item_by_template(slot, d);
			if (p_item)
			{
				inventory_slot_t s;
				s.slot_id = slot;
				s.p_item = reinterpret_cast<inventory_item*>(p_item);
				auto p_s = p_inventory_slot_t(pISInterface->GetTempBuffer(sizeof(inventory_slot_t), &s));
				p_index->AddItem(reinterpret_cast<LSOBJECTDATA&>(p_s));
			}
		}
		return p_index->GetContainerUsed();
	}

	DWORD inventory_holder::get_armor_inventory(std::vector<inventory_data_t*> &v)
	{
		for (auto i = 17; i < 32; i++)
		{
			auto p_inventory_data = P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_inventory_holder()->get_inventory_holder_data().p_regular_inventory->p_inventory_data[i];
			if (p_inventory_data)
				v.push_back(p_inventory_data);
		}
		return v.size();
	}
	
	bank_entry* inventory_holder::get_bank_inventory() const
	{
		return reinterpret_cast<bank_entry*>(get_inventory_holder_data().p_bank_entry);
	}

	DWORD inventory_holder::get_character_inventory(std::vector<inventory_data_t*> &v)
	{
		for (auto i = 64; i < 94; i++)
		{
			auto p_inventory_data = P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_inventory_holder()->get_inventory_holder_data().p_regular_inventory->p_inventory_data[i];
			if (p_inventory_data)
				v.push_back(p_inventory_data);
		}
		return v.size();
	}

	DWORD inventory_holder::get_implant_inventory(std::vector<inventory_data_t*> &v)
	{
		for (auto i = 33; i < 46; i++)
		{
			auto p_inventory_data = P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_inventory_holder()->get_inventory_holder_data().p_regular_inventory->p_inventory_data[i];
			if (p_inventory_data)
				v.push_back(p_inventory_data);
		}
		return v.size();
	}

	DWORD inventory_holder::get_inventory_count() const
	{
		std::map<identity_t, inventory_item*> m;
		return get_inventory(m);
	}
	
	new_inventory* inventory_holder::get_new_inventory() const
	{
		return reinterpret_cast<new_inventory*>(get_inventory_holder_data().p_regular_inventory);
	}

	inventory_holder_t inventory_holder::get_inventory_holder_data() const
	{
		return inventory_holder_;
	}

	p_identity_t inventory_holder::get_inventory_holder_identity() const
	{
		return get_inventory_holder_data().p_client_identity;
	}

	new_inventory* inventory_holder::get_overflow_inventory() const
	{
		return reinterpret_cast<new_inventory*>(get_inventory_holder_data().p_overflow_inventory);
	}

	inventory_item* inventory_holder::get_inventory_item(DWORD index) const
	{
		std::map<identity_t, inventory_item*> m;
		if(this->get_inventory(m))
		{
			if (index < 1 || index > m.size())
				return nullptr;
			for (auto it = m.begin(); it != m.end(); ++it)  // NOLINT(modernize-loop-convert)
			{
				index -= 1;
				if (index == 0)
					return it->second;
			}
		}		
		return nullptr;
	}

	inventory_item* inventory_holder::get_inventory_item(const PCSTR sz_arg) const
	{
		identity_t id(0, 0);
		const identity_t d(0,0);
		char sz_name[MAX_VARSTRING] = { 0 };
		char sz_search_name[MAX_VARSTRING];
		strcpy_s(sz_search_name, MAX_VARSTRING, sz_arg);
		_strlwr_s(sz_search_name);
		if (!strcmp(sz_search_name, "ws_hud1"))
			get_inv_slot_identity(WS_HUD_1, id);
		else if (!strcmp(sz_search_name, "ws_hud2"))
			get_inv_slot_identity(WS_HUD_2, id);
		else if (!strcmp(sz_search_name, "ws_hud3"))
			get_inv_slot_identity(WS_HUD_3, id);
		else if (!strcmp(sz_search_name, "ws_util1"))
			get_inv_slot_identity(WS_UTIL_1, id);
		else if (!strcmp(sz_search_name, "ws_util2"))
			get_inv_slot_identity(WS_UTIL_2, id);
		else if (!strcmp(sz_search_name, "ws_util3"))
			get_inv_slot_identity(WS_UTIL_3, id);
		else if (!strcmp(sz_search_name, "ws_rhand"))
			get_inv_slot_identity(WS_R_HAND, id);
		else if (!strcmp(sz_search_name, "ws_belt"))
			get_inv_slot_identity(WS_BELT, id);
		else if (!strcmp(sz_search_name, "ws_lhand"))
			get_inv_slot_identity(WS_L_HAND, id);
		else if (!strcmp(sz_search_name, "ws_ncu1"))
			get_inv_slot_identity(WS_NCU_1, id);
		else if (!strcmp(sz_search_name, "ws_ncu2"))
			get_inv_slot_identity(WS_NCU_2, id);
		else if (!strcmp(sz_search_name, "ws_ncu3"))
			get_inv_slot_identity(WS_NCU_3, id);
		else if (!strcmp(sz_search_name, "ws_ncu4"))
			get_inv_slot_identity(WS_NCU_4, id);
		else if (!strcmp(sz_search_name, "ws_ncu5"))
			get_inv_slot_identity(WS_NCU_5, id);
		else if (!strcmp(sz_search_name, "ws_ncu6"))
			get_inv_slot_identity(WS_NCU_6, id);
		else if (!strcmp(sz_search_name, "as_neck"))
			get_inv_slot_identity(AS_NECK, id);
		else if (!strcmp(sz_search_name, "as_head"))
			get_inv_slot_identity(AS_HEAD, id);
		else if (!strcmp(sz_search_name, "as_back"))
			get_inv_slot_identity(AS_BACK, id);
		else if (!strcmp(sz_search_name, "as_rshoulder"))
			get_inv_slot_identity(AS_R_SHOULDER, id);
		else if (!strcmp(sz_search_name, "as_chest"))
			get_inv_slot_identity(AS_CHEST, id);
		else if (!strcmp(sz_search_name, "as_lshoulder"))
			get_inv_slot_identity(AS_L_SHOULDER, id);
		else if (!strcmp(sz_search_name, "as_rarm"))
			get_inv_slot_identity(AS_R_ARM, id);
		else if (!strcmp(sz_search_name, "as_hands"))
			get_inv_slot_identity(AS_HANDS, id);
		else if (!strcmp(sz_search_name, "as_larm"))
			get_inv_slot_identity(AS_L_ARM, id);
		else if (!strcmp(sz_search_name, "as_rwrist"))
			get_inv_slot_identity(AS_R_WRIST, id);
		else if (!strcmp(sz_search_name, "as_legs"))
			get_inv_slot_identity(AS_LEGS, id);
		else if (!strcmp(sz_search_name, "as_lwrist"))
			get_inv_slot_identity(AS_L_WRIST, id);
		else if (!strcmp(sz_search_name, "as_rfinger"))
			get_inv_slot_identity(AS_R_FINGER, id);
		else if (!strcmp(sz_search_name, "as_feet"))
			get_inv_slot_identity(AS_FEET, id);
		else if (!strcmp(sz_search_name, "as_lfinger"))
			get_inv_slot_identity(AS_L_FINGER, id);
		else if (!strcmp(sz_search_name, "is_eyes"))
			get_inv_slot_identity(IS_EYES, id);
		else if (!strcmp(sz_search_name, "is_head"))
			get_inv_slot_identity(IS_HEAD, id);
		else if (!strcmp(sz_search_name, "is_ears"))
			get_inv_slot_identity(IS_EARS, id);
		else if (!strcmp(sz_search_name, "is_rarm"))
			get_inv_slot_identity(IS_R_ARM, id);
		else if (!strcmp(sz_search_name, "is_chest"))
			get_inv_slot_identity(IS_CHEST, id);
		else if (!strcmp(sz_search_name, "is_larm"))
			get_inv_slot_identity(IS_L_ARM, id);
		else if (!strcmp(sz_search_name, "is_rwrist"))
			get_inv_slot_identity(IS_R_WRIST, id);
		else if (!strcmp(sz_search_name, "is_waist"))
			get_inv_slot_identity(IS_WAIST, id);
		else if (!strcmp(sz_search_name, "is_lwrist"))
			get_inv_slot_identity(IS_L_WRIST, id);
		else if (!strcmp(sz_search_name, "is_rhand"))
			get_inv_slot_identity(IS_R_HAND, id);
		else if (!strcmp(sz_search_name, "is_legs"))
			get_inv_slot_identity(IS_LEGS, id);
		else if (!strcmp(sz_search_name, "is_lhand"))
			get_inv_slot_identity(IS_L_HAND, id);
		else if (!strcmp(sz_search_name, "is_feet"))
			get_inv_slot_identity(IS_FEET, id);
		if (id.type != 0)
			return reinterpret_cast<inventory_item*>(P_ENGINE_CLIENT_ANARCHY->get_item_by_template(id, d));
		std::map<identity_t, inventory_item*> m;
		if(this->get_inventory(m))
		{
			for (auto it = m.begin(); it != m.end(); ++it)  // NOLINT(modernize-loop-convert)
			{
				if (it->second)
				{
					strcpy_s(sz_name, MAX_VARSTRING, it->second->get_name());
					_strlwr_s(sz_name);
					if (strstr(sz_name, sz_search_name))
						return reinterpret_cast<inventory_item*>(it->second);
				}
			}
		}		
		return nullptr;
	}

	inventory_slot_t inventory_holder::get_inventory_slot(DWORD index) const
	{
		inventory_slot_t s;
		std::map<identity_t, inventory_item*> m;
		if (this->get_inventory(m))
		{
			if (index < 1 || index > m.size())
				return s;
			for (auto it = m.begin(); it != m.end(); ++it)  // NOLINT(modernize-loop-convert)
			{
				index -= 1;
				if (index == 0)
				{
					s.slot_id = it->first;
					s.p_item = it->second;
					return s;
				}
			}
		}		
		return s;
	}

	inventory_slot_t inventory_holder::get_inventory_slot(const PCSTR sz_arg) const
	{
		inventory_slot_t s;
		identity_t id(0, 0);
		const identity_t d(0, 0);
		char sz_name[MAX_VARSTRING] = { 0 };
		char sz_search_name[MAX_VARSTRING];
		strcpy_s(sz_search_name, MAX_VARSTRING, sz_arg);
		_strlwr_s(sz_search_name);
		if (!strcmp(sz_search_name, "ws_hud1"))
			get_inv_slot_identity(ao::WS_HUD_1, id);
		else if (!strcmp(sz_search_name, "ws_hud2"))
			get_inv_slot_identity(ao::WS_HUD_2, id);
		else if (!strcmp(sz_search_name, "ws_hud3"))
			get_inv_slot_identity(ao::WS_HUD_3, id);
		else if (!strcmp(sz_search_name, "ws_util1"))
			get_inv_slot_identity(ao::WS_UTIL_1, id);
		else if (!strcmp(sz_search_name, "ws_util2"))
			get_inv_slot_identity(ao::WS_UTIL_2, id);
		else if (!strcmp(sz_search_name, "ws_util3"))
			get_inv_slot_identity(ao::WS_UTIL_3, id);
		else if (!strcmp(sz_search_name, "ws_rhand"))
			get_inv_slot_identity(ao::WS_R_HAND, id);
		else if (!strcmp(sz_search_name, "ws_belt"))
			get_inv_slot_identity(ao::WS_BELT, id);
		else if (!strcmp(sz_search_name, "ws_lhand"))
			get_inv_slot_identity(ao::WS_L_HAND, id);
		else if (!strcmp(sz_search_name, "ws_ncu1"))
			get_inv_slot_identity(ao::WS_NCU_1, id);
		else if (!strcmp(sz_search_name, "ws_ncu2"))
			get_inv_slot_identity(ao::WS_NCU_2, id);
		else if (!strcmp(sz_search_name, "ws_ncu3"))
			get_inv_slot_identity(ao::WS_NCU_3, id);
		else if (!strcmp(sz_search_name, "ws_ncu4"))
			get_inv_slot_identity(ao::WS_NCU_4, id);
		else if (!strcmp(sz_search_name, "ws_ncu5"))
			get_inv_slot_identity(ao::WS_NCU_5, id);
		else if (!strcmp(sz_search_name, "ws_ncu6"))
			get_inv_slot_identity(ao::WS_NCU_6, id);
		else if (!strcmp(sz_search_name, "as_neck"))
			get_inv_slot_identity(ao::AS_NECK, id);
		else if (!strcmp(sz_search_name, "as_head"))
			get_inv_slot_identity(ao::AS_HEAD, id);
		else if (!strcmp(sz_search_name, "as_back"))
			get_inv_slot_identity(ao::AS_BACK, id);
		else if (!strcmp(sz_search_name, "as_rshoulder"))
			get_inv_slot_identity(ao::AS_R_SHOULDER, id);
		else if (!strcmp(sz_search_name, "as_chest"))
			get_inv_slot_identity(ao::AS_CHEST, id);
		else if (!strcmp(sz_search_name, "as_lshoulder"))
			get_inv_slot_identity(ao::AS_L_SHOULDER, id);
		else if (!strcmp(sz_search_name, "as_rarm"))
			get_inv_slot_identity(ao::AS_R_ARM, id);
		else if (!strcmp(sz_search_name, "as_hands"))
			get_inv_slot_identity(ao::AS_HANDS, id);
		else if (!strcmp(sz_search_name, "as_larm"))
			get_inv_slot_identity(ao::AS_L_ARM, id);
		else if (!strcmp(sz_search_name, "as_rwrist"))
			get_inv_slot_identity(ao::AS_R_WRIST, id);
		else if (!strcmp(sz_search_name, "as_legs"))
			get_inv_slot_identity(ao::AS_LEGS, id);
		else if (!strcmp(sz_search_name, "as_lwrist"))
			get_inv_slot_identity(ao::AS_L_WRIST, id);
		else if (!strcmp(sz_search_name, "as_rfinger"))
			get_inv_slot_identity(ao::AS_R_FINGER, id);
		else if (!strcmp(sz_search_name, "as_feet"))
			get_inv_slot_identity(ao::AS_FEET, id);
		else if (!strcmp(sz_search_name, "as_lfinger"))
			get_inv_slot_identity(ao::AS_L_FINGER, id);
		else if (!strcmp(sz_search_name, "is_eyes"))
			get_inv_slot_identity(ao::IS_EYES, id);
		else if (!strcmp(sz_search_name, "is_head"))
			get_inv_slot_identity(ao::IS_HEAD, id);
		else if (!strcmp(sz_search_name, "is_ears"))
			get_inv_slot_identity(ao::IS_EARS, id);
		else if (!strcmp(sz_search_name, "is_rarm"))
			get_inv_slot_identity(ao::IS_R_ARM, id);
		else if (!strcmp(sz_search_name, "is_chest"))
			get_inv_slot_identity(ao::IS_CHEST, id);
		else if (!strcmp(sz_search_name, "is_larm"))
			get_inv_slot_identity(ao::IS_L_ARM, id);
		else if (!strcmp(sz_search_name, "is_rwrist"))
			get_inv_slot_identity(ao::IS_R_WRIST, id);
		else if (!strcmp(sz_search_name, "is_waist"))
			get_inv_slot_identity(ao::IS_WAIST, id);
		else if (!strcmp(sz_search_name, "is_lwrist"))
			get_inv_slot_identity(ao::IS_L_WRIST, id);
		else if (!strcmp(sz_search_name, "is_rhand"))
			get_inv_slot_identity(ao::IS_R_HAND, id);
		else if (!strcmp(sz_search_name, "is_legs"))
			get_inv_slot_identity(ao::IS_LEGS, id);
		else if (!strcmp(sz_search_name, "is_lhand"))
			get_inv_slot_identity(ao::IS_L_HAND, id);
		else if (!strcmp(sz_search_name, "is_feet"))
			get_inv_slot_identity(ao::IS_FEET, id);
		if (id.type != 0)
		{
			s.slot_id = id;
			s.p_item = reinterpret_cast<inventory_item*>(P_ENGINE_CLIENT_ANARCHY->get_item_by_template(id, d));
		}
		std::map<identity_t, inventory_item*> m;
		if (this->get_inventory(m))
		{
			for (auto it = m.begin(); it != m.end(); ++it)  // NOLINT(modernize-loop-convert)
			{
				if (it->second)
				{
					strcpy_s(sz_name, MAX_VARSTRING, it->second->get_name());
					_strlwr_s(sz_name);
					if (strstr(sz_name, sz_search_name))
					{
						s.slot_id = it->first;
						s.p_item = reinterpret_cast<inventory_item*>(it->second);
					}
				}
			}
		}		
		return s;
	}

	DWORD inventory_holder::get_inventory(std::map<identity_t, inventory_item*>& m) const
	{
		const identity_t d(0, 0);
		const auto count = get_new_inventory()->get_inventory_size();
		for (DWORD i = 0; i < count; i++)
		{
			identity_t id;
			get_inv_slot_identity(i, id);
			const auto p_item = P_ENGINE_CLIENT_ANARCHY->get_item_by_template(id, d);
			if (p_item)
				m.insert_or_assign(id, reinterpret_cast<inventory_item*>(P_ENGINE_CLIENT_ANARCHY->get_item_by_template(id, d)));
		}
		return m.size();
	}

	DWORD inventory_holder::get_weapon_inventory(std::vector<inventory_data_t*>& v)
	{
		for (auto i = 1; i < 16; i++)
		{
			auto p_inventory_data = P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_inventory_holder()->get_inventory_holder_data().p_regular_inventory->p_inventory_data[i];
			if (p_inventory_data)
				v.push_back(p_inventory_data);
		}
		return v.size();
	}

	bool inventory_holder::get_inv_slot_identity(ao::ArmorSlot_e slot, ao::identity_t& id)
	{
		id.type = 102;
		switch (slot)
		{
		case ao::AS_NECK:
		case ao::AS_HEAD:
		case ao::AS_BACK:
		case ao::AS_R_SHOULDER:
		case ao::AS_CHEST:
		case ao::AS_L_SHOULDER:
		case ao::AS_R_ARM:
		case ao::AS_HANDS:
		case ao::AS_L_ARM:
		case ao::AS_R_WRIST:
		case ao::AS_LEGS:
		case ao::AS_L_WRIST:
		case ao::AS_R_FINGER:
		case ao::AS_FEET:
		case ao::AS_L_FINGER:
			id.id = DWORD(slot) + 16;
			break;
		default:
			return false;;
		}
		return true;
	}

	bool inventory_holder::get_inv_slot_identity(ao::ImplantSlot_e slot, ao::identity_t& id)
	{
		id.type = 103;
		switch (slot)
		{
		case ao::IS_EYES:
		case ao::IS_HEAD:
		case ao::IS_EARS:
		case ao::IS_R_ARM:
		case ao::IS_CHEST:
		case ao::IS_L_ARM:
		case ao::IS_R_WRIST:
		case ao::IS_WAIST:
		case ao::IS_L_WRIST:
		case ao::IS_R_HAND:
		case ao::IS_LEGS:
		case ao::IS_L_HAND:
		case ao::IS_FEET:
			id.id = DWORD(slot) + 32;
			break;
		default:
			return false;
		}
		return true;
	}

	bool inventory_holder::get_inv_slot_identity(ao::WeaponSlot_e slot, ao::identity_t& id)
	{
		id.type = 101;
		switch (slot)
		{
		case ao::WS_HUD_1:
		case ao::WS_HUD_3:
		case ao::WS_UTIL_1:
		case ao::WS_UTIL_2:
		case ao::WS_UTIL_3:
		case ao::WS_R_HAND:
		case ao::WS_BELT:
		case ao::WS_L_HAND:
		case ao::WS_NCU_1:
		case ao::WS_NCU_2:
		case ao::WS_NCU_3:
		case ao::WS_NCU_4:
		case ao::WS_NCU_5:
		case ao::WS_NCU_6:
		case ao::WS_HUD_2:
			id.id = DWORD(slot);
			break;
		default:
			return false;
		}
		return true;
	}

	bool inventory_holder::get_inv_slot_identity(DWORD slot, ao::identity_t& id)
	{
		id.id = slot;
		switch (slot)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			id.type = 101;
			break;
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 22:
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
			id.type = 102;
			break;
		case 33:
		case 34:
		case 35:
		case 36:
		case 37:
		case 38:
		case 39:
		case 40:
		case 41:
		case 42:
		case 43:
		case 44:
		case 45:
			id.type = 103;
			break;
		case 64:
		case 65:
		case 66:
		case 67:
		case 68:
		case 69:
		case 70:
		case 71:
		case 72:
		case 73:
		case 74:
		case 75:
		case 76:
		case 77:
		case 78:
		case 79:
		case 80:
		case 81:
		case 82:
		case 83:
		case 84:
		case 85:
		case 86:
		case 87:
		case 88:
		case 89:
		case 90:
		case 91:
		case 92:
		case 93:
		case 94:
			id.type = 104;
			break;
		default:
			return false;
		}
		return true;
	}

	PCSTR inventory_holder::get_inv_slot_name(const ao::identity_t& slot)
	{
		switch (slot.type)
		{
		case 101:
		{
			switch (slot.id)
			{
			case 1:
				return "WS_HUD1";
			case 2:
				return "WS_HUD3";
			case 3:
				return "WS_UTIL1";
			case 4:
				return "WS_UTIL2";
			case 5:
				return "WS_UTIL3";
			case 6:
				return "WS_RHAND";
			case 7:
				return "WS_BELT";
			case 8:
				return "WS_LHAND";
			case 9:
				return "WS_NCU1";
			case 10:
				return "WS_NCU2";
			case 11:
				return "WS_NCU3";
			case 12:
				return "WS_NCU4";
			case 13:
				return "WS_NCU5";
			case 14:
				return "WS_NCU6";
			case 15:
				return "WS_HUD2";
			default:
				return "Unknown";
			}
		}
		case 102:
		{
			switch (slot.id - 16)
			{
			case 1:
				return "AS_NECK";
			case 2:
				return "AS_HEAD";
			case 3:
				return "AS_BACK";
			case 4:
				return "AS_RSHOULDER";
			case 5:
				return "AS_CHEST";
			case 6:
				return "AS_LSHOULDER";
			case 7:
				return "AS_RARM";
			case 8:
				return "AS_HANDS";
			case 9:
				return "AS_LARM";
			case 10:
				return "AS_RWRIST";
			case 11:
				return "AS_LEGS";
			case 12:
				return "AS_LWRIST";
			case 13:
				return "AS_RFINGER";
			case 14:
				return "AS_FEET";
			case 15:
				return "AS_LFINGER";
			default:
				return "Unknown";
			}
		}
		case 103:
		{
			switch (slot.id - 32)
			{
			case 1:
				return "IS_EYES";
			case 2:
				return "IS_HEAD";
			case 3:
				return "IS_EARS";
			case 4:
				return "IS_RARM";
			case 5:
				return "IS_CHEST";
			case 6:
				return "IS_LARM";
			case 7:
				return "IS_RWRIST";
			case 8:
				return "IS_WAIST";
			case 9:
				return "IS_LWRIST";
			case 10:
				return "IS_RHAND";
			case 11:
				return "IS_LEGS";
			case 12:
				return "IS_LHAND";
			case 13:
				return "IS_FEET";
			default:
				return "Unknown";
			}
		}
		case 104:
		{
			switch (slot.id - 63)
			{
			case 1:
				return "GI_64";
			case 2:
				return "GI_65";
			case 3:
				return "GI_66";
			case 4:
				return "GI_67";
			case 5:
				return "GI_68";
			case 6:
				return "GI_69";
			case 7:
				return "GI_70";
			case 8:
				return "GI_71";
			case 9:
				return "GI_72";
			case 10:
				return "GI_73";
			case 11:
				return "GI_74";
			case 12:
				return "GI_75";
			case 13:
				return "GI_76";
			case 14:
				return "GI_77";
			case 15:
				return "GI_78";
			case 16:
				return "GI_79";
			case 17:
				return "GI_80";
			case 18:
				return "GI_81";
			case 19:
				return "GI_82";
			case 20:
				return "GI_83";
			case 21:
				return "GI_84";
			case 22:
				return "GI_85";
			case 23:
				return "GI_86";
			case 24:
				return "GI_87";
			case 25:
				return "GI_88";
			case 26:
				return "GI_89";
			case 27:
				return "GI_90";
			case 28:
				return "GI_91";
			case 29:
				return "GI_92";
			case 30:
				return "GI_93";
			default:
				return "Unknown";
			}
		}
		default:
			break;
		}
		return "Unknown";
	}

	bool inventory_holder::get_inv_slot_identity(PCSTR slot_name, ao::identity_t &id)
	{
		char search_name[MAX_VARSTRING];
		strcpy_s(search_name, MAX_VARSTRING, slot_name);
		_strlwr_s(search_name);
		if (!strcmp(search_name, "ws_hud1"))
			get_inv_slot_identity(ao::WS_HUD_1, id);
		else if (!strcmp(search_name, "ws_hud2"))
			get_inv_slot_identity(ao::WS_HUD_2, id);
		else if (!strcmp(search_name, "ws_hud3"))
			get_inv_slot_identity(ao::WS_HUD_3, id);
		else if (!strcmp(search_name, "ws_util1"))
			get_inv_slot_identity(ao::WS_UTIL_1, id);
		else if (!strcmp(search_name, "ws_util2"))
			get_inv_slot_identity(ao::WS_UTIL_2, id);
		else if (!strcmp(search_name, "ws_util3"))
			get_inv_slot_identity(ao::WS_UTIL_3, id);
		else if (!strcmp(search_name, "ws_rhand"))
			get_inv_slot_identity(ao::WS_R_HAND, id);
		else if (!strcmp(search_name, "ws_belt"))
			get_inv_slot_identity(ao::WS_BELT, id);
		else if (!strcmp(search_name, "ws_lhand"))
			get_inv_slot_identity(ao::WS_L_HAND, id);
		else if (!strcmp(search_name, "ws_ncu1"))
			get_inv_slot_identity(ao::WS_NCU_1, id);
		else if (!strcmp(search_name, "ws_ncu2"))
			get_inv_slot_identity(ao::WS_NCU_2, id);
		else if (!strcmp(search_name, "ws_ncu3"))
			get_inv_slot_identity(ao::WS_NCU_3, id);
		else if (!strcmp(search_name, "ws_ncu4"))
			get_inv_slot_identity(ao::WS_NCU_4, id);
		else if (!strcmp(search_name, "ws_ncu5"))
			get_inv_slot_identity(ao::WS_NCU_5, id);
		else if (!strcmp(search_name, "ws_ncu6"))
			get_inv_slot_identity(ao::WS_NCU_6, id);
		else if (!strcmp(search_name, "as_neck"))
			get_inv_slot_identity(ao::AS_NECK, id);
		else if (!strcmp(search_name, "as_head"))
			get_inv_slot_identity(ao::AS_HEAD, id);
		else if (!strcmp(search_name, "as_back"))
			get_inv_slot_identity(ao::AS_BACK, id);
		else if (!strcmp(search_name, "as_rshoulder"))
			get_inv_slot_identity(ao::AS_R_SHOULDER, id);
		else if (!strcmp(search_name, "as_chest"))
			get_inv_slot_identity(ao::AS_CHEST, id);
		else if (!strcmp(search_name, "as_lshoulder"))
			get_inv_slot_identity(ao::AS_L_SHOULDER, id);
		else if (!strcmp(search_name, "as_rarm"))
			get_inv_slot_identity(ao::AS_R_ARM, id);
		else if (!strcmp(search_name, "as_hands"))
			get_inv_slot_identity(ao::AS_HANDS, id);
		else if (!strcmp(search_name, "as_larm"))
			get_inv_slot_identity(ao::AS_L_ARM, id);
		else if (!strcmp(search_name, "as_rwrist"))
			get_inv_slot_identity(ao::AS_R_WRIST, id);
		else if (!strcmp(search_name, "as_legs"))
			get_inv_slot_identity(ao::AS_LEGS, id);
		else if (!strcmp(search_name, "as_lwrist"))
			get_inv_slot_identity(ao::AS_L_WRIST, id);
		else if (!strcmp(search_name, "as_rfinger"))
			get_inv_slot_identity(ao::AS_R_FINGER, id);
		else if (!strcmp(search_name, "as_feet"))
			get_inv_slot_identity(ao::AS_FEET, id);
		else if (!strcmp(search_name, "as_lfinger"))
			get_inv_slot_identity(ao::AS_L_FINGER, id);
		else if (!strcmp(search_name, "is_eyes"))
			get_inv_slot_identity(ao::IS_EYES, id);
		else if (!strcmp(search_name, "is_head"))
			get_inv_slot_identity(ao::IS_HEAD, id);
		else if (!strcmp(search_name, "is_ears"))
			get_inv_slot_identity(ao::IS_EARS, id);
		else if (!strcmp(search_name, "is_rarm"))
			get_inv_slot_identity(ao::IS_R_ARM, id);
		else if (!strcmp(search_name, "is_chest"))
			get_inv_slot_identity(ao::IS_CHEST, id);
		else if (!strcmp(search_name, "is_larm"))
			get_inv_slot_identity(ao::IS_L_ARM, id);
		else if (!strcmp(search_name, "is_rwrist"))
			get_inv_slot_identity(ao::IS_R_WRIST, id);
		else if (!strcmp(search_name, "is_waist"))
			get_inv_slot_identity(ao::IS_WAIST, id);
		else if (!strcmp(search_name, "is_lwrist"))
			get_inv_slot_identity(ao::IS_L_WRIST, id);
		else if (!strcmp(search_name, "is_rhand"))
			get_inv_slot_identity(ao::IS_R_HAND, id);
		else if (!strcmp(search_name, "is_legs"))
			get_inv_slot_identity(ao::IS_LEGS, id);
		else if (!strcmp(search_name, "is_lhand"))
			get_inv_slot_identity(ao::IS_L_HAND, id);
		else if (!strcmp(search_name, "is_feet"))
			get_inv_slot_identity(ao::IS_FEET, id);
		else if (!strcmp(search_name, "gi_64"))
			get_inv_slot_identity(64, id);
		else if (!strcmp(search_name, "gi_65"))
			get_inv_slot_identity(65, id);
		else if (!strcmp(search_name, "gi_66"))
			get_inv_slot_identity(66, id);
		else if (!strcmp(search_name, "gi_67"))
			get_inv_slot_identity(67, id);
		else if (!strcmp(search_name, "gi_68"))
			get_inv_slot_identity(68, id);
		else if (!strcmp(search_name, "gi_69"))
			get_inv_slot_identity(69, id);
		else if (!strcmp(search_name, "gi_70"))
			get_inv_slot_identity(70, id);
		else if (!strcmp(search_name, "gi_71"))
			get_inv_slot_identity(71, id);
		else if (!strcmp(search_name, "gi_72"))
			get_inv_slot_identity(72, id);
		else if (!strcmp(search_name, "gi_73"))
			get_inv_slot_identity(73, id);
		else if (!strcmp(search_name, "gi_74"))
			get_inv_slot_identity(74, id);
		else if (!strcmp(search_name, "gi_75"))
			get_inv_slot_identity(75, id);
		else if (!strcmp(search_name, "gi_76"))
			get_inv_slot_identity(76, id);
		else if (!strcmp(search_name, "gi_77"))
			get_inv_slot_identity(77, id);
		else if (!strcmp(search_name, "gi_78"))
			get_inv_slot_identity(78, id);
		else if (!strcmp(search_name, "gi_79"))
			get_inv_slot_identity(79, id);
		else if (!strcmp(search_name, "gi_80"))
			get_inv_slot_identity(80, id);
		else if (!strcmp(search_name, "gi_81"))
			get_inv_slot_identity(81, id);
		else if (!strcmp(search_name, "gi_82"))
			get_inv_slot_identity(82, id);
		else if (!strcmp(search_name, "gi_83"))
			get_inv_slot_identity(83, id);
		else if (!strcmp(search_name, "gi_84"))
			get_inv_slot_identity(84, id);
		else if (!strcmp(search_name, "gi_85"))
			get_inv_slot_identity(85, id);
		else if (!strcmp(search_name, "gi_86"))
			get_inv_slot_identity(86, id);
		else if (!strcmp(search_name, "gi_87"))
			get_inv_slot_identity(87, id);
		else if (!strcmp(search_name, "gi_88"))
			get_inv_slot_identity(88, id);
		else if (!strcmp(search_name, "gi_89"))
			get_inv_slot_identity(89, id);
		else if (!strcmp(search_name, "gi_90"))
			get_inv_slot_identity(90, id);
		else if (!strcmp(search_name, "gi_91"))
			get_inv_slot_identity(91, id);
		else if (!strcmp(search_name, "gi_92"))
			get_inv_slot_identity(92, id);
		else if (!strcmp(search_name, "gi_93"))
			get_inv_slot_identity(93, id);
		else if (!strcmp(search_name, "gi_94"))
			get_inv_slot_identity(94, id);
		return id.type != 0;
	}

	ao::p_inventory_data_t inventory_holder::get_inv_slot_data(ao::inventory_slot_t *slot)
	{
		return P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_inventory_holder()->get_inventory_holder_data().p_regular_inventory->p_inventory_data[slot->slot_id.id];
	}
}
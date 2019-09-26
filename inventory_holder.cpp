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
			isxao::GetInvSlotIdentity(i, slot);
			auto p_item = P_ENGINE_CLIENT_ANARCHY->get_item_by_template(slot, d);
			if (p_item)
			{
				p_map->SetItem(isxao::GetInvSlotName(slot), reinterpret_cast<LSOBJECTDATA&>(p_item));
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
			isxao::GetInvSlotIdentity(i, slot);
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
		get_inventory(m);
		if (index < 1 || index > m.size())
			return nullptr;
		for (auto it = m.begin(); it != m.end(); ++it)  // NOLINT(modernize-loop-convert)
		{
			index -= 1;
			if (index == 0)
				return it->second;
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
			isxao::GetInvSlotIdentity(WS_HUD_1, id);
		else if (!strcmp(sz_search_name, "ws_hud2"))
			isxao::GetInvSlotIdentity(WS_HUD_2, id);
		else if (!strcmp(sz_search_name, "ws_hud3"))
			isxao::GetInvSlotIdentity(WS_HUD_3, id);
		else if (!strcmp(sz_search_name, "ws_util1"))
			isxao::GetInvSlotIdentity(WS_UTIL_1, id);
		else if (!strcmp(sz_search_name, "ws_util2"))
			isxao::GetInvSlotIdentity(WS_UTIL_2, id);
		else if (!strcmp(sz_search_name, "ws_util3"))
			isxao::GetInvSlotIdentity(WS_UTIL_3, id);
		else if (!strcmp(sz_search_name, "ws_rhand"))
			isxao::GetInvSlotIdentity(WS_R_HAND, id);
		else if (!strcmp(sz_search_name, "ws_belt"))
			isxao::GetInvSlotIdentity(WS_BELT, id);
		else if (!strcmp(sz_search_name, "ws_lhand"))
			isxao::GetInvSlotIdentity(WS_L_HAND, id);
		else if (!strcmp(sz_search_name, "ws_ncu1"))
			isxao::GetInvSlotIdentity(WS_NCU_1, id);
		else if (!strcmp(sz_search_name, "ws_ncu2"))
			isxao::GetInvSlotIdentity(WS_NCU_2, id);
		else if (!strcmp(sz_search_name, "ws_ncu3"))
			isxao::GetInvSlotIdentity(WS_NCU_3, id);
		else if (!strcmp(sz_search_name, "ws_ncu4"))
			isxao::GetInvSlotIdentity(WS_NCU_4, id);
		else if (!strcmp(sz_search_name, "ws_ncu5"))
			isxao::GetInvSlotIdentity(WS_NCU_5, id);
		else if (!strcmp(sz_search_name, "ws_ncu6"))
			isxao::GetInvSlotIdentity(WS_NCU_6, id);
		else if (!strcmp(sz_search_name, "as_neck"))
			isxao::GetInvSlotIdentity(AS_NECK, id);
		else if (!strcmp(sz_search_name, "as_head"))
			isxao::GetInvSlotIdentity(AS_HEAD, id);
		else if (!strcmp(sz_search_name, "as_back"))
			isxao::GetInvSlotIdentity(AS_BACK, id);
		else if (!strcmp(sz_search_name, "as_rshoulder"))
			isxao::GetInvSlotIdentity(AS_R_SHOULDER, id);
		else if (!strcmp(sz_search_name, "as_chest"))
			isxao::GetInvSlotIdentity(AS_CHEST, id);
		else if (!strcmp(sz_search_name, "as_lshoulder"))
			isxao::GetInvSlotIdentity(AS_L_SHOULDER, id);
		else if (!strcmp(sz_search_name, "as_rarm"))
			isxao::GetInvSlotIdentity(AS_R_ARM, id);
		else if (!strcmp(sz_search_name, "as_hands"))
			isxao::GetInvSlotIdentity(AS_HANDS, id);
		else if (!strcmp(sz_search_name, "as_larm"))
			isxao::GetInvSlotIdentity(AS_L_ARM, id);
		else if (!strcmp(sz_search_name, "as_rwrist"))
			isxao::GetInvSlotIdentity(AS_R_WRIST, id);
		else if (!strcmp(sz_search_name, "as_legs"))
			isxao::GetInvSlotIdentity(AS_LEGS, id);
		else if (!strcmp(sz_search_name, "as_lwrist"))
			isxao::GetInvSlotIdentity(AS_L_WRIST, id);
		else if (!strcmp(sz_search_name, "as_rfinger"))
			isxao::GetInvSlotIdentity(AS_R_FINGER, id);
		else if (!strcmp(sz_search_name, "as_feet"))
			isxao::GetInvSlotIdentity(AS_FEET, id);
		else if (!strcmp(sz_search_name, "as_lfinger"))
			isxao::GetInvSlotIdentity(AS_L_FINGER, id);
		else if (!strcmp(sz_search_name, "is_eyes"))
			isxao::GetInvSlotIdentity(IS_EYES, id);
		else if (!strcmp(sz_search_name, "is_head"))
			isxao::GetInvSlotIdentity(IS_HEAD, id);
		else if (!strcmp(sz_search_name, "is_ears"))
			isxao::GetInvSlotIdentity(IS_EARS, id);
		else if (!strcmp(sz_search_name, "is_rarm"))
			isxao::GetInvSlotIdentity(IS_R_ARM, id);
		else if (!strcmp(sz_search_name, "is_chest"))
			isxao::GetInvSlotIdentity(IS_CHEST, id);
		else if (!strcmp(sz_search_name, "is_larm"))
			isxao::GetInvSlotIdentity(IS_L_ARM, id);
		else if (!strcmp(sz_search_name, "is_rwrist"))
			isxao::GetInvSlotIdentity(IS_R_WRIST, id);
		else if (!strcmp(sz_search_name, "is_waist"))
			isxao::GetInvSlotIdentity(IS_WAIST, id);
		else if (!strcmp(sz_search_name, "is_lwrist"))
			isxao::GetInvSlotIdentity(IS_L_WRIST, id);
		else if (!strcmp(sz_search_name, "is_rhand"))
			isxao::GetInvSlotIdentity(IS_R_HAND, id);
		else if (!strcmp(sz_search_name, "is_legs"))
			isxao::GetInvSlotIdentity(IS_LEGS, id);
		else if (!strcmp(sz_search_name, "is_lhand"))
			isxao::GetInvSlotIdentity(IS_L_HAND, id);
		else if (!strcmp(sz_search_name, "is_feet"))
			isxao::GetInvSlotIdentity(IS_FEET, id);
		if (id.type != 0)
			return reinterpret_cast<inventory_item*>(P_ENGINE_CLIENT_ANARCHY->get_item_by_template(id, d));
		std::map<identity_t, inventory_item*> m;
		get_inventory(m);
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
		return nullptr;
	}

	inventory_slot_t inventory_holder::get_inventory_slot(DWORD index) const
	{
		inventory_slot_t s;
		if (P_ENGINE_CLIENT_ANARCHY)
		{
			std::map<identity_t, inventory_item*> m;
			get_inventory(m);
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
		if (P_ENGINE_CLIENT_ANARCHY && P_ENGINE_CLIENT_ANARCHY->get_client_char())
		{
			identity_t id(0, 0);
			const identity_t d(0, 0);
			char sz_name[MAX_VARSTRING] = { 0 };
			char sz_search_name[MAX_VARSTRING];
			strcpy_s(sz_search_name, MAX_VARSTRING, sz_arg);
			_strlwr_s(sz_search_name);
			if (!strcmp(sz_search_name, "ws_hud1"))
				isxao::GetInvSlotIdentity(ao::WS_HUD_1, id);
			else if (!strcmp(sz_search_name, "ws_hud2"))
				isxao::GetInvSlotIdentity(ao::WS_HUD_2, id);
			else if (!strcmp(sz_search_name, "ws_hud3"))
				isxao::GetInvSlotIdentity(ao::WS_HUD_3, id);
			else if (!strcmp(sz_search_name, "ws_util1"))
				isxao::GetInvSlotIdentity(ao::WS_UTIL_1, id);
			else if (!strcmp(sz_search_name, "ws_util2"))
				isxao::GetInvSlotIdentity(ao::WS_UTIL_2, id);
			else if (!strcmp(sz_search_name, "ws_util3"))
				isxao::GetInvSlotIdentity(ao::WS_UTIL_3, id);
			else if (!strcmp(sz_search_name, "ws_rhand"))
				isxao::GetInvSlotIdentity(ao::WS_R_HAND, id);
			else if (!strcmp(sz_search_name, "ws_belt"))
				isxao::GetInvSlotIdentity(ao::WS_BELT, id);
			else if (!strcmp(sz_search_name, "ws_lhand"))
				isxao::GetInvSlotIdentity(ao::WS_L_HAND, id);
			else if (!strcmp(sz_search_name, "ws_ncu1"))
				isxao::GetInvSlotIdentity(ao::WS_NCU_1, id);
			else if (!strcmp(sz_search_name, "ws_ncu2"))
				isxao::GetInvSlotIdentity(ao::WS_NCU_2, id);
			else if (!strcmp(sz_search_name, "ws_ncu3"))
				isxao::GetInvSlotIdentity(ao::WS_NCU_3, id);
			else if (!strcmp(sz_search_name, "ws_ncu4"))
				isxao::GetInvSlotIdentity(ao::WS_NCU_4, id);
			else if (!strcmp(sz_search_name, "ws_ncu5"))
				isxao::GetInvSlotIdentity(ao::WS_NCU_5, id);
			else if (!strcmp(sz_search_name, "ws_ncu6"))
				isxao::GetInvSlotIdentity(ao::WS_NCU_6, id);
			else if (!strcmp(sz_search_name, "as_neck"))
				isxao::GetInvSlotIdentity(ao::AS_NECK, id);
			else if (!strcmp(sz_search_name, "as_head"))
				isxao::GetInvSlotIdentity(ao::AS_HEAD, id);
			else if (!strcmp(sz_search_name, "as_back"))
				isxao::GetInvSlotIdentity(ao::AS_BACK, id);
			else if (!strcmp(sz_search_name, "as_rshoulder"))
				isxao::GetInvSlotIdentity(ao::AS_R_SHOULDER, id);
			else if (!strcmp(sz_search_name, "as_chest"))
				isxao::GetInvSlotIdentity(ao::AS_CHEST, id);
			else if (!strcmp(sz_search_name, "as_lshoulder"))
				isxao::GetInvSlotIdentity(ao::AS_L_SHOULDER, id);
			else if (!strcmp(sz_search_name, "as_rarm"))
				isxao::GetInvSlotIdentity(ao::AS_R_ARM, id);
			else if (!strcmp(sz_search_name, "as_hands"))
				isxao::GetInvSlotIdentity(ao::AS_HANDS, id);
			else if (!strcmp(sz_search_name, "as_larm"))
				isxao::GetInvSlotIdentity(ao::AS_L_ARM, id);
			else if (!strcmp(sz_search_name, "as_rwrist"))
				isxao::GetInvSlotIdentity(ao::AS_R_WRIST, id);
			else if (!strcmp(sz_search_name, "as_legs"))
				isxao::GetInvSlotIdentity(ao::AS_LEGS, id);
			else if (!strcmp(sz_search_name, "as_lwrist"))
				isxao::GetInvSlotIdentity(ao::AS_L_WRIST, id);
			else if (!strcmp(sz_search_name, "as_rfinger"))
				isxao::GetInvSlotIdentity(ao::AS_R_FINGER, id);
			else if (!strcmp(sz_search_name, "as_feet"))
				isxao::GetInvSlotIdentity(ao::AS_FEET, id);
			else if (!strcmp(sz_search_name, "as_lfinger"))
				isxao::GetInvSlotIdentity(ao::AS_L_FINGER, id);
			else if (!strcmp(sz_search_name, "is_eyes"))
				isxao::GetInvSlotIdentity(ao::IS_EYES, id);
			else if (!strcmp(sz_search_name, "is_head"))
				isxao::GetInvSlotIdentity(ao::IS_HEAD, id);
			else if (!strcmp(sz_search_name, "is_ears"))
				isxao::GetInvSlotIdentity(ao::IS_EARS, id);
			else if (!strcmp(sz_search_name, "is_rarm"))
				isxao::GetInvSlotIdentity(ao::IS_R_ARM, id);
			else if (!strcmp(sz_search_name, "is_chest"))
				isxao::GetInvSlotIdentity(ao::IS_CHEST, id);
			else if (!strcmp(sz_search_name, "is_larm"))
				isxao::GetInvSlotIdentity(ao::IS_L_ARM, id);
			else if (!strcmp(sz_search_name, "is_rwrist"))
				isxao::GetInvSlotIdentity(ao::IS_R_WRIST, id);
			else if (!strcmp(sz_search_name, "is_waist"))
				isxao::GetInvSlotIdentity(ao::IS_WAIST, id);
			else if (!strcmp(sz_search_name, "is_lwrist"))
				isxao::GetInvSlotIdentity(ao::IS_L_WRIST, id);
			else if (!strcmp(sz_search_name, "is_rhand"))
				isxao::GetInvSlotIdentity(ao::IS_R_HAND, id);
			else if (!strcmp(sz_search_name, "is_legs"))
				isxao::GetInvSlotIdentity(ao::IS_LEGS, id);
			else if (!strcmp(sz_search_name, "is_lhand"))
				isxao::GetInvSlotIdentity(ao::IS_L_HAND, id);
			else if (!strcmp(sz_search_name, "is_feet"))
				isxao::GetInvSlotIdentity(ao::IS_FEET, id);
			if (id.type != 0)
			{
				s.slot_id = id;
				s.p_item = reinterpret_cast<inventory_item*>(P_ENGINE_CLIENT_ANARCHY->get_item_by_template(id, d));
			}
			std::map<identity_t, inventory_item*> m;
			this->get_inventory(m);
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
			isxao::GetInvSlotIdentity(i, id);
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

}
#include "isxao_main.h"

namespace isxao_classes
{

	DWORD InventoryHolder::BuildLSInventory(LSObjectCollection *pMap) const
	{
		IDENTITY d;
		ZeroMemory(&d, sizeof(IDENTITY));
		auto count = GetNewInventory()->GetInventorySize();
		for (DWORD i = 0; i < count; i++)
		{
			IDENTITY slot;
			isxao_utilities::GetInvSlotIdentity(i, slot);
			auto pItem = pEngineClientAnarchy->GetItemByTemplate(slot, d);
			if (pItem)
			{
				pMap->SetItem(isxao_utilities::GetInvSlotName(slot), reinterpret_cast<LSOBJECTDATA&>(pItem));
			}
		}
		return pMap->GetContainerUsed();
	}

	DWORD InventoryHolder::BuildLSInventory(LSIndex* pIndex) const
	{
		IDENTITY d;
		ZeroMemory(&d, sizeof(IDENTITY));
		auto count = GetNewInventory()->GetInventorySize();
		for (DWORD i = 0; i < count; i++)
		{
			IDENTITY slot;
			::GetInvSlotIdentity(i, slot);
			auto pItem = pEngineClientAnarchy->GetItemByTemplate(slot, d);
			if (pItem)
			{
				INVENTORYSLOT s;
				s.SlotID = slot;
				s.pItem = reinterpret_cast<InventoryItem*>(pItem);
				auto pS = PINVENTORYSLOT(pISInterface->GetTempBuffer(sizeof(INVENTORYSLOT), &s));
				pIndex->AddItem(reinterpret_cast<LSOBJECTDATA&>(pS));
			}
		}
		return pIndex->GetContainerUsed();
	}

	DWORD InventoryHolder::GetArmorInventory(std::vector<INVENTORYDATA*> &v)
	{
		for (int i = 17; i < 32; i++)
		{
			PINVENTORYDATA p_inventory_data = pEngineClientAnarchy->GetClientChar()->GetInventoryHolder()->GetInventoryHolderData().pRegularInventory->pInventoryData[i];
			if (p_inventory_data)
				v.push_back(p_inventory_data);
		}
		return v.size();
	}
	
	BankEntry* InventoryHolder::GetBankInventory() const
	{
		return reinterpret_cast<BankEntry*>(GetInventoryHolderData().pBankEntry);
	}

	DWORD InventoryHolder::GetCharacterInventory(std::vector<INVENTORYDATA*> &v)
	{
		for (int i = 64; i < 94; i++)
		{
			PINVENTORYDATA p_inventory_data = pEngineClientAnarchy->GetClientChar()->GetInventoryHolder()->GetInventoryHolderData().pRegularInventory->pInventoryData[i];
			if (p_inventory_data)
				v.push_back(p_inventory_data);
		}
		return v.size();
	}

	DWORD InventoryHolder::GetImplantInventory(std::vector<INVENTORYDATA*> &v)
	{
		for (int i = 33; i < 46; i++)
		{
			PINVENTORYDATA p_inventory_data = pEngineClientAnarchy->GetClientChar()->GetInventoryHolder()->GetInventoryHolderData().pRegularInventory->pInventoryData[i];
			if (p_inventory_data)
				v.push_back(p_inventory_data);
		}
		return v.size();
	}

	DWORD InventoryHolder::GetInventoryCount() const
	{
		std::map<IDENTITY, InventoryItem*> m;
		return GetInventory(m);
	}
	
	NewInventory* InventoryHolder::GetNewInventory() const
	{
		return reinterpret_cast<NewInventory*>(GetInventoryHolderData().pRegularInventory);
	}

	INVENTORYHOLDER InventoryHolder::GetInventoryHolderData() const
	{
		return inventory_holder_;
	}

	PIDENTITY InventoryHolder::GetInventoryHolderIdentity() const
	{
		return GetInventoryHolderData().pClientIdentity;
	}

	NewInventory* InventoryHolder::GetOverflowInventory() const
	{
		return reinterpret_cast<NewInventory*>(GetInventoryHolderData().pOverflowInventory);
	}

	InventoryItem* InventoryHolder::GetInventoryItem(DWORD index) const
	{
		std::map<IDENTITY, InventoryItem*> m;
		GetInventory(m);
		if (index < 1 || index > m.size())
			return nullptr;
		for (auto it = m.begin(); it != m.end(); ++it)
		{
			index -= 1;
			if (index == 0)
				return it->second;
		}
		return nullptr;
	}

	InventoryItem* InventoryHolder::GetInventoryItem(PCSTR szArg) const
	{
		IDENTITY id;
		ZeroMemory(&id, sizeof(IDENTITY));
		IDENTITY d;
		ZeroMemory(&d, sizeof(IDENTITY));
		char szName[MAX_STRING] = { 0 };
		char szSearchName[MAX_STRING];
		strcpy_s(szSearchName, MAX_STRING, szArg);
		_strlwr_s(szSearchName);
		if (!strcmp(szSearchName, "ws_hud1"))
			GetInvSlotIdentity(::WS_HUD_1, id);
		else if (!strcmp(szSearchName, "ws_hud2"))
			GetInvSlotIdentity(::WS_HUD_2, id);
		else if (!strcmp(szSearchName, "ws_hud3"))
			GetInvSlotIdentity(::WS_HUD_3, id);
		else if (!strcmp(szSearchName, "ws_util1"))
			GetInvSlotIdentity(::WS_UTIL_1, id);
		else if (!strcmp(szSearchName, "ws_util2"))
			GetInvSlotIdentity(::WS_UTIL_2, id);
		else if (!strcmp(szSearchName, "ws_util3"))
			GetInvSlotIdentity(::WS_UTIL_3, id);
		else if (!strcmp(szSearchName, "ws_rhand"))
			GetInvSlotIdentity(::WS_R_HAND, id);
		else if (!strcmp(szSearchName, "ws_belt"))
			GetInvSlotIdentity(::WS_BELT, id);
		else if (!strcmp(szSearchName, "ws_lhand"))
			GetInvSlotIdentity(::WS_L_HAND, id);
		else if (!strcmp(szSearchName, "ws_ncu1"))
			GetInvSlotIdentity(::WS_NCU_1, id);
		else if (!strcmp(szSearchName, "ws_ncu2"))
			GetInvSlotIdentity(::WS_NCU_2, id);
		else if (!strcmp(szSearchName, "ws_ncu3"))
			GetInvSlotIdentity(::WS_NCU_3, id);
		else if (!strcmp(szSearchName, "ws_ncu4"))
			GetInvSlotIdentity(::WS_NCU_4, id);
		else if (!strcmp(szSearchName, "ws_ncu5"))
			GetInvSlotIdentity(::WS_NCU_5, id);
		else if (!strcmp(szSearchName, "ws_ncu6"))
			GetInvSlotIdentity(::WS_NCU_6, id);
		else if (!strcmp(szSearchName, "as_neck"))
			GetInvSlotIdentity(::AS_NECK, id);
		else if (!strcmp(szSearchName, "as_head"))
			GetInvSlotIdentity(::AS_HEAD, id);
		else if (!strcmp(szSearchName, "as_back"))
			GetInvSlotIdentity(::AS_BACK, id);
		else if (!strcmp(szSearchName, "as_rshoulder"))
			GetInvSlotIdentity(::AS_R_SHOULDER, id);
		else if (!strcmp(szSearchName, "as_chest"))
			GetInvSlotIdentity(::AS_CHEST, id);
		else if (!strcmp(szSearchName, "as_lshoulder"))
			GetInvSlotIdentity(::AS_L_SHOULDER, id);
		else if (!strcmp(szSearchName, "as_rarm"))
			GetInvSlotIdentity(::AS_R_ARM, id);
		else if (!strcmp(szSearchName, "as_hands"))
			GetInvSlotIdentity(::AS_HANDS, id);
		else if (!strcmp(szSearchName, "as_larm"))
			GetInvSlotIdentity(::AS_L_ARM, id);
		else if (!strcmp(szSearchName, "as_rwrist"))
			GetInvSlotIdentity(::AS_R_WRIST, id);
		else if (!strcmp(szSearchName, "as_legs"))
			GetInvSlotIdentity(::AS_LEGS, id);
		else if (!strcmp(szSearchName, "as_lwrist"))
			GetInvSlotIdentity(::AS_L_WRIST, id);
		else if (!strcmp(szSearchName, "as_rfinger"))
			GetInvSlotIdentity(::AS_R_FINGER, id);
		else if (!strcmp(szSearchName, "as_feet"))
			GetInvSlotIdentity(::AS_FEET, id);
		else if (!strcmp(szSearchName, "as_lfinger"))
			GetInvSlotIdentity(::AS_L_FINGER, id);
		else if (!strcmp(szSearchName, "is_eyes"))
			GetInvSlotIdentity(::IS_EYES, id);
		else if (!strcmp(szSearchName, "is_head"))
			GetInvSlotIdentity(::IS_HEAD, id);
		else if (!strcmp(szSearchName, "is_ears"))
			GetInvSlotIdentity(::IS_EARS, id);
		else if (!strcmp(szSearchName, "is_rarm"))
			GetInvSlotIdentity(::IS_R_ARM, id);
		else if (!strcmp(szSearchName, "is_chest"))
			GetInvSlotIdentity(::IS_CHEST, id);
		else if (!strcmp(szSearchName, "is_larm"))
			GetInvSlotIdentity(::IS_L_ARM, id);
		else if (!strcmp(szSearchName, "is_rwrist"))
			GetInvSlotIdentity(::IS_R_WRIST, id);
		else if (!strcmp(szSearchName, "is_waist"))
			GetInvSlotIdentity(::IS_WAIST, id);
		else if (!strcmp(szSearchName, "is_lwrist"))
			GetInvSlotIdentity(::IS_L_WRIST, id);
		else if (!strcmp(szSearchName, "is_rhand"))
			GetInvSlotIdentity(::IS_R_HAND, id);
		else if (!strcmp(szSearchName, "is_legs"))
			GetInvSlotIdentity(::IS_LEGS, id);
		else if (!strcmp(szSearchName, "is_lhand"))
			GetInvSlotIdentity(::IS_L_HAND, id);
		else if (!strcmp(szSearchName, "is_feet"))
			GetInvSlotIdentity(::IS_FEET, id);
		if (id.Type != 0)
			return reinterpret_cast<InventoryItem*>(pEngineClientAnarchy->GetItemByTemplate(id, d));
		std::map<IDENTITY, InventoryItem*> m;
		GetInventory(m);
		for (auto it = m.begin(); it != m.end(); ++it)
		{
			if (it->second)
			{
				strcpy_s(szName, MAX_STRING, it->second->GetName());
				_strlwr_s(szName);
				if (strstr(szName, szSearchName))
					return reinterpret_cast<InventoryItem*>(it->second);
			}
		}
		return nullptr;
	}

	INVENTORYSLOT InventoryHolder::GetInventorySlot(DWORD index) const
	{
		INVENTORYSLOT s;
		ZeroMemory(&s, sizeof(INVENTORYSLOT));
		if (pEngineClientAnarchy)
		{
			std::map<IDENTITY, InventoryItem*> m;
			GetInventory(m);
			if (index < 1 || index > m.size())
				return s;
			for (auto it = m.begin(); it != m.end(); ++it)
			{
				index -= 1;
				if (index == 0)
				{
					s.SlotID = it->first;
					s.pItem = it->second;
					return s;
				}
			}
		}
		return s;
	}

	INVENTORYSLOT InventoryHolder::GetInventorySlot(PCSTR szArg) const
	{
		INVENTORYSLOT s;
		ZeroMemory(&s, sizeof(INVENTORYSLOT));
		if (pEngineClientAnarchy && pEngineClientAnarchy->GetClientChar())
		{
			IDENTITY id;
			ZeroMemory(&id, sizeof(IDENTITY));
			IDENTITY d;
			ZeroMemory(&d, sizeof(IDENTITY));
			char szName[MAX_STRING] = { 0 };
			char szSearchName[MAX_STRING];
			strcpy_s(szSearchName, MAX_STRING, szArg);
			_strlwr_s(szSearchName);
			if (!strcmp(szSearchName, "ws_hud1"))
				GetInvSlotIdentity(::WS_HUD_1, id);
			else if (!strcmp(szSearchName, "ws_hud2"))
				GetInvSlotIdentity(::WS_HUD_2, id);
			else if (!strcmp(szSearchName, "ws_hud3"))
				GetInvSlotIdentity(::WS_HUD_3, id);
			else if (!strcmp(szSearchName, "ws_util1"))
				GetInvSlotIdentity(::WS_UTIL_1, id);
			else if (!strcmp(szSearchName, "ws_util2"))
				GetInvSlotIdentity(::WS_UTIL_2, id);
			else if (!strcmp(szSearchName, "ws_util3"))
				GetInvSlotIdentity(::WS_UTIL_3, id);
			else if (!strcmp(szSearchName, "ws_rhand"))
				GetInvSlotIdentity(::WS_R_HAND, id);
			else if (!strcmp(szSearchName, "ws_belt"))
				GetInvSlotIdentity(::WS_BELT, id);
			else if (!strcmp(szSearchName, "ws_lhand"))
				GetInvSlotIdentity(::WS_L_HAND, id);
			else if (!strcmp(szSearchName, "ws_ncu1"))
				GetInvSlotIdentity(::WS_NCU_1, id);
			else if (!strcmp(szSearchName, "ws_ncu2"))
				GetInvSlotIdentity(::WS_NCU_2, id);
			else if (!strcmp(szSearchName, "ws_ncu3"))
				GetInvSlotIdentity(::WS_NCU_3, id);
			else if (!strcmp(szSearchName, "ws_ncu4"))
				GetInvSlotIdentity(::WS_NCU_4, id);
			else if (!strcmp(szSearchName, "ws_ncu5"))
				GetInvSlotIdentity(::WS_NCU_5, id);
			else if (!strcmp(szSearchName, "ws_ncu6"))
				GetInvSlotIdentity(::WS_NCU_6, id);
			else if (!strcmp(szSearchName, "as_neck"))
				GetInvSlotIdentity(::AS_NECK, id);
			else if (!strcmp(szSearchName, "as_head"))
				GetInvSlotIdentity(::AS_HEAD, id);
			else if (!strcmp(szSearchName, "as_back"))
				GetInvSlotIdentity(::AS_BACK, id);
			else if (!strcmp(szSearchName, "as_rshoulder"))
				GetInvSlotIdentity(::AS_R_SHOULDER, id);
			else if (!strcmp(szSearchName, "as_chest"))
				GetInvSlotIdentity(::AS_CHEST, id);
			else if (!strcmp(szSearchName, "as_lshoulder"))
				GetInvSlotIdentity(::AS_L_SHOULDER, id);
			else if (!strcmp(szSearchName, "as_rarm"))
				GetInvSlotIdentity(::AS_R_ARM, id);
			else if (!strcmp(szSearchName, "as_hands"))
				GetInvSlotIdentity(::AS_HANDS, id);
			else if (!strcmp(szSearchName, "as_larm"))
				GetInvSlotIdentity(::AS_L_ARM, id);
			else if (!strcmp(szSearchName, "as_rwrist"))
				GetInvSlotIdentity(::AS_R_WRIST, id);
			else if (!strcmp(szSearchName, "as_legs"))
				GetInvSlotIdentity(::AS_LEGS, id);
			else if (!strcmp(szSearchName, "as_lwrist"))
				GetInvSlotIdentity(::AS_L_WRIST, id);
			else if (!strcmp(szSearchName, "as_rfinger"))
				GetInvSlotIdentity(::AS_R_FINGER, id);
			else if (!strcmp(szSearchName, "as_feet"))
				GetInvSlotIdentity(::AS_FEET, id);
			else if (!strcmp(szSearchName, "as_lfinger"))
				GetInvSlotIdentity(::AS_L_FINGER, id);
			else if (!strcmp(szSearchName, "is_eyes"))
				GetInvSlotIdentity(::IS_EYES, id);
			else if (!strcmp(szSearchName, "is_head"))
				GetInvSlotIdentity(::IS_HEAD, id);
			else if (!strcmp(szSearchName, "is_ears"))
				GetInvSlotIdentity(::IS_EARS, id);
			else if (!strcmp(szSearchName, "is_rarm"))
				GetInvSlotIdentity(::IS_R_ARM, id);
			else if (!strcmp(szSearchName, "is_chest"))
				GetInvSlotIdentity(::IS_CHEST, id);
			else if (!strcmp(szSearchName, "is_larm"))
				GetInvSlotIdentity(::IS_L_ARM, id);
			else if (!strcmp(szSearchName, "is_rwrist"))
				GetInvSlotIdentity(::IS_R_WRIST, id);
			else if (!strcmp(szSearchName, "is_waist"))
				GetInvSlotIdentity(::IS_WAIST, id);
			else if (!strcmp(szSearchName, "is_lwrist"))
				GetInvSlotIdentity(::IS_L_WRIST, id);
			else if (!strcmp(szSearchName, "is_rhand"))
				GetInvSlotIdentity(::IS_R_HAND, id);
			else if (!strcmp(szSearchName, "is_legs"))
				GetInvSlotIdentity(::IS_LEGS, id);
			else if (!strcmp(szSearchName, "is_lhand"))
				GetInvSlotIdentity(::IS_L_HAND, id);
			else if (!strcmp(szSearchName, "is_feet"))
				GetInvSlotIdentity(::IS_FEET, id);
			if (id.Type != 0)
			{
				s.SlotID = id;
				s.pItem = reinterpret_cast<InventoryItem*>(pEngineClientAnarchy->GetItemByTemplate(id, d));
			}
			std::map<IDENTITY, InventoryItem*> m;
			GetInventory(m);
			for (auto it = m.begin(); it != m.end(); ++it)
			{
				if (it->second)
				{
					strcpy_s(szName, MAX_STRING, it->second->GetName());
					_strlwr_s(szName);
					if (strstr(szName, szSearchName))
					{
						s.SlotID = it->first;
						s.pItem = reinterpret_cast<InventoryItem*>(it->second);
					}
				}
			}
		}
		return s;
	}

	DWORD InventoryHolder::GetInventory(std::map<IDENTITY, InventoryItem*>& m) const
	{
		IDENTITY d;
		d.Type = 0;
		d.Id = 0;
		auto count = GetNewInventory()->GetInventorySize();
		for (DWORD i = 0; i < count; i++)
		{
			IDENTITY id;
			isxao_utilities::GetInvSlotIdentity(i, id);
			auto pItem = pEngineClientAnarchy->GetItemByTemplate(id, d);
			if (pItem)
				m.insert_or_assign(id, reinterpret_cast<InventoryItem*>(pEngineClientAnarchy->GetItemByTemplate(id, d)));
		}
		return m.size();
	}

	DWORD InventoryHolder::GetWeaponInventory(std::vector<INVENTORYDATA*>& v)
	{
		for (int i = 1; i < 16; i++)
		{
			PINVENTORYDATA p_inventory_data = pEngineClientAnarchy->GetClientChar()->GetInventoryHolder()->GetInventoryHolderData().pRegularInventory->pInventoryData[i];
			if (p_inventory_data)
				v.push_back(p_inventory_data);
		}
		return v.size();
	}

}
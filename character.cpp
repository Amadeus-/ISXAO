#include "isxao_main.h"

namespace isxao_classes
{

	std::map<IDENTITY, InventoryItem*> Character::GetInventory()
	{
		std::map<IDENTITY, InventoryItem*> m;
		IDENTITY d;
		d.Type = 0;
		d.Id = 0;
		auto count = GetInventoryHolder()->GetNewInventory()->GetInventorySize();
		for (DWORD i = 0; i < count; i++)
		{
			IDENTITY id;
			::GetInvSlotIdentity(i, id);
			auto pItem = pEngineClientAnarchy->GetItemByTemplate(id, d);
			if (pItem)
				m.insert_or_assign(id, reinterpret_cast<InventoryItem*>(pEngineClientAnarchy->GetItemByTemplate(id, d)));
		}
		return m;
	}

	DWORD Character::BuildLSInventory(LSObjectCollection *pMap)
	{
		IDENTITY d;
		ZeroMemory(&d, sizeof(IDENTITY));
		auto count = GetInventoryHolder()->GetNewInventory()->GetInventorySize();
		for (DWORD i = 0; i < count; i++)
		{
			IDENTITY slot;
			::GetInvSlotIdentity(i, slot);
			auto pItem = pEngineClientAnarchy->GetItemByTemplate(slot, d);
			if (pItem)
			{
				PCHAR pName = nullptr;
				GetInvSlotName(slot, pName);
				pMap->SetItem(pName, reinterpret_cast<LSOBJECTDATA&>(pItem));
			}				
		}
		return pMap->GetContainerSize();
	}

	DWORD Character::BuildLSInventory(LSIndex* pIndex)
	{
		IDENTITY d;
		ZeroMemory(&d, sizeof(IDENTITY));
		auto count = GetInventoryHolder()->GetNewInventory()->GetInventorySize();
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
		return pIndex->GetAllocated();
	}


	void Character::CastNanoSpell(IDENTITY const& nano, IDENTITY const& target) const
	{
		if (pEngineClientAnarchy)
			pEngineClientAnarchy->N3Msg_CastNanoSpell(nano, target);
	}

#ifdef SimpleChar_t__CheckLOS_x
	FUNCTION_AT_ADDRESS(bool Character::CheckLOS(Dynel* pDynel), SimpleChar_t__CheckLOS);
#else
	bool Character::CheckLOS(Dynel* pDynel)
	{
		if (pEngineClientAnarchy && pEngineClientAnarchy->GetClientChar() && pPlayfieldDir && pPlayfieldDir->GetPlayfield())
		{
			VECTOR3 offset;
			offset.X = 0.0f;
			offset.Y = 1.6f;
			offset.Z = 0.0f;
			VECTOR3 client;
			pEngineClientAnarchy->N3Msg_GetGlobalCharacterPosition(client);
			VECTOR3 offsetClient = VECTOR3::Add(client, offset);
			VECTOR3 dynel = pDynel->GetPosition();
			VECTOR3 offsetMe = VECTOR3::Add(dynel, offset);
			return pPlayfieldDir->GetPlayfield()->LineOfSight(offsetClient, offsetMe, GetDynelData()->pVehicle->ZoneInstanceID, false);
		}
		return false;
	}
#endif

	void Character::DefaultAttack(IDENTITY const& id) const
	{
		if (pEngineClientAnarchy)
			pEngineClientAnarchy->N3Msg_DefaultAttack(id, true);
	}

	DWORD Character::GetInventoryCount()
	{
		return GetInventory().size();
	}

	InventoryHolder* Character::GetInventoryHolder()
	{
		return reinterpret_cast<InventoryHolder*>(GetSimpleCharData()->pContainerInventory);
	}

	InventoryItem* Character::GetInventoryItem(DWORD index)
	{
		if (pEngineClientAnarchy)
		{
			auto m = GetInventory();
			if (index < 1 || index > m.size())
				return nullptr;
			for (auto it = m.begin(); it != m.end(); ++it)
			{
				index -= 1;
				if (index == 0)
					return it->second;
			}
		}
		return nullptr;
	}

	InventoryItem* Character::GetInventoryItem(PCSTR szArg)
	{
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
				return reinterpret_cast<InventoryItem*>(pEngineClientAnarchy->GetItemByTemplate(id, d));
			std::map<IDENTITY, InventoryItem*> m = GetInventory();
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
		}
		return nullptr;
	}

	INVENTORYSLOT Character::GetInventorySlot(DWORD index)
	{
		INVENTORYSLOT s;
		ZeroMemory(&s, sizeof(INVENTORYSLOT));
		if (pEngineClientAnarchy)
		{
			auto m = GetInventory();
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

	INVENTORYSLOT Character::GetInventorySlot(PCSTR szArg)
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
			std::map<IDENTITY, InventoryItem*> m = GetInventory();
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

	PerkHolder* Character::GetPerkHolder()
	{
		return reinterpret_cast<PerkHolder*>(GetSimpleCharData()->pPerkHolder);
	}

	bool Character::GetInvSlotIdentity(AOData::ArmorSlot_e slot, IDENTITY& id)
	{
		id.Type = 102;
		switch (slot)
		{
		case AS_NECK:
		case AS_HEAD:
		case AS_BACK:
		case AS_R_SHOULDER:
		case AS_CHEST:
		case AS_L_SHOULDER:
		case AS_R_ARM:
		case AS_HANDS:
		case AS_L_ARM:
		case AS_R_WRIST:
		case AS_LEGS:
		case AS_L_WRIST:
		case AS_R_FINGER:
		case AS_FEET:
		case AS_L_FINGER:
			id.Id = DWORD(slot) + 16;
			break;
		default:
			return false;;
		}
		return true;
	}

	bool Character::GetInvSlotIdentity(AOData::ImplantSlot_e slot, IDENTITY& id)
	{
		id.Type = 103;
		switch (slot)
		{
		case IS_EYES:
		case IS_HEAD:
		case IS_EARS:
		case IS_R_ARM:
		case IS_CHEST:
		case IS_L_ARM:
		case IS_R_WRIST:
		case IS_WAIST:
		case IS_L_WRIST:
		case IS_R_HAND:
		case IS_LEGS:
		case IS_L_HAND:
		case IS_FEET:
			id.Id = DWORD(slot) + 32;
			break;
		default:
			return false;
		}
		return true;
	}

	bool Character::GetInvSlotIdentity(AOData::WeaponSlot_e slot, IDENTITY& id)
	{
		id.Type = 101;
		switch (slot)
		{
		case WS_HUD_1:
		case WS_HUD_3:
		case WS_UTIL_1:
		case WS_UTIL_2:
		case WS_UTIL_3:
		case WS_R_HAND:
		case WS_BELT:
		case WS_L_HAND:
		case WS_NCU_1:
		case WS_NCU_2:
		case WS_NCU_3:
		case WS_NCU_4:
		case WS_NCU_5:
		case WS_NCU_6:
		case WS_HUD_2:
			id.Id = DWORD(slot);
			break;
		default:
			return false;
		}
		return true;
	}

	bool Character::GetInvSlotIdentity(DWORD slot, IDENTITY& id)
	{
		id.Id = slot;
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
			id.Type = 101;
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
			id.Type = 102;
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
			id.Type = 103;
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
			id.Type = 104;
			break;
		default:
			return false;
		}
		return true;
	}

	void Character::GetPerkMap(std::map<IDENTITY, DWORD> &m)
	{
		GetPerkHolder()->GetPerkMap(m);
	}

	bool Character::GetWeaponTarget(IDENTITY& id)
	{
		if (HasWeaponTarget())
		{
			id = pAttackingIndicator->Identity;
			return true;
		}
		return false;
	}

	SpecialActionHolder* Character::GetSpecialActionHolder()
	{
		return reinterpret_cast<SpecialActionHolder*>(GetSimpleCharData()->pSpecialActionHolder);
	}

	void Character::GetSpecialActions(std::vector<SpecialAction> &v)
	{
		GetSpecialActionHolder()->GetSpecialActions(v);
	}

	StatHolder* Character::GetStatHolder()
	{
		return reinterpret_cast<StatHolder*>(GetSimpleCharData()->pMapHolder);
	}

	void Character::GetStatMap(std::map<DWORD, LONG> &m)
	{
		GetStatHolder()->GetStatMap(m);
	}

	bool Character::GetTarget(IDENTITY& id)
	{
		if (HasTarget())
		{
			id = pSelectionIndicator->Identity;
			return true;
		}
		return false;
	}

	bool Character::HasTarget()
	{
		return pSelectionIndicator != nullptr;
	}

	bool Character::HasWeaponTarget()
	{
		return pAttackingIndicator != nullptr;
	}

	void Character::MakeTeamLeader(const IDENTITY& id)
	{
		if (pEngineClientAnarchy && IsInTeam() && IsTeamLeader())
			pEngineClientAnarchy->N3Msg_TransferTeamLeadership(id);
	}

	bool Character::PerformSpecialAction(const IDENTITY &id) const
	{
		typedef bool(__thiscall * tPerformSpecialAction)(PVOID, IDENTITY const &);
		auto pPerformSpecialAction = tPerformSpecialAction(n3EngineClientAnarchy_t__N3Msg_PerformSpecialAction_2);
		return pPerformSpecialAction(pEngineClientAnarchy, id);
	}

	void Character::SetRotation(const QUATERNION& q)
	{
		GetVehicle()->SetRotation(q);
	}

	void Character::StopAttack() const
	{
		typedef void(__thiscall * tStopAttack)(PVOID);
		auto pStopAttack = tStopAttack(n3EngineClientAnarchy_t__N3Msg_StopAttack);
		pStopAttack(pEngineClientAnarchy);
	}

#ifdef n3EngineClientAnarchy_t__N3Msg_UseItem_x
	void Character::UseItem(const IDENTITY& id)
	{
		pEngineClientAnarchy->N3Msg_UseItem(id, false);
	}
#else
	void Character::UseItem(IDENTITY const& id)
	{
		IDENTITY dummy;
		dummy.Type = 0;
		dummy.Id = 0;
		if (pEngineClientAnarchy->GetItemByTemplate(id, dummy))
		{
			typedef void(__thiscall * tUseItem)(PVOID, IDENTITY const &, bool);
			auto pUseItem = tUseItem(n3EngineClientAnarchy_t__N3Msg_UseItem);
			pUseItem(this, id, false);
		}
	}
#endif

	DWORD Character::GetPetMap(std::map<IDENTITY, DWORD> &m)
	{
		isxao_utilities::GetPetMap(m, GetSimpleCharData()->pNpcHolder->pPetDir);
		return m.size();
	}

	std::vector<DWORD> Character::GetNanoSpellList()
	{
		std::vector<DWORD> v;
		if (pEngineClientAnarchy && pEngineClientAnarchy->GetClientChar())
		{
			std::list<DWORD> l = GetSimpleCharData()->pSpellTemplateData->SpellList;
			for (auto it = l.begin(); it != l.end(); ++it)
			{
				v.push_back(*it);
			}
			std::sort(v.begin(), v.end(), less<DWORD>());
			return v;
		}
		return v;
	}

	NpcHolder* Character::GetNPCHolder()
	{
		return reinterpret_cast<NpcHolder*>(GetSimpleCharData()->pNpcHolder);
	}

	void Character::Face(float heading)
	{
		if (heading > 180.0f)
			heading -= 360.0f;
		auto q = QUATERNION::GetQuaternion(heading);
		SetRotation(q);
	}

	void Character::Face(VECTOR3 &location)
	{
		auto client_position = GetPosition();
		auto q = QUATERNION::GetQuaternionToFace(location, client_position);
		SetRotation(q);
	}
}
#include "isxao_main.h"

bool CharacterType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;

#define pCharacter ((Character*)ObjectData.Ptr)
	switch (CharacterTypeMembers(Member->ID))
	{
	case Inventory:
	{
		if(ISINDEX())
		{
			if(ISNUMBER())
			{
				INVENTORYSLOT s = pCharacter->GetInventoryHolder()->GetInventorySlot(GETNUMBER());
				PINVENTORYSLOT pS = static_cast<PINVENTORYSLOT>(pISInterface->GetTempBuffer(sizeof(INVENTORYSLOT), &s));
				if((Object.Ptr = pS))
				{
					Object.Type = pInventorySlotType;
					return true;
				}
			}
			INVENTORYSLOT s = pCharacter->GetInventoryHolder()->GetInventorySlot(argv[0]);
			if(s.SlotID.Type != 0)
			{
				PINVENTORYSLOT pS = static_cast<PINVENTORYSLOT>(pISInterface->GetTempBuffer(sizeof(INVENTORYSLOT), &s));
				if ((Object.Ptr = pS))
				{
					Object.Type = pInventorySlotType;
					return true;
				}
			}
		}
		return false;
	}
	case InventoryCount:
	{
		Object.DWord = pCharacter->GetInventoryHolder()->GetInventoryCount();
		Object.Type = pUintType;
		break;
	}
	case GetInventory:
	{
		if (ISINDEX())
		{
			// parse first arg to get a collection:InventoryItemType
			LSOBJECT MapObject;
			if (!pISInterface->DataParse(argv[0], MapObject))
				return false;
			// we got an object, now check the type
			if (MapObject.Type != pMapType)
				return false;
			// it's a collection:something, make sure it is collection:InventoryItemType
			LSObjectCollection *pMap = (LSObjectCollection*)MapObject.Ptr;
			if (pMap->GetType() != pInventoryItemType)
				return false;
			auto count = pCharacter->GetInventoryHolder()->BuildLSInventory(pMap);
			Object.DWord = pMap->GetCount();
			Object.Type = pUintType;
			return true;
		}
		return false;
	}
	case NanoSpell:
	{
		if(ISINDEX())
		{
			std::vector<DWORD> v;
			pCharacter->GetSpellTemplateData()->GetNanoSpellList(v);
			if(ISNUMBER())
			{
				auto index = DWORD(GETNUMBER());				
				if (index > v.size())
					return false;
				if((Object.Ptr = isxao_utilities::GetNanoItem(v[index - 1])))
				{
					Object.Type = pNanoSpellType;
					return true;
				}
			}
			else
			{
				char name[MAX_STRING];
				char search_name[MAX_STRING];
				strcpy_s(search_name, sizeof(search_name), argv[0]);
				_strlwr_s(search_name);
				for (auto it = v.begin(); it != v.end(); ++it)
				{
					auto pSpell = reinterpret_cast<NanoItem*>(isxao_utilities::GetNanoItem(*it));
					strcpy_s(name, sizeof(name), pSpell->GetName());
					_strlwr_s(name);
					if(strstr(name, search_name))
					{
						Object.Ptr = pSpell;
						Object.Type = pNanoSpellType;
						return true;
					}
				}
			}
		}
		return false;
	}
	case NanoSpellCount:
	{
		std::vector<DWORD> v;		
		Object.DWord = pCharacter->GetSpellTemplateData()->GetNanoSpellList(v);
		Object.Type = pUintType;
		break;
	}
	case GetNanoSpells:
	{
		if(ISINDEX())
		{
			LSOBJECT IndexObject;
			if (!pISInterface->DataParse(argv[0], IndexObject))
				return false;
			if (IndexObject.Type != pIndexType)
				return false;
			LSIndex *pIndex = (LSIndex*)IndexObject.Ptr;
			if (pIndex->GetType() != pNanoSpellType)
				return false;
			Object.DWord = pCharacter->GetSpellTemplateData()->BuildLSNanoSpellList(pIndex);
			Object.Type = pUintType;
			return true;
		}
		return false;
	}
	//case EquipmentIndex:
	//{
	//	if (ISINDEX())
	//	{
	//		// parse first arg to get a collection:InventoryItemType
	//		LSOBJECT IndexObject;
	//		if (!pISInterface->DataParse(argv[0], IndexObject))
	//			return false;				
	//		// we got an object, now check the type
	//		if (IndexObject.Type != pIndexType)
	//			return false;				
	//		// it's a collection:something, make sure it is collection:InventoryItemType
	//		LSIndex *pIndex = (LSIndex*)IndexObject.Ptr;
	//		if (pIndex->GetType() != pInventorySlotType)
	//			return false;
	//		auto count = pCharacter->GetInventoryHolder()->BuildLSInventory(pIndex);
	//		Object.DWord = pIndex->GetContainerUsed();
	//		Object.Type = pUintType;
	//		return true;
	//	}
	//	return false;
	//}
	case SpecialAction:
	{
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				auto index = DWORD(GETNUMBER());
				if ((Object.Ptr = pEngineClientAnarchy->GetClientChar()->GetSpecialActionHolder()->GetSpecialAction(index - 1)))
				{
					Object.Type = pSpecialActionType;
					return true;
				}
				return false;
			}
			if ((Object.Ptr = pEngineClientAnarchy->GetClientChar()->GetSpecialActionHolder()->GetSpecialAction(argv[0])))
			{
				Object.Type = pSpecialActionType;
				return true;
			}
			return false;
		}
		return false;
	}
	case SpecialActionCount:
	{
		Object.DWord = pEngineClientAnarchy->GetClientChar()->GetSpecialActionHolder()->GetSpecialActionCount();
		Object.Type = pUintType;
		break;
	}
	case GetSpecialActions:
	{
		if (ISINDEX())
		{
			LSOBJECT IndexObject;
			if (!pISInterface->DataParse(argv[0], IndexObject))
				return false;
			if (IndexObject.Type != pIndexType)
				return false;
			LSIndex *pIndex = (LSIndex*)IndexObject.Ptr;
			if (pIndex->GetType() != pSpecialActionTemplateType)
				return false;
			Object.DWord = pCharacter->GetSpecialActionHolder()->BuildLSSpecialActions(pIndex);
			Object.Type = pUintType;
			return true;
		}
		return false;
	}
	case ToActor:
	{
		Object.Ptr = pCharacter;
		Object.Type = pActorType;
		break;
	}
	default:
		return false;
	}
	return true;
#undef pCharacter
}

bool CharacterType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define pCharacter ((Character*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%s", pCharacter->GetName());
#undef pCharacter

	return true;
}
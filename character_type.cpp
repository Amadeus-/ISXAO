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
				INVENTORYSLOT s = pCharacter->GetInventorySlot(GETNUMBER());
				PINVENTORYSLOT pS = static_cast<PINVENTORYSLOT>(pISInterface->GetTempBuffer(sizeof(INVENTORYSLOT), &s));
				if((Object.Ptr = pS))
				{
					Object.Type = pInventorySlotType;
					return true;
				}
			}
			INVENTORYSLOT s = pCharacter->GetInventorySlot(argv[0]);
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
		Object.DWord = pCharacter->GetInventoryCount();
		Object.Type = pUintType;
		break;
	}
	case NanoSpell:
	{
		if(ISINDEX())
		{
			std::vector<DWORD> v = pCharacter->GetNanoSpellList();
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
				for (auto it = v.begin(); it != v.end(); ++it)
				{
					auto pSpell = reinterpret_cast<NanoItem*>(isxao_utilities::GetNanoItem(*it));
					if(!_strnicmp(GETFIRST(), pSpell->GetName(), strlen(GETFIRST())))
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
		Object.DWord = pCharacter->GetNanoSpellList().size();
		Object.Type = pUintType;
		break;
	}
	case EquipmentCollection:
	{
		if(ISINDEX())
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
			auto count = pCharacter->BuildLSInventory(pMap);
			Object.DWord = pMap->GetCount();
			Object.Type = pUintType;
			return true;
		}
		return false;
	}
	case EquipmentIndex:
	{
		if (ISINDEX())
		{
			// parse first arg to get a collection:InventoryItemType
			LSOBJECT IndexObject;
			if (!pISInterface->DataParse(argv[0], IndexObject))
				return false;				
			// we got an object, now check the type
			if (IndexObject.Type != pIndexType)
				return false;				
			// it's a collection:something, make sure it is collection:InventoryItemType
			LSIndex *pIndex = (LSIndex*)IndexObject.Ptr;
			if (pIndex->GetType() != pInventorySlotType)
				return false;
			auto count = pCharacter->BuildLSInventory(pIndex);
			Object.DWord = pIndex->GetContainerUsed();
			Object.Type = pUintType;
			return true;
		}
		return false;
	}
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
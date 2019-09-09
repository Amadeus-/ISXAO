#include "isxao_main.h"

bool CharacterType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;

#define pCharacter ((character*)ObjectData.Ptr)
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
			if(s.SlotID.type != 0)
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
				identity_t i(53019, v[index - 1]);
				identity_t d(0.0, 0.0);
				if((Object.Ptr = P_ENGINE_CLIENT_ANARCHY->get_item_by_template(i, d)))
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
					identity_t i(53019, *it);
					identity_t d(0.0, 0.0);
					auto pSpell = reinterpret_cast<NanoItem*>(P_ENGINE_CLIENT_ANARCHY->get_item_by_template(i, d));
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
				if ((Object.Ptr = P_ENGINE_CLIENT_ANARCHY->get_client_char()->GetSpecialActionHolder()->GetSpecialAction(index - 1)))
				{
					Object.Type = pSpecialActionTemplateType;
					return true;
				}
				return false;
			}
			if ((Object.Ptr = P_ENGINE_CLIENT_ANARCHY->get_client_char()->GetSpecialActionHolder()->GetSpecialAction(argv[0])))
			{
				Object.Type = pSpecialActionTemplateType;
				return true;
			}
			return false;
		}
		return false;
	}
	case SpecialActionCount:
	{
		Object.DWord = P_ENGINE_CLIENT_ANARCHY->get_client_char()->GetSpecialActionHolder()->GetSpecialActionCount();
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

bool CharacterType::GetMethod(LSOBJECTDATA& ObjectData, PLSTYPEMETHOD pMethod, int argc, char* argv[])
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pActor ((Character*)ObjectData.Ptr)
		switch (CharacterTypeMethods(pMethod->ID))
		{
		case Activate:
		{
			if (GetGameState() == GAMESTATE_IN_GAME)
				isxao_commands::Activate(0, argc, argv);
		}
		case Cast:
		{
			if (GetGameState() == GAMESTATE_IN_GAME)
				isxao_commands::Cast(0, argc, argv);
		}
		default: break;
		}
#undef pActor
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, pMethod->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}


bool CharacterType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define pCharacter ((character*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%I64u", pCharacter->get_identity().get_combined_identity());
#undef pCharacter

	return true;
}
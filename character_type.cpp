#include "isxao_main.h"

bool CharacterType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object)
{
	if (g_game_state != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;

#define P_CHARACTER ((ao::character*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
	switch (CharacterTypeMembers(Member->ID))
	{
	case Inventory:
	{
		if(IS_INDEX())
		{
			if(IS_NUMBER())
			{
				auto s = P_CHARACTER->get_inventory_holder()->get_inventory_slot(GET_NUMBER());  // NOLINT(cert-err34-c)
				const auto p_s = static_cast<ao::p_inventory_slot_t>(pISInterface->GetTempBuffer(sizeof(ao::inventory_slot_t), &s));
				if((Object.Ptr = p_s))
				{
					Object.Type = pInventorySlotType;
					return true;
				}
			}
			ao::inventory_slot_t s = P_CHARACTER->get_inventory_holder()->get_inventory_slot(argv[0]);
			if(s.slot_id.type != 0)
			{
				auto p_s = static_cast<ao::p_inventory_slot_t>(pISInterface->GetTempBuffer(sizeof(ao::inventory_slot_t), &s));
				if ((Object.Ptr = p_s))
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
		Object.DWord = P_CHARACTER->get_inventory_holder()->get_inventory_count();
		Object.Type = pUintType;
		break;
	}
	case GetInventory:
	{
		if (IS_INDEX())
		{
			// parse first arg to get a collection:InventoryItemType
			LSOBJECT MapObject;
			if (!pISInterface->DataParse(argv[0], MapObject))
				return false;
			// we got an object, now check the type
			if (MapObject.Type != pMapType)
				return false;
			// it's a collection:something, make sure it is collection:InventoryItemType
			auto*pMap = static_cast<LSObjectCollection*>(MapObject.Ptr);
			if (pMap->GetType() != pInventoryItemType)
				return false;
			auto count = P_CHARACTER->get_inventory_holder()->build_ls_inventory(pMap);
			Object.DWord = pMap->GetCount();
			Object.Type = pUintType;
			return true;
		}
		return false;
	}
	case NanoSpell:
	{
		if(IS_INDEX())
		{
			std::vector<DWORD> v;
			P_CHARACTER->get_spell_template_data()->get_nano_spell_list(v);
			if(IS_NUMBER())
			{
				auto index = DWORD(GET_NUMBER());				
				if (index > v.size())
					return false;
				ao::identity_t i(53019, v[index - 1]);
				ao::identity_t d(0, 0);
				if((Object.Ptr = P_ENGINE_CLIENT_ANARCHY->get_item_by_template(i, d)))
				{
					Object.Type = pNanoSpellType;
					return true;
				}
			}
			else
			{
				char name[MAX_VARSTRING];
				char search_name[MAX_VARSTRING];
				strcpy_s(search_name, sizeof(search_name), argv[0]);
				_strlwr_s(search_name);
				for (auto it = v.begin(); it != v.end(); ++it)
				{
					ao::identity_t i(53019, *it);
					ao::identity_t d(0, 0);
					auto pSpell = reinterpret_cast<ao::nano_item*>(P_ENGINE_CLIENT_ANARCHY->get_item_by_template(i, d));
					strcpy_s(name, sizeof(name), pSpell->get_name());
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
		Object.DWord = P_CHARACTER->get_spell_template_data()->get_nano_spell_list(v);
		Object.Type = pUintType;
		break;
	}
	case GetNanoSpells:
	{
		if(IS_INDEX())
		{
			LSOBJECT IndexObject;
			if (!pISInterface->DataParse(argv[0], IndexObject))
				return false;
			if (IndexObject.Type != pIndexType)
				return false;
			LSIndex *pIndex = (LSIndex*)IndexObject.Ptr;
			if (pIndex->GetType() != pNanoSpellType)
				return false;
			Object.DWord = P_CHARACTER->get_spell_template_data()->build_ls_nano_spell_list(pIndex);
			Object.Type = pUintType;
			return true;
		}
		return false;
	}
	case SpecialAction:
	{
		if (IS_INDEX())
		{
			if (IS_NUMBER())
			{
				auto index = DWORD(GET_NUMBER());
				if ((Object.Ptr = P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_special_action_holder()->get_special_action(index - 1)))
				{
					Object.Type = pSpecialActionTemplateType;
					return true;
				}
				return false;
			}
			if ((Object.Ptr = P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_special_action_holder()->get_special_action(argv[0])))
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
		Object.DWord = P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_special_action_holder()->get_special_action_count();
		Object.Type = pUintType;
		break;
	}
	case GetSpecialActions:
	{
		if (IS_INDEX())
		{
			LSOBJECT IndexObject;
			if (!pISInterface->DataParse(argv[0], IndexObject))
				return false;
			if (IndexObject.Type != pIndexType)
				return false;
			LSIndex *pIndex = (LSIndex*)IndexObject.Ptr;
			if (pIndex->GetType() != pSpecialActionTemplateType)
				return false;
			Object.DWord = P_CHARACTER->get_special_action_holder()->build_ls_special_actions(pIndex);
			Object.Type = pUintType;
			return true;
		}
		return false;
	}
	case ToActor:
	{
		Object.Ptr = P_CHARACTER;
		Object.Type = pActorType;
		break;
	}
	default:
		return false;
	}
	return true;
#undef P_CHARACTER
}

bool CharacterType::GetMethod(LSOBJECTDATA& ObjectData, PLSTYPEMETHOD pMethod, int argc, char* argv[])
{
	if (g_game_state != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define P_CHARACTER ((ao::character*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (CharacterTypeMethods(pMethod->ID))
		{
		case Activate:
		{
			isxao::commands::Activate(0, argc, argv);
			break;
		}
		case Cast:
		{
			isxao::commands::Cast(0, argc, argv);
			break;
		}
		case Attack:
		{
			break;
		}
		case Sit:
		{
			P_CHARACTER->sit();
			break;
		}
		case Stand:
		{
			P_CHARACTER->stand();
			break;
		}
		default: break;
		}
#undef P_CHARACTER
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, pMethod->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}


bool CharacterType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (g_game_state != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define P_CHARACTER ((ao::character*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
	sprintf_s(buf, buflen, "%I64u", P_CHARACTER->get_identity().get_combined_identity());
#undef P_CHARACTER

	return true;
}
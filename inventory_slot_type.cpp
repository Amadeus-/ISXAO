#include "isxao_main.h"

bool InventorySlotType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (g_game_state != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define P_INVENTORY_SLOT ((ao::inventory_slot_t*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (InventorySlotTypeMembers(Member->ID))
		{
		case IsReady:
		{
			const bool is_ready = P_INVENTORY_SLOT->is_item_locked();
			Object.DWord = !is_ready;
			Object.Type = pBoolType;
			break;
		}
		case Item:
		{
			if((Object.Ptr = P_INVENTORY_SLOT->p_item))
			{
				Object.Type = pInventoryItemType;
				return true;
			}
			return false;
		}
		case ItemCount:
		{
			Object.DWord = P_INVENTORY_SLOT->get_inv_slot_data()->count;
			Object.Type = pUintType;
			break;
		}
		case LockOutRemaining:
		{
			DWORD a;
			DWORD b;
			double progress = P_INVENTORY_SLOT->get_item_progress(a, b);
			Object.DWord = a;
			Object.Type = pUintType;
			break;
		}
		case Name:
		{
			Object.ConstCharPtr = P_INVENTORY_SLOT->get_slot_name();
			Object.Type = pStringType;
			break;
		}
		case QualityLevel:
		{
			Object.DWord = P_INVENTORY_SLOT->get_inv_slot_data()->quality_level;
			Object.Type = pUintType;
			break;
		}
		case Slot:
		{
			auto id = P_INVENTORY_SLOT->slot_id;
			const auto p_id = static_cast<ao::p_identity_t>(pISInterface->GetTempBuffer(sizeof(ao::identity_t), &id));
			Object.Ptr = p_id;
			Object.Type = pIdentityType;
			break;
		}
		default: break;
		}
#undef P_INVENTORY_SLOT
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool InventorySlotType::GetMethod(LSOBJECTDATA& ObjectData, PLSTYPEMETHOD pMethod, int argc, char* argv[])
{
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define P_INVENTORY_SLOT ((ao::inventory_slot_t*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (InventorySlotTypeMethods(pMethod->ID))
		{
		case Use:
		{
			const ao::identity_t d(0, 0);
			if(P_ENGINE_CLIENT_ANARCHY && P_ENGINE_CLIENT_ANARCHY->get_client_char() && P_ENGINE_CLIENT_ANARCHY->get_item_by_template(P_INVENTORY_SLOT->slot_id, d))
			{
				P_ENGINE_CLIENT_ANARCHY->n3_msg_use_item(P_INVENTORY_SLOT->slot_id, false);
				return true;
			}
			return false;
		}
		default: break;
		}
#undef P_INVENTORY_SLOT
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, pMethod->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool InventorySlotType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (g_game_state != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define P_INVENTORY_SLOT ((ao::inventory_slot_t*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
	sprintf_s(buf, buflen, "%s", P_INVENTORY_SLOT->get_slot_name());
#undef P_INVENTORY_SLOT

	return true;
}
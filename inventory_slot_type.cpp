#include "isxao_main.h"

bool InventorySlotType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pInventorySlot ((INVENTORYSLOT*)ObjectData.Ptr)
		switch (InventorySlotTypeMembers(Member->ID))
		{
		case Name:
		{
			PCHAR pName = { nullptr };
			pInventorySlot->GetSlotName(pName);
			Object.ConstCharPtr = pName;
			Object.Type = pStringType;
			break;
		}
		case Item:
		{
			if((Object.Ptr = pInventorySlot->pItem))
			{
				Object.Type = pInventoryItemType;
				return true;
			}
			return false;
		}
		case Slot:
		{
			IDENTITY id = pInventorySlot->SlotID;
			PIDENTITY pId = static_cast<PIDENTITY>(pISInterface->GetTempBuffer(sizeof(IDENTITY), &id));
			Object.Ptr = pId;
			Object.Type = pIdentityType;
			break;
		}
		default: break;
		}
#undef pInventorySlot
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
#define pInventorySlot ((INVENTORYSLOT*)ObjectData.Ptr)
		switch (InventorySlotTypeMethods(pMethod->ID))
		{
		case Use:
		{
			IDENTITY d;
			ZeroMemory(&d, sizeof(IDENTITY));
			if(pEngineClientAnarchy && pEngineClientAnarchy->GetClientChar() && pEngineClientAnarchy->GetItemByTemplate(pInventorySlot->SlotID, d))
			{
				pEngineClientAnarchy->N3Msg_UseItem(pInventorySlot->SlotID, false);
				return true;
			}
			return false;
		}
		default: break;
		}
#undef pInventorySlot
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, pMethod->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool InventorySlotType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define pInventorySlot ((INVENTORYSLOT*)ObjectData.Ptr)
	PCHAR pName = { nullptr };
	pInventorySlot->GetSlotName(pName);
	sprintf_s(buf, buflen, "%s", pName);
#undef pInventorySlot

	return true;
}
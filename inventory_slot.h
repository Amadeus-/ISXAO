#pragma once

typedef struct _INVENTORYSLOT
{
	IDENTITY SlotID;
	InventoryItem* pItem;


	void GetSlotName(PCHAR pName) const
	{
		switch(SlotID.Type)
		{
		case 101:
		{
			switch(SlotID.Id)
			{
			case 1:
				pName = "WS_HUD1";
				return;
			case 2:
				pName =  "WS_HUD3";
				return;
			case 3:
				pName =  "WS_UTIL1";
				return;
			case 4:
				pName =  "WS_UTIL2";
				return;
			case 5:
				pName =  "WS_UTIL3";
				return;
			case 6:
				pName =  "WS_RHAND";
				return;
			case 7:
				pName =  "WS_BELT";
				return;
			case 8:
				pName =  "WS_LHAND";
				return;
			case 9:
				pName =  "WS_NCU1";
				return;
			case 10:
				pName =  "WS_NCU2";
				return;
			case 11:
				pName =  "WS_NCU3";
				return;
			case 12:
				pName =  "WS_NCU4";
				return;
			case 13:
				pName =  "WS_NCU5";
				return;
			case 14:
				pName =  "WS_NCU6";
				return;
			case 15:
				pName =  "WS_HUD2";
				return;
			default:
				pName =  "Unknown";
				return;
			}
		}			
		case 102:
		{
			switch (SlotID.Id - 16)
			{
			case 1:
				pName =  "AS_NECK";
				return;
			case 2:
				pName =  "AS_HEAD";
				return;
			case 3:
				pName =  "AS_BACK";
				return;
			case 4:
				pName =  "AS_RSHOULDER";
				return;
			case 5:
				pName =  "AS_CHEST";
				return;
			case 6:
				pName =  "AS_LSHOULDER";
				return;
			case 7:
				pName =  "AS_RARM";
				return;
			case 8:
				pName =  "AS_HANDS";
				return;
			case 9:
				pName =  "AS_LARM";
				return;
			case 10:
				pName =  "AS_RWRIST";
				return;
			case 11:
				pName =  "AS_LEGS";
				return;
			case 12:
				pName =  "AS_LWRIST";
				return;
			case 13:
				pName =  "AS_RFINGER";
				return;
			case 14:
				pName =  "AS_FEET";
				return;
			case 15:
				pName =  "AS_LFINGER";
				return;
			default:
				pName =  "Unknown";
				return;
			}
		}
		case 103:
		{
			switch (SlotID.Id - 32)
			{
			case 1:
				pName =  "IS_EYES";
				return;
			case 2:
				pName =  "IS_HEAD";
				return;
			case 3:
				pName =  "IS_EARS";
				return;
			case 4:
				pName =  "IS_RARM";
				return;
			case 5:
				pName =  "IS_CHEST";
				return;
			case 6:
				pName =  "IS_LARM";
				return;
			case 7:
				pName =  "IS_RWRIST";
				return;
			case 8:
				pName =  "IS_WAIST";
				return;
			case 9:
				pName =  "IS_LWRIST";
				return;
			case 10:
				pName =  "IS_RHAND";
				return;
			case 11:
				pName =  "IS_LEGS";
				return;
			case 12:
				pName =  "IS_LHAND";
				return;
			case 13:
				pName =  "IS_FEET";
				return;
			default:
				pName =  "Unknown";
				return;
			}
		}
		case 104:
		{
			sprintf_s(pName, MAX_STRING, "GI_%d", SlotID.Id);
			return;
		}
		default:
			break;
		}
		pName = "Unknown";
	}

} INVENTORYSLOT, *PINVENTORYSLOT;
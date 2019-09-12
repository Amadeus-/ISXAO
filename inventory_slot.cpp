#include "isxao_main.h"

namespace isxao_classes
{

	PCSTR inventory_slot::get_slot_name() const
	{
		switch (slot_id.type)
		{
		case 101:
		{
			switch (slot_id.id)
			{
			case 1:
				return "WS_HUD1";
			case 2:
				return "WS_HUD3";
			case 3:
				return "WS_UTIL1";
			case 4:
				return "WS_UTIL2";
			case 5:
				return "WS_UTIL3";
			case 6:
				return "WS_RHAND";
			case 7:
				return "WS_BELT";
			case 8:
				return "WS_LHAND";
			case 9:
				return "WS_NCU1";
			case 10:
				return "WS_NCU2";
			case 11:
				return "WS_NCU3";
			case 12:
				return "WS_NCU4";
			case 13:
				return "WS_NCU5";
			case 14:
				return "WS_NCU6";
			case 15:
				return "WS_HUD2";
			default:
				return "Unknown";
			}
		}
		case 102:
		{
			switch (slot_id.id - 16)
			{
			case 1:
				return "AS_NECK";
			case 2:
				return "AS_HEAD";
			case 3:
				return "AS_BACK";
			case 4:
				return "AS_RSHOULDER";
			case 5:
				return "AS_CHEST";
			case 6:
				return "AS_LSHOULDER";
			case 7:
				return "AS_RARM";
			case 8:
				return "AS_HANDS";
			case 9:
				return "AS_LARM";
			case 10:
				return "AS_RWRIST";
			case 11:
				return "AS_LEGS";
			case 12:
				return "AS_LWRIST";
			case 13:
				return "AS_RFINGER";
			case 14:
				return "AS_FEET";
			case 15:
				return "AS_LFINGER";
			default:
				return "Unknown";
			}
		}
		case 103:
		{
			switch (slot_id.id - 32)
			{
			case 1:
				return "IS_EYES";
			case 2:
				return "IS_HEAD";
			case 3:
				return "IS_EARS";
			case 4:
				return "IS_RARM";
			case 5:
				return "IS_CHEST";
			case 6:
				return "IS_LARM";
			case 7:
				return "IS_RWRIST";
			case 8:
				return "IS_WAIST";
			case 9:
				return "IS_LWRIST";
			case 10:
				return "IS_RHAND";
			case 11:
				return "IS_LEGS";
			case 12:
				return "IS_LHAND";
			case 13:
				return "IS_FEET";
			default:
				return "Unknown";
			}
		}
		case 104:
		{
			switch (slot_id.id - 63)
			{
			case 1:
				return "GI_64";
			case 2:
				return "GI_65";
			case 3:
				return "GI_66";
			case 4:
				return "GI_67";
			case 5:
				return "GI_68";
			case 6:
				return "GI_69";
			case 7:
				return "GI_70";
			case 8:
				return "GI_71";
			case 9:
				return "GI_72";
			case 10:
				return "GI_73";
			case 11:
				return "GI_74";
			case 12:
				return "GI_75";
			case 13:
				return "GI_76";
			case 14:
				return "GI_77";
			case 15:
				return "GI_78";
			case 16:
				return "GI_79";
			case 17:
				return "GI_80";
			case 18:
				return "GI_81";
			case 19:
				return "GI_82";
			case 20:
				return "GI_83";
			case 21:
				return "GI_84";
			case 22:
				return "GI_85";
			case 23:
				return "GI_86";
			case 24:
				return "GI_87";
			case 25:
				return "GI_88";
			case 26:
				return "GI_89";
			case 27:
				return "GI_90";
			case 28:
				return "GI_91";
			case 29:
				return "GI_92";
			case 30:
				return "GI_93";
			default: 
				return "Unknown";
			}
		}
		default:
			break;
		}
		return "Unknown";
	}

	p_inventory_data_t inventory_slot::get_inv_slot_data()
	{
		return GetInvSlotData(this);
	}

	double inventory_slot::get_item_progress(DWORD& a, DWORD& b) const
	{
		return P_ENGINE_CLIENT_ANARCHY->n3_msg_get_item_progress(slot_id, a, b);
	}

	bool inventory_slot::is_item_locked() const
	{
		const identity_t d(0, 0);
		return P_ENGINE_CLIENT_ANARCHY->N3Msg_IsItemDisabled(slot_id, d);
	}

}
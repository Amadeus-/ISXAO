#include "isxao_main.h"

namespace isxao_classes
{

	identity_t InventoryData::GetDynelId() const
	{
		return GetInventoryDataData().dynel_identity;
	}

	inventory_data_t InventoryData::GetInventoryDataData() const
	{
		return inventory_data_;
	}

	DWORD InventoryData::GetItemCount() const
	{
		return GetInventoryDataData().count;
	}

	rdb_identity_t InventoryData::GetRDBIdentity() const
	{
		return GetInventoryDataData().rdb_identity;
	}

	DWORD InventoryData::GetQualityLevel() const
	{
		return GetInventoryDataData().quality_level;
	}


}
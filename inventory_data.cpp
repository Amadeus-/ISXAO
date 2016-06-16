#include "isxao_main.h"

namespace isxao_classes
{

	IDENTITY InventoryData::GetDynelId() const
	{
		return GetInventoryDataData().DynelIdentity;
	}

	INVENTORYDATA InventoryData::GetInventoryDataData() const
	{
		return inventory_data_;
	}

	DWORD InventoryData::GetItemCount() const
	{
		return GetInventoryDataData().Count;
	}

	RDBIDENTITY InventoryData::GetRDBIdentity() const
	{
		return GetInventoryDataData().RDBIdentity;
	}

}
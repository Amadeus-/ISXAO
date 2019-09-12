#include "isxao_main.h"

namespace isxao_classes
{

	identity_t inventory_data::get_dynel_id() const
	{
		return get_inventory_data_data().dynel_identity;
	}

	inventory_data_t inventory_data::get_inventory_data_data() const
	{
		return inventory_data_;
	}

	DWORD inventory_data::get_item_count() const
	{
		return get_inventory_data_data().count;
	}

	rdb_identity_t inventory_data::get_rdb_identity() const
	{
		return get_inventory_data_data().rdb_identity;
	}

	DWORD inventory_data::get_quality_level() const
	{
		return get_inventory_data_data().quality_level;
	}


}
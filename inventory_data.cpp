#include "isxao_main.h"
#include "inventory_data.h"

namespace ao
{

	identity_t inventory_data::get_dynel_id()
	{
		return get_data()->dynel_identity;
	}

	unsigned long inventory_data::get_item_count()
	{
		return get_data()->count;
	}

	rdb_identity_t inventory_data::get_rdb_identity()
	{
		return get_data()->rdb_identity;
	}

	DWORD inventory_data::get_quality_level()
	{
		return get_data()->quality_level;
	}

}
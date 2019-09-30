#include "isxao_main.h"
#include "dummy_item_base.h"

namespace ao
{

	const char* dummy_item_base::get_description()
	{
		return get_data()->description;
	}

	identity_t dummy_item_base::get_identity()
	{
		return get_data()->identity;
	}

	identity_t dummy_item_base::get_parent_identity()
	{
		return get_data()->parent_identity;
	}

	PCSTR dummy_item_base::get_name()
	{
		return get_data()->name;
	}

}


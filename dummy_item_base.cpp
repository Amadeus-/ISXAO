#include "isxao_main.h"

namespace ao
{

	PVOID dummy_item_base::get_data()
	{
		return &dummy_item_base_;
	}

	p_dummy_item_base_t dummy_item_base::get_dummy_item_base_data()
	{
		return p_dummy_item_base_t(get_data());
	}

	PCSTR dummy_item_base::get_description()
	{
		return get_dummy_item_base_data()->description;
	}

	identity_t dummy_item_base::get_identity()
	{
		return get_dummy_item_base_data()->identity;
	}

	identity_t dummy_item_base::get_parent_identity()
	{
		return get_dummy_item_base_data()->parent_identity;
	}

	PCSTR dummy_item_base::get_name()
	{
		return get_dummy_item_base_data()->name;
	}

}


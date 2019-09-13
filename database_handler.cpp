#include "isxao_main.h"

namespace isxao_classes
{

	ResourceDatabase* database_handler::get_resource_database() const
	{
		return reinterpret_cast<ResourceDatabase*>(n3_database_handler_.p_resource_database);
	}

}

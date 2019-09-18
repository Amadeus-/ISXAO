#include "isxao_main.h"

namespace ao
{
	resource_database* database_handler::get_resource_database() const
	{
		return reinterpret_cast<resource_database*>(n3_database_handler_.p_resource_database);
	}

}

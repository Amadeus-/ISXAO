#include "isxao_main.h"
#include "database_handler.h"

namespace ao
{
#if false
	static_assert(false, "database_handler::get_resource_database() does not have a native function.");
#else
	resource_database* database_handler::get_resource_database()
	{
		return reinterpret_cast<resource_database*>(this->get_data()->p_resource_database);
	}
#endif
}

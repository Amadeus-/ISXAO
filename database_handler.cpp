#include "isxao_main.h"

namespace isxao_classes
{

	ResourceDatabase* DatabaseHandler::GetResourceDatabase() const
	{
		return reinterpret_cast<ResourceDatabase*>(n3_database_handler_.pResourceDatabase);
	}

}

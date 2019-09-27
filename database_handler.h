#pragma once
#include "game_object.h"

namespace ao
{
	class resource_database;
	
	class database_handler : public game_object<ao::n3_database_handler_t>
	{
	public:
		ao::resource_database* get_resource_database();
	};
}
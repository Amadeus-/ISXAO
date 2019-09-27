#pragma once
#include "game_object.h"

namespace ao
{
	struct ao_resource_database;
	typedef ao_resource_database resource_database_t, *p_resource_database_t;

	struct ao_db_object;
	typedef ao_db_object db_object_t, *p_db_object_t;

	struct ao_identity;
	typedef ao_identity identity_t, *p_identity_t;

	class resource_database : game_object<ao::resource_database_t>
	{
	public:
		ao::p_db_object_t get_db_object(const ao::identity_t&);
	};
}
#include "isxao_main.h"
#include "team_entry.h"

namespace ao
{

	identity_t team_entry::get_identity()
	{
		return get_data()->identity;
	}

	PCSTR team_entry::get_name()
	{
		return get_data()->name.c_str();
	}

}
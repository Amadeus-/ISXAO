#include "isxao_main.h"

namespace ao
{

	identity_t team_entry::get_identity() const
	{
		return get_team_entry_data().identity;
	}

	PCSTR team_entry::get_name() const
	{
		return get_team_entry_data().name.c_str();
	}

	team_entry_t team_entry::get_team_entry_data() const
	{
		return team_entry_;
	}

}
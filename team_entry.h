#pragma once
#include "game_object.h"

namespace ao
{
	struct ao_identity;
	struct ao_team_entry;

	typedef ao_identity identity_t, *p_identity_t;
	typedef ao_team_entry team_entry_t, *p_team_entry_t;

	class team_entry : public game_object<team_entry_t>
	{
	public:
		const char* get_name();
		identity_t get_identity();
	};
}

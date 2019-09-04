#include "isxao_main.h"

namespace isxao_classes
{

	identity_t TeamEntry::GetIdentity() const
	{
		return GetTeamEntryData().identity;
	}

	PCSTR TeamEntry::GetName() const
	{
		return GetTeamEntryData().name.c_str();
	}

	team_entry_t TeamEntry::GetTeamEntryData() const
	{
		return team_entry_;
	}

}
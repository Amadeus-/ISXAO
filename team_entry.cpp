#include "isxao_main.h"

namespace isxao_classes
{

	identity_t TeamEntry::GetIdentity() const
	{
		return GetTeamEntryData().Identity;
	}

	PCSTR TeamEntry::GetName() const
	{
		return GetTeamEntryData().Name.c_str();
	}

	TEAMENTRY TeamEntry::GetTeamEntryData() const
	{
		return team_entry_;
	}

}
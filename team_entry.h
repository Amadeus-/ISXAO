#pragma once

class TeamEntry
{
public:
	AOLIB_OBJECT PCSTR GetName() const;
	AOLIB_OBJECT identity_t GetIdentity() const;
	AOLIB_OBJECT team_entry_t GetTeamEntryData() const;
private:
	team_entry_t team_entry_;
};
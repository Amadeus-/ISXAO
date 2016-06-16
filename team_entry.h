#pragma once

class TeamEntry
{
public:
	AOLIB_OBJECT PCSTR GetName() const;
	AOLIB_OBJECT IDENTITY GetIdentity() const;
	AOLIB_OBJECT TEAMENTRY GetTeamEntryData() const;
private:
	TEAMENTRY team_entry_;
};
#pragma once

class TeamRaid
{
public:
	AOLIB_OBJECT DWORD BuildLSTeam(LSIndex*) const;
	AOLIB_OBJECT DWORD BuildLSRaid(LSIndex*) const;
	static
	AOLIB_OBJECT void CreateRaid();
	AOLIB_OBJECT TeamEntry* GetTeamLeader() const;
	AOLIB_OBJECT DWORD GetRaid(std::vector<TeamEntry*>&) const;
	AOLIB_OBJECT DWORD GetRaidCount() const;
	AOLIB_OBJECT TeamEntry* GetRaidMember(DWORD) const;
	AOLIB_OBJECT TeamEntry* GetRaidMember(PCSTR) const;
	AOLIB_OBJECT DWORD GetTeam(std::vector<TeamEntry*>&) const;
	AOLIB_OBJECT DWORD GetTeam(std::vector<TeamEntry*>&, DWORD) const;
	AOLIB_OBJECT DWORD GetTeamCount() const;
	AOLIB_OBJECT TeamEntry* GetTeamMember(DWORD) const;
	AOLIB_OBJECT TeamEntry* GetTeamMember(PCSTR) const;
	AOLIB_OBJECT IDENTITY GetTeamIdentity() const;
	AOLIB_OBJECT IDENTITY GetTeamLeaderID() const;
	AOLIB_OBJECT TEAMRAIDHOLDER GetTeamRaidData() const;
	AOLIB_OBJECT DWORD GetTeamRaidIndex() const;
	AOLIB_OBJECT bool IsRaid() const;
private:
	TEAMRAIDHOLDER team_raid_holder_;
};
#pragma once

class TeamRaid
{
public:
	AOLIB_OBJECT DWORD BuildLSTeam(LSIndex*) const;
	AOLIB_OBJECT DWORD BuildLSRaid(LSIndex*) const;
	static
	AOLIB_OBJECT void CreateRaid();
	AOLIB_OBJECT team_entry* GetTeamLeader() const;
	AOLIB_OBJECT DWORD GetRaid(std::vector<team_entry*>&) const;
	AOLIB_OBJECT DWORD GetRaidCount() const;
	AOLIB_OBJECT team_entry* GetRaidMember(DWORD) const;
	AOLIB_OBJECT team_entry* GetRaidMember(PCSTR) const;
	AOLIB_OBJECT DWORD GetTeam(std::vector<team_entry*>&) const;
	AOLIB_OBJECT DWORD GetTeam(std::vector<team_entry*>&, DWORD) const;
	AOLIB_OBJECT DWORD GetTeamCount() const;
	AOLIB_OBJECT team_entry* GetTeamMember(DWORD) const;
	AOLIB_OBJECT team_entry* GetTeamMember(PCSTR) const;
	AOLIB_OBJECT identity_t GetTeamIdentity() const;
	AOLIB_OBJECT identity_t GetTeamLeaderID() const;
	AOLIB_OBJECT team_raid_holder_t GetTeamRaidData() const;
	AOLIB_OBJECT DWORD GetTeamRaidIndex() const;
	AOLIB_OBJECT bool IsRaid() const;
private:
	team_raid_holder_t team_raid_holder_;
};
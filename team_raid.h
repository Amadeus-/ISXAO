#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class team_raid
{
public:
	DWORD build_ls_team(LSIndex*) const;
	DWORD build_ls_raid(LSIndex*) const;
	static void create_raid();
	ao::team_entry* get_team_leader() const;
	DWORD get_raid(std::vector<ao::team_entry*>&) const;
	DWORD get_raid_count() const;
	ao::team_entry* get_raid_member(DWORD) const;
	ao::team_entry* get_raid_member(PCSTR) const;
	DWORD get_team(std::vector<ao::team_entry*>&) const;
	DWORD get_team(std::vector<ao::team_entry*>&, DWORD) const;
	DWORD get_team_count() const;
	ao::team_entry* get_team_member(DWORD) const;
	ao::team_entry* get_team_member(PCSTR) const;
	ao::identity_t get_team_identity() const;
	ao::identity_t get_team_leader_id() const;
	ao::team_raid_holder_t get_team_raid_data() const;
	DWORD get_team_raid_index() const;
	bool is_raid() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::team_raid_holder_t team_raid_holder_;
};
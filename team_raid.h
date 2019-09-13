#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class team_raid
{
public:
	AOLIB_OBJECT DWORD build_ls_team(LSIndex*) const;
	AOLIB_OBJECT DWORD build_ls_raid(LSIndex*) const;
	AOLIB_OBJECT static void create_raid();
	AOLIB_OBJECT team_entry* get_team_leader() const;
	AOLIB_OBJECT DWORD get_raid(std::vector<team_entry*>&) const;
	AOLIB_OBJECT DWORD get_raid_count() const;
	AOLIB_OBJECT team_entry* get_raid_member(DWORD) const;
	AOLIB_OBJECT team_entry* get_raid_member(PCSTR) const;
	AOLIB_OBJECT DWORD get_team(vector<team_entry*>&) const;
	AOLIB_OBJECT DWORD get_team(vector<team_entry*>&, DWORD) const;
	AOLIB_OBJECT DWORD get_team_count() const;
	AOLIB_OBJECT team_entry* get_team_member(DWORD) const;
	AOLIB_OBJECT team_entry* get_team_member(PCSTR) const;
	AOLIB_OBJECT identity_t get_team_identity() const;
	AOLIB_OBJECT identity_t get_team_leader_id() const;
	AOLIB_OBJECT team_raid_holder_t get_team_raid_data() const;
	AOLIB_OBJECT DWORD get_team_raid_index() const;
	AOLIB_OBJECT bool is_raid() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	team_raid_holder_t team_raid_holder_;
};
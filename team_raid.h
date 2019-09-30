#pragma once
#include "game_object.h"

// ReSharper disable once CppInconsistentNaming
class LSIndex;

namespace std
{
	template <typename _Tp, typename _Alloc>
	class list;
	template <typename _Key, typename _Tp, typename _Compare, typename _Alloc>
	class map;
	template <typename _Tp, typename _Alloc>
	class vector;
}

namespace ao
{
	class team_entry;

	struct ao_identity;
	struct ao_team_raid_holder;

	typedef ao_identity identity_t, *p_identity_t;
	typedef ao_team_raid_holder team_raid_holder_t, *p_team_raid_holder_t;

	class team_raid : public game_object<team_raid_holder_t>
	{
	public:
		unsigned long build_ls_team(LSIndex*);
		unsigned long build_ls_raid(LSIndex*);
		static void create_raid();
		team_entry* get_team_leader();
		unsigned long get_raid(std::vector<team_entry*>&);
		unsigned long get_raid_count();
		team_entry* get_raid_member(unsigned long);
		team_entry* get_raid_member(const char*);
		unsigned long get_team(std::vector<team_entry*>&);
		unsigned long get_team(std::vector<team_entry*>&, unsigned long);
		unsigned long get_team_count();
		team_entry* get_team_member(unsigned long);
		team_entry* get_team_member(const char*);
		identity_t get_team_identity();
		identity_t get_team_leader_id();
		unsigned long get_team_raid_index();
		bool is_raid();
	};
}

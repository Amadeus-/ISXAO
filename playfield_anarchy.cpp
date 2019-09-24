#include "isxao_main.h"

namespace ao
{

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(void playfield_anarchy::debug_draw_pathfinder(), n3_playfield_t__debug_draw_pathfinder)
#else
	static_assert(false, "playfield_anarchy::debug_draw_pathfinder() requires a native function.");
#endif

	LONG playfield_anarchy::get_pf_world_x_pos() const
	{
		return playfield_anarchy_.pf_world_x_pos;
	}

	LONG playfield_anarchy::get_pf_world_z_pos() const
	{
		return playfield_anarchy_.pf_world_z_pos;
	}

	DWORD playfield_anarchy::get_playfield_actors(std::vector<actor*> &v)
	{
		for (auto it = playfield_anarchy_.p_dynel_children.begin(); it != playfield_anarchy_.p_dynel_children.end(); ++it)  // NOLINT(modernize-loop-convert)
		{
			if ((*it)->identity.type == 50000)
				v.push_back(reinterpret_cast<actor*>(*it));
		}
		std::sort(v.begin(), v.end(), dynel::p_dynel_compare);
		return v.size();
	}

	playfield_anarchy_t playfield_anarchy::get_playfield_data() const
	{
		return playfield_anarchy_;
	}

	DWORD playfield_anarchy::get_playfield_instance() const
	{
		return playfield_anarchy_.instance_id.id;
	}

	PCSTR playfield_anarchy::get_playfield_name() const
	{
		return playfield_anarchy_.p_rdb_playfield->name;
	}

	float playfield_anarchy::get_size_x() const
	{
		return playfield_anarchy_.p_n3_tile_map->p_rdb_tile_map->map_size_multiplier * playfield_anarchy_.p_n3_tile_map->p_rdb_tile_map->width;
	}

	float playfield_anarchy::get_size_z() const
	{
		return playfield_anarchy_.p_n3_tile_map->p_rdb_tile_map->map_size_multiplier * playfield_anarchy_.p_n3_tile_map->p_rdb_tile_map->height;
	}

	bool playfield_anarchy::is_dungeon() const
	{
		return playfield_anarchy_.p_n3_tile_map->p_rdb_tile_map->is_dungeon == 1;
	}

	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(bool playfield_anarchy::line_of_sight(const vector3_t &, const vector3_t &, int, bool), n3_playfield_t__line_of_sight);

	p_grid_space_t playfield_anarchy::get_grid_space() const
	{
		return playfield_anarchy_.p_space_i;
	}

	p_n3_tile_map_surface_t playfield_anarchy::get_tile_map_surface() const
	{
		return playfield_anarchy_.p_surface_i;
	}

#pragma endregion

#pragma region playfield_dir

	playfield_anarchy* playfield_dir::get_playfield() const
	{
		return reinterpret_cast<playfield_anarchy*>(playfield_dir_.p_root->p_node->value);
	}

#pragma endregion

}


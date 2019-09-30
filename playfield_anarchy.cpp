#include "isxao_main.h"
#include "playfield_anarchy.h"

namespace ao
{
#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void playfield_anarchy::debug_draw_pathfinder(), n3_playfield_t__debug_draw_pathfinder)
#else
	static_assert(false, "playfield_anarchy::debug_draw_pathfinder() requires a native function.");
#endif

	long playfield_anarchy::get_pf_world_x_pos()
	{
		return get_data()->pf_world_x_pos;
	}

	long playfield_anarchy::get_pf_world_z_pos()
	{
		return get_data()->pf_world_z_pos;
	}

	unsigned long playfield_anarchy::get_playfield_actors(std::vector<actor*> &v)
	{
		for (auto it = get_data()->p_dynel_children.begin(); it != get_data()->p_dynel_children.end(); ++it)  // NOLINT(modernize-loop-convert)
		{
			if ((*it)->identity.type == 50000)
				v.push_back(reinterpret_cast<actor*>(*it));
		}
		std::sort(v.begin(), v.end(), dynel::p_dynel_compare);
		return v.size();
	}

	unsigned long playfield_anarchy::get_playfield_instance()
	{
		return get_data()->instance_id.id;
	}

	const char* playfield_anarchy::get_playfield_name()
	{
		return get_data()->p_rdb_playfield->name;
	}

	float playfield_anarchy::get_size_x()
	{
		return get_data()->p_n3_tile_map->p_rdb_tile_map->map_size_multiplier * get_data()->p_n3_tile_map->p_rdb_tile_map->width;
	}

	float playfield_anarchy::get_size_z()
	{
		return get_data()->p_n3_tile_map->p_rdb_tile_map->map_size_multiplier * get_data()->p_n3_tile_map->p_rdb_tile_map->height;
	}

	bool playfield_anarchy::is_dungeon()
	{
		return get_data()->p_n3_tile_map->p_rdb_tile_map->is_dungeon == 1;
	}

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool playfield_anarchy::line_of_sight(const vector3_t &, const vector3_t &, int, bool), n3_playfield_t__line_of_sight)
#else
	static_assert(false, "playfield_anarchy::line_of_sight(const vector3_t &, const vector3_t &, int, bool) requires a native function.");
#endif

	p_grid_space_t playfield_anarchy::get_grid_space()
	{
		return get_data()->p_space_i;
	}

	p_n3_tile_map_surface_t playfield_anarchy::get_tile_map_surface()
	{
		return get_data()->p_surface_i;
	}

#pragma endregion

#pragma region playfield_dir

	playfield_anarchy* playfield_dir::get_playfield()
	{
		return reinterpret_cast<playfield_anarchy*>(get_data()->p_root->p_node->value);
	}

#pragma endregion

}
#include "isxao_main.h"

namespace isxao_classes
{

	LONG PlayfieldAnarchy::GetPFWorldXPos() const
	{
		return playfield_anarchy_.pf_world_x_pos;
	}

	LONG PlayfieldAnarchy::GetPFWorldZPos() const
	{
		return playfield_anarchy_.pf_world_z_pos;
	}

	DWORD PlayfieldAnarchy::GetPlayfieldActors(std::vector<Actor*> &v)
	{
		for (auto it = playfield_anarchy_.p_dynel_children.begin(); it != playfield_anarchy_.p_dynel_children.end(); ++it)
		{
			if ((*it)->identity.type == 50000)
				v.push_back(reinterpret_cast<Actor*>(*it));
		}
		std::sort(v.begin(), v.end(), dynel::p_dynel_compare);
		return v.size();
	}

	playfield_anarchy_t PlayfieldAnarchy::GetPlayfieldData() const
	{
		return playfield_anarchy_;
	}

	DWORD PlayfieldAnarchy::GetPlayfieldInstance() const
	{
		return playfield_anarchy_.instance_id.id;
	}

	PCSTR PlayfieldAnarchy::GetPlayfieldName() const
	{
		return playfield_anarchy_.p_rdb_playfield->name;
	}

	float PlayfieldAnarchy::GetSizeX() const
	{
		return playfield_anarchy_.p_n3_tile_map->p_rdb_tile_map->map_size_multiplier * playfield_anarchy_.p_n3_tile_map->p_rdb_tile_map->width;
	}

	float PlayfieldAnarchy::GetSizeZ() const
	{
		return playfield_anarchy_.p_n3_tile_map->p_rdb_tile_map->map_size_multiplier * playfield_anarchy_.p_n3_tile_map->p_rdb_tile_map->height;
	}

	bool PlayfieldAnarchy::IsDungeon() const
	{
		return playfield_anarchy_.p_n3_tile_map->p_rdb_tile_map->is_dungeon == 1;
	}

	FUNCTION_AT_ADDRESS(bool PlayfieldAnarchy::LineOfSight(const vector3_t &, const vector3_t &, int, bool), n3_playfield_t__line_of_sight);

	p_grid_space_t PlayfieldAnarchy::GetGridSpace() const
	{
		return playfield_anarchy_.p_space_i;
	}

	p_n3_tile_map_surface_t PlayfieldAnarchy::GetTilemapSurface() const
	{
		return playfield_anarchy_.p_surface_i;
	}


#pragma endregion

#pragma region PlayfieldDir

	PlayfieldAnarchy* PlayfieldDir::GetPlayfield() const
	{
		return reinterpret_cast<PlayfieldAnarchy*>(playfield_dir_.p_root->p_node->p_playfield);
	}

#pragma endregion

}


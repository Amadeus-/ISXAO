#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class playfield_anarchy
{
public:
	void debug_draw_pathfinder();
	LONG get_pf_world_x_pos() const;
	LONG get_pf_world_z_pos() const;
	DWORD get_playfield_actors(std::vector<ao::actor*> &v);
	ao::playfield_anarchy_t get_playfield_data() const;
	DWORD get_playfield_instance() const;
	PCSTR get_playfield_name() const;
	float get_size_x() const;
	float get_size_z() const;
	bool is_dungeon() const;
	bool line_of_sight(const ao::vector3_t &, const ao::vector3_t &, int, bool);
	ao::p_grid_space_t get_grid_space() const;
	ao::p_n3_tile_map_surface_t get_tile_map_surface() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::playfield_anarchy_t playfield_anarchy_;
};

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class playfield_dir
{
public:
	playfield_anarchy* get_playfield() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::playfield_dir_t playfield_dir_;
};

#pragma once
#include "game_object.h"

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
	class actor;
	class cell_surface;
	class surface_i;

	struct ao_grid_space;
	struct ao_n3_tile_map_surface;
	template <typename T, typename U>
	struct ao_map;

	struct ao_playfield_anarchy;
	struct ao_vector3;

	typedef ao_grid_space grid_space_t, *p_grid_space_t;
	typedef ao_n3_tile_map_surface n3_tile_map_surface_t, *p_n3_tile_map_surface_t;
	typedef ao_map<unsigned long, struct ao_playfield_anarchy*> playfield_dir_t, *p_playfield_dir_t;
	typedef ao_playfield_anarchy playfield_anarchy_t, *p_playfield_anarchy_t;
	typedef ao_vector3 vector3_t, *p_vector3_t;

	class playfield_anarchy : game_object<playfield_anarchy_t>
	{
	public:
		void debug_draw_pathfinder();
		long get_pf_world_x_pos();
		long get_pf_world_z_pos();
		unsigned long get_playfield_actors(std::vector<ao::actor*> &v);
		unsigned long get_playfield_instance();
		const char* get_playfield_name();
		float get_size_x();
		float get_size_z();
		bool is_dungeon();
		bool line_of_sight(const ao::vector3_t &, const ao::vector3_t &, int, bool);
		ao::p_grid_space_t get_grid_space();
		ao::p_n3_tile_map_surface_t get_tile_map_surface();
		cell_surface* get_cell_surface();
		surface_i* get_surface();
	};

	class playfield_dir : public game_object<playfield_dir_t>
	{
	public:
		playfield_anarchy* get_playfield();
	};
}
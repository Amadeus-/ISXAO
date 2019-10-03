#pragma once
#ifndef _CELL_SURFACE_H
#define _CELL_SURFACE_H
#include "game_object.h"

namespace ao
{
	struct ao_cell_surface;
	struct ao_vector3;

	typedef ao_cell_surface cell_surface_t, *p_cell_surface_t;
	typedef ao_vector3 vector3_t, *p_vector3_t;

	class cell_surface : game_object<cell_surface_t>
	{
	public:
		unsigned long get_all_triangles(std::vector<ao::vector3_t>&);
		unsigned long get_line_intersection(const vector3_t& a, const vector3_t& b, vector3_t& point_of_intersection, vector3_t& normal_at_intersection, bool, const void* locality_source);
		unsigned long get_line_intersection(const vector3_t&, const vector3_t&, vector3_t&, bool, const void*);
	};
}
#endif
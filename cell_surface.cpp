#include "isxao_main.h"
#include "cell_surface.h"

namespace ao
{

#if true
	FUNCTION_AT_ADDRESS(unsigned long cell_surface::get_all_triangles(std::vector<vector3_t>& v), cell_surface_t__get_all_triangles)
#else
	static_assert(false, "cell_surface::get_all_triangles(std::vector<vector3_t>& v) requires a native function.");
#endif

#if true
	FUNCTION_AT_ADDRESS(unsigned long cell_surface::get_line_intersection(const vector3_t&, const vector3_t&, vector3_t&, vector3_t&, bool, const void*), cell_surface_t__get_line_intersection_1)
#else
	static_assert(false, "cell_surface::get_line_intersection(const vector3_t&, const vector3_t&, vector3_t&, vector3_t&, bool, const void*) requires a native function.");
#endif

#if true
	FUNCTION_AT_ADDRESS(unsigned long cell_surface::get_line_intersection(const vector3_t&, const vector3_t&, vector3_t&, bool, const void*), cell_surface_t__get_line_intersection_2)
#else
	static_assert(false, "get_line_intersection(vector3_t&, vector3_t&, vector3_t&, bool, void*) requires a native function.");
#endif
}
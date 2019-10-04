#include "isxao_main.h"
#include "surface_i.h"

namespace ao
{
#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_VIRTUAL_ADDRESS(void surface_i::calculate_closest_point(const vector3_t&, vector3_t&, vector3_t&, void*, void*), 0x4)
#else
	static_assert(false, "surface_i::calculate_closest_point(const vector3_t&, vector3_t&, vector3_t&, void*, void*) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_VIRTUAL_ADDRESS(void surface_i::calculate_normal(const vector3_t&, vector3_t&), 0x8)
#else
	static_assert(false, "surface_i::calculate_closest_point(const vector3_t&, vector3_t&, vector3_t&, void*, void*) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_VIRTUAL_ADDRESS(bool surface_i::get_line_intersection(const vector3_t& a, const vector3_t& b, vector3_t& point_of_intersection, bool, const void* locality_source), 0xC)
#else
	static_assert(false, "surface_i::get_line_intersection(const vector3_t& a, const vector3_t& b, vector3_t& point_of_intersection, bool, const void* locality_source) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_VIRTUAL_ADDRESS(bool surface_i::get_line_intersection(const vector3_t& a, const vector3_t& b, vector3_t& point_of_intersection, vector3_t& normal_at_intersection, bool, const void* locality_source), 0x10)
#else
	static_assert(false, "surface_i::get_line_intersection(const vector3_t& a, const vector3_t& b, vector3_t& point_of_intersection, vector3_t& normal_at_intersection, bool, const void* locality_source) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_VIRTUAL_ADDRESS(bool surface_i::get_sphere_intersection(const vector3_t&, float, vector3_t&), 0x14)
#else
	static_assert(false, "surface_i::get_line_intersection(const vector3_t& a, const vector3_t& b, vector3_t& point_of_intersection, vector3_t& normal_at_intersection, bool, const void* locality_source) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_VIRTUAL_ADDRESS(bool surface_i::get_sphere_intersection(const vector3_t&, float, vector3_t&, vector3_t&, float&), 0x18)
#else
	static_assert(false, "surface_i::get_line_intersection(const vector3_t& a, const vector3_t& b, vector3_t& point_of_intersection, vector3_t& normal_at_intersection, bool, const void* locality_source) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_VIRTUAL_ADDRESS(bool surface_i::is_inside(const vector3_t&, void*), 0x1C)
#else
	static_assert(false, "surface_i::is_inside(const vector3_t&, void*) requires a native function.");
#endif

}
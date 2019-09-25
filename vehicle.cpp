#include "isxao_main.h"

namespace ao
{

	p_char_movement_status_t vehicle::get_char_movement_status()
	{
		return get_char_vehicle_data()->p_char_movement_status;
	}

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void vehicle::set_rotation(const quaternion_t &), vehicle_t__set_rel_rot)
#else
	static_assert(false, "vehicle::set_rotation(const quaternion_t &) requires a native function.");
#endif

	PVOID vehicle::get_data()
	{
		return &char_vehicle_;
	}

	vector3_t vehicle::get_velocity()
	{
		return get_char_vehicle_data()->velocity;
	}

	DWORD vehicle::get_zone_instance_id()
	{
		return get_char_vehicle_data()->zone_instance_id;
	}

	p_char_vehicle_t vehicle::get_char_vehicle_data()
	{
		return p_char_vehicle_t(get_data());
	}

	float vehicle::get_max_speed()
	{
		return get_char_vehicle_data()->max_speed;
	}

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(int vehicle::steering_direction_arrive(const ao::vector3_t&, ao::vector3_t&), vehicle_t__steering_dir_arrive)
#else
	static_assert(false, "vehicle::set_rotation(const quaternion_t &) requires a native function.");
#endif

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(int vehicle::steering_flee(const ao::vector3_t&, ao::vector3_t&), vehicle_t__steering_flee)
#else
	static_assert(false, "vehicle::steering_flee(const ao::vector3_t&, ao::vector3_t&) requires a native function.");
#endif

}
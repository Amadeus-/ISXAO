#include "isxao_main.h"

namespace isxao_classes
{

	p_char_movement_status_t vehicle::get_char_movement_status()
	{
		return get_char_vehicle_data()->p_char_movement_status;
	}

#ifdef VEHICLE_T__SET_REL_ROT_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
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

}
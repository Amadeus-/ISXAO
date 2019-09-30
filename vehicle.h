#pragma once
#include "game_object.h"

namespace ao
{
	struct ao_char_movement_status;
	struct ao_char_vehicle;
	struct ao_quaternion;
	struct ao_vector3;	

	typedef ao_char_movement_status char_movement_status_t, *p_char_movement_status_t;
	typedef ao_char_vehicle char_vehicle_t, *p_char_vehicle_t;
	typedef ao_quaternion quaternion_t, *p_quaternion_t;
	typedef ao_vector3 vector3_t, *p_vector3_t;

	class vehicle : public game_object<char_vehicle_t>
	{
	public:
		ao::p_char_movement_status_t get_char_movement_status();
		void set_rotation(const ao::quaternion_t &);
		ao::vector3_t get_velocity();
		unsigned long get_zone_instance_id();
		float get_max_speed();
		int steering_direction_arrive(const ao::vector3_t&, ao::vector3_t&);
		int steering_flee(const ao::vector3_t&, ao::vector3_t&);
	};
}

#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class vehicle
{
public:
	ao::p_char_movement_status_t get_char_movement_status();
	void set_rotation(const ao::quaternion_t &);
	ao::vector3_t get_velocity();
	DWORD get_zone_instance_id();
	PVOID get_data();
	ao::p_char_vehicle_t get_char_vehicle_data();
	float get_max_speed();
	int steering_direction_arrive(const ao::vector3_t&, ao::vector3_t&);
	int steering_flee(const ao::vector3_t&, ao::vector3_t&);
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::char_vehicle_t char_vehicle_;
};

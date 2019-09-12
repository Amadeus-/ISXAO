#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class vehicle
{
public:
	AOLIB_OBJECT p_char_movement_status_t get_char_movement_status();
	AOLIB_OBJECT void set_rotation(const quaternion_t &);
	AOLIB_OBJECT vector3_t get_velocity();
	AOLIB_OBJECT DWORD get_zone_instance_id();
	AOLIB_OBJECT PVOID get_data();
	AOLIB_OBJECT p_char_vehicle_t get_char_vehicle_data();
	AOLIB_OBJECT float get_max_speed();
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	char_vehicle_t char_vehicle_;
};

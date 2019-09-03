#pragma once

class Vehicle
{
public:
	AOLIB_OBJECT p_char_movement_status_t GetCharMovementStatus();
	AOLIB_OBJECT void SetRotation(const quaternion_t &);
	AOLIB_OBJECT vector3_t GetVelocity();
	AOLIB_OBJECT DWORD GetZoneInstanceID();
	AOLIB_OBJECT PVOID GetData();
	AOLIB_OBJECT p_char_vehicle_t GetCharVehicleData();
	AOLIB_OBJECT DWORD UseWaypointPath(std::vector<vector3_t> &v, float unknown);
	AOLIB_OBJECT float GetMaxSpeed();
private:
	char_vehicle_t char_vehicle_;
};
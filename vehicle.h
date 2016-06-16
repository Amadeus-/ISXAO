#pragma once

class Vehicle
{
public:
	AOLIB_OBJECT PCHARMOVEMENTSTATUS GetCharMovementStatus();
	AOLIB_OBJECT void SetRotation(const QUATERNION &);
	AOLIB_OBJECT VECTOR3 GetVelocity();
	AOLIB_OBJECT DWORD GetZoneInstanceID();
	AOLIB_OBJECT PVOID GetData();
	AOLIB_OBJECT PCHARVEHICLE GetCharVehicleData();
	AOLIB_OBJECT DWORD UseWaypointPath(std::vector<VECTOR3> &v, float unknown);
	AOLIB_OBJECT float GetMaxSpeed();
private:
	CHARVEHICLE char_vehicle_;
};
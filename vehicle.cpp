#include "isxao_main.h"

namespace isxao_classes
{

	p_char_movement_status_t Vehicle::GetCharMovementStatus()
	{
		return GetCharVehicleData()->p_char_movement_status;
	}

#ifdef Vehicle_t__SetRelRot_x
	FUNCTION_AT_ADDRESS(void Vehicle::SetRotation(const quaternion_t &), Vehicle_t__SetRelRot);
#endif

	PVOID Vehicle::GetData()
	{
		return &char_vehicle_;
	}

	vector3_t Vehicle::GetVelocity()
	{
		return GetCharVehicleData()->velocity;
	}

	DWORD Vehicle::GetZoneInstanceID()
	{
		return GetCharVehicleData()->zone_instance_id;
	}

	p_char_vehicle_t Vehicle::GetCharVehicleData()
	{
		return p_char_vehicle_t(GetData());
	}

#ifdef PlayerVehicle_t__UseWaypointPath_x
	FUNCTION_AT_ADDRESS(DWORD Vehicle::UseWaypointPath(std::vector<vector3_t>&, float), PlayerVehicle_t__UseWaypointPath);
#endif

	float Vehicle::GetMaxSpeed()
	{
		return GetCharVehicleData()->max_speed;
	}


}
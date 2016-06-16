#include "isxao_main.h"

namespace isxao_classes
{

	PCHARMOVEMENTSTATUS Vehicle::GetCharMovementStatus()
	{
		return GetCharVehicleData()->pCharMovementStatus;
	}

#ifdef Vehicle_t__SetRelRot_x
	FUNCTION_AT_ADDRESS(void Vehicle::SetRotation(const QUATERNION &), Vehicle_t__SetRelRot);
#endif

	PVOID Vehicle::GetData()
	{
		return &char_vehicle_;
	}

	VECTOR3 Vehicle::GetVelocity()
	{
		return GetCharVehicleData()->Velocity;
	}

	DWORD Vehicle::GetZoneInstanceID()
	{
		return GetCharVehicleData()->ZoneInstanceID;
	}

	PCHARVEHICLE Vehicle::GetCharVehicleData()
	{
		return PCHARVEHICLE(GetData());
	}

#ifdef PlayerVehicle_t__UseWaypointPath_x
	FUNCTION_AT_ADDRESS(DWORD Vehicle::UseWaypointPath(std::vector<VECTOR3>&, float), PlayerVehicle_t__UseWaypointPath);
#endif

	float Vehicle::GetMaxSpeed()
	{
		return GetCharVehicleData()->MaxSpeed;
	}


}
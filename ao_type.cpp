#include "isxao_main.h"

bool AOType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (!ObjectData.Ptr)
		return false;

	strcpy_s(buf, buflen, "AO");
	return true;
}

bool AOType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER pMember, int argc, char *argv[], LSOBJECT &Object)
{
	if (!ObjectData.Ptr)
		return false;

	switch ((AOTypeMembers)pMember->ID)
	{
	case CheckCollision:
	{
		if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
			return false;
		if (!ISINDEX())
			return false;
		if (argc == 6 && IsNumber(argv[0]) && IsNumber(argv[1]) && IsNumber(argv[2]) && IsNumber(argv[3]) && IsNumber(argv[4]) && IsNumber(argv[5]))
		{
			VECTOR3 to_position;
			to_position.X = float(atof(argv[0]));
			to_position.Y = float(atof(argv[1]));
			to_position.Z = float(atof(argv[2]));
			VECTOR3 from_position;
			from_position.X = float(atof(argv[3]));
			from_position.Y = float(atof(argv[4]));
			from_position.Z = float(atof(argv[5]));
			Object.DWord = P_PLAYFIELD_DIR->GetPlayfield()->LineOfSight(to_position, from_position, P_ENGINE_CLIENT_ANARCHY->GetClientChar()->GetVehicle()->GetZoneInstanceID(), false);
			Object.Type = pBoolType;
			return true;
		}
		return false;
	}
	case GetActors:
	{
		if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
			return false;
		if (ISINDEX())
		{
			LSOBJECT IndexObject;
			if (!pISInterface->DataParse(argv[0], IndexObject))
				return false;
			if (IndexObject.Type != pIndexType)
				return false;
			LSIndex *pIndex = (LSIndex*)IndexObject.Ptr;
			if (pIndex->GetType() != pActorType)
				return false;
			Object.DWord = GetActorIndexFromActorVector(pIndex);
			Object.Type = pUintType;
			return true;
		}
		return false;
	}
	case HeadingTo:
	{
		if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
			return false;
		if (!ISINDEX())
			return false;
		if (argc == 6 && IsNumber(argv[0]) && IsNumber(argv[1]) && IsNumber(argv[2]) && IsNumber(argv[3]) && IsNumber(argv[4]) && IsNumber(argv[5]))
		{
			VECTOR3 to_position;
			to_position.X = float(atof(argv[0]));
			to_position.Y = float(atof(argv[1]));
			to_position.Z = float(atof(argv[2]));
			VECTOR3 from_position;
			from_position.X = float(atof(argv[3]));
			from_position.Y = float(atof(argv[4]));
			from_position.Z = float(atof(argv[5]));
			auto raw_heading = VECTOR3::Subtract(to_position, from_position).GetYaw();
			auto heading = float(raw_heading * 360.0f / (2 * M_PI));
			if (heading < 0.0f)
				heading += 360.0f;
			Object.Float = heading;
			Object.Type = pfloatType;
			return true;
		}
		return false;
	}
	case Zoning:
	{
		if(isxao_utilities::GetGameState() == GAMESTATE_IN_GAME)
		{
			Object.DWord = g_zoning;
			Object.Type = pIntType;
			return true;
		}
		Object.DWord = -1;
		Object.Type = pIntType;
		break;
	}
	default:
		return false;
	}
	return true;
}
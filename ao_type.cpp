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
		if (g_game_state != GAMESTATE_IN_GAME)
			return false;
		if (!IS_INDEX())
			return false;
		if (argc == 6 && IsNumber(argv[0]) && IsNumber(argv[1]) && IsNumber(argv[2]) && IsNumber(argv[3]) && IsNumber(argv[4]) && IsNumber(argv[5]))
		{
			ao::vector3_t to_position;
			to_position.x = float(atof(argv[0]));
			to_position.y = float(atof(argv[1]));
			to_position.z = float(atof(argv[2]));
			ao::vector3_t from_position;
			from_position.x = float(atof(argv[3]));
			from_position.y = float(atof(argv[4]));
			from_position.z = float(atof(argv[5]));
			Object.DWord = P_PLAYFIELD_DIR->get_playfield()->line_of_sight(to_position, from_position, P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_vehicle()->get_zone_instance_id(), false);
			Object.Type = pBoolType;
			return true;
		}
		return false;
	}
	case GetActors:
	{
		if (g_game_state != GAMESTATE_IN_GAME)
			return false;
		if (IS_INDEX())
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
		if (g_game_state != GAMESTATE_IN_GAME)
			return false;
		if (!IS_INDEX())
			return false;
		if (argc == 6 && IsNumber(argv[0]) && IsNumber(argv[1]) && IsNumber(argv[2]) && IsNumber(argv[3]) && IsNumber(argv[4]) && IsNumber(argv[5]))
		{
			ao::vector3_t to_position;
			to_position.x = float(atof(argv[0]));  // NOLINT(cert-err34-c)
			to_position.y = float(atof(argv[1]));  // NOLINT(cert-err34-c)
			to_position.z = float(atof(argv[2]));  // NOLINT(cert-err34-c)
			ao::vector3_t from_position;
			from_position.x = float(atof(argv[3]));  // NOLINT(cert-err34-c)
			from_position.y = float(atof(argv[4]));  // NOLINT(cert-err34-c)
			from_position.z = float(atof(argv[5]));  // NOLINT(cert-err34-c)
			auto raw_heading = ao::vector3_t::subtract(to_position, from_position).get_raw_yaw();
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
		if(g_game_state == GAMESTATE_IN_GAME)
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
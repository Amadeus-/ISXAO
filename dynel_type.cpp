#include "isxao_main.h"

bool DynelType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object)
{
	if (g_game_state != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define P_DYNEL ((ao::dynel*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (DynelTypeMembers(Member->ID))
		{
		case Identity:
		{
			auto id = P_DYNEL->get_identity();
			const auto p_id = static_cast<ao::p_identity_t>(pISInterface->GetTempBuffer(sizeof(ao::identity_t), &id));
			Object.Ptr = p_id;
			Object.Type = pIdentityType;
			break;
		}
		case Name:
		{
			Object.ConstCharPtr = P_DYNEL->get_name();
			Object.Type = pStringType;
			break;
		}
		case Loc:
		{
			auto v = P_DYNEL->get_position();
			auto p = isxao::point3f_from_vector3(v);
			const auto p_p = PPOINT3F(pISInterface->GetTempBuffer(sizeof(p), &p));
			Object.Ptr = p_p;
			Object.Type = pPoint3fType;
			break;
		}
		case X:
		{
			Object.Float = P_DYNEL->get_position().x;
			Object.Type = pfloatType;
			break;
		}
		case Y:
		{
			Object.Float = P_DYNEL->get_position().y;
			Object.Type = pfloatType;
			break;
		}
		case Z:
		{
			Object.Float = P_DYNEL->get_position().z;
			Object.Type = pfloatType;
			break;
		}
		case Distance:
		{
			ao::vector3_t v;
			P_ENGINE_CLIENT_ANARCHY->n3_msg_get_global_character_position(v);
			Object.Float = P_DYNEL->get_distance_3d_to(v);
			Object.Type = pfloatType;
			break;			
		}
		case Distance2D:
		{
			ao::vector3_t v;
			P_ENGINE_CLIENT_ANARCHY->n3_msg_get_global_character_position(v);
			Object.Float = P_DYNEL->get_distance_to(v);
			Object.Type = pfloatType;
			break;
		}
		case Heading:
		{
			float heading;
			const auto raw_heading = P_DYNEL->get_raw_heading();
			if (raw_heading > 0.0f)
				heading = float(raw_heading * 180.0f / M_PI);
			else
				heading = float(raw_heading * 180.0f / M_PI) + 360.0f;
			Object.Float = heading;
			Object.Type = pfloatType;
			break;
		}
		case HeadingTo:
		{
			float heading;
			if (P_ENGINE_CLIENT_ANARCHY && P_ENGINE_CLIENT_ANARCHY->get_client_char())
			{
				ao::vector3_t v;
				P_ENGINE_CLIENT_ANARCHY->n3_msg_get_global_character_position(v);
				const auto raw_heading = P_DYNEL->get_raw_heading_to(v);
				if (raw_heading > 0.0f)
					heading = float(raw_heading * 180.0f / M_PI);
				else
					heading = float(raw_heading * 180.0f / M_PI) + 360.0f;
				if (IS_INDEX() && !IS_NUMBER())
				{
					char arg[MAX_VARSTRING];
					strcpy_s(arg, MAX_VARSTRING, argv[0]);
					_strlwr_s(arg);
					if (!strcmp(arg, "asstring"))
					{
						if (heading >= 0.0f && heading <= 11.25f || heading > 348.75f && heading <= 360.0f)
							Object.ConstCharPtr = "N";
						else if (heading > 11.25f && heading <= 33.75f)
							Object.ConstCharPtr = "NNE";
						else if (heading > 33.75f && heading <= 56.25f)
							Object.ConstCharPtr = "NE";
						else if (heading > 56.25f && heading <= 78.75f)
							Object.ConstCharPtr = "ENE";
						else if (heading > 78.75f && heading <= 101.25f)
							Object.ConstCharPtr = "E";
						else if (heading > 101.25f && heading <= 123.75f)
							Object.ConstCharPtr = "ESE";
						else if (heading > 123.75f && heading <= 146.25f)
							Object.ConstCharPtr = "SE";
						else if (heading > 146.25f && heading <= 168.75f)
							Object.ConstCharPtr = "SSE";
						else if (heading > 168.75f && heading <= 191.25f)
							Object.ConstCharPtr = "S";
						else if (heading > 191.25f && heading <= 213.75f)
							Object.ConstCharPtr = "SSW";
						else if (heading > 213.75f && heading <= 236.25f)
							Object.ConstCharPtr = "SW";
						else if (heading > 236.25f && heading <= 258.75f)
							Object.ConstCharPtr = "WSW";
						else if (heading > 258.75f && heading <= 281.25f)
							Object.ConstCharPtr = "W";
						else if (heading > 281.25f && heading <= 303.75f)
							Object.ConstCharPtr = "WNW";
						else if (heading > 303.75f && heading <= 326.25f)
							Object.ConstCharPtr = "NW";
						else if (heading > 326.25f && heading <= 348.75f)
							Object.ConstCharPtr = "NNW";
						else
							Object.ConstCharPtr = "HeadingOutOfBounds";
						Object.Type = pStringType;
						return true;
					}
				}
				else
					heading = 0.0f;
				Object.Float = heading;
				Object.Type = pfloatType;
				break;
			}
		}
		case HeadingToLoc:
		{
			float heading;
			if (IS_INDEX() && argc == 2 && IsNumber(argv[0]) && IsNumber(argv[1]))
			{
				const auto x = float(atof(argv[0]));  // NOLINT(cert-err34-c)
				const auto z = float(atof(argv[1]));  // NOLINT(cert-err34-c)
				ao::vector3_t offset;
				offset.x = x;
				offset.y = 0.0f;
				offset.z = z;
				ao::vector3_t v;
				P_ENGINE_CLIENT_ANARCHY->n3_msg_get_global_character_position(v);
				const auto raw_heading = P_DYNEL->get_raw_heading_to_loc(v, offset);
				if (raw_heading > 0.0f)
					heading = float(raw_heading * 180.0 / M_PI);
				else
					heading = float(raw_heading * 180.0 / M_PI) + 360.0f;
			}
			else
				heading = 0.0f;
			Object.Float = heading;
			Object.Type = pfloatType;
			break;

		}
		case CheckCollision:
		{
			if (!IS_INDEX())
			{
				if (P_ENGINE_CLIENT_ANARCHY && P_ENGINE_CLIENT_ANARCHY->get_client_char())
				{
					Object.DWord = P_ENGINE_CLIENT_ANARCHY->get_client_char()->check_los(P_DYNEL);
					Object.Type = pBoolType;
					return true;
				}
			}
			else if (argc < 2)
			{
				LSOBJECT object;
				if (!pISInterface->DataParse(argv[0], object))
				{
					return false;
				}
				if (object.Type != pPoint3fType)
				{
					return false;
				}
				const auto p = PPOINT3F(object.Ptr);
				auto v = isxao::vector3_from_p_point3f(p);
				Object.DWord = P_DYNEL->is_in_line_of_sight(v);
				Object.Type = pBoolType;
				return true;
			}
			else if (argc == 3 && IsNumber(argv[0]) && IsNumber(argv[1]) && IsNumber(argv[2]))
			{
				ao::vector3_t v;
				v.x = float(atof(argv[0]));  // NOLINT(cert-err34-c)
				v.y = float(atof(argv[1]));  // NOLINT(cert-err34-c)
				v.z = float(atof(argv[2]));  // NOLINT(cert-err34-c)
				Object.DWord = P_DYNEL->is_in_line_of_sight(v);
				Object.Type = pBoolType;
				return true;
			}
			return false;
		}
		case NearestDynel:
		{
			if (isxao::is_client_id(P_DYNEL->get_identity().id))
			{
				return (TLO_ACTORSEARCH(argc, argv, Object) != 0);
			}
			if (argc)
			{
				DWORD nth;
				isxao::internal::SEARCHACTOR sd_dynel;
				isxao::ClearSearchActor(&sd_dynel);
				sd_dynel.f_radius = 999999.0f;
				if (argc >= 2 || !IsNumber(argv[0]))
				{
					isxao::ParseSearchActor(1, argc, argv, sd_dynel);
					nth = atoi(argv[0]);  // NOLINT(cert-err34-c)
				}
				else
					nth = atoi(argv[0]);  // NOLINT(cert-err34-c)
				const auto result = isxao::NthNearestActor(&sd_dynel, nth, P_ENGINE_CLIENT_ANARCHY->get_client_char());
				if (result)
				{
					Object.Ptr = result;
					Object.Type = isxao::get_real_type(reinterpret_cast<ao::dynel*>(result));
					return true;
				}
			}
			return false;
		}
		case Type:
		{
			switch (P_DYNEL->get_identity().type)
			{
			case 50000:
			{
				if (P_DYNEL->is_pet())
					Object.ConstCharPtr = "Pet";
				else if (P_DYNEL->is_actor())
					Object.ConstCharPtr = "Actor";
				else if (P_DYNEL->is_character())
					Object.ConstCharPtr = "Character";
				else if (P_DYNEL->is_player())
					Object.ConstCharPtr = "Player";
				else
					Object.ConstCharPtr = "Unknown";
				break;
			}
			case 51016:
				Object.ConstCharPtr = "Door";
				break;
			case 51017:
				Object.ConstCharPtr = "Container";
				break;
			case 51018:
				Object.ConstCharPtr = "Weapon";
				break;
			case 51035:
				Object.ConstCharPtr = "VendingMachine";
				break;
			case 51047:
				Object.ConstCharPtr = "TemporaryBag";
				break;
			case 51050:
				Object.ConstCharPtr = "Corpse";
				break;
			case 56001:
				Object.ConstCharPtr = "QuestBooth";
				break;
			default:
				Object.ConstCharPtr = "Unknown";
				break;
			}
			Object.Type = pStringType;
			break;
		}
		case IsActor:
		{
			Object.DWord = P_DYNEL->is_actor();
			Object.Type = pBoolType;
			break;
		}
		case IsAPet:
		{
			Object.DWord = P_DYNEL->is_pet();
			Object.Type = pBoolType;
			break;
		}
		case IsCharacter:
		{
			Object.DWord = isxao::is_client_id(P_DYNEL->get_identity().id);
			Object.Type = pBoolType;
			break;
		}
		case IsInfoRequestComplete:
		{
			Object.DWord = P_DYNEL->is_info_request_completed();
			Object.Type = pBoolType;
			break;
		}
		case IsMyPet:
		{
			Object.DWord = P_DYNEL->is_pet() && isxao::is_client_id(P_DYNEL->to_actor()->get_master_id());
			Object.Type = pBoolType;
			break;
		}
		case IsPlayer:
		{
			Object.DWord = P_DYNEL->is_player();
			Object.Type = pBoolType;
			break;
		}
		case IsTeamMember:
		{
			Object.DWord = P_DYNEL->is_team_member();
			Object.Type = pBoolType;
			break;
		}
		case ToActor:
		{
			Object.Ptr = P_DYNEL;
			Object.Type = pActorType;
			break;
		}
		case ToPet:
		{
			Object.Ptr = P_DYNEL;
			Object.Type = pPetType;
			break;
		}
		default:
			return false;
		}
#undef P_DYNEL
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;

}

bool DynelType::GetMethod(LSOBJECTDATA& ObjectData, PLSTYPEMETHOD pMethod, int argc, char* argv[])
{
	if (g_game_state != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define P_DYNEL ((ao::dynel*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (DynelTypeMethods(pMethod->ID))
		{
		case Interact:
		{
			P_DYNEL->interact();
			break;
		}
		case RequestInfo:
		{
			P_ENGINE_CLIENT_ANARCHY->n3_msg_request_info_packet(P_DYNEL->get_identity());
			break;
		}
		default: break;
		}
#undef P_DYNEL
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, pMethod->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool DynelType::ToText(LSOBJECTDATA ObjectData, char *buf, const unsigned int buffer_length)
{
	if (g_game_state != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage, cppcoreguidelines-macro-usage)
		return false;
#define P_DYNEL ((ao::dynel*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
	sprintf_s(buf, buffer_length, "%I64d", P_DYNEL->get_identity().get_combined_identity());
#undef P_DYNEL

	return true;
}
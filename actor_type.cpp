#include "isxao_main.h"

bool ActorType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define P_ACTOR ((ao::actor*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (ActorTypeMembers(Member->ID))
		{
		case Breed:
		{
			Object.ConstCharPtr = P_ENGINE_CLIENT_ANARCHY->get_breed_str(ao::breed_e(P_ACTOR->get_skill(ao::ST_BREED)));
			Object.Type = pStringType;
			break;
		}
		case Casting:
		{
			Object.DWord = P_ACTOR->casting();
			Object.Type = pUintType;
			break;
		}		
		case CheckCollision:
		{
			if (!IS_INDEX())
			{
				if (P_ENGINE_CLIENT_ANARCHY && P_ENGINE_CLIENT_ANARCHY->get_client_char())
				{
					Object.DWord = P_ENGINE_CLIENT_ANARCHY->get_client_char()->check_los(P_ACTOR);
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
				auto v = vector3_from_p_point3f(p);
				Object.DWord = P_ACTOR->is_in_line_of_sight(v);
				Object.Type = pBoolType;
				return true;
			}
			else if (argc == 3 && IsNumber(argv[0]) && IsNumber(argv[1]) && IsNumber(argv[2]))
			{
				ao::vector3_t v;
				v.x = float(atof(argv[0]));  // NOLINT(cert-err34-c)
				v.y = float(atof(argv[1]));  // NOLINT(cert-err34-c)
				v.z = float(atof(argv[2]));  // NOLINT(cert-err34-c)
				Object.DWord = P_ACTOR->is_in_line_of_sight(v);
				Object.Type = pBoolType;
				return true;
			}
			return false;
		}
		case Con:
		{
			Object.ConstCharPtr = P_ACTOR->consider();
			Object.Type = pStringType;
			break;
		}
		case ConColor:
		{
			Object.ConstCharPtr = P_ACTOR->con_color();
			Object.Type = pStringType;
			break;
		}
		case CurrentHealth:
		{
			Object.Int = P_ACTOR->get_skill(ao::ST_HEALTH);
			Object.Type = pIntType;
			break;
		}
		case CurrentNano:
		{
			Object.DWord = P_ACTOR->get_skill(ao::ST_CURRENTNANO);
			Object.Type = pUintType;
			break;
		}
		case CurrentNCU:
		{
			Object.DWord = P_ACTOR->get_skill(ao::ST_CURRENTNCU);
			Object.Type = pUintType;
			break;
		}
		case Distance:
		{
			ao::vector3_t v;
			P_ENGINE_CLIENT_ANARCHY->n3_msg_get_global_character_position(v);
			Object.Float = P_ACTOR->get_distance_3d_to(v);
			Object.Type = pfloatType;
			break;
		}
		case Distance2D:
		{
			ao::vector3_t v;
			P_ENGINE_CLIENT_ANARCHY->n3_msg_get_global_character_position(v);
			Object.Float = P_ACTOR->get_distance_to(v);
			Object.Type = pfloatType;
			break;
		}
		case DistancePredict:
		{
			ao::vector3_t client = P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_position();
			Object.Float = P_ACTOR->estimated_distance_to(client);
			Object.Type = pfloatType;
			break;
		}
		case Gender:
		{
			Object.ConstCharPtr = P_ENGINE_CLIENT_ANARCHY->get_gender_string(P_ACTOR->get_identity());
			Object.Type = pStringType;
			break;
		}
		case GetNCU:
		{
			if (IS_INDEX())
			{
				LSOBJECT index_object;
				if (!pISInterface->DataParse(argv[0], index_object))
					return false;
				if (index_object.Type != pIndexType)
					return false;
				auto p_index = static_cast<LSIndex*>(index_object.Ptr);
				if (p_index->GetType() != pNanoTemplateType)
					return false;
				Object.DWord = P_ACTOR->build_ls_ncu(p_index);
				Object.Type = pUintType;
				return true;
			}
			return false;
		}
		case GetPets:
		{
			if (IS_INDEX())
			{
				LSOBJECT index_object;
				if (!pISInterface->DataParse(argv[0], index_object))
					return false;
				if (index_object.Type != pIndexType)
					return false;
				auto p_index = static_cast<LSIndex*>(index_object.Ptr);
				if (p_index->GetType() != pActorType)
					return false;
				Object.DWord = P_ACTOR->build_ls_pets(p_index);
				Object.Type = pUintType;
				return true;
			}
			return false;
		}
		case GM:
		{
			Object.DWord = P_ACTOR->get_skill(ao::ST_GMLEVEL);
			Object.Type = pBoolType;
			break;
		}
		case HasPets:
		{
			Object.DWord = P_ACTOR->has_pet();
			Object.Type = pBoolType;
			break;
		}
		case Heading:
		{
			float heading;
			const auto raw_heading = P_ACTOR->get_heading();
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
				const auto raw_heading = P_ACTOR->get_heading_to(v);
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
				const auto raw_heading = P_ACTOR->get_heading_to_loc(v, offset);
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
		case Identity:
		{
			auto id = P_ACTOR->get_identity();
			const auto p_id = static_cast<ao::p_identity_t>(pISInterface->GetTempBuffer(sizeof(ao::identity_t), &id));
			Object.Ptr = p_id;
			Object.Type = pIdentityType;
			break;
		}
		case IsAPet:
		{
			Object.DWord = P_ACTOR->is_pet();
			Object.Type = pBoolType;
			break;
		}
		case IsBackingUp:
		{
			Object.DWord = P_ACTOR->is_backing_up();
			Object.Type = pBoolType;
			break;
		}
		case IsCasting:
		{
			Object.DWord = P_ACTOR->is_casting();
			Object.Type = pBoolType;
			break;
		}
		case IsCharacter:
		{
			Object.DWord = isxao::is_client_id(P_ACTOR->get_identity().id);
			Object.Type = pBoolType;
			break;
		}
		case IsCrawling:
		{
			Object.DWord = P_ACTOR->get_skill(ao::ST_CURRENTMOVEMENTMODE) == 5;
			Object.Type = pBoolType;
			break;
		}
		case IsFighting:
		{
			Object.DWord = P_ACTOR->is_fighting();
			Object.Type = pBoolType;
			break;
		}
		case IsFightingMe:
		{
			Object.DWord = P_ACTOR->is_fighting_me();
			Object.Type = pBoolType;
			break;
		}
		case IsFlying:
		{
			Object.DWord = P_ACTOR->get_skill(ao::ST_CURRENTMOVEMENTMODE) == 7;
			Object.Type = pBoolType;
			break;
		}
		case IsIdle:
		{
			Object.DWord = P_ACTOR->is_idle();
			Object.Type = pBoolType;
			break;
		}
		case IsInfoRequestComplete:
		{
			Object.DWord = P_ACTOR->is_info_request_completed();
			Object.Type = pBoolType;
			break;
		}
		case IsInMyRaidTeam:
		{
			Object.DWord = P_ACTOR->is_in_my_raid_team();
			Object.Type = pBoolType;
			break;
		}
		case IsInRaid:
		{
			Object.DWord = P_ACTOR->is_in_raid();
			Object.Type = pBoolType;
			break;
		}
		case IsInMyTeam:
		{
			Object.DWord = P_ACTOR->is_in_my_team();
			Object.Type = pBoolType;
			break;
		}
		case IsInTeam:
		{
			Object.DWord = P_ACTOR->is_in_team();
			Object.Type = pBoolType;
			break;
		}
		case IsInvis:
		{
			Object.DWord = P_ACTOR->is_invis();
			Object.Type = pBoolType;
			break;
		}
		case IsKOS:
		{
			Object.DWord = P_ACTOR->is_kos();
			Object.Type = pBoolType;
			break;
		}
		case IsMovingForward:
		{
			Object.DWord = P_ACTOR->is_moving_forward();
			Object.Type = pBoolType;
			break;
		}
		case IsMyPet:
		{
			Object.DWord = P_ACTOR->is_pet() && isxao::is_client_id(P_ACTOR->get_master_id());
			Object.Type = pBoolType;
			break;
		}
		case IsPlayer:
		{
			Object.DWord = P_ACTOR->is_player();
			Object.Type = pBoolType;
			break;
		}
		case IsRooted:
		{
			Object.DWord = P_ACTOR->get_skill(ao::ST_CURRENTMOVEMENTMODE) == 1;
			Object.Type = pBoolType;
			break;
		}
		case IsRunning:
		{
			Object.DWord = P_ACTOR->get_skill(ao::ST_CURRENTMOVEMENTMODE) == 3;
			Object.Type = pBoolType;
			break;
		}
		case IsSitting:
		{
			Object.DWord = P_ACTOR->get_skill(ao::ST_CURRENTMOVEMENTMODE) == 8;
			Object.Type = pBoolType;
			break;
		}
		case IsSneaking:
		{
			Object.DWord = P_ACTOR->get_skill(ao::ST_CURRENTMOVEMENTMODE) == 6;
			Object.Type = pBoolType;
			break;
		}
		case IsStealthed:
		{
			Object.DWord = P_ACTOR->is_invis();
			Object.Type = pBoolType;
			break;
		}
		case IsStrafingLeft:
		{
			Object.DWord = P_ACTOR->is_strafing_left();
			Object.Type = pBoolType;
			break;
		}
		case IsStrafingRight:
		{
			Object.DWord = P_ACTOR->is_strafing_right();
			Object.Type = pBoolType;
			break;
		}
		case IsSwimming:
		{
			Object.DWord = P_ACTOR->get_skill(ao::ST_CURRENTMOVEMENTMODE) == 4;
			Object.Type = pBoolType;
			break;
		}
		case IsWalking:
		{
			Object.DWord = P_ACTOR->get_skill(ao::ST_CURRENTMOVEMENTMODE) == 2;
			Object.Type = pBoolType;
			break;
		}
		case Level:
		{
			Object.DWord = P_ACTOR->get_skill(ao::ST_LEVEL);
			Object.Type = pUintType;
			break;
		}
		case Loc:
		{
			auto v = P_ACTOR->get_position();
			auto p = point3f_from_vector3(v);
			const auto p_p = PPOINT3F(pISInterface->GetTempBuffer(sizeof(p), &p));
			Object.Ptr = p_p;
			Object.Type = pPoint3fType;
			break;
		}
		case Master:
		{
			if((Object.Ptr = P_ACTOR->get_master()))
			{
				Object.Type = GetRealType(static_cast<ao::dynel*>(Object.Ptr));
				return true;
			}
			return false;
		}
		case MaxHealth:
		{
			Object.DWord = P_ACTOR->get_skill(ao::ST_LIFE);
			Object.Type = pUintType;
			break;
		}
		case MaxNano:
		{
			Object.DWord = P_ACTOR->get_skill(ao::ST_MAXNANOENERGY);
			Object.Type = pUintType;
			break;
		}
		case Name:
		{
			Object.ConstCharPtr = P_ACTOR->get_name();
			Object.Type = pStringType;
			break;
		}
		case NCU:
		{
			if (IS_INDEX())
			{
				if (IS_NUMBER())
				{
					if ((Object.Ptr = P_ACTOR->get_ncu(GET_NUMBER() - 1)))  // NOLINT(cert-err34-c)
					{
						Object.Type = pNanoTemplateType;
						return true;
					}
				}
				if ((Object.Ptr = P_ACTOR->get_ncu(argv[0])))
				{
					Object.Type = pNanoTemplateType;
					return true;
				}
			}
			return false;
		}
		case NCUCount:
		{
			Object.DWord = P_ACTOR->get_ncu_count();
			Object.Type = pUintType;
			break;
		}
		case NPCFamily:
		{
			Object.Int = P_ACTOR->get_skill(ao::ST_NPCFAMILY);
			Object.Type = pIntType;
			break;
		}
		case NearestActor:
		{
			if (is_client_id(P_ACTOR->get_identity().id))
			{
				return (TLO_ACTORSEARCH(argc, argv, Object) != 0);
			}
			if (argc)
			{
				DWORD nth;
				SEARCHACTOR sd_dynel;
				ClearSearchActor(&sd_dynel);
				sd_dynel.f_radius = 999999.0f;
				if (argc >= 2 || !IsNumber(argv[0]))
				{
					ParseSearchActor(1, argc, argv, sd_dynel);
					nth = atoi(argv[0]);  // NOLINT(cert-err34-c)
				}
				else
					nth = atoi(argv[0]);  // NOLINT(cert-err34-c)
				const auto result = NthNearestActor(&sd_dynel, nth, P_ENGINE_CLIENT_ANARCHY->get_client_char());
				if (result)
				{
					Object.Ptr = result;
					Object.Type = ::GetRealType(reinterpret_cast<ao::dynel*>(result));
					return true;
				}
			}
			return false;
		}
		case PctHealth:
		{
			Object.Int = P_ACTOR->get_skill(ao::ST_PERCENTREMAININGHEALTH);
			Object.Type = pIntType;
			break;
		}
		case PctNano:
		{
			Object.DWord = P_ACTOR->get_skill(ao::ST_PERCENTREMAININGNANO);
			Object.Type = pUintType;
			break;
		}
		case Pet:
		{
			if (IS_INDEX())
			{
				if(IS_NUMBER())
				{
					if ((Object.Ptr = P_ACTOR->get_pet(GET_NUMBER() - 1)))  // NOLINT(cert-err34-c)
					{
						if (is_client_id(P_ACTOR->get_identity().id))
							Object.Type = pPetType;
						else
							Object.Type = pActorType;
						return true;
					}
				}
				if ((Object.Ptr = P_ACTOR->get_pet(argv[0])))
				{
					if (is_client_id(P_ACTOR->get_identity().id))
						Object.Type = pPetType;
					else
						Object.Type = pActorType;
					return true;
				}
			}			
			return false;
		}
		case PetCount:
		{
			Object.DWord = P_ACTOR->get_pet_count();
			Object.Type = pUintType;
			break;
		}
		case Profession:
		{
			Object.ConstCharPtr = ao::engine_client_anarchy::get_profession_str(ao::profession_e(P_ACTOR->get_skill(ao::ST_PROFESSION)));
			Object.Type = pStringType;
			break;
		}
		case ProfessionLevel:
		{
			Object.DWord = P_ACTOR->get_skill(ao::ST_PROFESSIONLEVEL);
			Object.Type = pUintType;
			break;
		}
		case Radius:
		{
			Object.Int = P_ACTOR->get_skill(ao::ST_CHARRADIUS);
			Object.Type = pIntType;
			break;
		}
		case Runspeed:
		{
			Object.Int = P_ACTOR->get_skill(ao::ST_RUNSPEED);
			Object.Type = pIntType;
			break;
		}
		case Scale:
		{
			Object.Float = P_ACTOR->get_scale();
			Object.Type = pfloatType;
			break;
		}
		case Side:
		{
			Object.ConstCharPtr = get_side_str(P_ACTOR->get_skill(ao::ST_SIDE));
			Object.Type = pStringType;
			break;
		}
		case Speed:
		{
			Object.Float = P_ACTOR->get_vehicle()->get_velocity().length();
			Object.Type = pfloatType;
			break;
		}
		case ToCharacter:
		{
			Object.Ptr = P_ACTOR;
			Object.Type = pCharacterType;
			break;
		}
		case ToPet:
		{
			Object.Ptr = P_ACTOR;
			Object.Type = pPetType;
			break;
		}
		case Velocity:
		{
			auto velocity_vector3 = P_ACTOR->get_vehicle()->get_velocity();
			// ReSharper disable once CppInconsistentNaming
			auto velocity_point3f = point3f_from_vector3(velocity_vector3);
			// ReSharper disable once CppInconsistentNaming
			const auto p_velocity_point3f = PPOINT3F(pISInterface->GetTempBuffer(sizeof(POINT3F), &velocity_point3f));
			Object.Ptr = p_velocity_point3f;
			Object.Type = pPoint3fType;
			break;
		}
		case X:
		{
			Object.Float = P_ACTOR->get_position().x;
			Object.Type = pfloatType;
			break;
		}
		case Y:
		{
			Object.Float = P_ACTOR->get_position().y;
			Object.Type = pfloatType;
			break;
		}
		case Z:
		{
			Object.Float = P_ACTOR->get_position().z;
			Object.Type = pfloatType;
			break;
		}
		default:
			return false;
		}
#undef P_ACTOR
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool ActorType::GetMethod(LSOBJECTDATA& ObjectData, PLSTYPEMETHOD pMethod, int argc, char* argv[])
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define P_ACTOR ((ao::actor*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
		switch (ActorTypeMethods(pMethod->ID))
		{
		case DoFace:
		{
			P_ACTOR->do_face();
			break;
		}
		case DoTarget:
		{
			P_ACTOR->do_target();
			break;
		}
		case Interact:
		{
			P_ACTOR->interact();
			break;
		}
		case Invite:
		{
			P_ACTOR->send_team_invite();
			break;
		}
		case Kick:
		{
			P_ACTOR->kick();
			break;
		}
		case MakeLeader:
		{
			P_ACTOR->make_leader();
			break;
		}
		case RequestInfo:
		{
			P_ENGINE_CLIENT_ANARCHY->n3_msg_request_info_packet(P_ACTOR->get_identity());
			break;
		}
		default: break;
		}
#undef P_ACTOR
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, pMethod->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool ActorType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define P_ACTOR ((ao::actor*)ObjectData.Ptr)  // NOLINT(cppcoreguidelines-macro-usage)
	sprintf_s(buf, buflen, "%I64u", P_ACTOR->get_identity().get_combined_identity());
#undef P_ACTOR

	return true;
}
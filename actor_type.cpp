#include "isxao_main.h"

bool ActorType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pActor ((Actor*)ObjectData.Ptr)
		switch (ActorTypeMembers(Member->ID))
		{
		case Breed:
		{
			Object.ConstCharPtr = GetBreedStr(pActor->GetSkill(::ST_BREED));
			Object.Type = pStringType;
			break;
		}
		case Casting:
		{
			Object.DWord = pActor->Casting();
			Object.Type = pUintType;
			break;
		}		
		case CheckCollision:
		{
			if (!ISINDEX())
			{
				if (pEngineClientAnarchy && pEngineClientAnarchy->GetClientChar())
				{
					Object.DWord = pEngineClientAnarchy->GetClientChar()->CheckLOS(pActor);
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
				PPOINT3F p = PPOINT3F(object.Ptr);
				VECTOR3 v = Vector3FrompPoint3f(p);
				Object.DWord = pActor->IsInLineOfSight(v);
				Object.Type = pBoolType;
				return true;
			}
			else if (argc == 3 && IsNumber(argv[0]) && IsNumber(argv[1]) && IsNumber(argv[2]))
			{
				VECTOR3 v;
				v.X = float(atof(argv[0]));
				v.Y = float(atof(argv[1]));
				v.Z = float(atof(argv[2]));
				Object.DWord = pActor->IsInLineOfSight(v);
				Object.Type = pBoolType;
				return true;
			}
			return false;
		}
		case CurrentHealth:
		{
			Object.Int = pActor->GetSkill(::ST_HEALTH);
			Object.Type = pIntType;
			break;
		}
		case CurrentNano:
		{
			Object.DWord = pActor->GetSkill(ST_CURRENTNANO);
			Object.Type = pUintType;
			break;
		}
		case CurrentNCU:
		{
			Object.DWord = pActor->GetSkill(::ST_CURRENTNCU);
			Object.Type = pUintType;
			break;
		}
		case Distance:
		{
			VECTOR3 v;
			pEngineClientAnarchy->N3Msg_GetGlobalCharacterPosition(v);
			Object.Float = pActor->GetDistance3DTo(v);
			Object.Type = pfloatType;
			break;
		}
		case Distance2D:
		{
			VECTOR3 v;
			pEngineClientAnarchy->N3Msg_GetGlobalCharacterPosition(v);
			Object.Float = pActor->GetDistanceTo(v);
			Object.Type = pfloatType;
			break;
		}
		case DistancePredict:
		{
			VECTOR3 client = pEngineClientAnarchy->GetClientChar()->GetPosition();
			Object.Float = pActor->EstimatedDistanceTo(client);
			Object.Type = pfloatType;
			break;
		}
		case Gender:
		{
			Object.ConstCharPtr = pEngineClientAnarchy->GetGenderString(pActor->GetIdentity());
			Object.Type = pStringType;
			break;
		}
		case GetNCU:
		{
			if (ISINDEX())
			{
				LSOBJECT IndexObject;
				if (!pISInterface->DataParse(argv[0], IndexObject))
					return false;
				if (IndexObject.Type != pIndexType)
					return false;
				LSIndex *pIndex = (LSIndex*)IndexObject.Ptr;
				if (pIndex->GetType() != pNanoTemplateType)
					return false;
				Object.DWord = pActor->BuildLSNCU(pIndex);
				Object.Type = pUintType;
				return true;
			}
			return false;
		}
		case GetPets:
		{
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
				Object.DWord = pActor->BuildLSPets(pIndex);
				Object.Type = pUintType;
				return true;
			}
			return false;
		}
		case GM:
		{
			Object.DWord = pActor->GetSkill(ST_GMLEVEL);
			Object.Type = pBoolType;
			break;
		}
		case HasPets:
		{
			Object.DWord = pActor->HasPet();
			Object.Type = pBoolType;
			break;
		}
		case Heading:
		{
			float heading;
			auto rawHeading = pActor->GetHeading();
			if (rawHeading > 0.0f)
				heading = float(rawHeading * 180.0f / M_PI);
			else
				heading = float(rawHeading * 180.0f / M_PI) + 360.0f;
			Object.Float = heading;
			Object.Type = pfloatType;
			break;
		}
		case HeadingTo:
		{
			float heading;
			if (pEngineClientAnarchy && pEngineClientAnarchy->GetClientChar())
			{
				VECTOR3 v;
				pEngineClientAnarchy->N3Msg_GetGlobalCharacterPosition(v);
				auto rawHeading = pActor->GetHeadingTo(v);
				if (rawHeading > 0.0f)
					heading = float(rawHeading * 180.0f / M_PI);
				else
					heading = float(rawHeading * 180.0f / M_PI) + 360.0f;
				if (ISINDEX() && !ISNUMBER())
				{
					char arg[MAX_STRING];
					strcpy_s(arg, MAX_STRING, argv[0]);
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
			if (ISINDEX() && argc == 2 && IsNumber(argv[0]) && IsNumber(argv[1]))
			{
				float rawheading;
				float x = float(atof(argv[0]));
				float z = float(atof(argv[1]));
				VECTOR3 offset;
				offset.X = x;
				offset.Y = 0.0f;
				offset.Z = z;
				VECTOR3 v;
				pEngineClientAnarchy->N3Msg_GetGlobalCharacterPosition(v);
				rawheading = pActor->GetHeadingToLoc(v, offset);
				if (rawheading > 0.0f)
					heading = float(rawheading * 180.0 / M_PI);
				else
					heading = float(rawheading * 180.0 / M_PI) + 360.0f;
			}
			else
				heading = 0.0f;
			Object.Float = heading;
			Object.Type = pfloatType;
			break;

		}
		case Identity:
		{
			IDENTITY id = pActor->GetIdentity();
			PIDENTITY pId = static_cast<PIDENTITY>(pISInterface->GetTempBuffer(sizeof(IDENTITY), &id));
			Object.Ptr = pId;
			Object.Type = pIdentityType;
			break;
		}
		case IsAPet:
		{
			Object.DWord = pActor->IsPet();
			Object.Type = pBoolType;
			break;
		}
		case IsBackingUp:
		{
			Object.DWord = pActor->IsBackingUp();
			Object.Type = pBoolType;
			break;
		}
		case IsCasting:
		{
			Object.DWord = pActor->IsCasting();
			Object.Type = pBoolType;
			break;
		}
		case IsCharacter:
		{
			Object.DWord = isxao_inlines::IsClientId(pActor->GetIdentity().Id);
			Object.Type = pBoolType;
			break;
		}
		case IsCrawling:
		{
			Object.DWord = pActor->GetSkill(::ST_CURRENTMOVEMENTMODE) == 5;
			Object.Type = pBoolType;
			break;
		}
		case IsFighting:
		{
			Object.DWord = pActor->IsFighting();
			Object.Type = pBoolType;
			break;
		}
		case IsFightingMe:
		{
			Object.DWord = pActor->IsFightingMe();
			Object.Type = pBoolType;
			break;
		}
		case IsFlying:
		{
			Object.DWord = pActor->GetSkill(::ST_CURRENTMOVEMENTMODE) == 7;
			Object.Type = pBoolType;
			break;
		}
		case IsIdle:
		{
			Object.DWord = pActor->IsIdle();
			Object.Type = pBoolType;
			break;
		}
		case IsInfoRequestComplete:
		{
			Object.DWord = pActor->IsInfoRequestCompleted();
			Object.Type = pBoolType;
			break;
		}
		case IsInMyRaidTeam:
		{
			Object.DWord = pActor->IsInMyRaidTeam();
			Object.Type = pBoolType;
			break;
		}
		case IsInRaid:
		{
			Object.DWord = pActor->IsInRaid();
			Object.Type = pBoolType;
			break;
		}
		case IsInMyTeam:
		{
			Object.DWord = pActor->IsInMyTeam();
			Object.Type = pBoolType;
			break;
		}
		case IsInTeam:
		{
			Object.DWord = pActor->IsInTeam();
			Object.Type = pBoolType;
			break;
		}
		case IsInvis:
		{
			Object.DWord = pActor->IsInvis();
			Object.Type = pBoolType;
			break;
		}
		case IsKOS:
		{
			Object.DWord = pActor->IsKOS();
			Object.Type = pBoolType;
			break;
		}
		case IsMovingForward:
		{
			Object.DWord = pActor->IsMovingForward();
			Object.Type = pBoolType;
			break;
		}
		case IsMyPet:
		{
			Object.DWord = pActor->IsPet() && isxao_inlines::IsClientId(pActor->GetMasterId());
			Object.Type = pBoolType;
			break;
		}
		case IsPlayer:
		{
			Object.DWord = pActor->IsPlayer();
			Object.Type = pBoolType;
			break;
		}
		case IsRooted:
		{
			Object.DWord = pActor->GetSkill(::ST_CURRENTMOVEMENTMODE) == 1;
			Object.Type = pBoolType;
			break;
		}
		case IsRunning:
		{
			Object.DWord = pActor->GetSkill(::ST_CURRENTMOVEMENTMODE) == 3;
			Object.Type = pBoolType;
			break;
		}
		case IsSitting:
		{
			Object.DWord = pActor->GetSkill(::ST_CURRENTMOVEMENTMODE) == 8;
			Object.Type = pBoolType;
			break;
		}
		case IsSneaking:
		{
			Object.DWord = pActor->GetSkill(::ST_CURRENTMOVEMENTMODE) == 6;
			Object.Type = pBoolType;
			break;
		}
		case IsStealthed:
		{
			Object.DWord = pActor->IsInvis();
			Object.Type = pBoolType;
			break;
		}
		case IsStrafingLeft:
		{
			Object.DWord = pActor->IsStrafingLeft();
			Object.Type = pBoolType;
			break;
		}
		case IsStrafingRight:
		{
			Object.DWord = pActor->IsStrafingRight();
			Object.Type = pBoolType;
			break;
		}
		case IsSwimming:
		{
			Object.DWord = pActor->GetSkill(::ST_CURRENTMOVEMENTMODE) == 4;
			Object.Type = pBoolType;
			break;
		}
		case IsWalking:
		{
			Object.DWord = pActor->GetSkill(::ST_CURRENTMOVEMENTMODE) == 2;
			Object.Type = pBoolType;
			break;
		}
		case Level:
		{
			Object.DWord = pActor->GetSkill(::ST_LEVEL);
			Object.Type = pUintType;
			break;
		}
		case Loc:
		{
			VECTOR3 v = pActor->GetPosition();
			POINT3F p = Point3fFromVector3(v);
			PPOINT3F pP = PPOINT3F(pISInterface->GetTempBuffer(sizeof(p), &p));
			Object.Ptr = pP;
			Object.Type = pPoint3fType;
			break;
		}
		case Master:
		{
			if((Object.Ptr = pActor->GetMaster()))
			{
				Object.Type = ::GetRealType(static_cast<Dynel*>(Object.Ptr));
				return true;
			}
			return false;
		}
		case MaxHealth:
		{
			Object.DWord = pActor->GetSkill(::ST_LIFE);
			Object.Type = pUintType;
			break;
		}
		case MaxNano:
		{
			Object.DWord = pActor->GetSkill(ST_MAXNANOENERGY);
			Object.Type = pUintType;
			break;
		}
		case Name:
		{
			Object.ConstCharPtr = pActor->GetName();
			Object.Type = pStringType;
			break;
		}
		case NCU:
		{
			if (ISINDEX())
			{
				if (ISNUMBER())
				{
					if ((Object.Ptr = pActor->GetNCU(GETNUMBER() - 1)))
					{
						Object.Type = pNanoTemplateType;
						return true;
					}
				}
				if ((Object.Ptr = pActor->GetNCU(argv[0])))
				{
					Object.Type = pNanoTemplateType;
					return true;
				}
			}
			return false;
		}
		case NCUCount:
		{
			Object.DWord = pActor->GetNCUCount();
			Object.Type = pUintType;
			break;
		}
		case NPCFamily:
		{
			Object.Int = pActor->GetSkill(::ST_NPCFAMILY);
			Object.Type = pIntType;
			break;
		}
		case NearestActor:
		{
			if (IsClientId(pActor->GetIdentity().Id))
			{
				return (TLO_ACTORSEARCH(argc, argv, Object) != 0);
			}
			if (argc)
			{
				DWORD nth;
				SEARCHACTOR sdDynel;
				ClearSearchActor(&sdDynel);
				sdDynel.f_radius = 999999.0f;
				if (argc >= 2 || !IsNumber(argv[0]))
				{
					ParseSearchActor(1, argc, argv, sdDynel);
					nth = atoi(argv[0]);
				}
				else
					nth = atoi(argv[0]);
				auto result = NthNearestActor(&sdDynel, nth, pEngineClientAnarchy->GetClientChar());
				if (result)
				{
					Object.Ptr = result;
					Object.Type = ::GetRealType(reinterpret_cast<Dynel*>(result));
					return true;
				}
			}
			return false;
		}
		case PctHealth:
		{
			Object.Int = pActor->GetSkill(::ST_PERCENTREMAININGHEALTH);
			Object.Type = pIntType;
			break;
		}
		case PctNano:
		{
			Object.DWord = pActor->GetSkill(ST_PERCENTREMAININGNANO);
			Object.Type = pUintType;
			break;
		}
		case Pet:
		{
			if (ISINDEX())
			{
				if(ISNUMBER())
				{
					if ((Object.Ptr = pActor->GetPet(GETNUMBER() - 1)))
					{
						if (IsClientId(pActor->GetIdentity().Id))
							Object.Type = pPetType;
						else
							Object.Type = pActorType;
						return true;
					}
				}
				if ((Object.Ptr = pActor->GetPet(argv[0])))
				{
					if (IsClientId(pActor->GetIdentity().Id))
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
			Object.DWord = pActor->GetPetCount();
			Object.Type = pUintType;
			break;
		}
		case Profession:
		{
			Object.ConstCharPtr = isxao_utilities::GetProfessionStr(pActor->GetSkill(::ST_PROFESSION));
			Object.Type = pStringType;
			break;
		}
		case ProfessionLevel:
		{
			Object.DWord = pActor->GetSkill(::ST_PROFESSIONLEVEL);
			Object.Type = pUintType;
			break;
		}
		case Radius:
		{
			Object.Int = pActor->GetSkill(::ST_CHARRADIUS);
			Object.Type = pIntType;
			break;
		}
		case Runspeed:
		{
			Object.Int = pActor->GetSkill(::ST_RUNSPEED);
			Object.Type = pIntType;
			break;
		}
		case Scale:
		{
			Object.Float = pActor->GetScale();
			Object.Type = pfloatType;
			break;
		}
		case Side:
		{
			Object.ConstCharPtr = GetSideStr(pActor->GetSkill(::ST_SIDE));
			Object.Type = pStringType;
			break;
		}
		case Speed:
		{
			Object.Float = pActor->GetVehicle()->GetVelocity().Length();
			Object.Type = pfloatType;
			break;
		}
		case ToCharacter:
		{
			Object.Ptr = pActor;
			Object.Type = pCharacterType;
			break;
		}
		case ToPet:
		{
			Object.Ptr = pActor;
			Object.Type = pPetType;
			break;
		}
		case Velocity:
		{
			VECTOR3 velocity_vector3 = pActor->GetVehicle()->GetVelocity();
			POINT3F velocity_point3f = Point3fFromVector3(velocity_vector3);
			PPOINT3F pvelocity_point3f = PPOINT3F(pISInterface->GetTempBuffer(sizeof(POINT3F), &velocity_point3f));
			Object.Ptr = pvelocity_point3f;
			Object.Type = pPoint3fType;
			break;
		}
		case X:
		{
			Object.Float = pActor->GetPosition().X;
			Object.Type = pfloatType;
			break;
		}
		case Y:
		{
			Object.Float = pActor->GetPosition().Y;
			Object.Type = pfloatType;
			break;
		}
		case Z:
		{
			Object.Float = pActor->GetPosition().Z;
			Object.Type = pfloatType;
			break;
		}
		default:
			return false;
		}
#undef pActor
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
#define pActor ((Actor*)ObjectData.Ptr)
		switch (ActorTypeMethods(pMethod->ID))
		{
		case DoFace:
		{
			pActor->DoFace();
			break;
		}
		case DoTarget:
		{
			pActor->DoTarget();
			break;
		}
		case Interact:
		{
			pActor->Interact();
			break;
		}
		case Invite:
		{
			pActor->SendTeamInvite();
			break;
		}
		case Kick:
		{
			pActor->Kick();
			break;
		}
		case MakeLeader:
		{
			pActor->MakeLeader();
			break;
		}
		case RequestInfo:
		{
			isxao_utilities::RequestInfo(pActor->GetIdentity());
			break;
		}
		default: break;
		}
#undef pActor
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
#define pActor ((Actor*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%I64u", pActor->GetIdentity().GetCombinedIdentity());
#undef pActor

	return true;
}
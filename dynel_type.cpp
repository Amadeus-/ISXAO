#include "isxao_main.h"

bool DynelType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pDynel ((Dynel*)ObjectData.Ptr)
		switch (DynelTypeMembers(Member->ID))
		{
		case Identity:
		{
			identity_t id = pDynel->GetIdentity();
			p_identity_t pId = static_cast<p_identity_t>(pISInterface->GetTempBuffer(sizeof(identity_t), &id));
			Object.Ptr = pId;
			Object.Type = pIdentityType;
			break;
		}
		case Name:
		{
			Object.ConstCharPtr = pDynel->GetName();
			Object.Type = pStringType;
			break;
		}
		case Loc:
		{						
			vector3_t v = pDynel->GetPosition();
			POINT3F p = Point3fFromVector3(v);
			PPOINT3F pP = PPOINT3F(pISInterface->GetTempBuffer(sizeof(p), &p));
			Object.Ptr = pP;
			Object.Type = pPoint3fType;
			break;
		}
		case X:
		{
			Object.Float = pDynel->GetPosition().x;
			Object.Type = pfloatType;
			break;
		}
		case Y:
		{
			Object.Float = pDynel->GetPosition().y;
			Object.Type = pfloatType;
			break;
		}
		case Z:
		{
			Object.Float = pDynel->GetPosition().z;
			Object.Type = pfloatType;
			break;
		}
		case Distance:
		{
			vector3_t v;
			P_ENGINE_CLIENT_ANARCHY->N3Msg_GetGlobalCharacterPosition(v);
			Object.Float = pDynel->GetDistance3DTo(v);
			Object.Type = pfloatType;
			break;			
		}
		case Distance2D:
		{
			vector3_t v;
			P_ENGINE_CLIENT_ANARCHY->N3Msg_GetGlobalCharacterPosition(v);
			Object.Float = pDynel->GetDistanceTo(v);
			Object.Type = pfloatType;
			break;
		}
		case Heading:
		{
			float heading;
			auto rawHeading = pDynel->GetHeading();
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
			if (P_ENGINE_CLIENT_ANARCHY && P_ENGINE_CLIENT_ANARCHY->get_client_char())
			{
				vector3_t v;
				P_ENGINE_CLIENT_ANARCHY->N3Msg_GetGlobalCharacterPosition(v);
				auto rawHeading = pDynel->GetHeadingTo(v);
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
				vector3_t offset;
				offset.x = x;
				offset.y = 0.0f;
				offset.z = z;
				vector3_t v;
				P_ENGINE_CLIENT_ANARCHY->N3Msg_GetGlobalCharacterPosition(v);
				rawheading = pDynel->GetHeadingToLoc(v, offset);
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
		case CheckCollision:
		{
			if (!ISINDEX())
			{
				if (P_ENGINE_CLIENT_ANARCHY && P_ENGINE_CLIENT_ANARCHY->get_client_char())
				{
					Object.DWord = P_ENGINE_CLIENT_ANARCHY->get_client_char()->CheckLOS(pDynel);
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
				vector3_t v = Vector3FrompPoint3f(p);
				Object.DWord = pDynel->IsInLineOfSight(v);
				Object.Type = pBoolType;
				return true;
			}
			else if (argc == 3 && IsNumber(argv[0]) && IsNumber(argv[1]) && IsNumber(argv[2]))
			{
				vector3_t v;
				v.x = float(atof(argv[0]));
				v.y = float(atof(argv[1]));
				v.z = float(atof(argv[2]));
				Object.DWord = pDynel->IsInLineOfSight(v);
				Object.Type = pBoolType;
				return true;
			}
			return false;
		}
		case NearestDynel:
		{
			if (IsClientId(pDynel->GetIdentity().id))
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
				auto result = NthNearestActor(&sdDynel, nth, P_ENGINE_CLIENT_ANARCHY->get_client_char());
				if (result)
				{
					Object.Ptr = result;
					Object.Type = ::GetRealType(reinterpret_cast<Dynel*>(result));
					return true;
				}
			}
			return false;
		}
		case Type:
		{
			switch (pDynel->GetIdentity().type)
			{
			case 50000:
			{
				if (pDynel->IsPet())
					Object.ConstCharPtr = "Pet";
				else if (pDynel->IsActor())
					Object.ConstCharPtr = "Actor";
				else if (pDynel->IsCharacter())
					Object.ConstCharPtr = "Character";
				else if (pDynel->IsPlayer())
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
			Object.DWord = pDynel->IsActor();
			Object.Type = pBoolType;
			break;
		}
		case IsAPet:
		{
			Object.DWord = pDynel->IsPet();
			Object.Type = pBoolType;
			break;
		}
		case IsCharacter:
		{
			Object.DWord = isxao_inlines::IsClientId(pDynel->GetIdentity().id);
			Object.Type = pBoolType;
			break;
		}
		case IsInfoRequestComplete:
		{
			Object.DWord = pDynel->IsInfoRequestCompleted();
			Object.Type = pBoolType;
			break;
		}
		case IsMyPet:
		{
			Object.DWord = pDynel->IsPet() && isxao_inlines::IsClientId(pDynel->ToActor()->GetMasterId());
			Object.Type = pBoolType;
			break;
		}
		case IsPlayer:
		{
			Object.DWord = pDynel->IsPlayer();
			Object.Type = pBoolType;
			break;
		}
		case IsTeamMember:
		{
			Object.DWord = pDynel->IsTeamMember();
			Object.Type = pBoolType;
			break;
		}
		case ToActor:
		{
			Object.Ptr = pDynel;
			Object.Type = pActorType;
			break;
		}
		case ToPet:
		{
			Object.Ptr = pDynel;
			Object.Type = pPetType;
			break;
		}
		default:
			return false;
		}
#undef pDynel
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;

}

bool DynelType::GetMethod(LSOBJECTDATA& ObjectData, PLSTYPEMETHOD pMethod, int argc, char* argv[])
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pDynel ((Dynel*)ObjectData.Ptr)
		switch (DynelTypeMethods(pMethod->ID))
		{
		case Interact:
		{
			pDynel->Interact();
			break;
		}
		case RequestInfo:
		{
			isxao_utilities::RequestInfo(pDynel->GetIdentity());
			break;
		}
		default: break;
		}
#undef pDynel
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, pMethod->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool DynelType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define pDynel ((Dynel*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%I64d", pDynel->GetIdentity().get_combined_identity());
#undef pDynel

	return true;
}
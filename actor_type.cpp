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
		case CharRadius:
		{
			Object.Int = pActor->GetSkill(::ST_CHARRADIUS);
			Object.Type = pIntType;
			break;
		}
		case CurrentHealth:
		{
			Object.Int = pActor->GetSkill(::ST_HEALTH);
			Object.Type = pIntType;
			break;
		}
		case CurrentNCU:
		{
			Object.DWord = pActor->GetSkill(::ST_CURRENTNCU);
			Object.Type = pUintType;
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
		case IsInvis:
		{
			Object.DWord = pActor->IsInvis();
			Object.Type = pBoolType;
			break;
		}
		case IsMovingForward:
		{
			Object.DWord = pActor->IsMovingForward();
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
		case NPCNumPets:
		{
			Object.Int = pActor->GetSkill(::ST_NPCNUMPETS);
			Object.Type = pIntType;
			break;
		}
		case PctHealth:
		{
			Object.Int = pActor->GetSkill(::ST_PERCENTREMAININGHEALTH);
			Object.Type = pIntType;
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
			//printf(isxao_utilities::GetProfessionStr(pActor->GetSkill(::ST_PROFESSION)));
			Object.ConstCharPtr = isxao_utilities::GetProfessionStr(pActor->GetSkill(::ST_PROFESSION));
			Object.Type = pStringType;
			break;
		}
		case Runspeed:
		{
			Object.Int = pActor->GetSkill(::ST_RUNSPEED);
			Object.Type = pIntType;
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
		case Velocity:
		{
			VECTOR3 velocity_vector3 = pActor->GetVehicle()->GetVelocity();
			POINT3F velocity_point3f = Point3fFromVector3(velocity_vector3);
			PPOINT3F pvelocity_point3f = PPOINT3F(pISInterface->GetTempBuffer(sizeof(POINT3F), &velocity_point3f));
			Object.Ptr = pvelocity_point3f;
			Object.Type = pPoint3fType;
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
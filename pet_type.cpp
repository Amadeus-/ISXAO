#include "isxao_main.h"

bool PetType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pPet ((Pet*)ObjectData.Ptr)
		switch (PetTypeMembers(Member->ID))
		{
		case Type:
		{
			Object.DWord = pPet->GetPetType();
			Object.Type = pUintType;
			break;
		}
		default:
			return false;
		}
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
#undef pPet
}

bool PetType::GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[])
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pPet ((Pet*)ObjectData.Ptr)
		switch (PetTypeMethods(pMethod->ID))
		{
		case Attack:
		{
			pPet->Attack();
			break;
		}
		case Behind:
		{
			pPet->Behind();
			break;
		}
		case Follow:
		{
			pPet->Follow();
			break;
		}
		case Guard:
		{
			pPet->Guard();
			break;
		}
		case Heal:
		{
			pPet->Heal();
			break;
		}
		case Report:
		{
			pPet->Report();
			break;
		}
		case Terminate:
		{
			pPet->Terminate();
			break;
		}
		case Wait:
		{
			pPet->Wait();
			break;
		}
		default: break;
		}
#undef pPet
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, pMethod->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool PetType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define pPet ((Pet*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%I64u", pPet->GetIdentity().get_combined_identity());
#undef pPet

	return true;
}
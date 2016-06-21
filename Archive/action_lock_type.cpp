#include "isxao_main.h"

bool ActionLockType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char* argv[], LSOBJECT& Object)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
	__try
	{
#define pActionLock ((ActionLock*)ObjectData.Ptr)
		switch (ActionLockTypeMembers(Member->ID))
		{
		case LockoutTimeLeft:
		{
			Object.DWord = pActionLock->GetLockOutTimeRemaining();
			Object.Type = pUintType;
			break;
		}
		case LockoutTimeTotal:
		{
			Object.DWord = pActionLock->GetTotalLockOutTime();
			Object.Type = pUintType;
			break;
		}
		default: break;
		}
#undef pActionLock
	}
	__except (pExtension->HandleLSTypeCrash(__FUNCTION__, Member->ID, ObjectData.Ptr, argc, argv, GetExceptionCode(), GetExceptionInformation()))
	{

	}
	return true;
}

bool ActionLockType::ToText(LSOBJECTDATA ObjectData, char* buf, unsigned buflen)
{
	if (isxao_utilities::GetGameState() != GAMESTATE_IN_GAME)
		return false;
	if (!ObjectData.Ptr)
		return false;
#define pActionLock ((ActionLock*)ObjectData.Ptr)
	sprintf_s(buf, buflen, "%d", pActionLock->GetLockOutTimeRemaining());
#undef pActionLock
	return true;
}
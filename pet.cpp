#include "isxao_main.h"

namespace isxao_classes
{

	void Pet::Attack()
	{
		pEngineClientAnarchy->N3Msg_SendPetCommand(0, GetIdentity(), PC_ATTACK, 0, nullptr);
	}

	void Pet::Behind()
	{
		pEngineClientAnarchy->N3Msg_SendPetCommand(0, GetIdentity(), PC_BEHIND, 0, nullptr);
	}

	void Pet::Follow()
	{
		pEngineClientAnarchy->N3Msg_SendPetCommand(0, GetIdentity(), PC_FOLLOW, 0, nullptr);
	}

	DWORD Pet::GetPetType()
	{
		return GetSkill(ST_PETTYPE);
	}

	void Pet::Guard()
	{
		pEngineClientAnarchy->N3Msg_SendPetCommand(0, GetIdentity(), PC_GUARD, 0, nullptr);
	}

	void Pet::Heal()
	{
		pEngineClientAnarchy->N3Msg_SendPetCommand(0, GetIdentity(), PC_HEAL, 0, nullptr);
	}

	void Pet::Report()
	{
		pEngineClientAnarchy->N3Msg_SendPetCommand(0, GetIdentity(), PC_REPORT, 0, nullptr);
	}

	void Pet::Terminate()
	{
		pEngineClientAnarchy->N3Msg_SendPetCommand(0, GetIdentity(), PC_TERMINATE, 0, nullptr);
	}

	void Pet::Wait()
	{
		pEngineClientAnarchy->N3Msg_SendPetCommand(0, GetIdentity(), PC_WAIT, 0, nullptr);
	}

}
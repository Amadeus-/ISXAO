#include "isxao_main.h"
#include "dynel.h"
#include "engine_client_anarchy.h"
#include "pet.h"

namespace ao
{
	void pet::attack()
	{
		P_ENGINE_CLIENT_ANARCHY->n3_msg_send_pet_command(0, this->to_dynel()->get_identity(), PC_ATTACK, 0, nullptr);
	}

	void pet::behind()
	{
		P_ENGINE_CLIENT_ANARCHY->n3_msg_send_pet_command(0, this->to_dynel()->get_identity(), PC_BEHIND, 0, nullptr);
	}

	void pet::follow()
	{
		P_ENGINE_CLIENT_ANARCHY->n3_msg_send_pet_command(0, this->to_dynel()->get_identity(), PC_FOLLOW, 0, nullptr);
	}

	DWORD pet::get_pet_type()
	{
		return this->to_dynel()->get_skill(ST_PETTYPE);
	}

	void pet::guard()
	{
		P_ENGINE_CLIENT_ANARCHY->n3_msg_send_pet_command(0, this->to_dynel()->get_identity(), PC_GUARD, 0, nullptr);
	}

	void pet::heal()
	{
		P_ENGINE_CLIENT_ANARCHY->n3_msg_send_pet_command(0, this->to_dynel()->get_identity(), PC_HEAL, 0, nullptr);
	}

	void pet::report()
	{
		P_ENGINE_CLIENT_ANARCHY->n3_msg_send_pet_command(0, this->to_dynel()->get_identity(), PC_REPORT, 0, nullptr);
	}

	void pet::terminate()
	{
		P_ENGINE_CLIENT_ANARCHY->n3_msg_send_pet_command(0, this->to_dynel()->get_identity(), PC_TERMINATE, 0, nullptr);
	}

	void pet::wait()
	{
		P_ENGINE_CLIENT_ANARCHY->n3_msg_send_pet_command(0, this->to_dynel()->get_identity(), PC_WAIT, 0, nullptr);
	}

}
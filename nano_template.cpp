#include "isxao_main.h"
#include "engine_client_anarchy.h"
#include "nano_template.h"
#include "game_time.h"

namespace ao
{

	identity_t nano_template::get_caster_identity()
	{
		return get_data()->caster_identity;
	}

	DWORD nano_template::get_duration()
	{
		return get_data()->duration;
	}

	identity_t nano_template::get_nano_identity()
	{
		return get_data()->nano_identity;
	}

	DWORD nano_template::get_start_time()
	{
		return get_data()->start_time;
	}

	float nano_template::get_time_remaining()
	{
		auto result = float(this->get_start_time() + this->get_duration()) / 100.0f - float(P_GAME_TIME->get_normal_time());
		if (result < 0.0f)
			result = 0.0f;
		return result;
	}

	bool nano_template::nano_template_compare(nano_template &a, nano_template &b)
	{
		return a.get_nano_identity().id < b.get_nano_identity().id;
	}

	bool nano_template::remove()
	{
		return P_ENGINE_CLIENT_ANARCHY->N3Msg_RemoveBuff(get_nano_identity());
	}

}
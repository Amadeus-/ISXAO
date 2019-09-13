#include "isxao_main.h"

namespace isxao_classes
{

	identity_t nano_template::get_caster_identity() const
	{
		return this->get_nano_template_data().caster_identity;
	}

	DWORD nano_template::get_duration() const
	{
		return this->get_nano_template_data().duration;
	}

	identity_t nano_template::get_nano_identity() const
	{
		return this->get_nano_template_data().nano_identity;
	}

	nano_template_t nano_template::get_nano_template_data() const
	{
		return this->nano_template_;
	}

	DWORD nano_template::get_start_time() const
	{
		return this->get_nano_template_data().start_time;
	}

	float nano_template::get_time_remaining() const
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

	bool nano_template::remove() const
	{
		return P_ENGINE_CLIENT_ANARCHY->N3Msg_RemoveBuff(get_nano_identity());
	}

}
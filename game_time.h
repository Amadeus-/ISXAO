#pragma once
#include "game_object.h"
namespace ao
{
	struct ao_game_time;

	typedef ao_game_time game_time_t, *p_game_time_t;

	class game_time : public game_object<game_time_t>
	{
	public:
		unsigned long get_current_day();
		unsigned long get_current_hour();
		unsigned long get_current_minute();
		double get_current_real_time();
		unsigned long get_current_seconds();
		unsigned long get_current_time_in_minutes();
		unsigned long get_current_time_in_seconds();
		double get_dawn_end();
		double get_dawn_start();
		unsigned long get_day_period();
		double get_delta_time();
		double get_dusk_end();
		double get_dusk_start();
		double get_normal_time();
	};
}
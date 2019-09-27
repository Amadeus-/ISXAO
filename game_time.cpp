#include "isxao_main.h"
#include "game_time.h"

namespace ao
{
	DWORD game_time::get_current_day()
	{
		return this->get_data()->current_day;
	}

	DWORD game_time::get_current_hour()
	{
		return this->get_data()->current_hour;
	}

	DWORD game_time::get_current_minute()
	{
		return this->get_data()->current_minute;
	}

	double game_time::get_current_real_time()
	{
		return this->get_data()->current_real_time;
	}

	DWORD game_time::get_current_seconds()
	{
		return this->get_data()->current_second;
	}

	DWORD game_time::get_current_time_in_minutes()
	{
		return this->get_current_minute() + this->get_current_hour() * this->get_data()->minutes_per_hour;
	}

	DWORD game_time::get_current_time_in_seconds()
	{
		return this->get_current_seconds() + this->get_current_minute() * this->get_data()->seconds_per_minute + this->get_current_hour() * this->get_data()->seconds_in_a_hour;
	}

	double game_time::get_dawn_end()
	{
		return double((this->get_data()->hour_of_dawn_start + this->get_data()->dawn_duration_in_hours) * this->get_data()->seconds_in_a_hour);
	}

	double game_time::get_dawn_start()
	{
		return double(this->get_data()->hour_of_dawn_start * this->get_data()->seconds_in_a_hour);
	}

	DWORD game_time::get_day_period()
	{
		return this->get_data()->day_period;
	}

	double game_time::get_delta_time()
	{
		return this->get_data()->delta_time;
	}

	double game_time::get_dusk_end()
	{
		return double((this->get_data()->hour_of_dusk_start + this->get_data()->dusk_duration_in_hours) * this->get_data()->seconds_in_a_hour);
	}

	double game_time::get_dusk_start()
	{
		return double(this->get_data()->hour_of_dusk_start * this->get_data()->seconds_in_a_hour);
	}

	double game_time::get_normal_time()
	{
		return this->get_data()->normal_time;
	}

}
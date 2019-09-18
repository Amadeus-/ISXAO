#include "isxao_main.h"

namespace ao
{

	DWORD game_time::get_current_day() const
	{
		return this->get_game_time_data().current_day;
	}

	DWORD game_time::get_current_hour() const
	{
		return this->get_game_time_data().current_hour;
	}

	DWORD game_time::get_current_minute() const
	{
		return this->get_game_time_data().current_minute;
	}

	double game_time::get_current_real_time() const
	{
		return this->get_game_time_data().current_real_time;
	}

	DWORD game_time::get_current_seconds() const
	{
		return this->get_game_time_data().current_second;
	}

	DWORD game_time::get_current_time_in_minutes() const
	{
		return this->get_current_minute() + this->get_current_hour() * this->get_game_time_data().minutes_per_hour;
	}

	DWORD game_time::get_current_time_in_seconds() const
	{
		return this->get_current_seconds() + this->get_current_minute() * this->get_game_time_data().seconds_per_minute + this->get_current_hour() * this->get_game_time_data().seconds_in_a_hour;
	}

	double game_time::get_dawn_end() const
	{
		return double((this->get_game_time_data().hour_of_dawn_start + this->get_game_time_data().dawn_duration_in_hours) * this->get_game_time_data().seconds_in_a_hour);
	}

	double game_time::get_dawn_start() const
	{
		return double(this->get_game_time_data().hour_of_dawn_start * this->get_game_time_data().seconds_in_a_hour);
	}

	DWORD game_time::get_day_period() const
	{
		return this->get_game_time_data().day_period;
	}

	double game_time::get_delta_time() const
	{
		return this->get_game_time_data().delta_time;
	}

	double game_time::get_dusk_end() const
	{
		return double((this->get_game_time_data().hour_of_dusk_start + this->get_game_time_data().dusk_duration_in_hours) * this->get_game_time_data().seconds_in_a_hour);
	}

	double game_time::get_dusk_start() const
	{
		return double(this->get_game_time_data().hour_of_dusk_start * this->get_game_time_data().seconds_in_a_hour);
	}

	game_time_t game_time::get_game_time_data() const
	{
		return this->game_time_;
	}

	double game_time::get_normal_time() const
	{
		return this->get_game_time_data().normal_time;
	}

}
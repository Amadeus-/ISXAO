#include "isxao_main.h"

namespace isxao_classes
{

	DWORD GameTime::GetCurrentDay() const
	{
		return GetGameTimeData().current_day;
	}

	DWORD GameTime::GetCurrentHour() const
	{
		return GetGameTimeData().current_hour;
	}

	DWORD GameTime::GetCurrentMinute() const
	{
		return GetGameTimeData().current_minute;
	}

	double GameTime::GetCurrentRealTime() const
	{
		return GetGameTimeData().current_real_time;
	}

	DWORD GameTime::GetCurrentSeconds() const
	{
		return GetGameTimeData().current_second;
	}

	DWORD GameTime::GetCurrentTimeInMinutes() const
	{
		return GetCurrentMinute() + GetCurrentHour() * GetGameTimeData().minutes_per_hour;
	}

	DWORD GameTime::GetCurrentTimeInSeconds() const
	{
		return GetCurrentSeconds() + GetCurrentMinute() * GetGameTimeData().seconds_per_minute + GetCurrentHour() * GetGameTimeData().seconds_in_a_hour;
	}

	double GameTime::GetDawnEnd() const
	{
		return double((GetGameTimeData().hour_of_dawn_start + GetGameTimeData().dawn_duration_in_hours) * GetGameTimeData().seconds_in_a_hour);
	}

	double GameTime::GetDawnStart() const
	{
		return double(GetGameTimeData().hour_of_dawn_start * GetGameTimeData().seconds_in_a_hour);
	}

	DWORD GameTime::GetDayPeriod() const
	{
		return GetGameTimeData().day_period;
	}

	double GameTime::GetDeltaTime() const
	{
		return GetGameTimeData().delta_time;
	}

	double GameTime::GetDuskEnd() const
	{
		return double((GetGameTimeData().hour_of_dusk_start + GetGameTimeData().dusk_duration_in_hours) * GetGameTimeData().seconds_in_a_hour);
	}

	double GameTime::GetDuskStart() const
	{
		return double(GetGameTimeData().hour_of_dusk_start * GetGameTimeData().seconds_in_a_hour);
	}

	game_time_t GameTime::GetGameTimeData() const
	{
		return game_time_;
	}

	double GameTime::GetNormalTime() const
	{
		return GetGameTimeData().normal_time;
	}

}
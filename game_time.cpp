#include "isxao_main.h"

namespace isxao_classes
{

	DWORD GameTime::GetCurrentDay() const
	{
		return GetGameTimeData().CurrentDay;
	}

	DWORD GameTime::GetCurrentHour() const
	{
		return GetGameTimeData().CurrentHour;
	}

	DWORD GameTime::GetCurrentMinute() const
	{
		return GetGameTimeData().CurrentMinute;
	}

	double GameTime::GetCurrentRealTime() const
	{
		return GetGameTimeData().CurrentRealTime;
	}

	DWORD GameTime::GetCurrentSeconds() const
	{
		return GetGameTimeData().CurrentSecond;
	}

	DWORD GameTime::GetCurrentTimeInMinutes() const
	{
		return GetCurrentMinute() + GetCurrentHour() * GetGameTimeData().MinutesPerHour;
	}

	DWORD GameTime::GetCurrentTimeInSeconds() const
	{
		return GetCurrentSeconds() + GetCurrentMinute() * GetGameTimeData().SecondsPerMinute + GetCurrentHour() * GetGameTimeData().SecondsInAHour;
	}

	double GameTime::GetDawnEnd() const
	{
		return double((GetGameTimeData().HourOfDawnStart + GetGameTimeData().DawnDurationInHours) * GetGameTimeData().SecondsInAHour);
	}

	double GameTime::GetDawnStart() const
	{
		return double(GetGameTimeData().HourOfDawnStart * GetGameTimeData().SecondsInAHour);
	}

	DWORD GameTime::GetDayPeriod() const
	{
		return GetGameTimeData().DayPeriod;
	}

	double GameTime::GetDeltaTime() const
	{
		return GetGameTimeData().DeltaTime;
	}

	double GameTime::GetDuskEnd() const
	{
		return double((GetGameTimeData().HourOfDuskStart + GetGameTimeData().DuskDurationInHours) * GetGameTimeData().SecondsInAHour);
	}

	double GameTime::GetDuskStart() const
	{
		return double(GetGameTimeData().HourOfDuskStart * GetGameTimeData().SecondsInAHour);
	}

	GAMETIME GameTime::GetGameTimeData() const
	{
		return game_time_;
	}

	double GameTime::GetNormalTime() const
	{
		return GetGameTimeData().NormalTime;
	}

}
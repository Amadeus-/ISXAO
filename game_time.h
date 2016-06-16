#pragma once

class GameTime
{
public:
	AOLIB_OBJECT DWORD GetCurrentDay() const;
	AOLIB_OBJECT DWORD GetCurrentHour() const;
	AOLIB_OBJECT DWORD GetCurrentMinute() const;
	AOLIB_OBJECT double GetCurrentRealTime() const;
	AOLIB_OBJECT DWORD GetCurrentSeconds() const;
	AOLIB_OBJECT DWORD GetCurrentTimeInMinutes() const;
	AOLIB_OBJECT DWORD GetCurrentTimeInSeconds() const;
	AOLIB_OBJECT double GetDawnEnd() const;
	AOLIB_OBJECT double GetDawnStart() const;
	AOLIB_OBJECT DWORD GetDayPeriod() const;
	AOLIB_OBJECT double GetDeltaTime() const;
	AOLIB_OBJECT double GetDuskEnd() const;
	AOLIB_OBJECT double GetDuskStart() const;
	AOLIB_OBJECT GAMETIME GetGameTimeData() const;
	AOLIB_OBJECT double GetNormalTime() const;
private:
	GAMETIME game_time_;
};
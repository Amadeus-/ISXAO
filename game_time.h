#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class game_time
{
public:
	DWORD get_current_day() const;
	DWORD get_current_hour() const;
	DWORD get_current_minute() const;
	double get_current_real_time() const;
	DWORD get_current_seconds() const;
	DWORD get_current_time_in_minutes() const;
	DWORD get_current_time_in_seconds() const;
	double get_dawn_end() const;
	double get_dawn_start() const;
	DWORD get_day_period() const;
	double get_delta_time() const;
	double get_dusk_end() const;
	double get_dusk_start() const;
	ao::game_time_t get_game_time_data() const;
	double get_normal_time() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::game_time_t game_time_;
};
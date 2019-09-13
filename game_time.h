#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class game_time
{
public:
	AOLIB_OBJECT DWORD get_current_day() const;
	AOLIB_OBJECT DWORD get_current_hour() const;
	AOLIB_OBJECT DWORD get_current_minute() const;
	AOLIB_OBJECT double get_current_real_time() const;
	AOLIB_OBJECT DWORD get_current_seconds() const;
	AOLIB_OBJECT DWORD get_current_time_in_minutes() const;
	AOLIB_OBJECT DWORD get_current_time_in_seconds() const;
	AOLIB_OBJECT double get_dawn_end() const;
	AOLIB_OBJECT double get_dawn_start() const;
	AOLIB_OBJECT DWORD get_day_period() const;
	AOLIB_OBJECT double get_delta_time() const;
	AOLIB_OBJECT double get_dusk_end() const;
	AOLIB_OBJECT double get_dusk_start() const;
	AOLIB_OBJECT game_time_t get_game_time_data() const;
	AOLIB_OBJECT double get_normal_time() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	game_time_t game_time_;
};
#include "isxao_main.h"

namespace isxao
{
#pragma region move_loc

	move_loc::move_loc()
	{
		this->location.zero();
		this->cur_distance = 0.0f;
		this->dif_distance = 0.0f;
	}

#pragma endregion

#pragma region move_delay

	// ReSharper disable once CppPossiblyUninitializedMember
	move_delay::move_delay()  // NOLINT(cppcoreguidelines-pro-type-member-init)
	{
		this->min = 0;
		this->max = 0;
		this->resume_ = t_inactive;
	}

	int move_delay::elapsed_ms() const
	{
		SYSTEMTIME     st_current, st_result;
		FILETIME       ft_prev, ft_current, ft_result;
		ULARGE_INTEGER prev, current, result;

		GetSystemTime(&st_current);
		SystemTimeToFileTime(&this->time_began_, &ft_prev);
		SystemTimeToFileTime(&st_current, &ft_current);
		prev.HighPart = ft_prev.dwHighDateTime;
		prev.LowPart = ft_prev.dwLowDateTime;
		current.HighPart = ft_current.dwHighDateTime;
		current.LowPart = ft_current.dwLowDateTime;
		result.QuadPart = current.QuadPart - prev.QuadPart;
		ft_result.dwHighDateTime = result.HighPart;
		ft_result.dwLowDateTime = result.LowPart;
		FileTimeToSystemTime(&ft_result, &st_result);
		return int(st_result.wSecond * 1000 + st_result.wMilliseconds);
	};

	void move_delay::max_delay(const int new_max)
	{
		this->max = new_max;
		if (this->max < this->min + 125)
			this->max = this->min + 125;
	}

	void move_delay::min_delay(const int new_min)
	{
		this->min = new_min;
		if (this->min < 125)
			this->min = 125;
	}

	void move_delay::time_start()
	{
		GetSystemTime(&this->time_began_);
		this->resume_ = rand() & (this->max - this->min + 1) + this->min;
	}

	int move_delay::time_status() const
	{
		if (this->resume_ == t_inactive)
		{
			return t_inactive;
		}
		if (this->elapsed_ms() >= resume_)
		{
			return t_ready;
		}
		return t_waiting;
	}

	void move_delay::time_stop()
	{
		this->resume_ = t_inactive;
	}

	void move_delay::validate()
	{
		this->min_delay(this->min);
		this->max_delay(this->max);
	}

#pragma endregion

#pragma region move_character

	bool move_character::in_combat()
	{
		return g_game_state == GAMESTATE_IN_GAME && P_ENGINE_CLIENT_ANARCHY->get_client_char()->is_fighting();
	}

	bool move_character::is_me(ao::dynel* p_dynel)
	{
		return is_client_id(p_dynel->get_identity().id);
	}

#pragma endregion

#pragma region stuck_logic

	stuck_logic::stuck_logic()
	{
		this->is_on = true;
		this->try_jump = false;
		this->turn_half = true;
		this->turn_size = 10.0f;
		this->dist = 0.1f;
		this->check = 6;
		this->unstuck = 10;
		this->stuck_inc = 0;
		this->stuck_dec = 0;
		this->cur_distance = 1.0f;
	}


	void stuck_logic::reset()
	{
		this->location.zero();
		this->dif_distance = 0.0f;
		this->cur_distance = 0.0f;
		this->stuck_inc = 0;
		this->stuck_dec = 0;
	}

#pragma endregion

	move_to::move_to()
	{
		this->is_on = false;
		this->precise_x = false;
		this->precise_y = false;
	}

	void move_to::activate(const ao::vector3_t& location)
	{
		
	}


}
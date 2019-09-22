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

#pragma region stick_settings

	stick_settings::stick_settings()
	{
		this->min = 1500;
		this->max = 3000;
		this->break_gate = true;
		this->break_hit = false;
		this->break_target = false;
		this->break_warp = true;
		this->pause_warp = false;
		this->flex = false;
		this->randomize = false;
		this->delay_strafe = true;
		this->use_back = true;
		this->use_fleeing = true;
		this->walk = false;
		this->uw = false;
		this->arc_behind = behind_arc;
		this->arc_not_front = not_front_arc;
		this->dist_back = 10.0f;
		this->dist_break = 250.0f;
		this->dist_flex = 7.0f;
		this->dist_mod = 0.0f;
		this->dist_mod_p = 1.0f;
		this->dist_snap = 10.0f;
	}


#pragma endregion

#pragma region camp_settings

	camp_settings::camp_settings()
	{
		this->min = 500;
		this->max = 1500;
		this->have_target = false;
		this->no_aggro = false;
		this->not_looting = false;
		this->scatter = false;
		this->real_time = false;
		this->leash = false;
		this->bearing = 0.0f;
		this->length = 50.0f;
		this->radius = 40.0f;
		this->scat_size = 10.0f;
		this->scat_dist = 10.0f;
	}

	void camp_settings::set_radius(const float new_radius)
	{
		this->radius = new_radius;
	}

	void camp_settings::set_leash(const float new_leash)
	{
		this->length = new_leash;
	}

	void camp_settings::validate_sizes()
	{
		if (this->radius < 5.0f)
			radius = 5.0f;
		const auto temp = this->radius + 5.0f;
		if (this->length < temp)
			this->length = temp;
	}

#pragma endregion

#pragma region move_to_settings

	move_to_settings::move_to_settings()
	{
		this->break_aggro = false;
		this->break_hit = false;
		this->use_back = false;
		this->uw = false;
		this->walk = true;
		this->dist = 10.0f;
		this->dist_back = 30.0f;
		this->dist_x = 10.0f;
		this->dist_y = 10.0f;
		this->mod = 0.0f;
	}

#pragma endregion

#pragma region circle_settings

	circle_settings::circle_settings()
	{
		this->backward = false;
		this->ccw = false;
		this->drunk = false;
		this->circle_mod = 0.0f;
		this->radius = 30.0f;
	}

	void circle_settings::set_radius(const float new_radius)
	{
		this->radius = new_radius;
	}

#pragma endregion

#pragma region move_settings

	move_settings::move_settings()
	{
		p_camp_settings = new camp_settings();
		p_stick_settings = new stick_settings();
		p_move_to_settings = new move_to_settings();
		p_circle_settings = new circle_settings();
		this->auto_save = true;
		this->auto_pause = true;
		this->auto_uw = false;
		this->break_gm = true;
		this->break_summon = false;
		this->break_knock_back = true;
		this->break_mouse = false;
		this->pause_mouse = false;
		this->lock_pause = false;
		this->save_by_char = true;
		this->spin = false;
		this->allow_move = 32.0f;
		this->dist_summon = 8.0f;
		this->turn_rate = 14.0f;
		this->head = h_true;
	}

	move_settings::~move_settings()
	{
		delete p_camp_settings;
		p_camp_settings = nullptr;
		delete p_stick_settings;
		p_stick_settings = nullptr;
		delete p_move_to_settings;
		p_move_to_settings = nullptr;
		delete p_circle_settings;
		p_circle_settings = nullptr;
	}

#pragma endregion

#pragma region circle_command

	void circle_command::at_me()
	{
		const auto p = P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_position();
		const auto h = P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_rotation().get_heading();
		const auto y = p.y + this->radius * sin(h * M_PI / heading_half);
		const auto x = p.x + this->radius * cos(h * M_PI / heading_half);
		this->location.x = x;
		this->location.y = y;
	}

	int circle_command::get_drunk(const int i)
	{
		return (i * rand() / (RAND_MAX + 1));
	}

	bool circle_command::wait()
	{
		if (this->elapsed_ms() > this->max + this->get_drunk(this->min))
		{
			this->time_start();
			return false;
		}
		return true;
	}

	void circle_command::user_defaults()
	{
		this->backward = p_circle_settings->backward;
		this->ccw = p_circle_settings->ccw;
		this->drunk = p_circle_settings->drunk;
		this->circle_mod = p_circle_settings->circle_mod;
		this->radius = p_circle_settings->radius;
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
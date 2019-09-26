#include "isxao_main.h"

namespace isxao
{
	namespace move
	{
#pragma region globals

	bool g_stick_on = false;

#pragma endregion

#pragma region locals

	bool* p_move_loaded = nullptr;
	bool wrapped = false;
	bool offset_override = false;
	verbosity_level verb_level = V_EVERYTHING;

	char message[MAX_VARSTRING] = { 0 };
	char debug_name[MAX_VARSTRING] = { 0 };
	char char_name[MAX_VARSTRING] = { 0 };

	const char on[10] = "ON";
	const char off[10] = "OFF";
	const char arrive_move[50] = "/move_to location";
	const char arrive_camp[50] = "camp from /make_camp return";
	const char arrive_alt_camp[50] = "camp from /make_camp alt_return";

	int auto_run = 0;
	DWORD* p_auto_run = nullptr;
	int forward = 0;
	DWORD* p_forward = nullptr;
	int backward = 0;
	DWORD* p_backward = nullptr;
	int turn_left = 0;
	DWORD* p_turn_left = nullptr;
	int turn_right = 0;
	DWORD* p_turn_right = nullptr;
	int strafe_left = 0;
	DWORD* p_strafe_left = nullptr;
	int strafe_right = 0;
	DWORD* p_strafe_right = nullptr;

	class settings* p_move_settings = nullptr;
	class active* p_move_active = nullptr;
	class character* p_character = nullptr;
	class movement* p_movement = nullptr;
	class stick_command* p_stick_command = nullptr;
	class move_to_command* p_move_to_command = nullptr;
	class circle_command* p_circle_command = nullptr;
	class stuck_logic* p_stuck_logic = nullptr;
	class camp_handler* p_camp_handler = nullptr;
	class alt_camp* p_alt_camp = nullptr;
	class camp_command* p_camp_command = nullptr;
	class pause_handler* p_pause_handler = nullptr;
	class loc* p_summon_loc = nullptr;
	class circle_settings* p_circle_settings = nullptr;
	class move_to_settings* p_move_to_settings = nullptr;
	class camp_settings* p_camp_settings = nullptr;
	class stick_settings* p_stick_settings = nullptr;

#pragma endregion

#pragma region move_loc

	loc::loc()
	{
		this->location.zero();
		this->cur_distance = 0.0f;
		this->dif_distance = 0.0f;
	}

#pragma endregion

#pragma region move_delay

	delay::delay()
	{
		this->min = 0;
		this->max = 0;
		this->resume_ = t_inactive;
	}

	int delay::elapsed_ms() const
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

	void delay::max_delay(const int new_max)
	{
		this->max = new_max;
		if (this->max < this->min + 125)
			this->max = this->min + 125;
	}

	void delay::min_delay(const int new_min)
	{
		this->min = new_min;
		if (this->min < 125)
			this->min = 125;
	}

	void delay::time_start()
	{
		GetSystemTime(&this->time_began_);
		this->resume_ = rand() & (this->max - this->min + 1) + this->min;
	}

	int delay::time_status() const
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

	void delay::time_stop()
	{
		this->resume_ = t_inactive;
	}

	void delay::validate()
	{
		this->min_delay(this->min);
		this->max_delay(this->max);
	}

#pragma endregion

#pragma region move_character

	bool character::in_combat()
	{
		return g_game_state == GAMESTATE_IN_GAME && P_ENGINE_CLIENT_ANARCHY->get_client_char()->is_fighting();
	}

	bool character::is_me(ao::dynel* p_dynel)
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
		this->dist_z = 10.0f;
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

	settings::settings()
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

	settings::~settings()
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

	circle_command::circle_command()
	{
		this->min = 600;
		this->max = 900;
		this->on = false;
		this->user_defaults();
		this->time_start();
	}

	void circle_command::at_loc(const ao::vector3_t l)
	{
		this->location.copy(l);
		this->on = true;
	}

	void circle_command::at_loc(const float x, const float z)
	{
		this->location.zero();
		this->location.x = x;
		this->location.z = z;
		this->on = true;
	}

	void circle_command::at_me()
	{
		const auto p = P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_position();
		const auto h = P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_rotation().get_raw_heading();
		const auto z = float(p.z + this->radius * sin(h * M_PI / heading_half));
		const auto x = float(p.x + this->radius * cos(h * M_PI / heading_half));
		this->location.x = x;
		this->location.z = z;
		this->on = true;
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

#pragma region move_to_command

	move_to_command::move_to_command()
	{
		this->on = false;
		this->precise_x = false;
		this->precise_z = false;
		this->user_defaults();
	}

	void move_to_command::user_defaults()
	{
		this->break_aggro = p_move_to_settings->break_aggro;
		this->break_hit = p_move_to_settings->break_hit;
		this->use_back = p_move_to_settings->use_back;
		this->uw = p_move_to_settings->uw;
		this->walk = p_move_to_settings->walk;
		this->dist_back = p_move_to_settings->dist_back;
		this->dist_z = p_move_to_settings->dist_z;
		this->dist_x = p_move_to_settings->dist_x;
		this->mod = p_move_to_settings->mod;
	}

	void move_to_command::activate(const ao::vector3_t p)
	{
		this->location.zero();
		this->location.copy(p);
		this->on = true;
	}

	void move_to_command::activate(const float x, const float y, const float z)
	{
		this->location.x = x;
		this->location.y = y;
		this->location.z = z;
		this->on = true;
	}

	bool move_to_command::did_aggro() const
	{
		if (p_camp_command->on && this->on && p_character->in_combat())
		{
			p_move_active->move_to_broke = true;
			// TODO: EndPreviousCmd
			sprintf_s(message, sizeof(message), "Aggro gained during /move_to, Halting command...");
			write_line(message, V_BREAK_ON_AGGRO);
			return true;
		}
		return false;
	}

#pragma endregion

#pragma region camp_command

	camp_command::camp_command()
	{
		this->on = false;
		this->pc = false;
		this->redo_stick = false;
		this->redo_circle = false;
		this->pc_identity.zero();
		this->user_defaults();
	}

	void camp_command::user_defaults()
	{
		this->min = p_camp_settings->min;
		this->max = p_camp_settings->max;
		this->have_target = p_camp_settings->have_target;
		this->no_aggro = p_camp_settings->no_aggro;
		this->not_looting = p_camp_settings->not_looting;
		this->scatter = p_camp_settings->scatter;
		this->real_time = p_camp_settings->real_time;
		this->leash = p_camp_settings->leash;
		this->bearing = p_camp_settings->bearing;
		this->length = p_camp_settings->length;
		this->radius = p_camp_settings->radius;
		this->scat_size = p_camp_settings->scat_size;
		this->scat_dist = p_camp_settings->scat_dist;
	}

#pragma endregion

#pragma region alt_camp

	alt_camp::alt_camp()
	{
		this->on = false;
		this->radius = 0.0f;
	}

	void alt_camp::update(camp_command* p_current)
	{
		this->location.copy(p_current->location);
		this->radius = p_current->radius;
		this->on = true;
	}

#pragma endregion

#pragma region camp_handler

	void camp_handler::var_reset()
	{
		this->is_auto = false;
		this->do_alt = false;
		this->do_return = false;
		this->returning = false;
	}

	camp_handler::camp_handler()
	{
		p_alt_camp = new alt_camp();
		p_camp_command = new camp_command();
		this->min = p_camp_settings->min;
		this->max = p_camp_settings->max;
		this->var_reset();
	}	

	camp_handler::~camp_handler()
	{
		delete p_alt_camp;
		p_alt_camp = nullptr;
		delete p_camp_command;
		p_camp_command = nullptr;
	}

	void camp_handler::reset_both()
	{
		delete p_alt_camp;
		p_alt_camp = new alt_camp();
		delete p_camp_command;
		p_camp_command = new camp_command();
	}

	void camp_handler::reset_camp(const bool output)
	{
		p_alt_camp->update(p_camp_command);
		this->new_camp(output);
	}

	void camp_handler::reset_player(const bool output)
	{
		this->new_camp(false);
		if (output)
			this->output_pc();
	}

	void camp_handler::new_camp(const bool output)
	{
		if (g_game_state == GAMESTATE_IN_GAME && p_move_to_command->on && this->returning)
		{
			// TODO: EndPreviousCmd
		}
		delete p_camp_command;
		p_camp_command = new camp_command();
		this->var_reset();
		if (output)
			this->output();
	}

	void camp_handler::activate(const float x, const float z)
	{
		if (p_camp_command->on && !p_camp_command->pc)
		{
			this->reset_camp(false);
		}
		else
		{
			this->new_camp(false);
		}
		p_camp_command->on = true;
		p_camp_command->location.zero();
		p_camp_command->location.x = x;
		p_camp_command->location.z = z;
		this->validate();
	}

	void camp_handler::activate(const ao::vector3_t p)
	{
		if (p_camp_command->on && !p_camp_command->pc)
		{
			this->reset_camp(false);
		}
		else
		{
			this->new_camp(false);
		}
		p_camp_command->on = true;
		p_camp_command->location.copy(p);
		this->validate();
	}

	void camp_handler::activate(ao::dynel* p_dynel)
	{
		const auto p = p_dynel->get_position();
		this->activate(p);
		sprintf_s(p_camp_command->pc_name, "%s", p_dynel->get_name());
		p_camp_command->pc = true;
		p_camp_command->pc_identity.copy(p_dynel->get_identity());
	}

	void camp_handler::output() const
	{
		sprintf_s(message, sizeof(message), "MakeCamp off.");
		write_line(message, V_MAKE_CAMP_V);
	}

	void camp_handler::output_pc() const
	{
		sprintf_s(message, sizeof(message), "MakeCamp player off.");
		write_line(message, V_MAKE_CAMP_V);
	}

#pragma endregion

#pragma region snap_roll

	snap_roll::snap_roll()
	{
		this->head = 0.0f;
		this->bearing = heading_half;
	}

#pragma endregion 

#pragma region stick_command

	stick_command::stick_command()
	{
		this->snap = new isxao::move::snap_roll();
		this->set_dist = false;
		this->dist = 0.0f;
		this->rand_min = 0.0f;
		this->rand_max = 0.0f;
		this->rand_flag = true;
		this->move_back = false;
		this->behind = false;
		this->behind_once = false;
		this->front = false;
		this->not_front = false;
		this->pin = false;
		this->snap_roll = false;
		this->hold = false;
		this->healer = false;
		this->always = false;
		this->have_target = false;
		this->strafe = false;
		this->on = false;
		this->last_target_id.zero();
		this->hold_id.zero();
		this->always_ready_ = true;
		this->user_defaults();
	}

	stick_command::~stick_command()
	{
		delete this->snap;
		this->snap = nullptr;
	}

	void stick_command::turn_on()
	{
		this->on = true;
		g_stick_on = true;
	}

	void stick_command::stop_hold()
	{
		this->hold_id.zero();
		this->hold = false;
	}

	void stick_command::first_always()
	{
		this->stop_hold();
		this->always = true;
		this->turn_on();
		if (P_SELECTION_INDICATOR)
		{
			this->have_target = true;
			return;
		}
		this->have_target = false;
	}

	void stick_command::new_snap_roll()
	{
		delete this->snap;
		this->snap = new isxao::move::snap_roll();
	}

	void stick_command::reset_loc()
	{
		this->location.zero();
		this->cur_distance = 0.0f;
		this->dif_distance = 0.0f;
	}

	void stick_command::do_randomize()
	{
		if (!this->randomize)
			return;
		if (this->not_front)
		{
			this->set_rand_arc(not_front_arc);
		}
		else if (this->behind)
		{
			this->set_rand_arc(behind_arc);
		}
		else if (this->pin)
		{
			this->set_rand_arc(pin_arc_min);
		}
	}

	void stick_command::user_defaults()
	{
		this->min = p_stick_settings->min;
		this->max = p_stick_settings->max;
		this->break_gate = p_stick_settings->break_gate;
		this->break_hit = p_stick_settings->break_hit;
		this->break_target = p_stick_settings->break_target;
		this->break_warp = p_stick_settings->break_warp;
		this->pause_warp = p_stick_settings->pause_warp;
		this->randomize = p_stick_settings->randomize;
		this->delay_strafe = p_stick_settings->delay_strafe;
		this->use_back = p_stick_settings->use_back;
		this->use_fleeing = p_stick_settings->use_fleeing;
		this->uw = p_stick_settings->uw;
		this->walk = p_stick_settings->walk;
		this->arc_behind = p_stick_settings->arc_behind;
		this->arc_not_front = p_stick_settings->arc_not_front;
		this->dist_back = p_stick_settings->dist_back;
		this->dist_break = p_stick_settings->dist_break;
		this->dist_mod = p_stick_settings->dist_mod;
		this->dist_mod_p = p_stick_settings->dist_mod_p;
		this->dist_snap = p_stick_settings->dist_snap;
	}

	void stick_command::set_rand_arc(const int arc_type)
	{
		auto temp_arc = 0.0f;
		auto arc_size = 0.0f;
		float* p_random_arc = nullptr;
		float* p_stable_arc = nullptr;

		this->rand_flag = !this->rand_flag;
		if (this->rand_flag)
		{
			p_random_arc = &this->rand_min;
			p_stable_arc = &this->rand_max;
		}
		else
		{
			p_random_arc = &this->rand_max;
			p_stable_arc = &this->rand_min;
		}

		// ReSharper disable once CppDefaultCaseNotHandledInSwitchStatement
		switch(arc_type)
		{
		case pin_arc_min:
			temp_arc = float(rand() % 32 + 5);
			arc_size = float(rand() % 32 + 15);
			break;
		case behind_arc:
			temp_arc = float(rand() % 45 + 5);
			arc_size = float(rand() % 90 + 40);
			break;
		case not_front_arc:
			temp_arc = float(rand() % 135 + 5);
			arc_size = float(rand() % 270 + 80);
			break;
		}

		*p_random_arc = temp_arc;
		*p_stable_arc = arc_size;

		sprintf_s(message, "Arcs randomized! Max: %.2f Min: %.2f", this->rand_max, this->rand_min);
		write_line(message, V_RANDOMIZE);
	}

	bool stick_command::ready()
	{
		if (this->always)
		{
			return this->always_status();
		}
		return this->on;
	}

	bool stick_command::always_status()
	{
		if (P_SELECTION_INDICATOR)
		{
			auto const p_dynel = ao::dynel::get_dynel(P_SELECTION_INDICATOR->identity);
			if (p_dynel && (p_dynel->get_identity().type != 50000))
			{
				if (this->always_ready_)
				{
					sprintf_s(message, sizeof(message), "Stick awaiting next valid NPC target...");
					write_line(message, V_STICK_ALWAYS);
					p_movement->stop_move(apply_to_all);
					this->do_randomize();
					this->always_ready_ = false;
				}
				this->have_target = false;
				return false;
			}
		}

		if (!this->always_ready_)
		{
			// TODO: EndPreviousCmd
			p_pause_handler->reset();
			p_movement->do_stand();
			p_movement->stop_heading();
			this->always_ready_ = true;
		}

		this->have_target = true;
		return true;
	}

#pragma endregion

#pragma region pause_handler

	pause_handler::pause_handler()
	{
		this->min = 500;
		this->max = 5000;
		this->paused_command = false;
		this->paused_move = false;
		this->user_kb = false;
		this->user_mouse = false;
		this->handle_mouse_ = false;
		this->handle_kb_ = false;
	}

	bool pause_handler::waiting() const
	{
		return this->paused_command || this->paused_move;
	}

	void pause_handler::handle_pause()
	{
		if (this->paused_command)
			return;
		if (this->mouse_check())
			return;
		this->mouse_free();
		this->pause_timers();
	}

	void pause_handler::pause_timers()
	{
		if (this->paused_move && !this->user_kb)
		{
			if (p_stick_command->on && (!p_stick_command->always || (p_stick_command->always && p_stick_command->have_target)))
			{
				ao::dynel* p_target = nullptr;
				if (p_stick_command->hold)
					p_target = ao::dynel::get_dynel(p_stick_command->hold_id);
				else if (P_SELECTION_INDICATOR)
					p_target = ao::dynel::get_dynel(P_SELECTION_INDICATOR->identity);
				if (!p_target || (p_stick_command->hold && p_stick_command->hold_id != p_target->get_identity()))
				{
					this->reset();
					// TODO: EndPreviousCmd
					sprintf_s(message, sizeof(message), "You are no longer sticking to anything.");
					write_line(message, V_STICK_V);
					return;
				}
			}
			switch (this->time_status())
			{
			case t_inactive:
			case t_waiting:
				break;
			case t_ready:
			default:
				this->paused_move = false;
				if (!p_camp_handler->is_auto)
				{
					sprintf_s(message, sizeof(message), "Resuming previous command from movement pause");
					write_line(message, V_MOVE_PAUSE);
				}
				this->reset();
				break;
			}
		}
	}

	void pause_handler::mouse_free()
	{
		if (this->handle_mouse_)
		{
			this->handle_mouse_ = false;
			if (this->pause_needed())
			{
				this->time_start();
			}
		}
	}

	bool pause_handler::pause_needed()
	{
		if (p_circle_command->on || p_stick_command->on || p_move_to_command->on || p_camp_handler->is_auto)
		{
			if (p_stick_command->on && (!p_stick_command->always || (p_stick_command->always && p_stick_command->have_target)))
			{
				ao::dynel* p_target = nullptr;
				if (p_stick_command->hold)
					p_target = ao::dynel::get_dynel(p_stick_command->hold_id);
				else if (P_SELECTION_INDICATOR)
					p_target = ao::dynel::get_dynel(P_SELECTION_INDICATOR->identity);
				if (!p_target || (p_stick_command->hold && p_stick_command->hold_id != p_target->get_identity()))
				{
					this->reset();
					if (!this->user_kb)
						this->paused_move = false;
					// TODO:: EndPreviousCmd
					sprintf_s(message, sizeof(message), "You are no longer sticking to anything.");
					write_line(message, V_STICK_V);
					return false;
				}
			}
			return true;
		}
		return false;
	}

	bool pause_handler::mouse_check()
	{
		if (MOUSE_LOOK_ACTIVE)
		{
			this->user_mouse = true;
			if ((p_move_settings->pause_mouse || p_move_settings->break_mouse) && this->pause_needed())
			{
				p_camp_handler->time_stop();
				this->time_stop();
				p_movement->stop_heading();
				if(p_move_settings->break_mouse)
				{
					// TODO: EndPreviousCmd
					if(!p_camp_handler->is_auto)
					{
						sprintf_s(message, sizeof(message), "Current command ended from mouse movement.");
						write_line(message, V_MOUSE_PAUSE);
					}
					return false;
				}
				this->paused_move = true;
				p_movement->do_move(apply_to_all, false, move_walk_off);
				this->handle_mouse_ = true;
				return true;
			}
			this->user_mouse = false;
			return false;
		}
		return false;
	}

	void pause_handler::reset()
	{
		p_camp_handler->time_stop();
		p_stuck_logic->reset();
		p_move_active->command_forward = false;
		p_move_active->command_strafe = false;
		p_move_active->new_summon();
		p_stick_command->new_snap_roll();
		p_stick_command->time_stop();
		p_stick_command->reset_loc();
	}

#pragma endregion

#pragma region move_active

	active::active()
	{
		p_stick_command = new stick_command();
		p_move_to_command = new move_to_command();
		p_circle_command = new circle_command();
		p_camp_handler = new camp_handler();
		p_pause_handler = new pause_handler();
		p_stuck_logic = new stuck_logic();
		p_summon_loc = new loc();

		this->aggro = false;
		this->broke_gm = false;
		this->broke_summon = false;
		this->command_forward = false;
		this->command_strafe = false;
		this->fix_walk = false;
		this->key_binds = false;
		this->key_killed = false;
		this->loaded = false;
		this->lock_pause = false;
		this->move_to_broke = false;
		this->rooted = false;
		this->stick_broke = false;
		this->stopped_move_to = false;
		this->head = h_true;
		this->defaults();
	}

	active::~active()
	{
		delete p_stick_command;
		p_stick_command = nullptr;
		delete p_move_to_command;
		p_move_to_command = nullptr;
		delete p_circle_command;
		p_circle_command = nullptr;
		delete p_camp_command;
		p_camp_command = nullptr;
		delete p_pause_handler;
		p_pause_handler = nullptr;
		delete p_stuck_logic;
		p_stuck_logic = nullptr;
		delete p_summon_loc;
		p_summon_loc = nullptr;
	}

	void active::defaults()
	{
		this->head = p_move_settings->head;
		this->lock_pause = p_move_settings->lock_pause;
	}

	void active::new_stick()
	{
		p_camp_command->redo_stick = false;
		g_stick_on = false;
		delete p_stick_command;
		p_stick_command = new stick_command();
	}

	void active::new_move_to()
	{
		p_camp_handler->var_reset();
		delete p_move_to_command;
		p_move_to_command = new move_to_command();
	}

	void active::new_circle()
	{
		p_camp_command->redo_circle = false;
		delete p_circle_command;
		p_circle_command = new circle_command();
	}

	void active::new_commands()
	{
		active::new_stick();
		active::new_move_to();
		active::new_circle();
	}

	void active::new_summon()
	{
		delete p_summon_loc;
		p_summon_loc = new loc();
	}

	void active::new_defaults()
	{
		active::new_commands();
		active::new_summon();
		p_stuck_logic->reset();
		p_camp_handler->reset_both();
		this->defaults();
	}

	bool active::is_active()
	{
		return p_stick_command->on || p_move_to_command->on || p_circle_command->on || p_camp_handler->returning;
	}

	void active::aggro_tlo()
	{
		// TODO: Resolve this
	}

	bool active::broken() const
	{
		return this->broke_gm || this->broke_summon;
	}


#pragma endregion

#pragma region move_movement

	movement::movement()
	{
		this->change_head = h_inactive;
		this->root_head = 0.0f;
	}

	void movement::auto_head() const
	{
		if (this->change_head == h_inactive)
			return;
		this->turn_head(this->change_head);
	}

	void movement::new_head(const float new_heading)
	{
		if (g_game_state != GAMESTATE_IN_GAME)
			return;
		switch(p_move_active->head)
		{
		case h_loose:
		case h_true:
			this->change_head = new_heading;
			break;
		case h_fast:
		default:
			movement::fast_turn(new_heading);
			break;
		}
	}

	void movement::new_face(const float new_face)
	{
		if (g_game_state != GAMESTATE_IN_GAME)
			return;
		switch(p_move_active->head)
		{
			case h_loose:
			case h_true:
			case h_fast:
			default:
				movement::fast_turn(new_face);
				break;
		}
	}

	void movement::stop_heading() const
	{
		if (this->change_head != h_inactive)
		{
			this->turn_head(P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_heading());
		}
	}

	float movement::sane_head(float heading)
	{
		if (heading >= heading_max)
			heading -= heading_max;
		if (heading < 0.0f)
			heading += heading_max;
		return heading;
	}

	void movement::do_root()
	{
		if (!p_move_active->rooted || g_game_state != GAMESTATE_IN_GAME)
			return;
		if (offset_override)
		{
			this->stop_root();
			return;
		}
		this->change_head = h_inactive;
		P_ENGINE_CLIENT_ANARCHY->get_client_char()->face(this->root_head);
		movement::true_move_off(apply_to_all);
	}

	void movement::stop_root()
	{
		if (!p_move_active->rooted)
			return;
		p_move_active->rooted = false;
		this->root_head = 0.0f;
		char temp_out[MAX_VARSTRING] = { 0 };
		sprintf_s(temp_out, sizeof(temp_out), "You are no longer rooted");
		write_line(message, V_SILENCE);
	}

	float movement::ang_dist(float heading_1, float heading_2) const
	{
		if (fabs(heading_1 - heading_2) > heading_half)
		{
			(heading_1 < heading_2 ? heading_1 : heading_2) += heading_max;
		}
		return (fabs(heading_1 - heading_2) > heading_half) ? (heading_2 - heading_1) : (heading_1 - heading_2);
	}

	float movement::ang_dist(ao::quaternion_t& rotation_1, ao::quaternion_t& rotation_2) const
	{
		const auto heading_1 = rotation_1.get_heading();
		const auto heading_2 = rotation_2.get_heading();
		return this->ang_dist(heading_1, heading_2);
	}

	bool movement::can_move(const float heading, const float x, const float z) const
	{
		if (g_game_state != GAMESTATE_IN_GAME)
			return false;
		ao::vector3_t loc(x, 0.0f, z);
		const auto head_diff = fabs(P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_heading() - heading);
		if (head_diff > p_move_settings->allow_move)
		{
			return false;
		}
		if ((head_diff / 2.0f) > fabs(P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_distance_to(loc)))
		{
			return false;
		}
		return true;
	}

	bool movement::can_move(const float heading, ao::vector3_t& loc) const
	{
		return this->can_move(heading, loc.x, loc.z);
	}

	bool movement::can_move(ao::quaternion_t& rotation, ao::vector3_t& loc) const
	{
		return this->can_move(rotation.get_heading(), loc.x, loc.z);
	}

	void movement::set_walk(const bool on)
	{
		if (g_game_state != GAMESTATE_IN_GAME)
			return;
		if ((on && !P_ENGINE_CLIENT_ANARCHY->get_client_char()->is_walking()) || (!on && P_ENGINE_CLIENT_ANARCHY->get_client_char()->is_walking()))
		{
			P_FLOW_CONTROL->slot_walk_toggle(false);

		}
	}

	void movement::do_stand()
	{
		if (g_game_state != GAMESTATE_IN_GAME)
			return;
		P_ENGINE_CLIENT_ANARCHY->get_client_char()->stand();
	}

	void movement::do_move(const byte direction, const bool turn_on = true, const byte walk = move_walk_off)
	{
		// ReSharper disable once CppDefaultCaseNotHandledInSwitchStatement
		switch(walk)  // NOLINT(hicpp-multiway-paths-covered)
		{
		case move_walk_on:
			movement::set_walk(true);
			break;
		case move_walk_off:
			movement::set_walk(false);
			break;
		case move_walk_ignore:
			break;
		}
		if (turn_on)
		{
			movement::true_move_on(direction);
			return;
		}
		movement::true_move_off(direction);
	}

	void movement::walk(const byte direction)
	{
		movement::do_move(direction, true, move_walk_on);
	}

	void movement::try_move(const byte direction, const byte walk, const float heading, const float x , const float z) const
	{
		movement::do_move(direction, can_move(heading, x, z), walk);
	}

	void movement::stop_move(const byte direction)
	{
		movement::true_move_off(direction);
	}

	void movement::stick_strafe(const byte direction)
	{
		if (p_stick_command->delay_strafe)
		{
			movement::timed_strafe(direction);
			return;
		}
		movement::do_move(direction, true, p_stick_command->walk ? move_walk_on : move_walk_ignore);
	}

	void movement::timed_strafe(const byte direction)
	{
		const byte result = p_stick_command->time_status();
		if(p_move_active->command_strafe && result == t_inactive)
		{
			movement::stop_move(kill_strafe);
			p_stick_command->time_start();
			return;
		}
		if (result == t_ready)
		{
			movement::do_move(direction, true, p_stick_command->walk ? move_walk_on : move_walk_ignore);
		}
	}

	void movement::turn_head(const float heading) const
	{
		if (g_game_state != GAMESTATE_IN_GAME)
			return;
		switch (p_move_active->head)
		{
		case h_loose:
		case h_true:
			this->loose_turn(heading);
			break;
		case h_fast:
			movement::fast_turn(heading);
		default:
			break;
		}
	}

	void movement::fast_turn(const float heading)
	{
		if (g_game_state != GAMESTATE_IN_GAME)
			return;
		P_ENGINE_CLIENT_ANARCHY->get_client_char()->face(heading);
		
	}

	void movement::loose_turn(const float new_heading) const
	{
		if (g_game_state != GAMESTATE_IN_GAME)
		{
			if (fabs(P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_heading() - new_heading) < p_move_settings->turn_rate)
			{
				movement::fast_turn(new_heading);
			}
			else
			{
				const auto comp_head = P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_heading() + heading_half;
				if (new_heading < comp_head)
				{
					movement::fast_turn(movement::sane_head(P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_heading() + p_move_settings->turn_rate));
				}
				else
				{
					movement::fast_turn(movement::sane_head(P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_heading() - p_move_settings->turn_rate));
				}
			}
		}
	}

	void movement::true_turn(float new_heading)
	{
		if (g_game_state != GAMESTATE_IN_GAME)
			return;
		if (fabs(P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_heading()) - new_heading < 14.0f)
		{
			movement::fast_turn(new_heading);
			this->change_head = h_inactive;
		}
		else
		{
			auto const comp_head = P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_heading() + heading_half;

			if (new_heading < P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_heading())
				new_heading += heading_max;
			if (new_heading < comp_head)
			{
				P_FLOW_CONTROL->slot_movement_right(true);
				P_FLOW_CONTROL->slot_movement_left(false);
			}
			else
			{
				P_FLOW_CONTROL->slot_movement_left(true);
				P_FLOW_CONTROL->slot_movement_right(false);
			}
		}
	}

	void movement::true_move_on(const byte direction)
	{  
		// ReSharper disable once CppDefaultCaseNotHandledInSwitchStatement
		switch(direction)	// NOLINT(hicpp-multiway-paths-covered)
		{
		case go_forward:
			p_move_active->command_forward = true;
			P_FLOW_CONTROL->slot_movement_back(true);
			P_FLOW_CONTROL->slot_movement_forward(false);
			break;
		case go_backward:
			p_move_active->command_forward = false;
			P_FLOW_CONTROL->slot_movement_forward(true);
			P_FLOW_CONTROL->slot_movement_back(false);
			break;
		case go_left:
			p_move_active->command_strafe = true;
			P_FLOW_CONTROL->slot_movement_strafe_right(true);
			P_FLOW_CONTROL->slot_movement_strafe_left(false);
			break;
		case go_right:
			p_move_active->command_strafe = true;
			P_FLOW_CONTROL->slot_movement_strafe_left(true);
			P_FLOW_CONTROL->slot_movement_strafe_right(false);
			break;
		}
	}

	void movement::true_move_off(const byte direction)
	{
		switch(direction)
		{
		case apply_to_all:
			P_FLOW_CONTROL->slot_movement_strafe_left(true);
			P_FLOW_CONTROL->slot_movement_strafe_right(true);
			P_FLOW_CONTROL->slot_movement_forward(true);
			P_FLOW_CONTROL->slot_movement_back(true);
			p_move_active->command_forward = false;
			p_move_active->command_strafe = false;
			p_stick_command->time_stop();
			break;
		case go_forward:
			P_FLOW_CONTROL->slot_movement_forward(true);
			p_move_active->command_forward = false;
			break;
		case go_backward:
			P_FLOW_CONTROL->slot_movement_back(true);
			p_move_active->command_forward = false;
			break;
		case go_left:
			P_FLOW_CONTROL->slot_movement_strafe_left(true);
			p_move_active->command_strafe = false;
			p_stick_command->time_stop();
			break;
		case go_right:
			P_FLOW_CONTROL->slot_movement_strafe_right(true);
			p_move_active->command_strafe = false;
			p_stick_command->time_stop();
			break;
		case kill_strafe:
			P_FLOW_CONTROL->slot_movement_strafe_left(true);
			P_FLOW_CONTROL->slot_movement_strafe_right(true);
			p_move_active->command_strafe = false;
			p_stick_command->time_stop();
			break;
		case kill_fb:
			P_FLOW_CONTROL->slot_movement_forward(true);
			P_FLOW_CONTROL->slot_movement_back(true);
			p_move_active->command_forward = false;
			break;
		}
	}


#pragma endregion

#pragma region Functions

	void spew_move_error(const byte error_num)
	{
		char error_msg[MAX_VARSTRING] = { 0 };
		switch(error_num)
		{
		case error_stick_self:
			sprintf_s(error_msg, sizeof(error_msg), "[ERROR] You cannot stick to yourself!");
			break;
		case error_stick_none:
			sprintf_s(error_msg, sizeof(error_msg), "[ERROR] You must specify something to stick to!");
			break;
		case error_bad_move_to:
			end_previous_cmd(true);
			sprintf_s(error_msg, sizeof(error_msg), "[ERROR] /move_to loc [ <X> <Z> [y] ] was supplied incorrectly.");
			break;
		case error_bad_make_camp:
			end_previous_cmd(true);
			sprintf_s(error_msg, sizeof(error_msg), "[ERROR} /make_camp loc [ <X> <Z> ] was supplied incorrectly.");
			break;
		case error_bad_circle:
			end_previous_cmd(true);
			sprintf_s(error_msg, sizeof(error_msg), "[ERROR} Usage /circle loc [ <x> <z> ] [other options].");
			break;
		case error_bad_actor:
			end_previous_cmd(true);
			sprintf_s(error_msg, sizeof(error_msg), "[ERROR} Invalid actor id and do not have a valid target.");
			break;
		case error_bad_delay:
			sprintf_s(error_msg, sizeof(error_msg), "[ERROR} [min_delay|max_delay] [#] was supplied incorrectly.");
			break;
		default:
			return;
		}
		write_line(error_msg, V_ERRORS);
	}

	void output_help(const byte cmd_used, bool only_cmd_help)
	{
		if (g_game_state != GAMESTATE_IN_GAME)
			return;
		char command[20] = { 0 };
		bool display_settings = false;

		switch(cmd_used)
		{
		case command_make_camp:
			sprintf_s(command, "/make_camp");
			break;
		case command_stick:
			sprintf_s(command, "/stick");
			break;
		case command_move_to:
			sprintf_s(command, "/move_to");
			break;
		case command_circle:
			sprintf_s(command, "/circle");
			break;
		case help_settings:
			display_settings = true;
			break;
		}

		char temp_output[MAX_VARSTRING] = { 0 };
		sprintf_s(temp_output, "Move");
		write_line(temp_output, V_SILENCE);

		if (display_settings)
		{
			write_line("The following settings can be changed with any of the 4 commands. There are three options (using /stick as an example).", V_SILENCE);
			write_line("/stick [set] [setting] [on | off] - This will turn the setting on or off", V_SILENCE);
			write_line("/stick [set] [setting] [#] - This will change settings that use numerical values", V_SILENCE);
			write_line("/stick [toggle] [setting] - This will toggle the setting on and off.", V_SILENCE);
			write_line("The following settings can be set on/off OR toggled:", V_SILENCE);
			write_line("[auto_save] - Automatic saving of configuration file each time you change a setting.", V_SILENCE);
			write_line("[feign] - Stay-FD support, awaiting you to manually stand before resuming command.", V_SILENCE);
			write_line("[break_on_kb|break_on_mouse] - End command from manual keyboard/mouse movement.", V_SILENCE);
			write_line("[m_pause|mouse_pause] - Pause from manual keyboard/mouse movement. Resumes after pause_min_delay/pause_max_delay values.", V_SILENCE);
			write_line("[auto_pause] - Automatic pause & resume command when casting, stunned, targeting self.", V_SILENCE);
			write_line("[verbosity|full_verbosity] - MQ2ChatWnd command output and detailed output.", V_SILENCE);
			write_line("[hide_help] - Hides help output from showing automatically on command failures.", V_SILENCE);
			write_line("[total_silence] - Hide all MQ2ChatWnd output except critical warnings and requested information.", V_SILENCE);
			write_line("[stuck_logic] - Automatic detection of stuck movement and attempted correction.", V_SILENCE);
			write_line("[try_to_jump] - Try to jump as part of stuck logic getting over obstacles.", V_SILENCE);
			write_line("[turn_half] - Reset heading and try the other way if halfway from destination in stuck logic.", V_SILENCE);
			write_line("[no_hott_front] - Awareness for stick front to not spin if loose aggro.", V_SILENCE);
			write_line("[save_by_char] - Save character-specific settings to [CharName] section of configuration file.", V_SILENCE);
			write_line("[break_on_summon] - Halt plugin if character summoned beyond certain distance in a single pulse.", V_SILENCE);
			write_line("[use_walk] - Walk when closing in on move_to / camp return locations for precision.", V_SILENCE);
			write_line("[always_true_head] - Use legit heading adjustments with right/left keys.", V_SILENCE);
			write_line("The following settings use a numerical value:", V_SILENCE);
			write_line("[pulse_check] [#] - Set number of frames used to calculate moving average for stuck logic. (default 4)", V_SILENCE);
			write_line("[pulse_unstuck] [#] - Set number of frames successfully moved forward to consider unstuck (default 5)", V_SILENCE);
			write_line("[dist_stuck] [#.###] - Set distance needed to move per pulse to not be considered stuck. (default 0.5)", V_SILENCE);
			write_line("[camp_min_delay|camp_max_delay|pause_min_delay|pause_max_delay] [#] - Set camp return or m_pause/mouse_pause delays.", V_SILENCE);
			write_line("[turn_rate] [#.##] (1.0 to 100.0) - Set increment used for loose heading turns.", V_SILENCE);
			return;
		}

		// TODO: Finish this
	}

	void write_line(char output[MAX_VARSTRING], const verbosity_level v_compare)
	{
		if (verb_level == V_SILENCE)
			return;

		if ((v_compare == V_SILENCE) || (verb_level & V_EVERYTHING) == V_EVERYTHING || (verb_level & v_compare) == v_compare)
		{
			printf("%s", output);
			gp_isxao_log->add_line("%s", output);
		}
	}

	void handle_our_cmd(const byte cmd_used, int begin_inclusive, int argc, char *argv[])
	{
		if (g_game_state != GAMESTATE_IN_GAME)
			return;
		char current_arg[MAX_VARSTRING] = { 0 };
		char temp_id[MAX_VARSTRING] = { 0 };
		DWORD arg_num = begin_inclusive;
		auto temp_z = 0.0f;

		ao::actor* p_target_used = nullptr;
		ao::actor* p_camp_player = nullptr;
		ao::actor* p_target;
		if (P_SELECTION_INDICATOR)
		{
			p_target = static_cast<ao::actor*>(ao::dynel::get_dynel(P_SELECTION_INDICATOR->identity));
		}
		else
			p_target = nullptr;
		auto p_character = P_ENGINE_CLIENT_ANARCHY->get_client_char();

		if ((rand() & 100) > 50)
			p_stuck_logic->turn_size *= -1.0f;

		if (cmd_used == command_move_to)
		{
			p_move_active->stopped_move_to = false;
			p_move_active->move_to_broke = false;
		}

		if (cmd_used == command_stick)
		{
			p_move_active->stick_broke = false;
		}

		get_arg(current_arg, argc, argv, arg_num);
		arg_num++;
		if (!*current_arg)
		{
			if (p_move_active->broke_gm || p_move_active->broke_summon)
			{
				sprintf_s(message, "Command failed due to %s triggering", p_move_active->broke_gm ? "break_on_gm" : "break_on_summon");
				write_line(message, V_SILENCE);
				return;
			}

			if (p_move_active->rooted)
			{
				sprintf_s(message, "Command failed due to /root_me active.");
				write_line(message, V_SILENCE);
				return;
			}

			if (p_pause_handler->paused_command && p_move_active->lock_pause)
			{
				sprintf_s(message, "Command failed due to plugin paused with lock_pause.");
				write_line(message, V_PAUSED);
			}

			p_pause_handler->paused_move = false;

			switch (cmd_used)
			{
			case command_make_camp:
				if (!p_camp_command->on)
				{
					p_pause_handler->time_stop();
					p_camp_handler->activate(p_character->get_position());
					sprintf_s(message, "MakeCamp activated. X(%.2f) Z(%.2f) Radius(%.2f) Leash(%s) LeashLen(%.2f) Min(%d) Max(%d)", 
						p_camp_command->location.x, p_camp_command->location.z, p_camp_command->radius, p_camp_command->leash ? "on" : "off", p_camp_command->length, p_camp_handler->min, p_camp_handler->max);
					write_line(message, V_MAKE_CAMP_V);
					break;
				}
				p_camp_handler->reset_camp(true);
				break;
			case command_stick:
				end_previous_cmd(true);
				if (p_target)
				{
					if(is_client_id(p_target->get_identity().id))
					{
						spew_move_error(error_stick_self);
					}
					p_stick_command->turn_on();
					p_movement->do_stand();
					sprintf_s(message, "You are now sticking to %s.", p_target->get_name());
					write_line(message, V_STICK_V);
					break;
				}
				spew_move_error(error_stick_none);
				break;
			case command_move_to:
			case command_circle:
			default:
				end_previous_cmd(true);
				sprintf_s(message, "[ERROR] /move_to or /circle command used with no parameter.");
				write_line(message, V_ERRORS);
				break;
			}
			return;
		}
	}

	void end_previous_cmd(bool stop_move, byte cmd_used, bool preserve_self)
	{
		p_pause_handler->paused_move = false;
		p_pause_handler->paused_command = false;
		p_pause_handler->time_stop();
		p_pause_handler->reset();

		if (cmd_used != command_circle || !preserve_self)
		{
			p_move_active->new_circle();
		}
		if (cmd_used != command_move_to || !preserve_self)
		{
			p_move_active->new_move_to();
		}
		if (cmd_used != command_stick || !preserve_self)
		{
			p_move_active->new_stick();
		}

		p_move_active->defaults();
		p_movement->set_walk(false);
		// TODO: SetupEvents
		if (stop_move)
		{
			p_movement->stop_heading();
			p_movement->stop_move(apply_to_all);
		}
	}

#pragma endregion


	}
}
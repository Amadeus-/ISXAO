#include "isxao_main.h"
#include "navigation.h"
#include "dynel.h"
#include "character.h"
#include "engine_client_anarchy.h"
#include "flow_control.h"
#include "game_time.h"
#include "input_config.h"

namespace isxao
{
	namespace navigation
	{
		timer::timer()
		{
			this->is_active_ = false;
		}

		unsigned long long timer::elapsed_ms() const
		{
			SYSTEMTIME     st_current, st_result;
			FILETIME       ft_prev, ft_current, ft_result;
			ULARGE_INTEGER prev, current, result;

			GetSystemTime(&st_current);
			SystemTimeToFileTime(&this->start_, &ft_prev);
			if (this->is_active_)
				SystemTimeToFileTime(&st_current, &ft_current);
			else
				SystemTimeToFileTime(&this->stop_, &ft_current);
			prev.HighPart = ft_prev.dwHighDateTime;
			prev.LowPart = ft_prev.dwLowDateTime;
			current.HighPart = ft_current.dwHighDateTime;
			current.LowPart = ft_current.dwLowDateTime;
			result.QuadPart = current.QuadPart - prev.QuadPart;
			ft_result.dwHighDateTime = result.HighPart;
			ft_result.dwLowDateTime = result.LowPart;
			FileTimeToSystemTime(&ft_result, &st_result);
			return unsigned long long(st_result.wHour * 60 * 60 * 1000 + st_result.wMinute * 60 * 1000 + st_result.wSecond * 1000 + st_result.wMilliseconds);
		}

		void timer::reset()
		{
			GetLocalTime(&this->stop_);
			GetLocalTime(&this->start_);			
		}

		void timer::start_timer()
		{
			GetLocalTime(&this->start_);
			this->is_active_ = true;
		}

		void timer::stop_timer()
		{
			GetLocalTime(&this->stop_);
			this->is_active_ = false;
		}

		move_to::move_to()
		{
			this->command_forward_backward_ = false;
			this->command_strafe_ = false;
			this->current_distance_ = 0.0f;
			this->current_facing_.zero();
			this->current_heading_ = heading_inactive_;
			this->distance_buffer_ = 5.0f;
			this->move_to_loc_.zero();
			this->move_to_active_ = false;
			this->simulate_keypresses_ = false;
			this->turn_type_ = TT_FAST;
			this->use_3d_ = false;
		}


		float move_to::check_heading(const float& heading)
		{
			if (heading < 0.0f)
				return heading + 360.0f;
			if (heading >= 360.0f)
				return heading - 360.0f;
			return heading;
		}

		float move_to::degrees_rotation_this_frame() const
		{
			return this->get_delta_time() * this->turn_speed_per_second_ * this->circle_half_ / float(M_PI);
		}

		void move_to::do_move(const move_direction direction, const bool turn_on, const walk_type walk)
		{
			switch(walk)
			{
			case WT_WALK_ON: 
				move_to::set_walk(true);
				break;
			case WT_WALK_OFF:
				move_to::set_walk(false);
				break;
			case WT_WALK_IGNORE:
			default: 
				break;
			}
			turn_on ? this->move_on(direction) : this->move_off(direction);
		}

		bool move_to::get_active()
		{
			return this->move_to_active_;
		}

		void move_to::initialize()
		{

		}

		void move_to::loose_turn(const ao::quaternion_t& new_facing)
		{
			if (ao::g_game_state != GAMESTATE_IN_GAME)
			{
				const auto p_character = P_ENGINE_CLIENT_ANARCHY->get_client_char();
				const auto p_char_as_dynel = p_character->to_dynel();
				const auto current_heading = p_char_as_dynel->get_heading();
				

				if (fabs(P_ENGINE_CLIENT_ANARCHY->get_client_char()->to_dynel()->get_heading() - new_facing.get_heading()) < this->degrees_rotation_this_frame())
				{
					move_to::fast_turn(new_facing);
					this->current_heading_ = heading_inactive_;
					this->current_facing_ = facing_inactive_;
				}
				else
				{
					auto new_heading = new_facing.get_heading();
					const auto comp_heading = current_heading + circle_half_;
					const auto new_pitch = new_facing.get_pitch();
					if (new_heading < current_heading)
						new_heading += this->circle_full_;
					if (new_heading < comp_heading)
					{
						new_heading = current_heading - degrees_rotation_this_frame();						
					}
					else
					{
						new_heading = current_heading + degrees_rotation_this_frame();
					}
					const auto q_this_frame = ao::quaternion_t::get_quaternion(new_heading, new_pitch);
					move_to::fast_turn(q_this_frame);
				}
			}
		}

		void move_to::loose_turn(const float& new_heading)
		{
			const auto new_q = ao::quaternion_t::get_quaternion(new_heading);
			this->loose_turn(new_q);
		}

		void move_to::on_pulse()
		{
			if (ao::g_game_state != GAMESTATE_IN_GAME)
				return;
			this->process();
		}

		void move_to::process()
		{			
			
			const auto p_character = P_ENGINE_CLIENT_ANARCHY->get_client_char();
			const auto p_char_as_dynel = P_ENGINE_CLIENT_ANARCHY->get_client_char()->to_dynel();
			this->current_distance_ = this->use_3d_ ? p_char_as_dynel->get_distance_3d_to(this->move_to_loc_) : p_char_as_dynel->get_distance_to(this->move_to_loc_);
			if (ao::g_pulse_count % 180)
			{
				sprintf_s(message_, "Current distance to target at <%.2f, %.2f, %.2f> is %.2f.", this->move_to_loc_.x, this->move_to_loc_.y, this->move_to_loc_.z, this->current_distance_);
				printf(message_);
			}
			if (this->current_distance_ < this->distance_buffer_)
			{
				this->current_heading_ = this->heading_inactive_;
				this->current_facing_ = this->facing_inactive_;
				this->move_to_loc_ = this->move_to_loc_inactive_;
				this->move_to_active_ = false;
				this->do_move(DIR_ALL, false);
				sprintf_s(message_, "Made it to within %.2f units (%.2f) of target.", this->distance_buffer_, this->current_distance_);
				printf(message_);
				return;
			}
			else
			{				
				if (this->current_facing_ == this->facing_inactive_)
					this->current_facing_ = p_character->get_facing_to(this->move_to_loc_);
				if (this->current_heading_ == this->heading_inactive_)
				{
					this->current_heading_ = p_character->get_heading_to(this->move_to_loc_);
					sprintf_s(message_, "Turning to %.2f degrees to face target at <%.2f, %.2f, %.2f>.", this->current_heading_, this->move_to_loc_.x, this->move_to_loc_.y, this->move_to_loc_.z);
					printf(message_);
				}
				this->use_3d_ ? this->turn_head(this->current_facing_) : this->turn_head(this->current_heading_);
				this->do_move(DIR_FORWARD, true);
			}
		}		

		void move_to::fast_turn(const float new_heading)
		{
			if (ao::g_game_state != GAMESTATE_IN_GAME)
				return;
			P_ENGINE_CLIENT_ANARCHY->get_client_char()->face(new_heading);
		}

		void move_to::fast_turn(const ao::quaternion_t new_facing)
		{
			if (ao::g_game_state != GAMESTATE_IN_GAME)
				return;
			P_ENGINE_CLIENT_ANARCHY->get_client_char()->set_rotation(new_facing);
		}

		float move_to::get_delta_time()
		{
			if (ao::g_game_state != GAMESTATE_IN_GAME)
				return 0.0f;
			return P_GAME_TIME->get_delta_time();
		}

		void move_to::set_active(bool is_active)
		{
			this->move_to_active_ = true;
		}

		void move_to::set_move_to_loc(const ao::vector3_t& loc)
		{
			this->move_to_loc_ = loc;
		}

		void move_to::set_walk(const bool on) const
		{
			if (ao::g_game_state != GAMESTATE_IN_GAME)
				return;
			if ((on && !P_ENGINE_CLIENT_ANARCHY->get_client_char()->is_walking()) || (!on && P_ENGINE_CLIENT_ANARCHY->get_client_char()->is_walking()))
			{
				
				if (this->simulate_keypresses_ )
					P_FLOW_CONTROL->slot_walk_toggle(false);
				else
				{
					ao::keypress_info_t key(ao::IMD_X);
					key.key_down();
					P_INPUT_CONFIG->process_input(key, ao::IME_ANY_MODE);
					key.key_up();
					P_INPUT_CONFIG->process_input(key, ao::IME_ANY_MODE);
				}
			}
		}


		void move_to::shutdown()
		{

		}

		void move_to::move_on(const move_direction direction)
		{
			ao::keypress_info_t key_up;
			key_up.key_up();
			ao::keypress_info_t key_down;
			key_down.key_down();
			switch(direction)
			{
			case DIR_FORWARD:
				if (this->simulate_keypresses_)
				{
					this->command_forward_backward_ = true;
					key_up.key = ao::IMD_S;
					key_down.key = ao::IMD_W;
					P_INPUT_CONFIG->process_input(key_up, ao::IME_ANY_MODE);
					P_INPUT_CONFIG->process_input(key_down, ao::IME_ANY_MODE);
				}
				else
				{
					this->command_forward_backward_ = true;
					P_FLOW_CONTROL->slot_movement_back(true);
					P_FLOW_CONTROL->slot_movement_forward(false);
				}
				break;
			case DIR_BACKWARD:
				if (this->simulate_keypresses_)
				{
					this->command_forward_backward_ = true;
					key_up.key = ao::IMD_W;
					key_down.key = ao::IMD_S;
					P_INPUT_CONFIG->process_input(key_up, ao::IME_ANY_MODE);
					P_INPUT_CONFIG->process_input(key_down, ao::IME_ANY_MODE);
				}
				else
				{
					this->command_forward_backward_ = true;
					P_FLOW_CONTROL->slot_movement_forward(true);
					P_FLOW_CONTROL->slot_movement_back(false);
					break;
				}
				break;
			case DIR_LEFT:
				if (this->simulate_keypresses_)
				{
					this->command_strafe_ = true;
					key_up.key = ao::IMD_C;
					key_down.key = ao::IMD_Z;
					P_INPUT_CONFIG->process_input(key_up, ao::IME_ANY_MODE);
					P_INPUT_CONFIG->process_input(key_down, ao::IME_ANY_MODE);
				}
				else
				{
					this->command_strafe_ = true;
					P_FLOW_CONTROL->slot_movement_strafe_right(true);
					P_FLOW_CONTROL->slot_movement_strafe_left(false);
				}
				break;
			case DIR_RIGHT:
				if (simulate_keypresses_)
				{
					this->command_strafe_ = true;
					key_up.key = ao::IMD_Z;
					key_down.key = ao::IMD_C;
					P_INPUT_CONFIG->process_input(key_up, ao::IME_ANY_MODE);
					P_INPUT_CONFIG->process_input(key_down, ao::IME_ANY_MODE);
				}
				else
				{
					this->command_strafe_ = true;
					P_FLOW_CONTROL->slot_movement_strafe_left(true);
					P_FLOW_CONTROL->slot_movement_strafe_right(false);
				}
				break;
			default: 
				break;;
			}
		}
		
		void move_to::move_off(const move_direction direction)
		{
			ao::keypress_info_t key_up;
			key_up.key_up();
			switch(direction)
			{
			case DIR_ALL:
				if (simulate_keypresses_)
				{
					key_up.key = ao::IMD_W;
					P_INPUT_CONFIG->process_input(key_up, ao::IME_ANY_MODE);
					key_up.key = ao::IMD_S;
					P_INPUT_CONFIG->process_input(key_up, ao::IME_ANY_MODE);
					key_up.key = ao::IMD_C;
					P_INPUT_CONFIG->process_input(key_up, ao::IME_ANY_MODE);
					key_up.key = ao::IMD_V;
					P_INPUT_CONFIG->process_input(key_up, ao::IME_ANY_MODE);					
				}
				else
				{
					P_FLOW_CONTROL->slot_movement_strafe_left(true);
					P_FLOW_CONTROL->slot_movement_strafe_right(true);
					P_FLOW_CONTROL->slot_movement_forward(true);
					P_FLOW_CONTROL->slot_movement_back(true);
				}
				this->command_forward_backward_ = false;
				this->command_strafe_ = false;
				break;
			case DIR_FORWARD:
				if (this->simulate_keypresses_)
				{
					key_up.key = ao::IMD_W;
					P_INPUT_CONFIG->process_input(key_up, ao::IME_ANY_MODE);
				}
				else
				{
					P_FLOW_CONTROL->slot_movement_forward(true);
					this->command_forward_backward_ = false;
				}
				this->command_forward_backward_ = false;
				break;
			case DIR_BACKWARD:
				if (this->simulate_keypresses_)
				{
					key_up.key = ao::IMD_S;
					P_INPUT_CONFIG->process_input(key_up, ao::IME_ANY_MODE);
				}
				else
				{
					P_FLOW_CONTROL->slot_movement_back(true);
					this->command_forward_backward_ = false;
				}
				this->command_forward_backward_ = false;
				break;
			case DIR_LEFT:
				if (this->simulate_keypresses_)
				{
					key_up.key = ao::IMD_Z;
					P_INPUT_CONFIG->process_input(key_up, ao::IME_ANY_MODE);
				}
				else
				{
					P_FLOW_CONTROL->slot_movement_strafe_left(true);
					this->command_strafe_ = false;
				}
				this->command_forward_backward_ = false;
				break;
			case DIR_RIGHT:
				if (this->simulate_keypresses_)
				{
					key_up.key = ao::IMD_C;
					P_INPUT_CONFIG->process_input(key_up, ao::IME_ANY_MODE);
					this->command_forward_backward_ = false;
				}
				else
				{
					P_FLOW_CONTROL->slot_movement_strafe_right(true);
					this->command_strafe_ = false;
				}
				break;
			case DIR_FRONT_BACK:
				if (this->simulate_keypresses_)
				{
					key_up.key = ao::IMD_W;
					P_INPUT_CONFIG->process_input(key_up, ao::IME_ANY_MODE);
					key_up.key = ao::IMD_S;
					P_INPUT_CONFIG->process_input(key_up, ao::IME_ANY_MODE);
				}
				else
				{
					P_FLOW_CONTROL->slot_movement_forward(true);
					P_FLOW_CONTROL->slot_movement_back(true);
				}
				this->command_forward_backward_ = false;
				break;
			case DIR_STRAFING:
				if (this->simulate_keypresses_)
				{
					key_up.key = ao::IMD_Z;
					P_INPUT_CONFIG->process_input(key_up, ao::IME_ANY_MODE);
					key_up.key = ao::IMD_C;
					P_INPUT_CONFIG->process_input(key_up, ao::IME_ANY_MODE);
				}
				else
				{
					P_FLOW_CONTROL->slot_movement_strafe_left(true);
					P_FLOW_CONTROL->slot_movement_strafe_right(true);
				}
				this->command_forward_backward_ = false;
			default: 
				break;
			}
		}

		void move_to::turn(const float new_heading)
		{
			const auto new_q = ao::quaternion_t::get_quaternion(new_heading);
			this->turn(new_q);
		}

		void move_to::turn(const ao::quaternion_t& new_facing)
		{
			if (ao::g_game_state != GAMESTATE_IN_GAME)
				return;
			const auto p_character = P_ENGINE_CLIENT_ANARCHY->get_client_char();
			const auto p_char_as_dynel = p_character->to_dynel();
			const auto current_heading = p_char_as_dynel->get_heading();

			ao::keypress_info_t key_up;
			key_up.key_up();
			ao::keypress_info_t key_down;
			key_down.key_down();

			if (fabs(P_ENGINE_CLIENT_ANARCHY->get_client_char()->to_dynel()->get_heading() - new_facing.get_heading()) < this->degrees_rotation_this_frame())
			{
				move_to::fast_turn(new_facing);
				this->current_heading_ = heading_inactive_;
				this->current_facing_ = facing_inactive_;
			}
			else
			{
				auto new_heading = new_facing.get_heading();
				const auto comp_heading = current_heading + circle_half_;
				const auto new_pitch = new_facing.get_pitch();
				if (new_heading < current_heading)
					new_heading += this->circle_full_;

				if (new_heading < comp_heading)
				{
					if (this->simulate_keypresses_)
					{
						P_FLOW_CONTROL->slot_movement_right(true);
						P_FLOW_CONTROL->slot_movement_left(false);
					}
					else
					{
						key_up.key = ao::IMD_D;
						key_down.key = ao::IMD_A;
						P_INPUT_CONFIG->process_input(key_up, ao::IME_ANY_MODE);
						P_INPUT_CONFIG->process_input(key_down, ao::IME_ANY_MODE);
					}
				}
				else
				{
					if (this->simulate_keypresses_)
					{
						P_FLOW_CONTROL->slot_movement_left(true);
						P_FLOW_CONTROL->slot_movement_right(false);
					}
					else
					{
						key_up.key = ao::IMD_A;
						key_down.key = ao::IMD_D;
						P_INPUT_CONFIG->process_input(key_up, ao::IME_ANY_MODE);
						P_INPUT_CONFIG->process_input(key_down, ao::IME_ANY_MODE);
					}
				}
			}
		}

		void move_to::turn_head(const float heading)
		{
			if (ao::g_game_state != GAMESTATE_IN_GAME)
				return;
			switch (this->turn_type_)
			{
			case TT_LOOSE:
				this->loose_turn(heading);
				break;
			case TT_TRUE:
				this->turn(heading);
				break;
			case TT_FAST:
				move_to::fast_turn(heading);
			default:
				break;
			}
		}

		void move_to::turn_head(const ao::quaternion_t& facing)
		{

			if (ao::g_game_state != GAMESTATE_IN_GAME)
				return;
			switch (this->turn_type_)
			{
			case TT_LOOSE:
				this->loose_turn(facing);
				break;
			case TT_TRUE:
				this->turn(facing);
				break;
			case TT_FAST:
				move_to::fast_turn(facing);
			default:
				break;
			}
		}

	}
}

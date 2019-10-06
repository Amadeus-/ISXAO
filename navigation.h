#pragma once
#ifndef _NAVIGATION_H
#define _NAVIGATION_H
#include <bemapiset.h>
#include <cfloat>

namespace ao
{
	struct ao_vector3;
	struct ao_quaternion;

	typedef ao_vector3 vector3_t, *p_vector3_t;
	typedef ao_quaternion quaternion_t, *p_quaternion_t;
}

namespace isxao
{
	namespace navigation
	{
		enum move_direction
		{
			DIR_FORWARD = 1,
			DIR_BACKWARD,
			DIR_LEFT,
			DIR_RIGHT,
			DIR_ALL,
			DIR_FRONT_BACK,
			DIR_STRAFING 			
		};

		enum turn_type
		{
			TT_LOOSE = 1,
			TT_TRUE,
			TT_FAST
		};

		enum walk_type
		{
			WT_WALK_ON = 1,
			WT_WALK_OFF,
			WT_WALK_IGNORE
		};

		class timer
		{
		public:
			timer();
			unsigned long long elapsed_ms() const;
			void reset();
			void start_timer();
			void stop_timer();
		private:
			bool is_active_;
			SYSTEMTIME start_{};
			SYSTEMTIME stop_{};

		};

		class move_to : public timer
		{
		public:
			move_to();
			bool get_active();
			void initialize();
			void on_pulse();
			void process();
			void set_active(bool);
			void set_move_to_loc(const ao::vector3_t&);
			void shutdown();
		private:
			const ao::quaternion_t facing_inactive_ = ao::quaternion_t(FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX);
			const float heading_inactive_ = FLT_MAX;
			const ao::vector3_t move_to_loc_inactive_ = ao::vector3_t(FLT_MAX, FLT_MAX, FLT_MAX);
			const float circle_full_ = 360.0f;
			const float circle_half_ = 180.0f;
			const float circle_quarter_ = 90.0f;
			const float turn_speed_per_second_ = float(M_PI / 3.0f); // rad s^-1

			char message_[MAX_VARSTRING]{};

			bool command_forward_backward_;
			bool command_strafe_;
			float current_distance_;
			ao::quaternion_t current_facing_;
			float current_heading_;			
			float distance_buffer_;
			float heading_error_;
			ao::vector3_t move_to_loc_;
			bool move_to_active_;
			bool simulate_keypresses_;
			turn_type turn_type_;
			bool use_3d_;

			static float check_heading(const float& heading);
			void do_move(move_direction, bool turn_on, walk_type walk = WT_WALK_OFF);			
			float degrees_rotation_this_frame() const;
			static void fast_turn(float new_heading);
			static void fast_turn(ao::quaternion_t new_facing);
			static float get_delta_time();
			void loose_turn(const ao::quaternion_t& new_facing);
			void loose_turn(const float&);
			void set_walk(bool on) const;
			void move_on(move_direction);
			void move_off(move_direction);			
			void turn(const ao::quaternion_t& new_facing);
			void turn(const float new_heading);
			void turn_head(const ao::quaternion_t&);
			void turn_head(const float heading);
		};
	}

	
}
#endif
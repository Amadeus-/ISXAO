#pragma once

namespace isxao
{
#pragma region constants

	constexpr float circle_quarter = 90.0f;
	constexpr float circle_half = 180.0f;
	constexpr float circle_max = 360.0;

	constexpr float h_inactive = 10000.0f;
	constexpr int h_fast = 0;
	constexpr int h_loose = 1;
	constexpr int h_true = 2;

	constexpr int max_ring_size = 32;

	constexpr float heading_quarter = 128.0f;
	constexpr float heading_half = 256.0f;
	constexpr float heading_max = 512.0f;

	constexpr int behind_arc = 45;
	constexpr int front_arc = 240;
	constexpr int not_front_arc = 135;
	constexpr int pin_arc_min = 112;
	constexpr int pin_arc_max = 144;

	constexpr int t_inactive = 0;
	constexpr int t_ready = 2;
	constexpr int t_waiting = 1;

#pragma endregion

	class move_settings* p_settings = nullptr;

	class move_character* p_character = nullptr;

	class stuck_logic* p_stuck_logic = nullptr;

	class move_loc* p_summon_loc = nullptr;
	class circle_settings* p_circle_settings = nullptr;
	class move_to_settings* p_move_to_settings = nullptr;
	class camp_settings* p_camp_settings = nullptr;
	class stick_settings* p_stick_settings = nullptr;

	class move_loc
	{
	public:
		ao::vector3_t location;
		float cur_distance{};
		float dif_distance{};
		move_loc();
	};

	class move_delay
	{
	public:
		int min;
		int max;
		move_delay();
		void min_delay(int);
		void max_delay(int);
		void time_start();
		int time_status() const;
		void time_stop();
		void validate();

	protected:
		int resume_;
		SYSTEMTIME time_began_;
		int elapsed_ms() const;
	};

	class move_character
	{
	public:
		static bool in_combat();
		static bool is_me(ao::dynel*);
	};

	class stuck_logic : public move_loc
	{
	public:
		bool is_on;
		bool try_jump;
		bool turn_half;
		DWORD check;
		DWORD unstuck;
		float dist;
		float turn_size;
		DWORD stuck_inc;
		DWORD stuck_dec;
		stuck_logic();
		void reset();
	};

	class stick_settings : public move_delay
	{
	public:
		bool break_gate;
		bool break_hit;
		bool break_target;
		bool break_warp;
		bool flex;
		bool pause_warp;
		bool randomize;
		bool delay_strafe;
		bool use_back;
		bool use_fleeing;
		bool walk;
		bool uw;
		float arc_behind;
		float arc_not_front;
		float dist_back;
		float dist_break;
		float dist_flex;
		float dist_mod;
		float dist_mod_p;
		float dist_snap;
		stick_settings();
	};

	class camp_settings : public move_delay
	{
	public:
		bool have_target;
		bool no_aggro;
		bool not_looting;
		bool scatter;
		bool real_time;
		bool leash;
		float bearing;
		float length;
		float radius;
		float scat_size;
		float scat_dist;
		camp_settings();
		void set_radius(float);
		void set_leash(float);
	protected:
		void validate_sizes();
	};

	class move_to_settings
	{
	public:
		bool break_aggro;
		bool break_hit;
		bool use_back;
		bool uw;
		bool walk;
		float dist;
		float dist_back;
		float dist_y;
		float dist_x;
		float mod;
		move_to_settings();
	};

	class circle_settings
	{
	public:
		bool backward;
		bool ccw;
		bool drunk;
		float circle_mod;
		float radius;
		circle_settings();
		void set_radius(float);
	};

	class move_settings  // NOLINT(hicpp-special-member-functions, cppcoreguidelines-special-member-functions)
	{
	public:
		bool auto_save;
		bool auto_pause;
		bool auto_uw;
		bool break_gm;
		bool break_summon;
		bool break_knock_back;
		bool break_mouse;
		bool pause_mouse;
		bool lock_pause;
		bool save_by_char;
		bool spin;
		float allow_move;
		float dist_summon;
		float turn_rate;
		int head;
		move_settings();
		~move_settings();
	};

	class circle_command : public move_loc, public move_delay, public circle_settings
	{
	public:
		bool is_on;
		bool wait();
		void at_me();

	protected:
		void user_defaults();
		static int get_drunk(int);
	};

	class move_to
	{
	public:
		bool is_on;
		bool precise_x;
		bool precise_y;
		move_to();
		void activate(const ao::vector3_t&);
	private:		
	};

}
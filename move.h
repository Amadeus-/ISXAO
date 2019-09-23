#pragma once

namespace isxao
{
#pragma region constants

	constexpr byte command_stick = 1;
	constexpr byte command_move_to = 2;
	constexpr byte command_circle = 3;
	constexpr byte command_make_camp = 4;

	constexpr byte move_walk_on = 10;
	constexpr byte move_walk_off = 11;
	constexpr byte move_walk_ignore = 12;

	constexpr byte set_alt_camp = 20;
	constexpr byte reset_alt_camp = 21;

	constexpr byte go_forward = 30;
	constexpr byte go_backward = 31;
	constexpr byte go_left = 32;
	constexpr byte go_right = 33;
	constexpr byte kill_strafe = 34;
	constexpr byte kill_fb = 35;
	constexpr byte apply_to_all = 36;

	constexpr byte help_settings = 50;

	constexpr byte error_stick_self = 60;
	constexpr byte error_stick_none = 61;
	constexpr byte error_bad_move_to = 62;
	constexpr byte error_bad_make_camp = 63;
	constexpr byte error_bad_circle = 64;
	constexpr byte error_bad_actor = 65;
	constexpr byte error_bad_delay = 66;

	constexpr byte debug_main = 200;
	constexpr byte debug_stuck = 201;
	constexpr byte debug_misc = 202;
	constexpr byte debug_disable = 203;

	constexpr float circle_quarter = 90.0f;
	constexpr float circle_half = 180.0f;
	constexpr float circle_max = 360.0;

	constexpr float heading_quarter = 128.0f;
	constexpr float heading_half = 256.0f;
	constexpr float heading_max = 512.0f;

	constexpr int behind_arc = 45;
	constexpr int front_arc = 240;
	constexpr int not_front_arc = 135;
	constexpr int pin_arc_min = 112;
	constexpr int pin_arc_max = 144;

	constexpr float h_inactive = 10000.0f;
	constexpr int h_fast = 0;
	constexpr int h_loose = 1;
	constexpr int h_true = 2;

	constexpr int t_inactive = 0;
	constexpr int t_ready = 2;
	constexpr int t_waiting = 1;

	constexpr int max_ring_size = 32;

	constexpr DWORD event_aggro_norm = 0;
	constexpr DWORD event_miss_norm = 0;
	constexpr DWORD event_aggro_abbrev = 0;
	constexpr DWORD event_miss_abbrev = 0;
	constexpr DWORD event_miss_num_only = 0;
	constexpr DWORD event_gates = 0;

#pragma endregion

#pragma region enums

	enum verbosity_level
	{
		V_SILENCE = 0,
		V_AUTO_PAUSE = 1,
		V_MOVE_PAUSE = 1 >> 1,
		V_MOUSE_PAUSE = 1 >> 2,
		V_FEIGN = 1 >> 3,
		V_HIDE_HELP = 1 >> 4,
		V_STICK_V = 1 >> 5,
		V_STICK_FV = 1 >> 6,
		V_MOVE_TO_V = 1 >> 7,
		V_MOVE_TO_FV = 1 >> 8,
		V_MAKE_CAMP_V = 1 >> 9,
		V_MAKE_CAMP_FV = 1 >> 10,
		V_CIRCLE_V = 1 >> 11,
		V_CIRCLE_FV = 1 >> 12,
		V_SETTINGS = 1 >> 13,
		V_SAVED = 1 >> 14,
		V_BREAK_ON_WARP = 1 >> 15,
		V_BREAK_ON_AGGRO = 1 >> 16,
		V_BREAK_ON_HIT = 1 >> 17,
		V_BREAK_ON_SUMMON = 1 >> 18,
		V_BREAK_ON_GM = 1 >> 19,
		V_BREAK_ON_GATE = 1 >> 20,
		V_STICK_ALWAYS = 1 >> 21,
		V_ERRORS = 1 >> 22,
		V_RANDOMIZE = 1 >> 23,
		V_PAUSED = 1 >> 24,
		V_VERBOSITY = V_CIRCLE_FV + V_MAKE_CAMP_V + V_MOVE_TO_V + V_STICK_V, // normal verbosity msgs
		V_FULL_VERBOSITY = V_RANDOMIZE + V_STICK_ALWAYS + V_BREAK_ON_GATE + V_BREAK_ON_HIT + V_BREAK_ON_AGGRO + V_CIRCLE_FV + V_MAKE_CAMP_FV +  V_MOVE_TO_FV + V_STICK_FV + V_MOUSE_PAUSE + V_MOUSE_PAUSE, // full verbosity msgs
		V_EVERYTHING = 1 >> 25, // all messages on (dont add verb + fullverb in)
	};

#pragma endregion

#pragma region globals

	AOLIB_API bool g_stick_on;
	// AOLIB_API int stick_cmd(int argc, char* argv[]);

#pragma endregion

	class move_loc
	{
	public:
		ao::vector3_t location;
		float cur_distance;
		float dif_distance;
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
		SYSTEMTIME time_began_{};
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
		float dist_z;
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
		bool on;
		circle_command();
		bool wait();
		void at_me();
		void at_loc(ao::vector3_t);
		void at_loc(float x, float z);

	protected:
		void user_defaults();
		static int get_drunk(int);
	};

	class move_to_command: public move_loc, public move_to_settings
	{
	public:
		bool on;
		bool precise_x;
		bool precise_z;
		move_to_command();
		bool did_aggro();
		void activate(ao::vector3_t);
		void activate(float x, float y, float z);

	protected:
		void user_defaults();
	};

	class camp_command: public move_loc, public camp_settings
	{
	public:
		bool on;
		bool pc;
		bool redo_stick;
		bool redo_circle;
		ao::identity_t pc_identity;
		char pc_name[MAX_VARSTRING] = { 0 };
		camp_command();
		void user_defaults();
	};

	class alt_camp : public move_loc
	{
	public:
		bool on;
		float radius;
		alt_camp();
		void update(camp_command* p_current);
	};

	class camp_handler: public move_delay, public move_loc
	{
	public:
		bool is_auto;
		bool do_alt;
		bool do_return;
		bool returning;
		camp_handler();
		~camp_handler();
		static void reset_both();
		void reset_camp(bool);
		void reset_player(bool);
		void new_camp(bool);
		void activate(ao::vector3_t p);
		void activate(float x, float z);
		void activate(ao::dynel*);
		void var_reset();

	protected:
		void output();
		void output_pc();
	};

	class snap_roll : public move_loc
	{
	public:
		float head;
		float bearing;
		snap_roll();
	};

	class stick_command: public move_loc, public stick_settings
	{
	public:
		snap_roll* snap;
		bool set_dist;
		float dist;
		float rand_min;
		float rand_max;
		bool rand_flag;
		bool move_back;
		bool behind;
		bool behind_once;
		bool front;
		bool not_front;
		bool pin;
		bool snap_roll;
		bool hold;
		bool healer;
		bool always;
		bool have_target;
		bool strafe;
		bool on;
		ao::identity_t last_target_id;
		ao::identity_t hold_id;
		stick_command();
		~stick_command();
		void turn_on();
		void stop_hold();
		void first_always();
		void new_snap_roll();
		void reset_loc();
		bool ready();
		void do_randomize();

	protected:
		void user_defaults();
		void set_rand_arc(int arc_type);
		bool always_status();
		bool always_ready_;
	};

	class pause_handler : public move_delay
	{
	public:
		bool paused_command;
		bool paused_move;
		bool user_kb;
		bool user_mouse;
		pause_handler();
		bool waiting() const;
		void handle_pause();
		void pause_timers();
		void mouse_free();
		bool pause_needed();
		bool mouse_check();
		void reset();

	protected:
		bool handle_mouse_;
		bool handle_kb_;
	};

	class move_active
	{
	public:
		bool aggro;
		bool broke_gm;
		bool broke_summon;
		bool command_forward;
		bool command_strafe;
		bool fix_walk;
		bool key_binds;
		bool key_killed;
		bool loaded;
		bool lock_pause;
		bool move_to_broke;
		bool stick_broke;
		bool rooted;
		bool stopped_move_to;
		int head;
		move_active();
		~move_active();
		static void new_stick();
		static void new_move_to();
		static void new_circle();
		static void new_commands();
		static void new_summon();
		void new_defaults();
		static bool active();
		void aggro_tlo();
		bool broken() const;
		void defaults();
	};

	class move_movement
	{
	public:
		float change_head;
		float root_head;
		void auto_head();
		void new_head(float);
		static void new_face(float);
		void stop_heading();
		static float sane_head(float heading);
		void do_root();
		void stop_root();
		float ang_dist(float, float, float);
		float ang_dist(float, ao::vector3_t&);
		float ang_dist(ao::quaternion_t&, float, float);
		float ang_dist(ao::quaternion_t&, ao::vector3_t&);
		bool can_move(float, float, float);
		bool can_move(float, ao::vector3_t&);
		bool can_move(ao::quaternion_t&, ao::vector3_t&);
		bool set_walk(bool);
		void do_stand();
		void walk(byte);
		void try_move(byte, byte, float, float, float);
		void do_move(byte, bool, byte);
		void stop_move(byte);
		void stick_strafe(byte);
		move_movement();
	private:
		void timed_strafe(byte);
		void turn_head(float);
		void fast_turn(float);
		void loose_turn(float);
		void true_turn(float);
		void true_move_on(byte);
		void true_move_off(byte);
		void sim_move_on(byte);
		void sim_move_off(byte);
	};

}
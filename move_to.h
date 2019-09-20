#pragma once

namespace isxao
{
	constexpr int t_inactive = 0;
	constexpr int t_ready = 2;
	constexpr int t_waiting = 1;

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

	};

	class move_to
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
		bool is_on;
		bool precise_x;
		bool precise_y;
		move_to();
		void activate(const ao::vector3_t&);
	private:		
	};

}
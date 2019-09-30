#pragma once
#include "team_member.h"

namespace ao
{
	class inventory_holder;
	class npc_holder;
	class perk_holder;
	class special_action_holder;
	class stat_holder;

	struct ao_quaternion;

	typedef ao_quaternion quaternion_t, *p_quaternion_t;


	class character : public team_member
	{
	public:
		// Holders
		inventory_holder* get_inventory_holder();
		perk_holder* get_perk_holder();
		npc_holder* get_npc_holder();
		special_action_holder* get_special_action_holder();
		stat_holder* get_stat_holder();

		// Info
		bool check_los(dynel*);
		static bool get_weapon_target(identity_t&);
		static bool get_target(identity_t&);
		static bool has_weapon_target();
		static bool has_target();

		// Actions
		static void cast_nano_spell(identity_t const &, identity_t const &);
		static void default_attack(identity_t const &);
		void face(float heading);
		void face(vector3_t &location);
		void make_team_leader(const identity_t &);
		static bool perform_special_action(const identity_t &);
		void set_rotation(const quaternion_t&);
		static void stop_attack();
		static void use_item(identity_t const &);

		// Movement
		static bool is_walking();
		void move_forward_start();
		void move_forward_stop();
		void move_backward_start();
		void move_backward_stop();
		void rotate_left_start();
		void rotate_left_stop();
		void rotate_right_start();
		void rotate_right_stop();
		void sit();
		void stand();
		void strafe_left_start();
		void strafe_left_stop();
		void strafe_right_start();
		void strafe_right_stop();
		void stop();

	private:
		unsigned long get_stat_map(std::map<unsigned long, long>&);

	};
}
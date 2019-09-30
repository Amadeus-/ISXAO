#pragma once
#pragma once
#ifndef _DYNEL_H
#define _DYNEL_H

#include "game_object.h"

namespace std
{
	template <typename _Tp, typename _Alloc>
	class list;
	template <typename _Key, typename _Tp, typename _Compare, typename _Alloc>
	class map;
	template <typename _Tp, typename _Alloc>
	class vector;
}

namespace ao
{
	class actor;
	class character;
	class pet;
	class player;
	class team_member;
	class info_item_remote;

	struct ao_identity;
	struct ao_n3_dynel;
	struct ao_quaternion;
	struct ao_vector3;	

	typedef ao_identity identity_t, *p_identity_t;
	typedef ao_n3_dynel n3_dynel_t, *p_n3_dynel_t;
	typedef ao_quaternion quaternion_t, *p_quaternion_t;
	typedef ao_vector3 vector3_t, *p_vector3_t;

	class dynel : public game_object<n3_dynel_t>
	{
	public:
		float get_distance_to_client();
		float get_distance_to(vector3_t&);
		float get_distance_3d_to(vector3_t&);
		float get_distance_3d_to_squared(vector3_t&);
		float get_distance_to_squared(vector3_t&);
		float get_distance_x_to(vector3_t&);
		float get_distance_y_to(vector3_t&);
		float get_distance_z_to(vector3_t&);
		static dynel* get_dynel(const identity_t&);;
		float get_heading();
		float get_raw_heading();
		float get_heading_to(vector3_t &);
		float get_raw_heading_to(vector3_t &);
		float get_heading_to_loc(vector3_t &, vector3_t &);
		float get_raw_heading_to_loc(vector3_t &, vector3_t &);
		identity_t get_identity();
		const char* get_name();
		vector3_t get_position();
		quaternion_t get_rotation();
		long get_skill(unsigned long);
		static bool is_dynel_in_engine(const identity_t &);
		bool is_info_request_completed();
		void interact();
		bool is_container();
		bool is_corpse();
		bool is_door();
		bool is_in_line_of_sight();
		bool is_in_line_of_sight(const vector3_t &);
		bool is_character();
		bool is_actor();
		bool is_pet();
		bool is_player();
		bool is_team_member();
		bool is_vending_machine();
		bool is_weapon_instance();
		void send_iir_to_observers(ao::info_item_remote*);
		actor* to_actor();
		character* to_character();
		pet* to_pet();
		player* to_player();
		team_member* to_team_member();
		void update_locality_listeners();
		static bool p_dynel_compare(dynel *p_a, dynel *p_b);
	};
}
#endif
#pragma once
#include "game_object.h"

class LSIndex;
// struct _RGBCOLOR;
// typedef _RGBCOLOR RGBCOLOR;

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
	class dynel;
	class nano_template;
	class spell_template_data;
	class team_raid;
	class vehicle;
	class weapon_holder;
	
	struct ao_identity;
	struct ao_simple_char;
	struct ao_vector3;	
	
	typedef ao_identity identity_t, *p_identity_t;
	typedef ao_simple_char simple_char_t, *p_simple_char_t;
	typedef ao_vector3 vector3_t, *p_vector3_t;

	class actor : public game_object<simple_char_t>
	{
	public:
		unsigned long build_ls_ncu(LSIndex*);
		unsigned long build_ls_pets(LSIndex*);
		unsigned long casting();
		const char* consider();
		const char* con_color();
		RGBCOLOR con_color_argb();
		void do_face(bool uw = false);
		void do_target();
		float estimated_distance_to(vector3_t &);
		actor* get_master();
		unsigned long get_master_id();
		nano_template* get_ncu(unsigned long);
		nano_template* get_ncu(const char*);
		unsigned long get_ncu_count();
		actor* get_pet(unsigned long);
		actor* get_pet(const char*);
		unsigned long get_pet_count();
		unsigned long get_pet_ids(std::map<ao::identity_t, unsigned long>&);
		float get_scale();
		spell_template_data* get_spell_template_data();
		team_raid* get_team_raid();
		vehicle* get_vehicle();
		weapon_holder* get_weapon_holder();
		bool has_pet();
		bool is_backing_up();
		bool is_casting();
		bool is_crawling();
		bool is_fighting_me();
		bool is_fighting();
		bool is_idle();
		bool is_in_my_team();
		bool is_in_my_raid_team();
		bool is_in_team();
		bool is_in_raid();
		bool is_invis();
		bool is_kos();
		bool is_moving_forward();
		bool is_npc();
		bool is_rotating_left();
		bool is_rotating_right();
		bool is_sitting();
		bool is_strafing_left();
		bool is_strafing_right();
		bool is_standing();
		bool is_team_leader();
		void kick();
		void make_leader();
		bool send_team_invite();
		dynel* to_dynel();
	};
}
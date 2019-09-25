#pragma once

class actor : public ao::dynel
{
public:
	DWORD build_ls_ncu(LSIndex*);
	DWORD build_ls_pets(LSIndex*);
	DWORD casting();
	PCSTR consider();
	PCSTR con_color();
	RGBCOLOR con_color_argb();
	void do_face(bool uw = false);
	void do_target();
	float estimated_distance_to(ao::vector3_t &);
	actor* get_master();
	DWORD get_master_id();
	ao::nano_template* get_ncu(DWORD);
	ao::nano_template* get_ncu(PCSTR);
	DWORD get_ncu_count();
	actor* get_pet(DWORD);
	actor* get_pet(PCSTR);
	DWORD get_pet_count();
	DWORD get_pet_ids(std::map<ao::identity_t, DWORD>&);
	float get_scale();
	ao::p_simple_char_t get_simple_char_data();
	ao::spell_template_data* get_spell_template_data();
	ao::team_raid* get_team_raid();
	ao::vehicle* get_vehicle();
	ao::weapon_holder* get_weapon_holder();
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

};
#pragma once

class actor : public isxao_classes::dynel
{
public:
	AOLIB_OBJECT DWORD build_ls_ncu(LSIndex*);
	AOLIB_OBJECT DWORD build_ls_pets(LSIndex*);
	AOLIB_OBJECT DWORD casting();
	AOLIB_OBJECT PCSTR consider();
	AOLIB_OBJECT PCSTR con_color();
	AOLIB_OBJECT RGBCOLOR con_color_argb();
	AOLIB_OBJECT void do_face();
	AOLIB_OBJECT void do_target();
	AOLIB_OBJECT float estimated_distance_to(vector3_t &);
	AOLIB_OBJECT actor* get_master();
	AOLIB_OBJECT DWORD get_master_id();
	AOLIB_OBJECT NanoTemplate* get_ncu(DWORD);
	AOLIB_OBJECT NanoTemplate* get_ncu(PCSTR);
	AOLIB_OBJECT DWORD get_ncu_count();
	AOLIB_OBJECT actor* get_pet(DWORD);
	AOLIB_OBJECT actor* get_pet(PCSTR);
	AOLIB_OBJECT DWORD get_pet_count();
	AOLIB_OBJECT DWORD get_pet_ids(map<identity_t, DWORD>&);
	AOLIB_OBJECT float get_scale();
	AOLIB_OBJECT p_simple_char_t get_simple_char_data();
	AOLIB_OBJECT SpellTemplateData* get_spell_template_data();
	AOLIB_OBJECT TeamRaid* get_team_raid();
	AOLIB_OBJECT Vehicle* get_vehicle();
	AOLIB_OBJECT WeaponHolder* get_weapon_holder();
	AOLIB_OBJECT bool has_pet();	
	AOLIB_OBJECT bool is_backing_up();
	AOLIB_OBJECT bool is_casting();
	AOLIB_OBJECT bool is_fighting_me();
	AOLIB_OBJECT bool is_fighting();
	AOLIB_OBJECT bool is_idle();
	AOLIB_OBJECT bool is_in_my_team();
	AOLIB_OBJECT bool is_in_my_raid_team();
	AOLIB_OBJECT bool is_in_team();
	AOLIB_OBJECT bool is_in_raid();
	AOLIB_OBJECT bool is_invis();
	AOLIB_OBJECT bool is_kos();
	AOLIB_OBJECT bool is_moving_forward();
	AOLIB_OBJECT bool is_npc();
	AOLIB_OBJECT bool is_strafing_left();
	AOLIB_OBJECT bool is_strafing_right();
	AOLIB_OBJECT bool is_team_leader();
	AOLIB_OBJECT void kick();
	AOLIB_OBJECT void make_leader();
	AOLIB_OBJECT bool send_team_invite();

};
#pragma once

class character : public ao::team_member
{
public:
	// Holders
	ao::inventory_holder* get_inventory_holder();
	ao::perk_holder* get_perk_holder();
	ao::npc_holder* get_npc_holder();
	ao::special_action_holder* get_special_action_holder();
	ao::stat_holder* get_stat_holder();

	// Info
	bool check_los(dynel*);
	static bool get_weapon_target(ao::identity_t&);
	static bool get_target(ao::identity_t&);
	static bool has_weapon_target();	
	static bool has_target();

	// Actions
	static void cast_nano_spell(ao::identity_t const &, ao::identity_t const &);
	static void default_attack(ao::identity_t const &);
	void face(float heading);
	void face(ao::vector3_t &location);
	void make_team_leader(const ao::identity_t &);
	static bool perform_special_action(const ao::identity_t &);
	void set_rotation(const ao::quaternion_t&);
	static void stop_attack();
	static void use_item(ao::identity_t const &);

	// Movement
	void move_to(const ao::vector3_t&);
	void move_forward_start();
	void move_forward_stop();
	void move_backward_start();
	void move_backward_stop();
	void rotate_left_start();
	void rotate_left_stop();
	void rotate_right_start();
	void rotate_right_stop();
	void strafe_left_start();
	void strafe_left_stop();
	void strafe_right_start();
	void strafe_right_stop();
	void stop();

private:
	void get_stat_map(std::map<DWORD, LONG>&);
	
};
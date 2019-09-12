#pragma once

class character : public team_member
{
public:
	// Holders
	AOLIB_OBJECT inventory_holder* get_inventory_holder();
	AOLIB_OBJECT perk_holder* get_perk_holder();
	AOLIB_OBJECT npc_holder* get_npc_holder();
	AOLIB_OBJECT special_action_holder* get_special_action_holder();
	AOLIB_OBJECT stat_holder* get_stat_holder();

	// Info
	AOLIB_OBJECT bool check_los(dynel*);
	AOLIB_OBJECT static bool get_weapon_target(identity_t&);
	AOLIB_OBJECT static bool get_target(identity_t&);
	AOLIB_OBJECT static bool has_weapon_target();	
	AOLIB_OBJECT static bool has_target();

	// Actions
	AOLIB_OBJECT static void cast_nano_spell(identity_t const &, identity_t const &);
	AOLIB_OBJECT static void default_attack(identity_t const &);
	AOLIB_OBJECT void face(float heading);
	AOLIB_OBJECT void face(vector3_t &location);
	AOLIB_OBJECT void make_team_leader(const identity_t &);
	AOLIB_OBJECT static bool perform_special_action(const identity_t &);
	AOLIB_OBJECT void set_rotation(const quaternion_t&);
	AOLIB_OBJECT static void stop_attack();
	AOLIB_OBJECT static void use_item(identity_t const &);

private:
	AOLIB_OBJECT void get_stat_map(map<DWORD, LONG>&);

};
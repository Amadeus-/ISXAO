#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class dynel
{
public:
	AOLIB_OBJECT PVOID get_data();
	AOLIB_OBJECT float get_distance_to_client();
	AOLIB_OBJECT float get_distance_to(vector3_t&);
	AOLIB_OBJECT float get_distance_3d_to(vector3_t&);
	AOLIB_OBJECT float get_distance_3d_to_squared(vector3_t&);
	AOLIB_OBJECT float get_distance_to_squared(vector3_t&);
	AOLIB_OBJECT float get_distance_x_to(vector3_t&);
	AOLIB_OBJECT float get_distance_y_to(vector3_t&);
	AOLIB_OBJECT float get_distance_z_to(vector3_t&);
	AOLIB_OBJECT static dynel* get_dynel(const identity_t&);
	AOLIB_OBJECT p_n3_dynel_t get_dynel_data();
	AOLIB_OBJECT float get_heading();
	AOLIB_OBJECT float get_heading_to(vector3_t &);
	AOLIB_OBJECT float get_heading_to_loc(vector3_t &, vector3_t &);
	AOLIB_OBJECT identity_t get_identity();
	AOLIB_OBJECT PCSTR get_name();
	AOLIB_OBJECT vector3_t get_position();
	AOLIB_OBJECT quaternion_t get_rotation();
	AOLIB_OBJECT LONG get_skill(DWORD);
	AOLIB_OBJECT bool is_info_request_completed();
	AOLIB_OBJECT void interact();
	AOLIB_OBJECT bool is_container();
	AOLIB_OBJECT bool is_corpse();
	AOLIB_OBJECT bool is_door();
	AOLIB_OBJECT bool is_in_line_of_sight();
	AOLIB_OBJECT bool is_in_line_of_sight(vector3_t &);
	AOLIB_OBJECT bool is_character();
	AOLIB_OBJECT bool is_actor();
	AOLIB_OBJECT bool is_pet();
	AOLIB_OBJECT bool is_player();
	AOLIB_OBJECT bool is_team_member();
	AOLIB_OBJECT bool is_vending_machine();
	AOLIB_OBJECT bool is_weapon_instance();
	AOLIB_OBJECT void send_iir_to_observers(info_item_remote*);
	AOLIB_OBJECT actor* to_actor();
	AOLIB_OBJECT character* to_character();
	AOLIB_OBJECT Pet* to_pet();
	AOLIB_OBJECT Player* to_player();
	AOLIB_OBJECT TeamMember* to_team_member();
	AOLIB_OBJECT void update_locality_listeners();
	AOLIB_OBJECT static bool p_dynel_compare(dynel *p_a, dynel *p_b);
private: 
	// ReSharper disable once CppUninitializedNonStaticDataMember
	n3_dynel_t n3_dynel_;
};
#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class dynel
{
public:
	PVOID get_data();
	float get_distance_to_client();
	float get_distance_to(ao::vector3_t&);
	float get_distance_3d_to(ao::vector3_t&);
	float get_distance_3d_to_squared(ao::vector3_t&);
	float get_distance_to_squared(ao::vector3_t&);
	float get_distance_x_to(ao::vector3_t&);
	float get_distance_y_to(ao::vector3_t&);
	float get_distance_z_to(ao::vector3_t&);
	static dynel* get_dynel(const ao::identity_t&);
	ao::p_n3_dynel_t get_dynel_data();
	float get_heading();
	float get_heading_to(ao::vector3_t &);
	float get_heading_to_loc(ao::vector3_t &, ao::vector3_t &);
	ao::identity_t get_identity();
	PCSTR get_name();
	ao::vector3_t get_position();
	ao::quaternion_t get_rotation();
	LONG get_skill(DWORD);
	static bool is_dynel_in_engine(const ao::identity_t &);
	bool is_info_request_completed();
	void interact();
	bool is_container();
	bool is_corpse();
	bool is_door();
	bool is_in_line_of_sight();
	bool is_in_line_of_sight(const ao::vector3_t &);
	bool is_character();
	bool is_actor();
	bool is_pet();
	bool is_player();
	bool is_team_member();
	bool is_vending_machine();
	bool is_weapon_instance();
	void send_iir_to_observers(ao::info_item_remote*);
	ao::actor* to_actor();
	ao::character* to_character();
	ao::pet* to_pet();
	ao::player* to_player();
	ao::team_member* to_team_member();
	void update_locality_listeners();
	static bool p_dynel_compare(dynel *p_a, dynel *p_b);
private: 
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::n3_dynel_t n3_dynel_;
};
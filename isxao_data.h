#pragma once

namespace AOData
{
#include "isxao_enums.h"

#pragma region Formard Declarations

	struct char_vehicle;
	struct dummy_item_base;
	struct dummy_vehicle;
	struct _EVENTCASTER;
	struct inventory_data;
	struct _N3CELLMONITOR;
	struct _N3DYNEL;
	struct _N3OBJECTFACTORY;
	struct _N3ROOT;
	struct _N3SFBASE;
	struct _N3TILEMAP;
	struct n3_tile_map_surface;
	struct _PERKDIR;
	struct _PLAYFIELDANARCHY;
	struct _RDBPLAYFIELD;
	struct _RDBTILEMAP;
	struct _RESOURCEDATABASE;
	struct _SIMPLECHAR;
	struct _STATDIR;

#pragma endregion

#pragma region Struct Typedefines
	
#pragma region Common Structs (by alpha)
	
	// Size = 0x08
	typedef struct identity
	{
		DWORD type;
		DWORD id;

		DWORD64 get_combined_identity() const
		{
			return (static_cast<UINT64>(type) << 32) | id;
		}

		static struct identity get_identity_from_combined(const DWORD64 combined)
		{
			struct identity id;
			id.type = DWORD(combined >> 32);
			id.id = DWORD(combined);
			return id;
		}

		bool operator==(const struct identity& other) const
		{
			return get_combined_identity() == other.get_combined_identity();
		}

		bool operator!=(const struct identity& other) const
		{
			return get_combined_identity() != other.get_combined_identity();
		}

		bool operator<(const struct identity& other) const
		{
			return get_combined_identity() < other.get_combined_identity();
		}

		identity()
		{
			type = 0;
			id = 0;
		}

	} identity_t, *p_identity_t;
	
	// Size = 0x0C
	typedef struct vector3
	{
		float x;					// 0x00
		float y;					// 0x04
		float z;					// 0x08

		static struct vector3 add(struct vector3& v1, struct vector3& v2)
		{
			struct vector3 a;
			a.x = v1.x + v2.x;
			a.y = v1.y + v2.y;
			a.z = v1.z + v2.z;
			return a;
		}

		static struct vector3 subtract(struct vector3& v1, struct vector3& v2)
		{
			struct vector3 a;
			a.x = v1.x - v2.x;
			a.y = v1.y - v2.y;
			a.z = v1.z - v2.z;
			return a;
		}

		void normalize()
		{
			const auto m = sqrt(x*x + y*y + z*z);
			x = x / m;
			y = y / m;
			z = z / m;
		}

		static struct vector3 cross(struct vector3& v1, struct vector3& v2)
		{
			struct vector3 c;

			c.x = v1.y*v2.z - v1.z*v2.y;
			c.y = v1.z*v2.x - v1.x*v2.z;
			c.z = v1.x*v2.y - v1.y*v2.x;

			return c;
		}

		static float dot(struct vector3& v1, struct vector3& v2)
		{
			return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
		}

		float length() const
		{
			return sqrt(x*x + y*y + z*z);
		}

		float length_squared() const
		{
			return x*x + y*y + z*z;
		}

		static float distance(struct vector3& v1, struct vector3& v2)
		{
			const auto r = subtract(v1, v2);
			return r.length();
		}

		static float distance_squared(struct vector3& v1, struct vector3& v2)
		{
			const auto r = subtract(v1, v2);
			return r.length_squared();
		}

		static float distance_x(struct vector3& v1, struct vector3& v2)
		{
			return abs(v1.x - v2.x);
		}

		static float distance_y(struct vector3& v1, struct vector3& v2)
		{
			return abs(v1.y - v2.y);
		}

		static float distance_z(struct vector3& v1, struct vector3& v2)
		{
			return abs(v1.z - v2.z);
		}

		static float distance_xz(struct vector3& v1, struct vector3& v2)
		{
			const auto d_x = v1.x - v2.x;
			const auto d_z = v1.z - v2.z;
			return sqrt(d_x*d_x + d_z*d_z);
		}

		static float distance_xz_squared(struct vector3& v1, struct vector3& v2)
		{
			const auto d_x = v1.x - v2.x;
			const auto d_z = v1.z - v2.z;
			return d_x*d_x + d_z*d_z;
		}

		float get_yaw() const
		{
			return atan2f(x, z);
		}

		vector3()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

	} vector3_t, *p_vector3_t;
	
	// Size = 0x10
	typedef struct quaternion
	{
		float x;					// 0x00
		float y; // sin(theta/2)	// 0x04
		float z;					// 0x08
		float w; // cos(theta/2)	// 0x0C

		void normalize()
		{
			const auto m = sqrt(x*x + y*y + z*z + w*w);
			x = x / m;
			y = y / m;
			z = z / m;
			w = w / m;
		}

		float get_heading() const
		{
			return atan2f(2 * y*w - 2 * x*z, 1 - 2 * y*y - 2 * z*z);
		}

		float get_raw_pitch() const
		{
			return atan2f(2*(x*w - y*z), 1 - 2 * x*x - 2 * z*z);
		}

		static struct quaternion get_quaternion(float& yaw, float& pitch)
		{
			struct quaternion q;

			const auto c1 = cosf(yaw);
			const auto c2 = cosf(0);
			const auto c3 = cosf(pitch);

			const auto s1 = sinf(yaw);
			const auto s2 = sinf(0);
			const auto s3 = sinf(pitch);

			q.w = sqrt(1 + c1*c2 + c1*c3 - s1*s2*s3 + c2*c3) / 2;
			q.x = (c2*s3 + c1*s3 + s1*s2*c3) / (4 * q.w);
			q.y = (s1*c2 + s1*c3 + c1*s2*s3) / (4 * q.w);
			q.z = (-s1*s3 + c1*s2*c3 + s2) / (4 * q.w);

			const auto m = sqrt(q.w*q.w + q.x*q.x + q.y*q.y + q.z*q.z);

			q.w = q.w / m;
			q.x = q.x / m;
			q.y = q.y / m;
			q.z = q.z / m;

			return q;
		}

		static struct quaternion get_quaternion(float& yaw)
		{
			struct quaternion q;

			q.w = cosf(yaw / 2);
			q.x = 0;
			q.y = sinf(yaw / 2);
			q.z = 0;

			return q;
		}

		static struct quaternion get_quaternion_to_face(vector3_t& to, vector3_t& from)
		{
			// Get the unit vector pointing from the element at v1 and v2 and normalize it
			auto dir = vector3_t::subtract(to, from);
			dir.normalize();
			auto yaw = dir.get_yaw();
			auto q = get_quaternion(yaw);
			q.normalize();
			return q;
		}

		quaternion()
		{
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}

	} quaternion_t, *p_quaternion_t;	

	// Size = 0xC
	typedef struct rdb_identity
	{
		DWORD low_quality_level_id;
		DWORD high_quality_level_id;
		DWORD quality_level;
	} rdb_identity_t, *p_rdb_identity_t;
	
	// Size = 0x8
	// From Utils.dll
	typedef struct i_point
	{
		DWORD x;
		DWORD y;
	} i_point_t, *p_i_point_t;

#pragma endregion

#pragma region ACGGameItem

	typedef struct acg_game_item
	{
		rdb_identity_t rdb_identity;				// 0x00
		struct dummy_item_base* p_dummy_item_base;	// 0x04
		DWORD interpolated_id;						// 0x10
	} acg_game_item_t, *p_acg_game_item_t;

#pragma endregion

#pragma region ActionLock

	// Size = 0x10
	typedef struct action_lock  // NOLINT(hicpp-member-init, cppcoreguidelines-pro-type-member-init)
	{
		identity_t action_identity;		// 0x00
		DWORD total_lockout_time;		// 0x08
		DWORD lockout_time_remaining;	// 0x0C
	} action_lock_t, *p_action_lock_t;

#pragma endregion
	
#pragma region GameData::AreaData

	// Size = 0x5C
	// From GameData.dll
	typedef struct area_data  // NOLINT(hicpp-member-init, cppcoreguidelines-pro-type-member-init)
	{
		PVOID p_v_table;				// 0x00
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x4[0x4];			// 0x04
		std::string* p_name;			// 0x08
		std::string* p_description;		// 0x0C
		std::string* p_owner_name;		// 0x10
		std::string* p_knowledge;		// 0x14
		DWORD min_level;				// 0x18
		DWORD max_level;				// 0x1C
		PVOID p_environment_data;		// 0x20
		DWORD omni_tek_control;			// 0x24
		DWORD clan_control;				// 0x28
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x2C[0x1C];		// 0x2C
		struct vector3 center;			// 0x48
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x54[0x8];			// 0x54
	} area_data_t, *p_area_data_t;

#pragma endregion

#pragma region BankEntry

	// Size = 0x38
	// From Gamecode.dll
	typedef struct bank_entry
	{
		PVOID p_v_table;									// 0x00
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x04[0x4];								// 0x04
		PVOID p_v_table_new_inventory;						// 0x08
		std::vector <struct inventory_data*> inventory;		// 0x0C
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x18[0x4];								// 0x18
		DWORD count;										// 0x1C
		identity_t inventory_identity;						// 0x20
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x28[0x10];							// 0x28
	} bank_entry_t, *p_bank_entry_t;

#pragma endregion 
	
#pragma region BinaryStream

	// Size = 0x44
	// From BinaryStream.dll
	typedef struct binary_stream
	{
		// ReSharper disable once CppInconsistentNaming
		// ReSharper disable once IdentifierTypo
		struct binary_stream* (__thiscall *BinaryStream__readmemAddress)(binary_stream*, PCSTR, size_t);	// 0x00
		// ReSharper disable once CppInconsistentNaming
		// ReSharper disable once IdentifierTypo
		struct binary_stream* (__thiscall *BinaryStream__writememAddress)(binary_stream*, BYTE, size_t);	// 0x04
		// ReSharper disable once CppInconsistentNaming
		// ReSharper disable once IdentifierTypo
		DWORD(__thiscall *BinaryStream__bgetcAddress)(binary_stream*);										// 0x08
		// ReSharper disable once CppInconsistentNaming
		// ReSharper disable once IdentifierTypo
		DWORD(__thiscall *BinaryStream__bputcAddress)(binary_stream*, BYTE);								// 0x0C
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x10[0x2C];																			// 0x10
		DWORD machine_endian;																				// 0x3C
		DWORD endian;																						// 0x40
	} binary_stream_t, *p_binary_stream;

#pragma endregion

#pragma region CameraVehicle

	// Size = 0x1EC
	// From N3.dll
	typedef struct camera_vehicle  // NOLINT(cppcoreguidelines-pro-type-member-init, hicpp-member-init)
	{
		PVOID p_v_table;									// 0x0000
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x04[0x20];							// 0x0004
		PVOID p_locality_listener_i;						// 0x0024
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x28[0x4];								// 0x0028
		struct dummy_vehicle* p_parent_vehicle;				// 0x002C
		PVOID p_vehicle_body_i;								// 0x0030
		float mass;											// 0x0034
		float max_force;									// 0x0038
		float max_vel1;										// 0x003C
		float brake_distance;								// 0x0040
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x44[0x4];								// 0x0044
		float max_vel2;										// 0x0048
		float radius;										// 0x004C
		BYTE falling_enabled;								// 0x0050
		BYTE surface_hug_enabled;							// 0x0051
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x52[0x6];								// 0x0052
		vector3_t global_pos;								// 0x0058
		vector3_t velocity;									// 0x0064
		quaternion_t direction;								// 0x0070
		quaternion_t body_rot;								// 0x0080
		float dir;											// 0x0090
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x94[0x1C];							// 0x0094
		DWORD orientation_mode;								// 0x00B0
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0xB4[0x18];							// 0x00B4
		float velocity_magnitude;							// 0x00CC
		vector3_t last_pos;									// 0x00D0
		vector3_t parent_global_pos;						// 0x00DC
		quaternion_t parent_body_rot;						// 0x00E8
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0xF8[0x5C];							// 0x00F8	
		struct n3_tile_map_surface* p_n3_tile_map_surface;	// 0x0154
		DWORD playfield_instance_id;						// 0x0158
		BYTE surface_collision_enabled;						// 0x015C
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x15D[0x3];							// 0x015D
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x160[0x1C];							// 0x0160
		struct char_vehicle* p_secondary_target_vehicle;	// 0x017C
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x180[0x6C];							// 0x180
	} camera_vehicle_t, *p_camera_vehicle_t;

#pragma endregion

#pragma region CastNanoSpellIIR

	// Size = 0x30
	// From Gamecode.dll
	typedef struct cast_nanospell_iir  // NOLINT(cppcoreguidelines-pro-type-member-init, hicpp-member-init)
	{
		PVOID p_v_table;
		identity_t identity;		
		// ReSharper disable CppInconsistentNaming
		BYTE unknown_0xC;
		BYTE unknown_0xD[0x3];
		DWORD unknown_0x10;
		DWORD unknown_0x14;
		DWORD unknown_0x18;
		DWORD unknown_0x1C;
		DWORD unknown_0x20;
		DWORD unknown_0x24;
		DWORD unknown_0x28;
		DWORD unknown_0x2C;
		// ReSharper restore CppInconsistentNaming
	} cast_nanospell_iir_t, *p_cast_nanospell_iir_t;

#pragma endregion

#pragma region CharMovementStatus

	// Size = 0x34
	// From Gamecode.dll
	typedef struct char_movement_status
	{
		PVOID p_v_table;				// 0x00
		DWORD movement_mode;			// 0x04
		DWORD is_moving_forward_back;	// 0x08 If != 1
		DWORD forward_back_direction;	// 0x0C
		DWORD is_moving_strafe;			// 0x10 If != 1
		DWORD strafe_direction;			// 0x14
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x18[0x8];			// 0x18
		DWORD is_rotating;				// 0x20 If != 1
		DWORD rotation_direction;		// 0x24
		DWORD is_jumping;				// 0x28 If = 3
		PVOID p_vehicle;				// 0x2C
		// ReSharper disable once CppInconsistentNaming
		DWORD unknown_0x30;				// 0x30
	} char_movement_status_t, *p_char_movement_status_t;

#pragma endregion

#pragma region CharVehicle	

	// Size = 0x3AC
	// From Gamecode.dll
	typedef struct char_vehicle  // NOLINT(hicpp-member-init, cppcoreguidelines-pro-type-member-init)
	{
		PVOID p_v_table;									// 0x0000
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x04[0x10];							// 0x0004
		DWORD zone_instance_id;								// 0x0014
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x18[0xC];								// 0x0018
		PVOID p_locality_listener_i;						// 0x0024
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x28[0x4];								// 0x0028
		struct dummy_vehicle* p_parent_vehicle;				// 0x002C
		PVOID p_vehicle_body_i;								// 0x0030
		float mass;											// 0x0034
		float max_force;									// 0x0038
		float max_vel1;										// 0x003C
		float brake_distance;								// 0x0040
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x44[0x4];								// 0x0044
		float max_vel2;										// 0x0048
		float radius;										// 0x004C
		BYTE falling_enabled;								// 0x0050
		BYTE surface_hug_enabled;							// 0x0051
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x52[0x6];								// 0x0052
		vector3_t global_pos;								// 0x0058
		vector3_t velocity;									// 0x0064
		quaternion_t direction;								// 0x0070
		quaternion_t body_rot;								// 0x0080
		float dir;											// 0x0090
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x94[0x1C];							// 0x0094
		DWORD orientation_mode;								// 0x00B0
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0xB4[0xC];								// 0x00B4
		vector3_t body_forward;								// 0x00C0
		float velocity_magnitude;							// 0x00CC
		vector3_t last_pos;									// 0x00D0
		vector3_t parent_global_pos;						// 0x00DC
		quaternion_t parent_body_rot;						// 0x00E8
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0xF8[0x5C];							// 0x00F8	
		struct n3_tile_map_surface* p_n3_tile_map_surface;	// 0x0154
		DWORD playfield_instance_id;						// 0x0158
		BYTE surface_collision_enabled;						// 0x015C
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x15D[0x3];							// 0x015D
		PVOID pn_3dynel_event_listener_i;					// 0x0160
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x164[0x4];							// 0x0164
		identity_t identity;								// 0x0168
		float max_speed;									// 0x0170
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x174[0x4];							// 0x0174
		p_char_movement_status_t p_char_movement_status;	// 0x0178
		struct char_vehicle* p_this_vehicle;				// 0x017C
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x180[0x22C];							// 0x0180
	} char_vehicle_t, *p_char_vehicle_t;

#pragma endregion

#pragma region ChatGUIModule

	// Size = 0x2C0
	// From GUI.dll
	typedef struct chat_gui_module
	{
		PVOID p_v_table;					// 0x00
		// ReSharper disable CppInconsistentNaming
		BYTE unknown_0x4[0x4C];				// 0x04		
		PVOID p_v_table_signal_target_c;	// 0x50
		BYTE unknown_0x54[0x4];				// 0x54
		PVOID p_v_table_base_target_c;		// 0x58
		BYTE unknown_0x5C[0x84];			// 0x5C
		PVOID p_chat_sound_effect;			// 0xE0
		PVOID p_friend_list_view;			// 0xE4
		BYTE unknown_0xE8[0x14];			// 0xE8
		PVOID p_window;						// 0xFC
		BYTE unknown_0x100[0x18];			// 0x100
		PVOID p_friends_window;				// 0x118
		BYTE unknown_0x11C[0xB4];			// 0x11C
		PVOID p_chat_group_window;			// 0x1D0
		BYTE unknown_0x1D4[0xC0];			// 0x1D4
		string afk_message;					// 0x294
		BYTE Unknown0x2AC[0x4];				// 0x2AC
		DWORD64 AFKTimer;					// 0x2B0
		PVOID p_cc_generic;					// 0x2B8
		BYTE unknown_0x2BC[0x4];			// 0x2BC
		// ReSharper restore CppInconsistentNaming
	} chat_gui_module_t, *p_chat_gui_module_t;

#pragma endregion

#pragma region ChatWindowNode

	// Size = 0x218
	// From GUI.dll
	typedef struct chat_window_node
	{
		PVOID p_v_table;				// 0x00
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x04[0x4];			// 0x04
		PVOID p_v_table_base_object_c;	// 0x08
		std::string window_name;		// 0x0C
		// ReSharper disable once CppInconsistentNaming
		BYTE unknown_0x24[0x1F4];		// 0x24
	} chat_window_node_t, *p_chat_window_node_t;

	typedef struct chat_window_node_node
	{
		struct chat_window_node_node* p_lower;		// 0x00
		struct chat_window_node_node* p_back;		// 0x04
		struct chat_window_node_node* p_higher;		// 0x08
		string window_name;							// 0x0C
		struct chat_window_node* p_chat_window;		// 0x24
	} chat_window_node_node_t, *p_chat_window_node_node_t;

	typedef struct chat_window_node_root
	{
		struct chat_window_node_node* p_begin;
		struct chat_window_node_node* p_node;
		struct chat_window_node_node* pEnd;
	} chat_window_node_root_t, *p_chat_window_node_root_t;

	typedef struct chat_window_node_dir
	{
		BYTE unknown_0x00[0x4];
		p_chat_window_node_root_t p_root;
		DWORD count;
	} chat_window_node_dir_t, *p_chat_window_node_dir_t;

#pragma endregion

#pragma region ChatWindowController
	
	// Size = 0x80
	// From GUI.dll
	typedef struct _CHATWINDOWCONTROLLER
	{
		PVOID pvTable;											// 0x00
		BYTE Unknown0x04[0x10];									// 0x04
		struct chat_window_node_dir ChatWindowNodeDir;			// 0x18
		BYTE Unknown0x20[0x1C];									// 0x20
	} CHATWINDOWCONTROLLER, *PCHATWINDOWCONTROLLER;

#pragma endregion

#pragma region CommandInterpreter

	// Size = 0x80
	// From GUI.dll
	typedef struct _COMMANDINTERPRETER
	{
		PVOID pvTable;				// 0x00
		BYTE Unknown0x04[0x7C];		// 0x04
	} COMMANDINTERPRETER, *PCOMMANDINTERPRETER;
#pragma endregion

#pragma region CollInfo

	// Size = 0x14
	// From 
	typedef struct _COLLINFO
	{
		identity_t Identity;	// 0x00
		struct vector3 Location;	// 0x08
	} COLLINFO, *PCOLLINFO;

#pragma endregion

#pragma region Chest

	// Size = 0x1E8
	// From Gamecode.dll
	typedef struct _CHEST
	{
		PVOID pvTable;										// 0x0000
		PVOID pvTable_n3DynelEventSource;					// 0x0004
		BYTE Unknown_0x08[0x4];								// 0x0008
		PVOID pvTable_DbObject;								// 0x000C
		struct _EVENTCASTER* pEventCaster;					// 0x0010
		identity_t Identity;							// 0x0014
		BYTE Unknown_0x1C[0x8];								// 0x001C
		std::vector<COLLINFO>* pCollInfoVector;				// 0x0024
		PVOID pvTable_n3Fsm;								// 0x0028
		BYTE Unknown0x2C[0x10];								// 0x002C
		BYTE IsDead;										// 0x003C
		BYTE Unknown0x3D[0x3];								// 0x003D
		struct _N3SFBASE *pFirstStateFunction;				// 0x0040
		BYTE Unknown0x44[0x4];								// 0x044
		BYTE IsNotSnoozing;									// 0x0048
		BYTE Unknown0x49[0x7];								// 0x0049
		struct dummy_vehicle *pVehicle;						// 0x0050
		BYTE IsGroundCollisionEnabled;						// 0x0054
		BYTE IsCollEnabled;									// 0x0055
		BYTE Unknown0x56[0x2];								// 0x0056
		BYTE IsStationary;									// 0x0058
		BYTE IsRepulsive;									// 0x0059
		BYTE Unknown0x5A[0x2];								// 0x005A
		struct _N3DYNAMESHCOLLSPHERE* pCollPrim;			// 0x005C
		DWORD PlayfieldInstanceId;							// 0x0060
		struct _N3TILEMAP* pn3Tilemap;						// 0x0064
		BYTE IsOnBorder;									// 0x0068
		BYTE Unknown0x69[0x2];								// 0x0069
		BYTE IsInTree;										// 0x006B	
		PVOID pn3InfoItemRemote;							// 0x006C
		std::vector<struct _N3DYNEL*>* pChildDynelVector;		// 0x0070
		identity_t ParentIdentity;					// 0x0074
		BYTE Unknown0x7C[0x4];								// 0x007C
		BYTE IsDying;										// 0x0080
		BYTE field_81[0xB];									// 0x0081
		DWORD RDBDynelStatus;								// 0x008C
		DWORD LastAllowedZoneInst;							// 0x0090
		struct vector3 LastAllowedGlobalPositionInZone;	// 0x0094
		struct vector3 ReconcilePosition;					// 0x00A0
		float BodyScale;									// 0x00AC
		PVOID pTextureDataList;								// 0x00B0
		BYTE Unknown0xB4[0xC];								// 0x00B4
		PVOID pVisualMesh_t;								// 0x00C0
		PVOID pVisualCATMesh_t;								// 0x00C4
		BYTE Unknown0xC8[0x4];								// 0x00C8
		BYTE IsClientChar;									// 0x00CC
		BYTE IsVisible;										// 0x00CD
		BYTE UseCharDistCap;								// 0x00CE
		BYTE Unknown0xCF;									// 0x00CF
		struct vector3 BoundingSpherePos;					// 0x00D0
		BYTE Unknown0xDC[0x4C];								// 0x00DC
		struct _NEWINVENTORY* pInventory;					// 0x0128
		BYTE Unknown0x12C[0x1C];							// 0x012C
		PVOID pvTable_SignalHolder;							// 0x0148
		BYTE Unknown0x14C[0x30];							// 0x014C
		PVOID pvTable_StatHolder;							// 0x017C
		std::vector<LONG>* pStatVector;						// 0x0180
		identity_t UnknownIdentity;					// 0x0184
		BYTE Unknown0x18C[0x2C];							// 0x018C
		identity_t TemplateIdentity;					// 0x01B8
		BYTE Unknown0x1C0[0x28];							// 0x01C0
	} CHEST, *PCHEST;

#pragma endregion

#pragma region DatabaseController

	// Size = 0x08
	// From DatabaseController.dll
	typedef struct _DATABASECONTROLLER
	{
		PVOID pvTable;			// 0x00
		BYTE Unknown0x08;		// 0x08
		BYTE Unknown0x09[0x3];	// 0x09
	} DATABASECONTROLLER, *PDATABASECONTROLLER;

#pragma endregion

#pragma region DbObject
	
	// Size = 0x18
	// From DatabaseController.dll
	typedef struct _DBOBJECT
	{
		PVOID pvTable;							// 0x00
		struct _EVENTCASTER* pEventCaster;		// 0x04
		identity_t Identity;				// 0x08
		BYTE Unknown_0x10[0x8];					// 0x10
	} DBOBJECT, *PDBOBJECT;

#pragma endregion

#pragma region GameData::DistrictData

	// Size = 0x6C
	// From GameData.dll
	typedef struct _DISTRICTDATA
	{
		PVOID pvTable;				// 0x00
		BYTE Unknown0x4[0x8];		// 0x04
		struct vector3 Center;		// 0x0C
		BYTE Unknown0x18[0x24];		// 0x18
		DWORD NPCMinLevel;			// 0x3C
		BYTE Unknown0x40[0x4];		// 0x40
		DWORD LandControlMinLevel;	// 0x44
		DWORD LandControlMaxLevel;	// 0x48
		DWORD RespawnChance;		// 0x4C
		float RespawnTime;			// 0x50
		DWORD FightMode;			// 0x54
		PVOID pSpawnPointVec;		// 0x58
		PVOID pHashSpawnPointVec;	// 0x5C
		PVOID pSpawnInfoVec;		// 0x60
		PVOID pWildlifeEntries;		// 0x64
		DWORD DataFormatVersion;	// 0x68
	} DISTRICTDATA, *PDISTRICTDATA;

#pragma endregion

#pragma region DummyItemBase

	// Size = 0xA4
	// From Gamecode.dll
	typedef struct dummy_item_base  // NOLINT(hicpp-member-init, cppcoreguidelines-pro-type-member-init)
	{
		PVOID p_v_table;					// 0x00
		BYTE unknown_0x04[0x34];			// 0x04
		std::vector<LONG>* p_stats_vector;	// 0x38
		identity_t parent_identity;			// 0x3C
		BYTE unknown_0x44[0x2C];			// 0x44
		identity_t identity;				// 0x70
		BYTE unknown_0x78[0x24];			// 0x78
		char const * name;					// 0x9C
		char const * description;			// 0xA0
	} dummy_item_base_t, *p_dummy_item_base_t;

#pragma endregion

#pragma region DummyVehicle

	// Size = 0x160
	// From N3.dll
	typedef struct dummy_vehicle
	{
		PVOID pvTable;									// 0x0000
		BYTE Unknown0x04[0x10];							// 0x0004
		DWORD ZoneInstanceID;							// 0x0014
		BYTE Unknown0x18[0xC];							// 0x0018
		PVOID pLocalityListener_i;						// 0x0024
		BYTE Unknown0x28[0x4];							// 0x0028
		struct dummy_vehicle* pParentVehicle;			// 0x002C
		PVOID pVehicleBody_i;							// 0x0030
		float Mass;										// 0x0034
		float MaxForce;									// 0x0038
		float MaxVel1;									// 0x003C
		float BrakeDistance;							// 0x0040
		BYTE Unknown0x44[0x4];							// 0x0044
		float MaxVel2;									// 0x0048
		float Radius;									// 0x004C
		BYTE FallingEnabled;							// 0x0050
		BYTE SurfaceHugEnabled;							// 0x0051
		BYTE Unknown0x52[0x6];							// 0x0052
		struct vector3 GlobalPos;						// 0x0058
		struct vector3 Velocity;						// 0x0064
		quaternion_t Direction;					// 0x0070
		quaternion_t BodyRot;						// 0x0080
		float Dir;										// 0x0090
		BYTE Unknown0x94[0x1C];							// 0x0094
		DWORD OrientationMode;							// 0x00B0
		BYTE Unknown0xB4[0xC];							// 0x00B4
		struct vector3 BodyForward;					// 0x00C0
		float VelocityMagnitude;						// 0x00CC
		struct vector3 LastPos;						// 0x00D0
		struct vector3 ParentGlobalPos;				// 0x00DC
		quaternion_t ParentBodyRot;				// 0x00E8
		BYTE Unknown0xF8[0x5C];							// 0x00F8	
		struct n3_tile_map_surface* pn3TilemapSurface;	// 0x0154
		DWORD PlayfieldInstanceId;						// 0x0158
		BYTE SurfaceCollisionEnabled;					// 0x015C
		BYTE Unknown0x15D[0x3];							// 0x015D
	} dummy_vehicle_t, *p_dummy_vehicle_t;

#pragma endregion

#pragma region DummyWeapon

	// Size = 0xE8
	// From Gamecode.dll
	typedef struct _DUMMYWEAPON
	{
		PVOID pvTable;						// 0x00
		BYTE Unknown0x04[0x34];				// 0x04
		std::vector<LONG>* pStatsVector;	// 0x38
		identity_t UnknownsIdentity;	// 0x3C
		BYTE Unknown0x44[0x2C];				// 0x44
		identity_t Identity;			// 0x70
		BYTE Unknown0x78[0x24];				// 0x78
		char const * Name;					// 0x9C
		char const * Description;			// 0xA0
		identity_t WeaponIdentity;	// 0xA4
		BYTE Unknown0xAC[0x3C];				// 0xAC
	} DUMMYWEAPON, *PDUMMYWEAPON;

#pragma endregion

#pragma region DynelMap

	typedef struct _NODE
	{
		struct _NODE* pLower;
		struct _NODE* pBack;
		struct _NODE* pHigher;
	} NODE, *PNODE;

	typedef struct _ROOT
	{
		struct _NODE* pBegin;
		struct _NODE* pNode;
		struct _NODE* pEnd;
	} ROOT, *PROOT;

	typedef struct _DIR
	{
		BYTE Unknown0x00[0x4];
		struct _ROOT* pRoot;
		DWORD Count;
	} DIR, *PDIR;

	// Size = 0x18
	typedef struct _DYNELNODE
	{
		struct _DYNELNODE* pLower;		// 0x00
		struct _DYNELNODE* pBack;		// 0x04
		struct _DYNELNODE* pHigher;		// 0x08
		identity_t Identity;			// 0x0C
		struct _N3DYNEL* pDynel;			// 0x14
	} DYNELNODE, *PDYNELNODE;

	// Size = 0x0C
	typedef struct _DYNELROOT
	{
		struct _DYNELNODE* pBegin;		// 0x00
		struct _DYNELNODE* pNode;			// 0x04
		struct _DYNELNODE* pEnd;			// 0x08
	} DYNELROOT, *PDYNELROOT;

	// Size = 0x0C
	// From Gamecode.dll
	typedef struct _DYNELDIR
	{
		BYTE Unknown0x00[0x4];				// 0x00
		struct _DYNELROOT* pRoot;			// 0x04
		DWORD Count;						// 0x08
	} DYNELDIR, *PDYNELDIR;

#pragma endregion

#pragma region EventCaster

	// Size = 0x18
	// From N3.dll
	typedef struct _EVENTCASTER
	{
		PVOID pvTable;											// 0x00
		BYTE Unknown0x4[0x10];									// 0x04
		VOID(__thiscall *pn3Dynel_t__ReleaseAddress)(PVOID);	// 0x14
	} EVENTCASTER, *PEVENTCASTER;

#pragma endregion

#pragma region FlowControl

	// Size = 0x58
	// From GUI.dll
	typedef struct _FLOWCONTROL
	{
		PVOID pvTable;			// 0x00
		BYTE Unknown0x04[0x54];	// 0x04
	} FLOWCONTROL, *PFLOWCONTROL;


#pragma endregion

#pragma region Gametime

	// Size = 0xC8
	// From Gamecode.dll
	typedef struct _GAMETIME
	{
		PVOID pvTable;					// 0x00
		BYTE Unknown0x04[0x14];			// 0x04
		WORD SecondPing;				// 0x18
		BYTE OddSecondPing;				// 0x1A
		BYTE Unknown0x1B[0xD];			// 0x1B
		DOUBLE NormalTime;				// 0x28
		BYTE Unknown0x30[0x8];			// 0x30
		DOUBLE SecondPingDeltaTime;		// 0x38
		DWORD CurrentSecond;			// 0x40
		DWORD CurrentMinute;			// 0x44	
		DWORD CurrentHour;				// 0x48
		DWORD CurrentDay;				// 0x4C
		DOUBLE CurrentRealTime;			// 0x50
		DWORD DayPeriod;				// 0x58
		DWORD GameSecondsPerSecond;		// 0x5C
		BYTE Unknown0x60[0x18];			// 0x60
		DOUBLE DeltaTime;				// 0x78
		BYTE Unknown0x80[0x4];			// 0x80
		DWORD MinutesPerHour;			// 0x84
		DWORD SecondsPerMinute;			// 0x88
		DWORD SecondsInAHour;			// 0x8C
		DWORD HourOfDuskStart;			// 0x90
		DWORD DuskDurationInHours;		// 0x94
		DWORD HourOfDawnStart;			// 0x98
		DWORD DawnDurationInHours;		// 0x9C
		float SecondsInADay;			// 0xA0
		BYTE Unknown0xA4[0x10];			// 0xA4
		DWORD SystemTime;				// 0xB4
		BYTE Unknown0xB8[0x8];			// 0xB8
		DWORD SystemTimeCounted;		// 0xC0
		float SystemSecondsCounted;		// 0xC4
	} GAMETIME, *PGAMETIME;

#pragma endregion

#pragma region GraphPathFinder

	// Size = 0x24
	// From PathFinder.dll
	typedef struct _GRAPHPATHFINDER
	{
		PVOID pvTable;				// 0x00
		PVOID pAstarGraph_t;		// 0x04
		PVOID pVisibilityGraph_t;	// 0x08
		PVOID pSpace_i;				// 0x0C
		PVOID pSurface_i;			// 0x10
		DWORD GridSizeX;			// 0x14
		DWORD GridSizeZ;			// 0x18
		float TotalSizeX;			// 0x1C
		float TotalSizeZ;			// 0x20
	} GRAPHPATHFINDER, *PGRAPHPATHFINDER;

#pragma endregion

#pragma region GridSpace

	// Size = 0x3C
	// From Vehicle.dll
	typedef struct _GRIDSPACE
	{
		PVOID pvTable;						// 0x00
		PVOID pvTable_ChangeListener_i;		// 0x04
		PVOID pvTable_DetectionListener_i;	// 0x08
		BYTE Unknown0xC[0x14];				// 0x0C
		float TotalSizeX;					// 0x20
		float TotalSizeZ;					// 0x24
		DWORD GridSizeX;					// 0x28
		DWORD GridSizeZ;					// 0x2C
		BYTE Unknown0x30[0xC];				// 0x30
	} GRIDSPACE, *PGRIDSPACE;

#pragma endregion

#pragma region GameData::HashSpawnPoint

	//From GameData.dll
	// Size = 0x6C
	typedef struct _HASHSPAWNPOINT
	{
		PVOID pvTable;					// 0x00
		struct vector3 CenterPos;		// 0x04
		float Radius;					// 0x10
		float RotationMid;				// 0x14
		float RotationWidth;			// 0x18
		PVOID pvTable_ReferenceCounted;	// 0x1C
		BYTE Unknown0x20[0x4];			// 0x20
		DWORD Hash;						// 0x24
		DWORD MinLevel;					// 0x28
		DWORD MaxLevel;					// 0x2C
		DWORD RespawnChance;			// 0x30
		float RespawnTime;				// 0x34
		DWORD Flags;					// 0x38
		BYTE Unknown0x3C[0x4];			// 0x3C
		DWORD ProximityRange;			// 0x40
		DWORD AdditionalPoints;			// 0x44
		BYTE Unknown0x48[0xC];			// 0x48
		PVOID pSpells;					// 0x54
		BYTE Unknown0x58[0xC];			// 0x58
		DWORD MoreFlags;				// 0x64
		DWORD Tags;						// 0x68
	} HASHSPAWNPOINT, *PHASHSPAWNPOINT;

#pragma endregion

#pragma region HotSpot

	// Size = 0x54
	// From GUI.dll
	typedef struct _HOTSPOT
	{
		PVOID pvTable;				// 0x00
		DWORD SortLevel;			// 0x04
		BYTE Unknown0x08[0x4];		// 0x08
		DWORD TooltipStatus;		// 0x0C
		PVOID TooltipCallback;		// 0x10
		BYTE Unknown0x14[0x4];		// 0x14
		PCSTR pHelpText;		// 0x18
		BYTE Unknown0x1C[0x8];		// 0x1C
		BYTE IsDragable;			// 0x24
		BYTE IsInstantDrag;			// 0x25
		BYTE Unknown0x26[0x2];		// 0x26
		PVOID pRenderWindow;		// 0x28
		DWORD HotRectCorner1;		// 0x2C
		DWORD HotRectCorner2;		// 0x30
		DWORD HotRectCorner3;		// 0x34
		DWORD HotRectCorner4;		// 0x38
		i_point_t OrgPos;		// 0x3C
		i_point_t Unknown0x44;	// 0x44
		BYTE Unknown0x4C[0x4];		// 0x4C
		BYTE IsInserted;			// 0x50
		BYTE Unknown0x51[0x3];		// 0x51
	} HOTSPOT, *PHOTSPOT;

#pragma endregion

#pragma region HTMLParser

	// Size = 0x50
	// From GUI.dll
	typedef struct _HTMLPARSER
	{
		PVOID pvTable;			// 0x00
		string HtmlText;		// 0x04;
		BYTE Unknown0x1C[0x4];	// 0x1C
		BYTE Unknown0x20[0x20];	// 0x20
		DWORD FontId;			// 0x40
		BYTE Unknown0x44[0x8];	// 0x44
		DWORD FeatureFlags;		// 0x4C
	} HTMLPARSER, *PHTMLPARSER;

#pragma endregion

#pragma region Indicator

	// Size = 0x3C
	// From GUI.dll
	typedef struct _INDICATOR
	{
		PVOID pvTable;				// 0x00
		BYTE Uknown0x04[0x4];		// 0x04
		identity_t Identity;	// 0x08
		BYTE Unknown0x10[0x2C];		// 0x10
	} INDICATOR, *PINDICATOR;

#pragma endregion

#pragma region InputConfig

	// Size = 0x1D0
	// From GUI.dll
	typedef struct _INPUTCONFIG
	{
		PVOID pvTable;										// 0x0000
		BYTE Unknown0x04[0x18];								// 0x0004
		PVOID pHotkeyList;									// 0x001C
		DWORD TooltipTime;									// 0x0020
		BYTE Unknown0x24[0x80];								// 0x0024
		struct vector3 MouseWorldPosition;					// 0x00A4
		identity_t CurrentID;							// 0x00B0
		identity_t CurrentReference;					// 0x00B8
		identity_t CurrentTarget;						// 0x00C0
		DWORD CurrentVoidReference;							// 0x00C8
		struct _HOTSPOT* pCurrentHotspot;					// 0x00CC
		struct _HOTSPOT* pLastMouseButtonPressedHotspot;	// 0x00D0
		DWORD CharacterID;									// 0x00D4
		identity_t CharacterIdentity;					// 0x00D8
		BYTE Unknown0xE0[0x10];								// 0x00E0
		DWORD LastHotkeyPressed;							// 0x00F0
		BYTE Unknown0xF4[0x24];								// 0x00F4
		i_point_t CurrentMousePosition;				// 0x0118
		BYTE Unknown0x0120[0xB0];							// 0x0120
	} INPUTCONFIG, *PINPUTCONFIG;

#pragma endregion

#pragma region Inventory

	// Size = 0x2C
	// From Gamecode.dll
	typedef struct inventory_data  // NOLINT(hicpp-member-init, cppcoreguidelines-pro-type-member-init)
	{
		BYTE unknown_0x00[0x2];			// 0x00
		WORD count;						// 0x02
		identity_t dynel_identity;		// 0x04	
		rdb_identity_t rdb_identity;	// 0x0C
		DWORD quality_level;			// 0x14
		BYTE unknown_0x18[0x14];		// 0x18
	} inventory_data_t, *p_inventory_data_t;

	// Size = 0x2C
	// From Gamecode.dll
	typedef struct _NEWINVENTORY
	{
		PVOID pvTable;										// 0x00
		std::vector <struct inventory_data*> pInventoryData;	// 0x04
		BYTE Unknown0x10[0x4];								// 0x10
		DWORD Count;										// 0x14
		identity_t InventoryIdentity;					// 0x18
		BYTE Unknown0x20[0xC];								// 0x20
	} NEWINVENTORY, *PNEWINVENTORY;

	// Size = 0x1B8
	// From Gamecode.dll
	typedef struct _INVENTORYHOLDER
	{
		struct _SIMPLECHAR* pClientControlDynel;	// 0x0000
		identity_t* pClientIdentity;			// 0x0004
		struct _NEWINVENTORY* pRegularInventory;	// 0x0008
		struct _NEWINVENTORY* pUnknownInventory;	// 0x000C
		struct _NEWINVENTORY* pOverflowInventory;	// 0x0010
		BYTE Unknown0x14[0x168];					// 0x0014
		p_bank_entry_t p_bank_entry;				// 0x017C
		BYTE Unknown0x180[0x38];					// 0x0180
	} INVENTORYHOLDER, *PINVENTORYHOLDER;

	typedef struct _INVENTORYENTRY
	{
		identity_t TemplateIdentity;			// 0x00
		DWORD Unknown1;								// 0x04
		DWORD Unknown2;								// 0x08
		WORD Unknown3;								// 0x0C
		WORD Unknown4;								// 0x0E
	} INVENTORYENTRY, *PINVENTORYENTRY;

#pragma endregion

#pragma region LockIdMap

	// Size = 0x18
	typedef struct _LOCKIDNODE
	{
		struct _LOCKIDNODE* pLower;		// 0x00
		struct _LOCKIDNODE* pBack;		// 0x04
		struct _LOCKIDNODE* pHigher;	// 0x08
		DWORD LockId;					// 0x0C
		DWORD ActionId;					// 0x14
	} LOCKIDNODE, *PLOCKIDNODE;

	typedef struct _LOCKIDROOT
	{
		struct _LOCKIDNODE* pBegin;		// 0x00
		struct _LOCKIDNODE* pNode;			// 0x04
		struct _LOCKIDNODE* pEnd;			// 0x08
	} LOCKIDROOT, *PLOCKIDROOT;

	typedef struct _LOCKIDDIR
	{
		BYTE Unknown0x0[0x4];		// 0x00
		struct _LOCKIDROOT* pRoot;	// 0x04
		DWORD Count;
	} LOCKIDDIR, *PLOCKIDDIR;

#pragma endregion

#pragma region LookAtIIR

	// Size = 0x24
	// From Gamecode.dll
	typedef struct _LOOKATIIR
	{
		PVOID pvTable;				// 0x00
		identity_t ClientId;	// 0x04
		BYTE Unknown0xC;			// 0x0C
		BYTE Unknown0xD[0x3];		// 0x0D
		DWORD MapToKey;				// 0x10
		DWORD Unknown0x14;			// 0x14
		identity_t TargetId;	// 0x18
		DWORD Unknown0x20;			// 0x20
	} LOOKATIIR, *PLOOKATIIR;

#pragma endregion

#pragma region LoginModule_c

	// Size = 0xB8
	// From GUI.dll
	typedef struct _LOGINMODULE
	{
		PVOID pvTable;				// 0x00
		BYTE Unknown0x04[0xC];		// 0x04
		PVOID pLoginWindow;			// 0x10
		PVOID pCharSelectWindow;	// 0x14
		PVOID pLimboWindow;			// 0x18
		BYTE Unknown0x1C[0x78];		// 0x1C
		PVOID pLoginWorld;			// 0x94
	} LOGINMODULE, *PLOGINMODULE;

#pragma endregion

#pragma region StatHolder

	typedef struct _STATHOLDER
	{
		std::vector<action_lock_t>* pSkillLocks;	// 0x00
		struct _STATDIR* pStatMapDir;			// 0x04
	} STATHOLDER, *PSTATHOLDER;

#pragma endregion

#pragma region Message

	typedef struct _MESSAGE
	{
		PVOID pvTable;				// 0x00
		WORD MessageId;				// 0x04
		WORD Unknown0x06;			// 0x06
		DWORD MessageType;			// 0x08
		DWORD SourceId;				// 0x0C
		DWORD DestId;				// 0x10
		DWORD Priority;				// 0x14
		DWORD Unknnown0x18;			// 0x18
	} MESSAGE, *PMESSAGE;

#pragma endregion

#pragma region n3Camera

	// Size - 0x258
	// From N3.dll
	typedef struct _N3CAMERA
	{
		PVOID pvTable;										// 0x0000
		PVOID pvTable_n3DynelEventSource;					// 0x0004
		BYTE Unknown_0x08[0x4];								// 0x0008
		PVOID pvTable_DbObject;								// 0x000C
		struct _EVENTCASTER* pEventCaster;					// 0x0010
		identity_t Identity;							// 0x0014
		BYTE Unknown_0x1C[0x8];								// 0x001C
		BYTE Unknown0x24[0x4];								// 0x0024
		PVOID pvTable_n3Fsm;								// 0x0028
		BYTE Unknown0x04[0x10];								// 0x002C
		BYTE IsDead;										// 0x003C
		BYTE Unknown0x15[0x3];								// 0x003D
		struct _N3SFBASE *pFirstStateFunction;				// 0x0040
		BYTE Unknown0x44[0xC];								// 0x0044
		p_camera_vehicle_t pCameraVehicle;				// 0x0050
		BYTE Unknown0x54[0x190];							// 0x0054
		identity_t SelectedTarget;					// 0x01E4
		DWORD CameraType;									// 0x01EC 0 - 1st Person, 1 = 3rd Person Trail, 2 = 3rd Person Rubber, 3 = 3rd Person Lock
		BYTE Unknown0x1F0[0x10];							// 0x01F0
		PVOID pVisualCamera;								// 0x0200
		BYTE Unknown0x204[0x54];							// 0x0204
	} N3CAMERA, *PN3CAMERA;

#pragma endregion

#pragma region n3CellMonitor

	// Size = 0x38
	// From N3.dll
	typedef struct _N3CELLMONITOR
	{
		PVOID pvTable;					// 0x00
		BYTE Unknown0x04[0x20];			// 0x04
		PVOID pLocalityListener_i;		// 0x24
		struct vector3 Pos;			// 0x28
		BYTE Unknown0x34[0x4];			// 0x34
	} N3CELLMONITOR, *PN3CELLMONITOR;

#pragma endregion

#pragma region n3DatabaseHandler

	// Size = 0xC
	// From N3.dll
	typedef struct _N3DATABASEHANDLER
	{
		PVOID pvTable;									// 0x00
		struct _RESOURCEDATABASE* pResourceDatabase;	// 0x04
		struct _RESOURCEDATABASE* pGameDatabase;		// 0x08
	} N3DATABASEHANDLER, *PN3DATABASEHANDLER;

#pragma endregion

#pragma region N3DynaMeshCollsphere

	// Size = 0x18
	// From Collision.dll
	typedef struct _COLLPRIM
	{
		PVOID pvTable;					// 0x00
		struct vector3 GlobalPos;		// 0x04
		BYTE Unknown0x10[0x4];			// 0x10
		DWORD CollPrimType;				// 0x14 Sphere = 2
	} COLLPRIM, *PCOLLPRIM;

	// Size = 0x1C
	// From Collision.dll
	typedef struct _COLLSPHERE
	{
		struct _COLLPRIM CollPrim;		// 0x00
		float PossibleRadius;			// 0x18
	} COLLSPHERE, *PCOLLSPHERE;

	// Size = 0x1C
	// From Collision.dll
	typedef struct _MESHCOLLSPHERE
	{
		struct _COLLSPHERE CollSphere;				// 0x00
	} MESHCOLLSPHERE, _MESHCOLLSPHERE;

	// Size = 0x30
	// From N3.dll
	typedef struct _N3DYNAMESHCOLLSPHERE
	{
		struct _MESHCOLLSPHERE MeshCollSphere;		// 0x00
		PVOID pLocalityListener_i;					// 0x1C
		struct _N3DYNEL* pOwner;					// 0x20
		struct vector3 OriginalRelativePosition;	// 0x24
	} N3DYNAMESHCOLLSPHERE, *PN3DYNAMESHCOLLSPHERE;

#pragma endregion

#pragma region n3Dynel

	// Size = 0xA0
	// From N3.dll
	typedef struct _N3DYNEL
	{
		PVOID pvTable;										// 0x00
		PVOID pvTable_n3DynelEventSource;					// 0x04
		BYTE Unknown_0x08[0x4];								// 0x08
		PVOID pvTable_DbObject;								// 0x0C
		struct _EVENTCASTER* pEventCaster;					// 0x10
		identity_t Identity;							// 0x14
		BYTE Unknown_0x1C[0x8];								// 0x1C
		std::vector<COLLINFO>* pCollInfoVector;				// 0x24
		PVOID pvTable_n3Fsm;								// 0x28
		BYTE Unknown0x2C[0x10];								// 0x2C
		BYTE IsDead;										// 0x3C
		BYTE Unknown0x3D[0x3];								// 0x3D
		struct _N3SFBASE *pFirstStateFunction;				// 0x40
		BYTE Unknown0x44[0x4];								// 0x44
		BYTE IsNotSnoozing;									// 0x48
		BYTE Unknown0x49[0x7];								// 0x49
		struct dummy_vehicle *pVehicle;						// 0x50
		BYTE IsGroundCollisionEnabled;						// 0x54
		BYTE IsCollEnabled;									// 0x55
		BYTE Unknown0x56[0x2];								// 0x56
		BYTE IsStationary;									// 0x58
		BYTE IsRepulsive;									// 0x59
		BYTE Unknown0x5A[0x2];								// 0x5A
		struct _N3DYNAMESHCOLLSPHERE* pCollPrim;			// 0x5C
		DWORD PlayfieldInstanceId;							// 0x60
		struct _N3TILEMAP* pn3Tilemap;						// 0x64
		BYTE IsOnBorder;									// 0x68
		BYTE Unknown0x69[0x2];								// 0x69
		BYTE IsInTree;										// 0x6B	
		PVOID pn3InfoItemRemote;							// 0x6C
		std::vector<struct _N3DYNEL*>* pChildDynelVector;		// 0x70
		identity_t ParentIdentity;					// 0x74
		BYTE Unknown0x7C[0x4];								// 0x7C
		BYTE IsDying;										// 0x80
		BYTE field_81[0xB];									// 0x81
		DWORD RDBDynelStatus;								// 0x8C
		DWORD LastAllowedZoneInst;							// 0x90
		struct vector3 LastAllowedGlobalPositionInZone;	// 0x94
	} N3DYNEL, *PN3DYNEL;

#pragma endregion

#pragma region n3DynelEventSource

	// Size = 0x08
	// From N3.dll
	typedef struct _N3DYNELEVENTSOURCE
	{
		PVOID pvTable;				// 0x00
		BYTE Unknown_0x04[0x4];		// 0x04
	} N3DYNELEVENTSOURCE, *PN3DYNELEVENTSOURCE;

#pragma endregion

#pragma region n3EngineClientAnarchy

	// Size = 0x130
	// From Gamecode.dll
	typedef struct n3_engine_client_anarchy  // NOLINT(hicpp-member-init, cppcoreguidelines-pro-type-member-init, cppcoreguidelines-pro-type-member-init, cppcoreguidelines-pro-type-member-init)
	{
		PVOID p_v_table;										// 0x0000
		binary_stream_t binary_stream;						// 0x0004
		BYTE unknown_0x48[0x10];								// 0x0048
		BYTE teleport_status;									// 0x0058
		BYTE unknown_0x59[0x7];									// 0x0059					
		struct _RESOURCEDATABASE* p_resource_database;			// 0x0060
		struct _N3ROOT* p_n3_root;								// 0x0064
		float delta_time;										// 0x0068
		BYTE unknown_0x6C[0x4];									// 0x006C
		float total_time;										// 0x0070
		struct _N3OBJECTFACTORY* p_n3_object_factory;			// 0x0074
		BYTE unknown_0x78[0x4];									// 0x0078
		struct _N3CAMERA* p_n3_camera;							// 0x007C
		DWORD client_inst_id;									// 0x0080
		struct _SIMPLECHAR* p_client_control_char;				// 0x0084
		BYTE unknown_0x88[0x8];									// 0x0088
		struct n3_engine_client_anarchy** pp_client_interface;	// 0x0090
		BYTE unknown_0x94[0xC];									// 0x0094
		PVOID p_grid_destination_list;							// 0x00A0
		BYTE unknown_0xA4[0x24];								// 0x00A4
		identity_t mouseover_target;						// 0x00C8
		BYTE unknown_0xD0[0x8];									// 0x00D0
		DOUBLE time_of_last_motion;								// 0x00D8
		quaternion_t last_rot;							// 0x00E0
		struct vector3 last_move;								// 0x00F0
		BYTE unknown_0xFC[0x4];									// 0x00FC
		PVOID p_anim_calibration_control;						// 0x0100
		BYTE is_first_login;									// 0x0104
		BYTE unknown_0x105[0x2B];								// 0x0105
	} n3_engine_client_anarchy_t, *p_n3_engine_client_anarchy_t;

#pragma endregion

#pragma region n3Fobj

	// Size = 0x18
	// From N3.dll
	typedef struct _N3FOBJ
	{
		PVOID pvTable;				// 0x00
		BYTE Unknown0x04[0x10];		// 0x04
		BYTE Unknown0x14;			// 0x14
		BYTE Unknown0x15[0x3];		// 0x15
	} N3FOBJ, *PN3FOBJ;

#pragma endregion
	
#pragma region n3Fsm

	// Size = 1C
	// From N3.dll
	typedef struct _N3FSM
	{
		PVOID pvTable;												// 0x00
		BYTE Unknown0x04[0x10];										// 0x04
		BYTE IsDead;												// 0x14
		BYTE Unknown0x15[0x3];										// 0x15
		struct _N3SFBASE *pFirstStateFunction;						// 0x18
	} N3FSM, *PN3FSM;	

#pragma endregion

#pragma region N3Message

	typedef struct _N3MESSAGE
	{
		PVOID pvTable;				// 0x00
		WORD MessageId;				// 0x04
		WORD Unknown0x06;			// 0x06
		DWORD MessageType;			// 0x08
		DWORD SourceId;				// 0x0C
		DWORD DestId;				// 0x10
		DWORD Priority;				// 0x14
		DWORD Unknown0x18;			// 0x18
		PVOID pACE_Data_Block;		// 0x1C
		DWORD MessageBodyLen;		// 0x20
	} N3MESSAGE, *PN3MESSAGE;


#pragma endregion

#pragma region n3ObjectFactory

	// Size = 0x8
	// From N3.dll
	typedef struct _N3OBJECTFACTORY
	{
		struct _RESOURCEDATABASE* pResourceDatabase;	// 0x00
		DWORD Unknown0x04;								// 0x04
	} N3OBJECTFACTORY, *PN3OBJECTFACTORY;

#pragma endregion

#pragma region n3Root

	// Size = 0x3C
	// From N3.dll
	typedef struct _N3ROOT
	{
		PVOID pvTable;				// 0x00
		BYTE Unknown0x04[0x1C];		// 0x04
		BYTE Unknown0x20;			// 0x20
		BYTE Unknown0x21[0x3];		// 0x21
		PVOID pvTable_n3Fobj;		// 0x24
		BYTE Unknown0x28[0x10];		// 0x28
		BYTE Unknown0x38;			// 0x38
		BYTE Unknown0x39[0x3];		// 0x39
	} N3ROOT, *PN3ROOT;

#pragma endregion

#pragma region n3SfBase

	// Size = 0x08
	// From N3.dll
	typedef struct _N3SFBASE
	{
		PVOID pvTable;			// 0x00
		struct _N3FSM* pN3Fsm;	// 0x04
	} N3SFBASE, *PN3SFBASE;

#pragma endregion

#pragma region N3Tilemap	

	// Size = 0x424
	// From N3.dll
	typedef struct _N3TILEMAP
	{
		PVOID pvTable;						// 0x0000
		BYTE Unknown0x04[0x4];				// 0x0004
		DWORD PlayfieldInstanceID;			// 0x0008
		struct _RDBTILEMAP* pRDBTileMap;	// 0x000C
		BYTE Unknown0x10[0x410];			// 0x0010
		PVOID pRDBHeightmap;				// 0x0420
	} N3TILEMAP, *PN3TILEMAP;

#pragma endregion

#pragma region n3TilemapSurface

	// Size = 0x18
	// From N3.dll
	typedef struct n3_tile_map_surface
	{
		PVOID pvTable;				// 0x00
		BYTE Unknown0x04[0x14];		// 0x04
	} n3_tile_map_surface_t, *p_n3_tile_map_surface_t;

#pragma endregion

#pragma region N3VisualDynel

	// Size = 0xE0
	// From N3.dll
	typedef struct _N3VISUALDYNEL
	{
		PVOID pvTable;										// 0x00
		PVOID pvTable_n3DynelEventSource;					// 0x04
		BYTE Unknown_0x08[0x4];								// 0x08
		PVOID pvTable_DbObject;								// 0x0C
		struct _EVENTCASTER* pEventCaster;					// 0x10
		identity_t Identity;							// 0x14
		BYTE Unknown_0x1C[0x8];								// 0x1C
		std::vector<COLLINFO>* pCollInfoVector;				// 0x24
		PVOID pvTable_n3Fsm;								// 0x28
		BYTE Unknown0x2C[0x10];								// 0x2C
		BYTE IsDead;										// 0x3C
		BYTE Unknown0x3D[0x3];								// 0x3D
		struct _N3SFBASE *pFirstStateFunction;				// 0x40
		BYTE Unknown0x44[0x4];								// 0x44
		BYTE IsNotSnoozing;									// 0x48
		BYTE Unknown0x49[0x7];								// 0x49
		struct dummy_vehicle *pVehicle;						// 0x50
		BYTE IsGroundCollisionEnabled;						// 0x54
		BYTE IsCollEnabled;									// 0x55
		BYTE Unknown0x56[0x2];								// 0x56
		BYTE IsStationary;									// 0x58
		BYTE IsRepulsive;									// 0x59
		BYTE Unknown0x5A[0x2];								// 0x5A
		struct _N3DYNAMESHCOLLSPHERE* pCollPrim;			// 0x5C
		DWORD PlayfieldInstanceId;							// 0x60
		struct _N3TILEMAP* pn3Tilemap;						// 0x64
		BYTE IsOnBorder;									// 0x68
		BYTE Unknown0x69[0x2];								// 0x69
		BYTE IsInTree;										// 0x6B	
		PVOID pn3InfoItemRemote;							// 0x6C
		std::vector<struct _N3DYNEL*>* pChildDynelVector;		// 0x70
		identity_t ParentIdentity;					// 0x74
		BYTE Unknown0x7C[0x4];								// 0x7C
		BYTE IsDying;										// 0x80
		BYTE field_81[0xB];									// 0x81
		DWORD RDBDynelStatus;								// 0x8C
		DWORD LastAllowedZoneInst;							// 0x90
		struct vector3 LastAllowedGlobalPositionInZone;	// 0x94
		struct vector3 ReconcilePosition;					// 0xA0
		float BodyScale;									// 0xAC
		PVOID pTextureDataList;								// 0xB0
		BYTE Unknown0xB4[0xC];								// 0xB4
		PVOID pVisualMesh_t;								// 0xC0
		PVOID pVisualCATMesh_t;								// 0xC4
		BYTE Unknown0xC8[0x4];								// 0xC8
		BYTE IsClientChar;									// 0xCC
		BYTE IsVisible;										// 0xCD
		BYTE UseCharDistCap;								// 0xCE
		BYTE Unknown0xCF;									// 0xCF
		struct vector3 BoundingSpherePos;					// 0xD0
		float Unknown0xDC;									// 0xDC
	} N3VISUALDYNEL, *PN3VISUALDYNEL;


#pragma endregion

#pragma region NanoItem

	// Size = 0xC0
	typedef struct _NANOITEM
	{
		PVOID pvTable;						// 0x04
		BYTE Unknown0x04[0x34];				// 0x04
		std::vector <LONG>* pStatsVector;	// 0x38
		identity_t ParentIdentity;	// 0x3C
		BYTE Unknown0x44[0x2C];				// 0x44
		identity_t UnknownIdentity;	// 0x70
		BYTE Unknown0x78[0x24];				// 0x78
		char const * Name;					// 0x9C
		char const * Description;			// 0xA0
		identity_t NanoIdentity;		// 0xA4
		BYTE Unknown0xAC[0xC];				// 0xAC
		DWORD Radius;						// 0xB8
		BYTE IsNanoSelfOnly;				// 0xBC
		BYTE Unknown0xBC[0x3];				// 0xBD
	} NANOITEM, *PNANOITEM;

#pragma endregion

#pragma region NanoMap

	// Size = 0x14
	typedef struct _NANOITEMNODE
	{
		struct _NANOITEMNODE* pLower;		// 0x00
		struct _NANOITEMNODE* pNode;		// 0x04
		struct _NANOITEMNODE* pHigher;	// 0x08
		DWORD NanoItemId;					// 0x0C
		struct _NANOITEM* pNanoItem;		// 0x10
	} NANOITEMNODE, *PNANOITEMNODE;

	// Size = 0xC
	typedef struct _NANOITEMROOT
	{
		struct _NANOITEMNODE* pBegin;		// 0x00
		struct _NANOITEMNODE* pNode;		// 0x04
		struct _NANOITEMNODE* pEnd;		// 0x08
	} NANOITEMROOT, *PNANOITEMROOT;

	// Size = 0xC
	// From Gamecode.dll
	typedef struct _NANOITEMDIR
	{
		BYTE Unknown0x00[0x4];				// 0x00
		struct _NANOITEMROOT* pRoot;		// 0x04
		DWORD Count;						// 0x08
	} NANOITEMDIR, *PNANOITEMDIR;

#pragma endregion

#pragma region NanoTemplate

	// Size = 0x1C
	// From Gamecode.dll
	typedef struct _NANOTEMPLATE
	{
		identity_t NanoIdentity;		// 0x00
		DWORD StartTime;					// 0x08
		DWORD Duration;						// 0x0C
		BYTE Unknown0x10[0x4];				// 0x10
		identity_t CasterIdentity;	// 0x14
	} NANOTEMPLATE, *PNANOTEMPLATE;

#pragma endregion

#pragma region NpcHolder

	typedef struct _PETNODE
	{
		struct _PETNODE* pLower;
		struct _PETNODE* pNode;
		struct _PETNODE* pHigher;
		identity_t Identity;
		DWORD Index;
	} PETNODE, *PPETNODE;

	typedef struct _PETROOT
	{
		struct _PETNODE* pBegin;
		struct _PETNODE* pNode;
		struct _PETNODE* pEnd;
	} PETROOT, *PPETROOT;

	typedef struct _PETDIR
	{
		BYTE Unknown0x0[0x4];
		struct _PETROOT* pRoot;
		DWORD Count;
	} PETDIR, *PPETDIR;


	// Size = 0x2C
	// From Gamecode.dll
	typedef struct _NPCHOLDER
	{
		PVOID pvTable;				// 0x00
		BYTE Unknown0x04[0x18];		// 0x04
		struct _PETDIR* pPetDir;	// 0x1C
		BYTE Unknown0x20[0xC];		// 0x20
	} NPCHOLDER, *PNPCHOLDER;

#pragma endregion

#pragma region PerkHolder

	typedef struct _PERKHOLDER
	{
		BYTE Unknown0x00[0x4];					// 0x00
		struct _PERKDIR* pPerkDir;				// 0x04
		std::vector<action_lock_t>* pPerkLocks;	// 0x08
	} PERKHOLDER, *PPERKHOLDER;

#pragma endregion

#pragma region PerkMap

	typedef struct _PERKNODE
	{
		struct _PERKNODE* pLower;
		struct _PERKNODE* pBack;
		struct _PERKNODE* pHigher;
		identity_t PerkIdentity;
		DWORD PerkID;
	} PERKNODE, *PPERKNODE;

	typedef struct _PERKROOT
	{
		struct _PERKNODE* pBegin;
		struct _PERKNODE* pNode;
		struct _PERKNODE* pEnd;
	} PERKROOT, *PPERKROOT;

	typedef struct _PERKDIR
	{
		BYTE Unknown0x0[0x4];		// 0x00
		struct _PERKROOT* pRoot;	// 0x04
		DWORD Count;
	} PERKDIR, *PPERKDIR;

#pragma endregion

#pragma region PlayfieldAnarchy

	typedef struct _PLAYFIELDMAPNODE
	{
		struct _PLAYFIELDMAPNODE* Lower;		// 0x00
		struct _PLAYFIELDMAPNODE* Back;			// 0x04
		struct _PLAYFIELDMAPNODE* Higher;		// 0x08
		DWORD PlayfieldInstanceId;				// 0x0C
		struct _PLAYFIELDANARCHY* pPlayfield;	// 0x10
	} PLAYFIELDMAPNODE, *PPLAYFIELDMAPNODE;


	typedef struct _PLAYFIELDMAPROOT
	{
		struct _PLAYFIELDMAPNODE* Begin;
		struct _PLAYFIELDMAPNODE* Node;
		struct _PLAYFIELDMAPNODE* End;
	} PLAYFIELDMAPROOT, *PPLAYFIELDMAPROOT;

	typedef struct _PLAYFIELDDIR
	{
		BYTE Unknown0x00[0x4];				// 0x00
		struct _PLAYFIELDMAPROOT* Root;		// 0x04
		DWORD Count;						// 0x08
	} PLAYFIELDDIR, *PPLAYFIELDDIR;

	// Size - 0x110
	// From Gamecode.dll
	typedef struct _PLAYFIELDANARCHY
	{
		PVOID vTable;							// 0x00
		BYTE Unknown0x04[0x4];					// 0x04
		identity_t ModelID;				// 0x08
		BYTE Unknown0x10[0x8];					// 0x10
		identity_t InstanceID;			// 0x18
		BYTE Unknown0x20[0xC];					// 0x20
		PVOID pRoomLinks;						// 0x2C
		std::vector<struct _N3DYNEL*, std::allocator<struct _N3DYNEL*>> DynelChildren;	// 0x30
		BYTE Unknown0x3C[0x10];					// 0x3C
		DWORD LastEntranceDoorNumber;			// 0x4C
		DWORD ZoneSize;							// 0x50						
		struct _N3TILEMAP* pn3Tilemap;			// 0x54
		struct _GRIDSPACE* pSpace_i;			// 0x58
		PVOID pPathfinder_i;					// 0x5C
		struct n3_tile_map_surface* pSurface_i;	// 0x60
		BYTE Unknown0x64[0x8];					// 0x64
		PVOID pShadowList;						// 0x6C
		BYTE Unknown0x70[0x14];					// 0x70
		PVOID pOrgZoneIDList;					// 0x84
		DWORD NumOrgZones;						// 0x88
		struct _RDBPLAYFIELD* pRDBPlayfield;	// 0x8C
		BYTE Unknown0x90[0x8];					// 0x90
		DWORD NumberOfWaters;					// 0x98
		PVOID pn3WaterData;						// 0x9C
		PVOID pEnviromentData;					// 0xA0
		BYTE Unknown0xA4[0x4];					// 0xA4				
		struct _N3CELLMONITOR* pn3CellMonitor;	// 0xA8
		LONG PFWorldXPos;						// 0xAC
		LONG PFWorldZPos;						// 0xB0
		PVOID pPlayfieldAreaInfo;				// 0xB4
		PVOID pPlayfieldDistrictInfo;			// 0xB8
		PVOID pFightModeHandler;				// 0xBC
		BYTE Unknown0xC0[0x4];					// 0xC0
		PVOID pGameData__LandControlMap_t;		// 0xC4
		BYTE Unknown0xC8[0x4];					// 0xC8
		PVOID pIDRangeRemapper;					// 0xCC
		BYTE Unknown0xD0[0x8];					// 0xD0
		DWORD GameRunMode;						// 0xD8
		BYTE Unknown0xDC[0x34];					// 0xDC
	} PLAYFIELDANARCHY, *PPLAYFIELDANARCHY;

#pragma endregion

#pragma region ppj::Client_c::GroupAction_t

	// Size = 0x48
	// From GUI.dll
	typedef struct _PPJCLIENTGROUPACTION
	{
		PVOID pvTable;		// 0x00
		DWORD Unknown0x4;	// 0x04
		DWORD Unknown0x8;	// 0x08
		string String1;		// 0x0C
		BYTE Unknown0x24[0x4];
		DWORD Unknown0x28;	// 0x28
		DWORD Unknown0x2C;	// 0x2C
		DWORD Unknown0x30;	// 0x30
		DWORD Unknown0x34;	// 0x34
		DWORD Unknown0x38;	// 0x38
		DWORD Unknown0x3C;	// 0x3C
		DWORD Unknown0x40;	// 0x40
		DWORD Unknown0x44;	// 0x44
	} PPJCLIENTGROUPACTION, *PPPJCLIENTGROUPACTION;

#pragma endregion

#pragma region ppj::Client_c::GroupMessage_t

	// Size = 0x78
	// From GUI.dll
	typedef struct _PPJCLIENTGROUPMESSAGE
	{
		PVOID pvTable;		// 0x00
		DWORD Unknown0x04;	// 0x04
		DWORD SenderId;	// 0x08
		string Sender;		// 0x0C
		BYTE Unknown0x24[0x4];
		DWORD Unknown0x28;	// 0x28
		DWORD Unknown0x2C;	// 0x2C
		string ChannelName;		// 0x30
		BYTE Unknown0x48[0x4];
		string Message;		// 0x4C
		BYTE Unknown0x64[0x4];
		DWORD Unknown0x68;	// 0x68
		DWORD Unknown0x6C;	// 0x6C
		DWORD Unknown0x70;	// 0x70
		DWORD Unknown0x74;	// 0x74
	} PPJCLIENTGROUPMESSAGE, *PPPJCLIENTGROUPMESSAGE;

#pragma endregion

#pragma region ppj::Client_c::PrivateGroupAction_t

	// Size = 0x4C
	// From GUI.dll
	typedef struct _PPJCLIENTPRIVATEGROUPACTION
	{
		PVOID pvTable;		// 0x00
		DWORD Unknown0x04;	// 0x04
		DWORD Unknown0x08;	// 0x08
		string String1;		// 0x0C
		BYTE Unknown0x24[0x4];
		DWORD Unknown0x28;	// 0x28
		DWORD Unknown0x2C;	// 0x2C
		string String2;		// 0x30;
		BYTE Unknown0x48[0x4];
	} PPJCLIENTPRIVATEGROUPACTION, *PPPJCLIENTPRIVATEGROUPACTION;

#pragma endregion

#pragma region ppj::Client_c::PrivateMessage_t

	// Size = 0x54
	// From GUI.dll
	typedef struct _PPJCLIENTPRIVATEMESSAGE
	{
		PVOID pvTable;		// 0x00
		DWORD Unknown0x4;	// 0x04
		DWORD SenderId;		// 0x08
		string Sender;		// 0x0C
		BYTE Unknown0x24[0x4];
		string Message;		// 0x28
		BYTE Unknown0x40[0x4];
		DWORD Unknown0x44;	// 0x44
		DWORD Unknown0x48;	// 0x48
		DWORD Unknown0x4C;	// 0x4C
		DWORD Unknown0x50;	// 0x50
	} PPJCLIENTPRIVATEMESSAGE, *PPPJCLIENTPRIVATEMESSAGE;


#pragma endregion

#pragma region ppj::Client_c::SystemMessage_t

	// Size = 0x48
	// From GUI.dll
	typedef struct _PPJCLIENTSYSTEMMESSAGE
	{
		PVOID pvTable;		// 0x00
		DWORD Unknown0x4;	// 0x04
		DWORD Unknown0x8;	// 0x08
		string String1;		// 0x0C
		BYTE Unknown0x24[0x4];
		DWORD Unknown0x28;	// 0x28
		string String2;		// 0x2C
		BYTE Unknown0x44[0x4];
	} PPJCLIENTSYSTEMMESSAGE, *PPPJCLIENTSYSTEMMESSAGE;

#pragma endregion

#pragma region ppj::Client_c::VicinityMessage_t

	// Size = 0x54
	// From GUI.dll
	typedef struct _PPJCLIENTVICINITYMESSAGE
	{
		PVOID pvTable;		// 0x00
		DWORD Unknown0x4;	// 0x04
		DWORD SenderId;		// 0x08
		std::string Sender;		// 0x0C
		BYTE Unknown0x24[0x4];
		std::string Message;		// 0x28
		BYTE Unknown0x40[0x4];
		DWORD Unknown0x44;	// 0x44
		DWORD Unknown0x48;	// 0x48
		DWORD Unknown0x4C;	// 0x4C
		DWORD Unknown0x50;	// 0x50
	} PPJCILENTVICINITYMESSAGE, *PPPJCLIENTVICINITYMESSAGE;

#pragma endregion

#pragma region RDBPlayfield

	// Size = 0x6C
	// From Gamecode.dll
	typedef struct _RDBPLAYFIELD
	{
		PVOID vTable;					// 0x00
		BYTE Unknown0x04[0x4];			// 0x04
		identity_t ResourceId;	// 0x08
		BYTE Unknown0x10[0x10];			// 0x10
		char Name[0x20];				// 0x20
		BYTE Unknown0x40[0x18];			// 0x40
		DWORD PlayfieldTypeBits;		// 0x58
		BYTE Unknown0x5C[0x10];			// 0x5C
	} RDBPLAYFIELD, *PRDBPLAYFIELD;

#pragma endregion

#pragma region PlayfieldMap



#pragma endregion

#pragma region RDBTilemap

	// Size = 0x8270
	// From DisplaySystem.dll
	typedef struct _RDBTILEMAP
	{
		PVOID pvTable;							    // 0x00
		struct _EVENTCASTER* pEventCaster;		    // 0x04
		identity_t Identity;					// 0x08
		BYTE Unknown_0x10[0x8];						// 0x10
		DWORD IsDungeon;							// 0x0018
		float Unknown0x1C;							// 0x001C
		BYTE Unknown0x20[0x8];						// 0x0020
		BYTE Unknown0x28[0x200];					// 0x0028
		BYTE Unknown0x228[0x8];						// 0x0228
		UINT16 NumMainTiles;						// 0x0230
		BYTE Unknown0x232[2];						// 0x0232
		const UINT16* pMainTileIDs;					// 0x0234
		BYTE Unknown0x238[0x4];						// 0x0238
		BYTE Unknown0x23C[0x8000];					// 0x023C
		BYTE Unknown0x823C[0x14];					// 0x823C
		WORD Unknown0x8250;							// 0x8259
		BYTE Unknown0x8252[2];						// 0x8252		
		BYTE Unknown0x8254[0x4];					// 0x8254
		PVOID pAnarchyGroundDataDB_t;				// 0x8258
		DWORD Width;								// 0x825C
		DWORD Height;								// 0x8260
		float MapSizeMultiplier;					// 0x8264
		BYTE Unknown0x8268[0x8];					// 0x8268
	} RDBTILEMAP, *PRDBTILEMAP;

#pragma endregion

#pragma region Reference Counted

	// Size = 0x08
	// From DatabaseController.dll
	typedef struct _REFERENCECOUNTED
	{
		PVOID pvTable;							// 0x00
		struct _EVENTCASTER* pEventCaster;		// 0x04
	} REFERENCECOUNTED, *PREFERENCECOUNTED;

#pragma endregion

#pragma region ResourceDatabase

	// Size = 0x10
	// From DatabaseController.dll
	typedef struct _RESOURCEDATABASE
	{
		struct _DATABASECONTROLLER DatabaseController;		// 0x00
		PVOID pACE_TOKEN;									// 0x08
		PVOID pRdbLinkRDb_c;								// 0x0C
	} RESOURCEDATABASE, *PRESOURCEDATABASE;

#pragma endregion 

#pragma region SimpleChar

	// Size = 0x2D8
	// From Gamecode.dll
	typedef struct _SIMPLECHAR
	{
		PVOID pvTable;										// 0x00
		struct _N3DYNELEVENTSOURCE N3DynelEventSource;		// 0x04
		struct _DBOBJECT DbObject;							// 0x0C
		std::vector<COLLINFO>* pCollInfoVector;				// 0x24
		struct _N3FSM n3Fsm;								// 0x28
		BYTE Unknown0x44[0x4];								// 0x44
		BYTE IsNotSnoozing;									// 0x48
		BYTE Unknown0x49[0x7];								// 0x49
		struct char_vehicle* pVehicle;						// 0x50
		BYTE IsGroundCollisionEnabled;						// 0x54
		BYTE IsCollEnabled;									// 0x55
		BYTE Unknown0x56[0x2];								// 0x56
		BYTE IsStationary;									// 0x58
		BYTE IsRepulsive;									// 0x59
		BYTE Unknown0x5A[0x2];								// 0x5A
		struct _N3DYNAMESHCOLLSPHERE* pCollPrim;			// 0x5C
		DWORD PlayfieldInstanceId;							// 0x60
		struct _N3TILEMAP* pn3Tilemap;						// 0x64
		BYTE IsOnBorder;									// 0x68
		BYTE Unknown0x69[0x2];								// 0x69
		BYTE IsInTree;										// 0x6B	
		PVOID pn3InfoItemRemote_t;							// 0x6C
		std::vector<struct _N3DYNEL*>* pChildDynelVector;   // 0x70
		identity_t ParentIdentity;					// 0x74
		BYTE Unknown0x7C[0x4];								// 0x7C
		BYTE IsDying;										// 0x80
		BYTE field_81[0xB];									// 0x81
		DWORD RDBDynelStatus;								// 0x8C
		DWORD LastAllowedZoneInst;							// 0x90
		struct vector3 LastAllowedGlobalPositionInZone;	// 0x94
		struct vector3 ReconcilePosition;					// 0xA0
		float BodyScale;									// 0xAC
		PVOID pTextureDataList;								// 0xB0
		BYTE Unknown0xB4[0xC];								// 0xB4
		PVOID pVisualMesh_t;								// 0xC0
		PVOID pVisualCATMesh_t;								// 0xC4
		BYTE Unknown0xC8[0x4];								// 0xC8
		BYTE IsClientChar;									// 0xCC
		BYTE IsVisible;										// 0xCD
		BYTE UseCharDistCap;								// 0xCE
		BYTE Unknown0xCF;									// 0xCF
		struct vector3 BoundingSpherePos;					// 0xD0
		BYTE Unknown0xDC[0x4];								// 0xDC
		PVOID pvTable_TriggerHolder;						// 0xE0
		BYTE Unknown0xE4[0x8];								// 0xE4
		PVOID pvTable_Beholder;								// 0xEC
		BYTE Unknown0xF0[0x30];								// 0xF0
		PVOID pvTable_StatHolder_t;							// 0x120
		std::vector<LONG>* pStatVector;						// 0x124
		identity_t Identity;							// 0x128
		BYTE Unknown0x130[0x28];							// 0x130
		std::string Name;									// 0x148
		BYTE Unknown0x170[0x4C];							// 0x170
		struct _INVENTORYHOLDER* pContainerInventory;		// 0x1BC
		struct _STATHOLDER* pMapHolder;						// 0x1C0
		struct _SPELLTEMPLATEDATA* pSpellTemplateData;		// 0x1C4
		BYTE Unknown0x1C8[0xC];								// 0x1C8
		struct _SPECIALACTIONHOLDER* pSpecialActionHolder;	// 0x1D4
		struct _WEAPONHOLDER* pWeaponHolder;				// 0x1D8
		struct _NPCHOLDER* pNpcHolder;						// 0x1DC
		PVOID pAnimHolder;									// 0x1E0
		struct _TEAMRAIDHOLDER* pTeamRaidInfo;				// 0x1E4
		struct _SIMPLECHAR** ppClientControlChar;			// 0x1E8
		BYTE Unknown0x1EC[0xC];								// 0x1EC
		struct _PERKHOLDER* pPerkHolder;					// 0x1F8
		BYTE Unknown0x1FC[0xC];								// 0x1FC
		DWORD State;										// 0x208
		DWORD CharacterBodyShape;							// 0x20C
		BYTE Unknown0x210[0x10];							// 0x210
		BYTE IsNPC;											// 0x220
		BYTE Unknown0x221[0xB7];							// 0x221
	} SIMPLECHAR, *PSIMPLECHAR;


#pragma endregion	

#pragma region GameData::SpawnPoint

	// From GameData.dll
	// Size = 0x14
	typedef struct _SPAWNPOINT
	{
		PVOID pvTable;		        // 0x00
		struct vector3 CenterPos;	// 0x04
		float Radius;				// 0x10
	} SPAWNPOINT, *PSPAWNPOINT;


#pragma endregion

#pragma region SpecialAction

	// Size = 0x20
	typedef struct _SPECIALACTION
	{
		identity_t Identity;			// 0x00
		identity_t WeaponIdentity;	// 0x08
		DWORD LockedSkillId1;				// 0x10
		DWORD LockedSkillId2;				// 0x14
		BYTE Unknown0x18[0x4];				// 0x18
		BYTE IsLocked;						// 0x1C
		BYTE Unknown0x1D[0x3];				// 0x1D
	} SPECIALACTION, *PSPECIALACTION;

#pragma endregion

#pragma region SpecialActionHolder

	// Size = 0xFC
	// From Gamecode.dll
	typedef struct _SPECIALACTIONHOLDER
	{
		struct _SIMPLECHAR* pClientControlChar;			// 0x00
		BYTE Unknown0x04[0x58];							// 0x04
		identity_t SpecialActionTarget;			// 0x5C
		BYTE Unknown0x64[0x10];							// 0x64
		PVOID pDistrictData;							// 0x74
		PVOID pAreaData;								// 0x78
		BYTE Unknown0x7C[0x8];							// 0x7C
		std::list<SPECIALACTION>* pSpecialActionsList;	// 0x84
		struct _LOCKIDDIR* pLockIdDir;					// 0x88
		BYTE Unknown0x8C[0x70];							// 0x8C
	} SPECIALACTIONHOLDER, *PSPECIALACTIONHOLDER;

#pragma endregion

#pragma region Spell

	// Size = 0x4
	typedef struct _SPELL
	{
		DWORD Id;
	} SPELL, *PSPELL;

#pragma endregion

#pragma region SpellTemplateData	

	typedef struct _CASTINGDATA
	{
		PNANOITEM pNanoItem;		// 0x00
		DWORD NanoId;				// 0x04
		LONG Unknown0x08;			// 0x08
		DWORD CastStatus;			// 0x0C
		BYTE Unknown0x10[0x14];		// 0x10
		identity_t  Target;	// 0x24
		BYTE Unknown0x2C[0x4];		// 0x2C
		identity_t Caster;	// 0x30
	} CASTINGDATA, *PCASTINGDATA;

	// Size = 0x50
	// From Gamecode.dll
	typedef struct _SPELLTEMPLATEDATA
	{
		struct _SIMPLECHAR* pClientControlDynel;		// 0x00
		DWORD InCooldown;								// 0x04
		BYTE Unknown0x08[0x4];							// 0x08
		DWORD CastingId;								// 0x0C
		BYTE Unknown0x10[0x4];							// 0x10
		std::list<DWORD> SpellList;						// 0x14
		BYTE Unknown0x1C[0x4];							// 0x1C
		std::list<NANOTEMPLATE> NanoTemplateList;		// 0x20
		BYTE Unknown0x28[0x4];							// 0x28
		std::list<CASTINGDATA*>* pSpellcastingInfo;		// 0x2C
		std::vector<p_identity_t> ActiveNanos;				// 0x30
		BYTE Unknown0x3C[0x14];							// 0x3C
	} SPELLTEMPLATEDATA, *PSPELLTEMPLATEDATA;

#pragma endregion
		
#pragma region Static Items

	typedef struct _STATICITEM
	{
		identity_t StaticIdentity;
		struct dummy_item_base* pDummyItem;
		DWORD Unknown;
	} STATICITEM, *PSTATICITEM;

#pragma endregion

#pragma region StatMap

	// Size = 0x14
	typedef struct _STATNODE
	{
		struct _STATNODE* pLower;			// 0x00
		struct _STATNODE* pNode;			// 0x04
		struct _STATNODE* pHigher;			// 0x08
		DWORD Stat;							// 0x0C
		LONG Modifier;						// 0x10
	} STATNODE, *PSTATNODE;

	// Size = 0x0C
	typedef struct _STATROOT
	{
		struct _STATNODE* pBegin;			// 0x00
		struct _STATNODE* pNode;			// 0x04
		struct _STATNODE* pEnd;				// 0x08
	} STATROOT, *PSTATROOT;

	typedef struct _STATDIR
	{
		BYTE Unknown0x00[0x4];				// 0x00
		struct _STATROOT* pRoot;			// 0x04
		DWORD Count;						// 0x08
	} STATDIR, *PSTATDIR;

#pragma endregion 

#pragma region StatNameMap

	// Size = 0x14
	typedef struct _STATNAMENODE
	{
		struct _STATNAMENODE* pLower;	// 0x00
		struct _STATNAMENODE* pBack;		// 0x04
		struct _STATNAMENODE* pHigher;	// 0x08
		DWORD Stat;						// 0x0C
		PCSTR pName;						// 0x10
	} STATNAMENODE, *PSTATNAMENODE;

	// Size = 0xC
	typedef struct _STATNAMEROOT
	{
		struct _STATNAMENODE* pBegin;	// 0x00
		struct _STATNAMENODE* pNode;		// 0x04
		struct _STATNAMENODE* pEnd;		// 0x08
	} STATNAMEROOT, *PSTATNAMEROOT;

	// Size = 0xC
	typedef struct _STATNAMEDIR
	{
		BYTE Unknown0x00[0x4];			// 0x00
		struct _STATNAMEROOT* pRoot;		// 0x04
		DWORD Count;					// 0x08
	} STATNAMEDIR, *PSTATNAMEDIR;


#pragma endregion

#pragma region TeamEntry

	typedef struct _TEAMENTRY
	{
		string Name;
		BYTE Unknown0x18[0x4];
		identity_t Identity;
	} TEAMENTRY, *PTEAMENTRY;

#pragma endregion

#pragma region TeamRaidHolder

	typedef struct _TEAMRAIDINFO
	{
		const char Name[0x14];		// 0x00
		BYTE Unknown0x14[0x8];		// 0x14
		identity_t Identity;	// 0x1C
	} TEAMRAIDINFO, *PTEAMRAIDINFO;

	typedef struct _TEAMRAIDHOLDER
	{
		identity_t TeamIdentity;				// 0x00
		struct _SIMPLECHAR* pClientControlDynel;	// 0x08
		BYTE Unknown0xC[0x8];						// 0x0C
		identity_t TeamLeaderIdentity;		// 0x14
		BYTE Unknown0x1C[0x4];						// 0x1C
		std::vector<PTEAMRAIDINFO*>* pTeamList[6];	// 0x20
		//std::vector<PTEAMRAIDINFO>* pTeamList_2;	// 0x24
		//std::vector<PTEAMRAIDINFO>* pTeamList_3;	// 0x28
		//std::vector<PTEAMRAIDINFO>* pTeamList_4;	// 0x2C
		//std::vector<PTEAMRAIDINFO>* pTeamList_5;	// 0x30
		//std::vector<PTEAMRAIDINFO>* pTeamList_6;	// 0x34
		LONG RaidTeamIndex;							// 0x38
	} TEAMRAIDHOLDER, *PTEAMRAIDHOLDER;

#pragma endregion

#pragma region WeaponHolder

	typedef struct _WEAPONITEMNODE
	{
		struct _WEAPONITEMNODE* pLower;			// 0x00
		struct _WEAPONITEMNODE* pNode;			// 0x04
		struct _WEAPONITEMNODE* pHigher;			// 0x08
		DWORD ActionID;							// 0x0C
		struct _WEAPONITEM* pWeaponItem;		// 0x10
	} WEAPONITEMNODE, *PWEAPONITEMNODE;

	// Size = 0x0C
	typedef struct _WEAPONITEMROOT
	{
		struct _WEAPONITEMNODE* pBegin;			// 0x00
		struct _WEAPONITEMNODE* pNode;			// 0x04
		struct _WEAPONITEMNODE* pEnd;			// 0x08
	} WEAPONITEMROOT, *PWEAPONITEMROOT;

	typedef struct _WEAPONITEMDIR
	{
		BYTE Unknown0x00[0x4];					// 0x00
		struct _WEAPONITEMROOT* pRoot;			// 0x04
		DWORD Count;							// 0x08
	} WEAPONITEMDIR, *PWEAPONITEMDIR;

	// Size = 0xA4
	// From Gamecode.dll
	typedef struct _WEAPONHOLDER
	{
		PVOID pvTable;							// 0x00
		BYTE Unknown0x04[0x4];					// 0x04
		PSIMPLECHAR pClientControlChar;			// 0x08
		struct _WEAPONITEMDIR WeaponItemDir;	// 0x0C
		BYTE Unknown0x18[0x2C];					// 0x18
		DWORD IsAttacking;						// 0x44
		BYTE Unknown0x48[0x4];					// 0x48
		identity_t WeaponTargetIdentity;	// 0x4C
		BYTE Unknown0x54[0x50];					// 0x54
	} WEAPONHOLDER, *PWEAPONHOLDER;

#pragma endregion		

#pragma region WeaponItem

	// Size = 0x204
	// From Gamecode.dll
	typedef struct _WEAPONITEM
	{
		PVOID pvTable;										// 0x0000
		PVOID pvTable_n3DynelEventSource;					// 0x0004
		BYTE Unknown_0x08[0x4];								// 0x0008
		PVOID pvTable_DbObject;								// 0x000C
		struct _EVENTCASTER* pEventCaster;					// 0x0010
		identity_t InstanceIdentity;					// 0x0014
		BYTE Unknown_0x1C[0x8];								// 0x001C
		std::vector<COLLINFO>* pCollInfoVector;				// 0x0024
		PVOID pvTable_n3Fsm;								// 0x0028
		BYTE Unknown0x2C[0x10];								// 0x002C
		BYTE IsDead;										// 0x003C
		BYTE Unknown0x3D[0x3];								// 0x003D
		struct _N3SFBASE *pFirstStateFunction;				// 0x0040
		BYTE Unknown0x44[0x4];								// 0x0044
		BYTE IsNotSnoozing;									// 0x0048
		BYTE Unknown0x49[0x7];								// 0x0049
		struct dummy_vehicle *pVehicle;						// 0x0050
		BYTE IsGroundCollisionEnabled;						// 0x0054
		BYTE IsCollEnabled;									// 0x0055
		BYTE Unknown0x56[0x2];								// 0x0056
		BYTE IsStationary;									// 0x0058
		BYTE IsRepulsive;									// 0x0059
		BYTE Unknown0x5A[0x2];								// 0x005A
		struct _N3DYNAMESHCOLLSPHERE* pCollPrim;			// 0x005C
		DWORD PlayfieldInstanceId;							// 0x0060
		struct _N3TILEMAP* pn3Tilemap;						// 0x0064
		BYTE IsOnBorder;									// 0x0068
		BYTE Unknown0x69[0x2];								// 0x0069
		BYTE IsInTree;										// 0x006B	
		PVOID pn3InfoItemRemote;							// 0x006C
		std::vector<struct _N3DYNEL*>* pChildDynelVector;		// 0x0070
		identity_t ParentIdentity;					// 0x0074
		BYTE Unknown0x7C[0x4];								// 0x007C
		BYTE IsDying;										// 0x0080
		BYTE field_81[0xB];									// 0x0081
		DWORD RDBDynelStatus;								// 0x008C
		DWORD LastAllowedZoneInst;							// 0x0090
		struct vector3 LastAllowedGlobalPositionInZone;	// 0x0094
		struct vector3 ReconcilePosition;					// 0x00A0
		float BodyScale;									// 0x00AC
		PVOID pTextureDataList;								// 0x00B0
		BYTE Unknown0xB4[0xC];								// 0x00B4
		PVOID pVisualMesh;								    // 0x00C0
		PVOID pVisualCATMesh;								// 0x00C4
		BYTE Unknown0xC8[0x4];								// 0x00C8
		BYTE IsClientChar;									// 0x00CC
		BYTE IsVisible;										// 0x00CD
		BYTE UseCharDistCap;								// 0x00CE
		BYTE Unknown0xCF;									// 0x00CF
		struct vector3 BoundingSpherePos;					// 0x00D0
		BYTE Unknown0xDC[0x4];								// 0x00DC
		identity_t StaticIdentity;					// 0x00E0
		BYTE Unknown0xE8[0x70];								// 0x00E8
		PVOID pvTable_WeaponItem;							// 0x0158
		BYTE Unknown0x15C[0x30];							// 0x015C
		PVOID pvTable_StatHolder;							// 0x018C
		std::vector<LONG>* pStatVector;						// 0x0190
		BYTE Unknown0x194[0x34];							// 0x0194
		identity_t UnknownIdentity2;					// 0x01C8
		BYTE Unknown0x1D0[0x24];							// 0x01D0
		char const * Name;									// 0x01F4
		char const * Description;							// 0x01F8
		PVOID pvTable_TriggerHolder;						// 0x01FC
		BYTE Unknown0x200[0x4];								// 0x0200
	} WEAPONITEM, *PWEAPONITEM;

#pragma endregion

#pragma endregion

}
using namespace AOData;
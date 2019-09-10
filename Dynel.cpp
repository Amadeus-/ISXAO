#include "isxao_main.h"

namespace isxao_classes
{

	float dynel::get_distance_to_client()
	{
		vector3_t client_position;
		P_ENGINE_CLIENT_ANARCHY->n3_msg_get_global_character_position(client_position);
		return this->get_distance_3d_to(client_position);
	}

	float dynel::get_distance_to(vector3_t& position)
	{
		auto dynel_position = this->get_position();
		return vector3_t::distance_xz(dynel_position, position);
	}

	// ReSharper disable once CppInconsistentNaming
	float dynel::get_distance_3d_to(vector3_t& position)
	{
		auto dynel_position = this->get_position();
		return vector3_t::distance(dynel_position, position);
	}

	// ReSharper disable once CppInconsistentNaming
	float dynel::get_distance_3d_to_squared(vector3_t& position)
	{
		auto dynel_position = this->get_position();
		return vector3_t::distance_squared(dynel_position, position);
	}

	float dynel::get_distance_to_squared(vector3_t& position)
	{
		auto dynel_position = this->get_position();
		return vector3_t::distance_xz_squared(dynel_position, position);
	}

	float dynel::get_distance_x_to(vector3_t& position)
	{
		auto dynel_position = this->get_position();
		return vector3_t::distance_x(dynel_position, position);
	}

	float dynel::get_distance_y_to(vector3_t& position)
	{
		auto dynel_position = this->get_position();
		return vector3_t::distance_y(dynel_position, position);
	}

	float dynel::get_distance_z_to(vector3_t& position)
	{
		auto dynel_position = this->get_position();
		return vector3_t::distance_z(dynel_position, position);
	}

	float dynel::get_heading()
	{
		return get_rotation().get_heading();
	}

	float dynel::get_heading_to(vector3_t & position)
	{
		auto dynel_position = this->get_position();
		auto direction_vector = vector3_t::subtract(dynel_position, position);
		direction_vector.normalize();
		return direction_vector.get_yaw();
	}

	float dynel::get_heading_to_loc(vector3_t &position, vector3_t &position_offset)
	{
		auto dynel_position = this->get_position();
		auto new_position = vector3_t::add(dynel_position, position_offset);
		auto direction_vector = vector3_t::subtract(position, new_position);
		direction_vector.normalize();
		return direction_vector.get_yaw();
	}

	identity_t dynel::get_identity()
	{
		return this->get_dynel_data()->identity;
	}	

	void dynel::interact()
	{
		P_ENGINE_CLIENT_ANARCHY->n3_msg_default_action_on_dynel(this->get_identity());
	}

	bool dynel::is_in_line_of_sight()
	{
		vector3_t height_offset;
		height_offset.x = 0.0f;
		height_offset.y = 1.6f;
		height_offset.z = 0.0f;
		vector3_t client_position;
		P_ENGINE_CLIENT_ANARCHY->n3_msg_get_global_character_position(client_position);
		const auto offset_client_position = vector3_t::add(client_position, height_offset);
		auto dynel_position = this->get_position();
		const auto offset_dynel_position = vector3_t::add(dynel_position, height_offset);
		return P_PLAYFIELD_DIR->GetPlayfield()->LineOfSight(offset_client_position, offset_dynel_position, get_dynel_data()->p_vehicle->zone_instance_id, false);
	}

	bool dynel::is_in_line_of_sight(vector3_t &position)
	{
		vector3_t height_offset;
		height_offset.x = 0.0f;
		height_offset.y = 1.6f;
		height_offset.z = 0.0f;
		auto dynel_position = this->get_position();
		const auto offset_dynel_position = vector3_t::add(dynel_position, height_offset);
		return P_PLAYFIELD_DIR->GetPlayfield()->LineOfSight(position, offset_dynel_position, get_dynel_data()->p_vehicle->zone_instance_id, false);
	}
	
	PCSTR dynel::get_name()
	{
		const identity_t container_identity(0.0, 0.0);
		return P_ENGINE_CLIENT_ANARCHY->n3_msg_get_name(this->get_identity(), container_identity);
	}

	vector3_t dynel::get_position()
	{
		if (get_dynel_data()->p_vehicle->p_parent_vehicle == nullptr)
			return get_dynel_data()->p_vehicle->global_pos;
		return get_dynel_data()->p_vehicle->parent_global_pos;
	}

	quaternion_t dynel::get_rotation()
	{
		if (get_dynel_data()->p_vehicle->p_parent_vehicle == nullptr)
			return get_dynel_data()->p_vehicle->body_rot;
		return get_dynel_data()->p_vehicle->parent_body_rot;
	}

	LONG dynel::get_skill(DWORD stat)
	{
		const auto dynel_identity = this->get_identity();
		const identity_t container_identity(0.0, 0.0);
		if (!IsClientId(dynel_identity.id))
		{
			return P_ENGINE_CLIENT_ANARCHY->n3_msg_get_skill(dynel_identity, stat, 2, container_identity);
		}			
		return P_ENGINE_CLIENT_ANARCHY->n3_msg_get_skill(stat, 2);
	}

	bool dynel::is_container()
	{
		return this->get_identity().type == 51017;
	}

	bool dynel::is_corpse()
	{
		return this->get_identity().type == 51050;
	}

	bool dynel::is_door()
	{
		return this->get_identity().type == 51016;
	}

	bool dynel::is_actor()
	{
		const auto dynel_identity = this->get_identity();
		if (dynel_identity.type == 50000)
		{
			const auto is_npc = P_ENGINE_CLIENT_ANARCHY->N3Msg_IsNpc(dynel_identity);
			return is_npc;
		}
		return false;
	}

	bool dynel::is_info_request_completed()
	{
		const auto dynel_identity = this->get_identity();
		if(!IsClientId(dynel_identity.id))
		{
			const identity_t container_identity(0.0, 0.0);
			const auto profession = P_ENGINE_CLIENT_ANARCHY->n3_msg_get_skill(dynel_identity, ST_PROFESSION, 2, container_identity);
			return profession != -1;
		}
		return true;
	}

	bool dynel::is_pet()
	{
		const auto dynel_identity = this->get_identity();
		if (dynel_identity.type == 50000)
		{
			const auto is_npc = P_ENGINE_CLIENT_ANARCHY->N3Msg_IsNpc(dynel_identity);
			if (is_npc)
			{
				if (this->get_skill(ST_PETMASTER) != 1234567890)
					return true;
			}
		}
		return false;
	}

	bool dynel::is_player()
	{
		const auto dynel_identity = this->get_identity();
		if (dynel_identity.type == 50000)
		{
			const auto is_npc = P_ENGINE_CLIENT_ANARCHY->N3Msg_IsNpc(dynel_identity);
			return is_npc == 0;
		}
		return false;
	}

	bool dynel::is_character()
	{
		const auto dynel_identity = this->get_identity();
		if (dynel_identity.type == 50000)
		{
			return dynel_identity.id == g_character_id;
		}
		return false;
	}

	bool dynel::is_team_member()
	{
		return this->is_player() && this->to_player()->is_in_my_team();
	}

	bool dynel::is_vending_machine()
	{
		return get_identity().type == 51035;
	}

	bool dynel::is_weapon_instance()
	{
		return get_identity().type == 51018;
	}

	PVOID dynel::get_data()
	{
		return &n3_dynel_;
	}

	p_n3_dynel_t dynel::get_dynel_data()
	{
		return p_n3_dynel_t(get_data());
	}

#ifdef N3_DYNEL_T__SEND_IIR_TO_OBSERVERS_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void dynel::send_iir_to_observers(info_item_remote*), n3_dynel_t__send_iir_to_observers)
#else
	static_assert(false, "dynel::send_iir_to_observers(info_item_remote*) requires a native function.");
#endif

	actor* dynel::to_actor()
	{
		return static_cast<actor*>(get_data());
	}

	character* dynel::to_character()
	{
		return static_cast<character*>(get_data());
	}

	Pet* dynel::to_pet()
	{
		return static_cast<Pet*>(get_data());
	}

	Player* dynel::to_player()
	{
		return static_cast<Player*>(get_data());
	}

	TeamMember* dynel::to_team_member()
	{
		return static_cast<TeamMember*>(get_data());
	}

#ifdef N3_DYNEL_T__UPDATE_LOCALITY_LISTENERS_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(void dynel::update_locality_listeners(), n3_dynel_t__update_locality_listeners)
#else
	static_assert(false, "dynel::update_locality_listeners() requires a native function.");
#endif
	
	bool dynel::p_dynel_compare(dynel *p_a, dynel *p_b)
	{
		return p_a->get_distance_to_client() < p_b->get_distance_to_client();
	}
	
}
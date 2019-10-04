#include "isxao_main.h"
#include "navigation.h"
#include "character.h"
#include "engine_client_anarchy.h"
#include "playfield_anarchy.h"
#include "surface_i.h"

namespace isxao
{
	void navigation::random_facing(const ao::vector3_t& current_position, ao::quaternion_t& new_facing)
	{
		if (ao::g_game_state != GAMESTATE_IN_GAME)
			return;
		ao::vector3_t intersection;
		ao::vector3_t normal;
		const ao::vector3_t down_offset(0.0f, -1000000.0f, 0.0f);
		const auto ground_check_position = ao::vector3_t::add(current_position, down_offset);
		if (P_PLAYFIELD_DIR->get_playfield()->get_surface()->get_line_intersection(
			current_position, ground_check_position, intersection, normal, false,
			P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_vehicle()))
		{
			
		}

	}

}

#pragma once
#include "game_object.h"

namespace ao
{
	class flow_control : game_object<flow_control_t>
	{
	public:
		void slot_autorun(bool);
		void slot_movement_back(bool);
		void slot_movement_forward(bool);
		void slot_movement_jump(bool);
		void slot_movement_left(bool);
		void slot_movement_right(bool);
		void slot_movement_strafe_left(bool);
		void slot_movement_strafe_right(bool);
		void slot_walk_toggle(bool);
	};
}

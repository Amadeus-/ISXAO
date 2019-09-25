#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class flow_control
{
public:
	ao::flow_control_t get_flow_control_data() const;
	void slot_autorun(bool);
	void slot_movement_back(bool);
	void slot_movement_forward(bool);
	void slot_movement_jump(bool);
	void slot_movement_left(bool);
	void slot_movement_right(bool);
	void slot_movement_strafe_left(bool);
	void slot_movement_strafe_right(bool);
	void slot_walk_toggle(bool);
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::flow_control_t flow_control_;
};

#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class action_lock
{
public:
	AOLIB_OBJECT identity_t get_action_identity() const;
	AOLIB_OBJECT action_lock_t get_action_lock_data() const;
	AOLIB_OBJECT DWORD get_lock_out_time_remaining() const;
	AOLIB_OBJECT DWORD get_total_lock_out_time() const;
	AOLIB_OBJECT static bool p_action_lock_compare(action_lock*, action_lock*);
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	action_lock_t action_lock_;
};

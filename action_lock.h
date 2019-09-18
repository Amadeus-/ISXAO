#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class action_lock
{
public:
	ao::identity_t get_action_identity() const;
	ao::action_lock_t get_action_lock_data() const;
	DWORD get_lock_out_time_remaining() const;
	DWORD get_total_lock_out_time() const;
	static bool p_action_lock_compare(action_lock*, action_lock*);
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::action_lock_t action_lock_;
};

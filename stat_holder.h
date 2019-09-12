#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class stat_holder
{
public:
	AOLIB_OBJECT DWORD get_skill_locks(vector<action_lock*>&) const;
	AOLIB_OBJECT action_lock* get_skill_lock(special_action_template*) const;
	AOLIB_OBJECT stat_holder_t get_stat_holder_data() const;
	AOLIB_OBJECT DWORD get_stat_map(map<DWORD, LONG>&) const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	stat_holder_t stat_holder_;
};

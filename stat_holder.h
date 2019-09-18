#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class stat_holder
{
public:
	DWORD get_skill_locks(std::vector<ao::action_lock*>&) const;
	ao::action_lock* get_skill_lock(ao::special_action_template*) const;
	ao::stat_holder_t get_stat_holder_data() const;
	DWORD get_stat_map(std::map<DWORD, LONG>&) const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::stat_holder_t stat_holder_;
};

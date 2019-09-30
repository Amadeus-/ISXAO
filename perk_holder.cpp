#include "isxao_main.h"
#include "perk_holder.h"

namespace ao
{

	DWORD perk_holder::get_perk_locks(std::vector<action_lock*> &v)
	{
		std::vector<action_lock_t>* p_perk_lock_vector = get_data()->p_perk_locks;
		for (auto it = p_perk_lock_vector->begin(); it != p_perk_lock_vector->end(); ++it)  // NOLINT(modernize-loop-convert)
			v.push_back(reinterpret_cast<action_lock*>(&(*it)));
		return v.size();
	}

	DWORD perk_holder::get_perk_map(std::map<identity_t, DWORD> &m)
	{
		return this->get_data()->p_perk_dir->copy_map(m);
	}

}
#include "isxao_main.h"

namespace isxao_classes
{

	perk_holder_t perk_holder::get_perk_holder_data() const
	{
		return perk_holder_;
	}

	DWORD perk_holder::get_perk_locks(std::vector<action_lock*> &v) const
	{
		std::vector<action_lock_t>* p_perk_lock_vector = get_perk_holder_data().p_perk_locks;
		for (auto it = p_perk_lock_vector->begin(); it != p_perk_lock_vector->end(); ++it)  // NOLINT(modernize-loop-convert)
			v.push_back(reinterpret_cast<action_lock*>(&(*it)));
		return v.size();
	}

	DWORD perk_holder::get_perk_map(std::map<identity_t, DWORD> &m) const
	{
		return this->get_perk_holder_data().p_perk_dir->copy_map(m);
	}

}
#include "isxao_main.h"

namespace isxao_classes
{

	perk_holder PerkHolder::GetPerkHolderData() const
	{
		return perk_holder_;
	}

	DWORD PerkHolder::GetPerkLocks(std::vector<ActionLock*> &v) const
	{
		std::vector<action_lock_t>* p_perk_lock_vector = GetPerkHolderData().p_perk_locks;
		for (auto it = p_perk_lock_vector->begin(); it != p_perk_lock_vector->end(); ++it)
			v.push_back(reinterpret_cast<ActionLock*>(&(*it)));
		return v.size();
	}

	DWORD PerkHolder::GetPerkMap(std::map<identity_t, DWORD> &m) const
	{
		isxao_utilities::GetPerkMap(m, GetPerkHolderData().p_perk_dir);
		return m.size();
	}

	ActionLock* PerkHolder::GetActionLock(SpecialActionTemplate* special_action)
	{
		return nullptr;
	}


}
#include "isxao_main.h"

namespace isxao_classes
{

	PERKHOLDER PerkHolder::GetPerkHolderData() const
	{
		return perk_holder_;
	}

	DWORD PerkHolder::GetPerkLocks(std::vector<ActionLock*> &v) const
	{
		std::vector<ACTIONLOCK>* p_perk_lock_vector = GetPerkHolderData().pPerkLocks;
		for (auto it = p_perk_lock_vector->begin(); it != p_perk_lock_vector->end(); ++it)
			v.push_back(reinterpret_cast<ActionLock*>(&(*it)));
		return v.size();
	}

	DWORD PerkHolder::GetPerkMap(std::map<IDENTITY, DWORD> &m) const
	{
		isxao_utilities::GetPerkMap(m, GetPerkHolderData().pPerkDir);
		return m.size();
	}

	ActionLock* PerkHolder::GetActionLock(SpecialAction* special_action)
	{
		return nullptr;
	}


}
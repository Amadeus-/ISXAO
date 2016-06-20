#include "isxao_main.h"

namespace isxao_classes
{

	DWORD StatHolder::GetSkillLocks(std::vector<ActionLock*> &v) const
	{
		std::vector<ACTIONLOCK>* p_skill_lock_vector = GetStatHolderData().pSkillLocks;
		for (auto it = p_skill_lock_vector->begin(); it != p_skill_lock_vector->end(); ++it)
			v.push_back(reinterpret_cast<ActionLock*>(&(*it)));
		std::sort(v.begin(), v.end(), ActionLock::pActionLockCompare);
		return v.size();
	}

	ActionLock* StatHolder::GetSkillLock(SpecialActionTemplate* special_action) const
	{
		std::vector<ActionLock*> v;
		GetSkillLocks(v);
		for (auto it = v.begin(); it != v.end(); ++it)
		{
			auto action_identity = (*it)->GetActionIdentity();
			auto id1 = special_action->GetLockedSkillId1();
			auto id2 = special_action->GetLockedSkillId2();
			if (action_identity.Type == id1 || action_identity.Type == id2 || action_identity.Id == id1 || action_identity.Id == id2)
				return *it;
		}
		return nullptr;
	}

	STATHOLDER StatHolder::GetStatHolderData() const
	{
		return stat_holder_;
	}

	DWORD StatHolder::GetStatMap(std::map<DWORD, LONG> &m) const
	{
		isxao_utilities::GetStatMap(m, GetStatHolderData().pStatMapDir);
		return m.size();
	}

}
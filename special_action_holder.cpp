#include "isxao_main.h"

namespace isxao_classes
{

	DWORD SpecialActionHolder::BuildLSSpecialActions(LSIndex* pIndex) const
	{
		std::vector<SpecialAction*> v;
		GetSpecialActions(v);
		for (auto it = v.begin(); it != v.end(); ++it)
			pIndex->AddItem(reinterpret_cast<LSOBJECTDATA&>((*it)));
		return pIndex->GetContainerUsed();
	}

	DWORD SpecialActionHolder::GetLockIdMap(std::map<DWORD, DWORD>& m) const
	{
		isxao_utilities::GetLockIdMap(m, GetSpecialActionHolderData().pLockIdDir);
		return m.size();
	}

	SPECIALACTIONHOLDER SpecialActionHolder::GetSpecialActionHolderData() const
	{
		return special_action_holder_;
	}

	DWORD SpecialActionHolder::GetSpecialActions(std::vector<SpecialAction> &v) const
	{
		std::list<SPECIALACTION>* p_special_actions_vector = GetSpecialActionHolderData().pSpecialActionsList;
		for (auto it = p_special_actions_vector->begin(); it != p_special_actions_vector->end(); ++it)
			v.push_back(*reinterpret_cast<SpecialAction*>(&(*it)));
		std::sort(v.begin(), v.end(), SpecialAction::SpecialActionCompare);
		return v.size();
	}

	DWORD SpecialActionHolder::GetSpecialActions(std::vector<SpecialAction*> &v) const
	{
		std::list<SPECIALACTION>* p_special_actions_vector = GetSpecialActionHolderData().pSpecialActionsList;
		for (auto it = p_special_actions_vector->begin(); it != p_special_actions_vector->end(); ++it)
			v.push_back(reinterpret_cast<SpecialAction*>(&(*it)));
		std::sort(v.begin(), v.end(), SpecialAction::pSpecialActionCompare);
		return v.size();
	}

	SpecialAction* SpecialActionHolder::GetSpecialAction(DWORD index) const
	{
		std::vector<SpecialAction*> v;
		auto count = GetSpecialActions(v);
		if (index < 0 || index >= count)
			return nullptr;
		return v[index];
	}

	SpecialAction* SpecialActionHolder::GetSpecialAction(PCHAR special_action_name) const
	{
		char name[MAX_STRING];
		char search_name[MAX_STRING];
		strcpy_s(search_name, sizeof(search_name), special_action_name);
		_strlwr_s(search_name);
		std::vector<SpecialAction> v;
		GetSpecialActions(v);
		for (auto it = v.begin(); it != v.end(); ++it)
		{
			strcpy_s(name, sizeof(name), it->GetName());
			_strlwr_s(name);
			if (strstr(name, search_name))
				return &(*it);
		}
		return nullptr;
	}

	SpecialAction* SpecialActionHolder::GetSpecialAction(const IDENTITY& id) const
	{
		vector<SpecialAction> v;
		GetSpecialActions(v);
		for (auto it = v.begin(); it != v.end(); ++it)
		{
			if (it->GetIdentity() == id)
				return &(*it);
		}
		return nullptr;
	}

	DWORD SpecialActionHolder::GetSpecialActionCount() const
	{
		std::vector<SpecialAction*> v;
		return GetSpecialActions(v);
	}

	IDENTITY SpecialActionHolder::GetSpecialActionTarget() const
	{
		return GetSpecialActionHolderData().SpecialActionTarget;
	}

	ActionLock* SpecialActionHolder::GetActionLock(SpecialAction* p_special_action) const
	{
		std::map<DWORD, DWORD> m;
		GetLockIdMap(m);
		DWORD lock_id = 0;
		auto action_id = p_special_action->GetIdentity().Id;
		for (auto it = m.begin(); it != m.end(); ++it)
		{
			if(it->second == action_id)
			{
				lock_id = it->first;
				break;
			}
		}
		if (lock_id)
			return nullptr;
		std::vector<ActionLock*> v;
		pEngineClientAnarchy->GetClientChar()->GetStatHolder()->GetSkillLocks(v);
		for (auto it = v.begin(); it != v.end(); ++it)
		{
			//if((*it)->GetActionIdentity().Type)
		}
		return nullptr;
	}

}

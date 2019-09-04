#include "isxao_main.h"

namespace isxao_classes
{

	DWORD SpecialActionHolder::BuildLSSpecialActions(LSIndex* pIndex) const
	{
		std::vector<SpecialActionTemplate*> v;
		GetSpecialActions(v);
		for (auto it = v.begin(); it != v.end(); ++it)
			pIndex->AddItem(reinterpret_cast<LSOBJECTDATA&>((*it)));
		return pIndex->GetContainerUsed();
	}

	DWORD SpecialActionHolder::GetLockIdMap(std::map<DWORD, DWORD>& m) const
	{
		isxao_utilities::GetLockIdMap(m, GetSpecialActionHolderData().p_lock_id_dir);
		return m.size();
	}

	special_action_holder_t SpecialActionHolder::GetSpecialActionHolderData() const
	{
		return special_action_holder_;
	}

	DWORD SpecialActionHolder::GetSpecialActions(std::vector<SpecialActionTemplate> &v) const
	{
		std::list<special_action_t>* p_special_actions_vector = GetSpecialActionHolderData().p_special_actions_list;
		for (auto it = p_special_actions_vector->begin(); it != p_special_actions_vector->end(); ++it)
			v.push_back(*reinterpret_cast<SpecialActionTemplate*>(&(*it)));
		std::sort(v.begin(), v.end(), SpecialActionTemplate::SpecialActionCompare);
		return v.size();
	}

	DWORD SpecialActionHolder::GetSpecialActions(std::vector<SpecialActionTemplate*> &v) const
	{
		std::list<special_action_t>* p_special_actions_vector = GetSpecialActionHolderData().p_special_actions_list;
		for (auto it = p_special_actions_vector->begin(); it != p_special_actions_vector->end(); ++it)
			v.push_back(reinterpret_cast<SpecialActionTemplate*>(&(*it)));
		std::sort(v.begin(), v.end(), SpecialActionTemplate::pSpecialActionCompare);
		return v.size();
	}

	SpecialActionTemplate* SpecialActionHolder::GetSpecialAction(DWORD index) const
	{
		std::vector<SpecialActionTemplate*> v;
		auto count = GetSpecialActions(v);
		if (index < 0 || index >= count)
			return nullptr;
		return v[index];
	}

	SpecialActionTemplate* SpecialActionHolder::GetSpecialAction(PCHAR special_action_name) const
	{
		char name[MAX_STRING];
		char search_name[MAX_STRING];
		strcpy_s(search_name, sizeof(search_name), special_action_name);
		_strlwr_s(search_name);
		std::vector<SpecialActionTemplate> v;
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

	SpecialActionTemplate* SpecialActionHolder::GetSpecialAction(const identity_t& id) const
	{
		vector<SpecialActionTemplate> v;
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
		std::vector<SpecialActionTemplate*> v;
		return GetSpecialActions(v);
	}

	identity_t SpecialActionHolder::GetSpecialActionTarget() const
	{
		return GetSpecialActionHolderData().special_action_target;
	}

	ActionLock* SpecialActionHolder::GetActionLock(SpecialActionTemplate* p_special_action) const
	{
		std::map<DWORD, DWORD> m;
		GetLockIdMap(m);
		DWORD lock_id = 0;
		auto action_id = p_special_action->GetIdentity().id;
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
		P_ENGINE_CLIENT_ANARCHY->get_client_char()->GetStatHolder()->GetSkillLocks(v);
		for (auto it = v.begin(); it != v.end(); ++it)
		{
			//if((*it)->GetActionIdentity().Type)
		}
		return nullptr;
	}

}

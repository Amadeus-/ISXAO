#include "isxao_main.h"

namespace ao
{

	DWORD special_action_holder::build_ls_special_actions(LSIndex* p_index) const
	{
		std::vector<special_action_template*> v;
		this->get_special_actions(v);
		for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
			p_index->AddItem(reinterpret_cast<LSOBJECTDATA&>((*it)));
		return p_index->GetContainerUsed();
	}

	DWORD special_action_holder::get_lock_id_map(std::map<DWORD, DWORD>& m) const
	{
		return this->get_special_action_holder_data().p_lock_id_dir->copy_map(m);
	}

	special_action_holder_t special_action_holder::get_special_action_holder_data() const
	{
		return this->special_action_holder_;
	}

	DWORD special_action_holder::get_special_actions(std::vector<special_action_template> &v) const
	{
		auto p_special_actions_vector = this->get_special_action_holder_data().p_special_actions_list;
		for (auto it = p_special_actions_vector->begin(); it != p_special_actions_vector->end(); ++it)  // NOLINT(modernize-loop-convert)
			v.push_back(*reinterpret_cast<special_action_template*>(&(*it)));
		std::sort(v.begin(), v.end(), special_action_template::special_action_compare);
		return v.size();
	}

	DWORD special_action_holder::get_special_actions(std::vector<special_action_template*> &v) const
	{
		auto p_special_actions_vector = this->get_special_action_holder_data().p_special_actions_list;
		for (auto it = p_special_actions_vector->begin(); it != p_special_actions_vector->end(); ++it)  // NOLINT(modernize-loop-convert)
			v.push_back(reinterpret_cast<special_action_template*>(&(*it)));
		std::sort(v.begin(), v.end(), special_action_template::p_special_action_compare);
		return v.size();
	}

	special_action_template* special_action_holder::get_special_action(const DWORD index) const
	{
		std::vector<special_action_template*> v;
		const auto count = this->get_special_actions(v);
		if (index < 0 || index >= count)
			return nullptr;
		return v[index];
	}

	special_action_template* special_action_holder::get_special_action(const PCSTR special_action_name) const
	{
		char name[MAX_VARSTRING];
		char search_name[MAX_VARSTRING];
		strcpy_s(search_name, sizeof(search_name), special_action_name);
		_strlwr_s(search_name);
		std::vector<special_action_template> v;
		this->get_special_actions(v);
		for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
		{
			strcpy_s(name, sizeof(name), it->get_name());
			_strlwr_s(name);
			if (strstr(name, search_name))
				return &(*it);
		}
		return nullptr;
	}

	special_action_template* special_action_holder::get_special_action(const identity_t& id) const
	{
		std::vector<special_action_template> v;
		this->get_special_actions(v);
		for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
		{
			if (it->get_identity() == id)
				return &(*it);
		}
		return nullptr;
	}

	DWORD special_action_holder::get_special_action_count() const
	{
		std::vector<special_action_template*> v;
		return this->get_special_actions(v);
	}

	identity_t special_action_holder::get_special_action_target() const
	{
		return get_special_action_holder_data().special_action_target;
	}

	action_lock* special_action_holder::get_action_lock(special_action_template* p_special_action) const
	{
		std::map<DWORD, DWORD> m;
		get_lock_id_map(m);
		DWORD lock_id = 0;
		const auto action_id = p_special_action->get_identity().id;
		for (auto it = m.begin(); it != m.end(); ++it)  // NOLINT(modernize-loop-convert)
		{
			if(it->second == action_id)
			{
				lock_id = it->first;
				break;
			}
		}
		if (lock_id)
			return nullptr;
		std::vector<action_lock*> v;
		P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_stat_holder()->get_skill_locks(v);
		for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
		{
			if ((*it)->get_action_identity() == p_special_action->get_identity())
				return *it;
		}
		return nullptr;
	}

}

#include "isxao_main.h"

namespace ao
{

	DWORD stat_holder::get_skill_locks(std::vector<action_lock*> &v) const
	{
		auto p_skill_lock_vector = this->get_stat_holder_data().p_skill_locks;
		for (auto it = p_skill_lock_vector->begin(); it != p_skill_lock_vector->end(); ++it)  // NOLINT(modernize-loop-convert)
			v.push_back(reinterpret_cast<action_lock*>(&(*it)));
		std::sort(v.begin(), v.end(), action_lock::p_action_lock_compare);
		return v.size();
	}

	action_lock* stat_holder::get_skill_lock(special_action_template* special_action) const
	{
		std::vector<action_lock*> v;
		if (this->get_skill_locks(v))
		{
			for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
			{
				const auto action_identity = (*it)->get_action_identity();
				const auto id1 = special_action->get_locked_skill_id_1();
				const auto id2 = special_action->get_locked_skill_id_2();
				if (action_identity.type == id1 || action_identity.type == id2 || action_identity.id == id1 || action_identity.id == id2)
					return *it;
			}
		}		
		return nullptr;
	}

	stat_holder_t stat_holder::get_stat_holder_data() const
	{
		return stat_holder_;
	}

	DWORD stat_holder::get_stat_map(std::map<DWORD, LONG> &m) const
	{
		return this->get_stat_holder_data().p_stat_map_dir->copy_map(m);
	}

}
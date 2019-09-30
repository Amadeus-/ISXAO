#include "isxao_main.h"
#include "action_lock.h"
#include "special_action_template.h"
#include "stat_holder.h"

namespace ao
{

	unsigned long stat_holder::get_skill_locks(std::vector<action_lock*> &v)
	{
		auto p_skill_lock_vector = this->get_data()->p_skill_locks;
		for (auto it = p_skill_lock_vector->begin(); it != p_skill_lock_vector->end(); ++it)  // NOLINT(modernize-loop-convert)
			v.push_back(reinterpret_cast<action_lock*>(&(*it)));
		std::sort(v.begin(), v.end(), action_lock::p_action_lock_compare);
		return v.size();
	}

	action_lock* stat_holder::get_skill_lock(special_action_template* special_action)
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

	unsigned long stat_holder::get_stat_map(std::map<unsigned long, long> &m)
	{
		return this->get_data()->p_stat_map_dir->copy_map(m);
	}

}
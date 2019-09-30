#include "isxao_main.h"
#include "npc_holder.h"

namespace ao
{

	unsigned long npc_holder::get_pet_map(std::map<unsigned long, identity_t> &m)
	{
		std::map<identity_t, unsigned long> pet_map;
		this->get_raw_pet_map(pet_map);
		for (auto it = pet_map.begin(); it != pet_map.end(); ++it)  // NOLINT(modernize-loop-convert)
			m.insert_or_assign(it->second, it->first);
		return m.size();
	}

	unsigned long npc_holder::get_raw_pet_map(std::map<identity_t, unsigned long> &m)
	{
		return this->get_data()->p_pet_dir->copy_map(m);
	}

}
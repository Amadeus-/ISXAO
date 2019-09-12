#include "isxao_main.h"

namespace isxao_classes
{

	npc_holder_t npc_holder::get_npc_holder_data() const
	{
		return npc_holder_;
	}

	DWORD npc_holder::get_pet_map(std::map<DWORD, identity_t> &m) const
	{
		std::map<identity_t, DWORD> pet_map;
		this->get_npc_holder_data().p_pet_dir->copy_map(pet_map);
		for (auto it = pet_map.begin(); it != pet_map.end(); ++it)  // NOLINT(modernize-loop-convert)
			m.insert_or_assign(it->second, it->first);
		return m.size();
	}

}
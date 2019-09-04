#include "isxao_main.h"

namespace isxao_classes
{

	npc_holder_t NpcHolder::GetNPCHolderData() const
	{
		return npc_holder_;
	}

	DWORD NpcHolder::GetPetMap(std::map<DWORD, identity_t> &m) const
	{
		std::map<identity_t, DWORD> pet_map;
		isxao_utilities::GetPetMap(pet_map, GetNPCHolderData().p_pet_dir);
		for (auto it = pet_map.begin(); it != pet_map.end(); ++it)
			m.insert_or_assign(it->second, it->first);
		return m.size();
	}

}
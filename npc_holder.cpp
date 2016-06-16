#include "isxao_main.h"

namespace isxao_classes
{

	NPCHOLDER NpcHolder::GetNPCHolderData() const
	{
		return npc_holder_;
	}

	DWORD NpcHolder::GetPetMap(std::map<DWORD, IDENTITY> &m) const
	{
		std::map<IDENTITY, DWORD> pet_map;
		isxao_utilities::GetPetMap(pet_map, GetNPCHolderData().pPetDir);
		for (auto it = pet_map.begin(); it != pet_map.end(); ++it)
			m.insert_or_assign(it->second, it->first);
		return m.size();
	}

}
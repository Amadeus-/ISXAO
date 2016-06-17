#pragma once

class NpcHolder
{
public:
	AOLIB_OBJECT NPCHOLDER GetNPCHolderData() const;
	AOLIB_OBJECT DWORD GetPetMap(std::map<DWORD, IDENTITY> &m) const;
private:
	NPCHOLDER npc_holder_;
};
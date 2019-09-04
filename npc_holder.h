#pragma once

class NpcHolder
{
public:
	AOLIB_OBJECT npc_holder_t GetNPCHolderData() const;
	AOLIB_OBJECT DWORD GetPetMap(std::map<DWORD, identity_t> &m) const;
private:
	npc_holder_t npc_holder_;
};
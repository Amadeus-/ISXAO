#pragma once

class PerkHolder
{
public:
	AOLIB_OBJECT PERKHOLDER GetPerkHolderData() const;
	AOLIB_OBJECT DWORD GetPerkLocks(std::vector<ActionLock*>&) const;
	AOLIB_OBJECT DWORD GetPerkMap(std::map<IDENTITY, DWORD> &m) const;
	AOLIB_OBJECT ActionLock* GetActionLock(SpecialActionTemplate*);
private:
	PERKHOLDER perk_holder_;
};
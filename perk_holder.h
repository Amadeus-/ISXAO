#pragma once

class PerkHolder
{
public:
	AOLIB_OBJECT perk_holder GetPerkHolderData() const;
	AOLIB_OBJECT DWORD GetPerkLocks(std::vector<ActionLock*>&) const;
	AOLIB_OBJECT DWORD GetPerkMap(std::map<identity_t, DWORD> &m) const;
	AOLIB_OBJECT ActionLock* GetActionLock(SpecialActionTemplate*);
private:
	perk_holder perk_holder_;
};
#pragma once

class SpecialActionHolder
{
public:
	AOLIB_OBJECT DWORD BuildLSSpecialActions(LSIndex*) const;
	AOLIB_OBJECT DWORD GetLockIdMap(std::map<DWORD, DWORD> &m) const;
	AOLIB_OBJECT SPECIALACTIONHOLDER GetSpecialActionHolderData() const;
	AOLIB_OBJECT DWORD GetSpecialActions(std::vector<SpecialActionTemplate>&) const;
	AOLIB_OBJECT DWORD GetSpecialActions(std::vector<SpecialActionTemplate*>&) const;
	AOLIB_OBJECT SpecialActionTemplate* GetSpecialAction(PCHAR) const;
	AOLIB_OBJECT SpecialActionTemplate* GetSpecialAction(DWORD) const;
	AOLIB_OBJECT SpecialActionTemplate* GetSpecialAction(const IDENTITY&) const;
	AOLIB_OBJECT DWORD GetSpecialActionCount() const;
	AOLIB_OBJECT IDENTITY GetSpecialActionTarget() const;
	AOLIB_OBJECT ActionLock* GetActionLock(SpecialActionTemplate*) const;	
private:
	SPECIALACTIONHOLDER special_action_holder_;
};
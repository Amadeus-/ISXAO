#pragma once

class SpecialActionHolder
{
public:
	AOLIB_OBJECT DWORD BuildLSSpecialActions(LSIndex*) const;
	AOLIB_OBJECT DWORD GetLockIdMap(std::map<DWORD, DWORD> &m) const;
	AOLIB_OBJECT SPECIALACTIONHOLDER GetSpecialActionHolderData() const;
	AOLIB_OBJECT DWORD GetSpecialActions(std::vector<SpecialAction>&) const;
	AOLIB_OBJECT DWORD GetSpecialActions(std::vector<SpecialAction*>&) const;
	AOLIB_OBJECT SpecialAction* GetSpecialAction(PCHAR) const;
	AOLIB_OBJECT SpecialAction* GetSpecialAction(DWORD) const;
	AOLIB_OBJECT SpecialAction* GetSpecialAction(const IDENTITY&) const;
	AOLIB_OBJECT DWORD GetSpecialActionCount() const;
	AOLIB_OBJECT IDENTITY GetSpecialActionTarget() const;
	AOLIB_OBJECT ActionLock* GetActionLock(SpecialAction*) const;
private:
	SPECIALACTIONHOLDER special_action_holder_;
};
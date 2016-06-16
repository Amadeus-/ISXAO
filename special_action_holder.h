#pragma once

class SpecialActionHolder
{
public:
	AOLIB_OBJECT DWORD BuildLSSpecialActions(LSIndex*) const;
	AOLIB_OBJECT SPECIALACTIONHOLDER GetSpecialActionHolderData() const;
	AOLIB_OBJECT DWORD GetSpecialActions(std::vector<SpecialAction>&) const;
	AOLIB_OBJECT DWORD GetSpecialActions(std::vector<SpecialAction*>&) const;
	AOLIB_OBJECT SpecialAction* GetSpecialAction(PCHAR) const;
	AOLIB_OBJECT SpecialAction* GetSpecialAction(const IDENTITY&) const;
	AOLIB_OBJECT IDENTITY GetSpecialActionTarget() const;
	AOLIB_OBJECT ActionLock* GetActionLock(SpecialAction*);
private:
	SPECIALACTIONHOLDER special_action_holder_;
};
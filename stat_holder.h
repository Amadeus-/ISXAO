#pragma once

class StatHolder
{
public:
	AOLIB_OBJECT DWORD GetSkillLocks(std::vector<ActionLock*>&) const;
	AOLIB_OBJECT ActionLock* GetSkillLock(SpecialAction*) const;
	AOLIB_OBJECT STATHOLDER GetStatHolderData() const;
	AOLIB_OBJECT DWORD GetStatMap(std::map<DWORD, LONG>&) const;
private:
	STATHOLDER stat_holder_;
};
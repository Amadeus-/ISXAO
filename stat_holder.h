#pragma once

class StatHolder
{
public:
	AOLIB_OBJECT DWORD GetSkillLocks(std::vector<ActionLock*>&) const;
	AOLIB_OBJECT ActionLock* GetSkillLock(SpecialActionTemplate*) const;
	AOLIB_OBJECT stat_holder_t GetStatHolderData() const;
	AOLIB_OBJECT DWORD GetStatMap(std::map<DWORD, LONG>&) const;
private:
	stat_holder_t stat_holder_;
};
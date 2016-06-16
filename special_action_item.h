#pragma once

class SpecialActionItem : public DummyItemBase
{
public:
	LONG GetSkill(DWORD);
	bool IsGeneralAction();
	bool IsPerk();
	bool IsSpecialAttack();

};
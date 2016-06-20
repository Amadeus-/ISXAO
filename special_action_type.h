#pragma once

class SpecialActionType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum SpecialActionTypeMembers
	{
		AttackDelay,
		CanApplyOnFriendly,
		CanApplyOnHostile,
		CanApplyOnSelf,
		CanApplyOnFightingTarget,
		CanUse,
		IsBuff,
		IsGeneralAction,
		IsHostile,
		IsNoRemoveNoNCUIsFriendly,
		IsNoResist,
		IsNoResistNoFumble,
		IsNotRemovable,
		IsPerk,
		IsSpecialAction,
		Range,
		SpecialActionId,
		SpecialActionProgress,
		WillBreakOnAttack,
		WillBreakOnDebuff,
		WillBreakOnSpellAttack,
	};

	enum SpecialActionTypeMethods
	{
		
	};

	SpecialActionType() : LSType("SpecialAction")
	{
		TypeMember(AttackDelay);
		TypeMember(CanApplyOnFriendly);
		TypeMember(CanApplyOnHostile);
		TypeMember(CanApplyOnSelf);
		TypeMember(CanApplyOnFightingTarget);
		TypeMember(CanUse);
		TypeMember(IsBuff);
		TypeMember(IsGeneralAction);
		TypeMember(IsHostile);
		TypeMember(IsNoRemoveNoNCUIsFriendly);
		TypeMember(IsNoResist);
		TypeMember(IsNoResistNoFumble);
		TypeMember(IsNotRemovable);
		TypeMember(IsPerk);
		TypeMember(IsSpecialAction);
		TypeMember(Range);
		TypeMember(SpecialActionId);
		TypeMember(SpecialActionProgress);
		TypeMember(WillBreakOnAttack);
		TypeMember(WillBreakOnDebuff);
		TypeMember(WillBreakOnSpellAttack);

		PersistentClass = pISInterface->RegisterPersistentClass("SpecialAction");
		pISInterface->SetPersistentClass(this, PersistentClass);
	}

	~SpecialActionType()
	{
		pISInterface->InvalidatePersistentClass(PersistentClass);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[]);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);

};
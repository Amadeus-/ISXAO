#pragma once

class NanoSpellType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum NanoSpellTypeMembers
	{
		CanApplyOnFriendly,
		CanApplyOnHostile,
		CanApplyOnSelf,
		CanApplyOnFightingTarget,
		CastingTime,
		IsBuff,
		IsHostile,
		IsNoResistCannotFumble,
		IsReady,
		IsSelfOnly,
		IsShapeChangeNano,
		IsTeamNano,
		FormulaProgress,
		FormulaRadius,
		Name,
		NanoId,
		NanoPointCost,
		NanoSchool,
		NanoStrain,
		NCUCost,
		Range,
		RechargeDelay,
		StackingOrder,
		WillBreakOnAttack,
		WillBreakOnDebuff,
		WillBreakOnSpellAttack
	};

	enum NanoSpellTypeMethods
	{
		Cast,
	};

	NanoSpellType() : LSType("nanospell")
	{
		TypeMember(CanApplyOnFightingTarget);
		TypeMember(CanApplyOnFriendly);
		TypeMember(CanApplyOnHostile);
		TypeMember(CanApplyOnSelf);
		TypeMember(CastingTime);
		TypeMember(FormulaProgress);
		TypeMember(FormulaRadius);
		TypeMember(IsBuff);
		TypeMember(IsHostile);
		TypeMember(IsNoResistCannotFumble);
		TypeMember(IsReady);
		TypeMember(IsSelfOnly);
		TypeMember(IsShapeChangeNano);
		TypeMember(IsTeamNano);
		TypeMember(Name);
		TypeMember(NanoId);
		TypeMember(NanoPointCost);
		TypeMember(NanoSchool);
		TypeMember(NanoStrain);
		TypeMember(NCUCost);
		TypeMember(Range);
		TypeMember(RechargeDelay);
		TypeMember(StackingOrder);
		TypeMember(WillBreakOnAttack);
		TypeMember(WillBreakOnDebuff);
		TypeMember(WillBreakOnSpellAttack);

		TypeMethod(Cast);

		PersistentClass = pISInterface->RegisterPersistentClass("nanospell");
		pISInterface->SetPersistentClass(this, PersistentClass);
	}

	~NanoSpellType()
	{
		pISInterface->InvalidatePersistentClass(PersistentClass);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[]);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);

};
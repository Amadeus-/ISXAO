#pragma once

class NanoSpellType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum NanoSpellTypeMembers
	{
		CastingTime,
		FormulaProgress,
		FormulaRadius,
		Name,
		NanoPointCost,
		NanoSchool,
		NanoStrain,
		NCUCost,
		Range,
		RechargeDelay,
	};

	enum NanoSpellTypeMethods
	{
		Cast,
	};

	NanoSpellType() : LSType("NanoSpell")
	{
		TypeMember(CastingTime);
		TypeMember(FormulaProgress);
		TypeMember(FormulaRadius);
		TypeMember(Name);
		TypeMember(NanoPointCost);
		TypeMember(NanoSchool);
		TypeMember(NanoStrain);
		TypeMember(NCUCost);
		TypeMember(Range);
		TypeMember(RechargeDelay);

		TypeMethod(Cast);

		PersistentClass = pISInterface->RegisterPersistentClass("NanoSpell");
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
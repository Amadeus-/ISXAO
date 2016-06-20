#pragma once

class SpecialActionTemplateType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum SpecialActionTemplateTypeMembers
	{
		Identity,
		IsLocked,
		LockOutRemaining,
		Name,
	};

	enum SpecialActionTemplateTypeMethods
	{
		Use,
	};

	SpecialActionTemplateType() : LSType("SpecialActionTemplate")
	{
		TypeMember(Identity);
		TypeMember(IsLocked);
		TypeMember(LockOutRemaining);
		TypeMember(Name);

		TypeMethod(Use);

		PersistentClass = pISInterface->RegisterPersistentClass("SpecialActionTemplate");
		pISInterface->SetPersistentClass(this, PersistentClass);
	}

	~SpecialActionTemplateType()
	{
		pISInterface->InvalidatePersistentClass(PersistentClass);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[]);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);

};
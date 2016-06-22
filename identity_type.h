#pragma once

class IdentityType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum IdentityTypeMembers
	{
		Type,
		Id,
		Combined
	};

	IdentityType() : LSType("identity")
	{
		TypeMember(Type);
		TypeMember(Id);
		TypeMember(Combined);

		PersistentClass = pISInterface->RegisterPersistentClass("identity");
		pISInterface->SetPersistentClass(this, PersistentClass);
	}
	~IdentityType()
	{
		pISInterface->InvalidatePersistentClass(PersistentClass);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);
};
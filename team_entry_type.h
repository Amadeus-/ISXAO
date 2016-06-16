#pragma once

class TeamEntryType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum TeamEntryTypeMembers
	{
		Name,
		Identity,
		ToTeamMember
	};

	enum TeamEntryTypeMethods
	{
		Kick,
		MakeLeader,
	};

	TeamEntryType() : LSType("TeamEntry")
	{
		TypeMember(Name);
		TypeMember(Identity);
		TypeMember(ToTeamMember);

		TypeMethod(Kick);
		TypeMethod(MakeLeader);

		PersistentClass = pISInterface->RegisterPersistentClass("TeamEntry");
		pISInterface->SetPersistentClass(this, PersistentClass);
	}

	~TeamEntryType()
	{
		pISInterface->InvalidatePersistentClass(PersistentClass);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[]);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);
};
#pragma once

class TeamMemberType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum TeamMemberTypeMembers
	{
		CurrentNano,
		IsInMyRaidTeam,
		MaxNano,
		PctNano
	};

	enum TeamMemberTypeMethods
	{
		Kick,
		MakeLeader,
	};

	TeamMemberType() : LSType("TeamMember")
	{
		TypeMember(CurrentNano);
		TypeMember(IsInMyRaidTeam);
		TypeMember(MaxNano);
		TypeMember(PctNano);

		TypeMethod(Kick);
		TypeMethod(MakeLeader);

		PersistentClass = pISInterface->RegisterPersistentClass("TeamMember");
		pISInterface->SetPersistentClass(this, PersistentClass);
	}

	~TeamMemberType()
	{
		pISInterface->InvalidatePersistentClass(PersistentClass);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[]);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);

	//INHERITDIRECT(pPlayerType)
};
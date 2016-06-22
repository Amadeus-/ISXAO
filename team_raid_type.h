#pragma once

class TeamRaidType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum TeamRaidTypeMembers
	{
		Leader,
		RaidCount,
		Raid,
		TeamCount,
		Team,
		GetTeam,
		GetRaid
	};

	enum TeamRaidTypeMethods
	{
		CreateRaid,
	};

	TeamRaidType() : LSType("teamraid")
	{
		TypeMember(Leader);
		TypeMember(RaidCount);
		TypeMember(Raid);
		TypeMember(TeamCount);
		TypeMember(Team);
		TypeMember(GetTeam);
		TypeMember(GetRaid);

		TypeMethod(CreateRaid);

		PersistentClass = pISInterface->RegisterPersistentClass("teamraid");
		pISInterface->SetPersistentClass(this, PersistentClass);
	}

	~TeamRaidType()
	{
		pISInterface->InvalidatePersistentClass(PersistentClass);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[]);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);
};
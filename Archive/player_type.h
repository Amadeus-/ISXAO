#pragma once

class PlayerType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum PlayerTypeMembers
	{
		IsInMyTeam,
		IsInTeam,
		ProfessionLevel,
		VisualProfession,
	};

	enum PlayerTypeMethods
	{
		Invite,
	};

	PlayerType() : LSType("Player")
	{
		TypeMember(IsInMyTeam);
		TypeMember(IsInTeam);
		TypeMember(ProfessionLevel);
		TypeMember(VisualProfession);

		TypeMethod(Invite);

		PersistentClass = pISInterface->RegisterPersistentClass("Player");
		pISInterface->SetPersistentClass(this, PersistentClass);
	}

	~PlayerType()
	{
		pISInterface->InvalidatePersistentClass(PersistentClass);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[]);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);

	//INHERITDIRECT(pActorType)

};
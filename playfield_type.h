#pragma once

class PlayfieldType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum PlayfieldTypeMembers
	{
		Name,
		ID
	};

	PlayfieldType() : LSType("Playfield")
	{
		TypeMember(Name);
		TypeMember(ID);

		PersistentClass = pISInterface->RegisterPersistentClass("Playfield");
		pISInterface->SetPersistentClass(this, PersistentClass);
	}

	~PlayfieldType()
	{
		pISInterface->InvalidatePersistentClass(PersistentClass);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);

};
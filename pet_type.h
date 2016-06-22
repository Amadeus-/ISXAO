#pragma once

class PetType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum PetTypeMembers
	{
		Type,
	};

	enum PetTypeMethods
	{
		Attack,
		Behind,
		Follow,
		Guard,
		Heal,
		Report,
		Terminate,
		Wait
	};

	PetType() : LSType("pet")
	{
		TypeMember(Type);

		TypeMethod(Attack);
		TypeMethod(Behind);
		TypeMethod(Follow);
		TypeMethod(Guard);
		TypeMethod(Heal);
		TypeMethod(Report);
		TypeMethod(Terminate);
		TypeMethod(Wait);

		PersistentClass = pISInterface->RegisterPersistentClass("pet");
		pISInterface->SetPersistentClass(this, PersistentClass);
	}

	~PetType()
	{
		pISInterface->InvalidatePersistentClass(PersistentClass);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[]);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);

	//INHERITDIRECT(pActorType)

};
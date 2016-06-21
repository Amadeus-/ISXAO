#pragma once

class DynelType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum DynelTypeMembers
	{
		Identity,
		Name,
		Distance,
		Distance2D,
		X,
		Y,
		Z,
		Loc,
		Heading,
		HeadingTo,		
		HeadingToLoc,
		CheckCollision,

		IsActor,
		IsAPet,
		IsCharacter,
		IsInfoRequestComplete,
		IsMyPet,
		IsPlayer,
		IsTeamMember,

		ToActor,
		ToPet,

		NearestDynel,
		Type,
		Id
	};

	enum DynelTypeMethods
	{
		Interact,
		RequestInfo
	};

	DynelType() : LSType("Dynel")
	{
		TypeMember(Identity);
		TypeMember(Name);

		TypeMember(Distance);
		TypeMember(Distance2D);
		TypeMember(X);
		TypeMember(Y);
		TypeMember(Z);
		TypeMember(Loc);		
		TypeMember(Heading);
		TypeMember(HeadingTo);
		TypeMember(HeadingToLoc);
		TypeMember(CheckCollision);

		TypeMember(IsActor);
		TypeMember(IsAPet);
		TypeMember(IsInfoRequestComplete);
		TypeMember(IsCharacter);
		TypeMember(IsMyPet);
		TypeMember(IsPlayer);
		TypeMember(IsTeamMember);

		TypeMember(NearestDynel);
		TypeMember(Type);
		TypeMember(Id);

		TypeMember(ToActor);
		TypeMember(ToPet);

		TypeMethod(Interact);
		TypeMethod(RequestInfo);

		PersistentClass = pISInterface->RegisterPersistentClass("Dynel");
		pISInterface->SetPersistentClass(this, PersistentClass);
	}

	~DynelType()
	{
		pISInterface->InvalidatePersistentClass(PersistentClass);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[]);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);

};
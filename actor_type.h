#pragma once

class ActorType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum ActorTypeMembers
	{
		Breed,
		Casting,
		CharRadius,
		CurrentHealth,
		CurrentNCU,
		DistancePredict,
		Gender,
		GetNCU,
		GetPets,
		GM,
		HasPets,
		IsBackingUp,
		IsCasting,
		IsCrawling,
		IsFighting,
		IsFightingMe,
		IsFlying,
		IsIdle,
		IsInvis,
		IsMovingForward,
		IsRooted,
		IsRunning,
		IsSitting,
		IsSneaking,
		IsStealthed,
		IsStrafingLeft,
		IsStrafingRight,
		IsSwimming,
		IsWalking,
		Level,
		MaxHealth,
		Master,
		MonsterScale,
		NCU,
		NCUCount,
		NPCFamily,
		NPCNumPets,
		PctHealth,
		Pet,
		PetCount,
		Profession,
		Runspeed,
		Side,
		Speed,
		Velocity
	};

	enum ActorTypeMethods
	{
		DoFace,
		DoTarget
	};

	ActorType() : LSType("Actor")
	{
		TypeMember(Breed);
		TypeMember(Casting);
		TypeMember(CharRadius);
		TypeMember(CurrentHealth);
		TypeMember(CurrentNCU);
		TypeMember(DistancePredict);
		TypeMember(Gender);
		TypeMember(GetNCU);
		TypeMember(GetPets);
		TypeMember(GM);
		TypeMember(HasPets);
		TypeMember(IsBackingUp);
		TypeMember(IsCasting);
		TypeMember(IsCrawling);
		TypeMember(IsFighting);
		TypeMember(IsFightingMe);
		TypeMember(IsFlying);
		TypeMember(IsIdle);
		TypeMember(IsInvis);
		TypeMember(IsMovingForward);
		TypeMember(IsRooted);
		TypeMember(IsRunning);
		TypeMember(IsSitting);
		TypeMember(IsSneaking);
		TypeMember(IsStealthed);
		TypeMember(IsStrafingLeft);
		TypeMember(IsStrafingRight);
		TypeMember(IsSwimming);
		TypeMember(IsWalking);
		TypeMember(Level);
		TypeMember(Master);
		TypeMember(MaxHealth);
		TypeMember(MonsterScale);
		TypeMember(NCU);
		TypeMember(NCUCount);
		TypeMember(NPCFamily);
		TypeMember(NPCNumPets);
		TypeMember(PctHealth);
		TypeMember(Pet);
		TypeMember(PetCount);
		TypeMember(Profession);
		TypeMember(Runspeed);
		TypeMember(Side);
		TypeMember(Speed);
		TypeMember(Velocity);

		TypeMethod(DoTarget);
		TypeMethod(DoFace);

		PersistentClass = pISInterface->RegisterPersistentClass("Actor");
		pISInterface->SetPersistentClass(this, PersistentClass);
	}

	~ActorType()
	{
		pISInterface->InvalidatePersistentClass(PersistentClass);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[]);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);

	INHERITDIRECT(pDynelType)

};
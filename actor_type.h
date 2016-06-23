#pragma once

class ActorType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum ActorTypeMembers
	{
		Breed,
		Casting,
		CheckCollision,
		Con,
		ConColor,
		CurrentHealth,
		CurrentNano,
		CurrentNCU,
		Distance,
		Distance2D,
		DistancePredict,
		Gender,
		GetNCU,
		GetPets,
		GM,
		HasPets,
		Heading,
		HeadingTo,
		HeadingToLoc,
		Identity,
		IsAPet,
		IsBackingUp,
		IsCasting,
		IsCharacter,
		IsCrawling,
		IsFighting,
		IsFightingMe,
		IsFlying,
		IsIdle,
		IsInfoRequestComplete,
		IsInMyRaidTeam,
		IsInMyTeam,
		IsInRaid,
		IsInTeam,
		IsInvis,
		IsKOS,
		IsMovingForward,
		IsMyPet,
		IsPlayer,
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
		Loc,
		MaxHealth,
		MaxNano,
		Master,
		Name,
		NCU,
		NCUCount,
		NPCFamily,
		NearestActor,
		PctHealth,
		PctNano,
		Pet,
		PetCount,
		Profession,
		ProfessionLevel,
		Radius,
		Runspeed,
		Scale,
		Side,
		Speed,
		ToCharacter,
		ToPet,
		Velocity,
		VisualProfession,
		X,
		Y,
		Z
	};

	enum ActorTypeMethods
	{
		DoFace,
		DoTarget,
		Interact,
		Invite,
		Kick,
		MakeLeader,
		RequestInfo
	};

	ActorType() : LSType("actor")
	{
		TypeMember(Breed);
		TypeMember(Casting);
		TypeMember(CheckCollision);
		TypeMember(Con);
		TypeMember(ConColor);
		TypeMember(CurrentHealth);
		TypeMember(CurrentNano);
		TypeMember(CurrentNCU);
		TypeMember(Distance);
		TypeMember(Distance2D);
		TypeMember(DistancePredict);
		TypeMember(Gender);
		TypeMember(GetNCU);
		TypeMember(GetPets);
		TypeMember(GM);
		TypeMember(HasPets);
		TypeMember(Heading);
		TypeMember(HeadingTo);
		TypeMember(HeadingToLoc);
		TypeMember(Identity);
		TypeMember(IsAPet);
		TypeMember(IsCharacter);
		TypeMember(IsBackingUp);
		TypeMember(IsCasting);
		TypeMember(IsCrawling);
		TypeMember(IsFighting);
		TypeMember(IsFightingMe);
		TypeMember(IsFlying);
		TypeMember(IsIdle);
		TypeMember(IsInfoRequestComplete);
		TypeMember(IsInMyRaidTeam);
		TypeMember(IsInMyTeam);
		TypeMember(IsInRaid);
		TypeMember(IsInTeam);
		TypeMember(IsInvis);
		TypeMember(IsKOS);
		TypeMember(IsMovingForward);
		TypeMember(IsMyPet);
		TypeMember(IsPlayer);
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
		TypeMember(Loc);
		TypeMember(Master);
		TypeMember(MaxHealth);
		TypeMember(MaxNano);
		TypeMember(Name);
		TypeMember(NCU);
		TypeMember(NCUCount);
		TypeMember(NPCFamily);
		TypeMember(NearestActor);
		TypeMember(PctHealth);
		TypeMember(PctNano);
		TypeMember(Pet);
		TypeMember(PetCount);
		TypeMember(Profession);
		TypeMember(ProfessionLevel);
		TypeMember(Radius);
		TypeMember(Runspeed);
		TypeMember(Scale);
		TypeMember(Side);
		TypeMember(Speed);
		TypeMember(ToCharacter);
		TypeMember(ToPet);
		TypeMember(Velocity);
		TypeMember(VisualProfession);
		TypeMember(X);
		TypeMember(Y);
		TypeMember(Z);

		TypeMethod(DoTarget);
		TypeMethod(DoFace);
		TypeMethod(Interact);
		TypeMethod(Invite);
		TypeMethod(Kick);
		TypeMethod(MakeLeader);
		TypeMethod(RequestInfo);

		PersistentClass = pISInterface->RegisterPersistentClass("actor");
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
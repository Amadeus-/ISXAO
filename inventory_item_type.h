#pragma once

class InventoryItemType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum InventoryItemTypeMembers
	{
		CanApplyOnFriendly,
		CanApplyOnHostile,
		CanApplyOnFightingTarget,
		CanApplyOnSelf,
		CanBeSplit,
		CanUse,
		Description,
		IsArmor,
		IsConsumable,
		IsImplant,
		IsMisc,
		IsNPC,
		IsSpirit,
		IsStackable,
		IsTower,
		IsWeapon,
		IsUtility,
		MustSit,
		Name,
	};

	enum InventoryItemTypeMethods
	{

	};

	InventoryItemType() : LSType("InventoryItem")
	{		
		TypeMember(CanApplyOnFriendly);
		TypeMember(CanApplyOnHostile);
		TypeMember(CanApplyOnSelf);
		TypeMember(CanApplyOnFightingTarget);
		TypeMember(CanBeSplit);
		TypeMember(CanUse);
		TypeMember(Description);
		TypeMember(IsArmor);
		TypeMember(IsConsumable);
		TypeMember(IsImplant);
		TypeMember(IsMisc);
		TypeMember(IsNPC);
		TypeMember(IsSpirit);
		TypeMember(IsStackable);
		TypeMember(IsTower);
		TypeMember(IsWeapon);
		TypeMember(IsUtility);
		TypeMember(MustSit);
		TypeMember(Name);

		PersistentClass = pISInterface->RegisterPersistentClass("InventoryItem");
		pISInterface->SetPersistentClass(this, PersistentClass);
	}

	~InventoryItemType()
	{
		pISInterface->InvalidatePersistentClass(PersistentClass);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[]);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);

};
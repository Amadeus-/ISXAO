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
		IsReady,
		IsSpirit,
		IsStackable,
		IsTower,
		IsWeapon,
		IsUtility,
		MustSit,
		Name,
		Rarity,
	};

	enum InventoryItemTypeMethods
	{

	};

	InventoryItemType() : LSType("inventoryitem")
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
		TypeMember(IsReady);
		TypeMember(IsSpirit);
		TypeMember(IsStackable);
		TypeMember(IsTower);
		TypeMember(IsWeapon);
		TypeMember(IsUtility);
		TypeMember(MustSit);
		TypeMember(Name);
		TypeMember(Rarity);

		PersistentClass = pISInterface->RegisterPersistentClass("inventoryitem");
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
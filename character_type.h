#pragma once

class CharacterType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum CharacterTypeMembers
	{
		//BankInventory,
		//BankInventoryCount,
		Inventory,
		InventoryCount,
		NanoSpell,
		NanoSpellCount,
		EquipmentCollection,
		EquipmentIndex,
	};

	enum CharacterTypeMethods
	{

	};

	CharacterType() : LSType("Character")
	{
		TypeMember(Inventory);
		TypeMember(InventoryCount);
		TypeMember(NanoSpell);
		TypeMember(NanoSpellCount);
		TypeMember(EquipmentCollection);
		TypeMember(EquipmentIndex);

		PersistentClass = pISInterface->RegisterPersistentClass("Character");
		pISInterface->SetPersistentClass(this, PersistentClass);
	}

	~CharacterType()
	{
		pISInterface->InvalidatePersistentClass(PersistentClass);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	//virtual bool GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[]);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);

	INHERITDIRECT(pActorType)

};

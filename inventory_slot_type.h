#pragma once

class InventorySlotType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum InventorySlotTypeMembers
	{
		Name,
		Item,
		Slot
	};

	enum InventorySlotTypeMethods
	{
		Use
	};

	InventorySlotType() : LSType("InventorySlot")
	{

		TypeMember(Name);
		TypeMember(Item);
		TypeMember(Slot);

		TypeMethod(Use);

		PersistentClass = pISInterface->RegisterPersistentClass("InventorySlot");
		pISInterface->SetPersistentClass(this, PersistentClass);
	}

	~InventorySlotType()
	{
		pISInterface->InvalidatePersistentClass(PersistentClass);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[]);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);

};
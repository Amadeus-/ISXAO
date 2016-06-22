#pragma once

class InventorySlotType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum InventorySlotTypeMembers
	{
		IsReady,
		Item,
		ItemCount,
		LockOutRemaining,
		Name,
		QualityLevel,
		Slot
	};

	enum InventorySlotTypeMethods
	{
		Use
	};

	InventorySlotType() : LSType("inventoryslot")
	{

		TypeMember(IsReady);
		TypeMember(Item);
		TypeMember(ItemCount);
		TypeMember(LockOutRemaining);
		TypeMember(Name);
		TypeMember(QualityLevel);
		TypeMember(Slot);

		TypeMethod(Use);

		PersistentClass = pISInterface->RegisterPersistentClass("inventoryslot");
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
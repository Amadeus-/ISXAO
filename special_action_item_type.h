#pragma once

class SpecialActionItemType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum SpecialActionItemTypeMembers
	{
		IsGeneralAction,
		IsPerk,
		IsSpecialAction
	};

	enum SpecialActionItemTypeMethods
	{
		
	};

	SpecialActionItemType() : LSType("SpecialActionItem")
	{
		TypeMember(IsGeneralAction);
		TypeMember(IsPerk);
		TypeMember(IsSpecialAction);

		PersistentClass = pISInterface->RegisterPersistentClass("SpecialActionItem");
		pISInterface->SetPersistentClass(this, PersistentClass);
	}

	~SpecialActionItemType()
	{
		pISInterface->InvalidatePersistentClass(PersistentClass);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[]);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);

};
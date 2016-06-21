#pragma once

class ActionLockType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum ActionLockTypeMembers
	{
		LockoutTimeLeft,
		LockoutTimeTotal
	};

	ActionLockType() : LSType("ActionLock")
	{
		TypeMember(LockoutTimeLeft);
		TypeMember(LockoutTimeTotal);

		PersistentClass = pISInterface->RegisterPersistentClass("ActionLock");
		pISInterface->SetPersistentClass(this, PersistentClass);
	}

	~ActionLockType()
	{
		pISInterface->InvalidatePersistentClass(PersistentClass);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);

};
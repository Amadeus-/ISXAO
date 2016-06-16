#pragma once

class NanoTemplateType : public LSTypeDefinition
{
public:
	int PersistentClass;

	enum NanoTemplateTypeMembers
	{
		CasterId,
		NanoId,
		TimeCast,
		TimeRemaining,
		TotalDuration,
	};

	enum NanoTemplateTypeMethods
	{
		Remove,
	};

	NanoTemplateType() : LSType("NanoTemplate")
	{
		TypeMember(CasterId);
		TypeMember(NanoId);
		TypeMember(TimeCast);
		TypeMember(TimeRemaining);
		TypeMember(TotalDuration);

		TypeMethod(Remove);

		PersistentClass = pISInterface->RegisterPersistentClass("NanoTemplate");
		pISInterface->SetPersistentClass(this, PersistentClass);
	}

	~NanoTemplateType()
	{
		pISInterface->InvalidatePersistentClass(PersistentClass);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[]);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);

};
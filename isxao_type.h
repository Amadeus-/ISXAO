#pragma once

class ISXAOType : public LSTypeDefinition
{
public:
	enum ISXAOTypeMembers
	{
		IsReady,
		Version
	};

	enum ISXAOTypeMethods
	{
	};

	ISXAOType() : LSType("ISXAO")
	{
		TypeMember(IsReady);
		TypeMember(Version);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);
};
#pragma once

class AOType : public LSTypeDefinition
{
public:
	enum AOTypeMembers
	{
		CheckCollision,
		GetActors,
		HeadingTo,
		Zoning,
	};

	enum AOTypeMethods
	{
	};

	AOType() : LSType("ao")
	{
		TypeMember(CheckCollision);
		TypeMember(GetActors);
		TypeMember(HeadingTo);
		TypeMember(Zoning);
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER Member, int argc, char *argv[], LSOBJECT &Object);
	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen);
};
#include "isxao_main.h"

bool ISXAOType::ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
{
	if (!ObjectData.Ptr)
		return false;

	strcpy_s(buf, buflen, AO_Version);
	return true;
}

bool ISXAOType::GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER pMember, int argc, char *argv[], LSOBJECT &Object)
{
	if (!ObjectData.Ptr)
		return false;

	switch ((ISXAOTypeMembers)pMember->ID)
	{
	case Version:
	{
		Object.ConstCharPtr = AO_Version;
		Object.Type = pStringType;
		break;
	}
	case IsReady:
	{
		Object.DWord = ao::g_isxao_initialized;
		Object.Type = pBoolType;
		break;
	}
	default:
		return false;
	}
	return true;
}
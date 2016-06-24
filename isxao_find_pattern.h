#pragma once

namespace isxao_find_pattern
{
	
	bool Compare(const BYTE* pData, const BYTE* bMask, const char* szMask);

	DWORD Pattern(DWORD dwAddress, DWORD dwLen, BYTE *bMask, char * szMask);

}

using namespace isxao_find_pattern;
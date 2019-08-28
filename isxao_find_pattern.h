#pragma once

namespace isxao_find_pattern
{
	
	bool Compare(const BYTE* pData, const BYTE* bMask, const char* szMask);

	DWORD Pattern(DWORD dwAddress, DWORD dwLen, BYTE *bMask, char * szMask);

	std::size_t find_pattern(std::vector<unsigned char> data, const char* psz_pattern, std::size_t base_address = 0, std::size_t offset = 0, int occurrence = 0);

}

using namespace isxao_find_pattern;
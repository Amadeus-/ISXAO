#include "isxao_main.h"


namespace isxao_find_pattern
{
	
	bool Compare(const BYTE* pData, const BYTE* bMask, const char* szMask)
	{
		for (; *szMask; ++szMask, ++pData, ++bMask)
			if (*szMask == 'x' && *pData != *bMask)   return 0;
		return (*szMask) == NULL;
	}

	DWORD Pattern(DWORD dwAddress, DWORD dwLen, BYTE *bMask, char * szMask)
	{
		for (DWORD i = 0; i < dwLen; i++)
			if (Compare((BYTE*)(dwAddress + i), bMask, szMask))  return (DWORD)(dwAddress + i);
		return 0;
	}

	struct PatternByte
	{
		struct PatternNibble
		{
			unsigned char data;
			bool wildcard;
		} nibble[2];
	};

	static string FormatPattern(string patterntext)
	{
		string result;
		size_t len = patterntext.length();
		for (size_t i = 0; i < len; i++)
			if (patterntext[i] == '?' || isxdigit(patterntext[i]))
				result += toupper(patterntext[i]);
		return result;
	}

	static int HexChToInt(char ch)
	{
		if (ch >= '0' && ch <= '9')
			return ch - '0';
		else if (ch >= 'A' && ch <= 'F')
			return ch - 'A' + 10;
		else if (ch >= 'a' && ch <= 'f')
			return ch - 'a' + 10;
		return 0;
	}

	static bool TransformPattern(string patterntext, vector<PatternByte> & pattern)
	{
		pattern.clear();
		patterntext = FormatPattern(patterntext);
		size_t len = patterntext.length();
		if (!len)
			return false;

		if (len % 2) // not a multiple of 2
		{
			patterntext += '?';
			len++;
		}

		PatternByte newByte;
		for (size_t i = 0, j = 0; i < len; i++)
		{
			if (patterntext[i] == '?') // wildcard
			{
				newByte.nibble[j].wildcard = true; // match anything
			}
			else //hex
			{
				newByte.nibble[j].wildcard = false;
				newByte.nibble[j].data = HexChToInt(patterntext[i]) & 0xF;
			}

			j++;
			if (j == 2) // two nibbles = one byte
			{
				j = 0;
				pattern.push_back(newByte);
			}
		}
		return true;
	}

	static bool MatchByte(const unsigned char byte, const PatternByte & pbyte)
	{
		int matched = 0;

		unsigned char n1 = (byte >> 4) & 0xF;
		if (pbyte.nibble[0].wildcard)
			matched++;
		else if (pbyte.nibble[0].data == n1)
			matched++;

		unsigned char n2 = byte & 0xF;
		if (pbyte.nibble[1].wildcard)
			matched++;
		else if (pbyte.nibble[1].data == n2)
			matched++;

		return (matched == 2);
	}

	size_t find_pattern(vector<unsigned char> data, const char* psz_pattern, size_t base_address, size_t offset, int occurrence)
	{
		// Build vectored pattern..
		vector<PatternByte> patterndata;
		if (!TransformPattern(psz_pattern, patterndata))
			return -1;

		// The result count for multiple results..
		int resultCount = 0;
		vector<unsigned char>::iterator scanStart = data.begin();

		while (true)
		{
			// Search for the pattern..
			vector<unsigned char>::iterator ret = search(scanStart, data.end(), patterndata.begin(), patterndata.end(), MatchByte);

			// Did we find a match..
			if (ret != data.end())
			{
				// If we hit the usage count, return the result..
				if (occurrence == 0 || resultCount == occurrence)
					return base_address + distance(data.begin(), ret) + offset;

				// Increment the found count and scan again..
				resultCount++;
				scanStart = ++ret;
			}
			else
				break;
		}

		return -1;
	}
}
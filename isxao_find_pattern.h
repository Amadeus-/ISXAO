#pragma once

namespace isxao
{
	namespace pattern {

		std::size_t find_pattern(std::vector<unsigned char> data, const char* pattern_text, std::size_t base_address = 0, std::size_t offset = 0, int occurrence = 0);

	}
}

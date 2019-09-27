#pragma once
#include "game_object.h"

namespace ao
{
	struct ao_html_parser;

	typedef ao_html_parser html_parser_t, *p_html_parser_t;

	class html_parser : public game_object<html_parser_t>  // NOLINT(hicpp-special-member-functions)
	{
	public:
		html_parser(html_parser&) noexcept;
		html_parser(const std::string&, unsigned long, int, bool) noexcept;
		~html_parser();
		std::string* extract_text(std::string*, int, int, unsigned long);
	};
}
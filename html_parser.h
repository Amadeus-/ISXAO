#pragma once

class html_parser  // NOLINT(cppcoreguidelines-special-member-functions, hicpp-special-member-functions)
{
public:
	html_parser(html_parser&) noexcept;
	html_parser(const string&, DWORD, int, bool) noexcept;	
	~html_parser();
	string* extract_text(string*, int, int, DWORD);
private:
	html_parser_t html_parser_;
};
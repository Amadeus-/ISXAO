#pragma once

class HTMLParser
{
public:
	HTMLParser(const string&, DWORD, int, bool);
	HTMLParser(class HTMLParser&);
	~HTMLParser();
	string* ExtractText(string*, int, int, DWORD);
private:
	html_parser_t html_parser_;
};
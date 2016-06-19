#pragma once

class HTMLParser
{
public:
	HTMLParser(const string&, DWORD, int, bool);
	HTMLParser(class HTMLParser&);
	HTMLParser::~HTMLParser();
	string* ExtractText(string*, int, int, DWORD);
private:
	HTMLPARSER html_parser_;
};
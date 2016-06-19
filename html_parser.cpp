#include "isxao_main.h"

namespace isxao_classes
{

	//FUNCTION_AT_ADDRESS(HTMLParser::HTMLParser(std::string*, int, int, DWORD), HTMLParser_c__HTMLParser_c);

	HTMLParser::HTMLParser(const string &a, DWORD b, int c, bool d)
	{
		typedef void(__thiscall *tHTMLParser)(HTMLParser*, const string&, DWORD, int, bool);
		auto pHTMLParser = tHTMLParser(HTMLParser_c__HTMLParser_c);
		pHTMLParser(this, a, b, c, d);
	}

	//FUNCTION_AT_ADDRESS(HTMLParser::HTMLParser(class HTMLParser&), HTMLParser_c__HTMLParser_c_copy);

	HTMLParser::HTMLParser(HTMLParser& h)
	{
		typedef void(__thiscall *tHTMLParser)(HTMLParser*, HTMLParser&);
		auto pHTMLParser = tHTMLParser(HTMLParser_c__HTMLParser_c_copy);
		pHTMLParser(this, h);
	}


	HTMLParser::~HTMLParser()
	{
		typedef void(__thiscall *tdHTMLParser)(HTMLParser*);
		auto pdHTMLParser = tdHTMLParser(HTMLParser_c__dHTMLParser_c);
		pdHTMLParser(this);
	}


	FUNCTION_AT_ADDRESS(string* HTMLParser::ExtractText(string*, int, int, DWORD), HTMLParser_c__ExtractText);

}
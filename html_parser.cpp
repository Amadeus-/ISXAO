#include "isxao_main.h"

namespace isxao_classes
{

#ifdef HTML_PARSER_C__HTML_PARSER_1_USE_NATIVE
	// ReSharper disable once CppPossiblyUninitializedMember
	FUNCTION_AT_ADDRESS(html_parser::html_parser(html_parser&) noexcept, html_parser_c__html_parser_c_1)
#else
	static_assert(false, "html_parser::html_parser(html_parser&) requires a native function.");
#endif

#ifdef HTML_PARSER_C__HTML_PARSER_2_USE_NATIVE
	// ReSharper disable once CppPossiblyUninitializedMember
	FUNCTION_AT_ADDRESS(html_parser::html_parser(const string&, DWORD, int, bool) noexcept, html_parser_c__html_parser_c_2)
#else
	static_assert(false, "html_parser::html_parser(const string&, DWORD, int, bool) requires a native function.");
#endif

#ifdef HTML_PARSER_C__D_HTML_PARSER_USE_NATIVE
	FUNCTION_AT_ADDRESS(html_parser::~html_parser(), html_parser_c__d_html_parser_c)
#else
	static_assert(false, "html_parser::~html_parser() requires a native function.");
#endif

#ifdef HTML_PARSER_C__EXTRACT_TEXT_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(string* html_parser::extract_text(string*, int, int, DWORD), html_parser_c__extract_text)
#else
	static_assert(false, "html_parser::extract_text(string*, int, int, DWORD) requires a native function.");
#endif

}
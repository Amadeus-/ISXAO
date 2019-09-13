#include "isxao_main.h"

namespace isxao_classes
{
	
chat_window_node_t chat_window_node::get_data() const
{
	return chat_window_node_;
}

#ifdef ChatWindowNode_c__ParseTextCommand_x
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(bool chat_window_node::parse_text_command(string&), chat_window_node_c__parse_text_command);
#endif

}
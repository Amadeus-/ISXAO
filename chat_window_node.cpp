#include "isxao_main.h"

namespace isxao_classes
{
	
CHATWINDOWNODE ChatWindowNode::GetData() const
{
	return chat_window_node_;
}

#ifdef ChatWindowNode_c__ParseTextCommand_x
FUNCTION_AT_ADDRESS(bool ChatWindowNode::ParseTextCommand(string&), ChatWindowNode_c__ParseTextCommand);
#endif

}
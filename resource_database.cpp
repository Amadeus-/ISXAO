#include "isxao_main.h"
#include "resource_database.h"

namespace ao{

#if true
	// ReSharper disable once CppMemberFunctionMayBeStatic
	// ReSharper disable once CppMemberFunctionMayBeConst
	FUNCTION_AT_ADDRESS(p_db_object_t resource_database::get_db_object(const identity_t&), resource_database_t__get_db_object_1)
#else
	static_assert(false, "resource_database::get_db_object(const identity_t&) requires a native function.");
#endif
}
#include "isxao_main.h"

namespace ao
{

#ifdef TargetingModule_t__RemoveTarget_x
	FUNCTION_AT_ADDRESS(void __cdecl targeting_module::remove_target(const identity_t &), TargetingModule_t__RemoveTarget);
#endif

#ifdef TargetingModule_t__SelectSelf_x
	FUNCTION_AT_ADDRESS(void targeting_module::select_self(), TargetingModule_t__SelectSelf);
#endif

#ifdef TargetingModule_t__SetTarget_x
	FUNCTION_AT_ADDRESS(void __cdecl targeting_module::set_target(const identity_t&, bool), targeting_module_t__set_target);
#endif

//#ifdef TargetingModule_t__SetTargetPet_x
//	FUNCTION_AT_ADDRESS(void __cdecl TargetingModule::SetTargetPet(DWORD), TargetingModule_t__SetTargetPet);
//#endif

}


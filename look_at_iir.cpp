#include "isxao_main.h"

namespace isxao_classes
{

	//FUNCTION_AT_ADDRESS(LookAtIIR::LookAtIIR(const identity_t*, const identity_t*, int), LookAtIIR_t__sub_10073E4D);

	LookAtIIR::LookAtIIR(const identity_t* client_id, const identity_t* target_id, int unknown)
	{
		typedef void(__thiscall * tLookAtIIR)(LookAtIIR*, const identity_t*, const identity_t*, int);
		auto pLookAtIIR = tLookAtIIR(LookAtIIR_t__sub_10073E4D);
		pLookAtIIR(this, client_id, target_id, unknown);
	}


}
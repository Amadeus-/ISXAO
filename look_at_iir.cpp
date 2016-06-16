#include "isxao_main.h"

namespace isxao_classes
{

	//FUNCTION_AT_ADDRESS(LookAtIIR::LookAtIIR(const IDENTITY*, const IDENTITY*, int), LookAtIIR_t__sub_10073E4D);

	LookAtIIR::LookAtIIR(const IDENTITY* client_id, const IDENTITY* target_id, int unknown)
	{
		typedef void(__thiscall * tLookAtIIR)(LookAtIIR*, const IDENTITY*, const IDENTITY*, int);
		auto pLookAtIIR = tLookAtIIR(LookAtIIR_t__sub_10073E4D);
		pLookAtIIR(this, client_id, target_id, unknown);
	}


}
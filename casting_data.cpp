#include "isxao_main.h"
#include "casting_data.h"

namespace ao
{

	identity_t casting_data::get_caster()
	{
		return get_data()->caster;
	}

	DWORD casting_data::get_nano_id()
	{
		return get_data()->nano_id;
	}

	nano_item* casting_data::get_nano_item()
	{
		return reinterpret_cast<nano_item*>(get_data()->p_nano_item);
	}

	identity_t casting_data::get_target()
	{
		return get_data()->target;
	}

}
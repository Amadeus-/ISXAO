#include "isxao_main.h"

namespace ao
{

	identity_t casting_data::get_caster() const
	{
		return get_casting_data().caster;
	}

	DWORD casting_data::get_nano_id() const
	{
		return get_casting_data().nano_id;
	}

	casting_data_t casting_data::get_casting_data() const
	{
		return casting_data_;
	}

	nano_item* casting_data::get_nano_item() const
	{
		return reinterpret_cast<nano_item*>(get_casting_data().p_nano_item);
	}

	identity_t casting_data::get_target() const
	{
		return get_casting_data().target;
	}

}
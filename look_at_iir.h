#pragma once
#include "game_object.h"

namespace ao
{
	struct ao_identity;
	struct ao_look_at_iir;

	typedef ao_identity identity_t, *p_identity_t;
	typedef ao_look_at_iir look_at_iir_t, *p_look_at_iir_t;

	class look_at_iir : public game_object<look_at_iir_t>
	{
	public:
		look_at_iir(const identity_t*, const identity_t*, int);
	};
}
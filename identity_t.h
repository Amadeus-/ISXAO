#pragma once
#ifndef _IDENTITY_T_H
#define _IDENTITY_T_H
namespace ao
{
	union ao_identity;
	typedef ao_identity identity_t, *p_identity_t;

	typedef union ao_identity
	{
		unsigned long long combined_identity{};
		struct
		{
			unsigned long type;
			unsigned long id;
		};
	} identity_t, *p_identity_t;
}
#endif
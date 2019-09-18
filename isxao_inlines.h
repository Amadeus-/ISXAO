#pragma once

namespace isxao
{

	DWORD64 inline atoui64(const PCSTR unsigned_int64)
	{
		return _strtoui64(unsigned_int64, nullptr, 10);
	}

	bool inline is_client_id(DWORD id)
	{
		return G_CHARACTER_ID == id;
	}

	// ReSharper disable once CppInconsistentNaming
	POINT3F inline point3f_from_vector3(ao::vector3_t &v)
	{
		POINT3F p;
		p.X = v.x;
		p.Y = v.y;
		p.Z = v.z;
		return p;
	}

	// ReSharper disable once CppInconsistentNaming
	ao::vector3_t inline vector3_from_point3f(POINT3F &p)
	{
		ao::vector3_t v;
		v.x = p.X;
		v.y = p.Y;
		v.z = p.Z;
		return v;
	}

	// ReSharper disable once CppInconsistentNaming
	ao::vector3_t inline vector3_from_p_point3f(PPOINT3F p)
	{
		ao::vector3_t v;
		v.x = p->X;
		v.y = p->Y;
		v.z = p->Z;
		return v;
	}

}
#pragma once

namespace isxao_inlines
{

	DWORD64 inline atoui64(PCSTR unsigned_int64)
	{
		return _strtoui64(unsigned_int64, nullptr, 10);
	}

	MODULEINFO inline GetModuleInfo(PCSTR module_name)
	{
		MODULEINFO module_info = { nullptr };
		HMODULE module_handle = GetModuleHandle(module_name);
		if (module_handle == nullptr) return module_info;
		GetModuleInformation(GetCurrentProcess(), module_handle, &module_info, sizeof(MODULEINFO));
		return module_info;
	}

	bool inline IsClientId(DWORD id)
	{
		return G_CHARACTER_ID == id;
	}

	POINT3F inline Point3fFromVector3(vector3_t &v)
	{
		POINT3F p;
		p.X = v.x;
		p.Y = v.y;
		p.Z = v.z;
		return p;
	}

	vector3_t inline Vector3FromPoint3f(POINT3F &p)
	{
		vector3_t v;
		v.x = p.X;
		v.y = p.Y;
		v.z = p.Z;
		return v;
	}

	vector3_t inline Vector3FrompPoint3f(PPOINT3F p)
	{
		vector3_t v;
		v.x = p->X;
		v.y = p->Y;
		v.z = p->Z;
		return v;
	}

}

using namespace isxao_inlines;
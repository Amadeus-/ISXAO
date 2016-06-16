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
		return g_character_id == id;
	}

	POINT3F inline Point3fFromVector3(VECTOR3 &v)
	{
		POINT3F p;
		p.X = v.X;
		p.Y = v.Y;
		p.Z = v.Z;
		return p;
	}

	VECTOR3 inline Vector3FromPoint3f(POINT3F &p)
	{
		VECTOR3 v;
		v.X = p.X;
		v.Y = p.Y;
		v.Z = p.Z;
		return v;
	}

	VECTOR3 inline Vector3FrompPoint3f(PPOINT3F p)
	{
		VECTOR3 v;
		v.X = p->X;
		v.Y = p->Y;
		v.Z = p->Z;
		return v;
	}

}

using namespace isxao_inlines;
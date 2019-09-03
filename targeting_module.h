#pragma once

class TargetingModule
{
public:
	AOLIB_OBJECT static void __cdecl RemoveTarget(const identity_t &);
	AOLIB_OBJECT void SelectSelf();
	AOLIB_OBJECT static void __cdecl SetTarget(const identity_t&, bool);
	//AOLIB_OBJECT static void __cdecl SetTargetPet(DWORD);
};
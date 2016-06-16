#pragma once

class TargetingModule
{
public:
	AOLIB_OBJECT static void __cdecl RemoveTarget(const IDENTITY &);
	AOLIB_OBJECT void SelectSelf();
	AOLIB_OBJECT static void __cdecl SetTarget(const IDENTITY&, bool);
	//AOLIB_OBJECT static void __cdecl SetTargetPet(DWORD);
};
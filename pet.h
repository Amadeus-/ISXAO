#pragma once

class Pet : public actor
{
public:
	AOLIB_OBJECT void Attack();
	AOLIB_OBJECT void Behind();
	AOLIB_OBJECT void Follow();
	AOLIB_OBJECT DWORD GetPetType();
	AOLIB_OBJECT void Guard();
	AOLIB_OBJECT void Heal();
	AOLIB_OBJECT void Report();
	AOLIB_OBJECT void Terminate();
	AOLIB_OBJECT void Wait();
};
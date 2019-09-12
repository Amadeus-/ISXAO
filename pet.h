#pragma once

class pet : public actor
{
public:
	AOLIB_OBJECT void attack();
	AOLIB_OBJECT void behind();
	AOLIB_OBJECT void follow();
	AOLIB_OBJECT DWORD get_pet_type();
	AOLIB_OBJECT void guard();
	AOLIB_OBJECT void heal();
	AOLIB_OBJECT void report();
	AOLIB_OBJECT void terminate();
	AOLIB_OBJECT void wait();
};
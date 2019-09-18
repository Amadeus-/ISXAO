#pragma once

class pet : public ao::actor
{
public:
	void attack();
	void behind();
	void follow();
	DWORD get_pet_type();
	void guard();
	void heal();
	void report();
	void terminate();
	void wait();
};
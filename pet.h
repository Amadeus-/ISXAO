#pragma once
#ifndef _PET_H
#define _PET_H

#include "actor.h"

namespace ao
{
	class pet : public actor
	{
	public:
		void attack();
		void behind();
		void follow();
		unsigned long get_pet_type();
		void guard();
		void heal();
		void report();
		void terminate();
		void wait();
	};
}
#endif
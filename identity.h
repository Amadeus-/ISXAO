#pragma once
#ifndef _IDENTITY_H
#define _IDENTITY_H
#include "identity_t.h"
#include "game_object.h"
namespace ao
{
	class identity : public game_object<identity_t>
	{
	public:
		unsigned long long get_combined_identity() const;
		void set_combined_identity(unsigned long long i);
		unsigned long get_type() const;
		void set_type(unsigned long t);
		unsigned long get_id() const;
		void set_id(unsigned long i);
		bool operator==(const identity& other) const;
		bool operator!=(const identity& other) const;
		bool operator<(const identity& other) const;
		void zero();
		void copy(const struct identity& other);
		identity();
		identity(const unsigned long t, const unsigned long i);
		identity(const unsigned long long i);
	};
}
#endif
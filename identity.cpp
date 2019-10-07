#include "identity.h"

namespace ao
{
	identity::identity()
	{
		this->set_combined_identity(0);
	}

	identity::identity(const unsigned long long i)
	{
		this->set_combined_identity(i);
	}

	identity::identity(const unsigned long t, const unsigned long i)
	{
		this->set_type(t);
		this->set_id(i);
	}
	
	unsigned long long identity::get_combined_identity() const
	{
		return this->object_data_.combined_identity;
	}

	void identity::set_combined_identity(const unsigned long long i)
	{
		this->object_data_.combined_identity = i;
	}

	unsigned long identity::get_type() const
	{
		return this->object_data_.type;
	}

	void identity::set_type(const unsigned long t)
	{
		this->object_data_.type = t;
	}

	unsigned long identity::get_id() const
	{
		return this->object_data_.id;
	}

	void identity::set_id(const unsigned long i)
	{
		this->object_data_.id = i;
	}

	bool identity::operator==(const identity& other) const
	{
		return this->get_combined_identity() == other.get_combined_identity();
	}

	bool identity

}
#pragma once

namespace ao
{
	struct ao_vector3;
	struct ao_quaternion;

	typedef ao_vector3 vector3_t, *p_vector3_t;
	typedef ao_quaternion quaternion_t, *p_quaternion_t;
}

namespace isxao
{
	class navigation
	{
	public:

	private:
		void random_facing(const ao::vector3_t&, ao::quaternion_t&);
	};
}
#include "game_object.h"

	template <typename T>
	T* game_object<T>::get_data()
	{
		return &object_data_;
	}

	template <typename T>
	template <typename U>
	U game_object<T>::get_member(const unsigned int offset)
	{
		return *reinterpret_cast<U*>(unsigned int(this->get_data()) + offset);
	}

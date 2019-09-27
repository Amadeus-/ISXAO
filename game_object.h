#pragma once
#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

template <typename T>
class game_object
{
protected:
	T* get_data();
	//{
	//	return &object_data_;
	//}
	template <typename U>
	U get_member(const unsigned int offset);
	//{
	//	return *reinterpret_cast<U*>(unsigned int(this->get_data()) + offset);
	//}
private:
	T object_data_;
};
#include "game_object.cpp"
#endif
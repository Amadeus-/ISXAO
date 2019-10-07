#pragma once
#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

template <typename T>
class game_object
{
protected:
	T* get_data();
	template <typename U>
	U get_member(const unsigned int offset);
	T object_data_;
};
#include "game_object.cpp"
#endif
//
// Created by pedro on 28/04/18.
//

#pragma once

#include <stdlib.h>
class Memory
{
public:
	//Memcpy is not implemented in the stdlib
	static void memcpy(void* destination, const void* source, size_t size);

	//Realloc implementation for C++
	template <class T>
	static T* realloc(T* ptr, size_t oldSize, size_t newSize)
	{
		T* newBlock = new T[newSize];

		for(size_t i = 0; i < oldSize; i++)
		{
			newBlock[i] = ptr[i];
		}

		delete[] ptr;

		return newBlock;

	}
};

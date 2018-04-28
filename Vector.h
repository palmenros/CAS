#pragma once

#include <stdlib.h>
#include "Memory.h"

template <class T>
class Vector
{
private:

	//Raw data
	T* data;

	//Number of items stored
	size_t count;

	//Maximum number of objects which can be stored before reallocating
	size_t capacity;

public:

	Vector()
	{
		capacity = 8;
		count = 0;
		data = (T*) malloc(sizeof(T) * capacity);
	}

	template <size_t N>
	explicit Vector(T (&arr)[N])
	{
		count = N;
		capacity = N;
		data = (T*) malloc(sizeof(T) * capacity);

		for(size_t i = 0; i < count; i++)
		{
			data[i] = arr[i];
		}
	}

	Vector(const Vector<T>& other)
	{
		count = other.count;
		capacity = other.capacity;
		data = (T*) malloc(sizeof(T) * capacity);

		for(size_t i = 0; i < count; i++)
		{
			data[i] = other[i];
		}
	}

	Vector& operator=(const Vector<T>& other)
	{
		data = (T*) realloc(data, sizeof(T) * other.capacity);
		capacity = other.capacity;
		count = other.count;

		for(size_t i = 0; i < count; i++)
		{
			data[i] = other[i];
		}

		return *this;
	}

	~Vector()
	{
		//Destroy all objects
		for(size_t i = 0; i < count; i++)
		{
			data[i].~T();
		}

		free(data);
	}

	void push(const T& e)
	{
		if(count >= capacity)
		{
			capacity *= 2;
			data = (T*) realloc(data, sizeof(T) * capacity);
		}

		data[count++] = e;
	}

	void push(const Vector<T>& v)
	{
		for(size_t i = 0; i < v.getSize(); i++)
		{
			push(v[i]);
		}
	}

	T& operator[](size_t index)
	{
		return data[index];
	}

	const T& operator[](size_t index) const
	{
		return data[index];
	}

	size_t getSize() const
	{
		return count;
	}
};
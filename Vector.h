#pragma once

#include <stdlib.h>
#include "Memory.h"

#include "Algorithm.h"

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
		capacity = 0;
		count = 0;
		data = NULL;
	}

	explicit Vector(size_t capacity)
	{
		this->capacity = capacity;
		count = 0;
		data = new T[capacity];
	}

	template <size_t N>
	explicit Vector(T (&arr)[N])
	{
		count = N;
		capacity = N;

		data = new T[capacity];

		for(size_t i = 0; i < count; i++)
		{
			data[i] = arr[i];
		}
	}

	Vector(const Vector<T>& other)
	{
		count = other.count;
		capacity = other.capacity;

		data = new T[capacity];

		for(size_t i = 0; i < count; i++)
		{
			data[i] = other[i];
		}
	}

	Vector& operator=(const Vector<T>& other)
	{
		data = Memory::realloc(data, capacity, other.capacity);

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
		delete[] data;
	}

	void push(const T& e)
	{
		if(count >= capacity)
		{
			size_t oldCapacity = capacity;
			capacity *= 2;

			data = Memory::realloc(data, oldCapacity, capacity);
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

	/**
	 * Sorts vector using mergesort
	 * @tparam Compare Function object which can be called in the form bool(*compare)(const T& a, const T& b)
	 * @param compare Returns true if A goes before than B: A <= B
	 */
	template <class Compare>
	void sort(Compare compare)
	{
		mergeSort(0, count - 1, compare);
	}

	void sort()
	{
		mergeSort(0, count - 1, Algorithm::less<T>());
	}

protected:

	/**
	 * Merges two sorted subarrays into a sorted array
	 * First subarray is [l..m]
	 * Second subarray is [m+1..r]
	 * @tparam Compare Function object which can be called in the form bool(*compare)(const T& a, const T& b)
	 * @param l Left boundary of first array
	 * @param m Right boundary of first array and left boundary of second array
	 * @param r Right boundary of second array
	 * @param compare Returns true if A goes before than B: A <= B
	 */
	template<class Compare>
	void merge(size_t l, size_t m, size_t r, Compare compare)
	{
		//Array sizes
		size_t n1 = m - l + 1;
		size_t n2 = r - m;

		//Temp arrays
		Vector<T> L(n1), R(n2);

		for(size_t i = 0; i < n1; i++)
		{
			L.push(data[l + i]);
		}

		for(size_t i = 0; i < n2; i++)
		{
			R.push(data[m + 1 + i]);
		}

		//Merge temporal arrays bach into arr[l..r]
		size_t i = 0; //Initial index of first subarray
		size_t j = 0; //Initial index of second subarray
		size_t k = l; //Initial index of merged subarray

		while(i < n1 && j < n2)
		{
			if(compare(L[i], R[j]))
			{
				data[k] = L[i];
				i++;
			}
			else
			{
				data[k] = R[j];
				j++;
			}
			k++;
		}

		//Copy the remaining elements of L if there are any
		while(i < n1)
		{
			data[k] = L[i];
			i++;
			k++;
		}

		//Copy the remaining elements of R if there are any
		while(j < n2)
		{
			data[k] = R[j];
			j++;
			k++;
		}
	}

	/**
	 * Sorts using mergesort an array [l..r]
	 * @tparam Compare Function object which can be called in the form bool(*compare)(const T& a, const T& b)
	 * @param l Left boundary of the array
	 * @param r Right boundary of the array
	 * @param compare Returns true if A goes before than B: A <= B
	 */
	template <class Compare>
	void mergeSort(size_t l, size_t r, Compare compare)
	{
		if(l < r)
		{
			//Same thing as (l+r)/2, but avoids overflow for large l and h
			size_t m = l + (r - l) / 2;

			//Sort first and second array halves
			mergeSort(l, m, compare);
			mergeSort(m + 1, r, compare);

			merge(l, m, r, compare);
		}
	}

};
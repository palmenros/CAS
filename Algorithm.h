//
// Created by pedro on 29/04/18.
//

#pragma once

#include <stdlib.h>

namespace Algorithm
{

//Comparing helper functions, useful to sort
template <class T>
struct less
{
	bool operator()(const T& a, const T& b) const
	{
		return a <= b;
	}
};

template <class T>
struct greater
{
	bool operator()(const T& a, const T& b) const
	{
		return a > b;
	}
};

//Hash function, useful to hash keys for Map
template <class T>
struct hash
{
	//It is not implemented. If it is not implemented for user types, a LINK error will occur.
	size_t operator()(const T& t) const;
};

//Define hashes of trivially hashable types
#define algorithm_define_trivial_hash(T) 		  \
  	template<>									  \
    struct hash<T> 								  \
    {                                             \
      size_t operator()(T val) const 			  \
      { return static_cast<size_t>(val); }        \
    };

algorithm_define_trivial_hash(bool)
algorithm_define_trivial_hash(char)
algorithm_define_trivial_hash(unsigned char)
algorithm_define_trivial_hash(signed char)
algorithm_define_trivial_hash(short)
algorithm_define_trivial_hash(int)
algorithm_define_trivial_hash(long)
algorithm_define_trivial_hash(long long)
algorithm_define_trivial_hash(unsigned short)
algorithm_define_trivial_hash(unsigned int)
algorithm_define_trivial_hash(unsigned long)
algorithm_define_trivial_hash(unsigned long long)


#undef algorithm_define_trivial_hash


}

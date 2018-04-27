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
};

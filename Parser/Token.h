//
// Created by pedro on 29/04/18.
//

#pragma once


#include "../String.h"

class Token
{
private:

	//String representation of the token
	String str;

	//Position in the source string, saved for error reporting
	int position;

public:

	Token();

	explicit Token(const String& str, int position = -1);

};



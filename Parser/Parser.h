//
// Created by pedro on 29/04/18.
//

#pragma once

#include "../String.h"
#include "../Vector.h"
#include "Token.h"

class Parser
{
private:

	String src;

protected:

	//Generate tokens from an input string
	static Vector<Token> tokenize(const String& str);

	//Vector containing

public:

	Parser(const String& source);

};



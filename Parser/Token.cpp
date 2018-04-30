//
// Created by pedro on 29/04/18.
//

#include "Token.h"

Token::Token(const String &str, int position)
	: str(str), position(position)
{
}

Token::Token()
	: str(""), position(-1)
{
}
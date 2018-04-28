//
// Created by pedro on 28/04/18.
//

#pragma once

#include "Vector.h"
#include "String.h"

namespace ExpressionType
{
	enum e {
		Literal,
		Function,
		Operator
	};
};


class Expression
{
private:

	//String representation of the expression
	String str;

	//Type of the expression
	ExpressionType::e type;

	//Arguments of the expression
	Vector<Expression> args;

public:
	Expression(const String& str, ExpressionType::e type, const Vector<Expression>& args = Vector<Expression>());

	String toString() const;
};

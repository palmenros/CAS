//
// Created by pedro on 28/04/18.
//

#include "Expression.h"

Expression::Expression(const String& str, ExpressionType::e type, const Vector<Expression>& args)
	: str(str), type(type), args(args)
{
}
String Expression::toString() const
{

	return String();
}

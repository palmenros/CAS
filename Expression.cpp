//
// Created by pedro on 28/04/18.
//

#include "Expression.h"

Expression::Expression(const String &str, ExpressionType::e type, const Vector<Expression> &args)
	: str(str), type(type), args(args)
{
}

String Expression::toString() const
{
	String result;
	switch (type) {
	case ExpressionType::Literal: result = str;
		break;
	case ExpressionType::Function: result = str;
		result += '(';

		for (size_t i = 0; i < args.getSize(); i++) {
			result = result + args[i].toString() + ",";
		}

		result += ')';
		break;
	case ExpressionType::Operator: char c = str[0];

		switch (c) {
		case '+':
			for (size_t i = 0; i < args.getSize() - 1; i++) {
				result = result + args[i].toString() + '+';
			}
			result += args[args.getSize() - 1].toString();
			break;

		case '*':
			for (size_t i = 0; i < args.getSize(); i++) {
				if (args[i].isSum() || args[i].isDivision()) {
					result = result + '(' + args[i].toString() + ")";
				}
				else {
					result = result + args[i].toString();
				}
				if (i < args.getSize() - 1) {
					result += '*';
				}
			}

			break;

		case '/':

			if(args[0].type == ExpressionType::Literal || args[0].isExponential())
			{
				result = args[0].toString() + '/';
			}
			else
			{
				result = '(' + args[0].toString() + ')' + '/';
			}

			if(args[1].type == ExpressionType::Literal || args[0].isExponential())
			{
				result += args[1].toString();
			}
			else
			{
				result += '(' + args[1].toString() + ')';
			}
			break;

		case '^':
			if(args[0].type == ExpressionType::Literal)
			{
				result = args[0].toString() + '/';
			}
			else
			{
				result = '(' + args[0].toString() + ')' + '^';
			}

			if(args[1].type == ExpressionType::Literal)
			{
				result = args[1].toString();
			}
			else
			{
				result = '(' + args[1].toString() + '^';
			}
			break;
		}


		break;
	}

	return result;
}

bool Expression::isSum() const
{
	return type == ExpressionType::Operator && str[0] == '+';
}

bool Expression::isDivision() const
{
	return type == ExpressionType::Operator && str[0] == '/';
}
bool Expression::isExponential() const
{
	return type == ExpressionType::Operator && str[0] == '^';
}

Expression::Expression()
	: type(ExpressionType::None)
{
}



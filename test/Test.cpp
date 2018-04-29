#include <iostream>

#include "../Vector.h"
#include "../String.h"
#include "../Expression.h"

template <class T>
void print(const T& t)
{
	std::cout << t << std::endl;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	os << str.getString();
	return os;
}

template <class T>
void print(const Vector<T>& v)
{
	for(int i = 0; i < v.getSize(); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

class Test {
public:
	Test()
	{
		print("Hola");
	}

	Test& operator=(const Test& other)
	{
		print("Copiado");
		return *this;
	}

	~Test()
	{
		print("Adios");
	}
};

template <class T>
void destroy(T t)
{
	t.~T();
}


int main()
{
	// 1 + 3x
	Expression a[] = { Expression("1", ExpressionType::Literal), Expression("3x", ExpressionType::Literal)};
	Expression sum = Expression("+", ExpressionType::Operator, Vector<Expression>(a));

	// 2x * 3
	Expression b[] = {Expression("2x", ExpressionType::Literal), Expression("3", ExpressionType::Literal), sum};
	Expression m = Expression("*", ExpressionType::Operator, Vector<Expression>(b));

	// 2x*3*(1+3x) / 2
	Expression c[] = { m, Expression("2", ExpressionType::Literal)};
	Expression res = Expression("/", ExpressionType::Operator, Vector<Expression>(c));

	String arr[] = {"hola mundo", "me llamo pedro", "abcd", "abba", "cadabra", "magia", "negra", "patata", "alvarez", "montecristo", "alvarez", "alvareza"};
	Vector<String> v(arr);

	print(v);
	v.sort(Sort::greater<String>());
	print(v);
	v.sort(Sort::less<String>());
	print(v);


	return 0;
}
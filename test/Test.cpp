#include <iostream>

#include "../Vector.h"
#include "../String.h"

template <class T>
void print(const T& t)
{
	std::cout << t << std::endl;
}

void print(const String& str)
{
	print(str.getString());
}

template <class T>
void print(const Vector<T>& v)
{
	for(int i = 0; i < v.getSize(); i++)
	{
		print(v[i]);
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
	Vector<String> a;
	{
		String str[] = {"Uno", "Dos", "Tres"};
		Vector<String> b(str);
		a = b;
	}

	print(a);


	return 0;
}
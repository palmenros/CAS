#include <iostream>

#include "../Vector.h"
#include "../String.h"

template <class T>
void print(const T& t)
{
	std::cout << t << " ";
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

int main()
{
	String a = "Hola", b = "mundo";
	print(a + ' ' + b);

	return 0;
}
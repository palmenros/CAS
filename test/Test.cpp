#include <iostream>

template <class T>
void print(const T& t)
{
	std::cout << t << std::endl;
}

int main()
{
	print("Hola mundo");
	return 0;
}
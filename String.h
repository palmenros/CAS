#pragma once

#include <stdlib.h>
#include "Algorithm.h"

class String
{
private:

	//Raw data representation
	char* data;

	//Number of char used (including \0)
	size_t count;

	//Max capacity of the string
	size_t capacity;

public:

	String();
	String(const char* str);

	//Construct string from a char. Repeat it n times
	explicit String(char c, size_t n = 1);

	String(const String& other);
	String& operator=(const String& other);
	~String();

	void push(char c);
	void push(const String& s);

	size_t getLength() const;

	char& operator[](size_t index);
	const char& operator[](size_t index) const;

	String& operator+=(const String& str);
	String& operator+=(char c);

	friend String operator+(const String& a, const String& b);
	friend String operator+(const String& s, char c);
	friend String operator+(char c, const String& s);

	bool operator!=(const String& other) const;
	bool operator==(const String& other) const;

	bool operator<(const String& other) const;
	bool operator<=(const String& other) const;
	bool operator>(const String& other) const;
	bool operator>=(const String& other) const;

	const char* getString() const;

private:

	//Helper function
	static size_t strlen(const char* str);

};

//Provide hash function
namespace Algorithm
{
	template<>
	struct hash<String>
	{
		/*djb2 hash function by Dan Bernstein*/
		size_t operator()(const String& s)
		{
			size_t hash = 5381;
			for(int i = 0; i < s.getLength(); i++)
			{
				hash = ((hash << 5) + hash) + s[i]; /* hash * 33 + c */
			}
			return hash;
		}
	};
}
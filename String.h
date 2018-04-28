#pragma once

#include <stdlib.h>

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

	const char* getString() const;
private:

	//Helper function
	static size_t strlen(const char* str);

};

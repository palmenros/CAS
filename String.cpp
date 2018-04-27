//
// Created by pedro on 27/04/18.
//

#include "String.h"
#include "Memory.h"

String::String()
{
	count = 1;
	capacity = 8;
	data = (char*) malloc(sizeof(char) * capacity);
	data[0] = '\0';
}

String::String(const char * str)
{
	size_t length = strlen(str);
	capacity = length + 1;
	count = capacity;
	data = (char*) malloc(sizeof(char) * capacity);
	Memory::memcpy(data, str, length + sizeof(char));
}

String::String(const String& other)
{
	capacity = other.capacity;
	count = other.count;
	data = (char*) malloc(sizeof(char) * capacity);
	Memory::memcpy(data, other.data, sizeof(char) * count);
}

String& String::operator=(const String& other)
{
	capacity = other.capacity;
	count = other.count;
	data = (char*) realloc(data, sizeof(char) * capacity);
	Memory::memcpy(data, other.data, sizeof(char) * count);
	return *this;
}

String::~String()
{
	free(data);
}

void String::push(char c)
{
	if(count >= capacity)
	{
		capacity *= 2;
		data = (char*) realloc(data, sizeof(char) * capacity);
	}

	//Replace '\0' with new char
	data[count - 1] = c;

	//Don't forget to end string
	data[count++] = '\0';
}

void String::push(const String &s)
{
	for(size_t i = 0; i < s.getLength(); i++)
	{
		push(s[i]);
	}
}

size_t String::getLength() const
{
	return count - 1;
}

char& String::operator[](size_t index)
{
	return data[index];
}

const char& String::operator[](size_t index) const
{
	return data[index];
}

String operator+(const String& a, const String& b)
{
	String result(a);
	result.push(b);
	return result;
}

String operator+(const String& s, char c)
{
	String result(s);
	result.push(c);
	return result;
}

String operator+(char c, const String& s)
{
	return s + c;
}

String& String::operator+=(const String& str)
{
	push(str);
	return *this;
}

String& String::operator+=(char c)
{
	push(c);
	return *this;
}

size_t String::strlen(const char* str)
{
	size_t size = 0;
	while(*str != '\0')
	{
		size++;
		str++;
	}

	return size;
}

const char* String::getString() const
{
	return data;
}
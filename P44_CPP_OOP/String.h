#pragma once
#include <iostream>

using namespace std;

class String
{
	char* str = nullptr;
	size_t size;

public:
	String(int size = 80);
	String(const char* str);

	String(const String& obj);

	String& operator=(const String& obj);

	~String();

	size_t length() const;

	friend ostream& operator<<(ostream& os, const String& obj);
	friend istream& operator>>(istream& is, String& obj);

	String operator+(const String& s) const;
	void operator+=(const String& s);

	char operator[](int index);

	bool operator==(const String& s);
	bool operator!=(const String& s);
	bool operator>(const String& s);
	bool operator<(const String& s);
	bool operator>=(const String& s);
	bool operator<=(const String& s);

	int compareTo(const String& s); // 1 0 -1

	const char* getStr();

};


String::String(int size)
{
	if (size < 0)
		size = 0;
	this->size = size;
	this->str = new char[size + 1];
	this->str[0] = '\0';
}

String::String(const char* str)
{
	size = strlen(str);
	this->str = new char[size + 1];
	strcpy_s(this->str, size + 1, str);
}

String::String(const String& obj)
{
	size = obj.size;
	str = new char[size + 1];
	strcpy_s(str, size + 1, obj.str);
}

String::~String()
{
	if (str != nullptr)
		delete[] str;
}

size_t String::length() const
{
	return size;
}

ostream& operator<<(ostream& os, const String& obj)
{
	os << obj.str;
	return os;
}

istream& operator>>(istream& is, String& obj)
{
	char buffer[1000];
	is.getline(buffer, 1000);

	obj.size = strlen(buffer);
	if (obj.str != nullptr)
		delete[] obj.str;
	obj.str = new char[obj.size + 1];
	strcpy_s(obj.str, obj.size + 1, buffer);
	return is;
}


bool String::operator==(const String& s)
{
	for (size_t i = 0; i < size + 1; i++)
	{
		if (str[i] != s.str[i])
		{
			return false;
		}
	}

	return true;
}

const char* String::getStr()
{
	return str;
}
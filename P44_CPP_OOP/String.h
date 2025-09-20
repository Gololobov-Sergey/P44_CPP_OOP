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

	~String();
	void set();
	void set(const String& obj);
	void set(const char* str);
	void print() const;
	size_t length() const;
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

void String::set()
{
	char buffer[1000];
	cin.getline(buffer, 1000);
	set(buffer);
}

void String::set(const String& obj)
{
	set(obj.str);
}

void String::set(const char* str)
{
	if (str == nullptr)
	{
		if (this->str != nullptr)
			this->str[0] = '\0';
		size = 0;
		return;
	}
	size = strlen(str);
	if (this->str != nullptr)
		delete[] this->str;
	this->str = new char[size + 1];
	strcpy_s(this->str, size + 1, str);
}

void String::print() const
{
	if (str != nullptr)
		cout << str << endl;
}

size_t String::length() const
{
	return size;
}
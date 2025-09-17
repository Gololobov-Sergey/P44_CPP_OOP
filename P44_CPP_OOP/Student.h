#pragma once
#include <iostream>
#include "String.h"

using namespace std;



class Student
{
//private:
	//int id;
	char* name;

	int age = 0;

	const int t;

	static int count;

public:
	

	Student() : t(5), age{ 0 }
	{
		cout << "Constructor" << endl;
		name = new char[8];
		strcpy_s(name, 8, "No name");
		count++;
	}

	Student(const char* n, int a, int t) : t(t)
	{
		
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		setAge(a);
		count++;
		cout << "Constructor " << name << endl;
	}

	Student(const Student& obj) : t(obj.t)
	{
		name = new char[strlen(obj.name) + 1];
		strcpy_s(name, strlen(obj.name) + 1, obj.name);
		age = obj.age;
		count++;
		cout << "Copy Constructor " << name << endl;
	}

	~Student()
	{
		cout << "Destructor " << name << endl;
		if (name != nullptr)
			delete[] name;
		count--;
	}

	void print() const
	{
		
		cout << "Name : " << name << endl;
		cout << "Age  : " << age << endl;
		cout << "T    : " << t << endl;
	}

	void setAge(int a)
	{
		if(a > 0 && a < 100)
			age = a;
	}

	int getAge() const
	{
		return age;
	}

	void setName(const char* n)
	{
		if (name != nullptr)
			delete[] name;
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}

	char* getName() const
	{
		return name;
	}

	static int getCount()
	{
		return count;
	}

};

int Student::count{0};


#pragma once
#include <iostream>

using namespace std;



class Student
{
//private:
	//int id;
	char* name;
	int age = 0;

public:
	
	Student()
	{
		cout << "Constructor" << endl;
		name = new char[8];
		strcpy_s(name, 8, "No name");
		age = 0;
	}

	Student(const char* n, int a)
	{
		cout << "Constructor" << endl;
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		age = a;
	}

	void print()
	{
		cout << "Name : " << name << endl;
		cout << "Age  : " << age << endl;
	}

	void setAge(int a)
	{
		if(a > 0 && a < 100)
			age = a;
	}

	int getAge()
	{
		return age;
	}

	void setName(const char* n)
	{
		strcpy_s(name, strlen(n) + 1, n);
	}
};

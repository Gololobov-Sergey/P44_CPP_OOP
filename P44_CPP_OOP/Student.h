#pragma once
#include <iostream>

using namespace std;



class Student
{
//private:
	//int id;
	char* name;
	int age = 0;

	const int t = 0;

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
		cout << "Constructor" << endl;
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		age = a;
		count++;
	}

	~Student()
	{
		cout << "Destructor" << endl;
		if (name != nullptr)
			delete[] name;
		count--;
	}

	void print()
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

	int getAge()
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

	char* getName()
	{
		return name;
	}

	static int getCount()
	{
		return count;
	}

	void f();

	void f1();

};

int Student::count = 0;

void Student::f()
{
	cout << "f()" << endl;
}

void Student::f1()
{
	cout << "f1()" << endl;
}
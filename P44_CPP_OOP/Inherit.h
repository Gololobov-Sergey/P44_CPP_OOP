#pragma once
#include<iostream>

using namespace std;

class Human
{
	string name;
	int age;

protected:

	int id;

public:

	Human() {}
	Human(string n, int a) : name(n), age(a) { cout << "Human" << endl; }

	void print()
	{
		cout << "Name : " << name << endl;
		cout << "Age  : " << age << endl;
	}

	void method()
	{

	}
};

class Worker : public Human
{
	int workTime;

public:
	Worker() {}
	Worker(string n, int a, int wt) : workTime(wt), Human(n, a)
	{
		cout << "Worker" << endl;
		id = 100;
	}

	void method() = delete;

	void print()
	{
		Human::print();
		cout << "Work time : " << workTime << endl;
	}
};


class Director : public Worker
{

};


class A
{
	int a1;

protected:

	int a2;

public:

	int a3;
};

class B : protected A
{
	void m()
	{
		//a1 = 10;
		a2 = 10;
		a3 = 10;
	}
};

class C : public B
{
	void c()
	{
		//a1 = 10;
		a2 = 10;
		a3 = 10;
	}
};
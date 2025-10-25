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

class Device
{
public:
	int id;

	Device(int id) : id(id) {}
};

class LAN : virtual public Device
{
	int id;

public:
	LAN(int id, int id_d) : Device(id_d), id(id) {}
	int getID() { return id; }
};


class WiFi : virtual public Device
{
	int id;

public:
	WiFi(int id, int id_d) : Device(id_d), id(id) {}
	int getID() { return id; }
};


class Router : public WiFi, public LAN
{
	int id;

public:
	Router(int id, int id_w, int id_l, int id_d) : id(id), WiFi(id_w, id_d), LAN(id_l, id_d), Device(id_d) {}
};
#pragma once
#include <iostream>


using namespace std;


class Animal
{
protected:
	string name;
	int age;

public:
	Animal(string n, int a) : name(n), age(a) {}

	virtual ~Animal() { cout << "Destr Animal" << endl; }

	virtual string getType() { return "Animal"; }

	virtual string getVoice() = 0;

	void print()
	{
		cout << "Name : " << name << endl;
		cout << "Age  : " << age << endl;
	}
};

string Animal::getVoice()
{
	//
	return "No voice";
}


class Cat /*final*/: public Animal
{
	int* mouse;

public:
	Cat(string n, int a) : Animal(n, a) { mouse = new int{ 0 }; }

	virtual ~Cat() { delete mouse; cout << "Destr Cat" << endl; }

	void catch_mouse() { (*mouse)++; }

	virtual string getType() override { return "Cat"; }

	virtual string getVoice() override /*final*/ { return "Mau-Mau"; }
};


class SiamCat : public Cat
{
public:
	SiamCat(string n, int a) : Cat(n, a) {}

	virtual string getType() override  { return "SiamCat"; }

	virtual string getVoice() override { return "Myau-Myau"; }
};


class Dog : public Animal
{

public:
	Dog(string n, int a) : Animal(n, a) {}

	virtual string getType() override { return "Dog"; }

	virtual string getVoice() override  { return "Gaw-Gaw"; }
};

class Ravlik : public Animal
{

public:

	Ravlik(string n, int a) : Animal(n, a) {}

	virtual string getType() override { return "Ravlik"; }

	virtual string getVoice() override { return Animal::getVoice(); }
};


class IFly
{
public:
	virtual void fly() = 0;
};


class Parrot : public Animal, public IFly
{
public:

	Parrot(string n, int a) : Animal(n, a) {}

	virtual string getType() override { return "Parrot"; }

	virtual string getVoice() override { return "Kar-Kar"; }

	virtual void fly() { cout << "Parrot fly" << endl; }
};

class Sparrow : public Animal, public IFly
{
public:

	Sparrow(string n, int a) : Animal(n, a) {}

	virtual string getType() override { return "Sparrow"; }

	virtual string getVoice() override { return "Chik-Chirik"; }

	virtual void fly() { cout << "Sparrow fly" << endl; }
};
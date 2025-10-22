#pragma once
#include<iostream>

using namespace std;


class Engine
{
public:

	int power = 50;

	void start()
	{
		cout << "Engine start" << endl;
	}
};


class Car
{
	Engine* engine;

public:
	Car() { engine = new Engine; }
	~Car() { delete engine; }

	void move()
	{
		engine->start();
	}

	Engine* getEngine()
	{
		Engine* temp = engine;
		engine = nullptr;
		return temp;
	}
};

class STO
{
	Engine* engine;

public:

	void setEngine(Engine* en)
	{
		engine = en;
	}

	void upgrade()
	{
		engine->power = 60;
	}

	Engine* getEngine()
	{
		return engine;
	}
};


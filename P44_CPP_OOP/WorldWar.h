#pragma once
#include <iostream>
#include <iomanip>

#include "List.h"


using namespace std;


class Warrior
{
	int hp;
	int damage;

public:
	Warrior(int hp, int damage) : hp(hp), damage(damage) {}

	virtual ~Warrior() {}

	virtual void skill() = 0;

	friend ostream& operator<<(ostream& out, const Warrior* w);

	virtual ostream& print(ostream& out) const
	{
		cout << " -> HP : " << hp << ", Damage : " << damage << endl;
		return out;
	}
};


ostream& operator<<(ostream& out, const Warrior* w)
{
	out << setw(12) << left << setfill('.');
	return w->print(out);
}

class Light : public Warrior
{
	//

public:
	Light(int hp, int damage) : Warrior(hp, damage) {}
};


class Dark : public Warrior
{
	//

public:
	Dark(int hp, int damage) : Warrior(hp, damage) {}
};


class Wizard : public Light
{
	//

public:
	Wizard(int hp, int damage) : Light(hp, damage) {}

	virtual void skill() override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Wizard";
		return Warrior::print(out);
	}
};

class Angel : public Light
{
	//

public:
	Angel(int hp, int damage) : Light(hp, damage) {}

	virtual void skill() override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Angel";
		return Warrior::print(out);
	}
};

class Swordsman : public Light
{
	//

public:
	Swordsman(int hp, int damage) : Light(hp, damage) {}

	virtual void skill() override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Swordsman";
		return Warrior::print(out);
	}
};



class Ork :public Dark
{
	//
public:
	Ork(int hp, int damage) : Dark(hp, damage) {}

	virtual void skill() override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Ork";
		return Warrior::print(out);
	}
};


class Zombi :public Dark
{
	//
public:
	Zombi(int hp, int damage) : Dark(hp, damage) {}

	virtual void skill() override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Zombi";
		return Warrior::print(out);
	}
};

class Skeleton :public Dark
{
	//
public:
	Skeleton(int hp, int damage) : Dark(hp, damage) {}

	virtual void skill() override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Skeleton";
		return Warrior::print(out);
	}
};


class WorldWar
{
	List<Light*> lights;
	List<Dark*>  darks;

public:

	WorldWar(int size)
	{
		Light* l = nullptr;
		for (size_t i = 0; i < size; i++)
		{
			int rnd = rand() % 3;
			switch (rnd)
			{
			case 0: l = new Wizard(rand() % 21 + 50, rand() % 10 + 60); break;
			case 1: l = new Angel(rand() % 21 + 60, rand() % 10 + 50); break;
			case 2: l = new Swordsman(rand() % 21 + 70, rand() % 10 + 40); break;
			}
			lights.push_back(l);
		}
		Dark* d = nullptr;
		for (size_t i = 0; i < size; i++)
		{
			int rnd = rand() % 3;
			switch (rnd)
			{
			case 0: d = new Ork(rand() % 21 + 50, rand() % 10 + 60); break;
			case 1: d = new Zombi(rand() % 21 + 60, rand() % 10 + 50); break;
			case 2: d = new Skeleton(rand() % 21 + 70, rand() % 10 + 40); break;
			}
			darks.push_back(d);
		}
	}

	void print()
	{
		cout << "     --== Light ==--" << endl;
		lights.print();

		cout << endl;

		cout << "     --== Dark ==--" << endl;
		darks.print();
	}
};

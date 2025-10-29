#pragma once
#include <iostream>
#include <iomanip>

#include "List.h"

using namespace std;

class Warrior;

class Skill
{
public:
	virtual void execute(Warrior* w1, Warrior* w2) = 0;
};

class FireBall : public Skill
{
public:

	virtual void execute(Warrior* w1, Warrior* w2);
};


class Warrior
{
	int hp;
	int damage;

	Skill* skills;

public:
	Warrior(int hp, int damage, Skill* skills = nullptr) : hp(hp), damage(damage), skills(skills) {}

	virtual ~Warrior() {}

	int getHP() const { return hp; }

	void setHP(int hp) { this->hp = hp; }

	int getDamage() const { return damage; }
	
	virtual void skill(Warrior* w) = 0;

	friend ostream& operator<<(ostream& out, const Warrior* w);

	virtual ostream& print(ostream& out) const
	{
		cout << " -> HP : " << hp << ", Damage : " << damage << endl;
		return out;
	}

	Skill* getSkill() { return skills; }
};


ostream& operator<<(ostream& out, const Warrior* w)
{
	out << setw(12) << left << setfill('.');
	return w->print(out);
}


void FireBall::execute(Warrior* w1, Warrior* w2)
{
	cout << "FireBall skill" << endl;
}

class Light : public Warrior
{
	//

public:
	Light(int hp, int damage, Skill* skills) : Warrior(hp, damage, skills) {}
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
	Wizard(int hp, int damage, Skill* skills) : Light(hp, damage, skills) {}

	virtual void skill(Warrior* w) override
	{
		this->setHP(100 + getHP());
		cout << "Wizard + 100 HP" << endl;
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
	Angel(int hp, int damage) : Light(hp, damage, nullptr) {}

	virtual void skill(Warrior* w) override
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
	Swordsman(int hp, int damage) : Light(hp, damage, nullptr) {}

	virtual void skill(Warrior* w) override
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

	virtual void skill(Warrior* w) override
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

	virtual void skill(Warrior* w) override
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

	virtual void skill(Warrior* w) override
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
			case 0: l = new Wizard(rand() % 21 + 50, rand() % 10 + 60, new FireBall()); break;
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

	Warrior* fight(Warrior* w1, Warrior* w2)
	{
		cout << "Fight: " << endl;
		cout << w1;
		cout << w2 << endl;

		// TODO random player

		w2->setHP(w2->getHP() - w1->getDamage());

		//w1->skill(w2);

		Skill* skill = w1->getSkill();
		if (skill)
			skill->execute(w1, w2);

		if (w2->getHP() <= 0)
			return w2;
		w1->setHP(w1->getHP() - w2->getDamage());
		if (w1->getHP() <= 0)
			return w1;

		return nullptr;
	}

	void game()
	{
		while (lights.length() > 0 && darks.length() > 0)
		{
			system("cls");
			print();
			int l_ind = rand() % lights.length();
			int d_ind = rand() % darks.length();
			Warrior* lose = fight(lights[l_ind], darks[d_ind]);
			if (lose == lights[l_ind])
			{
				lights.remove(l_ind);
			}
			else if (lose == darks[d_ind])
			{
				darks.remove(d_ind);
			}
			system("pause");
		}

		system("cls");
		print();
	}

};

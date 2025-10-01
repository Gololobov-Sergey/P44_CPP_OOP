#pragma once
#include <iostream>

#include "String.h"

using namespace std;


enum class ReservoirType
{
	OCEAN,
	SEA,
	RIVER,
	LAKE,
	POND,
	PUDDLE,
	NOTYPE = -1
};


const char* getReservoirTypeName(ReservoirType type)
{
	switch (type)
	{
	case ReservoirType::OCEAN:  return "OCEAN";  break;
	case ReservoirType::SEA:    return "SEA";    break;
	case ReservoirType::RIVER:  return "RIVER";  break;
	case ReservoirType::LAKE:   return "LAKE";   break;
	case ReservoirType::POND:   return "POND";   break;
	case ReservoirType::PUDDLE: return "PUDDLE"; break;
	}
}

class Reservoir
{
	ReservoirType type; 
	String name;

public:
	Reservoir() : Reservoir(ReservoirType::NOTYPE, "") {};
	Reservoir(ReservoirType type, String name);
	void set();
	void print() const;
};

inline Reservoir::Reservoir(ReservoirType type, String name)
{
	this->type = type;
	cin >> name;
}

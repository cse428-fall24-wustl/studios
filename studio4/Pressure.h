// Pressure.h
#ifndef PRESSURE
#define PRESSURE

#include <iostream>

using namespace std;

enum class Pressure
{
	Lo,
	Med,
	Hi,
	Pop
};

ostream &operator<<(ostream &, const Pressure &day);

Pressure &operator++(Pressure &day);

Pressure operator++(Pressure &day, int i);

#endif
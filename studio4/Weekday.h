//Weekday.h
#ifndef WEEK_DAY
#define WEEK_DAY

#include <iostream>

using namespace std;

enum class Weekday {
  Sun,
  Mon,
  Tue,
  Wed,
  Thu,
  Fri,
  Sat
};

ostream& operator << (ostream&, const Weekday& day);

Weekday& operator ++ (Weekday& day);

Weekday operator ++ (Weekday& day, int i);

Weekday& operator -- (Weekday& day);

Weekday operator -- (Weekday& day, int i);

#endif
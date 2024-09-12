//Weekday.cpp
#include "Weekday.h"

using namespace std;

ostream& operator << (ostream& os, const Weekday& day) {
  switch(day) {
    case Weekday::Sun: os << "Sun"; break;
    case Weekday::Mon: os << "Mon"; break;
    case Weekday::Tue: os << "Tue"; break;
    case Weekday::Wed: os << "Wed"; break;
    case Weekday::Thu: os << "Thu"; break;
    case Weekday::Fri: os << "Fri"; break;
    case Weekday::Sat: os << "Sat"; break;
  }
  os << " ";
  return os;
}

Weekday& operator ++ (Weekday& day) {
  switch(day) {
    case Weekday::Sun: day = Weekday::Mon; break;
    case Weekday::Mon: day = Weekday::Tue; break;
    case Weekday::Tue: day = Weekday::Wed; break;
    case Weekday::Wed: day = Weekday::Thu; break;
    case Weekday::Thu: day = Weekday::Fri; break;
    case Weekday::Fri: day = Weekday::Sat; break;
    case Weekday::Sat: day = Weekday::Sun; break;
  }
  return day;
}

Weekday operator ++ (Weekday& day, int) {
    Weekday oldDay = day;
    ++day;
    return oldDay;
}

Weekday& operator -- (Weekday& day) {
    switch (day) {
    case Weekday::Sun: day = Weekday::Sat; break;
    case Weekday::Mon: day = Weekday::Sun; break;
    case Weekday::Tue: day = Weekday::Mon; break;
    case Weekday::Wed: day = Weekday::Tue; break;
    case Weekday::Thu: day = Weekday::Wed; break;
    case Weekday::Fri: day = Weekday::Thu; break;
    case Weekday::Sat: day = Weekday::Fri; break;
    }
    return day;
}

Weekday operator -- (Weekday& day, int) {
    Weekday oldDay = day;
    --day;
    return oldDay;
}

//Pressure.cpp
#include "Pressure.h"

using namespace std;

ostream& operator << (ostream& os, const Pressure& day) {
    switch (day) {
    case Pressure::Lo: os << "Lo"; break;
    case Pressure::Med: os << "Med"; break;
    case Pressure::Hi: os << "Hi"; break;
    case Pressure::Pop: os << "Pop"; break;
    }
    os << " ";
    return os;
}

Pressure& operator ++ (Pressure& day) {
    switch (day) {
    case Pressure::Lo: day = Pressure::Med; break;
    case Pressure::Med: day = Pressure::Hi; break;
    case Pressure::Hi: day = Pressure::Pop; break;
    case Pressure::Pop: day = Pressure::Pop; break;
    }
    return day;
}

Pressure operator ++ (Pressure& day, int) {
    Pressure oldDay = day;
    ++day;
    return oldDay;
}
// Pressure.h
#ifndef PRESSURE
#define PRESSURE

#include <iostream>

namespace enumerations
{
    enum class Pressure
    {
        Lo,
        Med,
        Hi,
        Pop
    };

    std::ostream &operator<<(std::ostream &, const Pressure &day);

    Pressure &operator++(Pressure &day);

    Pressure operator++(Pressure &day, int i);
}

#endif
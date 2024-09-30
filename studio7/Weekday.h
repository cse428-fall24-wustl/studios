// Weekday.h
#ifndef WEEK_DAY
#define WEEK_DAY

#include <iostream>

namespace enumerations
{
    enum class Weekday
    {
        Sun,
        Mon,
        Tue,
        Wed,
        Thu,
        Fri,
        Sat
    };

    std::ostream &operator<<(std::ostream &, const Weekday &day);

    Weekday &operator++(Weekday &day);

    Weekday operator++(Weekday &day, int i);

    Weekday &operator--(Weekday &day);

    Weekday operator--(Weekday &day, int i);

}

#endif
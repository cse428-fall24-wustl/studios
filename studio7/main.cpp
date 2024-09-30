// main.cpp
#include "Pressure.h"
#include "Weekday.h"
#include <iterator>
#include <iostream>

using std::cout;
using std::endl;

using enumerations::Pressure;
using enumerations::Weekday;

int main()
{

    Weekday day = Weekday::Sun;
    Pressure pressure = Pressure::Lo;

    for (int i = 0; i < 7; i++)
    {
        cout << day << " ";
        ++day;
    }
    cout << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << pressure << " ";
        ++pressure;
    }
    cout << endl;
    return 0;
}
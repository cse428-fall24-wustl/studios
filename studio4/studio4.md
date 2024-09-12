# CSE428 Studio 4

## Q1

**Participants:**

- Dijkstra Liu
- Ryan Zhang

## Q2

```C++
//main.cpp
#include "Pressure.h"

int main()
{

	for (Pressure p = Pressure::Lo; p != Pressure::Pop;)
	{
		cout << ++p;
	}
}


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
```

```bash
[l.tingjun@shell studio4]$ ./studio4
Med Hi Pop
```

Start from 'Low' but the first output was 'Med' showing prefix operator has higher precedence than shift operator.

## Q3

```C++
// main.cpp
#include "Pressure.h"
#include "Weekday.h"

int main()
{
	Pressure p = Pressure::Lo;
	Pressure q = Pressure::Hi;
	cout << (p < q) << endl;
	Weekday w = Weekday::Mon;
	Weekday x = Weekday::Tue;
	cout << (w < x) << endl;
	return 0;
}
```

```bash
// main.cpp
#include "Pressure.h"
#include "Weekday.h"

int main()
{
	Pressure p = Pressure::Lo;
	Pressure q = Pressure::Hi;
	cout << (p < q) << endl;
	Weekday w = Weekday::Mon;
	Weekday x = Weekday::Tue;
	cout << (w < x) << endl;
	return 0;
}
```

Becuase the integers repersented by Lo in Enumeration is less the one by Hi, similarly Mon is less than Tue, so the opereration using "<" return true, which is 1.

## Q4
```C++
// main.cpp
#include "Pressure.h"
#include "Weekday.h"
#include <set>

int main()
{
	set<Weekday> Weekdays;
	Weekdays.insert(Weekday::Mon);
	Weekdays.insert(Weekday::Tue);

	set<Weekday> Weekdays2;
	Weekdays2.insert(Weekday::Wed);
	Weekdays2.insert(Weekday::Thu);

	for (Weekday day : Weekdays)
	{
		cout << day << endl;
	}

	for (Weekday day : Weekdays2)
	{
		cout << day << endl;
	}

	return 0;
}
```
```bash
[l.tingjun@shell studio4]$ ./studio4
Mon 
Tue 
Wed 
Thu 
```

## Q5
```C++
// main.cpp
#include "Pressure.h"
#include "Weekday.h"
#include <set>
#include <algorithm>
#include <iterator>

int main()
{
	set<Weekday> Weekdays;
	Weekdays.insert(Weekday::Mon);
	Weekdays.insert(Weekday::Tue);
	Weekdays.insert(Weekday::Wed);

	set<Weekday> Weekdays2;
	Weekdays2.insert(Weekday::Mon);
	Weekdays2.insert(Weekday::Tue);
	Weekdays2.insert(Weekday::Thu);

	set<Weekday> result;
	result.insert(Weekday::Sun);

	set_intersection(Weekdays.begin(), Weekdays.end(), Weekdays2.begin(), Weekdays2.end(), inserter(result, result.end()));

	for (Weekday day : result)
	{
		cout << day << endl;
	}

	return 0;
}
```

```bash
[l.tingjun@shell studio4]$ ./studio4
Sun 
Mon 
Tue 
```

## Q6
```C++
// main.cpp
#include "Pressure.h"
#include "Weekday.h"
#include <set>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int main()
{
	set<Weekday> Weekdays;
	Weekdays.insert(Weekday::Mon);
	Weekdays.insert(Weekday::Tue);
	Weekdays.insert(Weekday::Wed);

	set<Weekday> Weekdays2;
	Weekdays2.insert(Weekday::Mon);
	Weekdays2.insert(Weekday::Tue);
	Weekdays2.insert(Weekday::Thu);

	set<Weekday> result;
	result.insert(Weekday::Sun);

	set_union(Weekdays.begin(), Weekdays.end(), Weekdays2.begin(), Weekdays2.end(), inserter(result, result.begin()));

	for (Weekday day : result)
	{
		cout << day << endl;
	}

	return 0;
}
```

```bash
[l.tingjun@shell studio4]$ ./studio4
Sun 
Mon 
Tue 
Wed 
Thu 
```
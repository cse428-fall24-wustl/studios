# CSE428 Studio 7

## Q1

**Participants:**

- Dijkstra Liu
- Ryan Zhang

## Q2

```bash
[l.tingjun@shell studio7]$ ./main
Sun  Mon  Tue  Wed  Thu  Fri  Sat
Lo  Med  Hi  Pop
```

## Q3

```C++
using std::ostream;
using std::cout;
using std::endl;
```

## Q4

```bash
g++ -o main -DUNIX   -Wall -W -g -std=c++17 -DTEMPLATE_HEADERS_INCLUDE_SOURCE main.cpp Pressure.cpp Weekday.cpp
main.cpp: In function ‘int main()’:
main.cpp:13:5: error: ‘Weekday’ was not declared in this scope
     Weekday day = Weekday::Sun;
     ^~~~~~~
main.cpp:13:5: note: suggested alternative:
In file included from main.cpp:3:
Weekday.h:9:16: note:   ‘enumerations::Weekday’
     enum class Weekday
                ^~~~~~~
main.cpp:14:5: error: ‘Pressure’ was not declared in this scope
     Pressure pressure = Pressure::Lo;
     ^~~~~~~~
main.cpp:14:5: note: suggested alternative:
In file included from main.cpp:2:
Pressure.h:9:16: note:   ‘enumerations::Pressure’
     enum class Pressure
                ^~~~~~~~
main.cpp:18:17: error: ‘day’ was not declared in this scope
         cout << day << " ";
                 ^~~
main.cpp:24:17: error: ‘pressure’ was not declared in this scope
         cout << pressure << " ";
                 ^~~~~~~~
make: *** [Makefile:60: main] Error 1
```

### Q5

```C++
using namespace enumerations;
```

In main.cpp: Added using namespace enumerations; to access Weekday and Pressure directly.
In Weekday.cpp and Pressure.cpp: No need to add using namespace enumerations; because the code is already encapsulated within the enumerations namespace.

### Q6

```C++
using enumerations::Pressure;
using enumerations::Weekday;
```

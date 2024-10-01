# CSE428 Studio 9

## Q1

Dijkstra Liu
Ryan Zhang

## Q2
```bash
[l.tingjun@shell studio9]$ ./studio9
BaseClass default constructor
BaseClass default constructor
DerivedClass default constructor
DerivedClass::*ptr1 = DerivedClass
DerivedClass::*ptr2 = BaseClass
BaseClass::*ptr3 = BaseClass
--- End of main ---
DerivedClass destructor
BaseClass destructor
BaseClass destructor
```
```C++
#include <iostream>
#include "DerivedClass.h"
#include <memory>
using namespace std;

const int SUCCESS = 0;

int main()
{
    BaseClass base;
    DerivedClass derived;

    const std::string DerivedClass::*ptr1 = &DerivedClass::DerivedStr;
    const std::string DerivedClass::*ptr2 = &BaseClass::str;
    const std::string BaseClass::*ptr3 = &BaseClass::str;

    cout << "DerivedClass::*ptr1 = " << derived.*ptr1 << endl;
    cout << "DerivedClass::*ptr2 = " << derived.*ptr2 << endl;
    cout << "BaseClass::*ptr3 = " << base.*ptr3 << endl;

    cout << "--- End of main ---" << endl;
    return SUCCESS;
}

```

## Q3
```C++
    const std::string DerivedClass::*ptr1 = DerivedClass::getDerivedStrPtr();
    const std::string DerivedClass::*ptr2 = BaseClass::getStrPtr();
    const std::string BaseClass::*ptr3 = BaseClass::getStrPtr();
```

## Q4
```bash
BaseClass default constructor
BaseClass default constructor
DerivedClass default constructor
BaseClass display
DerivedClass display
DerivedClass display
--- End of main ---
DerivedClass destructor
BaseClass destructor
BaseClass destructor

```
```C++
static void (DerivedClass::*getDisplayPtr())();
void (DerivedClass::*DerivedClass::getDisplayPtr())()
{
    return &DerivedClass::display;
}

static void (BaseClass::*getDisplayPtr())();
void (BaseClass::*BaseClass::getDisplayPtr())()
{
    return &BaseClass::display;
}

void (BaseClass::*ptr1)() = BaseClass::getDisplayPtr();
void (DerivedClass::*ptr2)() = BaseClass::getDisplayPtr();
void (DerivedClass::*ptr3)() = DerivedClass::getDisplayPtr();

(base.*ptr1)();
(derived.*ptr2)();
(derived.*ptr3)();
```

## Q5
```bash
[l.tingjun@iht32-1504.sif studio9]$ ./studio9
BaseClass default constructor
BaseClass default constructor
DerivedClass default constructor
BaseClass display
BaseClass display
DerivedClass display
--- End of main ---
DerivedClass destructor
BaseClass destructor
BaseClass destructor
```

ptr2 is point to a BaseClass display function.

## Q6
```bash
[l.tingjun@iht32-1504.sif studio9]$ ./studio9
BaseClass default constructor
BaseClass default constructor
DerivedClass default constructor
BaseClass display
BaseClass display
DerivedClass display
--- End of main ---
DerivedClass destructor
BaseClass destructor
```

```c++
function<void()> func1 = bind(&BaseClass::display, &base);
function<void()> func2 = bind(&BaseClass::display, &derived);
function<void()> func3 = bind(&DerivedClass::display, &derived);
```

## Q7

```C++
function<void(BaseClass &)> func1 = mem_fn(&BaseClass ::display);
function<void(BaseClass &)> func2 = mem_fn(&BaseClass ::display);
function<void(DerivedClass &)> func3 = mem_fn(&DerivedClass ::display);

func1(base);
func2(derived);
func3(derived);
```
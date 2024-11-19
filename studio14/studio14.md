# CSE428 Studio 14

## Q1

Dijkstra Liu
Ryan Zhang


## Q2

```bash
[l.tingjun@shell studio14]$ ./main
Hello World
```

## Q3

```C++

bool operator < (const MyClass &rhs) const;

bool MyClass::operator < (const MyClass &rhs) const {
    return str < rhs.str;
}

```

## Q4

```C++
friend bool operator < (const MyClass &lhs, const MyClass &rhs);
bool operator < (const MyClass &lhs, const MyClass & rhs) {
    return lhs.str < rhs.str;
}

```

## Q5

It will lead a conflict for the compiler to decide which operator to use.

## Q6

```C++

#ifndef TEMPLATE_PRINT_H
#define TEMPLATE_PRINT_H

#include <iostream>

using std::ostream;

template <typename T>
void printToStream(std::ostream &os, const T &value);

#include "template_print.cpp"

#endif

``` 

```C++

#ifndef TEMPLATE_PRINT_CPP
#define TEMPLATE_PRINT_CPP

#include "template_print.h"

template <typename T>
void printToStream(std::ostream &os, const T &value){
    os << value;
}


#endif

```

## Q7

```bash
Template function called: Hello
Non-template function called: World
Template function called: Test
```



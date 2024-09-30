# CSE428 Studio 6

## Q1

Dijkstra Liu
Ryan Zhang


## Q2

```bash
[l.tingjun@shell studio6]$ make
g++ -o main -DUNIX   -Wall -W -g -std=c++17 -DTEMPLATE_HEADERS_INCLUDE_SOURCE main.cpp MyStruct.cpp 
main.cpp: In function ‘int main()’:
main.cpp:11:20: warning: ‘s.MyStruct::x’ is used uninitialized in this function [-Wuninitialized]
     cout << s.x << " " << s.y << endl;
                    ^~~
main.cpp:11:29: warning: ‘s.MyStruct::y’ may be used uninitialized in this function [-Wmaybe-uninitialized]
     cout << s.x << " " << s.y << endl;
                             ^
[l.tingjun@shell studio6]$ ./main
0 0               ^
```

Before adding the constructor, the program built with potential compiler warnings indicating that the member variables `x` and `y` were uninitialized, leading to random "garbage" values being printed when the program ran, since the variables took on whatever values were in memory. After adding the default constructor to initialize `x` and `y` to `0`, the program compiled cleanly without any warnings, and the output correctly showed `0 0`, as these values were explicitly set through the constructor's initialization list.

## Q3
In C++, the main difference between a **struct** and a **class** is the default access control. By default, the members of a **struct** are **public**, while the members of a **class** are **private**. When changing the declaration in the header from `struct` to `class` without adding any access specifiers, the member variables (`x` and `y`) are private, resulting in a compilation error when trying to access them in the main program. If the `public` specifier is added before the member variables, the program compiles and runs correctly, as the members are now accessible outside the class. If `protected` is used, the members are only accessible within the class and its derived classes, causing an access error when trying to access them outside the class. Finally, with `private`, the members remain inaccessible to external code, causing the same compilation error. Therefore, to make class members (variables and functions) visible outside the class, they need to be explicitly declared as `public`.

## Q4
```C++
#ifndef MyClass_H
#define MyClass_H

class MyClass
{

private:
  int x;
  int y;

public:
  MyClass();
  int getX() const;
  int getY() const;
  MyClass &setX(int x);
  MyClass &setY(int y);
};

#endif
```

```C++
#include "MyClass.h"

MyClass::MyClass() : x(0), y(0) {}

int MyClass::getX() const { return x; }

int MyClass::getY() const { return y; }

MyClass &MyClass::setX(int x)
{
  this->x = x;
  return *this;
}

MyClass &MyClass::setY(int y)
{
  this->y = y;
  return *this;
}
```

```C++
#include <iostream>
#include "MyClass.h"
using namespace std;

const int SUCCESS = 0;

int main()
{
    MyClass s;

    cout << s.getX() << " " << s.getY() << endl;

    s.setX(5).setY(10);

    cout << s.getX() << " " << s.getY() << endl;

    const MyClass cs;

    cout << cs.getX() << " " << cs.getY() << endl;

    return SUCCESS;
}

```

```bash
[l.tingjun@shell studio6]$ make
g++ -o main -DUNIX   -Wall -W -g -std=c++17 -DTEMPLATE_HEADERS_INCLUDE_SOURCE main.cpp MyClass.cpp 
[l.tingjun@shell studio6]$ ./main
0 0
5 10
0 0
```

## Q5
The default constructor initializes the member variables `x` and `y` to `0`, as seen in the output where `m.x` and `m.y` are both initially `0`. The mutator functions successfully modify these values, and their chaining works because the mutators return a reference to the current object, allowing `m.x` to be set to `7` and `m.y` to `3`. The compiler-supplied copy constructor performs a shallow copy of the member variables, resulting in `n` having the same values as `m` (`n.x = 7`, `n.y = 3`), which is appropriate in this case since `x` and `y` are primitive types.


## Q6
In this exercise, after defining a default constructor as = default; and implementing a custom copy constructor, the behavior when running the same code is similar to that with the compiler-supplied copy constructor. Both versions perform a shallow copy of the member variables, as expected for primitive types. The key difference is that, with the default constructor = default;, the member variables (x and y) are not initialized, so when the object is created, m.x contains an uninitialized (garbage) value like 4196240. This demonstrates that, unlike in the previous exercise where the copy constructor simply copied the values, the default constructor does not automatically initialize the member variables, resulting in undefined values until they are explicitly set via the mutator functions.

## Q7
When the program is built and run, the **default constructor** is first called when the object `m` is created in `main`. Then, the **copy constructor** is called twice when `m` is passed by value to the `returnByValue` function: once when the object is passed into the function, and again when the object is returned by value. After the mutator functions modify `m`, the same process occurs, with the **copy constructor** being called twice when `m` is passed and returned by value. The **copy constructor** is also called when creating `n` as a copy of `m`, and finally, it is called twice more when `n` is passed by value into the function and returned by value. This demonstrates the constructor calls during object creation, value passing, and returning.s

## Q8
If you declare the default constrctor as private but do not define it, you will not be able to create variables of that type in your main function. Since the constructor is private, it cannot be accessed outside of the class, including in main. The compiler will not supply a default constructor in this case because the constructor declaration exists but is inaccessible, and it will lead to a compilation error when you attempt to create an object of the class. Therefore, the compiler will not provide a usable default constructor, and you cannot create instances of the class from outside the class, including in main.
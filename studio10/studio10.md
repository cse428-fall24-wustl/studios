# CSE428 Studio 10

## Q1

Dijkstra Liu
Ryan Zhang


## Q2

```C++
// BaseClass.h
#ifndef BASECLASS_H
#define BASECLASS_H

#include <iostream>

class BaseClass
{
public:
    static std::size_t objectCount;

    std::size_t val;

    BaseClass();

    BaseClass(const BaseClass &other);

    ~BaseClass();
};

#endif
```

```C++
// BaseClass.cpp
#include "BaseClass.h"

using std::cout;
using std::endl;

std::size_t BaseClass::objectCount = 0;

BaseClass::BaseClass() : val(objectCount++)
{
    cout << "Default constructor for BaseClass is called. The non-static variable's value is: " << val << ", object's address is " << this << "." << endl;
}

BaseClass::BaseClass(const BaseClass &other) : val(other.val)
{
    objectCount++;
    cout << "Copy constructor for BaseClass is called. The non-static variable's value is: " << val << ", object's address is " << this << "." << endl;
}

BaseClass::~BaseClass()
{
    cout << "Destructor for BaseClass is called. The non-static variable's value is: " << val << ", object's address is " << this << "." << endl;
}
```

```C++
// main.cpp
#include <iostream>
#include "BaseClass.h"
using namespace std;

const int SUCCESS = 0;

int main()
{
    BaseClass obj1;
    BaseClass obj2(obj1);
    return SUCCESS;
}
```

```bash
[l.tingjun@iht32-1504.sif studio10]$ make
g++ -o main -DUNIX   -Wall -W -g -std=c++17 -DTEMPLATE_HEADERS_INCLUDE_SOURCE main.cpp BaseClass.cpp 
[l.tingjun@iht32-1504.sif studio10]$ ./main
Default constructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x7ffed6644a38.
Copy constructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x7ffed6644a30.
Destructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x7ffed6644a30.
Destructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x7ffed6644a38.
```

## Q3

```C++
// main.cpp
#include <iostream>
#include "BaseClass.h"
using namespace std;

const int SUCCESS = 0;

int main()
{
    BaseClass *dynamicArray = new BaseClass[3];
    delete[] dynamicArray;
    return SUCCESS;
}
```

```bash
[l.tingjun@iht32-1504.sif studio10]$ make
g++ -o main -DUNIX   -Wall -W -g -std=c++17 -DTEMPLATE_HEADERS_INCLUDE_SOURCE main.cpp BaseClass.cpp 
[l.tingjun@iht32-1504.sif studio10]$ ./main
Default constructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x2168eb8.
Default constructor for BaseClass is called. The non-static variable's value is: 1, object's address is 0x2168ec0.
Default constructor for BaseClass is called. The non-static variable's value is: 2, object's address is 0x2168ec8.
Destructor for BaseClass is called. The non-static variable's value is: 2, object's address is 0x2168ec8.
Destructor for BaseClass is called. The non-static variable's value is: 1, object's address is 0x2168ec0.
Destructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x2168eb8.
```

```C++
// main.cpp
#include <iostream>
#include "BaseClass.h"
using namespace std;

const int SUCCESS = 0;

int main()
{
    BaseClass *dynamicArray = new BaseClass[3];
    delete dynamicArray;
    return SUCCESS;
}
```

```bash
[l.tingjun@iht32-1504.sif studio10]$ make
g++ -o main -DUNIX   -Wall -W -g -std=c++17 -DTEMPLATE_HEADERS_INCLUDE_SOURCE main.cpp BaseClass.cpp 
[l.tingjun@iht32-1504.sif studio10]$ ./main
Default constructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0xa47eb8.
Default constructor for BaseClass is called. The non-static variable's value is: 1, object's address is 0xa47ec0.
Default constructor for BaseClass is called. The non-static variable's value is: 2, object's address is 0xa47ec8.
Destructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0xa47eb8.
munmap_chunk(): invalid pointer
Aborted (core dumped)
```

When using delete instead of delete[], only the destructor of the first object is called. The destructors for the remianing object are not called, causing unexpected behaviors such as memory leak and invalid access.

## Q4

```C++
// main.cpp
#include <iostream>
#include <memory>
#include "BaseClass.h"
using namespace std;

const int SUCCESS = 0;

int main()
{
    shared_ptr<BaseClass> ptr1 = make_shared<BaseClass>();
    shared_ptr<BaseClass> ptr2 = make_shared<BaseClass>(*ptr1);
    return SUCCESS;
}
```

```bash
[l.tingjun@iht32-1504.sif studio10]$ make
g++ -o main -DUNIX   -Wall -W -g -std=c++17 -DTEMPLATE_HEADERS_INCLUDE_SOURCE main.cpp BaseClass.cpp 
[l.tingjun@iht32-1504.sif studio10]$ ./main
Default constructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x748ec0.
Copy constructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x7492f0.
Destructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x7492f0.
Destructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x748ec0.
```

## Q5

```C++
// BaseClass.h
#ifndef BASECLASS_H
#define BASECLASS_H

#include <iostream>

class BaseClass
{
public:
    static std::size_t objectCount;

    std::size_t val;

    BaseClass();

    BaseClass(const BaseClass &other);

    ~BaseClass();

    void displayVal() const;
};

#endif
```

```C++
// BaseClass.cpp
#include "BaseClass.h"

using std::cout;
using std::endl;

std::size_t BaseClass::objectCount = 0;

BaseClass::BaseClass() : val(objectCount++)
{
    cout << "Default constructor for BaseClass is called. The non-static variable's value is: " << val << ", object's address is " << this << "." << endl;
}

BaseClass::BaseClass(const BaseClass &other) : val(other.val)
{
    objectCount++;
    cout << "Copy constructor for BaseClass is called. The non-static variable's value is: " << val << ", object's address is " << this << "." << endl;
}

BaseClass::~BaseClass()
{
    cout << "Destructor for BaseClass is called. The non-static variable's value is: " << val << ", object's address is " << this << "." << endl;
}

void BaseClass::displayVal() const
{
    cout << "The non-static variable's value is: " << val << ", object's address is " << this << "." << endl;
}
```

```C++
// main.cpp
#include <iostream>
#include <memory>
#include "BaseClass.h"
using namespace std;

const int SUCCESS = 0;

int main()
{
    shared_ptr<BaseClass> ptr1 = make_shared<BaseClass>();
    shared_ptr<BaseClass> ptr2 = make_shared<BaseClass>(*ptr1);

    weak_ptr<BaseClass> weakPtr = ptr1;

    shared_ptr<BaseClass> ptr3 = weakPtr.lock();

    if (ptr3 == nullptr)
    {
        cout << "The weak pointer no longer points to a valid object." << endl;
    }
    else
    {
        ptr3->displayVal();
        ptr3 = nullptr;
    }
    return SUCCESS;
}
```

```bash
[l.tingjun@iht32-1504.sif studio10]$ make
g++ -o main -DUNIX   -Wall -W -g -std=c++17 -DTEMPLATE_HEADERS_INCLUDE_SOURCE main.cpp BaseClass.cpp 
[l.tingjun@iht32-1504.sif studio10]$ ./main
Default constructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x11a9ec0.
Copy constructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x11aa2f0.
The non-static variable's value is: 0, object's address is 0x11a9ec0.
Destructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x11aa2f0.
Destructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x11a9ec0.
```

## Q6

```C++
// main.cpp
#include <iostream>
#include <memory>
#include "BaseClass.h"
using namespace std;

const int SUCCESS = 0;

int main()
{
    shared_ptr<BaseClass> ptr1 = make_shared<BaseClass>();
    shared_ptr<BaseClass> ptr2 = make_shared<BaseClass>(*ptr1);

    weak_ptr<BaseClass> weakPtr = ptr1;

    shared_ptr<BaseClass> ptr3 = weakPtr.lock();

    if (ptr3 == nullptr)
    {
        cout << "The weak pointer no longer points to a valid object." << endl;
    }
    else
    {
        ptr3->displayVal();
        ptr3 = nullptr;
    }

    cout << "Assigning ptr2 to ptr1." << endl;
    ptr1 = ptr2;
    cout << "Assignment complete." << endl;

    ptr3 = weakPtr.lock();

    if (ptr3 == nullptr)
    {
        cout << "The weak pointer no longer points to a valid object." << endl;
    }
    else
    {
        ptr3->displayVal();
    }
    return SUCCESS;
}
```

```bash
[l.tingjun@iht32-1504.sif studio10]$ make
g++ -o main -DUNIX   -Wall -W -g -std=c++17 -DTEMPLATE_HEADERS_INCLUDE_SOURCE main.cpp BaseClass.cpp 
[l.tingjun@iht32-1504.sif studio10]$ ./main
Default constructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x21f8ec0.
Copy constructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x21f92f0.
The non-static variable's value is: 0, object's address is 0x21f8ec0.
Assigning ptr2 to ptr1.
Destructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x21f8ec0.
Assignment complete.
The weak pointer no longer points to a valid object.
Destructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x21f92f0.
```

## Q7

```bash
Default constructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x15e42c0.
The non-static variable's value is: 0, object's address is 0x15e42c0.
The non-static variable's value is: 0, object's address is 0x15e42c0.
Destructor for BaseClass is called. The non-static variable's value is: 0, object's address is 0x15e42c0.
```
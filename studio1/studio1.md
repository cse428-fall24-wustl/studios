# CSE428 Studio 1

## Q1

**Participants:**

- Dijkstra Liu
- Ryan Zhang

## Q2

**Code:**

```c++
// studio1.h
#ifndef STUDIO1_H
#define STUDIO1_H

struct MyStruct {
    int value;
    MyStruct(int val);
};

#endif
```

```c++
// studio1.cpp
#include "studio1.h"
#include <iostream>

using namespace std;

const int SUCCESS = 0;

MyStruct::MyStruct(int val) : value(val) {
}

int main() {
    MyStruct myStruct1(1);
    MyStruct myStruct2(2);

    cout << myStruct1.value << " " << myStruct2.value << endl;

    return SUCCESS;
}
```

**Output:**

```bash
[l.tingjun@iht32-1506.sif studio1]$ ./studio1
1 2
```

## Q3

```c++
// studio1.h
#ifndef STUDIO1_H
#define STUDIO1_H

struct MyStruct {
    int value;
    MyStruct(int val);

    MyStruct(const MyStruct&) = delete;
    MyStruct& operator=(const MyStruct&) = delete;
    // ~MyStruct() = delete;
};

#endif
```

### Explanation:

- The `MyStruct(const MyStruct&) = delete;` and `MyStruct& operator=(const MyStruct&) = delete;` lines are kept because they don't interfere with the compilation and execution of the current code. The destructor deletion is commented out to avoid compilation errors since the destructor is needed when the objects go out of scope.

- In the main program file, we use direct initialization (`MyStruct myStruct1(1);`) rather than copy initialization, so there's no need to use the copy constructor, and hence, we can safely delete it.

### Output:

```bash
[l.tingjun@iht32-1502.sif studio1]$ ./studio1
1 2
```

## Q4

### Code:

```c++
// studio1.cpp
#include "studio1.h"
#include <iostream>
#include <algorithm> // for std::swap

using namespace std;

const int SUCCESS = 0;

MyStruct::MyStruct(int val) : value(val) {
}

int main() {
    MyStruct myStruct1(1);
    MyStruct myStruct2(2);

    cout << "Before swap: " << myStruct1.value << " " << myStruct2.value << endl;

    swap(myStruct1, myStruct2);

    cout << "After swap: " << myStruct1.value << " " << myStruct2.value << endl;

    return SUCCESS;
}
```

### Output:

```bash
[l.tingjun@iht32-1502.sif studio1]$ ./studio1
Before swap: 1 2
After swap: 2 1
```

## Q5

### Code:

```c++
// studio1.h
#ifndef STUDIO1_H
#define STUDIO1_H

struct MyStruct {
    int value;
    MyStruct(int val);

    // MyStruct(const MyStruct&) = delete;  // Commented out
    // MyStruct& operator=(const MyStruct&) = delete;  // Commented out
    // ~MyStruct() = delete;  // Commented out
};

#endif
```

### Explanation:

1. Copy Constructor (`MyStruct(const MyStruct&) = delete;`):

   - This line was **commented out**. The `std::swap` function relies on either the copy constructor or the move constructor to swap objects. If the copy constructor is deleted, `std::swap` cannot function correctly, leading to a compilation error.

2. Copy Assignment Operator (`MyStruct& operator=(const MyStruct&) = delete;`):

   - This line was also **commented out**. Similar to the copy constructor, the `std::swap` function may require the copy assignment operator or the move assignment operator to perform the swap. Deleting this operator would prevent `std::swap` from working, so it needs to be commented out.

3. Destructor (`~MyStruct() = delete;`):
   - The destructor deletion was **commented out** because it would prevent the objects from being properly destroyed when they go out of scope, which would result in a compilation error.

# Q6

```C++
// studio1.h
#ifndef STUDIO1_H
#define STUDIO1_H



template<typename T = int>
struct MyStruct {
    T value;
    MyStruct(T val);

    //MyStruct(const MyStruct&) = delete;

    //MyStruct& operator=(const MyStruct&) = delete;

    //~MyStruct() = delete;
};

#include "studio1.cpp"

#endif
```

```C++
//studio1.cpp
#include "studio1.h"
template<typename T>
MyStruct<T>::MyStruct(T val) : value(val) {}
```

```C++
//main.cpp
#include "studio1.h"
#include <iostream>
#include <algorithm>

using namespace std;

const int SUCCESS = 0;

int main() {
    MyStruct<> myStruct1(1);
    MyStruct<> myStruct2(2);

    cout << "Before swap: " << myStruct1.value << " " << myStruct2.value << endl;

    swap(myStruct1, myStruct2);

    cout << "After swap: " << myStruct1.value << " " << myStruct2.value << endl;

    return SUCCESS;
}

```

## Q7

```C++
#ifndef STUDIO1_H
#define STUDIO1_H

#include <iostream>

using std::ostream;

template<typename T>
class MyClass;

template<typename T>
ostream& operator << (ostream&, const MyClass<T>&);

template<typename T = int>
class MyClass {
	private:
		T value;

	public:
		MyClass(T val);

		friend ostream& operator << <>(ostream& os, const MyClass<T>& obj);
};

#include "studio1.cpp"

#endif
```

```C++
template<typename T>
MyClass<T>::MyClass(T val) : value(val) {}

template<typename T>
ostream& operator<<(ostream& os, const MyClass<T>& obj) {
	os << obj.value;
	return os;
}
```

```C++
#include "studio1.h"
#include <iostream>
#include <algorithm>

using namespace std;

const int SUCCESS = 0;

int main() {
    MyClass<> myClass1(1);
    MyClass<> myClass2(2);

    cout << "Before swap: " << myClass1 << " " << myClass2 << endl;

    swap(myClass1, myClass2);

    cout << "After swap: " << myClass1 << " " << myClass2 << endl;

    return SUCCESS;
}
```

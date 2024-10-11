# CSE428 Studio 11

## Q1

Dijkstra Liu
Ryan Zhang


## Q2
```C++
#ifndef MYCLASS_H
#define MYCLASS_H

#include <string>

using std::string;

class MyClass
{
private:
    string str;
};

#endif // MYCLASS_H
```
## Q3
```bash
[l.tingjun@iht32-1508.sif studio11]$ ./main
Copy constructor for MyClass is called. The string's value is: , object's address is 0x7ffdef90c680.
```

## Q4
```bash
[l.tingjun@iht32-1508.sif studio11]$ ./main
Parameterized constructor for MyClass is called. The string's value is: hello, object's address is 0x7ffe805884f0.
Copy constructor for MyClass is called. The string's value is: hello, object's address is 0x7ffe805884d0.
Destructor for MyClass is called. The string's value is: hello, object's address is 0x7ffe805884d0.
Destructor for MyClass is called. The string's value is: hello, object's address is 0x7ffe805884f0.
```

## Q5
```bash
[l.tingjun@iht32-1508.sif studio11]$ ./main
Parameterized constructor for MyClass is called. The string's value is: hello, object's address is 0x7ffc796a3410.
Parameterized constructor for MyClass is called. The string's value is: Thankyou, object's address is 0x7ffc796a33f0.
Parameterized constructor for MyClass is called. The string's value is: Goodbye, object's address is 0x7ffc796a33d0.
Assignment operator for MyClass is called. The string's value is: Thankyou, object's address is 0x7ffc796a33f0.
Assignment operator for MyClass is called. The string's value is: Goodbye, object's address is 0x7ffc796a33d0.
Destructor for MyClass is called. The string's value is: hello, object's address is 0x7ffc796a33d0.
Destructor for MyClass is called. The string's value is: hello, object's address is 0x7ffc796a33f0.
Destructor for MyClass is called. The string's value is: hello, object's address is 0x7ffc796a3410.
```
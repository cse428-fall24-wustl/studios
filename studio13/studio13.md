# CSE428 Studio 11

## Q1

Dijkstra Liu
Ryan Zhang

## Q2

```bash
[l.tingjun@shell studio13]$ ./main
Parameterized constructor for MyClass is called. The string's value is: Hello, object's address is 0x1febeb0.
The string's value is: Hello, object's address is 0x1febeb0.
The string's value is: Hello, object's address is 0x1febeb0.
Destructor for MyClass is called. The string's value is: Hello, object's address is 0x1febeb0.
```


## Q3
```C++
    unique_ptr<MyClass> ptr2(my_move(ptr));
    ptr = passUniquePtr(my_move(ptr2));
```

## Q4
```C++
    auto ptr = make_unique<MyClass>("Hello");

```


## Q5
```bash
7MyClass
```
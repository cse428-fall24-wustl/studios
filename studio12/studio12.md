# CSE428 Studio 0

## Q1

Dijkstra Liu
Ryan Zhang


## Q2

Can't make a pointer to a int point to a const int. The following code will not compile: 

```C++
int* const int_const_ptr_to_const_int = &const_int_var;
int* int_ptr_to_const_int = &const_int_var;
```

## Q3

```C++
    // ++const_int_const_ptr_to_const_int; // Not allowed because the pointer is const and cannot be changed.
    // ++const_int_const_ptr_to_int; // Not allowed for the same reason.

    // ++(*const_int_const_ptr_to_const_int); // Not allowed because it points to a const int.
    //++(*const_int_const_ptr_to_int); // Not allowed since it points to a const int.

    //++int_const_ptr_to_const_int; // Not allowed due to const restrictions on the pointer itself.
    ++(*int_const_ptr_to_int); // Allowed since the value being pointed to is non-const.

    ++const_int_ptr_to_const_int; // Allowed as it's a non-const pointer.
    // ++(*const_int_ptr_to_const_int); // Not allowed as it points to a const int.
    ++const_int_ptr_to_int; // This is allowed as the pointer itself is not const.
    //++(*const_int_ptr_to_int); // Not allowed as it points to a const int.

    // ++int_ptr_to_const_int; // Not allowed due to const restrictions on what it points to.
    ++(*int_ptr_to_int); // Allowed as it points to a non-const int.
```


## Q4

```C++
    auto auto_const_int_var = const_int_var;  // deduces int, top-level const discarded
    auto auto_int_var = int_var;             // deduces int

    auto auto_const_int_const_ptr_to_const_int = const_int_const_ptr_to_const_int;  // deduces const int*, top-level const discarded, low level const preserved
    auto auto_const_int_const_ptr_to_int = const_int_const_ptr_to_int;              // deduces const int*, top-level const discarded, low level const preserved

    auto auto_int_const_ptr_to_int = int_const_ptr_to_int;  // deduces int*, top-level const discarded

    auto auto_const_int_ptr_to_const_int = const_int_ptr_to_const_int;  // deduces const int*, low level const preserved
    auto auto_const_int_ptr_to_int = const_int_ptr_to_int;              // deduces const int*, low level const preserved

    auto auto_int_ptr_to_int = int_ptr_to_int;  // deduces int*
```


## Q5

The difference between auto and decltype is decltype do no infering and discard const


## Q6

```C++
typedef int Int;
typedef const int ConstInt;
typedef int* NonConstPtrToInt;
typedef const int* NonConstPtrToConstInt;
typedef int* const ConstPtrToNonConstInt;
typedef const int* const ConstPtrToConstInt;
```
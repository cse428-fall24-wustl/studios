#include <iostream>
#include <typeinfo>
using namespace std;

typedef int Int;
typedef const int ConstInt;
typedef int* NonConstPtrToInt;
typedef const int* NonConstPtrToConstInt;
typedef int* const ConstPtrToNonConstInt;
typedef const int* const ConstPtrToConstInt;

const int SUCCESS = 0;

int main()
{
    ConstInt const_int_var = 0;
    Int int_var = const_int_var;
    
    ConstPtrToConstInt const_int_const_ptr_to_const_int = &const_int_var;
    ConstPtrToConstInt const_int_const_ptr_to_int = &int_var;

    
    // int* const int_const_ptr_to_const_int = &const_int_var; // Not allowed because we can't have a non-const pointer point to const data.
    ConstPtrToNonConstInt int_const_ptr_to_int = &int_var;

    NonConstPtrToConstInt const_int_ptr_to_const_int = &const_int_var;
    NonConstPtrToConstInt const_int_ptr_to_int = &int_var; 
    
    // int* int_ptr_to_const_int = &const_int_var; // Not allowed for the same reason above.
    NonConstPtrToInt int_ptr_to_int = &int_var;

    cout<<"const_int_var: "<<const_int_var<<endl;
    cout<<"int_var: "<<int_var<<endl;

    cout<<"const_int_const_ptr_to_const_int address: "<<const_int_const_ptr_to_const_int<<" value: "<<*const_int_const_ptr_to_const_int<<endl;
    cout<<"const_int_const_ptr_to_int address: "<<const_int_const_ptr_to_int<<" value: "<<*const_int_const_ptr_to_int<<endl;

    // cout<<"int_const_ptr_to_const_int address: "<<int_const_ptr_to_const_int<<" value: "<<*int_const_ptr_to_const_int<<endl;
    cout<<"int_const_ptr_to_int address: "<<int_const_ptr_to_int<<" value: "<<*int_const_ptr_to_int<<endl;

    cout<<"const_int_ptr_to_const_int address: "<<const_int_ptr_to_const_int<<" value: "<<*const_int_ptr_to_const_int<<endl;
    cout<<"const_int_ptr_to_int address: "<<const_int_ptr_to_int<<" value: "<<*const_int_ptr_to_int<<endl;

    // cout<<"int_ptr_to_const_int address: "<<int_ptr_to_const_int<<" value: "<<*int_ptr_to_const_int<<endl;
    cout<<"int_ptr_to_int address: "<<int_ptr_to_int<<" value: "<<*int_ptr_to_int<<endl;

    // ++const_int_var; // Not allowed since it's declared as const.
    ++int_var; // This is allowed since int_var is not const.

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


    auto auto_const_int_var = const_int_var;  // deduces int, top-level const discarded
    auto auto_int_var = int_var;             // deduces int

    auto auto_const_int_const_ptr_to_const_int = const_int_const_ptr_to_const_int;  // deduces const int*, top-level const discarded
    auto auto_const_int_const_ptr_to_int = const_int_const_ptr_to_int;              // deduces const int*, top-level const discarded

    auto auto_int_const_ptr_to_int = int_const_ptr_to_int;  // deduces int*

    auto auto_const_int_ptr_to_const_int = const_int_ptr_to_const_int;  // deduces const int*
    auto auto_const_int_ptr_to_int = const_int_ptr_to_int;              // deduces const int*

    auto auto_int_ptr_to_int = int_ptr_to_int;  // deduces int*

    ++auto_const_int_var;
    ++auto_int_var;

    ++auto_const_int_const_ptr_to_const_int; // Allowed because the low-level const is discarded.
    //++(*auto_const_int_const_ptr_to_int); // Not allowed since it points to a const int.

    ++auto_const_int_const_ptr_to_int; //Allowed because the low-level const is discarded.
    //++(*auto_const_int_const_ptr_to_int); // Not allowed because the value being pointed to is const int.

    ++auto_int_const_ptr_to_int; // Allowed because the value being pointed to is non-const.
    ++(*auto_int_const_ptr_to_int); // Allowed because the value being pointed to is non-const.

    std::cout << "Type of auto_int_const_ptr_to_int: " << typeid(auto_int_const_ptr_to_int).name() << std::endl;

    ++auto_const_int_ptr_to_const_int; // Allowed because the low-level const is discarded.
    //++(*auto_const_int_ptr_to_const_int); // Not allowed because it points to a const int.

    ++auto_const_int_ptr_to_int; // Allowed because the low-level const is discarded.
    //++(*auto_const_int_ptr_to_int); // Not allowed because it points to a const int.

    std::cout << "Type of auto_const_int_ptr_to_const_int: " << typeid(auto_const_int_ptr_to_const_int).name() << std::endl;
    std::cout << "Type of auto_const_int_ptr_to_int: " << typeid(auto_const_int_ptr_to_int).name() << std::endl;

    ++auto_int_ptr_to_int; // Allowed because the value being pointed to is non-const.
    ++(*auto_int_ptr_to_int); // Allowed because the value being pointed to is non-const.s

    std::cout << "Type of auto_int_ptr_to_int: " << typeid(auto_int_ptr_to_int).name() << std::endl;

    decltype(const_int_var) decltype_const_int_var = const_int_var;  // deduces const int
    decltype(int_var) decltype_int_var = int_var;                   // deduces int

    decltype(const_int_const_ptr_to_const_int) decltype_const_int_const_ptr_to_const_int = const_int_const_ptr_to_const_int;  // deduces const int* const
    decltype(const_int_const_ptr_to_int) decltype_const_int_const_ptr_to_int = const_int_const_ptr_to_int;                    // deduces const int* const

    decltype(int_const_ptr_to_int) decltype_int_const_ptr_to_int = int_const_ptr_to_int;  // deduces int* const

    decltype(const_int_ptr_to_const_int) decltype_const_int_ptr_to_const_int = const_int_ptr_to_const_int;  // deduces const int*
    decltype(const_int_ptr_to_int) decltype_const_int_ptr_to_int = const_int_ptr_to_int;                    // deduces const int*

    decltype(int_ptr_to_int) decltype_int_ptr_to_int = int_ptr_to_int;

    //++decltype_const_int_var;
    ++decltype_int_var;

    //++decltype_const_int_const_ptr_to_const_int; // Not allowed because the pointer is const.
    //++(*decltype_const_int_const_ptr_to_const_int); // Not allowed because it points to a const int.

    //++decltype_const_int_const_ptr_to_int; // Not allowed because the pointer is const.
    //++(*decltype_const_int_const_ptr_to_int); // Not allowed because it points to a const int.

    //++decltype_int_const_ptr_to_int; // Not allowed because the value being pointed to is const.
    ++(*decltype_int_const_ptr_to_int); // Allowed because the value being pointed to is non-const.

    ++decltype_const_int_ptr_to_const_int; // Allowed because the pointer is non-const.
    //++(*decltype_const_int_ptr_to_const_int); // Not allowed because it points to a const int.

    ++decltype_const_int_ptr_to_int; // Allowed because the pointer is non-const.
    //++(*decltype_const_int_ptr_to_int); // Not allowed because it points to a const int.

    ++decltype_int_ptr_to_int; // Allowed because the value being pointed to is non-const.
    return SUCCESS;
}

#include <iostream>
#include "MyClass.h"
#include <memory>
using namespace std;

const int SUCCESS = 0;

unique_ptr<MyClass> passUniquePtr(unique_ptr<MyClass> ptr)
{
    ptr->displayVal();
    return ptr;
}

int main()
{
    unique_ptr<MyClass> ptr(new MyClass("Hello"));
    unique_ptr<MyClass> ptr2(move(ptr));
    ptr = passUniquePtr(move(ptr2));
    ptr->displayVal();
    return SUCCESS;
}

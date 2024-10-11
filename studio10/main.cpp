// main.cpp
#include <iostream>
#include <memory>
#include "BaseClass.h"
using namespace std;

const int SUCCESS = 0;

unique_ptr<BaseClass> createUniquePtr()
{
    unique_ptr<BaseClass> ptr(new BaseClass());
    return ptr;
}

void passUniquePtr(unique_ptr<BaseClass> &ptr)
{
    ptr->displayVal();
}

int main()
{
    unique_ptr<BaseClass> ptr = createUniquePtr();
    passUniquePtr(ptr);
    ptr->displayVal();
    return SUCCESS;
}

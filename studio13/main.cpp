#include <iostream>
#include "MyClass.h"
#include "template_move.h"
#include <memory>
#include <typeinfo>
#include <type_traits>
using namespace std;

const int SUCCESS = 0;

unique_ptr<MyClass> passUniquePtr(unique_ptr<MyClass> ptr)
{
    ptr->displayVal();
    return ptr;
}

int main()
{
    auto ptr = make_unique<MyClass>("Hello");

    std::remove_reference<decltype(*ptr)>::type v("Hello");

    cout<< typeid(v).name()<<endl;

    unique_ptr<MyClass> ptr2(my_move(ptr));
    ptr = passUniquePtr(my_move(ptr2));
    ptr->displayVal();
    return SUCCESS;
}

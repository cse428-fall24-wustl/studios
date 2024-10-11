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
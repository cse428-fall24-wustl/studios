#include "BaseClass.h"

using std::cout;
using std::endl;

BaseClass::BaseClass() : str("BaseClass")
{
    cout << "BaseClass default constructor" << endl;
}

BaseClass::~BaseClass()
{
    cout << "BaseClass destructor" << endl;
}

void BaseClass::display()
{
    cout << "BaseClass display" << endl;
}

const std::string BaseClass::*BaseClass::getStrPtr()
{
    return &BaseClass::str;
}

void (BaseClass::*BaseClass::getDisplayPtr())()
{
    return &BaseClass::display;
}
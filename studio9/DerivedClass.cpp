#include "DerivedClass.h"

using std::cout;
using std::endl;

DerivedClass::DerivedClass() : BaseClass()
{
    cout << "DerivedClass default constructor" << endl;
}

DerivedClass::~DerivedClass()
{
    cout << "DerivedClass destructor" << endl;
}

void DerivedClass::display()
{
    cout << "DerivedClass display" << endl;
}

const std::string DerivedClass::*DerivedClass::getDerivedStrPtr()
{
    return &DerivedClass::Derstr;
}

void (DerivedClass::*DerivedClass::getDisplayPtr())()
{
    return &DerivedClass::display;
}
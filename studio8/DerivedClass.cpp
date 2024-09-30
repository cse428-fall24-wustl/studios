#include "DerivedClass.h"

using std::cout;
using std::endl;

DerivedClass::DerivedClass()
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
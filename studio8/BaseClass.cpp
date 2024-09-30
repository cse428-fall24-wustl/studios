#include "BaseClass.h"

using std::cout;
using std::endl;

BaseClass::BaseClass()
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
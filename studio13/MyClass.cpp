#include "MyClass.h"

MyClass::MyClass(const MyClass &other) : str(other.str)
{
    cout << "Copy constructor for MyClass is called. The string's value is: " << str << ", object's address is " << this << "." << endl;
}

MyClass::MyClass(const string &str) : str(str)
{
    cout << "Parameterized constructor for MyClass is called. The string's value is: " << str << ", object's address is " << this << "." << endl;
}

MyClass::~MyClass()
{
    cout << "Destructor for MyClass is called. The string's value is: " << str << ", object's address is " << this << "." << endl;
}

MyClass &MyClass::operator=(const MyClass &other)
{
    cout << "Assignment operator for MyClass is called. The string's value is: " << str << ", object's address is " << this << "." << endl;
    str = other.str;
    return *this;
}

void MyClass::displayVal() const
{
    cout << "The string's value is: " << str << ", object's address is " << this << "." << endl;
}
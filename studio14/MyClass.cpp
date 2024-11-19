#include "MyClass.h"

MyClass::MyClass(const string &other) : str(other){}

// bool MyClass::operator < (const MyClass &rhs) const {
//     return str < rhs.str;
// }

ostream& operator<<(ostream &os, const MyClass &myClass)
{
    os << myClass.str;
    return os;
}

bool operator < (const MyClass &lhs, const MyClass & rhs) {
    return lhs.str < rhs.str;
}
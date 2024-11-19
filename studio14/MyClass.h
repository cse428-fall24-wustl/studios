#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::ostream;

class MyClass
{
    private:
        string str;
    public:
        MyClass(const string &other);
        friend ostream& operator<< (ostream &os, const MyClass &myClass);
        bool operator < (const MyClass &rhs) const;
        friend bool operator < (const MyClass &lhs, const MyClass &rhs);

};

#endif
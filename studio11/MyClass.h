#ifndef MYCLASS_H
#define MYCLASS_H

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class MyClass
{
private:
    string str;

public:
    MyClass(const MyClass &other);
    MyClass(const string &str);
    MyClass &operator=(const MyClass &other);
    ~MyClass();
    virtual void displayVal() const;
};

#endif // MYCLASS_H
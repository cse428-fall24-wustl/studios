#ifndef BASECLASS_H
#define BASECLASS_H

#include <iostream>

class BaseClass
{
public:
    BaseClass();
    virtual ~BaseClass();

    void display();

    static const std::string BaseClass::*getStrPtr();

    static void (BaseClass::*getDisplayPtr())();

private:
    std::string str;
};

#endif
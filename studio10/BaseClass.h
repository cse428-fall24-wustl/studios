// BaseClass.h
#ifndef BASECLASS_H
#define BASECLASS_H

#include <iostream>

class BaseClass
{
public:
    static std::size_t objectCount;

    std::size_t val;

    BaseClass();

    BaseClass(const BaseClass &other);

    ~BaseClass();

    void displayVal() const;
};

#endif
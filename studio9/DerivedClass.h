#ifndef DERIVEDCLASS_H
#define DERIVEDCLASS_H

#include "BaseClass.h"

class DerivedClass : public BaseClass
{
public:
    DerivedClass();
    virtual ~DerivedClass();

    void display();

    static const std::string DerivedClass::*getDerivedStrPtr();

    static void (DerivedClass::*getDisplayPtr())();

private:
    std::string Derstr;
};

#endif
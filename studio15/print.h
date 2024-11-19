#ifndef PRINT_H
#define PRINT_H

#include "MyClass.h"
#include <iostream>

namespace CustomPrint {

    // Non-template function declaration and definition
    void printToStream(std::ostream &os, const MyClass &value);

}

#endif
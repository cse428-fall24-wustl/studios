#ifndef PRINT_OVERLOADS_H
#define PRINT_OVERLOADS_H

#include <iostream>
#include <string>
#include "MyClass.h"

void printToStream(std::ostream &os, const std::string &value);

void printToStream(std::ostream &os, const char * const value);

void printToStream(std::ostream &os, const MyClass &value);

#endif

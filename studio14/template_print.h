#ifndef TEMPLATE_PRINT_H
#define TEMPLATE_PRINT_H

#include <iostream>

using std::ostream;

template <typename T>
void printToStream(std::ostream &os, const T &value);

#include "template_print.cpp"

#endif
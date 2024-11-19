#ifndef TEMPLATE_PRINT_H
#define TEMPLATE_PRINT_H

#include <iostream>

using std::ostream;

template <typename T>
void printToStream(std::ostream &os, const T &value);

template <typename T, typename... Args>
void printToStream(std::ostream &os, const T &value, const Args&... args);

template <typename... Args>
void countAndPrintToStream(std::ostream &os, const Args&... args);

template <typename T>
const T& measureSize(const T& value);

#include "template_print.cpp"

#endif
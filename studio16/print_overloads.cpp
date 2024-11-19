#include "print_overloads.h"


void printToStream(std::ostream &os, const std::string &value) {
    os << "\"" << value << "\" ";
}

void printToStream(std::ostream &os, const char * const value) {
    os << "[" << value << " " << reinterpret_cast<const void*>(value) << "] ";
}

void printToStream(std::ostream &os, const MyClass &value) {
    os << "{" << value << " " << &value << "} ";
}
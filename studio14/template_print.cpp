#ifndef TEMPLATE_PRINT_CPP
#define TEMPLATE_PRINT_CPP

#include "template_print.h"

template <typename T>
void printToStream(std::ostream &os, const T &value){
    os << "Template function called: " << value;
}


#endif
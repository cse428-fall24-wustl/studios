#ifndef TEMPLATE_UTILS_CPP
#define TEMPLATE_UTILS_CPP

#include "template_utils.h"

template <typename T>
void printArray(T start, T end) {
    for (T ptr = start; ptr != end ; ++ptr) {
        std::cout<<*ptr<<" ";
    }
    std::cout<<std::endl;
    return ;
}

#endif

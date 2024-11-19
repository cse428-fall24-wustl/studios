#ifndef TEMPLATE_PRINT_CPP
#define TEMPLATE_PRINT_CPP

#include "template_print.h"

static unsigned int count = 0;

template <typename T>
void printToStream(std::ostream &os, const T &value){
    os<< value << " ";
}

template <typename T, typename... Args>
void printToStream(std::ostream &os, const T &value, const Args&... args){
    os<< value << " ";
    printToStream(os, args...);
}

template <typename T>
const T& measureSize(const T& value){
    count+=sizeof(value);
    return value;
}


template <typename... Args>
void countAndPrintToStream(std::ostream &os, const Args&... args){
    cout << "Number of arguments: " << sizeof...(args) << std::endl;
    printToStream(os, measureSize(args)...);
    cout << "Total size: " << count << std::endl;
}

#endif
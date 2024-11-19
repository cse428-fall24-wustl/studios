#ifndef TEMPLATE_PRINT_CPP
#define TEMPLATE_PRINT_CPP

#include "template_print.h"

static unsigned int count = 0; // Total byte count
static unsigned int intByteCount = 0; // Count for int variables
static unsigned int floatByteCount = 0; 

template <typename T>
void printToStream(std::ostream &os, const T &value){
    os<< value << " ";
}

// template <>
// void printToStream(std::ostream &os, const std::string &value){
//     os<< "\""<< value << " \"";
// }


template <typename T, typename... Args>
void printToStream(std::ostream &os, const T &value, const Args&... args){
    printToStream(os, value);
    printToStream(os, args...);
}

template <typename... Args>
void printToStream(std::ostream &os, const std::string &value, const Args&... args){
    os<< "\""<< value << "\" ";
    printToStream(os, args...);
}

template <typename... Args>
void printToStream(std::ostream &os, const char * const value, const Args&... args) {
    os << "[" << value << " " << reinterpret_cast<const void*>(value) << "] ";
    printToStream(os, args...);
}

template <typename... Args>
void printToStream(std::ostream &os, const MyClass &value, const Args&... args) {
    os << "{" << value << " " << &value << "} ";
    printToStream(os, args...);
}


template <typename T>
const T& measureSize(const T& value) {
    count += sizeof(value);
    return value;
}

template <>
const int& measureSize(const int& value) {
    count += sizeof(value);
    intByteCount += sizeof(value);
    return value;
}


template <>
const float& measureSize(const float& value) {
    count += sizeof(value);
    floatByteCount += sizeof(value);
    return value;
}


template <typename... Args>
void countAndPrintToStream(std::ostream &os, const Args&... args){
    os << "Number of arguments: " << sizeof...(args) << std::endl;
    printToStream(os, measureSize(args)...);
    os << "\nTotal size: " << count << " bytes\n";
    os << "Total int size: " << intByteCount << " bytes\n";
    os << "Total float size: " << floatByteCount << " bytes\n";
    os << "Total size of other types: " << (count - intByteCount - floatByteCount) << " bytes\n";
}

#endif
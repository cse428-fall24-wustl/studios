#include <iostream>
#include "MyClass.h"
#include "template_print.h"
#include "print_overloads.h"
using namespace std;

const int SUCCESS = 0;

int main()
{
    string s = "Hello";
    const char* c= "World";
    MyClass MyClass("!");
    int i = 42;
    float f = 5.0/2;

    // printToStream(cout, s);
    // printToStream(cout, c);
    // printToStream(cout, MyClass);
    // printToStream(cout, i);
    //printToStream(cout, f);

    countAndPrintToStream(cout, s, c, MyClass, i, f);

    return SUCCESS;
}

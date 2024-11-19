#include <iostream>
#include "MyClass.h"
#include "template_print.h"
#include "print.h"
using namespace std;

const int SUCCESS = 0;

int main()
{

    MyClass myClass1("Hello");
    MyClass myClass2("World");
    //cout << myClass1 << " " << myClass2 << endl;
    printToStream(cout, myClass1);
    cout << endl;
    CustomPrint::printToStream(cout, myClass2);
    cout << endl;
    printToStream(cout, "Test");
    return SUCCESS;
}

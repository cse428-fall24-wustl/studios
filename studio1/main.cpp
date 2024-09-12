#include "studio1.h"
#include <iostream>
#include <algorithm>

using namespace std;

const int SUCCESS = 0;

int main() {
    MyClass<> myClass1(1);
    MyClass<> myClass2(2);

    cout << "Before swap: " << myClass1 << " " << myClass2 << endl;

    swap(myClass1, myClass2);

    cout << "After swap: " << myClass1 << " " << myClass2 << endl;

    return SUCCESS;
}

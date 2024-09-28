#include <iostream>
#include "MyClass.h"
using namespace std;

const int SUCCESS = 0;

int main()
{
    MyClass m;

    cout << "m.x is " << m.x() << " and m.y is " << m.y() << endl;

    m.returnByValue(m);

    m.x(7).y(3);

    m.returnByValue(m);

    cout << "m.x is " << m.x() << " and m.y is " << m.y() << endl;

    MyClass n(m);

    n.returnByValue(n);

    cout << "n.x = " << n.x() << " and n.y = " << n.y() << endl;

    return SUCCESS;
}

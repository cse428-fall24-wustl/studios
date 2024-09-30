#include <iostream>
#include "DerivedClass.h"
#include <memory>
using namespace std;

const int SUCCESS = 0;

int main()
{

    BaseClass *base1 = new BaseClass();
    BaseClass *base2 = new DerivedClass();
    DerivedClass *derived = new DerivedClass();

    base1->display();
    base2->display();
    derived->display();

    cout << "--- deleting base1 ---" << endl;
    delete base1;

    cout << "--- deleting base2 ---" << endl;
    delete base2;

    cout << "--- deleting derived ---" << endl;
    delete derived;

    cout << "--- End of main ---" << endl;
    return SUCCESS;
}

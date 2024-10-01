#include <iostream>
#include "DerivedClass.h"
#include <memory>
#include <functional>
using namespace std;

const int SUCCESS = 0;

int main()
{
    BaseClass base;
    DerivedClass derived;

    function<void(BaseClass &)> func1 = mem_fn(&BaseClass ::display);
    function<void(BaseClass &)> func2 = mem_fn(&BaseClass ::display);
    function<void(DerivedClass &)> func3 = mem_fn(&DerivedClass ::display);

    func1(base);
    func2(derived);
    func3(derived);

    cout << "--- End of main ---" << endl;
    return SUCCESS;
}

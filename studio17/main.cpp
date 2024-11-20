#include <iostream>
#include "template_utils.h"
#include <vector>
#include <deque>
#include <list>
using namespace std;

const int SUCCESS = 0;

int main()
{
    int arr[] = {1,2,3,4,5};

    cout << "Size of array: " << sizeof(arr) << " bytes" << endl;

    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
        
    int *endPtr = arr + (sizeof(arr)/sizeof(int));

    printArray(arr, endPtr);

    vector<int> v;
    deque<int> d;
    list<int> l;

    for (int *ptr = arr; ptr != endPtr; ++ptr) {
        v.emplace_back(*ptr);
        d.emplace_back(*ptr);
        l.emplace_back(*ptr);
    }

    printArray(v.begin(), v.end());
    printArray(d.begin(), d.end());
    printArray(l.begin(), l.end());

    vector<int>::iterator ptr1 = v.begin() + 1;

    printArray(v.begin(), ptr1);
    printArray(ptr1, v.end());

    vector<int>::iterator ptr2 = v.begin() + (v.end() - v.begin())/2;

    printArray(v.begin(), ptr2);
    printArray(ptr2, v.end());

    cout << "Array: " << arr[0] << endl; // Should work
    cout << "Deque: " << d[0] << endl;       // Should work
    cout << "Vector: " << v[0] << endl;     // Should work
    //cout << "List: " << l[0] << endl;    // Will NOT compile

    return SUCCESS;
}

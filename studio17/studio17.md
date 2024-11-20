# CSE428 Studio 17

## Q1

Dijkstra Liu
Ryan Zhang


## Q2
```bash
Size of array: 20 bytes
Size of int: 4 bytes
```

```C++
#include <iostream>
using namespace std;

const int SUCCESS = 0;

int main()
{
    int arr[] = {1,2,3,4,5};

    cout << "Size of array: " << sizeof(arr) << " bytes" << endl;

    cout << "Size of int: " << sizeof(int) << " bytes" << endl;


    return SUCCESS;
}

```

## Q3
```bash
Size of array: 20 bytes
Size of int: 4 bytes
1 2 3 4 5
```

```C++
        
int *endPtr = arr + (sizeof(arr)/sizeof(int));

for (int *ptr = arr; ptr != endPtr; ptr++)
{
    cout << *ptr << " ";
}

```


## Q4
```C++
template <typename T>
void printArray(T start, T end) {
    for (T ptr = start; ptr != end ; ++ptr) {
        std::cout<<*ptr<<" ";
    }
    std::cout<<std::endl;
    return ;
}

printArray(arr, endPtr);
```


## Q5
```bash
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
```


## Q6
```bash
1 
2 3 4 5 
1 2 
3 4 5 
```


## Q7
Containers that support []: C-style arrays, std::vector, std::deque.
Containers that do not support []: std::list, because it is not a random-access container and does not store elements contiguously.
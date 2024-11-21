# CSE428 Studio 18

## Q1

Dijkstra Liu
Ryan Zhang


## Q2

```C++
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

const int SUCCESS = 0;

int main()
{
    int arr[] = {-2, 19, 80, -47, 80, 80, -2, 19, 19};

    int *start = arr;
    int *end = arr + sizeof(arr) / sizeof(arr[0]);

    std::copy(start, end, std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;

    return SUCCESS;
}

```
```bash
[l.tingjun@shell studio18]$ ./studio18
-2 19 80 -47 80 80 -2 19 19 
```

## Q3

```C++
    std::vector<int> vec;

    std::back_insert_iterator<std::vector<int> > back_it = std::back_inserter(vec);

    std::copy(start, end, back_it);

    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));

```

```bash
-2 19 80 -47 80 80 -2 19 19
```

## Q4

```C++
    std::sort(vec.begin(), vec.end());

    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
```

```bash
-47 -2 -2 19 19 19 80 80 80
```

## Q5

```C++
    while (it != end)
    {
        it = std::adjacent_find(it, end);
        if (it == end)
        {
            break;
        }
        int cur = *it;
        do
        {
            std::cout << *it << " ";
            ++it;
        }
        while (it != end && *it == cur);
        std::cout << std::endl;
    }
```

```bash
-2 -2 
19 19 19 
80 80 80 
```

## Q6

```C++
    std::sort(start, end, std::greater<int>());

    std::copy(start, end, std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;
```

```bash
80 80 80 19 19 19 -2 -2 -2
``` 


## Q7
```C++

    int median = *(arr + sizeof(arr) / sizeof(arr[0]) / 2);
    std::cout << "Median: " << median << std::endl;

    float mean = static_cast<float>(std::accumulate(start, end, 0)) / (sizeof(arr) / sizeof(arr[0]));
    std::cout << "Mean: " << mean << std::endl;

    int mode = arr[0];
    int maxCount = 0;

    it = start;
    while (it != end) {
        int current = *it;
        int count = std::count(it, end, current);

        if (count > maxCount) {
            maxCount = count;
            mode = current;
        }

        it += count;
    }

    std::cout << "Mode: " << mode << std::endl;
```
```bash
Median: 19
Mean: 27.3333
Mode: 80
```
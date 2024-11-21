# CSE428 Studio 19

## Q1

Dijkstra Liu
Ryan Zhang


## Q2

```bash
./studio19 hello 1234 1234
./studio19
1234
hello
```

Set is sorted and unique, so it will only print out 1234 and hello and studio.


## Q3

```bash
./studio19 hello 1234 1234
./studio19
hello
1234
1234
```

Set of char* will sort by the address of the string, so it will print 1234 twice since they have different addresses.

## Q4

```C++
#include "string_order.h"


bool reverseStringOrder(const std::string& s1, const std::string& s2) {
    return s1 > s2;
}
```

```bash
Contents of the set (reverse order):
hello
1234
./studio19
```

## Q5

```bash
Contents of the set (reverse order):
hello
1234
1234
./studio19
```

The multiset will able to store duplicates, so it will print 1234 twice.


## Q6

```C++
    std::multiset<std::string> stringSet;

    std::copy(argv, argv + argc, std::inserter(stringSet, stringSet.begin()));

    std::cout << "Contents of the multiset:" << std::endl;
    std::copy(stringSet.begin(), stringSet.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
    std::cout << std::endl;


    string target ="1234";

    auto range = stringSet.equal_range(target);

    std::cout << "Occurrences of \"" << target << "\":" << std::endl;
    std::copy(range.first, range.second, std::ostream_iterator<std::string>(std::cout, "\n"));
```

```bash
Contents of the multiset:
./studio19
1234
1234
1234
hello

Occurrences of "1234":
1234
1234
1234
```


## Q7

The first variation erase the first "1234", the second variation erase all "1234" in the multiset.

```bash
Contents of the multiset after erasing the first occurrence of "1234":
./studio19
1234
1234
hello

Contents of the multiset after erasing all occurrences of "1234":
./studio19
hello
```

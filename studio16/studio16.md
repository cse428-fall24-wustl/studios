# CSE428 Studio 16

## Q1

Dijkstra Liu
Ryan Zhang


## Q2
```bash
template_print.cpp:16:6: error: ambiguous template specialization ‘printToStream<>’ for ‘void printToStream(std::ostream&, const string&)’
 void printToStream(std::ostream &os, const std::string &value) 
```

the compiler don't know which function to call because the template function is ambiguous. The compiler can't decide which function to call because both functions are equally good matches.

## Q3
```C++
template <typename... Args>
void printToStream(std::ostream &os, const std::string &value, const Args&... args);

template <typename... Args>
void printToStream(std::ostream &os, const std::string &value, const Args&... args){
    os<< "\""<< value << "\" ";
    printToStream(os, args...);
}

#ifndef PRINT_OVERLOADS_H
#define PRINT_OVERLOADS_H

#include <iostream>
#include <string>

void printToStream(std::ostream &os, const std::string &value);

#endif

#include "print_overloads.h"


void printToStream(std::ostream &os, const std::string &value) {
    os << "\"" << value << "\" ";
}
```

```bash
[l.tingjun@shell studio16]$ ./main
Number of arguments: 5
"Hello" World ! 42 2.5 Total size: 80
```

## Q4
```bash
[l.tingjun@shell studio16]$ ./main
Number of arguments: 5
"Hello" [World 0x403222] ! 42 2.5 Total size: 80
```

### Q5
```bash
[l.tingjun@shell studio16]$ ./main
Number of arguments: 5
"Hello" [World 0x403292] {! 0x7ffdd0821d30} 42 2.5 Total size: 80
```

### Q6
```bash
[l.tingjun@shell studio16]$ ./main
Number of arguments: 5
"Hello" [World 0x403352] {! 0x7ffeb2325d70} 42 2.5 
Total size: 80 bytes
Total int size: 4 bytes
Total float size: 4 bytes
Total size of other types: 72 bytes
```
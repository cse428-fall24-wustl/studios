# CSE428 Studio 15

## Q1

Dijkstra Liu
Ryan Zhang


## Q2

```bash
Hello World ! 42 2.5
```

## Q3
```C++
template <typename T>
void printToStream(std::ostream &os, const T &value);

template <typename T, typename... Args>
void printToStream(std::ostream &os, const T &value, const Args&... args);



template <typename T>
void printToStream(std::ostream &os, const T &value){
    os<< value << " ";
}

template <typename T, typename... Args>
void printToStream(std::ostream &os, const T &value, const Args&... args){
    os<< value << " ";
    printToStream(os, args...);
}


printToStream(cout, s, c, MyClass, i, f);

```


## Q4
```bash
l.tingjun@shell studio15]$ ./main
Number of arguments: 5
Hello World ! 42 2.5

```

## Q5
```bash
Number of arguments: 5
Hello World ! 42 2.5 
Total size: 80
```


# CSE428 Studio 0

## Q1

Dijkstra Liu
Ryan Zhang
Zheyuan Wu

## Q2

iht32-1506.engr.wustl.edu

## Q3

### which g++:

```bash
/project/compute/compilers/gcc-8.3.0/bin/g++
```

### g++ -v:

```bash
Using built-in specs.
COLLECT_GCC=g++
COLLECT_LTO_WRAPPER=/project/engineering/compilers/gcc-8.3.0/bin/../libexec/gcc/x86_64-pc-linux-gnu/8.3.0/lto-wrapper
Target: x86_64-pc-linux-gnu
Configured with: ../gcc-8.3.0/configure --prefix=/project/compute/compilers/gcc-8.3.0 --enable-languages=c,c++,fortran,go --disable-multilib
Thread model: posix
gcc version 8.3.0 (GCC)
```

## Q4

hello, world!

## Q5

### with arguments

```bash
[l.tingjun@iht32-1506.sif studio0]$ ./studio0 1 2
3
```

### with no arguments

```bash
[l.tingjun@iht32-1506.sif studio0]$ ./studio0
usage: studio0 <number1> <number2>
```

## Q6

### correct arguments

```
[l.tingjun@iht32-1506.sif studio0]$ ./studio0 1 2 1.txt
[l.tingjun@iht32-1506.sif studio0]$ cat 1.txt
3
```

### wrong arguments

```
[l.tingjun@iht32-1506.sif studio0]$ ./studio0 1 2
usage: studio0 <number1> <number2> <filename>
```

### not authorized

```bash
[l.tingjun@iht32-1506.sif studio0]$ chmod a-w 1.txt
[l.tingjun@iht32-1506.sif studio0]$ ./studio0 1 2 1.txt
Error opening file: 1.txt for writing
```

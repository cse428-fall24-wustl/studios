# CSE428 Studio 3

## Q1

**Participants:**

- Dijkstra Liu
- Ryan Zhang

## Q2
```bash
[l.tingjun@shell studio3]$ ./studio3 + 3 + 4 3
The value calculated is 10
[l.tingjun@shell studio3]$ echo $?
0
[l.tingjun@shell studio3]$ ./studio3 + 3 +  300
caught exception for unexpected end of expression.
[l.tingjun@shell studio3]$ echo $?
2
```

## Q3
```bash
[l.tingjun@shell studio3]$ gdb studio3
GNU gdb (GDB) Rocky Linux 8.2-20.el8.0.1
Copyright (C) 2018 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from studio3...done.
(gdb) 
```

## Q4
```bash
(gdb) break parse_and_compute
Breakpoint 1 at 0x401b71: file studio3.cpp, line 103.
(gdb) 
```

## Q5
```bash
(gdb) run + 1 + 2 + 3 4
Starting program: /home/warehouse/l.tingjun/cse428_fall24/studios/studio3/studio3 + 1 + 2 + 3 4

Breakpoint 1, parse_and_compute (current_index=@0x7fffffffc974: 1, last_index=7, argv=0x7fffffffca78) at studio3.cpp:103
103         if (current_index > last_index)
Missing separate debuginfos, use: yum debuginfo-install libgcc-8.5.0-22.el8_10.x86_64 libstdc++-8.5.0-22.el8_10.x86_64
(gdb) continue
Continuing.

Breakpoint 1, parse_and_compute (current_index=@0x7fffffffc974: 2, last_index=7, argv=0x7fffffffca78) at studio3.cpp:103
103         if (current_index > last_index)
```

## Q6
```bash
(gdb) where
#0  parse_and_compute (current_index=@0x7fffffffc974: 2, last_index=7, argv=0x7fffffffca78) at studio3.cpp:103
#1  0x0000000000401c30 in parse_and_compute (current_index=@0x7fffffffc974: 2, last_index=7, argv=0x7fffffffca78) at studio3.cpp:114
#2  0x00000000004019d4 in main (argc=8, argv=0x7fffffffca78) at studio3.cpp:53
```

## Q7
```bash
(gdb) print current_index
$7 = (int &) @0x7fffffffc974: 2
(gdb) print argv[2]
$8 = 0x7fffffffcf1c "1"
```
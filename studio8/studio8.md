# CSE428 Studio 8

## Q1

Dijkstra Liu
Ryan Zhang

## Q2
```bash
[l.tingjun@shell studio8]$ ./main
BaseClass default constructor
BaseClass default constructor
DerivedClass default constructor
DerivedClass destructor
BaseClass destructor
BaseClass destructor
```
During constructing, the base class only call bsclass constructor once. For derived class, it will firstly call base class constructor and then Derived class.

During dstrcuting, since derived class declares secondly it will destrcut first by stack order. it will also call derived class destructor first and then base class.

## Q3
```bash
[l.tingjun@shell studio8]$ ./main
BaseClass default constructor
BaseClass default constructor
DerivedClass default constructor

--- Invoking display on objects ---
Calling BaseClass::display() on baseObj:
BaseClass display
Calling DerivedClass::display() on derivedObj:
DerivedClass display

--- Invoking display on references ---
Calling BaseClass::display() on refBase1:
BaseClass display
Calling BaseClass::display() on refBase2:
BaseClass display
Calling DerivedClass::display() on refDerived:
DerivedClass display
DerivedClass destructor
BaseClass destructor
BaseClass destructor
```

## Q4
```bash
[l.tingjun@shell studio8]$ ./main
BaseClass default constructor
BaseClass default constructor
DerivedClass default constructor

--- Invoking display on objects ---
Calling BaseClass::display() on baseObj:
BaseClass display
Calling DerivedClass::display() on derivedObj:
DerivedClass display

--- Invoking display on references ---
Calling BaseClass::display() on refBase1:
BaseClass display
Calling BaseClass::display() on refBase2:
DerivedClass display
Calling DerivedClass::display() on refDerived:
DerivedClass display
DerivedClass destructor
BaseClass destructor
BaseClass destructor
```

Calling BaseClass::display() on refBase2 become derivedClass, that is because virtual function will lead dynamic binding, bind DerivedClass in the run time.

## Q5
They are same, I think this is because virtual function support runtime motipolism for both pointers and references.

## Q6
```bash
[l.tingjun@shell studio8]$ ./main
BaseClass default constructor
BaseClass default constructor
DerivedClass default constructor
BaseClass default constructor
DerivedClass default constructor
BaseClass display
DerivedClass display
DerivedClass display
--- End of main ---
DerivedClass destructor
BaseClass destructor
DerivedClass destructor
BaseClass destructor
BaseClass destructor
```

## Q7
```bash
[l.tingjun@shell studio8]$ ./main
BaseClass default constructor
BaseClass default constructor
DerivedClass default constructor
BaseClass default constructor
DerivedClass default constructor
BaseClass display
DerivedClass display
DerivedClass display
--- End of main ---
```
Destructor never calledm shows that the heap is never clean up.

## Q8

```bash
[l.tingjun@shell studio8]$ ./main
BaseClass default constructor
BaseClass default constructor
DerivedClass default constructor
BaseClass default constructor
DerivedClass default constructor
BaseClass display
DerivedClass display
DerivedClass display
BaseClass destructor
DerivedClass destructor
BaseClass destructor
DerivedClass destructor
BaseClass destructor
--- End of main ---
```

## Q9
```bash
[l.tingjun@iht32-1502.sif studio8]$ ./main
BaseClass default constructor
BaseClass default constructor
DerivedClass default constructor
BaseClass default constructor
DerivedClass default constructor
BaseClass display
DerivedClass display
DerivedClass display
--- deleting base1 ---
BaseClass destructor
--- deleting base2 ---
BaseClass destructor
--- deleting derived ---
DerivedClass destructor
BaseClass destructor
--- End of main ---
```

I not virtual, then the delete instruction can't call derived class destructor dynamically, lead memory leak for derived class

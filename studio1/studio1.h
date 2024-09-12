#ifndef STUDIO1_H
#define STUDIO1_H

#include <iostream>

using std::ostream;

template<typename T>
class MyClass;

template<typename T>
ostream& operator << (ostream&, const MyClass<T>&);

template<typename T = int>
class MyClass {
	private:
		T value;
	
	public:
		MyClass(T val);
		
		friend ostream& operator << <>(ostream& os, const MyClass<T>& obj);
};

#include "studio1.cpp"

#endif

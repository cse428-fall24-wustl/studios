#ifndef MyClass_H
#define MyClass_H

#include <iostream>

using namespace std;

class MyClass
{

private:
  int x_;
  int y_;

public:
  MyClass();
  MyClass(const MyClass &other);

  int x() const;
  int y() const;
  MyClass &x(int x);
  MyClass &y(int y);
  MyClass returnByValue(MyClass obj);
};

#endif

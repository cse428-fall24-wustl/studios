#include "MyClass.h"

MyClass::MyClass() : x_(0), y_(0)
{
  std::cout << "Default constructor called, this = " << this << ", x = " << x_ << ", y = " << y_ << std::endl;
}

MyClass::MyClass(const MyClass &other) : x_(other.x_), y_(other.y_)
{
  std::cout << "Copy constructor called, this = " << this << ", x = " << x_ << ", y = " << y_ << std::endl;
}

int MyClass::x() const { return x_; }

int MyClass::y() const { return y_; }

MyClass &MyClass::x(int x)
{
  this->x_ = x;
  return *this;
}

MyClass &MyClass::y(int y)
{
  this->y_ = y;
  return *this;
}

MyClass MyClass::returnByValue(MyClass obj)
{
  return obj;
}
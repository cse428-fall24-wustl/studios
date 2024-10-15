template <typename T>
MyClass<T>::MyClass(T val) : value(val) {}

template <typename T>
ostream &operator<<(ostream &os, const MyClass<T> &obj)
{
    os << obj.value;
    return os;
}

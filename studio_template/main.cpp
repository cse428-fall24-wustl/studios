#include <iostream>
using namespace std;

// // 非可变参数模板
// template<typename T>
// void func(T t) {
//     std::cout << "Called func(T t)" << std::endl;
// }

// // 可变参数模板
// template<typename T, typename... Args>
// void func(T first, Args... args) {
//     std::cout << "Called func(Args... args)" << std::endl;
//     func(args...);
// }

// // 对 int 类型进行全特化
// template<>
// void func<int>(int t) {
//     std::cout << "Specialized func<int>(int t)" << std::endl;
// }


class Base {   
public:
    int a;
    Base() : a(10) {}
    virtual void func() {
        std::cout << "Base::func()" << std::endl;
    }
};

class Derived : public Base {
public:
    int b;
    Derived() : Base(), b(20) {}
    void func() {
        std::cout << "Derived::func()" << std::endl;
    }
    void shit(int) {
        std::cout << "Derived::func(int)" << std::endl;
    }
};
#include <iostream>
#include <type_traits>


void process(int& x) {
    std::cout << "Lvalue reference processed: " << x << "\n";
}

void process(int&& x) {
    std::cout << "Rvalue reference processed: " << x << "\n";
}

template <typename T>
void func(T&& t) {
    if (std::is_lvalue_reference<T>::value) {
        std::cout << "T is an lvalue reference\n";
    } else if (std::is_rvalue_reference<T>::value) {
        std::cout << "T is an rvalue reference\n";
    } else {
        std::cout << "T is a non-reference type\n";
    }
    process(forward<int&&>(t));
}

template <typename T>
void print(T value) {
    std::cout << "Template: " << value << std::endl;
}

template <>
void print<int>(int value) {
    std::cout << "Specialized Template: " << value << std::endl;
}

// void print(int value) {
//     std::cout << "Non-template: " << value << std::endl;
// }

int main() {
    print(3);  // 调用普通函数
    return 0;
}
### **第四单元：函数重载与模板（Overloading and Templates）复习材料**

本单元核心内容包括**函数重载**、**模板函数重载**、**模板特化**、**SFINAE**（替换失败并非错误）以及**模板匹配的优先级**。以下是完整的复习材料。

---

### **1. 函数重载**

#### **1.1 普通函数重载**
- 定义：允许多个函数名称相同但参数列表不同（参数类型或数量）的函数共存。
- **注意**：返回值不同不能作为重载的条件。

#### **示例**
```cpp
#include <iostream>
void print(int x) {
    std::cout << "Integer: " << x << std::endl;
}
void print(double x) {
    std::cout << "Double: " << x << std::endl;
}
int main() {
    print(42);    // 调用 print(int)
    print(3.14);  // 调用 print(double)
    return 0;
}
```

---

### **2. 模板函数与重载**

#### **2.1 模板函数基础**
模板函数允许通过模板参数生成适配任意类型的函数实例。

#### **示例**
```cpp
template <typename T>
void print(T value) {
    std::cout << "Template: " << value << std::endl;
}
```

#### **2.2 普通函数与模板函数的重载**
1. **普通函数优先于模板函数**
   - 如果普通函数匹配实参，则不会选择模板函数。

2. **显式特化优先于模板函数**
   - 如果模板函数显式特化完全匹配实参，则优先使用特化版本。

#### **示例**
```cpp
#include <iostream>

template <typename T>
void print(T value) {
    std::cout << "Template: " << value << std::endl;
}

template <>
void print<int>(int value) {
    std::cout << "Specialized Template: " << value << std::endl;
}

void print(double value) {
    std::cout << "Non-template: " << value << std::endl;
}

int main() {
    print(42);    // 调用特化模板
    print(3.14);  // 调用普通函数
    print('A');   // 调用模板函数
    return 0;
}
```

---

### **3. 模板特化**

#### **3.1 完全特化（Full Specialization）**
- 完全特化是针对某个特定类型的模板实现。
- **应用场景**：某些类型需要不同的行为。

#### **示例**
```cpp
template <typename T>
void print(T value) {
    std::cout << "Generic Template: " << value << std::endl;
}

// 完全特化
template <>
void print<int>(int value) {
    std::cout << "Specialized Template for int: " << value << std::endl;
}
```

#### **3.2 部分特化（Partial Specialization）**
- 仅适用于**类模板**，允许对模板的一部分参数进行特化。

#### **示例：针对指针类型的部分特化**
```cpp
template <typename T>
class Storage {
public:
    void display() {
        std::cout << "Generic Storage" << std::endl;
    }
};

// 部分特化：针对指针类型
template <typename T>
class Storage<T*> {
public:
    void display() {
        std::cout << "Pointer Storage" << std::endl;
    }
};

int main() {
    Storage<int> s1;
    s1.display(); // 输出：Generic Storage

    int x = 42;
    Storage<int*> s2;
    s2.display(); // 输出：Pointer Storage
}
```

---

### **4. SFINAE（替换失败并非错误）**

#### **4.1 定义**
SFINAE（Substitution Failure Is Not An Error）是C++模板编程的重要机制：
- 当模板参数替换失败时，编译器会忽略该模板，而不是报错。
- 可用于限制模板的使用范围。

#### **4.2 应用场景**
通过`std::enable_if`和类型特性（`type_traits`）限制模板实例化条件。

#### **示例：根据类型特性启用模板**
```cpp
#include <iostream>
#include <type_traits>

template <typename T>
typename std::enable_if<std::is_integral<T>::value>::type print(T value) {
    std::cout << "Integral: " << value << std::endl;
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value>::type print(T value) {
    std::cout << "Floating Point: " << value << std::endl;
}

int main() {
    print(42);    // 输出：Integral: 42
    print(3.14);  // 输出：Floating Point: 3.14
    return 0;
}
```

---

### **5. 可变参数模板与模板重载**

#### **5.1 可变参数模板**
可变参数模板允许处理任意数量的模板参数。

#### **示例**
```cpp
#include <iostream>

template <typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first << " ";
    if constexpr (sizeof...(args) > 0) {
        print(args...); // 递归调用
    }
}

int main() {
    print(1, 2.5, "hello", 'A'); // 输出：1 2.5 hello A
    return 0;
}
```

#### **5.2 模板重载**
可变参数模板也可以与普通模板或普通函数一起重载。
```cpp
template <typename T>
void print(T value) {
    std::cout << "Single value: " << value << std::endl;
}

template <typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << "Multiple values: " << first << ", ";
    print(args...); // 调用单一参数版本
}

int main() {
    print(1);           // 调用单一参数版本
    print(1, 2, 3.5);   // 调用可变参数版本
    return 0;
}
```

---

### **6. 模板匹配优先级**

#### **匹配优先级总结**
1. **完全匹配的普通函数优先**。
2. **显式特化模板次之**。
3. **普通模板函数最后**。
4. **需要类型转换时，只有模板函数会被选择**。

#### **示例**
```cpp
template <typename T>
void print(T value) {
    std::cout << "Template: " << value << std::endl;
}

template <>
void print<int>(int value) {
    std::cout << "Specialized Template: " << value << std::endl;
}

void print(double value) {
    std::cout << "Non-template: " << value << std::endl;
}

int main() {
    print(42);    // 调用特化模板
    print(3.14);  // 调用普通函数
    print('A');   // 调用模板函数
    return 0;
}
```

---

### **7. 注意事项与最佳实践**

1. **普通函数优先**：
   - 如果参数匹配普通函数，则不会选择模板函数。
   - 需避免不必要的函数重载引发二义性。

2. **特化模板的合理使用**：
   - 显式特化适用于处理具体类型。
   - 部分特化适用于类模板的某些参数组合。

3. **SFINAE配合类型特性**：
   - 使用`std::enable_if`限制模板的适用范围，提高代码健壮性。

4. **可变参数模板的灵活应用**：
   - 使用`if constexpr`或递归简化可变参数处理逻辑。

---

### **知识点总览**

| **知识点**              | **内容**                                                                                         |
|-------------------------|-------------------------------------------------------------------------------------------------|
| **普通函数重载**         | 同名函数参数类型或数量不同，返回值不能区分重载。                                                          |
| **模板函数重载**         | 普通函数优先于模板函数，显式特化优先于模板函数，模板函数为最后的选择。                                         |
| **完全特化**             | 针对特定类型实现的模板版本。                                                                          |
| **部分特化**             | 类模板支持部分特化，对模板的一部分参数提供特殊实现。                                                         |
| **SFINAE**              | 替换失败并非错误机制，结合`std::enable_if`启用/禁用模板。                                                  |
| **可变参数模板**         | 允许传递任意数量的模板参数，常与递归结合使用。                                                              |
| **模板匹配优先级**       | 普通函数 > 显式特化模板 > 普通模板函数 > 类型转换后模板函数。                                                 |

---

通过本单元的复习，掌握了函数重载与模板结合的规则，能够灵活设计和优化模板代码，以适应各种实际需求！
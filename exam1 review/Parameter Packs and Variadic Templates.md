### **第五单元复习：Variadic Templates 和 Parameter Packs**

本单元的核心内容是 **Variadic Templates（可变参数模板）** 和 **Parameter Packs（参数包）** 的概念、语法及实际应用。以下是完整的复习材料，涵盖定义、用法、代码示例及注意事项。

---

### **1. 定义和基本概念**

#### **1.1 Variadic Templates**
- **定义（Definition）**：
  Variadic Templates 是一种模板机制，允许模板接收**任意数量**的参数，适用于模板参数（`template<typename... Args>`）和函数参数（`Args...`）。
  
- **特性（Features）**：
  - 提供极大的灵活性，可以处理数量不定、类型不定的参数。
  - 常用于打印、调用多个函数、类型操作等任务。

---

#### **1.2 Parameter Packs**
- **定义（Definition）**：
  参数包（Parameter Pack）是 Variadic Templates 用于表示**可变数量参数**的语法特性。
  
- **分类（Categories）**：
  1. **模板参数包（Template Parameter Pack）**：
     - 用于接收任意数量的模板参数（类型参数或非类型参数）。
     - 例如：`template<typename... Args>`。
  2. **函数参数包（Function Parameter Pack）**：
     - 用于接收任意数量的函数参数。
     - 例如：`void func(Args... args)`。

- **展开（Expansion）**：
  参数包需要展开才能逐一访问，每个参数的展开通过递归或**折叠表达式（Fold Expressions，C++17）**实现。

---

### **2. Variadic Templates 的语法**

#### **2.1 声明参数包**
- 模板参数包声明：
  ```cpp
  template <typename... Args>
  void func(Args... args) {
      // args 是函数参数包
  }
  ```

- 非类型模板参数包声明：
  ```cpp
  template <int... Nums>
  void func() {
      // Nums 是非类型模板参数包
  }
  ```

---

#### **2.2 参数包展开**
- 参数包需要展开才能逐一处理。展开方式包括递归展开和折叠表达式。
- **递归展开（Recursive Expansion）**：
  - 通过递归调用模板函数逐步展开参数包。
- **折叠表达式（Fold Expressions, C++17）**：
  - 使用操作符直接展开参数包，简化代码。

---

### **3. Variadic Templates 的应用场景**

#### **3.1 任意参数的打印**
**递归实现**：
```cpp
#include <iostream>

// 基例：终止递归
void print() {
    std::cout << "End of arguments" << std::endl;
}

// 可变参数模板：逐一展开
template <typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first << " ";
    print(args...); // 递归调用
}

int main() {
    print(1, 2.5, "hello", 'A'); 
    // 输出：1 2.5 hello A End of arguments
    return 0;
}
```

**折叠表达式实现（C++17）**：
```cpp
#include <iostream>

template <typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << std::endl; // 左折叠
}

int main() {
    print(1, 2.5, "hello", 'A');
    // 输出：1 2.5helloA
    return 0;
}
```

---

#### **3.2 静态数组生成**
```cpp
#include <array>
#include <iostream>

// 可变参数模板创建 std::array
template <typename... Args>
auto make_array(Args... args) {
    return std::array{args...}; // 使用参数包展开
}

int main() {
    auto arr = make_array(1, 2, 3, 4);
    for (auto i : arr) {
        std::cout << i << " "; // 输出：1 2 3 4
    }
    return 0;
}
```

---

#### **3.3 类型特性操作**
```cpp
#include <iostream>
#include <type_traits>

// 检查参数包中是否全是整型
template <typename... Args>
struct AreAllIntegral {
    static constexpr bool value = (std::is_integral<Args>::value && ...);
};

int main() {
    std::cout << std::boolalpha;
    std::cout << AreAllIntegral<int, char, long>::value << std::endl; // 输出：true
    std::cout << AreAllIntegral<int, char, double>::value << std::endl; // 输出：false
    return 0;
}
```

---

#### **3.4 参数数量统计**
使用 `sizeof...` 操作符统计参数包的数量：
```cpp
#include <iostream>

template <typename... Args>
void log(const Args&... args) {
    std::cout << "Number of arguments: " << sizeof...(Args) << std::endl;
}

int main() {
    log(1, 2.5, "hello", 'A'); 
    // 输出：Number of arguments: 4
    return 0;
}
```

---

### **4. Variadic Templates 的注意事项**

#### **4.1 参数包为空**
- 当参数包为空时，递归实现需要一个基例（非可变版本）来终止递归。

#### **4.2 避免过深的递归**
- 如果递归深度过大，可能会导致栈溢出。
- **折叠表达式** 是更高效的选择。

#### **4.3 参数顺序匹配**
- 在混合参数包时，确保模板参数的顺序正确。
```cpp
template <typename T, typename... Args>
void func(T first, Args... args) {
    // T 匹配第一个参数，Args 匹配剩余参数
}
```

---

### **5. Variadic Templates 的优缺点**

#### **优点**
1. **高灵活性**：可以接收任意数量和类型的参数。
2. **简化代码**：减少重复代码的书写，通过泛型处理多种情况。
3. **参数包展开方式多样**：支持递归和折叠表达式。

#### **缺点**
1. **代码复杂性**：递归实现可能不直观。
2. **错误调试困难**：错误可能发生在递归展开的某一步，调试难度较大。
3. **递归深度限制**：递归展开可能导致栈溢出。

---

### **6. Variadic Templates 的优先级**

#### **匹配规则**
- 在调用 Variadic Templates 时，非可变版本（Non-Variadic Version）优先匹配。
- 非可变版本更特化，因此会被优先选择。

#### **示例**
```cpp
#include <iostream>

// 非可变版本
void print(int x) {
    std::cout << "Non-variadic: " << x << std::endl;
}

// 可变版本
template <typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << std::endl; // 使用折叠表达式
}

int main() {
    print(42); // 调用非可变版本
    print(1, 2, 3); // 调用可变版本
    return 0;
}
```

---

### **7. 复习要点表格**

| **概念**                       | **解释**                                                                                     |
|--------------------------------|---------------------------------------------------------------------------------------------|
| **Variadic Templates**         | 支持任意数量参数的模板，用于模板参数和函数参数。                                                |
| **Parameter Pack**             | 表示可变数量参数的集合，可以是模板参数包或函数参数包。                                             |
| **递归展开（Recursive Expansion）** | 逐步处理参数包，通过递归调用非可变版本终止递归。                                                  |
| **折叠表达式（Fold Expressions）**  | C++17 引入的简化参数包处理的语法，通过操作符直接展开参数包。                                           |
| **`sizeof...`**                | 用于获取参数包中参数的数量。                                                                     |

---

### **8. 样题**

#### **8.1 简答题**
1. **What is a parameter pack, and how do you expand it in C++?**
   - **Answer**: A parameter pack is a collection of template or function parameters that can vary in number. It can be expanded using recursion or fold expressions.

2. **How does recursion help in processing parameter packs?**
   - **Answer**: Recursion allows us to process one parameter at a time until the parameter pack becomes empty. A non-variadic base case is needed to terminate the recursion.

#### **8.2 编程题**
1. **实现一个函数，用 Variadic Templates 打印所有参数，并输出参数数量：**
```cpp
#include <iostream>

template <typename... Args>
void log(Args... args) {
    std::cout <<

 "Number of arguments: " << sizeof...(Args) << std::endl;
    (std::cout << ... << args) << std::endl; // 折叠表达式
}

int main() {
    log("Error:", 404, "Not Found");
    // 输出：
    // Number of arguments: 3
    // Error:404Not Found
    return 0;
}
```

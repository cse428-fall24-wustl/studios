### **第八单元：Generic Algorithms（泛型算法）复习**

C++ 标准库（STL）中提供了一组 **泛型算法（Generic Algorithms）**，它们与容器无关，可以应用于任何符合要求的 **迭代器范围**。这些算法包含了常用的排序、查找、变换和处理等功能。

---

### **1. 什么是泛型算法？**

#### **定义**
- 泛型算法是基于 **模板** 的算法库，适用于不同类型的容器和数据结构。
- 它们不直接操作容器，而是通过迭代器访问容器中的元素。

#### **特点**
1. **与容器无关**：
   - 泛型算法通过 **迭代器** 而非容器操作数据。
   - 支持任何实现了标准迭代器接口的数据结构。

2. **高效性和通用性**：
   - 使用模板实现，无需针对特定类型重写代码。
   - 提供了大量预定义算法，减少重复代码。

3. **分类明确**：
   - 包括查找、排序、复制、变换、统计等多个类别。

---

### **2. 常见的泛型算法分类**

| **算法类别**          | **常用函数**                                                                                   | **描述**                                                             |
|-----------------------|-----------------------------------------------------------------------------------------------|----------------------------------------------------------------------|
| **非修改算法**         | `std::find`、`std::count`、`std::equal`                                                      | 不修改容器元素，仅进行查找、统计、比较等操作。                                |
| **修改算法**           | `std::copy`、`std::fill`、`std::replace`、`std::transform`                                    | 修改迭代器范围内的元素。                                                  |
| **排序与排列算法**     | `std::sort`、`std::stable_sort`、`std::reverse`、`std::rotate`、`std::next_permutation`        | 改变元素的排列顺序。                                                    |
| **查找算法**           | `std::binary_search`、`std::lower_bound`、`std::upper_bound`、`std::equal_range`              | 基于排序的查找算法。                                                    |
| **数值算法**           | `std::accumulate`、`std::inner_product`、`std::partial_sum`、`std::adjacent_difference`        | 执行数学运算的算法。                                                    |

---

### **3. 常用算法详解**

#### **3.1 非修改算法**

1. **`std::find`**
   - 功能：在范围内查找第一个匹配的元素。
   - 时间复杂度：O(n)。
   - 示例：
     ```cpp
     #include <iostream>
     #include <vector>
     #include <algorithm>

     int main() {
         std::vector<int> vec = {1, 2, 3, 4, 5};
         auto it = std::find(vec.begin(), vec.end(), 3);
         if (it != vec.end()) {
             std::cout << "Found: " << *it << std::endl;
         } else {
             std::cout << "Not Found" << std::endl;
         }
         return 0;
     }
     ```

2. **`std::count`**
   - 功能：统计范围内等于某个值的元素个数。
   - 示例：
     ```cpp
     std::vector<int> vec = {1, 2, 3, 2, 2};
     int count = std::count(vec.begin(), vec.end(), 2);
     std::cout << "Count: " << count << std::endl; // 输出：3
     ```

3. **`std::equal`**
   - 功能：检查两个范围的元素是否相等。
   - 示例：
     ```cpp
     std::vector<int> vec1 = {1, 2, 3};
     std::vector<int> vec2 = {1, 2, 3};
     if (std::equal(vec1.begin(), vec1.end(), vec2.begin())) {
         std::cout << "Equal" << std::endl;
     }
     ```

---

#### **3.2 修改算法**

1. **`std::copy`**
   - 功能：将一个范围内的元素复制到另一个范围。
   - 示例：
     ```cpp
     std::vector<int> src = {1, 2, 3};
     std::vector<int> dest(3);
     std::copy(src.begin(), src.end(), dest.begin());
     ```

2. **`std::fill`**
   - 功能：将范围内所有元素替换为指定值。
   - 示例：
     ```cpp
     std::vector<int> vec(5);
     std::fill(vec.begin(), vec.end(), 42); // vec: {42, 42, 42, 42, 42}
     ```

3. **`std::transform`**
   - 功能：对范围内的每个元素应用指定操作。
   - 示例：
     ```cpp
     std::vector<int> vec = {1, 2, 3};
     std::vector<int> result(3);
     std::transform(vec.begin(), vec.end(), result.begin(), [](int x) { return x * 2; });
     // result: {2, 4, 6}
     ```

---

#### **3.3 排序与排列算法**

1. **`std::sort`**
   - 功能：对范围内的元素进行升序排序。
   - 示例：
     ```cpp
     std::vector<int> vec = {3, 1, 2};
     std::sort(vec.begin(), vec.end()); // vec: {1, 2, 3}
     ```

2. **`std::reverse`**
   - 功能：反转范围内的元素顺序。
   - 示例：
     ```cpp
     std::vector<int> vec = {1, 2, 3};
     std::reverse(vec.begin(), vec.end()); // vec: {3, 2, 1}
     ```

3. **`std::next_permutation`**
   - 功能：生成序列的下一个排列。
   - 示例：
     ```cpp
     std::vector<int> vec = {1, 2, 3};
     do {
         for (int v : vec) std::cout << v << " ";
         std::cout << std::endl;
     } while (std::next_permutation(vec.begin(), vec.end()));
     ```

---

#### **3.4 数值算法**

1. **`std::accumulate`**
   - 功能：计算范围内所有元素的累加值。
   - 示例：
     ```cpp
     std::vector<int> vec = {1, 2, 3};
     int sum = std::accumulate(vec.begin(), vec.end(), 0); // sum: 6
     ```

2. **`std::inner_product`**
   - 功能：计算两个范围内元素的内积。
   - 示例：
     ```cpp
     std::vector<int> vec1 = {1, 2, 3};
     std::vector<int> vec2 = {4, 5, 6};
     int result = std::inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0);
     // result: 1*4 + 2*5 + 3*6 = 32
     ```

---

### **4. 泛型算法的注意事项**

1. **与迭代器配合使用**
   - 泛型算法通过迭代器操作范围内的元素。
   - 确保迭代器满足算法要求的类型（如随机访问迭代器或双向迭代器）。

2. **范围有效性**
   - 确保提供的范围 `[begin, end)` 有效，否则可能导致未定义行为。

3. **自定义比较函数**
   - 一些算法（如 `std::sort`）允许提供自定义的比较函数，以调整排序规则。

4. **避免使用未初始化的容器**
   - 修改算法如 `std::copy` 和 `std::transform` 需要目标范围事先分配足够的空间。

---

### **5. 样题**

#### **5.1 简答题**

1. **What is a generic algorithm, and how does it interact with iterators?**
   - **Answer**:
     - A generic algorithm is a function in the STL that works with iterators instead of directly operating on containers. It can be applied to any container type that supports compatible iterators.

2. **What is the difference between `std::find` and `std::binary_search`?**
   - **Answer**:
     - `std::find` performs a linear search and works on any unsorted range.
     - `std::binary_search` requires the range to be sorted and performs a logarithmic search.

---

#### **5.2 编程题**

1. **使用 STL 算法找到并替换向量中的某个值**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 2, 4};
    std::replace(vec.begin(), vec

.end(), 2, 5); // 将所有的2替换为5

    for (int v : vec) {
        std::cout << v << " "; // 输出：1 5 3 5 4
    }
    return 0;
}
```

2. **实现对序列的排序，并打印所有排列**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {3, 1, 2};
    std::sort(vec.begin(), vec.end());

    do {
        for (int v : vec) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(vec.begin(), vec.end()));

    return 0;
}
```

以下是一份关于 **C++ 标准泛型算法（Standard Generic Algorithms）** 的完整复习材料，包含知识点总结、示例代码、练习题和答案，帮助您系统化地复习并准备考试。

---

## **C++标准泛型算法复习材料**

### **1. 标准泛型算法的概述**
#### **1.1 核心特点**
- **通用性**：
  - 标准泛型算法支持对各种容器（如`std::vector`、`std::list`）和自定义类型的操作。
  - 算法仅需要容器提供合适的迭代器类型，而与具体容器的实现无关。
- **高效性**：
  - 算法使用模板和内联函数实现，能在编译时确定类型，优化性能。
- **分层设计**：
  - 不同算法需要不同种类的迭代器，迭代器类型包括：输入迭代器、前向迭代器、双向迭代器和随机访问迭代器。

#### **1.2 算法分类**
| **分类**             | **功能**                         | **示例算法**                             |
|----------------------|----------------------------------|------------------------------------------|
| **非修改序列操作**     | 遍历范围内元素，检查或计算。           | `std::find`, `std::count`, `std::equal` |
| **修改序列操作**       | 重新排列或修改范围内的元素。           | `std::copy`, `std::reverse`, `std::fill`|
| **排序与重排**         | 对范围内的元素排序或重排。            | `std::sort`, `std::partition`           |
| **删除与去重**         | 移除范围内特定元素或重复元素。         | `std::remove`, `std::unique`            |
| **数值操作**           | 计算范围内元素的累积和或数学运算。      | `std::accumulate`, `std::inner_product` |
| **集合操作**           | 对有序范围执行集合运算。              | `std::set_union`, `std::set_intersection` |

#### **1.3 常见迭代器类型与功能**
| **迭代器类别**              | **支持的操作**                                 | **示例容器**          |
|--------------------------|--------------------------------------------|--------------------|
| **输入迭代器**（InputIterator） | 单次读取，顺序遍历。                              | `std::istream_iterator` |
| **前向迭代器**（ForwardIterator）| 多次读取，支持赋值操作。                           | `std::forward_list`  |
| **双向迭代器**（BidirectionalIterator）| 支持向前、向后遍历。                             | `std::list`         |
| **随机访问迭代器**（RandomAccessIterator）| 支持随机位置访问和算术操作（如`[]`, `+`, `-`）。 | `std::vector`, `std::deque` |

---

### **2. 示例代码讲解**
以下是常用标准算法的示例代码，结合其迭代器要求和功能。

#### **2.1 非修改算法：`std::find`**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    auto it = find(v.begin(), v.end(), 3); // 查找值为3的元素
    if (it != v.end()) {
        cout << "找到3的位置：" << distance(v.begin(), it) << endl;
    } else {
        cout << "未找到3" << endl;
    }
    return 0;
}
```

#### **2.2 修改算法：`std::copy`**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> src = {1, 2, 3};
    vector<int> dest(3); // 确保目标容器有足够空间
    copy(src.begin(), src.end(), dest.begin()); // 复制数据
    for (int x : dest) cout << x << " "; // 输出目标容器
    return 0;
}
```

#### **2.3 排序算法：`std::sort`**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {3, 1, 4, 1, 5};
    sort(v.begin(), v.end()); // 排序
    for (int x : v) cout << x << " "; // 输出排序结果
    return 0;
}
```

#### **2.4 数值算法：`std::accumulate`**
```cpp
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4};
    int sum = accumulate(v.begin(), v.end(), 0); // 计算累加和
    cout << "总和是：" << sum << endl;
    return 0;
}
```

#### **2.5 删除操作：`std::remove`**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 2, 4};
    auto new_end = remove(v.begin(), v.end(), 2); // 移除值为2的元素
    v.erase(new_end, v.end()); // 调整容器大小
    for (int x : v) cout << x << " "; // 输出结果
    return 0;
}
```

---

### **3. 常见考点与习题**
#### **3.1 填空题**
1. **`std::find` 的最低迭代器要求是 ________。**
2. **`std::sort` 的最低迭代器要求是 ________。**
3. **`std::accumulate` 的功能是 ________。**

#### **3.2 判断题**
1. `std::sort` 使用迭代器的 `<` 运算符来比较元素值。(**True**)  
2. `std::remove` 会直接从容器中删除元素。(**False**)  

#### **3.3 编程题**
1. 使用 `std::partition` 将一个 `std::vector` 按奇偶分区，奇数在前，偶数在后。
2. 编写一个支持排序的自定义容器及其随机访问迭代器。

---

### **4. 习题答案**
#### **4.1 填空题**
1. 输入迭代器（InputIterator）。  
2. 随机访问迭代器（RandomAccessIterator）。  
3. 计算范围内元素的累加和。

#### **4.2 编程题示例**
1. **`std::partition` 分区示例**：
   ```cpp
   #include <iostream>
   #include <vector>
   #include <algorithm>
   using namespace std;

   int main() {
       vector<int> v = {1, 2, 3, 4, 5};
       partition(v.begin(), v.end(), [](int x) { return x % 2 != 0; }); // 奇偶分区
       for (int x : v) cout << x << " ";
       return 0;
   }
   ```
   **输出**：`1 3 5 4 2`

2. **支持排序的自定义容器与迭代器**：见前面关于随机访问迭代器的完整实现示例。

---

### **5. 总结与复习建议**
- **分类掌握**：按非修改、修改、排序、删除、数值等分类记忆算法功能和迭代器要求。
- **实践练习**：多写代码，通过实际使用算法加深理解。
- **关注迭代器**：理解各种迭代器的功能和应用场景，确保对`std::sort`、`std::remove`等高效使用。



### **表格1：常用标准泛型算法及其迭代器要求**

| **算法类别**           | **算法**                          | **最低迭代器要求**              | **说明**                                                                               |
|-----------------------|-----------------------------------|-------------------------------|---------------------------------------------------------------------------------------|
| **非修改序列操作**      | `std::find`, `std::count`        | 输入迭代器（InputIterator）      | 遍历范围，查找或计数元素，不修改数据。                                                    |
|                       | `std::equal`                     | 输入迭代器（InputIterator）      | 比较两个范围内的元素是否相等。                                                          |
|                       | `std::mismatch`                  | 输入迭代器（InputIterator）      | 找到两个范围第一个不匹配的元素位置。                                                     |
| **修改序列操作**        | `std::copy`, `std::move`         | 输入迭代器（InputIterator）      | 将输入范围的内容复制或移动到目标范围中。                                                 |
|                       | `std::reverse`                   | 双向迭代器（BidirectionalIterator）| 反转范围内的元素顺序，需要支持双向遍历。                                                  |
|                       | `std::fill`, `std::generate`     | 前向迭代器（ForwardIterator）    | 将范围内的所有元素填充为指定值，或根据生成器函数生成值。                                        |
| **排序与重排**         | `std::sort`                      | 随机访问迭代器（RandomAccessIterator）| 对范围内的元素进行排序，要求迭代器支持随机访问。                                              |
|                       | `std::stable_sort`               | 随机访问迭代器（RandomAccessIterator）| 稳定排序（保持相同值的相对顺序），迭代器支持随机访问。                                          |
|                       | `std::nth_element`               | 随机访问迭代器（RandomAccessIterator）| 部分排序，找到第n个元素的位置并保证左侧小于它，右侧大于它。                                       |
|                       | `std::partition`                 | 前向迭代器（ForwardIterator）    | 重新排列范围内的元素，使得满足条件的元素排在前面。                                                |
|                       | `std::rotate`                    | 前向迭代器（ForwardIterator）    | 将范围内的元素循环移动到新位置。                                                           |
| **删除操作**           | `std::remove`, `std::unique`     | 前向迭代器（ForwardIterator）    | 将范围内的元素重新排列，移除特定值或重复值，返回新范围的结束迭代器。                                     |
| **数值操作**           | `std::accumulate`                | 输入迭代器（InputIterator）      | 计算范围内元素的累积和，起始值可指定。                                                     |
|                       | `std::inner_product`             | 输入迭代器（InputIterator）      | 计算两个范围内对应元素的点积（内积）。                                                      |
|                       | `std::adjacent_difference`       | 输入迭代器（InputIterator）      | 计算范围内相邻元素之间的差值，生成一个新范围。                                                |
| **集合操作**           | `std::set_union`, `std::set_intersection` | 输入迭代器（InputIterator）      | 对有序范围执行集合操作，如并集、交集，结果写入目标范围。                                           |
|                       | `std::includes`                  | 输入迭代器（InputIterator）      | 检查一个有序范围是否包含另一个范围的所有元素。                                                 |

---

### **表格2：迭代器类型与功能**

| **迭代器类别**              | **关键功能**                                                                                                                                           | **支持的操作符**                                                   |
|--------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------|
| **输入迭代器**（InputIterator） | 单次读取，支持顺序遍历（如文件流、标准输入）。                                                                                                                 | `++`, `*`, `==`, `!=`                                         |
| **输出迭代器**（OutputIterator）| 单次写入，顺序遍历目标范围（如输出流、文件写入）。                                                                                                                 | `++`, `*`                                                    |
| **前向迭代器**（ForwardIterator）| 支持多次读取和顺序遍历，可用于链表等容器。                                                                                                                     | `++`, `*`, `==`, `!=`                                         |
| **双向迭代器**（BidirectionalIterator）| 支持多次读取，能向前和向后遍历（如`std::list`）。                                                                                                         | `++`, `--`, `*`, `==`, `!=`                                   |
| **随机访问迭代器**（RandomAccessIterator）| 支持多次读取，支持随机位置访问和算术操作（如`std::vector`，`std::deque`）。                                                                                      | `++`, `--`, `+`, `-`, `[]`, `<`, `<=`, `>`, `>=`, `*`         |


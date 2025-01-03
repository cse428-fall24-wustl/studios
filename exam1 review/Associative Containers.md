### 中文总结：Associative Containers (关联容器)

关联容器是C++标准模板库中提供的一类数据结构，用于存储和快速访问具有特定关系的键和值。以下是相关内容的总结：

#### 标准关联容器
1. **有序关联容器** (基于平衡二叉树实现，复杂度为 \(O(\log n)\))：
   - **`std::set`**：只存储键，不允许重复。
   - **`std::multiset`**：只存储键，允许重复。
   - **`std::map`**：键值对存储，每个键唯一。
   - **`std::multimap`**：键值对存储，允许重复键。

2. **无序关联容器** (基于哈希表实现，复杂度通常为 \(O(1)\))：
   - **`std::unordered_set`**：类似于 `set`，不允许重复键。
   - **`std::unordered_multiset`**：类似于 `multiset`，允许重复键。
   - **`std::unordered_map`**：类似于 `map`，不允许重复键。
   - **`std::unordered_multimap`**：类似于 `multimap`，允许重复键。

#### 关联容器的特性
- **类型定义**：
  - `key_type`：键的类型。
  - `value_type`：值的类型（对 `map` 和 `multimap` 来说为 `pair<const key_type, mapped_type>`）。
  - `mapped_type`：仅对 `map` 和 `multimap`，表示与键关联的值的类型。

- **迭代器特点**：
  - 支持双向迭代（`++` 和 `--` 操作）。
  - 对键只读访问（无法修改键），但可以修改 `map` 和 `multimap` 的值部分。

#### 常见操作
1. **插入元素**：
   - `insert` 返回一个 `pair`，其中第一个是迭代器，第二个是布尔值，指示插入是否成功（对 `set` 和 `map`）。
   - `multiset` 和 `multimap` 的 `insert` 只返回迭代器。

2. **查找元素**：
   - `find` 返回指向第一个匹配元素的迭代器。
   - `lower_bound` 和 `upper_bound` 分别返回不小于或大于给定键的第一个元素的迭代器。
   - `equal_range` 返回一对迭代器，界定具有给定键的所有元素的范围。

3. **哈希相关的注意点**：
   - 自定义类型使用无序容器时，需要实现 `operator==` 和 `hash` 函数。

#### 适用场景
- **有序容器**：适用于需要有序遍历的场景。
- **无序容器**：适用于需要高效插入和查找但无需排序的场景。

### 示例问题
1. **短答案**：描述 `std::map` 和 `std::unordered_map` 的主要区别。
2. **代码填空**：为一个 `std::set<int>` 添加一个范围内的元素。
3. **设计问题**：选择合适的容器用于统计单词频率并解释原因。
### **C++ IO 复习材料**

#### **1. 基础概念**

1. **标准IO流对象**：
   - `cin`：用于读取输入。
   - `cout`：用于输出。
   - `cerr`：用于输出错误信息。
   - 这些对象直接封装了标准输入输出设备。

2. **IO流状态**：
   - 使用`good()`、`fail()`、`eof()`等成员函数检查流的状态。
   - `cin.fail()`：输入不符合要求时会返回`true`。
   - `cin.eof()`：输入到达文件结束符时返回`true`。

3. **文件流**：
   - `ifstream`：读取文件。
   - `ofstream`：写入文件。
   - `fstream`：读写文件。
   - 文件打开模式：`ios::in`、`ios::out`、`ios::app`。

4. **字符串流**：
   - `stringstream`：在内存中对字符串进行读写操作。
   - `istringstream`：只读字符串。
   - `ostringstream`：只写字符串。

5. **操控器（Manipulators）**：
   - 用于格式化输出，例如`std::setw()`、`std::setprecision()`等。
   - 常见操控器：
     - `boolalpha`/`noboolalpha`：布尔值输出为`true/false`或`1/0`。
     - `hex`/`dec`/`oct`：设置数字进制。
     - `fixed`/`scientific`：控制浮点数格式。

---

#### **2. 示例代码**

以下是一个全面的示例，涵盖了标准输入输出、文件流、字符串流和操控器的使用：

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

int main() {
    // 标准输入输出示例
    std::cout << "请输入一个整数和一个浮点数: ";
    int integer;
    double floating;
    std::cin >> integer >> floating;
    std::cout << "您输入的整数是: " << integer << ", 浮点数是: " << floating << std::endl;

    // 操控器示例
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "固定精度浮点数: " << floating << std::endl;

    // 文件流示例
    std::ofstream outfile("example.txt");
    outfile << "这是一个文件写入示例。\n";
    outfile.close();

    std::ifstream infile("example.txt");
    std::string line;
    while (std::getline(infile, line)) {
        std::cout << "文件内容: " << line << std::endl;
    }

    // 字符串流示例
    std::stringstream ss;
    ss << "字符串流示例：将整数 " << integer << " 和浮点数 " << floating << " 转为字符串";
    std::string result = ss.str();
    std::cout << result << std::endl;

    return 0;
}
```

---

#### **3. 样题与答案**

**(1) 填空题**

1. C++ 的 `ifstream` 和 `ofstream` 分别用于_______和_______文件。
   - 答案：读取，写入。

2. 以下哪种流操控器可以设置浮点数的精度？（单选）
   - A. `setw`  B. `boolalpha`  C. `setprecision`  D. `flush`
   - 答案：C. `setprecision`

**(2) 判断题**

1. 操控器 `boolalpha` 会将布尔值格式化为 `true` 和 `false`。
   - 答案：正确。

2. 如果用 `ifstream` 打开一个不存在的文件，程序会抛出异常。
   - 答案：错误。可以使用`is_open()`检查文件是否成功打开。

Question: Why is it important that C++ IO streams have deleted copy constructors and assignment operators?
Answer:
防止多个流对象共享同一个底层资源（如文件描述符），以避免文件操作混乱或数据损坏。
例如：如果ifstream被复制，两个流对象可能同时尝试读写同一个文件，导致未定义行为。

6. Question: When should you use std::cerr instead of std::cout?
Answer:
当输出错误或诊断信息时，应该使用std::cerr。
它不经过缓冲区，确保错误信息即时输出。
适用于需要在程序崩溃之前查看错误信息的情况。

7. Question: What does the std::setw() manipulator do, and why is it important?
Answer:
它用于设置下一个输出字段的宽度。
重要性：
提高表格数据的对齐和可读性，例如打印一张成绩表或日志文件。

4. Question: What does the std::flush manipulator do in an output stream?
Answer:
它将缓冲区中的数据立即写入目的地（例如文件或控制台）。
通常用于确保重要信息在程序崩溃或中断之前被输出，例如日志记录。

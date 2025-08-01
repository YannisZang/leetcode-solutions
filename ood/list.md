
## 1. 设计缓存

* **146. LRU 缓存（Least Recently Used Cache）**
* **460. LFU 缓存（Least Frequently Used Cache）**

## 2. 设计哈希结构

* **705. 设计 HashSet**
* **706. 设计 HashMap**

## 3. 设计社交／消息流

* **355. 设计推特（Twitter）**
* **621. 任务调度器（Task Scheduler，变体）**

## 4. 设计文件系统／存储服务

* **588. 设计内存文件系统（In-Memory File System）**
* **535. 短链接服务（Encode and Decode TinyURL）**

## 5. 设计序列迭代器

* **604. 压缩字符串迭代器（Compressed String Iterator）**
* **1599. 设计聊天记录（变体）**

## 6. 设计并发控制（多线程）

* **1117. 构建 H2O（Building H2O）**
* **1226. 哲学家就餐（Dining Philosophers）**

## 7. 其他经典 OOD 题

* **707. 设计链表（Design Linked List）**
* **1206. 设计跳表（Design Skiplist）**
* **362. 计数器（Design Hit Counter）**

---

### 练习建议

1. **模板法**
   以 LRU 缓存为例，熟悉“哈希表 + 双向链表”这类组合套路，其他设计题（LFU、跳表、链表）也有类似思路。

2. **边界与复杂度**
   始终明确接口的时间（O(1)/O(log n)）和空间要求。

3. **接口与细节**
   不仅要写出核心数据结构，还要理清初始化、异常（如容量为 0）、多线程安全等边界场景。

4. **模拟演练**
   写完后手动模拟几种典型操作序列，确保设计逻辑严谨。

#### 120. 三角形最小路径和
- 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
- 例如，给定三角形：
    ```
    [
     [2],
     [3,4],
     [6,5,7],
     [4,1,8,3]
    ]
    ```
- 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
- 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

#### 数据访问图
- ![avatar](images/../../images/120_1.png)

#### 回溯图
- 以 leetcode_120_1.cpp 为例子
- ![avatar](images/../../images/120_2.png)


#### 参考资料
- [120. 三角形最小路径和](https://leetcode-cn.com/problems/triangle/solution/120-san-jiao-xing-zui-xiao-lu-jing-he-by-alexer-66/)
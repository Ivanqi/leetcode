#### 72. 编辑距离
- 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
- 你可以对一个单词进行如下三种操作：
  - 插入一个字符
  - 删除一个字符
  - 替换一个字符
- 示例 1：
    ```
    输入：word1 = "horse", word2 = "ros"
    输出：3
    解释：
    horse -> rorse (将 'h' 替换为 'r')
    rorse -> rose (删除 'r')
    rose -> ros (删除 'e')
    ```
- 示例 2：
    ```
    输入：word1 = "intention", word2 = "execution"
    输出：5
    解释：
    intention -> inention (删除 't')
    inention -> enention (将 'i' 替换为 'e')
    enention -> exention (将 'n' 替换为 'x')
    exention -> exection (将 'n' 替换为 'c')
    exection -> execution (插入 'u')
    ```
#### 插入字符，删除字符，替换字符流程
- 插入字符串
  - A = doge , B = dog. 要让 A == B
  - 在B后插入 `e`, B = doge. A == B
- 删除字符
  - A = doge, B = dog. 要让 A == B
  - 删除 A 后面的`e`, A = dog。 所以 A == B
- 替换字符
  - A = bat, B = cat。 要让 A == B
  - A 替换 `b` 为 `c` 或者 B 替换 `c` 为 `b`

#### 参考资料
- [编辑距离](https://leetcode-cn.com/problems/edit-distance/solution/bian-ji-ju-chi-by-leetcode-solution/)
- [编辑距离面试题详解](https://leetcode-cn.com/problems/edit-distance/solution/bian-ji-ju-chi-mian-shi-ti-xiang-jie-by-labuladong/)
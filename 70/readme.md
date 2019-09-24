#### 70. 爬楼梯
- 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
- 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
- 注意：给定 n 是一个正整数。
- 示例 1：
```
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
```

- 示例 2：
```
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
```

- 爬楼梯的思路解析
  - 走到第1级，有1种方法，直接走1
  - 走到第2级，有2种方法 (1, 1), (2) 总共两种走法
  - 走到第3级，有3种方法 (1, 1, 1), (1, 2), (2, 1) 总共3种走法
  - 走到第4级，有5种方法 (1, 1, 1, 1), (1, 1, 2), (1, 2, 1), (2, 2) 总共五种
  - 走到第5级，有8种方法，依次类推
  - 以此类推，后面的总等于前面两级方法之和，现在使用递归和递推两种方法解决问题
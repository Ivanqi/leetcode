#### 122. 买卖股票的最佳时机 II
- 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
- 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
- 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
- 示例 1:
    ```
    输入: [7,1,5,3,6,4]
    输出: 7
    解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
         随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。 
    ```
- 示例 2:
    ```
    输入: [1,2,3,4,5]
    输出: 4
    解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
         注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
         因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
    ```
- 示例 3:
    ```
    输入: [7,6,4,3,1]
    输出: 0
    解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
    ```

#### leetcode_122_1.cpp 回溯图
- ![avatar](images/../../images/122_1.png)

#### leetcode_122_4.cpp 部分回溯图
- ![avatar](images/../../images/122_2.png)
- 三种状态 : 不操作，买入， 卖出
- 不操作的原因：可能当前买入/卖出，都不能获得最大利益。需要往后看看
- 卖出了，下一个交易动作是不操作（等待时机）,或直接买入
- 买入了，下一个交易动作是不操作(等待时机)，或直接卖出

#### leetcode_122_5.cpp 及 leetcode_122_6.cpp 状态转移图
- ![avatar](images/../../images/122_3.png)

#### 参考资料
- [买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-ii-by-leetcode/)
- [买卖股票的最佳时机 II （贪心，清晰图解）](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/best-time-to-buy-and-sell-stock-ii-zhuan-hua-fa-ji/)
- [暴力搜索、贪心算法、动态规划](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/tan-xin-suan-fa-by-liweiwei1419-2/)
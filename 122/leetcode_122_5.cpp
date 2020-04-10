#include <iostream>
#include <vector>
#include <algorithm>

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int len = prices.size();
            if (len < 2) return 0;

            /**
             * 0: 持有现金
             * 1: 持有股票
             * 状态转移: 0 -> 1 -> 0 -> 1 -> 0 -> 1 -> 0
             */
            int dp[len][2];

            /**
             * 状态从持有现金(cash)开始，到最后一天我们关心的状态仍然是现金
             */
            dp[0][0] = 0;
            dp[0][1] = -prices[0];

            // 下一个状态的买入/卖出，依赖上一个状态买入/卖出的金钱的剩余值
            for (int i = 1; i < len; i++) {
                // 这里还是涉及一个不操作的状态。判断上一次的决策和这一次的决策谁的收益大
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            }

            return dp[len - 1][0];
        }
};

void test_case_1(Solution So) {
    vector<int> prices = {7,1,5,3,6,4};
    int ret = So.maxProfit(prices);
    cout << "结果为:" << ret << endl;
}

void test_case_2(Solution So) {
    vector<int> prices = {1, 7, 2, 3, 6, 7, 6, 7};
    int ret = So.maxProfit(prices);
    cout << "结果为:" << ret << endl;
}

int main(){

    Solution So;
    test_case_1(So);
    return 0;
}


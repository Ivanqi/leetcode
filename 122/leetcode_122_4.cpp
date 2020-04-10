#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
    public:
        int res = 0;
        int maxProfit(vector<int>& prices) {
            int len = prices.size();
            if (len < 2)  return 0;
            this->res = 0;
            dfs(prices, 0, len, 0, this->res);
            return res;
        }

        /**
         * @param prices 股价数组
         * @param index 当前是第几天，从0开始
         * @param status 0 表示不持有股票，1表示持有股票
         * @param profit 当前收益
         */
        void dfs(vector<int>& prices, int index, int len, int status, int profit)  {
            // 三种状态， 1. 不操作， 2. 买入， 3. 卖出
            // 终止条件， index == len
            if (index == len) {
                this->res = max(this->res, profit);
                return;
            }

            // 不操作的原因：可能当前买入/卖出，都不能获得最大利益。需要往后看看
            dfs(prices, index + 1, len, status, profit);

            // 卖出
            if (status == 0) {
               // 卖出了，下一个交易动作是不操作（等待时机）,或直接买入
                dfs(prices, index + 1, len, 1, profit - prices[index]);
            } else {
                // 买入了，下一个交易动作是不操作(等待时机)，或直接卖出
                dfs(prices, index + 1, len, 0, profit + prices[index]);
            }
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


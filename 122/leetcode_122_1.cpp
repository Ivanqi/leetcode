#include <iostream>
#include <vector>
using namespace std;

/**
 * 时间复杂度:O(n^n)，调用递归函数n ^ n次
 * 空间复杂度:O(n), 递归的深度为n
 */
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            return calculate(prices, 0);
        }

        int calculate(vector<int>& prices, int s) {
            if (s >= prices.size()) return 0;
            int n = prices.size();

            int max = 0;
            for (int start = s; start < n; start++) {
                int maxprofit = 0;
                for (int i = start + 1; i < prices.size(); i++) {
                    if (prices[start] < prices[i]) {
                        int profit = calculate(prices, i + 1) + prices[i] - prices[start];
                        if (profit > maxprofit) {
                            maxprofit = profit;
                        }
                    }
                }

                if (maxprofit > max) {
                    max = maxprofit;
                }
            }

            return max;
        }
};

void test_case_1(Solution So) {
    vector<int> prices = {7,1,5,3,6,4};
    int ret = So.maxProfit(prices);
    cout << "结果为:" << ret << endl;
}

int main(){

    Solution So;
    test_case_1(So);
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

/**
 * 时间复杂度: O(n),遍历一次
 * 空间复杂度: O(1)
 */
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            int maxprofit = 0;

            for (int i = 1; i < n ; i++) {
                if (prices[i] - prices[i - 1] > 0) {
                    maxprofit += prices[i] - prices[i - 1];
                }
            }

            return maxprofit;
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
    test_case_2(So);
    return 0;
}


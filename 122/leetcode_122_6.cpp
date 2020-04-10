#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int len = prices.size();

            int buy[len];
            int sell[len];

            sell[0] = 0;
            buy[0] = -prices[0];

            for (int i = 1; i < len; i++)  {
                sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
                buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
            }

            return sell[len - 1];
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


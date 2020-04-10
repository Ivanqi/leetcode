#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int len = prices.size();

            int sell = 0;
            int buy = -prices[0];

            int preSell = sell;
            int preBuy = buy;

            for (int i = 1; i < len; i++) {
                sell = max(preSell, buy + prices[i]);
                buy = max(preBuy, sell - prices[i]);

                preSell = sell;
                preBuy = buy;
            }

            return preSell;
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
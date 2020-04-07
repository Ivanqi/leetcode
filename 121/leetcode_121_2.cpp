#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            int maxprofit = 0;
            int inf = 1e9;
            int minprice = inf;
           
            for (int i = 0; i < n; i++) {
                maxprofit = max(maxprofit, prices[i] - minprice);
                minprice = min(prices[i], minprice);
               
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
    vector<int> prices = {7,6,4,3,1};
    int ret = So.maxProfit(prices);
    cout << "结果为:" << ret << endl;
}

int main() {
    Solution So;
    test_case_1(So);
    return 0;
}
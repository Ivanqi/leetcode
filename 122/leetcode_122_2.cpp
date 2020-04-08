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
            int i = 0;
            int peak = prices[0];
            int valley = prices[0];
            int maxprofit = 0;
            int n = prices.size();

            while (i < n - 1) {
                while (i < n - 1 && prices[i] > prices[i + 1]) {
                    i++;
                }
                valley = prices[i]; 

                while (i < n - 1 && prices[i] <= prices[i + 1]) {
                    i++;
                }
                peak = prices[i];
                maxprofit += peak - valley;
            }

            return maxprofit;
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


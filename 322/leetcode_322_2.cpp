#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            vector<int> memo(amount + 1, -2);
            return helper(coins, amount, memo);
        }

        int helper(vector<int>& coins, int amount, vector<int>& memo) {
            if (amount == 0) return 0;
            if (memo[amount] != -2) return memo[amount];
            int ans = INT_MAX;

            for (int coin: coins) {
                // 金额不可达
                if (amount - coin < 0) continue;
                int subProb = helper(coins, amount - coin, memo);
                // 子问题无解
                if (subProb == -1) continue;
                ans = min(ans, subProb + 1);
            }
            // 记录本轮答案
            memo[amount] = (ans == INT_MAX) ? -1 : ans;
            return memo[amount];
        }
};

void test_case_1(Solution So){
  vector<int> v = {1, 2, 5};  
  int amount = 11;
  cout << "val: "<< So.coinChange(v, amount) << endl;
}

int main() {
    Solution So;
    test_case_1(So);
    return 0;
}
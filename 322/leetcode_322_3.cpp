#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            vector<int> dp(amount + 1, amount + 1);
            dp[0] = 0;
            for (int i = 1; i <= amount; i++) {
                for (int coin : coins)
                    if (coin <= i)
                        dp[i] = min(dp[i], dp[i - coin] + 1);
            }
            return dp[amount] > amount ? -1 : dp[amount];
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
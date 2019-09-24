#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// 因为int占4字节32位，根据二进制编码的规则，INT_MAX = 2^31-1，INT_MIN= -2^31
class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            if (amount == 0) return 0;
            int ans = INT_MAX;
            for (int coin : coins) {
                // 金额不可达
                if (amount - coin < 0) continue;
                int subProb = coinChange(coins, amount - coin);
                // 子问题无解
                if (subProb == -1) continue;
                ans = min(ans, subProb + 1);
            }
            return ans == INT_MAX ? -1 : ans;
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
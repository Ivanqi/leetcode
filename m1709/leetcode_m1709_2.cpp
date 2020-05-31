#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
    public:
        int getKthMagicNumber(int k) {

            vector<int> dp(k);
            dp[0] = 1;
            vector<int> mask({3, 5, 7});
            int maskLen = mask.size();
            vector<int> index(maskLen, 0);

            for (int i = 1; i < k; i++) {
                int minNum = INT_MAX;
                for (int j = 0; j < maskLen; j++) {
                    if (minNum > dp[index[j]] * mask[j]) {
                        minNum = dp[index[j]] * mask[j];
                    }
                }
                dp[i] = minNum;


                for (int j = 0; j < maskLen; j++) {
                    if (dp[i] == dp[index[j]] * mask[j]) {
                        index[j]++;
                    }
                }
            }
            return dp[k - 1];
        }
};

void test_case_1(Solution So) {
    int k = 5;
    int ret = So.getKthMagicNumber(k);
    cout << "结果为: " << ret << endl;
}

int main() {

    Solution So;
    test_case_1(So);
}
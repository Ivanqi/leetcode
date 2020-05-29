#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <limits.h>
using namespace std;


class Solution {
    public:
        int nthSuperUglyNumber(int n, vector<int>& primes) {

            vector<long> dp(n);
            dp[0] = 1;
            int len = primes.size();
            vector<int> index(len, 0);

            for (int i = 1; i < n; i++) {
                int min = INT_MAX;
                for (int j = 0; j < len; j++) {
                    if (min > primes[j] * dp[index[j]]) {
                        min = primes[j] * dp[index[j]];
                    }
                }

                dp[i] = min;
                for (int j = 0; j < len; j++) {
                    if (min == primes[j] * dp[index[j]]) {
                        index[j]++;
                    }
                }
            }
            
            return dp[n - 1];
        }
};

void test_case_1(Solution So) {
    int n = 12;
    vector<int> primes = {2, 7, 13, 19};

    int ret = So.nthSuperUglyNumber(n, primes);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    int n = 100000;
    vector<int> primes = {2, 7, 13, 19};

    int ret = So.nthSuperUglyNumber(n, primes);
    cout << "结果为: " << ret << endl;
}

int main() {

    Solution So;
    test_case_2(So);
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// 小顶堆的方法是先存再排，dp的方法则是先排再存
class Solution {
    public:
        int nthUglyNumber(int n) {
            vector<int> dp(n);
            dp[0] = 1;

            int p2, p3, p5;
            p2 = p3 = p5 = 0;

            for (int i = 1; i < n; i++) {
                dp[i] = min(min(2 * dp[p2], 3 * dp[p3]), 5 * dp[p5]);
                if (dp[i] == 2 * dp[p2]) {
                    p2++;
                }

                if (dp[i] == 3 * dp[p3]) {
                    p3++;
                }

                if (dp[i] == 5 * dp[p5]) {
                    p5++;
                }
            }

            return dp[n - 1];
        }
};

void test_case_1(Solution So) {
    int n = 10;
    int ret = So.nthUglyNumber(n);
    cout << "结果为: " << ret <<endl;
}

void test_case_2(Solution So) {
    int n = 1407;
    int ret = So.nthUglyNumber(n);
    cout << "结果为: " << ret <<endl;
}


int main() {

    Solution So;
    test_case_1(So);
    return 0;
}
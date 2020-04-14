#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// 自上往下 - 一维
class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int len = triangle.size();
            if (len == 0) return 0;

            int dp[len + 1];
            for (int i = 0; i < len + 1; i++) {
                dp[i] = 0;
            }
            dp[0] = triangle[0][0];

            for (int i = 1; i < len; i++) {
                int n =  triangle[i].size();
                for (int j = n - 1; j >= 0; j--) {
                    if (j == 0) {
                        dp[j] = dp[j] + triangle[i][j];
                    } else if (j == n - 1) {
                        dp[j] = dp[j - 1] + triangle[i][j];
                    } else {
                        dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
                    }
                }
            }

            int minNums = INT_MAX;
            for (int i = 0; i < len; i++) {
                if (minNums > dp[i]) minNums = dp[i];
            }
            return minNums;
        }
};

void test_case_1(Solution So) {
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    int ret = So.minimumTotal(triangle);
    cout << "结果为:" << ret << endl;
}

void test_case_2(Solution So) {
    vector<vector<int>> triangle = {
        {-1},
        {2, 3},
        {1, -1, -3}
    };

    int ret = So.minimumTotal(triangle);
    cout << "结果为:" << ret << endl;
}

void test_case_3(Solution So) {
    vector<vector<int>> triangle = {
        {-1},
        {-2, -3},
    };

    int ret = So.minimumTotal(triangle);
    cout << "结果为:" << ret << endl;
}

int main() {
    Solution So;
    test_case_3(So);
    return 0;
}
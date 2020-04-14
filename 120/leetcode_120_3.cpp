#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// 自上往下 - 二维
class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int len = triangle.size();
            if (len == 0) return 0;

            int dp[len][len];
            dp[0][0] = triangle[0][0];

            for (int i = 1; i < len; i++) {
                int n =  triangle[i].size();
                for (int j = 0; j < n; j++) {
                    if (j == 0) {
                        dp[i][j] = dp[i - 1][j] + triangle[i][j];
                    }  else if (j == n - 1){
                        dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                    } else {
                        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
                    }
                }
            }

            int minNums = INT_MAX;
            for (int i = 0; i < len; i++) {
                int val = dp[len - 1][i];
                if (minNums > val) minNums = val;
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
    test_case_2(So);
    return 0;
}
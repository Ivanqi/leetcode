#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

// 自下往上 - 一维
class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int len = triangle.size();
            if (len == 0) return 0;
   
            int dp[len + 1];
            memset(dp, 0, sizeof(dp));
           

            for (int i = len - 1; i >= 0; --i) {
                for (int j = 0; j <= i; ++j) {
                    dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
                }
            }
            return dp[0];     
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
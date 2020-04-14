#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 自下往上 - 二维
class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int len = triangle.size();
            if (len == 0) return 0;
   
            for (int i = len - 2; i >= 0; --i) {
                for (int j = 0; j < triangle[i].size(); ++j) {
                    triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][ j + 1]);
                }
            }
            return triangle[0][0];
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

int main() {
    Solution So;
    test_case_1(So);
    return 0;
}
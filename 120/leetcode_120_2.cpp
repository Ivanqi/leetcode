#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 回溯算法 - 备忘录版本
class Solution {
    public:
        int helper(vector<vector<int>>& triangle, vector<vector<int>>& mem, int row, int col) {
            if (triangle.size() - 1 == row) {
                return triangle[row][col];
            }
            if (mem[row][col]) return mem[row][col];

            int down = helper(triangle, mem, row + 1, col);
            int right = helper(triangle, mem, row + 1, col + 1);

            int ret = min(down, right) + triangle[row][col];
            mem[row][col] = ret;
            return ret;
        }
        
        int minimumTotal(vector<vector<int>>& triangle) {
            int len = triangle.size();
            if (len == 0) return 0;
            vector<vector<int>> mem(len, vector<int>(len));
            return helper(triangle, mem, 0, 0);
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
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<int> memo;
        int jump(vector<int>& nums) {
            int n = nums.size();
            // 备忘录初始化为n,相当于INT_MAX
            // 因为从0调到n - 1 最多 n - 1步
            memo = vector<int>(n, n);
            return dp(nums, 0);
        }

        int dp(vector<int>& nums, int p) {
            int n = nums.size();

            // base case
            if (p >= n - 1) {
                return 0;
            }

            // 子问题已经计算过
            if (memo[p] != n) {
                return memo[p];
            }

            int steps = nums[p];
            // 你可以选择跳1步，2步。。。
            for (int i = 1; i <= steps; i++) {
                // 穷举每一个选择
                // 计算每一个子问题结果
                int subProblem = dp(nums, p + i);
                // 取其中最小的作为最终结果
                memo[p] = min(memo[p], subProblem + 1);
            }
            return memo[p];
        }
};

void test_case_1(Solution So) {
    vector<int> nums = {2, 3, 1, 1, 4};
    int ret = So.jump(nums);
    cout << "结果为: " << ret << endl;
}

int main() {

    Solution So;
    test_case_1(So);
    return 0;
}
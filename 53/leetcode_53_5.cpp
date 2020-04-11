#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

/**
 * 时间复杂度：O(N)
 * 空间复杂度：O(1)
 */
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            if (nums.size() == 0) return 0;
            int ans = 0;
            // 定义状态
            // dp[i] 表示前i个元素的最大连续子数组的和
            int dp[nums.size()];

            // 初始化状态, 数组中第一个元素的最大和就是第一个元素值
            dp[0] = nums[0];
            ans = nums[0];

            // 状态转移方程: max(dbp[i - 1], 0) + nums[i]
            for (int i = 1; i < nums.size(); i++) {
                dp[i] = max(0, dp[i - 1]) + nums[i];
                ans = max(dp[i], ans);
            }

            return ans;
        }
};

void test_case_1(Solution So) {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ret = So.maxSubArray(nums);
    cout << "结果为:" << ret << endl;
}

void test_case_2(Solution So) {
    vector<int> nums = {2, 1};
    int ret = So.maxSubArray(nums);
    cout << "结果为:" << ret << endl;
}

int main() {
    Solution So;
    test_case_1(So);
}
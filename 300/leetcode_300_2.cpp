#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        /**
         * 第一步：定义状态
         *  由于一个子序列一定会一个数结尾，于是将状态定义成: dp[i] 表示以nums[i]结尾的"上升子序列"
         * 
         * 第二步: 考虑状态转移方程
         *  遍历到nums[i]时，需要把下标i之前的所有的数都有看一遍
         *  只要nums[i]严格大于在它位置之前的某个数，那么nums[i]就可以接在这个数后面形成一个更长的上升子序列
         *  因此，dp[i]就等于下标i之前严格小于nums[i]的所有状态中的最大者 + 1
         * 
         * 第三步：考虑初始化
         *  dp[i] = 1, 1个字符显然是长度为1的上升子序列
         * 
         * 第四步：考虑输出
         *  这里要注意，不能返回最后一个状态
         *  还是根据定义，最后一个状态值只是以nums[len - 1]结尾的“上升子序列”的长度
         *  状态数组dp的最大值才是最后要输出的值
         */
        int lengthOfLIS(vector<int>& nums) {
            int len = nums.size();

            if (len == 0) return 0;

            int dp[len];
            int ans = 1;

            for (int i = 0; i < len; i++) {
                dp[i] = 1;
                for (int j = 0; j < i; j++) {
                    if (nums[i] > nums[j]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
                ans = max(ans, dp[i]);
            }

            return ans;
        }
};

void test_case_1(Solution So) {
    vector<int> nums = {
        10, 9, 2, 5, 3, 7, 101,18
    };

    int ret = So.lengthOfLIS(nums);

    cout << "结果为:" << ret << endl;
}

void test_case_2(Solution So) {
    vector<int> nums = {
       10, 9, 2, 5, 3, 4
    };
    int ret = So.lengthOfLIS(nums);

    cout << "结果为:" << ret << endl;
}

void test_case_3(Solution So) {
    vector<int> nums = { 
        1,3,6,7,9,4,10,5,6
    };
    int ret = So.lengthOfLIS(nums);
    cout << "结果为:" << ret << endl;
}

int main() {
    Solution So;
    test_case_1(So);

    return 0;
}
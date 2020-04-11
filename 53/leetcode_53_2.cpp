#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            
            // 两个变量，一个记录最大和，一个记录当前的和
            int localMaximum = nums[0];
            int GlobalMaximum = localMaximum;
            int len = nums.size();

            for (int i = 1; i < len; i++) {
                if (localMaximum + nums[i] > nums[i]) {
                    // 证明这里可以找到最长公共子序列
                    // 记录全局最大值
                    // 记录局部最大值
                    // 当当前序列加上此时的元素的值大于 localMaximum 的值，说明最大序列和可能出现在后续序列中，记录此时的最大值
                    GlobalMaximum = max(GlobalMaximum, localMaximum + nums[i]);
                    localMaximum = localMaximum + nums[i];
                } else {
                    // 如果没找到，从当前开始，接着往后找
                    // 记录当前点的全局最大值
                    // 当 localMaximum (当前和)小于下一个元素时候，当前最大序列到此为止。以该元素为起点继续找最大子序列
                    GlobalMaximum = max(max(GlobalMaximum, localMaximum), max(localMaximum + nums[i], nums[i]));
                    localMaximum = nums[i];
                }
            }

            return GlobalMaximum;
        }
};

void test_case_1(Solution So) {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ret = So.maxSubArray(nums);
    cout << "结果为:" << ret << endl;
}

int main() {
    Solution So;
    test_case_1(So);
}
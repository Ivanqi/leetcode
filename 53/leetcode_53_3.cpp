#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

/**
 * 时间复杂度: O(NlogN)
 * 空间复杂度: O(logN)
 */
class Solution {
    public:
        int crossNums(vector<int>&nums, int left, int mid, int right) {
            if (left == right) nums[left];
            int crossSumNums = 0;
            int leftSumNums = INT_MIN;
            for (int i = mid; i > left - 1; i--) {
                crossSumNums += nums[i];
                leftSumNums = max(leftSumNums, crossSumNums);
            }

            crossSumNums = 0;
            int rightSumNums = INT_MIN;
            for (int i = mid + 1; i < right + 1; i++) {
                crossSumNums += nums[i];
                rightSumNums = max(rightSumNums, crossSumNums);
            }
            return leftSumNums + rightSumNums;
        }

        int helper(vector<int>&nums, int left, int right) {
            if (left == right) return nums[left];

            int mid = (left + right) / 2;
            int leftNums = helper(nums, left, mid);
            int rightNums = helper(nums, mid + 1, right);
            int corssSumNums = crossNums(nums, left, mid, right);


            return max(max(leftNums, rightNums), corssSumNums);
        }

        int maxSubArray(vector<int>& nums) {
            int len = nums.size();
            return helper(nums, 0, len - 1);
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
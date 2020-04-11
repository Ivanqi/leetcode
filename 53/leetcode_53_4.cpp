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
            int maxNums = 0;
            int tmp = nums[0];

            for (int i = 1; i < nums.size(); i++) {
                tmp = max(nums[i], tmp + nums[i]);
                maxNums = max(tmp, maxNums);
            }

            return maxNums;
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
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * dpMax[i]有几种取值
 *  1. 当 nums[i] >= 0, 并且dpMax[i - 1] > 0, dpMax[i] = dpMax[i - 1] * nums[i]
 *  2. 当 nums[i] >= 0, 并且dbMax[i - 1] < 0, dpMax[i] = nums[i]
 *  3. nums[i] < 0, dpMin[i - 1] < 0, dpMax[i] = dpMin[i] * nums[i];
 *  4. nums[i] < 0, dpMin[i - 1] >= 0, dpMax[i - 1] > dpMin[i - 1] > 0, dpMax[i] = nums[i]
 */
class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int len = nums.size();
            int maxNums;
            int dpMax[len];
            int dpMin[len];
            maxNums = dpMax[0] = dpMin[0] = nums[0];
            for (int i = 1; i < len; i++) {
                dpMax[i] = max(max(nums[i], nums[i] * dpMax[i - 1]), nums[i] * dpMin[i - 1]);
                dpMin[i] = min(min(nums[i], nums[i] * dpMax[i - 1]), nums[i] * dpMin[i - 1]);
                maxNums = max(maxNums, dpMax[i]);
            }
            return maxNums;
        }
};

void test_case_1(Solution So) {
    vector<int> nums = {2, 3, -2, 4};
    int ret = So.maxProduct(nums);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    vector<int> nums = {-2,0,-1};
    int ret = So.maxProduct(nums);
    cout << "结果为: " << ret << endl;
}

void tese_case_3(Solution So) {
    vector<int> nums = {-2};
    int ret = So.maxProduct(nums);
    cout << "结果为: " << ret << endl;
}

void test_case_4(Solution So) {
    vector<int> nums = {-2, 3, -4};
    int ret = So.maxProduct(nums);
    cout << "结果为: " << ret << endl;
}

int main() {
    Solution So;

    test_case_4(So);
}
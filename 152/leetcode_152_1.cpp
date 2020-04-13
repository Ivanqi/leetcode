#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 如果给定的数组全部都是正数，那么子数组最大的乘积？ 把所有数字相乘即可
 * 但是如果给定的数组存在负数？
 *  1. 存在偶数个负数。把所有数字相乘即可，因为最终一定是正数
 *  2. 存在奇数个负数。
 *     1. 顺序遍历
 *     2. 倒序遍历
 */
class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int len = nums.size();
            if (len == 0) return 0;

            int maxNums = 1;
            int res = nums[0];
            for (int i = 0; i < len; i++) {
                maxNums *= nums[i];
                // cout << "maxNums:" << maxNums << "| nums[i]: " << nums[i] << endl;
                res = max(res, maxNums);
                if (maxNums == 0) {
                    maxNums = 1;
                }
            }
            // cout << "res: " << res << endl;
            maxNums = 1;
            for (int i = len - 1; i >= 0; i--) {
                maxNums *= nums[i];
                // cout << "maxNums:" << maxNums << endl;
                res = max(res, maxNums);
                if (maxNums == 0) maxNums = 1;
            }
            // cout << "res: " << res << endl;
            return res;
        }
};

void test_case_1(Solution So) {
    vector<int> nums = {2, 3, -2, 4};
    int ret = So.maxProduct(nums);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    vector<int> nums = {-2, 3, -4};
    int ret = So.maxProduct(nums);
    cout << "结果为: " << ret << endl;    
}

void test_case_3(Solution So) {
    vector<int> nums = {3, -1, 4};
    int ret = So.maxProduct(nums);
    cout << "结果为: " << ret << endl;  
}

int main() {
    Solution So;

    test_case_3(So);
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int maxLength = 0;
        int lengthOfLIS(vector<int>& nums) {
            int len = nums.size();
            if (len == 0) return 0;

            for (int i = 0; i < len; i++) {
                findMaxLength(nums, i, nums[i], 1);
            }
            return maxLength;
        }

        /**
         * 查找最长递增子序列主方法
         * @param nums 数组
         * @param index 上一次选取数据的下标
         * @param num 上一次选取的数据
         * @param length 当前选取的子序列长度
         */
        void findMaxLength(vector<int>& nums, int index, int num, int length) {
            for (int i = index; i < nums.size(); i++) {
                if (nums[i] > num) {
                    findMaxLength(nums, i, nums[i], length + 1);
                }
            }

            if (length > maxLength) {
                maxLength = length;
            }
        }
};

void test_case_1(Solution So) {
    vector<int> nums = {
        10, 9, 2, 5, 3, 7, 101, 18
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
        1, 3, 6, 7, 9, 4, 10, 5, 6
    };
    int ret = So.lengthOfLIS(nums);
    cout << "结果为:" << ret << endl;
}

int main() {
    Solution So;
    test_case_1(So);

    return 0;
}
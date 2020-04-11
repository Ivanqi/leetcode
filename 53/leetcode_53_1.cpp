#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            // 类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
            int max = INT_MIN;
            int numSize = int(nums.size());

            for (int i = 0; i < numSize; i++) {
                int sum = 0;
                for (int j = i; j < numSize; j++) {
                    sum += nums[j];
                    if (sum > max) {
                        max = sum;
                    }
                }
            }
            return max;
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